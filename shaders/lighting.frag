#version 450

layout(input_attachment_index = 0, binding = 0) uniform subpassInputMS i_albedo;
layout(input_attachment_index = 1, binding = 1) uniform subpassInputMS i_normal;
layout(input_attachment_index = 2, binding = 2) uniform subpassInputMS i_depth;

layout(constant_id = 0) const uint MSAA_SAMPLE_COUNT = 1;

layout(location = 0) in vec2 in_uv;
layout(location = 0) out vec4 o_color;

#include "lighting.h"

#define MAX_LIGHT_COUNT 16

#define POINT_LIGHT_COUNT 16


layout(set = 0, binding = 3) uniform GlobalUniform {
    mat4 inv_view_proj;
    Light point_lights[POINT_LIGHT_COUNT];
}
global_uniform;

vec3 calculate_fragment_light(vec4 albedo, vec3 normal, float depth) {
        // Retrieve position from depth
        vec4 clip = vec4(in_uv * 2.0 - 1.0, depth, 1.0);
        vec4 world_w = global_uniform.inv_view_proj * clip;
        vec3 pos = world_w.xyz / world_w.w;
        // Transform from [0,1] to [-1,1]
        normal = normalize(2.0 * normal - 1.0);
        
        vec3 fragment_light = vec3(0.0, 0.0, 0.0);

        // Calculate lighting
        for (uint i = 0U; i < POINT_LIGHT_COUNT && global_uniform.point_lights[i].color.w != 0.0; ++i) {
            fragment_light += apply_point_light(global_uniform.point_lights[i], pos, normal);
        }

        vec3 ambient_color = vec3(0.2) * albedo.xyz;
        return min(fragment_light, vec3(1.0, 1.0, 1.0)) * albedo.xyz + ambient_color;
}


void main() {
    // detect complex pixels
    // https://github.com/hghdev/NVIDIAGameWorks-GraphicsSamples/blob/master/samples/gl4-kepler/DeferredShadingMSAA/assets/shaders/Lighting_FS.glsl
    bool complex_pixel = false;

    vec4 albedo = subpassLoad(i_albedo, 0);
    vec3 normal = subpassLoad(i_normal, 0).xyz;
    float depth = subpassLoad(i_depth, 0).x;

    for (int i = 1; i < MSAA_SAMPLE_COUNT; i++) {
        vec4 next_albedo = subpassLoad(i_albedo, i);
        vec3 next_normal = subpassLoad(i_normal, i).xyz;
        float next_depth = subpassLoad(i_depth, i).x;

        if (abs(depth - next_depth) > 0.1f ||
            abs(dot(abs(normal - next_normal), vec3(1, 1, 1))) > 0.1 ||
            abs(dot(albedo - next_albedo, vec4(1, 1, 1, 1))) > 0.1) {
            complex_pixel = true;
            break;
        }
    }

    uint fragment_count = 1;
    if (complex_pixel) {
        fragment_count = MSAA_SAMPLE_COUNT;
    }

    vec3 diffuse = calculate_fragment_light(albedo, normal, depth);

    for (int i = 1; i < fragment_count; i++) {
        diffuse += calculate_fragment_light(subpassLoad(i_albedo, i), subpassLoad(i_normal, i).xyz, subpassLoad(i_depth, i).x);
    }

    o_color = vec4(diffuse / fragment_count, 1.0);
}
