module;


#include <GLFW/glfw3.h>
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

            init_scene();
        };

        void run() {
            Input input = {};
            bool out_of_date_swapchain = false;
            do {
                input = m_window.poll_input();

                if (glfwGetKey(m_window.get_window(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                    m_window.enable_cursor();
                }

                while (out_of_date_swapchain || input.window_resized) {
                    // Todo maybe move this into Render module
                    m_window_extent = m_window.get_framebuffer_size();
                    m_engine->set_extent(m_window_extent);
                    m_engine->recreate_swapchain();
                    out_of_date_swapchain = false;
                    input = m_window.poll_input();
                }

                update_camera(input);
                if (!m_engine->draw(m_registry, m_game_state)) {
                    out_of_date_swapchain = true;
                    utils::log_info("Out of date swapchain");
                }
            } while (!input.should_window_close);
        };

    private:
        Window m_window;
        std::optional<Render> m_engine;
        vk::Extent2D m_window_extent;

        GameState m_game_state = {};
        entt::registry m_registry;

        void init_scene() {
            GPUTexture *monkey_texture = m_engine->get_texture("monkey");
            GPUTexture *monkey_black_texture = m_engine->get_texture("monkey_black");

            GPUMesh *monkey_mesh = m_engine->get_mesh("monkey");

            auto const monkey_1 = m_registry.create();
            m_registry.emplace<GPUMesh *>(monkey_1, monkey_mesh);
            m_registry.emplace<Material *>(monkey_1, m_engine->get_material("default_mesh"));
            m_registry.emplace<Transform>(monkey_1, glm::mat4{1.0F});
            m_registry.emplace<GPUTexture *>(monkey_1, monkey_texture);

            auto const monkey_2 = m_registry.create();
            m_registry.emplace<GPUMesh *>(monkey_2, monkey_mesh);
            m_registry.emplace<Material *>(monkey_2, m_engine->get_material("default_mesh"));
            glm::mat4 object_matrix = glm::translate(glm::mat4{1.0F}, glm::vec3(2, 0, 2));
            m_registry.emplace<Transform>(monkey_2, object_matrix);
            m_registry.emplace<GPUTexture *>(monkey_2, monkey_black_texture);

            for (auto &light: m_game_state.lighting_buffer.point_lights) {
                light.position = {1.0f, 1.0f, 1.0f, 1.0f};
                light.color = {0.0f, 0.0f, 0.0f, 0.0f};
            }
            m_game_state.lighting_buffer.point_lights[0] = {.position = {5.0f, 5.0f, 4.0f, 1.0f}, .color = {0.5f, 0.0f, 0.5f, 0.1f}};
            m_game_state.lighting_buffer.point_lights[1] = {.position = {-5.0f, 5.0f, 1.0f, 1.0f}, .color = {0.0f, 0.5f, 0.0f, 0.1f}};
        };

        void update_camera(Input input) {
            auto *window = m_window.get_window();

            static glm::vec3 cam_pos = {0.F, -6.F, 10.F};
            static glm::vec3 camera_front = {0.0F, 0.0F, -1.0F};

            float const cameraSpeed = 0.05F;
            const glm::vec3 cam_up = {0.F, 1.F, 0.F};
            if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
                cam_pos += cameraSpeed * camera_front;
            }
            if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
                cam_pos -= cameraSpeed * camera_front;
            }
            if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
                cam_pos -= glm::normalize(glm::cross(camera_front, cam_up)) * cameraSpeed;
            }
            if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
                cam_pos += glm::normalize(glm::cross(camera_front, cam_up)) * cameraSpeed;
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

            float const sensitivity = 0.1F;
            x_offset *= sensitivity;
            y_offset *= sensitivity;

            static float yaw = -90.F;
            static float pitch = 0.0F;
            yaw += x_offset;
            pitch += y_offset;
            if (pitch > 89.9F) {
                pitch = 89.9F;
            }
            if (pitch < -89.9F) {
                pitch = -89.9F;
            }

            glm::vec3 direction;
            direction.x = cosf(glm::radians(yaw)) * cosf(glm::radians(pitch));
            direction.y = sinf(glm::radians(pitch));
            direction.z = sinf(glm::radians(yaw)) * cosf(glm::radians(pitch));

            camera_front = glm::normalize(direction);
            glm::mat4 view = glm::lookAt(cam_pos, cam_pos + camera_front, cam_up);

            glm::mat4 projection = glm::perspective(glm::radians(70.F),
                                                    (float) m_window_extent.width / (float) m_window_extent.height, 0.1F,
                                                    20.0F);
            projection[1][1] *= -1;

            m_game_state.camera = {view, projection};
            m_game_state.lighting_buffer.inv_viewproj = glm::inverse(projection * view);
        };
    };
}// namespace lime
