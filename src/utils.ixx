module;

#include <filesystem>
#include <iostream>
#include <mutex>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <source_location>

export module lime.utils;

import vulkan;

std::once_flag ASSET_DIR_FLAG;
std::string ASSET_DIR;

void find_asset_dir() {
    std::string dir = {"assets/"};
    for (int i = 0; i < 5; i++) {
        if (std::filesystem::is_directory(dir)) {
            break;
        }
        dir = "../" + dir;
    }
    ASSET_DIR = dir;
}

std::string get_time() {
    std::time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm ltime;
    localtime_r(&t, &ltime);
    std::stringstream time_string{};
    time_string << std::put_time(&ltime, "%H:%M:%S");
    return time_string.str();
}

export namespace lime::utils {
    void vk_assert(vk::Result result, std::string_view message = "vk_assert failed", std::source_location location = std::source_location::current()) {
        if (result != vk::Result::eSuccess) {
            auto error_code = static_cast<int32_t>(result);
            std::cout << "Assert in:" << location.file_name() << "(" << location.line() << ":" << location.column() << ") `" << location.function_name() << ", Code: " << error_code << " `: " << message << std::endl;
            abort();
        }
    }
    void assert_true(bool result, std::string_view message = "assert_true failed", std::source_location location = std::source_location::current()) {
        if (!result) {
            std::cout << "Assert in:" << location.file_name() << "(" << location.line() << ":" << location.column() << ") `" << location.function_name() << "`: " << message << "\n";
            abort();
        }
    }

    void log_info(std::string_view message) {
        std::cout << get_time() << " [INFO] " << message << "\n";
    }

    void log_error(std::string_view message) {
        std::cout << get_time() << " [ERROR] " << message << "\n";
    }

    std::string_view get_asset_dir() {
        std::call_once(ASSET_DIR_FLAG, []() { find_asset_dir(); });
        return ASSET_DIR;
    }
}// namespace lime::utils
