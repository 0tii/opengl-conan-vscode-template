cmake_minimum_required(VERSION 3.23)
project(GlTemplate)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
add_compile_definitions(GLM_FORCE_DEFAULT_ALIGNED_GENTYPES)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)
find_package(assimp REQUIRED)
find_package(stb REQUIRED)
find_package(imgui REQUIRED)

# local source files
file(GLOB_RECURSE PROJECT_SOURCES src/*.cpp)

# combine sources
set(SOURCES ${PROJECT_SOURCES})

# build application
add_executable(GlTemplate ${SOURCES})

target_include_directories(GlTemplate PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_include_directories(GlTemplate PRIVATE ${CMAKE_BINARY_DIR}/include/imgui)


target_link_libraries(GlTemplate PRIVATE glfw glad::glad stb::stb assimp::assimp imgui::imgui)

if (WIN32)
    target_link_libraries(GlTemplate PRIVATE opengl32)
elseif (APPLE)
    target_link_libraries(GlTemplate PRIVATE "-framework OpenGL")
elseif (UNIX)
    target_link_libraries(GlTemplate PRIVATE GL)
endif()

# copy all conan-linked DLLs to the executable directory
add_custom_command(
    TARGET GlTemplate POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "$<TARGET_RUNTIME_DLLS:GlTemplate>"
    "$<TARGET_FILE_DIR:GlTemplate>"
    COMMAND_EXPAND_LISTS
)