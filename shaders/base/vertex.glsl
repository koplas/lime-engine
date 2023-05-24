layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_uv;

#ifdef SKINNING
layout(location = 3) in uvec4 v_boneindex;
layout(location = 4) in vec4 v_weight;
#endif

layout(location = 0) out vec3 o_normal;
layout(location = 1) out vec2 o_uv;

layout(set = 0, binding = 0) uniform CameraBuffer {
    mat4 view;
    mat4 proj;
}
Camera;

layout(std140, set = 0, binding = 1) readonly buffer ObjectBuffer {
    mat4 objects[];
}
object_buffer;

layout(push_constant) uniform constants {
    uint buffer_offset;
    uint albedo_index;
    uint normal_index;
    uint specular_index;
}
PushConstants;

out gl_PerVertex {
    vec4 gl_Position;
};

void main() {
#ifdef SKINNING
    uint offset = PushConstants.buffer_offset + gl_BaseInstance;
    mat4 skin_matrix =
            v_weight.x * object_buffer.objects[offset + v_boneindex.x + 1] +
            v_weight.y * object_buffer.objects[offset + v_boneindex.y + 1] +
            v_weight.z * object_buffer.objects[offset + v_boneindex.z + 1] +
            v_weight.w * object_buffer.objects[offset + v_boneindex.w + 1];

    mat4 model_matrix = object_buffer.objects[offset];
    mat4 transform_matrix = (Camera.proj * Camera.view * model_matrix);
    gl_Position = transform_matrix * skin_matrix * vec4(v_position, 1.0f);
#else
    mat4 model_matrix = object_buffer.objects[PushConstants.buffer_offset + gl_BaseInstance];
    mat4 transform_matrix = (Camera.proj * Camera.view * model_matrix);
    gl_Position = transform_matrix * vec4(v_position, 1.0f);
#endif

    o_normal = mat3(model_matrix) * v_normal;
    o_uv = v_uv;
}
