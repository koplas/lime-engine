module;

#include <vk_mem_alloc.h>

#include <array>
#include <bit>


export module lime.vulkan_types;

import vulkan;
import glm;
import lime.utils;

export namespace lime {

    struct Transform {
        glm::vec3 position;
        glm::quat rotation;
        float scale = 1.0f;
    };

    struct AllocatedBuffer {
        VkBuffer buffer = VK_NULL_HANDLE;
        VmaAllocation allocation = nullptr;
    };

    struct AllocatedImage {
        vk::Image image = VK_NULL_HANDLE;
        VmaAllocation allocation = nullptr;
    };

    AllocatedBuffer create_buffer(VmaAllocator allocator, size_t alloc_size, vk::BufferUsageFlagBits usage, VmaMemoryUsage memory_usage) {
        vk::BufferCreateInfo const buffer_create_info{
                .size = alloc_size,
                .usage = usage,
        };

        VmaAllocationCreateInfo const vma_alloc_info{
                .usage = memory_usage,
        };

        AllocatedBuffer new_buffer{};

        auto result = vmaCreateBuffer(allocator,
                                      std::bit_cast<VkBufferCreateInfo const *>(&buffer_create_info), &vma_alloc_info,
                                      &new_buffer.buffer, &new_buffer.allocation,
                                      nullptr);
        lime::utils::vk_assert(std::bit_cast<vk::Result>(result));
        return new_buffer;
    }

    struct GPUMesh {
        uint32_t first_index = 0;
        uint32_t index_count = 0;
        int32_t vertex_offset = 0;
        AllocatedBuffer vertex_buffer;
        AllocatedBuffer index_buffer;
    };

    struct GPUTexture {
        AllocatedImage image;
        vk::ImageView image_view;
    };

    struct MeshPushConstants {
        uint32_t buffer_offset;
        uint32_t albedo_index;
        uint32_t normal_index;
        uint32_t specular_index;
    };

    struct Material {
        vk::Pipeline pipeline;
        vk::PipelineLayout *pipeline_layout = nullptr;
    };

    struct Camera {
        glm::mat4 view;
        glm::mat4 proj;
    };

    struct SceneData {
        glm::vec4 fog_color;
        glm::vec4 fog_distances;
        glm::vec4 ambient_color;
        glm::vec4 sunlight_direction;
        glm::vec4 sunlight_color;
    };

    struct Light {
        glm::vec4 position; // position.w represents type of light
        glm::vec4 color;    // color.w represents light intensity
        glm::vec4 direction;// direction.w represents range
        glm::vec4 info;     // (only used for spotlights) info.x represents light inner cone angle, info.y represents light outer cone angle
    };

    auto constexpr LIGHT_COUNT = 16;

    struct LightingBuffer {
        glm::mat4 inv_viewproj;
        std::array<Light, LIGHT_COUNT> point_lights;
    };

    struct GameState {
        Camera camera;
        SceneData scene_data;
        LightingBuffer lighting_buffer;
    };
}// namespace lime