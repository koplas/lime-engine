cmake_minimum_required(VERSION 3.26)
project(lime-engine)

set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    include(clang_modules.cmake)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # include(gcc_modules.cmake)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    include(msvc_modules.cmake)
endif ()


set(CMAKE_CXX_STANDARD 20)

find_program(GLSLC glslc HINTS /usr/bin /usr/local/bin $ENV{VULKAN_SDK}/Bin/ $ENV{VULKAN_SDK}/Bin32/)

include_directories(third_party/)

set(CMAKE_CURRENT_SOURCE_DIR "src/")
file(GLOB_RECURSE ALL_MODULE_FILES
        src/*.ixx
)

file(GLOB_RECURSE ALL_CPP_FILES
        src/*.cpp
)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "-stdlib=libc++ -Wall -fno-rtti -mavx2 -fno-exceptions -fomit-frame-pointer -fno-exceptions -fno-asynchronous-unwind-tables -Wno-read-modules-implicitly -Wno-nullability-completeness -ferror-limit=0")
    set(CMAKE_CXX_FLAGS_DEBUG "-ftime-trace -g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -ffast-math -fvisibility=hidden -flto")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g -DNDEBUG -ffast-math")
endif ()

find_package(Vulkan REQUIRED)

include_directories(${Vulkan_INCLUDE_DIR})

set(GLFW_STANDALONE OFF)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_INSTALL OFF)
set(GLFW_BUILD_DOCS OFF)

add_subdirectory(glm/glm)
include_directories(glm)

add_subdirectory(glfw)
include_directories(glfw/include)

file(GLOB_RECURSE GLSL_SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/shaders/*.frag"
        "${PROJECT_SOURCE_DIR}/shaders/*.vert"
        "${PROJECT_SOURCE_DIR}/shaders/*.comp"
)

foreach (GLSL ${GLSL_SOURCE_FILES})
    message(STATUS "BUILDING SHADER")
    get_filename_component(FILE_NAME ${GLSL} NAME)
    set(SPIRV "${PROJECT_SOURCE_DIR}/assets/shaders/${FILE_NAME}.spv")
    message(STATUS ${GLSL})
    add_custom_command(
            OUTPUT ${SPIRV}
            COMMAND ${GLSLC} ${GLSL} --target-env=vulkan1.3 -g -o ${SPIRV}
            DEPENDS ${GLSL})
    list(APPEND SPIRV_BINARY_FILES ${SPIRV})
endforeach (GLSL)

add_custom_target(
        Shaders
        DEPENDS ${SPIRV_BINARY_FILES}
)

add_executable(lime-engine ${ALL_CPP_FILES})

target_link_libraries(lime-engine glfw ${Vulkan_LIBRARIES})
target_sources(lime-engine
        PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
        ${ALL_MODULE_FILES}
)
