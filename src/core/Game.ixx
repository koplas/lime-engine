module;


#include <GLFW/glfw3.h>
#include <chrono>
#include <math.h>

#include <optional>

export module lime.Game;

import lime.Render;
import lime.Window;
import lime.utils;
import glm;
import vulkan;
import entt;
import lime.vulkan_types;

export namespace lime {
    class Game {
    public:
        Game() {
            m_window_extent = m_window.get_framebuffer_size();
            m_engine.emplace(m_window.get_window(), m_window_extent);

            m_game_state.scene_data = {
                    .fog_color = {0.67F, 0.84F, 0.90F, 0.0F},
                    .fog_distances = {0.99F, 1.0F, 0.0F, 0.0F},
                    .ambient_color = {0.0F, 0.0F, 0.0F, 0.0F},
            };

            m_game_state.camera = {
                    .position = {0.0F, 0.0F, -12.0F},
                    .rotation = glm::vec3{0.0F},
                    .fov = 70.0F,
            };

            init_scene();
        };

        void run() {
            Input input = {};
            auto last_frame = std::chrono::high_resolution_clock::now();
            do {
                auto now = std::chrono::high_resolution_clock::now();
                m_step = (float) std::chrono::duration_cast<std::chrono::nanoseconds>(now - last_frame).count() / (1000.0F * 1000.0F * 1000.0F);
                last_frame = now;

                input = m_window.poll_input();

                if (glfwGetKey(m_window.get_window(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                    m_window.enable_cursor();
                }

                while (input.window_resized) {
                    m_engine->set_extent(m_window_extent);
                    m_engine->recreate_swapchain();
                    input = m_window.poll_input();
                }

                update_camera(input);
                m_engine->draw(m_registry, m_game_state);
            } while (!input.should_window_close);
        };

    private:
        Window m_window;
        std::optional<Render> m_engine;
        vk::Extent2D m_window_extent;

        GameState m_game_state = {};
        entt::registry m_registry;

        float m_step = 0.2F;

        void init_scene() {
            m_engine->load_texture("monkey");
            m_engine->load_texture("monkey_black");

            m_engine->load_mesh("monkey");

            auto const monkey_1 = m_registry.create();
            m_registry.emplace<Model>(monkey_1, Model{.mesh = "monkey", .albedo_texture = "monkey"});
            Transform transform = {.position = {0, 0, 0}, .rotation = {glm::vec3{0, 0, 0}}, .scale = 1};
            m_registry.emplace<Transform>(monkey_1, transform);

            auto const monkey_2 = m_registry.create();
            m_registry.emplace<Model>(monkey_2, Model{.mesh = "monkey", .albedo_texture = "monkey_black"});
            Transform transform2 = {.position = {2, 0, 2}, .rotation = {glm::vec3{60, 0, 0}}, .scale = 2};
            m_registry.emplace<Transform>(monkey_2, transform2);

            for (auto &light: m_game_state.lighting_buffer.point_lights) {
                light.position = {1.0f, 1.0f, 1.0f, 1.0f};
                light.color = {0.0f, 0.0f, 0.0f, 0.0f};
            }
            m_game_state.lighting_buffer.point_lights[0] = {.position = {5.0f, 5.0f, 4.0f, 1.0f}, .color = {0.5f, 0.0f, 0.5f, 0.1f}};
            m_game_state.lighting_buffer.point_lights[1] = {.position = {-5.0f, 5.0f, 1.0f, 1.0f}, .color = {0.0f, 0.5f, 0.0f, 0.1f}};
        };

        void update_camera(Input input) {
            auto *window = m_window.get_window();

            float const camera_speed = 5.00F * m_step;
            auto &camera = m_game_state.camera;
            const glm::vec3 cam_left = glm::vec3{1.F, 0.F, 0.F} * camera.rotation;
            const glm::vec3 cam_forward = glm::vec3{0.F, 0.F, 1.F} * camera.rotation;
            if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
                camera.position += camera_speed * cam_forward;
            }
            if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
                camera.position -= camera_speed * cam_forward;
            }
            if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
                camera.position += camera_speed * cam_left;
            }
            if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
                camera.position -= camera_speed * cam_left;
            }

            static float last_x = 0.F;
            static float last_y = 0.F;

            if (static auto first_mouse = true; first_mouse) {
                last_x = input.cursor_x;
                last_y = input.cursor_y;
                first_mouse = false;
            }

            float x_offset = input.cursor_x - last_x;
            float y_offset = last_y - input.cursor_y;
            last_x = input.cursor_x;
            last_y = input.cursor_y;

            float const sensitivity = 1.00F * m_step;
            x_offset *= sensitivity;
            y_offset *= sensitivity;

            glm::quat q_pitch = glm::angleAxis(y_offset, glm::vec3(-1, 0, 0));
            glm::quat q_yaw = glm::angleAxis(x_offset, glm::vec3(0, 1, 0));
            // glm::quat q_roll = glm::angleAxis(0.0F ,glm::vec3(0,0,1));

            glm::quat orientation = glm::normalize(q_pitch * q_yaw);
            camera.rotation = orientation * camera.rotation;

            m_game_state.camera.fov = 70.0F;
        };
    };
}// namespace lime
