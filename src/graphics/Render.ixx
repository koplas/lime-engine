module;

#include <algorithm>
#include <bit>
#include <cstring>
#include <list>
#include <mutex>
#include <optional>
#include <set>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>
#include <vk_mem_alloc.h>
#include <vulkan/vulkan.h>

#include <GLFW/glfw3.h>

#define VULKAN_HPP_DEFAULT_DISPATCHER vk::defaultDispatchLoaderDynamic

export module lime.Render;

import lime.MaterialBuilder;
import vulkan;
import lime.Uploader;
import glm;
import lime.utils;
import entt;
import lime.vulkan_types;

#ifndef NDEBUG
constexpr bool ENABLE_VALIDATION_LAYERS = true;
#else
constexpr bool ENABLE_VALIDATION_LAYERS = false;
#endif


struct Bones {
    std::vector<glm::mat4> bones;
};

struct FrameData {
    vk::Semaphore present_semaphore;
    vk::Semaphore render_semaphore;
    vk::Fence render_fence;
    vk::CommandPool command_pool;
    vk::CommandBuffer main_command_buffer;

    lime::AllocatedBuffer camera_buffer;
    void *mapped_camera_buffer;

    lime::AllocatedBuffer object_buffer;
    void *mapped_object_buffer;

    lime::AllocatedBuffer scene_buffer;
    void *mapped_scene_buffer;

    lime::AllocatedBuffer lighting_buffer;
    void *mapped_lighting_buffer;

    vk::DescriptorSet main_descriptor;
    vk::DescriptorSet lighting_descriptor;
    uint32_t texture_update = 0;
    std::unordered_map<lime::GPUTexture *, uint32_t> material_indices;
};

struct GPUCamera {
    glm::mat4 view;
    glm::mat4 proj;
    glm::mat4 inv_view_proj;
};

constexpr unsigned int FRAME_OVERLAP = 2;

extern "C" VKAPI_ATTR VkBool32 VKAPI_CALL debug_callback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                         VkDebugUtilsMessageTypeFlagsEXT messageType,
                                                         VkDebugUtilsMessengerCallbackDataEXT const *pCallbackData,
                                                         void *pUserData) {
    if constexpr (ENABLE_VALIDATION_LAYERS) {
        constexpr std::string_view RESET = "\033[0m";
        constexpr std::string_view RED = "\033[31m";
        constexpr std::string_view BLUE = "\033[34m";
        constexpr std::string_view YELLOW = "\033[33m";

        (void) pUserData;
        std::string severity;
        std::string message;
        switch (messageSeverity) {
            case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
                message += BLUE;
                severity = "Verbose";
                break;
            case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
                message += RED;
                severity = "Error";
                break;
            case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
                message += BLUE;
                severity = "Info";
                break;
            case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
                message += YELLOW;
                severity = "Warning";
                break;
            default:
                severity = "Other";
                break;
        }
        std::string type;
        switch (messageType) {
            case VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT:
                type = "general";
                break;
            case VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT:
                type = "performance";
                break;
            case VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT:
                type = "validation";
                break;
            default:
                type = "other";
                break;
        }
        message += severity + ", " + type + ": " + pCallbackData->pMessage + std::string{RESET};
        lime::utils::log_info(message);
    }
    return VK_FALSE;
}


export namespace lime {
    class Render {
    public:
        Render(GLFWwindow *window, vk::Extent2D window_extent) : m_window_extent{window_extent} {
            if constexpr (ENABLE_VALIDATION_LAYERS) {
                utils::log_info("Enable validation layers");
            }
            init_instance(window);
            init_device();
            init_vma();
            init_swapchain();
            init_commands();
            init_renderpass();
            init_framebuffers();
            init_sync_structures();
            init_descriptors();
            init_pipelines();
            init_texture_sampler();

            m_uploader.emplace(m_device, m_graphics_queue, &m_graphics_queue_mutex, m_graphics_queue_family, m_allocator);
        };

        ~Render() {
            m_uploader->wait_all_upload(m_meshes, m_textures);

            for (auto const &frame: m_frames) {
                constexpr auto fence_timeout = 1000ULL * 1000ULL * 1000ULL;
                auto result = m_device.waitForFences(1, &frame.render_fence, true, fence_timeout);
                utils::vk_assert(result);

                // Todo wait until it is safe to destroy the present_semaphore
                m_device.destroy(frame.present_semaphore, nullptr);
                m_device.destroy(frame.render_semaphore, nullptr);

                m_device.destroy(frame.render_fence, nullptr);
                m_device.destroy(frame.command_pool, nullptr);
            }

            for (auto const &[name, material]: m_materials) {
                m_device.destroy(material.pipeline, nullptr);
            }

            for (auto const &layout: m_pipeline_layouts) {
                m_device.destroy(layout, nullptr);
            }

            for (auto const &[name, texture]: m_textures) {
                vmaDestroyImage(m_allocator, std::bit_cast<VkImage>(texture.image.image), texture.image.allocation);
                m_device.destroy(texture.image_view);
            }
            m_device.destroy(m_sampler);

            m_device.destroy(m_main_descriptor_set_layout);
            m_device.destroy(m_lighting_descriptor_set_layout);
            m_device.destroy(m_descriptor_pool);

            m_device.destroy(m_swapchain);
            m_device.destroy(m_render_pass);

            cleanup_render_targets();

            for (auto &[name, mesh]: m_meshes) {
                vmaDestroyBuffer(m_allocator, std::bit_cast<VkBuffer>(mesh.vertex_buffer.buffer),
                                 mesh.vertex_buffer.allocation);
                vmaDestroyBuffer(m_allocator, std::bit_cast<VkBuffer>(mesh.index_buffer.buffer),
                                 mesh.index_buffer.allocation);
            }

            for (auto &frame: m_frames) {
                vmaUnmapMemory(m_allocator, frame.camera_buffer.allocation);
                vmaUnmapMemory(m_allocator, frame.object_buffer.allocation);
                vmaUnmapMemory(m_allocator, frame.scene_buffer.allocation);
                vmaUnmapMemory(m_allocator, frame.lighting_buffer.allocation);
                vmaDestroyBuffer(m_allocator, std::bit_cast<VkBuffer>(frame.camera_buffer.buffer),
                                 frame.camera_buffer.allocation);
                vmaDestroyBuffer(m_allocator, std::bit_cast<VkBuffer>(frame.object_buffer.buffer),
                                 frame.object_buffer.allocation);

                vmaDestroyBuffer(m_allocator, std::bit_cast<VkBuffer>(frame.scene_buffer.buffer),
                                 frame.scene_buffer.allocation);
                vmaDestroyBuffer(m_allocator, std::bit_cast<VkBuffer>(frame.lighting_buffer.buffer),
                                 frame.lighting_buffer.allocation);
            }
            vmaDestroyAllocator(m_allocator);

            m_device.destroy();
            m_instance.destroy(m_surface, nullptr);
            if constexpr (ENABLE_VALIDATION_LAYERS) {
                vk::DispatchLoaderDynamic const instance_loader(m_instance, vkGetInstanceProcAddr);
                m_instance.destroyDebugUtilsMessengerEXT(m_debug_messenger, nullptr, instance_loader);
            }
            m_instance.destroy();
        };

        void draw(entt::registry &registry, GameState const &game_state) {
            static bool out_of_date_swapchain = false;

            vk::Result result = {};

            auto &frame = get_current_frame();
            uint32_t swapchain_image_index = 0;
            constexpr auto swapchain_timeout = 100ULL * 1000ULL * 1000ULL * 1000ULL;
            do {
                if (out_of_date_swapchain) {
                    recreate_swapchain();
                }
                result = m_device.acquireNextImageKHR(m_swapchain, swapchain_timeout,
                                                      frame.present_semaphore, nullptr,
                                                      &swapchain_image_index);
                out_of_date_swapchain = result == vk::Result::eErrorOutOfDateKHR || result == vk::Result::eSuboptimalKHR;
            } while (out_of_date_swapchain);

            if (result == vk::Result::eTimeout) {
                utils::log_info("Swapchain timeout retry later");
                return;
            }

            utils::vk_assert(result);

            bool texture_updated = false;
            m_uploader->poll_uploads(m_meshes, m_textures, texture_updated);
            if (texture_updated) {
                m_texture_update++;
            }


            constexpr auto fence_timeout = 1000ULL * 1000ULL * 1000ULL;
            result = m_device.waitForFences(1, &frame.render_fence, true, fence_timeout);
            utils::vk_assert(result);

            result = m_device.resetFences(1, &frame.render_fence);
            utils::vk_assert(result);

            if (m_texture_update != frame.texture_update) {
                update_texture_descriptors(frame.main_descriptor, frame.material_indices);
                frame.texture_update = m_texture_update;
            }

            m_device.resetCommandPool(frame.command_pool, {});
            vk::CommandBuffer const cmd = frame.main_command_buffer;

            vk::CommandBufferBeginInfo const cmd_begin_info = {
                    .flags = vk::CommandBufferUsageFlagBits::eOneTimeSubmit,
            };

            result = cmd.begin(&cmd_begin_info);
            utils::vk_assert(result);

            vk::Viewport const viewport = {
                    .width = static_cast<float>(m_window_extent.width),
                    .height = static_cast<float>(m_window_extent.height),
                    .minDepth = 0.0F,
                    .maxDepth = 1.0F,
            };
            cmd.setViewport(0, 1, &viewport);

            vk::Rect2D const scissor = {
                    .offset = vk::Offset2D{0, 0},
                    .extent = m_window_extent,
            };
            cmd.setScissor(0, 1, &scissor);

            vk::ClearColorValue color_value = {};
            color_value.setFloat32({0.0F, 0.0F, 0.0F, 1.0F});
            vk::ClearValue const color_clear = {
                    .color = color_value,
            };
            vk::ClearValue const present_clear = {
                    .color = color_value,
            };
            vk::ClearValue const normal_clear = {
                    .color = color_value,
            };

            vk::ClearValue const depth_clear{
                    .depthStencil = {1.0F},
            };

            std::array<vk::ClearValue, 4> clear_values = {color_clear, present_clear, depth_clear, normal_clear};

            vk::Rect2D const render_area = {
                    .offset = {0, 0},
                    .extent = m_window_extent,
            };
            vk::RenderPassBeginInfo const rp_info = {
                    .renderPass = m_render_pass,
                    .framebuffer = m_framebuffers[swapchain_image_index],
                    .renderArea = render_area,
                    .clearValueCount = clear_values.size(),
                    .pClearValues = clear_values.data(),
            };
            cmd.beginRenderPass(&rp_info, vk::SubpassContents::eInline);


            auto &camera = game_state.camera;

            glm::mat4 translate = glm::translate(glm::mat4(1.0F), camera.position);
            glm::mat4 rotate = glm::mat4_cast(camera.rotation);
            glm::mat4 view = rotate * translate;

            glm::mat4 projection = glm::perspective(glm::radians(camera.fov), (float) m_window_extent.width / (float) m_window_extent.height, 0.1F, 20.0F);

            projection[1][1] *= -1;
            GPUCamera gpu_cam = {.view = view, .proj = projection, .inv_view_proj = glm::inverse(projection * view)};

            // Update uniform buffers
            memcpy(frame.mapped_camera_buffer, &gpu_cam, sizeof(GPUCamera));

            memcpy(frame.mapped_scene_buffer, &game_state.scene_data, sizeof(SceneData));

            memcpy(frame.mapped_lighting_buffer, &game_state.lighting_buffer, sizeof(LightingBuffer));

            draw_objects(cmd, registry);

            // Calculate lighting
            cmd.nextSubpass(vk::SubpassContents::eInline);
            cmd.bindPipeline(vk::PipelineBindPoint::eGraphics, m_materials["lighting"].pipeline);
            // Bind descriptors
            cmd.bindDescriptorSets(vk::PipelineBindPoint::eGraphics, *m_materials["lighting"].pipeline_layout, 0, 1, &frame.lighting_descriptor, 0, nullptr);
            cmd.draw(3, 1, 0, 0);


            cmd.endRenderPass();
            utils::vk_assert(cmd.end());

            vk::PipelineStageFlags const wait_stage = vk::PipelineStageFlagBits::eColorAttachmentOutput;

            vk::SubmitInfo const submit = {
                    .waitSemaphoreCount = 1,
                    .pWaitSemaphores = &frame.present_semaphore,
                    .pWaitDstStageMask = &wait_stage,
                    .commandBufferCount = 1,
                    .pCommandBuffers = &cmd,
                    .signalSemaphoreCount = 1,
                    .pSignalSemaphores = &frame.render_semaphore,
            };

            {
                std::scoped_lock<std::mutex> const guard(m_graphics_queue_mutex);
                result = m_graphics_queue.submit(1, &submit, frame.render_fence);
                utils::vk_assert(result);
            }

            vk::PresentInfoKHR const present_info = {
                    .waitSemaphoreCount = 1,
                    .pWaitSemaphores = &frame.render_semaphore,
                    .swapchainCount = 1,
                    .pSwapchains = &m_swapchain,
                    .pImageIndices = &swapchain_image_index,
            };
            m_frame_number++;

            result = m_graphics_queue.presentKHR(&present_info);
            if (result == vk::Result::eErrorOutOfDateKHR || result == vk::Result::eSuboptimalKHR) {
                out_of_date_swapchain = true;
            } else {
                utils::vk_assert(result);
            }
        };

        Material *get_material(std::string_view name) {
            auto const it = m_materials.find(std::string{name});
            if (it == m_materials.end()) {
                return nullptr;
            }
            return &it->second;
        };

        void load_mesh(std::string_view name) {
            auto const it = m_meshes.find(std::string{name});
            if (it == m_meshes.end()) {
                m_meshes[std::string{name}];
                m_uploader->queue_mesh_upload(name);
            }
        };

        void load_texture(std::string_view name) {
            auto const it = m_textures.find(std::string{name});
            if (it == m_textures.end()) {
                m_textures[std::string{name}];
                m_uploader->queue_image_upload(name);
            }
        };

        void recreate_swapchain() {
            utils::log_info("Recreate swapchain");
            std::scoped_lock<std::mutex> const guard(m_graphics_queue_mutex);
            utils::vk_assert(m_device.waitIdle());
            cleanup_render_targets();
            init_swapchain();
            init_framebuffers();
            write_lighting_image_view_descriptors();
        };

        void set_extent(vk::Extent2D window_extent) {
            m_window_extent = window_extent;
        };

    private:
        vk::Extent2D m_window_extent;

        vk::Instance m_instance;
        vk::DebugUtilsMessengerEXT m_debug_messenger;
        vk::Device m_device;
        vk::PhysicalDevice m_physical_device;
        vk::PhysicalDeviceProperties m_gpu_properties;

        vk::SurfaceKHR m_surface = nullptr;

        vk::SwapchainKHR m_swapchain = nullptr;
        vk::Format m_swapchain_format = vk::Format::eUndefined;
        std::vector<vk::Image> m_swapchain_images;
        std::vector<vk::ImageView> m_swapchain_image_views;
        std::array<FrameData, FRAME_OVERLAP> m_frames;
        size_t m_frame_number = 0;

        AllocatedImage m_color_image;
        vk::ImageView m_color_image_view;

        AllocatedImage m_normals_image;
        vk::ImageView m_normals_image_view;

        vk::ImageView m_depth_image_view;
        AllocatedImage m_depth_image;
        vk::Format m_depth_format = vk::Format::eUndefined;

        vk::SampleCountFlagBits m_msaa_samples = vk::SampleCountFlagBits::e4;

        std::mutex m_graphics_queue_mutex;
        vk::Queue m_graphics_queue;
        uint32_t m_graphics_queue_family = 0;

        vk::RenderPass m_render_pass;
        std::vector<vk::Framebuffer> m_framebuffers;

        VmaAllocator m_allocator = nullptr;

        std::unordered_map<std::string, Material> m_materials;
        std::list<vk::PipelineLayout> m_pipeline_layouts;
        std::unordered_map<std::string, GPUMesh> m_meshes;
        std::unordered_map<std::string, GPUTexture> m_textures;
        uint32_t m_texture_update = 0;
        vk::Sampler m_sampler;

        vk::DescriptorSetLayout m_main_descriptor_set_layout;
        vk::DescriptorSetLayout m_lighting_descriptor_set_layout;
        vk::DescriptorPool m_descriptor_pool;

        std::optional<Uploader> m_uploader;

        FrameData &get_current_frame() {
            return m_frames[m_frame_number % FRAME_OVERLAP];
        }

        void draw_objects(vk::CommandBuffer cmd, entt::registry &registry) {
            auto &frame = get_current_frame();

            auto const view = registry.view<Model, Transform>();

            auto *object_ssbo = std::bit_cast<glm::mat4 *>(frame.mapped_object_buffer);
            uint32_t index = 0;
            for (auto entity: view) {
                auto &model = view.get<Model>(entity);
                auto *mesh = &m_meshes[model.mesh];
                auto *texture = &m_textures[model.albedo_texture];
                auto transform = view.get<Transform>(entity);
                auto object_matrix = glm::translate(glm::mat4{1.0}, transform.position) * glm::toMat4(transform.rotation) * transform.scale;
                object_ssbo[index] = object_matrix;
                // Skip if upload is not completed
                if ((mesh->vertex_buffer.buffer == nullptr) || (mesh->index_buffer.buffer == nullptr) ||
                    !texture->image.image) {
                    continue;
                }
                index++;
            }

            GPUMesh const *last_mesh = nullptr;
            Material const *last_material = nullptr;

            index = 0;
            auto *material = &m_materials["default_material"];
            for (auto [entity, model, transform]: view.each()) {
                auto *mesh = &m_meshes[model.mesh];
                auto *texture = &m_textures[model.albedo_texture];

                if ((mesh->vertex_buffer.buffer == nullptr) || (mesh->index_buffer.buffer == nullptr) ||
                    !texture->image.image) {
                    continue;
                }
                if (material != last_material) {
                    cmd.bindPipeline(vk::PipelineBindPoint::eGraphics, material->pipeline);
                    last_material = material;
                    std::array<vk::DescriptorSet, 1> descriptor_sets = {frame.main_descriptor};
                    cmd.bindDescriptorSets(vk::PipelineBindPoint::eGraphics, *material->pipeline_layout, 0, descriptor_sets.size(),
                                           descriptor_sets.data(), 0,
                                           nullptr);
                }

                MeshPushConstants constants{};
                constants.albedo_index = frame.material_indices[texture];
                constants.buffer_offset = index;
                cmd.pushConstants(*material->pipeline_layout,
                                  vk::ShaderStageFlagBits::eVertex | vk::ShaderStageFlagBits::eFragment, 0,
                                  sizeof(MeshPushConstants), &constants);

                if (mesh != last_mesh) {
                    vk::DeviceSize const offset = 0;
                    cmd.bindVertexBuffers(0, 1, std::bit_cast<vk::Buffer const *>(&mesh->vertex_buffer.buffer),
                                          &offset);
                    cmd.bindIndexBuffer(std::bit_cast<vk::Buffer>(mesh->index_buffer.buffer), 0, vk::IndexType::eUint32);
                    last_mesh = mesh;
                }
                cmd.drawIndexed(mesh->index_count, 1, mesh->first_index, mesh->vertex_offset, 0);
                index++;
            }
        };

        static bool is_device_supported(vk::PhysicalDevice const &device) {
            uint32_t extension_count = 0;
            auto result = device.enumerateDeviceExtensionProperties(nullptr, &extension_count, nullptr);
            utils::vk_assert(result);

            std::vector<vk::ExtensionProperties> available_extensions(extension_count);
            result = device.enumerateDeviceExtensionProperties(nullptr, &extension_count, available_extensions.data());
            utils::vk_assert(result);

            std::set<std::string, std::less<>> required_extensions{};
            auto device_extensions = get_required_device_extensions();
            required_extensions.insert(device_extensions.begin(), device_extensions.end());

            for (auto const &extension: available_extensions) {
                required_extensions.erase(extension.extensionName);
            }

            return required_extensions.empty();
        };

        static std::vector<char const *> get_required_extensions() {
            uint32_t glfw_extension_count = 0;
            char const **glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);
            std::vector<char const *> extensions(glfw_extensions, glfw_extensions + glfw_extension_count);

            if constexpr (ENABLE_VALIDATION_LAYERS) {
                extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
            }

            return extensions;
        };

        static std::vector<char const *> get_required_device_extensions() {
            std::vector<char const *> extensions;
            extensions.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
            extensions.push_back(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME);
            return extensions;
        };

        vk::SurfaceFormatKHR get_swapchain_format() const {
            auto [result, available_formats] = m_physical_device.getSurfaceFormatsKHR(m_surface);
            utils::vk_assert(result);

            for (auto const &format: available_formats) {
                if ((format.format == vk::Format::eB8G8R8A8Srgb || format.format == vk::Format::eR8G8B8A8Srgb) &&
                    format.colorSpace == vk::ColorSpaceKHR::eSrgbNonlinear) {
                    return format;
                }
            }
            return available_formats[0];
        };

        void init_instance(GLFWwindow *window) {
            vk::DynamicLoader dl;
            auto vkGetInstanceProcAddr = dl.getProcAddress<PFN_vkGetInstanceProcAddr>("vkGetInstanceProcAddr");
            VULKAN_HPP_DEFAULT_DISPATCHER.init(vkGetInstanceProcAddr);

            vk::ApplicationInfo const app_info = {
                    .pApplicationName = "lime-game",
                    .applicationVersion = 1,
                    .pEngineName = "lime-engine",
                    .engineVersion = 1,
                    .apiVersion = VK_API_VERSION_1_3,
            };

            auto extensions = get_required_extensions();

            vk::InstanceCreateInfo create_info = {
                    .pApplicationInfo = &app_info,
                    .enabledExtensionCount = static_cast<uint32_t>(extensions.size()),
                    .ppEnabledExtensionNames = extensions.data(),
            };

            vk::DebugUtilsMessengerCreateInfoEXT debug_create_info = {};
            std::vector<char const *> layers = {"VK_LAYER_KHRONOS_validation"};

            if constexpr (ENABLE_VALIDATION_LAYERS) {
                debug_create_info = {
                        .messageSeverity = vk::DebugUtilsMessageSeverityFlagBitsEXT::eError |
                                           vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning,
                        .messageType = vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral |
                                       vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance |
                                       vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation,
                        .pfnUserCallback = debug_callback,
                };

                create_info.enabledLayerCount = static_cast<uint32_t>(layers.size());
                create_info.ppEnabledLayerNames = layers.data();
                create_info.pNext = &debug_create_info;
            }
            auto result = vk::createInstance(&create_info, nullptr, &m_instance);
            utils::vk_assert(result);
            VULKAN_HPP_DEFAULT_DISPATCHER.init(m_instance);

            if constexpr (ENABLE_VALIDATION_LAYERS) {
                vk::DispatchLoaderDynamic const instance_loader(m_instance, vkGetInstanceProcAddr);
                auto test = m_instance.createDebugUtilsMessengerEXT(&debug_create_info, nullptr, &m_debug_messenger,
                                                                    instance_loader);
                utils::vk_assert(test);
            }

            VkResult const err = glfwCreateWindowSurface(std::bit_cast<VkInstance>(m_instance), window, nullptr,
                                                         std::bit_cast<VkSurfaceKHR *>(&m_surface));
            if (err != VK_SUCCESS) {
                abort();
            }
        };

        void init_device() {
            uint32_t device_count = 0;
            auto result = m_instance.enumeratePhysicalDevices(&device_count, nullptr);
            utils::vk_assert(result);
            utils::assert_true(device_count != 0);

            auto [device_result, devices] = m_instance.enumeratePhysicalDevices();
            utils::vk_assert(device_result);
            int best_device_rating = -1;
            bool found_device = false;
            for (auto const &device: devices) {
                if (is_device_supported(device)) {
                    auto properties = device.getProperties();
                    int device_rating;
                    switch (properties.deviceType) {
                        case vk::PhysicalDeviceType::eDiscreteGpu:
                            device_rating = 2;
                            break;
                        case vk::PhysicalDeviceType::eIntegratedGpu:
                            device_rating = 1;
                            break;
                        default:
                            device_rating = 0;
                            break;
                    }
                    if (device_rating > best_device_rating) {
                        best_device_rating = device_rating;
                        m_physical_device = device;
                        m_gpu_properties = properties;
                        found_device = true;
                    }
                }
            }
            utils::log_info("Using: " + std::string{m_gpu_properties.deviceName});
            utils::assert_true(found_device);

            auto queue_families = m_physical_device.getQueueFamilyProperties();

            bool found_queue_family = false;
            for (uint32_t i = 0; i < queue_families.size(); i++) {
                auto flags = queue_families[i].queueFlags;
                if (flags & vk::QueueFlagBits::eGraphics && flags & vk::QueueFlagBits::eTransfer) {
                    m_graphics_queue_family = i;
                    found_queue_family = true;
                }
            }
            utils::assert_true(found_queue_family);

            float const queue_priority = 1.0F;
            vk::DeviceQueueCreateInfo const queue_info{
                    .queueFamilyIndex = m_graphics_queue_family,
                    .queueCount = 1,
                    .pQueuePriorities = &queue_priority,
            };

            auto device_extensions = get_required_device_extensions();

            vk::PhysicalDeviceVulkan12Features v12_device_features = {
                    .descriptorIndexing = true,
                    .shaderSampledImageArrayNonUniformIndexing = true,
                    .descriptorBindingPartiallyBound = true,
                    .descriptorBindingVariableDescriptorCount = true,
                    .runtimeDescriptorArray = true,
            };

            vk::PhysicalDeviceShaderDrawParametersFeatures shader_draw_parameters_features{
                    .pNext = &v12_device_features,
                    .shaderDrawParameters = true,
            };

            vk::PhysicalDeviceFeatures const device_features = {
                    .samplerAnisotropy = true,
            };

            vk::DeviceCreateInfo const create_info = {
                    .pNext = &shader_draw_parameters_features,
                    .queueCreateInfoCount = 1,
                    .pQueueCreateInfos = &queue_info,
                    .enabledExtensionCount = static_cast<uint32_t>(device_extensions.size()),
                    .ppEnabledExtensionNames = device_extensions.data(),
                    .pEnabledFeatures = &device_features,
            };

            result = m_physical_device.createDevice(&create_info, nullptr, &m_device);
            utils::vk_assert(result);
            VULKAN_HPP_DEFAULT_DISPATCHER.init(m_device);

            m_graphics_queue = m_device.getQueue(m_graphics_queue_family, 0);
        };

        void init_vma() {
            VmaAllocatorCreateInfo allocator_info = {};
            VmaVulkanFunctions vma_vulkan_functions = {
                    .vkGetPhysicalDeviceProperties = vkGetPhysicalDeviceProperties,
                    .vkGetPhysicalDeviceMemoryProperties = vkGetPhysicalDeviceMemoryProperties,
                    .vkAllocateMemory = vkAllocateMemory,
                    .vkFreeMemory = vkFreeMemory,
                    .vkMapMemory = vkMapMemory,
                    .vkUnmapMemory = vkUnmapMemory,
                    .vkFlushMappedMemoryRanges = vkFlushMappedMemoryRanges,
                    .vkInvalidateMappedMemoryRanges = vkInvalidateMappedMemoryRanges,
                    .vkBindBufferMemory = vkBindBufferMemory,
                    .vkBindImageMemory = vkBindImageMemory,
                    .vkGetBufferMemoryRequirements = vkGetBufferMemoryRequirements,
                    .vkGetImageMemoryRequirements = vkGetImageMemoryRequirements,
                    .vkCreateBuffer = vkCreateBuffer,
                    .vkDestroyBuffer = vkDestroyBuffer,
                    .vkCreateImage = vkCreateImage,
                    .vkDestroyImage = vkDestroyImage,
                    .vkCmdCopyBuffer = vkCmdCopyBuffer,
            };

            allocator_info.physicalDevice = m_physical_device;
            allocator_info.device = m_device;
            allocator_info.instance = m_instance;
            allocator_info.pVulkanFunctions = &vma_vulkan_functions;
            vmaCreateAllocator(&allocator_info, &m_allocator);
        };

        void init_swapchain() {
            vk::SurfaceFormatKHR const surface_format = get_swapchain_format();
            vk::PresentModeKHR const present_mode = vk::PresentModeKHR::eFifo;

            auto [result, surface_capabilities] = m_physical_device.getSurfaceCapabilitiesKHR(m_surface);
            utils::vk_assert(result);
            uint32_t image_count = surface_capabilities.minImageCount;
            if (image_count <= 2) {
                image_count = 2;
            }

            m_window_extent = {
                    std::clamp(m_window_extent.width, surface_capabilities.minImageExtent.width, surface_capabilities.maxImageExtent.width),
                    std::clamp(m_window_extent.height, surface_capabilities.minImageExtent.height, surface_capabilities.maxImageExtent.height),
            };
            vk::Extent2D min_extent = {0, 0};
            vk::Extent2D max_extent = {0xFFFFFFFF, 0xFFFFFFFF};
            if (surface_capabilities.currentExtent != min_extent && surface_capabilities.currentExtent != max_extent) {
                m_window_extent = surface_capabilities.currentExtent;
            }

            auto old_swapchain = m_swapchain;
            vk::SwapchainCreateInfoKHR const create_info{
                    .surface = m_surface,
                    .minImageCount = image_count,
                    .imageFormat = surface_format.format,
                    .imageColorSpace = surface_format.colorSpace,
                    .imageExtent = m_window_extent,
                    .imageArrayLayers = 1,
                    .imageUsage = vk::ImageUsageFlagBits::eColorAttachment,
                    .imageSharingMode = vk::SharingMode::eExclusive,
                    .preTransform = vk::SurfaceTransformFlagBitsKHR::eIdentity,
                    .compositeAlpha = vk::CompositeAlphaFlagBitsKHR::eOpaque,
                    .presentMode = present_mode,
                    .clipped = true,
                    .oldSwapchain = m_swapchain,
            };

            result = m_device.createSwapchainKHR(&create_info, nullptr, &m_swapchain);
            utils::vk_assert(result);

            if (old_swapchain) {
                m_device.destroy(old_swapchain);
            }

            std::tie(result, m_swapchain_images) = m_device.getSwapchainImagesKHR(m_swapchain);
            utils::vk_assert(result);
            m_swapchain_format = surface_format.format;

            m_swapchain_image_views.resize(m_swapchain_images.size());

            vk::ImageSubresourceRange const subresource_range_swapchain = {
                    .aspectMask = vk::ImageAspectFlagBits::eColor,
                    .baseMipLevel = 0,
                    .levelCount = 1,
                    .baseArrayLayer = 0,
                    .layerCount = 1,
            };
            for (size_t i = 0; i < m_swapchain_images.size(); i++) {
                using enum vk::ComponentSwizzle;
                vk::ImageViewCreateInfo const image_view_info{
                        .image = m_swapchain_images[i],
                        .viewType = vk::ImageViewType::e2D,
                        .format = m_swapchain_format,
                        .components = {eIdentity, eIdentity,
                                       eIdentity, eIdentity},
                        .subresourceRange = subresource_range_swapchain,
                };
                result = m_device.createImageView(&image_view_info, nullptr, &m_swapchain_image_views[i]);
                utils::vk_assert(result);
            }

            // Albedo
            vk::Extent3D const image_extent = {
                    m_window_extent.width,
                    m_window_extent.height,
                    1,
            };

            vk::ImageCreateInfo cimg_info = {
                    .imageType = vk::ImageType::e2D,
                    .format = vk::Format::eR8G8B8A8Unorm,
                    .extent = image_extent,
                    .mipLevels = 1,
                    .arrayLayers = 1,
                    .samples = m_msaa_samples,
                    .tiling = vk::ImageTiling::eOptimal,
                    .usage = vk::ImageUsageFlagBits::eTransientAttachment | vk::ImageUsageFlagBits::eColorAttachment | vk::ImageUsageFlagBits::eInputAttachment,
            };

            VmaAllocationCreateInfo const alloc_info = {
                    .usage = VMA_MEMORY_USAGE_GPU_ONLY,
                    .requiredFlags = VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                    .preferredFlags = VkMemoryPropertyFlagBits::VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT,
            };

            auto vma_result = vmaCreateImage(m_allocator, std::bit_cast<VkImageCreateInfo const *>(&cimg_info), &alloc_info,
                                             std::bit_cast<VkImage *>(&m_color_image.image), &m_color_image.allocation,
                                             nullptr);
            utils::vk_assert(std::bit_cast<vk::Result>(vma_result));

            vk::ImageSubresourceRange const color_subresource_range = {
                    .aspectMask = vk::ImageAspectFlagBits::eColor,
                    .baseMipLevel = 0,
                    .levelCount = 1,
                    .baseArrayLayer = 0,
                    .layerCount = 1,
            };

            vk::ImageViewCreateInfo color_view_info = {
                    .image = m_color_image.image,
                    .viewType = vk::ImageViewType::e2D,
                    .format = vk::Format::eR8G8B8A8Unorm,
                    .subresourceRange = color_subresource_range,
            };

            result = m_device.createImageView(&color_view_info, nullptr, &m_color_image_view);
            utils::vk_assert(result);

            // Normals
            cimg_info.format = vk::Format::eA2B10G10R10UnormPack32;
            vma_result = vmaCreateImage(m_allocator, std::bit_cast<VkImageCreateInfo const *>(&cimg_info), &alloc_info,
                                        std::bit_cast<VkImage *>(&m_normals_image.image), &m_normals_image.allocation,
                                        nullptr);
            utils::vk_assert(std::bit_cast<vk::Result>(vma_result));

            color_view_info.image = m_normals_image.image;
            color_view_info.format = vk::Format::eA2B10G10R10UnormPack32;

            result = m_device.createImageView(&color_view_info, nullptr, &m_normals_image_view);
            utils::vk_assert(result);


            // Depth target
            m_depth_format = vk::Format::eD32Sfloat;

            vk::ImageCreateInfo const depth_img_info = {
                    .imageType = vk::ImageType::e2D,
                    .format = m_depth_format,
                    .extent = image_extent,
                    .mipLevels = 1,
                    .arrayLayers = 1,
                    .samples = m_msaa_samples,
                    .tiling = vk::ImageTiling::eOptimal,
                    .usage = vk::ImageUsageFlagBits::eTransientAttachment | vk::ImageUsageFlagBits::eDepthStencilAttachment | vk::ImageUsageFlagBits::eInputAttachment,
            };

            vma_result = vmaCreateImage(m_allocator, std::bit_cast<VkImageCreateInfo const *>(&depth_img_info), &alloc_info,
                                        std::bit_cast<VkImage *>(&m_depth_image.image), &m_depth_image.allocation, nullptr);
            utils::vk_assert(std::bit_cast<vk::Result>(vma_result));

            vk::ImageSubresourceRange const depth_subresource_range = {
                    .aspectMask = vk::ImageAspectFlagBits::eDepth,
                    .baseMipLevel = 0,
                    .levelCount = 1,
                    .baseArrayLayer = 0,
                    .layerCount = 1,
            };

            vk::ImageViewCreateInfo const depth_view_info = {
                    .image = m_depth_image.image,
                    .viewType = vk::ImageViewType::e2D,
                    .format = m_depth_format,
                    .subresourceRange = depth_subresource_range,
            };

            result = m_device.createImageView(&depth_view_info, nullptr, &m_depth_image_view);
            utils::vk_assert(result);
        };

        void cleanup_render_targets() {
            for (auto const &framebuffer: m_framebuffers) {
                m_device.destroy(framebuffer);
            }
            for (auto const &image_view: m_swapchain_image_views) {
                m_device.destroy(image_view);
            }
            m_device.destroy(m_color_image_view);
            m_device.destroy(m_normals_image_view);
            m_device.destroy(m_depth_image_view);
            vmaDestroyImage(m_allocator, std::bit_cast<VkImage>(m_color_image.image), m_color_image.allocation);
            vmaDestroyImage(m_allocator, std::bit_cast<VkImage>(m_normals_image.image), m_normals_image.allocation);
            vmaDestroyImage(m_allocator, std::bit_cast<VkImage>(m_depth_image.image), m_depth_image.allocation);
        };

        void init_commands() {
            vk::CommandPoolCreateInfo const cmd_pool_info = {
                    .queueFamilyIndex = m_graphics_queue_family,
            };

            for (auto &mFrame: m_frames) {
                auto result = m_device.createCommandPool(&cmd_pool_info, nullptr, &mFrame.command_pool);
                utils::vk_assert(result);

                vk::CommandBufferAllocateInfo const cmd_alloc_info = {
                        .commandPool = mFrame.command_pool,
                        .level = vk::CommandBufferLevel::ePrimary,
                        .commandBufferCount = 1,
                };

                result = m_device.allocateCommandBuffers(&cmd_alloc_info,
                                                         &mFrame.main_command_buffer);
                utils::vk_assert(result);
            }
        };

        void init_renderpass() {
            vk::AttachmentDescription const color_attachment = {
                    .format = vk::Format::eR8G8B8A8Unorm,
                    .samples = m_msaa_samples,
                    .loadOp = vk::AttachmentLoadOp::eClear,
                    .storeOp = vk::AttachmentStoreOp::eDontCare,
                    .stencilLoadOp = vk::AttachmentLoadOp::eDontCare,
                    .stencilStoreOp = vk::AttachmentStoreOp::eDontCare,
                    .initialLayout = vk::ImageLayout::eUndefined,
                    .finalLayout = vk::ImageLayout::eShaderReadOnlyOptimal,
            };

            vk::AttachmentReference const color_attachment_ref = {
                    .attachment = 0,
                    .layout = vk::ImageLayout::eColorAttachmentOptimal,
            };

            vk::AttachmentDescription const normal_attachment = {
                    .format = vk::Format::eA2B10G10R10UnormPack32,
                    .samples = m_msaa_samples,
                    .loadOp = vk::AttachmentLoadOp::eClear,
                    .storeOp = vk::AttachmentStoreOp::eDontCare,
                    .stencilLoadOp = vk::AttachmentLoadOp::eDontCare,
                    .stencilStoreOp = vk::AttachmentStoreOp::eDontCare,
                    .initialLayout = vk::ImageLayout::eUndefined,
                    .finalLayout = vk::ImageLayout::eShaderReadOnlyOptimal,
            };

            vk::AttachmentReference const normal_attachment_ref = {
                    .attachment = 3,
                    .layout = vk::ImageLayout::eColorAttachmentOptimal,
            };

            vk::AttachmentDescription const present_attachment = {
                    .format = m_swapchain_format,
                    .samples = vk::SampleCountFlagBits::e1,
                    .loadOp = vk::AttachmentLoadOp::eDontCare,
                    .storeOp = vk::AttachmentStoreOp::eStore,
                    .stencilLoadOp = vk::AttachmentLoadOp::eDontCare,
                    .stencilStoreOp = vk::AttachmentStoreOp::eDontCare,
                    .initialLayout = vk::ImageLayout::eUndefined,
                    .finalLayout = vk::ImageLayout::ePresentSrcKHR,
            };

            vk::AttachmentReference const present_attachment_ref = {
                    .attachment = 1,
                    .layout = vk::ImageLayout::eColorAttachmentOptimal,
            };

            vk::AttachmentDescription const depth_attachment = {
                    .format = m_depth_format,
                    .samples = m_msaa_samples,
                    .loadOp = vk::AttachmentLoadOp::eClear,
                    .storeOp = vk::AttachmentStoreOp::eDontCare,
                    .stencilLoadOp = vk::AttachmentLoadOp::eDontCare,
                    .stencilStoreOp = vk::AttachmentStoreOp::eDontCare,
                    .initialLayout = vk::ImageLayout::eUndefined,
                    .finalLayout = vk::ImageLayout::eDepthReadOnlyStencilAttachmentOptimal,
            };

            vk::AttachmentReference const depth_attachment_ref = {
                    .attachment = 2,
                    .layout = vk::ImageLayout::eDepthStencilAttachmentOptimal,
            };
            std::array<vk::AttachmentReference, 2> geometry_attachments = {color_attachment_ref, normal_attachment_ref};

            // Geometry
            vk::SubpassDescription const geometry_subpass = {
                    .pipelineBindPoint = vk::PipelineBindPoint::eGraphics,
                    .colorAttachmentCount = geometry_attachments.size(),
                    .pColorAttachments = geometry_attachments.data(),
                    .pDepthStencilAttachment = &depth_attachment_ref,
            };


            // Lighting
            vk::AttachmentReference const normal_attachment_readonly_ref = {
                    .attachment = 3,
                    .layout = vk::ImageLayout::eShaderReadOnlyOptimal,
            };

            vk::AttachmentReference const color_attachment_readonly_ref = {
                    .attachment = 0,
                    .layout = vk::ImageLayout::eShaderReadOnlyOptimal,
            };

            vk::AttachmentReference const depth_attachment_readonly_ref = {
                    .attachment = 2,
                    .layout = vk::ImageLayout::eDepthStencilReadOnlyOptimal,
            };

            std::array<vk::AttachmentReference, 3> lighting_input_attachments = {color_attachment_readonly_ref, normal_attachment_readonly_ref, depth_attachment_readonly_ref};

            vk::SubpassDescription const lighting_subpass = {
                    .pipelineBindPoint = vk::PipelineBindPoint::eGraphics,
                    .inputAttachmentCount = lighting_input_attachments.size(),
                    .pInputAttachments = lighting_input_attachments.data(),
                    .colorAttachmentCount = 1,
                    .pColorAttachments = &present_attachment_ref,
            };

            // Dependencies
            vk::SubpassDependency const dependency = {
                    .srcSubpass = 0,
                    .dstSubpass = 1,
                    .srcStageMask = vk::PipelineStageFlagBits::eColorAttachmentOutput | vk::PipelineStageFlagBits::eEarlyFragmentTests | vk::PipelineStageFlagBits::eLateFragmentTests,
                    .dstStageMask = vk::PipelineStageFlagBits::eFragmentShader | vk::PipelineStageFlagBits::eColorAttachmentOutput | vk::PipelineStageFlagBits::eEarlyFragmentTests | vk::PipelineStageFlagBits::eLateFragmentTests,
                    .srcAccessMask = vk::AccessFlagBits::eColorAttachmentWrite | vk::AccessFlagBits::eDepthStencilAttachmentWrite,
                    .dstAccessMask = vk::AccessFlagBits::eInputAttachmentRead | vk::AccessFlagBits::eColorAttachmentRead | vk::AccessFlagBits::eDepthStencilAttachmentWrite | vk::AccessFlagBits::eDepthStencilAttachmentRead | vk::AccessFlagBits::eDepthStencilAttachmentWrite,
                    .dependencyFlags = vk::DependencyFlagBits::eByRegion,
            };

            std::array<vk::SubpassDependency, 1> dependencies = {dependency};
            std::array<vk::AttachmentDescription, 4> attachments = {color_attachment, present_attachment, depth_attachment, normal_attachment};

            std::array<vk::SubpassDescription, 2> subpasses = {geometry_subpass, lighting_subpass};

            vk::RenderPassCreateInfo const render_pass_info = {
                    .attachmentCount = attachments.size(),
                    .pAttachments = attachments.data(),
                    .subpassCount = subpasses.size(),
                    .pSubpasses = subpasses.data(),
                    .dependencyCount = dependencies.size(),
                    .pDependencies = dependencies.data(),
            };

            auto result = m_device.createRenderPass(&render_pass_info, nullptr, &m_render_pass);
            utils::vk_assert(result);
        };

        void init_framebuffers() {
            vk::FramebufferCreateInfo fb_info = {
                    .renderPass = m_render_pass,
                    .attachmentCount = 4,
                    .width = m_window_extent.width,
                    .height = m_window_extent.height,
                    .layers = 1,
            };

            auto const swapchain_imagecount = static_cast<uint32_t>(m_swapchain_images.size());
            m_framebuffers = std::vector<vk::Framebuffer>(swapchain_imagecount);

            for (uint32_t i = 0; i < swapchain_imagecount; i++) {
                std::array<vk::ImageView, 4> attachments;
                attachments[0] = m_color_image_view;
                attachments[1] = m_swapchain_image_views[i];
                attachments[2] = m_depth_image_view;
                attachments[3] = m_normals_image_view;
                fb_info.pAttachments = attachments.data();
                auto result = m_device.createFramebuffer(&fb_info, nullptr, &m_framebuffers[i]);
                utils::vk_assert(result);
            }
        };

        void init_sync_structures() {
            vk::FenceCreateInfo const fence_info = {
                    .flags = vk::FenceCreateFlagBits::eSignaled,
            };

            vk::SemaphoreCreateInfo const semaphore_info = {};

            for (auto &mFrame: m_frames) {
                auto result = m_device.createFence(&fence_info, nullptr, &mFrame.render_fence);
                utils::vk_assert(result);


                result = m_device.createSemaphore(&semaphore_info, nullptr, &mFrame.present_semaphore);
                utils::vk_assert(result);

                result = m_device.createSemaphore(&semaphore_info, nullptr, &mFrame.render_semaphore);
                utils::vk_assert(result);
            }
        };

        void init_pipelines() {
            MaterialBuilder::build_materials(m_device, m_render_pass, m_main_descriptor_set_layout, m_lighting_descriptor_set_layout, m_msaa_samples, m_materials,
                                             m_pipeline_layouts);
        };

        void update_texture_descriptors(vk::DescriptorSet descriptor_set,
                                        std::unordered_map<GPUTexture *, uint32_t> &material_indices) {
            std::vector<vk::DescriptorImageInfo> texture_descriptors;
            uint32_t index = 0;
            for (auto &[name, texture]: m_textures) {
                // Skip texture if upload not completed
                if (!texture.image.image) {
                    continue;
                }
                vk::DescriptorImageInfo const image_info = {
                        .sampler = m_sampler,
                        .imageView = texture.image_view,
                        .imageLayout = vk::ImageLayout::eShaderReadOnlyOptimal,
                };
                texture_descriptors.push_back(image_info);
                material_indices[&texture] = index;
                index++;
            }

            vk::WriteDescriptorSet const texture_desc = {
                    .dstSet = descriptor_set,
                    .dstBinding = 3,
                    .descriptorCount = static_cast<uint32_t>(texture_descriptors.size()),
                    .descriptorType = vk::DescriptorType::eCombinedImageSampler,
                    .pImageInfo = texture_descriptors.data(),
            };
            m_device.updateDescriptorSets(1, &texture_desc, 0, nullptr);
        };

        void init_descriptors() {
            std::vector<vk::DescriptorPoolSize> sizes = {
                    {vk::DescriptorType::eUniformBuffer, 10},
                    {vk::DescriptorType::eUniformBufferDynamic, 10},
                    {vk::DescriptorType::eStorageBuffer, 10},
                    {vk::DescriptorType::eInputAttachment, 10},
                    {vk::DescriptorType::eCombinedImageSampler, 128},
            };

            vk::DescriptorPoolCreateInfo const pool_info{
                    .maxSets = 10,
                    .poolSizeCount = static_cast<uint32_t>(sizes.size()),
                    .pPoolSizes = sizes.data(),
            };

            auto result = m_device.createDescriptorPool(&pool_info, nullptr, &m_descriptor_pool);
            utils::vk_assert(result);

            // Main descriptor
            vk::DescriptorSetLayoutBinding const cam_buffer_binding = {
                    .binding = 0,
                    .descriptorType = vk::DescriptorType::eUniformBuffer,
                    .descriptorCount = 1,
                    .stageFlags = vk::ShaderStageFlagBits::eVertex | vk::ShaderStageFlagBits::eFragment,
            };

            vk::DescriptorSetLayoutBinding const object_binding = {
                    .binding = 1,
                    .descriptorType = vk::DescriptorType::eStorageBuffer,
                    .descriptorCount = 1,
                    .stageFlags = vk::ShaderStageFlagBits::eVertex,
            };

            vk::DescriptorSetLayoutBinding const scene_buffer_binding = {
                    .binding = 2,
                    .descriptorType = vk::DescriptorType::eUniformBuffer,
                    .descriptorCount = 1,
                    .stageFlags = vk::ShaderStageFlagBits::eFragment,
            };

            constexpr uint32_t MAX_TEXTURES = 64;
            vk::DescriptorSetLayoutBinding const texture_bind = {
                    .binding = 3,
                    .descriptorType = vk::DescriptorType::eCombinedImageSampler,
                    .descriptorCount = MAX_TEXTURES,
                    .stageFlags = vk::ShaderStageFlagBits::eFragment,
            };

            std::array<vk::DescriptorSetLayoutBinding, 4> bindings = {cam_buffer_binding, object_binding, scene_buffer_binding,
                                                                      texture_bind};

            std::array<vk::DescriptorBindingFlags, 4> flags;
            flags[0] = vk::DescriptorBindingFlags{};
            flags[1] = vk::DescriptorBindingFlags{};
            flags[2] = vk::DescriptorBindingFlags{};
            flags[3] = vk::DescriptorBindingFlagBits::eVariableDescriptorCount | vk::DescriptorBindingFlagBits::ePartiallyBound;
            vk::DescriptorSetLayoutBindingFlagsCreateInfoEXT set_flags = {
                    .bindingCount = flags.size(),
                    .pBindingFlags = flags.data(),
            };
            vk::DescriptorSetLayoutCreateInfo const set_info = {
                    .pNext = &set_flags,
                    .bindingCount = bindings.size(),
                    .pBindings = bindings.data(),
            };

            result = m_device.createDescriptorSetLayout(&set_info, nullptr, &m_main_descriptor_set_layout);
            utils::vk_assert(result);

            // Lighting descriptor
            vk::DescriptorSetLayoutBinding const albedo_binding = {
                    .binding = 1,
                    .descriptorType = vk::DescriptorType::eInputAttachment,
                    .descriptorCount = 1,
                    .stageFlags = vk::ShaderStageFlagBits::eFragment,
            };

            vk::DescriptorSetLayoutBinding const normal_binding = {
                    .binding = 2,
                    .descriptorType = vk::DescriptorType::eInputAttachment,
                    .descriptorCount = 1,
                    .stageFlags = vk::ShaderStageFlagBits::eFragment,
            };

            vk::DescriptorSetLayoutBinding const depth_binding = {
                    .binding = 3,
                    .descriptorType = vk::DescriptorType::eInputAttachment,
                    .descriptorCount = 1,
                    .stageFlags = vk::ShaderStageFlagBits::eFragment,
            };

            vk::DescriptorSetLayoutBinding const lighting_uniform = {
                    .binding = 4,
                    .descriptorType = vk::DescriptorType::eUniformBuffer,
                    .descriptorCount = 1,
                    .stageFlags = vk::ShaderStageFlagBits::eFragment,
            };

            std::array<vk::DescriptorSetLayoutBinding, 5> lighting_bindings = {cam_buffer_binding, albedo_binding, normal_binding, depth_binding, lighting_uniform};
            vk::DescriptorSetLayoutCreateInfo const lighting_set_info = {
                    .bindingCount = lighting_bindings.size(),
                    .pBindings = lighting_bindings.data(),
            };
            result = m_device.createDescriptorSetLayout(&lighting_set_info, nullptr, &m_lighting_descriptor_set_layout);
            utils::vk_assert(result);


            for (auto &frame: m_frames) {
                int const MAX_OBJECTS = 10 * 1000;
                frame.object_buffer = create_buffer(m_allocator, sizeof(Transform) * MAX_OBJECTS,
                                                    vk::BufferUsageFlagBits::eStorageBuffer, VMA_MEMORY_USAGE_CPU_TO_GPU);

                frame.camera_buffer = create_buffer(m_allocator, sizeof(GPUCamera), vk::BufferUsageFlagBits::eUniformBuffer,
                                                    VMA_MEMORY_USAGE_CPU_TO_GPU);

                frame.scene_buffer = create_buffer(m_allocator, sizeof(SceneData), vk::BufferUsageFlagBits::eUniformBuffer,
                                                   VMA_MEMORY_USAGE_CPU_TO_GPU);

                frame.lighting_buffer = create_buffer(m_allocator, sizeof(LightingBuffer), vk::BufferUsageFlagBits::eUniformBuffer,
                                                      VMA_MEMORY_USAGE_CPU_TO_GPU);

                vmaMapMemory(m_allocator, frame.camera_buffer.allocation, &frame.mapped_camera_buffer);
                vmaMapMemory(m_allocator, frame.object_buffer.allocation, &frame.mapped_object_buffer);
                vmaMapMemory(m_allocator, frame.scene_buffer.allocation, &frame.mapped_scene_buffer);
                vmaMapMemory(m_allocator, frame.lighting_buffer.allocation, &frame.mapped_lighting_buffer);

                std::array<uint32_t, 1> variable_desc_count = {MAX_TEXTURES};
                vk::DescriptorSetVariableDescriptorCountAllocateInfoEXT variable_descriptor_count_allocate_info = {
                        .descriptorSetCount = variable_desc_count.size(),
                        .pDescriptorCounts = variable_desc_count.data(),
                };
                vk::DescriptorSetAllocateInfo const alloc_info = {
                        .pNext = &variable_descriptor_count_allocate_info,
                        .descriptorPool = m_descriptor_pool,
                        .descriptorSetCount = 1,
                        .pSetLayouts = &m_main_descriptor_set_layout,
                };
                result = m_device.allocateDescriptorSets(&alloc_info, &frame.main_descriptor);
                utils::vk_assert(result);

                vk::DescriptorSetAllocateInfo const lighting_alloc_info = {
                        .descriptorPool = m_descriptor_pool,
                        .descriptorSetCount = 1,
                        .pSetLayouts = &m_lighting_descriptor_set_layout,
                };
                result = m_device.allocateDescriptorSets(&lighting_alloc_info, &frame.lighting_descriptor);
                utils::vk_assert(result);

                vk::DescriptorBufferInfo const camera_info = {
                        .buffer = std::bit_cast<vk::Buffer>(frame.camera_buffer.buffer),
                        .offset = 0,
                        .range = sizeof(GPUCamera),
                };

                vk::DescriptorBufferInfo const scene_info = {
                        .buffer = std::bit_cast<vk::Buffer>(frame.scene_buffer.buffer),
                        .offset = 0,
                        .range = sizeof(SceneData),
                };

                vk::DescriptorBufferInfo const lighting_info = {
                        .buffer = std::bit_cast<vk::Buffer>(frame.lighting_buffer.buffer),
                        .offset = 0,
                        .range = sizeof(LightingBuffer),
                };

                vk::DescriptorBufferInfo const object_buffer_info = {
                        .buffer = std::bit_cast<vk::Buffer>(frame.object_buffer.buffer),
                        .offset = 0,
                        .range = sizeof(Transform) * MAX_OBJECTS,
                };

                vk::WriteDescriptorSet const camera_write = {
                        .dstSet = frame.main_descriptor,
                        .dstBinding = 0,
                        .descriptorCount = 1,
                        .descriptorType = vk::DescriptorType::eUniformBuffer,
                        .pBufferInfo = &camera_info,
                };

                // Todo merge all into one descriptor
                vk::WriteDescriptorSet const camera_write_lighting = {
                        .dstSet = frame.lighting_descriptor,
                        .dstBinding = 0,
                        .descriptorCount = 1,
                        .descriptorType = vk::DescriptorType::eUniformBuffer,
                        .pBufferInfo = &camera_info,
                };

                vk::WriteDescriptorSet const object_write = {
                        .dstSet = frame.main_descriptor,
                        .dstBinding = 1,
                        .descriptorCount = 1,
                        .descriptorType = vk::DescriptorType::eStorageBuffer,
                        .pBufferInfo = &object_buffer_info,
                };

                vk::WriteDescriptorSet const scene_write = {
                        .dstSet = frame.main_descriptor,
                        .dstBinding = 2,
                        .descriptorCount = 1,
                        .descriptorType = vk::DescriptorType::eUniformBuffer,
                        .pBufferInfo = &scene_info,
                };

                vk::WriteDescriptorSet const lighting_write = {
                        .dstSet = frame.lighting_descriptor,
                        .dstBinding = 4,
                        .descriptorCount = 1,
                        .descriptorType = vk::DescriptorType::eUniformBuffer,
                        .pBufferInfo = &lighting_info,
                };

                std::array<vk::WriteDescriptorSet, 5> set_writes = {camera_write, camera_write_lighting, object_write, scene_write, lighting_write};

                m_device.updateDescriptorSets(set_writes.size(), set_writes.data(), 0, nullptr);
            }
            write_lighting_image_view_descriptors();
        };

        void write_lighting_image_view_descriptors() const {
            for (auto const &frame: m_frames) {
                // Input Attachments
                vk::DescriptorImageInfo const color_image = {
                        .imageView = m_color_image_view,
                        .imageLayout = vk::ImageLayout::eShaderReadOnlyOptimal,
                };

                vk::DescriptorImageInfo const normal_image = {
                        .imageView = m_normals_image_view,
                        .imageLayout = vk::ImageLayout::eShaderReadOnlyOptimal,
                };

                vk::DescriptorImageInfo const depth_image = {
                        .imageView = m_depth_image_view,
                        .imageLayout = vk::ImageLayout::eDepthStencilReadOnlyOptimal,
                };


                vk::WriteDescriptorSet const color_image_write = {
                        .dstSet = frame.lighting_descriptor,
                        .dstBinding = 1,
                        .descriptorCount = 1,
                        .descriptorType = vk::DescriptorType::eInputAttachment,
                        .pImageInfo = &color_image,
                };

                vk::WriteDescriptorSet const normal_image_write = {
                        .dstSet = frame.lighting_descriptor,
                        .dstBinding = 2,
                        .descriptorCount = 1,
                        .descriptorType = vk::DescriptorType::eInputAttachment,
                        .pImageInfo = &normal_image,
                };

                vk::WriteDescriptorSet const depth_image_write = {
                        .dstSet = frame.lighting_descriptor,
                        .dstBinding = 3,
                        .descriptorCount = 1,
                        .descriptorType = vk::DescriptorType::eInputAttachment,
                        .pImageInfo = &depth_image,
                };

                std::array<vk::WriteDescriptorSet, 3> set_writes = {color_image_write, normal_image_write, depth_image_write};
                m_device.updateDescriptorSets(set_writes.size(), set_writes.data(), 0, nullptr);
            }
        };

        void init_texture_sampler() {
            vk::SamplerCreateInfo const sampler_info = {
                    .magFilter = vk::Filter::eLinear,
                    .minFilter = vk::Filter::eLinear,
                    .maxLod = VK_LOD_CLAMP_NONE,
            };

            vk::Sampler sampler;
            auto result = m_device.createSampler(&sampler_info, nullptr, &sampler);
            utils::vk_assert(result);
            m_sampler = sampler;
        };
    };
}// namespace lime
