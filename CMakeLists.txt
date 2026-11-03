cmake_minimum_required(VERSION 4.3)
project(DinoRunner)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw
        GIT_TAG        master
        GIT_SHALLOW    TRUE
)

set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")

FetchContent_MakeAvailable(glfw)

find_package(OpenGL REQUIRED)

add_executable(DinoRunner
        src/main.cpp
        src/glad.c
        src/util/shader.cpp
        src/util/texture.cpp
)

target_include_directories(DinoRunner PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(DinoRunner PRIVATE glfw OpenGL::GL)

if (APPLE)
    target_link_libraries(DinoRunner PRIVATE "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/textures DESTINATION ${CMAKE_CURRENT_BINARY_DIR})