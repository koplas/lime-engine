module;

#include <condition_variable>
#include <mutex>
#include <queue>
#include <stb_image.h>
#include <string>
#include <thread>
#include <unordered_map>
#include <iostream>
#include <variant>
#include <vk_mem_alloc.h>
#include <vulkan/vulkan.h>
#include <cstring>

export module Uploader;

import vulkan;

import Mesh;
import utils;
import vulkan_types;


enum class UploadType {
    Mesh,
    Image,
};

struct UploadCommand {
    std::string file;
    UploadType type;
};

struct MeshUpload {
    GPUMesh mesh;
    vk::Fence fence;
    std::string name;
    AllocatedBuffer vertex_buffer;
    AllocatedBuffer index_buffer;
    vk::CommandBuffer command_buffer;
};

struct TextureUpload {
    GPUTexture texture;
    vk::Fence fence;
    std::string name;
    AllocatedBuffer buffer;
    vk::CommandBuffer command_buffer;
};

struct UploadThread {
    vk::CommandPool command_pool;
    std::jthread thread;
    std::atomic<bool> keep_running = true;

    std::mutex command_queue_mutex;
    std::condition_variable command_queue_cv;
    std::queue<UploadCommand> command_queue;

    std::mutex upload_mutex;
    std::vector<MeshUpload> uploaded_meshes;
    std::vector<TextureUpload> uploaded_textures;
};

// Todo refactor uploader
export class Uploader {
public:
    Uploader(vk::Device device, vk::Queue graphics_queue, std::mutex *graphics_queue_mutex,
             uint32_t graphics_queue_family, VmaAllocator allocator) : m_device{device}, m_graphics_queue_mutex{graphics_queue_mutex},
                                                                       m_graphics_queue{graphics_queue}, m_graphics_queue_family{graphics_queue_family},
                                                                       m_allocator{allocator} {
        vk::CommandPoolCreateInfo const upload_command_pool = {
                .queueFamilyIndex = m_graphics_queue_family,
        };
        auto result = m_device.createCommandPool(&upload_command_pool, nullptr,
                                                 &m_upload_thread.command_pool);
        vk_assert(result);

        init_upload_thread();
    };

    ~Uploader() {
        assert_true(!m_upload_thread.keep_running);
    };

    void queue_image_upload(std::string_view name) {
        UploadCommand const command = {
                .file = std::string{name},
                .type = UploadType::Image,
        };
        std::unique_lock const lock(m_upload_thread.command_queue_mutex);
        m_upload_thread.command_queue.push(command);
        m_upload_thread.command_queue_cv.notify_one();
    };

    void queue_mesh_upload(std::string_view name) {
        UploadCommand const command = {
                .file = std::string{name},
                .type = UploadType::Mesh,
        };
        std::unique_lock const lock(m_upload_thread.command_queue_mutex);
        m_upload_thread.command_queue.push(command);
        m_upload_thread.command_queue_cv.notify_one();
    };

    void poll_uploads(std::unordered_map<std::string, GPUMesh> &meshes,
                      std::unordered_map<std::string, GPUTexture> &textures, bool &texture_updated) {
        for (auto it = m_upload_thread.uploaded_meshes.begin(); it != m_upload_thread.uploaded_meshes.end();) {
            auto &upload = *it;
            auto status = m_device.getFenceStatus(upload.fence);
            if (status == vk::Result::eSuccess) {
                m_device.destroy(upload.fence);
                vmaDestroyBuffer(m_allocator, upload.vertex_buffer.buffer, upload.vertex_buffer.allocation);
                vmaDestroyBuffer(m_allocator, upload.index_buffer.buffer, upload.index_buffer.allocation);

                m_device.freeCommandBuffers(m_upload_thread.command_pool, 1, &upload.command_buffer);

                meshes[upload.name] = upload.mesh;
                it = m_upload_thread.uploaded_meshes.erase(it);
            } else {
                it++;
            }
            assert_true(status != vk::Result::eErrorDeviceLost);
        }

        texture_updated = false;
        for (auto it = m_upload_thread.uploaded_textures.begin(); it != m_upload_thread.uploaded_textures.end();) {
            auto &upload = *it;
            auto status = m_device.getFenceStatus(upload.fence);
            if (status == vk::Result::eSuccess) {
                m_device.destroy(upload.fence);
                vmaDestroyBuffer(m_allocator, upload.buffer.buffer, upload.buffer.allocation);

                m_device.freeCommandBuffers(m_upload_thread.command_pool, 1, &upload.command_buffer);

                textures[upload.name] = upload.texture;
                it = m_upload_thread.uploaded_textures.erase(it);
                texture_updated = true;
            } else {
                it++;
            }
            assert_true(status != vk::Result::eErrorDeviceLost);
        }
    };

    void wait_all_upload(std::unordered_map<std::string, GPUMesh> &meshes,
                         std::unordered_map<std::string, GPUTexture> &textures) {
        m_upload_thread.keep_running = false;
        m_upload_thread.command_queue_cv.notify_one();
        m_upload_thread.thread.join();

        auto constexpr upload_timeout = 999999999;

        for (auto it = m_upload_thread.uploaded_meshes.begin(); it != m_upload_thread.uploaded_meshes.end();) {
            auto const &upload = *it;
            auto result = m_device.waitForFences(1, &upload.fence, true, upload_timeout);
            vk_assert(result);
        }

        for (auto it = m_upload_thread.uploaded_textures.begin(); it != m_upload_thread.uploaded_textures.end();) {
            auto const &upload = *it;
            auto result = m_device.waitForFences(1, &upload.fence, true, upload_timeout);
            vk_assert(result);
        }

        bool texture_updated;
        poll_uploads(meshes, textures, texture_updated);

        m_device.destroy(m_upload_thread.command_pool, nullptr);
    };

private:
    vk::Device m_device;
    UploadThread m_upload_thread;

    std::mutex *m_graphics_queue_mutex = nullptr;
    vk::Queue m_graphics_queue;
    uint32_t m_graphics_queue_family;

    VmaAllocator m_allocator;

    template<class QueueSubmitFunction>
    void queue_submit(QueueSubmitFunction function, vk::Fence const &fence, vk::CommandBuffer &cmd) {
        vk::CommandBufferAllocateInfo const cmd_alloc_info = {
                .commandPool = m_upload_thread.command_pool,
                .level = vk::CommandBufferLevel::ePrimary,
                .commandBufferCount = 1,
        };
        auto result = m_device.allocateCommandBuffers(&cmd_alloc_info, &cmd);
        vk_assert(result);

        vk::CommandBufferBeginInfo const cmd_begin_info = {
                .flags = vk::CommandBufferUsageFlagBits::eOneTimeSubmit,
        };

        result = cmd.begin(&cmd_begin_info);
        vk_assert(result);

        function(cmd);

        vk_assert(cmd.end());

        vk::SubmitInfo const submit = {
                .commandBufferCount = 1,
                .pCommandBuffers = &cmd,
        };

        {
            std::scoped_lock<std::mutex> const guard(*m_graphics_queue_mutex);
            result = m_graphics_queue.submit(1, &submit, fence);
            vk_assert(result);
        }
    };

    MeshUpload upload_mesh(std::string_view name) {
        MeshUpload upload = {
                .name = std::string{name},
        };
        vk::FenceCreateInfo const upload_fence_info = {};
        auto result = m_device.createFence(&upload_fence_info, nullptr, &upload.fence);
        vk_assert(result);

        auto mesh = load_from_gltf(name, false);

        bool const skinning = mesh.index() == 1;

        size_t vertex_buffer_size;
        size_t index_buffer_size;
        uint32_t index_count;

        void const *vertex_data;
        void const *index_data;
        if (skinning) {
            auto &mesh_tmp = std::get<MeshBone>(mesh);
            vertex_buffer_size = mesh_tmp.vertices.size() * sizeof(VertexBone);
            index_buffer_size = mesh_tmp.index_buffer.size() * sizeof(uint32_t);
            index_count = (uint32_t) mesh_tmp.index_buffer.size();
            vertex_data = mesh_tmp.vertices.data();
            index_data = mesh_tmp.index_buffer.data();
        } else {
            auto &mesh_tmp = std::get<Mesh>(mesh);
            vertex_buffer_size = mesh_tmp.vertices.size() * sizeof(Vertex);
            index_buffer_size = mesh_tmp.index_buffer.size() * sizeof(uint32_t);
            index_count = (uint32_t) mesh_tmp.index_buffer.size();
            vertex_data = mesh_tmp.vertices.data();
            index_data = mesh_tmp.index_buffer.data();
        }

        vk::BufferCreateInfo const staging_vertex_buffer_info = {
                .size = vertex_buffer_size,
                .usage = vk::BufferUsageFlagBits::eTransferSrc,
        };

        vk::BufferCreateInfo const staging_index_buffer_info = {
                .size = index_buffer_size,
                .usage = vk::BufferUsageFlagBits::eTransferSrc,
        };

        VmaAllocationCreateInfo vma_alloc_info = {};
        vma_alloc_info.usage = VMA_MEMORY_USAGE_CPU_ONLY;

        auto result_vma = vmaCreateBuffer(m_allocator,
                                          std::bit_cast<VkBufferCreateInfo const *>(&staging_vertex_buffer_info),
                                          &vma_alloc_info, &upload.vertex_buffer.buffer, &upload.vertex_buffer.allocation,
                                          nullptr);
        vk_assert(std::bit_cast<vk::Result>(result_vma));

        result_vma = vmaCreateBuffer(m_allocator, std::bit_cast<VkBufferCreateInfo const *>(&staging_index_buffer_info),
                                     &vma_alloc_info, &upload.index_buffer.buffer, &upload.index_buffer.allocation,
                                     nullptr);
        vk_assert(std::bit_cast<vk::Result>(result_vma));

        void *data;
        vmaMapMemory(m_allocator, upload.vertex_buffer.allocation, &data);
        memcpy(data, vertex_data, vertex_buffer_size);
        vmaUnmapMemory(m_allocator, upload.vertex_buffer.allocation);

        vmaMapMemory(m_allocator, upload.index_buffer.allocation, &data);
        memcpy(data, index_data, index_buffer_size);
        vmaUnmapMemory(m_allocator, upload.index_buffer.allocation);

        vk::BufferCreateInfo const vertex_buffer_info = {
                .size = vertex_buffer_size,
                .usage = vk::BufferUsageFlagBits::eVertexBuffer | vk::BufferUsageFlagBits::eTransferDst,
        };

        vk::BufferCreateInfo const index_buffer_info = {
                .size = index_buffer_size,
                .usage = vk::BufferUsageFlagBits::eIndexBuffer | vk::BufferUsageFlagBits::eTransferDst,
        };

        vma_alloc_info.usage = VMA_MEMORY_USAGE_GPU_ONLY;

        GPUMesh gpu_mesh = {};
        gpu_mesh.first_index = 0;
        gpu_mesh.index_count = index_count;

        result_vma = vmaCreateBuffer(m_allocator, std::bit_cast<VkBufferCreateInfo const *>(&vertex_buffer_info),
                                     &vma_alloc_info, &gpu_mesh.vertex_buffer.buffer,
                                     &gpu_mesh.vertex_buffer.allocation,
                                     nullptr);
        vk_assert(std::bit_cast<vk::Result>(result_vma));

        result_vma = vmaCreateBuffer(m_allocator, std::bit_cast<VkBufferCreateInfo const *>(&index_buffer_info),
                                     &vma_alloc_info, &gpu_mesh.index_buffer.buffer,
                                     &gpu_mesh.index_buffer.allocation,
                                     nullptr);
        vk_assert(std::bit_cast<vk::Result>(result_vma));

        queue_submit([vertex_buffer_size, upload, gpu_mesh, index_buffer_size](vk::CommandBuffer cmd) {
            vk::BufferCopy copy = {
                    .srcOffset = 0,
                    .dstOffset = 0,
                    .size = vertex_buffer_size,
            };

            cmd.copyBuffer(std::bit_cast<vk::Buffer>(upload.vertex_buffer.buffer), std::bit_cast<vk::Buffer>(gpu_mesh.vertex_buffer.buffer), 1, &copy);
            copy.size = index_buffer_size;
            cmd.copyBuffer(std::bit_cast<vk::Buffer>(upload.index_buffer.buffer), std::bit_cast<vk::Buffer>(gpu_mesh.index_buffer.buffer), 1, &copy);
        },
                     upload.fence, upload.command_buffer);
        upload.mesh = gpu_mesh;

        return upload;
    };

    TextureUpload upload_image(std::string_view name) {
        // Replace with std::format in the future
        std::string file = std::string{get_asset_dir()};
        file += name;
        file += ".png";

        TextureUpload upload = {
                .name = std::string{name},
        };

        vk::FenceCreateInfo const upload_fence_info = {};
        auto result = m_device.createFence(&upload_fence_info, nullptr, &upload.fence);
        vk_assert(result);

        assert_true(load_image_from_file(file, upload.texture.image, upload.fence, upload.command_buffer, upload.buffer));
        vk::ImageSubresourceRange const image_subresource = {
                .aspectMask = vk::ImageAspectFlagBits::eColor,
                .baseMipLevel = 0,
                .levelCount = 1,
                .baseArrayLayer = 0,
                .layerCount = 1,
        };
        vk::ImageViewCreateInfo const image_info = {
                .image = upload.texture.image.image,
                .viewType = vk::ImageViewType::e2D,
                .format = vk::Format::eR8G8B8A8Srgb,
                .subresourceRange = image_subresource,
        };

        result = m_device.createImageView(&image_info, nullptr, &upload.texture.image_view);
        assert_true(result == vk::Result::eSuccess);
        return upload;
    };

    void upload_thread_entry() {
        do {
            std::unique_lock lock(m_upload_thread.command_queue_mutex);
            while (m_upload_thread.command_queue.empty() && m_upload_thread.keep_running) {
                m_upload_thread.command_queue_cv.wait(lock, [this]() {
                    return !m_upload_thread.command_queue.empty() || !m_upload_thread.keep_running;
                });
            }
            while (!m_upload_thread.command_queue.empty() && m_upload_thread.keep_running) {


                switch (auto const &command = m_upload_thread.command_queue.front(); command.type) {
                    case UploadType::Mesh: {

                        auto mesh_upload = upload_mesh(command.file);
                        {
                            std::scoped_lock<std::mutex> const guard(m_upload_thread.upload_mutex);
                            m_upload_thread.uploaded_meshes.emplace_back(mesh_upload);
                        }
                        break;
                    }
                    case UploadType::Image: {
                        auto texture_upload = upload_image(command.file);
                        {
                            std::scoped_lock<std::mutex> const guard(m_upload_thread.upload_mutex);
                            m_upload_thread.uploaded_textures.emplace_back(texture_upload);
                        }
                        break;
                    }
                }
                m_upload_thread.command_queue.pop();
            }
        } while (m_upload_thread.keep_running);
    };

    bool load_image_from_file(std::string const &file, AllocatedImage &new_image, vk::Fence fence,
                              vk::CommandBuffer cmd, AllocatedBuffer &staging_buffer) {
        int tex_width = 0;
        int tex_height = 0;
        int tex_channels = 0;
        stbi_uc *pixels = stbi_load(file.c_str(), &tex_width, &tex_height, &tex_channels, STBI_rgb_alpha);

        if (pixels == nullptr) {
            std::cout << "Failed to load texture file " << file << std::endl;
            return false;
        }

        void const *pixel_ptr = pixels;
        vk::DeviceSize const image_size = static_cast<uint64_t>(tex_width) * tex_height * 4ULL;
        vk::Format const image_format = vk::Format::eR8G8B8A8Srgb;

        staging_buffer = create_buffer(m_allocator, image_size, vk::BufferUsageFlagBits::eTransferSrc,
                                       VMA_MEMORY_USAGE_CPU_ONLY);

        void *data = nullptr;
        vmaMapMemory(m_allocator, staging_buffer.allocation, &data);
        memcpy(data, pixel_ptr, image_size);
        vmaUnmapMemory(m_allocator, staging_buffer.allocation);
        stbi_image_free(pixels);

        vk::Extent3D image_extent = {
                .width = static_cast<uint32_t>(tex_width),
                .height = static_cast<uint32_t>(tex_height),
                .depth = 1,
        };

        vk::ImageCreateInfo const img_info = {
                .imageType = vk::ImageType::e2D,
                .format = image_format,
                .extent = image_extent,
                .mipLevels = 1,
                .arrayLayers = 1,
                .samples = vk::SampleCountFlagBits::e1,
                .tiling = vk::ImageTiling::eOptimal,
                .usage = vk::ImageUsageFlagBits::eSampled | vk::ImageUsageFlagBits::eTransferDst,
        };

        VmaAllocationCreateInfo img_alloc_info = {};
        img_alloc_info.usage = VMA_MEMORY_USAGE_GPU_ONLY;

        auto result = vmaCreateImage(m_allocator, std::bit_cast<VkImageCreateInfo const *>(&img_info),
                                     &img_alloc_info,
                                     std::bit_cast<VkImage *>(&new_image.image), &new_image.allocation, nullptr);
        vk_assert(std::bit_cast<vk::Result>(result));

        queue_submit([&new_image, &image_extent, &staging_buffer](vk::CommandBuffer submit_cmd) {
            vk::ImageSubresourceRange const range = {
                    .aspectMask = vk::ImageAspectFlagBits::eColor,
                    .baseMipLevel = 0,
                    .levelCount = 1,
                    .baseArrayLayer = 0,
                    .layerCount = 1,
            };

            vk::ImageMemoryBarrier const image_barrier_to_transfer = {
                    .srcAccessMask = {},
                    .dstAccessMask = vk::AccessFlagBits::eTransferWrite,
                    .oldLayout = vk::ImageLayout::eUndefined,
                    .newLayout = vk::ImageLayout::eTransferDstOptimal,
                    .image = new_image.image,
                    .subresourceRange = range,
            };

            submit_cmd.pipelineBarrier(vk::PipelineStageFlagBits::eTopOfPipe, vk::PipelineStageFlagBits::eTransfer, {}, 0,
                                       nullptr, 0, nullptr, 1, &image_barrier_to_transfer);

            vk::ImageSubresourceLayers const image_subresource = {
                    .aspectMask = vk::ImageAspectFlagBits::eColor,
                    .mipLevel = 0,
                    .baseArrayLayer = 0,
                    .layerCount = 1,
            };
            vk::BufferImageCopy const copy_region = {
                    .bufferOffset = 0,
                    .bufferRowLength = 0,
                    .bufferImageHeight = 0,
                    .imageSubresource = image_subresource,
                    .imageExtent = image_extent,
            };
            submit_cmd.copyBufferToImage(std::bit_cast<vk::Buffer>(staging_buffer.buffer), new_image.image, vk::ImageLayout::eTransferDstOptimal, 1,
                                         &copy_region);

            vk::ImageMemoryBarrier image_barrier_to_readable = image_barrier_to_transfer;
            image_barrier_to_readable.oldLayout = vk::ImageLayout::eTransferDstOptimal;
            image_barrier_to_readable.newLayout = vk::ImageLayout::eShaderReadOnlyOptimal;
            image_barrier_to_readable.srcAccessMask = vk::AccessFlagBits::eTransferWrite;
            image_barrier_to_readable.dstAccessMask = vk::AccessFlagBits::eShaderRead;

            submit_cmd.pipelineBarrier(vk::PipelineStageFlagBits::eTransfer, vk::PipelineStageFlagBits::eFragmentShader, {}, 0,
                                       nullptr, 0, nullptr, 1, &image_barrier_to_readable);
        },
                     fence, cmd);

        return true;
    };

    void init_upload_thread() {
        m_upload_thread.thread = std::jthread{&Uploader::upload_thread_entry, this};
    };
};
