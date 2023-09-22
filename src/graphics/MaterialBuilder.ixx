module;

#include <array>
#include <bit>
#include <cstdint>
#include <fstream>
#include <list>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>


export module lime.MaterialBuilder;

import lime.PipelineBuilder;
import lime.mesh;
import lime.utils;
import vulkan;
import lime.vulkan_types;

void add_material(vk::Pipeline pipeline, vk::PipelineLayout layout, std::string const &name, std::unordered_map<std::string, lime::Material> &materials, std::list<vk::PipelineLayout> &pipeline_layouts) {
    auto it = std::ranges::find(pipeline_layouts, layout);
    if (it == pipeline_layouts.end()) {
        pipeline_layouts.push_back(layout);
        it = pipeline_layouts.end();
        it--;
    }
    lime::Material const mat{
            .pipeline = pipeline,
            .pipeline_layout = std::to_address(it),
    };
    materials[name] = mat;
}

export namespace lime {
    class MaterialBuilder {
    public:
        static void
        build_materials(vk::Device device, vk::RenderPass renderpass, vk::DescriptorSetLayout descriptor_set_layout, vk::DescriptorSetLayout lighting_descriptor_set_layout,
                        vk::SampleCountFlagBits msaa_samples, std::unordered_map<std::string, Material> &materials, std::list<vk::PipelineLayout> &pipeline_layouts) {

            vk::ShaderModule default_frag_shader;
            auto base_shader_dir = std::string{utils::get_asset_dir()} + "/shaders/";
            auto result = load_shader_module(base_shader_dir + "default.frag.spv", device, &default_frag_shader);
            utils::vk_assert(result);

            vk::ShaderModule default_vertex_shader;
            result = load_shader_module(base_shader_dir + "default.vert.spv", device, &default_vertex_shader);
            utils::vk_assert(result);

            vk::ShaderModule skinning_vertex_shader;
            result = load_shader_module(base_shader_dir + "skinning.vert.spv", device, &skinning_vertex_shader);
            utils::vk_assert(result);

            vk::PushConstantRange const push_constant = {
                    .stageFlags = vk::ShaderStageFlagBits::eVertex | vk::ShaderStageFlagBits::eFragment,
                    .offset = 0,
                    .size = sizeof(MeshPushConstants),
            };
            std::array<vk::DescriptorSetLayout, 1> set_layouts = {descriptor_set_layout};
            vk::PipelineLayoutCreateInfo const pipeline_layout_info = {
                    .setLayoutCount = set_layouts.size(),
                    .pSetLayouts = set_layouts.data(),
                    .pushConstantRangeCount = 1,
                    .pPushConstantRanges = &push_constant,
            };

            vk::PipelineLayout pipeline_layout{};
            result = device.createPipelineLayout(&pipeline_layout_info, nullptr, &pipeline_layout);
            utils::vk_assert(result);

            PipelineBuilder pipeline_builder;
            pipeline_builder.add_shader(vk::ShaderStageFlagBits::eVertex, default_vertex_shader)
                    .add_shader(vk::ShaderStageFlagBits::eFragment, default_frag_shader);

            mesh::VertexInputDescription vertex_description = mesh::Vertex::get_vertex_description();
            pipeline_builder.vertex_input(vertex_description)
                    .input_info(vk::PrimitiveTopology::eTriangleList)
                    .depth_stencil(true, true, vk::CompareOp::eLessOrEqual);

            pipeline_builder.rasterization_mode(vk::PolygonMode::eFill, vk::CullModeFlagBits::eBack)
                    .multisampling_mode(msaa_samples)
                    .color_blend_attachment_state()
                    .pipeline_layout(pipeline_layout)
                    .color_attachment_count(2);


            vk::Pipeline const pipeline = pipeline_builder.build_pipeline(device, renderpass);

            add_material(pipeline, pipeline_layout, "default_material", materials, pipeline_layouts);

            // Built skinning shader
            mesh::VertexInputDescription vertex_input_description_skinning = mesh::VertexBone::get_vertex_description();
            pipeline_builder.clear_shaders();

            pipeline_builder.add_shader(vk::ShaderStageFlagBits::eVertex, skinning_vertex_shader)
                    .add_shader(vk::ShaderStageFlagBits::eFragment, default_frag_shader)
                    .vertex_input(vertex_input_description_skinning);

            vk::Pipeline const skinning_pipeline = pipeline_builder.build_pipeline(device, renderpass);

            add_material(skinning_pipeline, pipeline_layout, "skinning", materials, pipeline_layouts);

            device.destroy(default_frag_shader, nullptr);
            device.destroy(default_vertex_shader, nullptr);
            device.destroy(skinning_vertex_shader, nullptr);

            // Build lighting pipeline
            vk::ShaderModule lighting_frag_shader;
            result = load_shader_module(base_shader_dir + "lighting.frag.spv", device, &lighting_frag_shader);
            utils::vk_assert(result);

            vk::ShaderModule lighting_vertex_shader;
            result = load_shader_module(base_shader_dir + "lighting.vert.spv", device, &lighting_vertex_shader);
            utils::vk_assert(result);

            pipeline_builder.clear_shaders();

            // Pass sample count constant to lighting shader
            vk::SpecializationMapEntry const msaa_samples_specialization = {0, 0, sizeof(uint32_t)};
            vk::SpecializationInfo const lighting_specialization_info = {
                    .mapEntryCount = 1,
                    .pMapEntries = &msaa_samples_specialization,
                    .dataSize = sizeof(uint32_t),
                    .pData = &msaa_samples,
            };

            pipeline_builder.add_shader(vk::ShaderStageFlagBits::eVertex, lighting_vertex_shader)
                    .add_shader(vk::ShaderStageFlagBits::eFragment, lighting_frag_shader, &lighting_specialization_info)
                    .depth_stencil(false, false, vk::CompareOp::eLessOrEqual)
                    .multisampling_mode(vk::SampleCountFlagBits::e1)
                    .rasterization_mode(vk::PolygonMode::eFill, vk::CullModeFlagBits::eNone)
                    .subpass_index(1)
                    .color_attachment_count(1);

            mesh::VertexInputDescription empty_vertex_input{};
            pipeline_builder.vertex_input(empty_vertex_input);

            std::array<vk::DescriptorSetLayout, 1> lighting_set_layouts = {lighting_descriptor_set_layout};
            vk::PipelineLayoutCreateInfo const lightning_layout_info = {
                    .setLayoutCount = lighting_set_layouts.size(),
                    .pSetLayouts = lighting_set_layouts.data(),
            };

            vk::PipelineLayout lightning_layout{};
            result = device.createPipelineLayout(&lightning_layout_info, nullptr, &lightning_layout);
            utils::vk_assert(result);
            pipeline_builder.pipeline_layout(lightning_layout);

            vk::Pipeline const lightning_pipeline = pipeline_builder.build_pipeline(device, renderpass);

            add_material(lightning_pipeline, lightning_layout, "lighting", materials, pipeline_layouts);

            device.destroy(lighting_frag_shader, nullptr);
            device.destroy(lighting_vertex_shader, nullptr);
        };

    private:
        static vk::Result load_shader_module(std::string &&file_path, vk::Device device, vk::ShaderModule *out_shader_module) {
            std::ifstream file(file_path, std::ios::ate | std::ios::binary);

            if (!file.is_open()) {
                // Todo better error handling
                return vk::Result::eErrorUnknown;
            }

            auto file_size = static_cast<size_t>(file.tellg());

            std::vector<uint32_t> buffer(file_size / sizeof(uint32_t));

            file.seekg(0);
            file.read(std::bit_cast<char *>(buffer.data()), static_cast<int64_t>(file_size));

            file.close();

            vk::ShaderModuleCreateInfo const create_info = {
                    .codeSize = buffer.size() * sizeof(uint32_t),
                    .pCode = buffer.data(),
            };

            vk::ShaderModule shader_module;
            auto result = device.createShaderModule(&create_info, nullptr, &shader_module);
            *out_shader_module = shader_module;
            return result;
        };
    };
}// namespace lime