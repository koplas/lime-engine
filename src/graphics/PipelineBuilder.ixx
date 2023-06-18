module;

#include <array>
#include <vector>
#include <vulkan/vulkan.h>

export module lime.PipelineBuilder;

import lime.mesh;
import vulkan;
import lime.vulkan_types;

export namespace lime {
    class PipelineBuilder {
    public:
        vk::Pipeline build_pipeline(vk::Device device, vk::RenderPass pass) {
            vk::PipelineViewportStateCreateInfo const viewport_state = {
                    .viewportCount = 1,
                    .scissorCount = 1,
            };

            std::array<vk::PipelineColorBlendAttachmentState, 2> color_blend_attachments = {m_color_blend_attachment, m_color_blend_attachment};

            vk::PipelineColorBlendStateCreateInfo const color_blending = {
                    .logicOpEnable = false,
                    .logicOp = vk::LogicOp::eCopy,
                    .attachmentCount = m_color_attachment_count,
                    .pAttachments = color_blend_attachments.data(),
            };

            std::array<vk::DynamicState, 2> dynamic_states = {vk::DynamicState::eViewport, vk::DynamicState::eScissor};
            vk::PipelineDynamicStateCreateInfo const dynamic_state = {
                    .dynamicStateCount = dynamic_states.size(),
                    .pDynamicStates = dynamic_states.data(),
            };

            vk::GraphicsPipelineCreateInfo const pipeline_info = {
                    .stageCount = static_cast<uint32_t>(m_shader_stages.size()),
                    .pStages = m_shader_stages.data(),
                    .pVertexInputState = &m_vertex_input_info,
                    .pInputAssemblyState = &m_input_assembly,
                    .pViewportState = &viewport_state,
                    .pRasterizationState = &m_rasterizer,
                    .pMultisampleState = &m_multisampling,
                    .pDepthStencilState = &m_depth_stencil_info,
                    .pColorBlendState = &color_blending,
                    .pDynamicState = &dynamic_state,
                    .layout = m_pipeline_layout,
                    .renderPass = pass,
                    .subpass = m_subpass_index,
                    .basePipelineHandle = VK_NULL_HANDLE,
            };

            return device.createGraphicsPipeline(nullptr, pipeline_info, nullptr).value;
        };

        PipelineBuilder &add_shader(vk::ShaderStageFlagBits stage, vk::ShaderModule shader_module, vk::SpecializationInfo const *specialization_info = nullptr) {
            vk::PipelineShaderStageCreateInfo const info = {
                    .stage = stage,
                    .module = shader_module,
                    .pName = "main",
                    .pSpecializationInfo = specialization_info,
            };
            m_shader_stages.push_back(info);
            return *this;
        };
        PipelineBuilder &clear_shaders() {
            m_shader_stages.clear();
            return *this;
        };

        PipelineBuilder &vertex_input(mesh::VertexInputDescription &vertex_input) {
            vk::PipelineVertexInputStateCreateInfo const info = {
                    .vertexBindingDescriptionCount = static_cast<uint32_t>(vertex_input.bindings.size()),
                    .pVertexBindingDescriptions = vertex_input.bindings.data(),
                    .vertexAttributeDescriptionCount = static_cast<uint32_t>(vertex_input.attributes.size()),
                    .pVertexAttributeDescriptions = vertex_input.attributes.data(),
            };
            m_vertex_input_info = info;
            return *this;
        };

        PipelineBuilder &input_info(vk::PrimitiveTopology topology) {
            vk::PipelineInputAssemblyStateCreateInfo const info = {
                    .topology = topology,
                    .primitiveRestartEnable = false,
            };
            m_input_assembly = info;
            return *this;
        };

        PipelineBuilder &depth_stencil(bool depth_test, bool depth_write, vk::CompareOp compare_op) {
            vk::PipelineDepthStencilStateCreateInfo const info{
                    .depthTestEnable = depth_test,
                    .depthWriteEnable = depth_write,
                    .depthCompareOp = depth_test ? compare_op : vk::CompareOp::eAlways,
                    .depthBoundsTestEnable = false,
                    .stencilTestEnable = false,
            };
            m_depth_stencil_info = info;
            return *this;
        };


        PipelineBuilder &rasterization_mode(vk::PolygonMode polygon_mode, vk::CullModeFlagBits cull_mode) {
            vk::PipelineRasterizationStateCreateInfo const info = {
                    .depthClampEnable = false,
                    .rasterizerDiscardEnable = false,
                    .polygonMode = polygon_mode,
                    .cullMode = cull_mode,
                    .frontFace = vk::FrontFace::eCounterClockwise,
                    .depthBiasEnable = false,
                    .lineWidth = 1.0f,
            };
            m_rasterizer = info;
            return *this;
        };

        PipelineBuilder &multisampling_mode(vk::SampleCountFlagBits samples) {
            vk::PipelineMultisampleStateCreateInfo const info = {
                    .rasterizationSamples = samples,
                    .sampleShadingEnable = false,
                    .minSampleShading = 1.0f,
                    .pSampleMask = nullptr,
                    .alphaToOneEnable = false,
            };
            m_multisampling = info;
            return *this;
        };

        PipelineBuilder &color_blend_attachment_state() {
            using enum vk::ColorComponentFlagBits;
            vk::PipelineColorBlendAttachmentState const info = {
                    .blendEnable = false,
                    .colorWriteMask = eR | eG | eB | eA,
            };
            m_color_blend_attachment = info;
            return *this;
        };

        PipelineBuilder &color_attachment_count(uint32_t color_attachment_count) {
            m_color_attachment_count = color_attachment_count;
            return *this;
        };

        PipelineBuilder &subpass_index(uint32_t subpass_index) {
            m_subpass_index = subpass_index;
            return *this;
        };

        PipelineBuilder &pipeline_layout(vk::PipelineLayout pipeline_layout) {
            m_pipeline_layout = pipeline_layout;
            return *this;
        };

    private:
        vk::PipelineVertexInputStateCreateInfo m_vertex_input_info;
        vk::PipelineInputAssemblyStateCreateInfo m_input_assembly;
        vk::PipelineRasterizationStateCreateInfo m_rasterizer;
        vk::PipelineColorBlendAttachmentState m_color_blend_attachment;
        vk::PipelineMultisampleStateCreateInfo m_multisampling;
        vk::PipelineDepthStencilStateCreateInfo m_depth_stencil_info;

        std::vector<vk::PipelineShaderStageCreateInfo> m_shader_stages;
        vk::PipelineLayout m_pipeline_layout;
        uint32_t m_subpass_index = 0;
        uint32_t m_color_attachment_count = 1;
    };
}// namespace lime
