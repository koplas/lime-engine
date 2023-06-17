module;

#include <GLFW/glfw3.h>
#include <bit>
#include <stdlib.h>


export module Window;
import vulkan;

export struct Input {
    bool should_window_close;
    bool window_resized;
    float cursor_x;
    float cursor_y;
};

static void framebuffer_size_callback(GLFWwindow *glfw_window, int width, int height);
static void cursor_callback(GLFWwindow *glfw_window, double x, double y);
static void window_focus_callback(GLFWwindow *glfw_window, int focused);

export namespace lime {
    class Window {
    public:
        Window() {
            if (!glfwInit()) {
                abort();
            }
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
            m_window = glfwCreateWindow(1700, 900, "Bambus", nullptr, nullptr);
            if (!m_window) {
                abort();
            }
            glfwSetWindowUserPointer(m_window, this);
            glfwSetWindowSizeLimits(m_window, 100, 100, 8000, 8000);

            m_cursor_enabled = true;
            if (glfwRawMouseMotionSupported())
                glfwSetInputMode(m_window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
            glfwSetCursorPosCallback(m_window, cursor_callback);
            glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
            glfwSetWindowFocusCallback(m_window, window_focus_callback);
        };

        ~Window() {
            glfwDestroyWindow(m_window);
            glfwTerminate();
        };

        Input poll_input() {
            glfwPollEvents();
            if (m_cursor_enabled && glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
                glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
                glfwSetCursorPos(m_window, 0, 0);
                m_cursor_enabled = false;
            }


            Input input = {};
            input.should_window_close = glfwWindowShouldClose(m_window);
            input.cursor_x = m_cursor_x;
            input.cursor_y = m_cursor_y;
            input.window_resized = m_window_resized;
            m_window_resized = false;
            return input;
        };

        vk::Extent2D get_framebuffer_size() {
            uint32_t height = 0;
            uint32_t width = 0;
            glfwGetFramebufferSize(m_window, std::bit_cast<int *>(&width), std::bit_cast<int *>(&height));
            return vk::Extent2D{width, height};
        };

        GLFWwindow *get_window() {
            return m_window;
        };

        void enable_cursor() {
            m_cursor_enabled = true;
            glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        };


        float m_cursor_x = 0.0F;
        float m_cursor_y = 0.0F;
        bool m_cursor_enabled = false;
        bool m_window_resized = false;

    private:
        GLFWwindow *m_window;
    };
}// namespace lime

static void cursor_callback(GLFWwindow *glfw_window, double x, double y) {
    auto *window = static_cast<lime::Window *>(glfwGetWindowUserPointer(glfw_window));
    if (!window->m_cursor_enabled) {
        window->m_cursor_x += (float) x;
        window->m_cursor_y += (float) y;
        glfwSetCursorPos(glfw_window, 0, 0);
    }
}


static void framebuffer_size_callback(GLFWwindow *glfw_window, int width, int height) {
    (void) width;
    (void) height;
    auto *window = static_cast<lime::Window *>(glfwGetWindowUserPointer(glfw_window));
    window->m_window_resized = true;
}

static void window_focus_callback(GLFWwindow *glfw_window, int focused) {
    auto *window = static_cast<lime::Window *>(glfwGetWindowUserPointer(glfw_window));
    if (!focused) {
        glfwSetInputMode(glfw_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        window->m_cursor_enabled = true;
    }
}
