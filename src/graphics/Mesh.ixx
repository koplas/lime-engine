module;

#include <iostream>
#include <variant>
#include <bit>
#include <vector>

#define TINYGLTF_NO_STB_IMAGE_WRITE
#include <tiny_gltf.h>


export module Mesh;
import vulkan;
import glm;
import utils;
import vulkan_types;

export struct VertexInputDescription {
    std::vector<vk::VertexInputBindingDescription> bindings;
    std::vector<vk::VertexInputAttributeDescription> attributes;
};

export struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;

    static VertexInputDescription get_vertex_description() {
        VertexInputDescription description;

        vk::VertexInputBindingDescription const binding = {
                .binding = 0,
                .stride = sizeof(Vertex),
                .inputRate = vk::VertexInputRate::eVertex,
        };

        description.bindings.push_back(binding);

        vk::VertexInputAttributeDescription const position_attribute = {
                .location = 0,
                .binding = 0,
                .format = vk::Format::eR32G32B32Sfloat,
                .offset = offsetof(Vertex, position),
        };

        vk::VertexInputAttributeDescription const normal_attribute = {
                .location = 1,
                .binding = 0,
                .format = vk::Format::eR32G32B32Sfloat,
                .offset = offsetof(Vertex, normal),
        };

        vk::VertexInputAttributeDescription const uv_attribute = {
                .location = 2,
                .binding = 0,
                .format = vk::Format::eR32G32Sfloat,
                .offset = offsetof(Vertex, uv),
        };

        description.attributes.push_back(position_attribute);
        description.attributes.push_back(normal_attribute);
        description.attributes.push_back(uv_attribute);

        return description;
    };
};

export struct VertexBone {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;
    std::array<uint32_t, 4> bone_index;
    glm::vec4 weight;

    static VertexInputDescription get_vertex_description() {
        VertexInputDescription description;

        vk::VertexInputBindingDescription const binding = {
                .binding = 0,
                .stride = sizeof(VertexBone),
                .inputRate = vk::VertexInputRate::eVertex,
        };

        description.bindings.push_back(binding);

        vk::VertexInputAttributeDescription const position_attribute = {
                .location = 0,
                .binding = 0,
                .format = vk::Format::eR32G32B32Sfloat,
                .offset = offsetof(VertexBone, position),
        };

        vk::VertexInputAttributeDescription const normal_attribute = {
                .location = 1,
                .binding = 0,
                .format = vk::Format::eR32G32B32Sfloat,
                .offset = offsetof(VertexBone, normal),
        };

        vk::VertexInputAttributeDescription const uv_attribute = {
                .location = 2,
                .binding = 0,
                .format = vk::Format::eR32G32Sfloat,
                .offset = offsetof(VertexBone, uv),
        };

        vk::VertexInputAttributeDescription const bone_index_attribute = {
                .location = 3,
                .binding = 0,
                .format = vk::Format::eR32G32B32A32Uint,
                .offset = offsetof(VertexBone, bone_index),
        };

        vk::VertexInputAttributeDescription const weight_attribute = {
                .location = 4,
                .binding = 0,
                .format = vk::Format::eR32G32B32A32Sfloat,
                .offset = offsetof(VertexBone, weight),
        };

        description.attributes.push_back(position_attribute);
        description.attributes.push_back(normal_attribute);
        description.attributes.push_back(uv_attribute);
        description.attributes.push_back(bone_index_attribute);
        description.attributes.push_back(weight_attribute);

        return description;
    };
};

export struct Mesh {
    std::vector<Vertex> vertices;
    std::vector<uint32_t> index_buffer;
};

export struct MeshBone {
    std::vector<VertexBone> vertices;
    std::vector<uint32_t> index_buffer;
};

export std::variant<Mesh, MeshBone> load_from_gltf(std::string_view path, bool load_skinning) {
    std::string file = std::string{get_asset_dir()};
    file += path;
    file += ".glb";

    tinygltf::Model model;
    tinygltf::TinyGLTF loader;
    std::string err;
    std::string warn;

    bool const ret = loader.LoadBinaryFromFile(&model, &err, &warn, file);

    if (!warn.empty()) {
        std::cerr << warn << std::endl;
    }

    if (!err.empty()) {
        std::cerr << err << std::endl;
    }

    if (!ret) {
        abort();
    }

    // load_images
    // load_material
    // load_textures

    std::variant<Mesh, MeshBone> out;

    if (load_skinning) {
        out = MeshBone{};
    } else {
        out = Mesh{};
    }

    for (auto const mesh = model.meshes[0]; auto const &primitive: mesh.primitives) {
        // uint32_t first_index = 0;
        uint32_t const vertex_start = 0;
        // uint32_t index_count = 0;

        // Vertices
        float const *position_buffer = nullptr;
        float const *normal_buffer = nullptr;
        float const *texcoord_buffer = nullptr;
        uint16_t const *jointindices_buffer = nullptr;
        float const *joint_weights_buffer = nullptr;
        size_t vertex_count = 0;

        if (primitive.attributes.contains("POSITION")) {
            tinygltf::Accessor const &accessor = model.accessors[primitive.attributes.find("POSITION")->second];
            tinygltf::BufferView const &view = model.bufferViews[accessor.bufferView];
            position_buffer = std::bit_cast<float const *>(&model.buffers[view.buffer].data[accessor.byteOffset +
                                                                                            view.byteOffset]);
            vertex_count = accessor.count;
        }

        if (primitive.attributes.contains("NORMAL")) {
            tinygltf::Accessor const &accessor = model.accessors[primitive.attributes.find("NORMAL")->second];
            tinygltf::BufferView const &view = model.bufferViews[accessor.bufferView];
            normal_buffer = std::bit_cast<float const *>(&model.buffers[view.buffer].data[accessor.byteOffset +
                                                                                          view.byteOffset]);
        }

        if (primitive.attributes.contains("TEXCOORD_0")) {
            tinygltf::Accessor const &accessor = model.accessors[primitive.attributes.find("TEXCOORD_0")->second];
            tinygltf::BufferView const &view = model.bufferViews[accessor.bufferView];
            texcoord_buffer = std::bit_cast<float const *>(&model.buffers[view.buffer].data[accessor.byteOffset +
                                                                                            view.byteOffset]);
        }

        if (primitive.attributes.contains("JOINTS_0")) {
            tinygltf::Accessor const &accessor = model.accessors[primitive.attributes.find("JOINTS_0")->second];
            tinygltf::BufferView const &view = model.bufferViews[accessor.bufferView];
            jointindices_buffer = std::bit_cast<uint16_t const *>(&(model.buffers[view.buffer].data[accessor.byteOffset + view.byteOffset]));
        }

        if (primitive.attributes.contains("WEIGHTS_0")) {
            tinygltf::Accessor const &accessor = model.accessors[primitive.attributes.find("WEIGHTS_0")->second];
            tinygltf::BufferView const &view = model.bufferViews[accessor.bufferView];
            joint_weights_buffer = std::bit_cast<float const *>(&(model.buffers[view.buffer].data[accessor.byteOffset +
                                                                                                  view.byteOffset]));
        }

        if (bool const has_bones = jointindices_buffer && joint_weights_buffer; !has_bones && load_skinning)
            abort();

        for (size_t v = 0; v < vertex_count; v++) {
            if (load_skinning) {
                VertexBone vertex = {
                        .position = glm::make_vec3(&position_buffer[v * 3]),
                        .normal = glm::normalize(
                                glm::vec3(normal_buffer ? glm::make_vec3(&normal_buffer[v * 3]) : glm::vec3(0.0f))),
                        .uv = texcoord_buffer ? glm::make_vec2(&texcoord_buffer[v * 2]) : glm::vec3(0.0f),
                        .weight = glm::make_vec4(&joint_weights_buffer[v * 4]),
                };
                memcpy(vertex.bone_index.data(), std::addressof(jointindices_buffer[v * 4]), sizeof(uint32_t) * 4);
                std::get<MeshBone>(out).vertices.push_back(vertex);
            } else {
                Vertex const vertex = {
                        .position = glm::make_vec3(&position_buffer[v * 3]),
                        .normal = glm::normalize(
                                glm::vec3(normal_buffer ? glm::make_vec3(&normal_buffer[v * 3]) : glm::vec3(0.0f))),
                        .uv = texcoord_buffer ? glm::make_vec2(&texcoord_buffer[v * 2]) : glm::vec3(0.0f),
                };
                std::get<Mesh>(out).vertices.push_back(vertex);
            }
        }

        // Indices
        tinygltf::Accessor const &accessor = model.accessors[primitive.indices];
        tinygltf::BufferView const &buffer_view = model.bufferViews[accessor.bufferView];
        tinygltf::Buffer const &buffer = model.buffers[buffer_view.buffer];

        // index_count += static_cast<uint32_t>(accessor.count);
        std::vector<uint32_t> *index_buffer = nullptr;
        if (load_skinning) {
            index_buffer = &std::get<MeshBone>(out).index_buffer;
        } else {
            index_buffer = &std::get<Mesh>(out).index_buffer;
        }

        switch (accessor.componentType) {
            case TINYGLTF_PARAMETER_TYPE_UNSIGNED_INT: {
                auto const *buf = std::bit_cast<uint32_t const *>(&buffer.data[accessor.byteOffset +
                                                                               buffer_view.byteOffset]);
                for (size_t index = 0; index < accessor.count; index++) {
                    index_buffer->push_back(buf[index] + vertex_start);
                }
                break;
            }
            case TINYGLTF_PARAMETER_TYPE_UNSIGNED_SHORT: {
                auto const *buf = std::bit_cast<uint16_t const *>(&buffer.data[accessor.byteOffset +
                                                                               buffer_view.byteOffset]);
                for (size_t index = 0; index < accessor.count; index++) {
                    index_buffer->push_back(buf[index] + vertex_start);
                }
                break;
            }
            case TINYGLTF_PARAMETER_TYPE_UNSIGNED_BYTE: {
                auto const *buf = &buffer.data[accessor.byteOffset +
                                               buffer_view.byteOffset];
                for (size_t index = 0; index < accessor.count; index++) {
                    index_buffer->push_back(buf[index] + vertex_start);
                }
                break;
            }
            default:
                std::cerr << "Index component type " << accessor.componentType << " not supported!" << std::endl;
                abort();
        }
    }
    return out;
};

