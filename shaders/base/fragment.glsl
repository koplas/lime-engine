#extension GL_EXT_nonuniform_qualifier : require

layout(location = 0) in vec3 in_normal;
layout(location = 1) in vec2 in_uv;

layout(location = 0) out vec4 o_albedo;
layout(location = 1) out vec4 o_normal;

//layout(set = 0, binding = 0) uniform CameraBuffer {
//    mat4 view;
//    mat4 proj;
//} Camera;

layout(set = 0, binding = 2) uniform SceneData {
    vec4 fog_color;
    vec4 fog_distances;
    vec4 ambient_color;
    vec4 sunlight_direction;
    vec4 sunlight_color;
}
scene_data;

layout(set = 0, binding = 3) uniform sampler2D tex1[];

layout(push_constant) uniform constants {
    uint buffer_offset;
    uint albedo_index;
    uint normal_index;
    float data2;
}
PushConstants;

void main() {
    vec3 normal = normalize(in_normal);
    // Transform from [-1, 1] to [0, 1]
    o_normal = vec4(0.5 * normal + 0.5, 1.0);

    vec4 color = vec4(texture(tex1[nonuniformEXT(PushConstants.albedo_index)], in_uv).xyz + scene_data.ambient_color.xyz, 1.0f);
    float fog_amount = smoothstep(scene_data.fog_distances.x, scene_data.fog_distances.y, gl_FragCoord.z);
    o_albedo = mix(color, scene_data.fog_color, fog_amount);
}
