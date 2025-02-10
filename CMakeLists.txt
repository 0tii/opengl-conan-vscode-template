cmake_minimum_required(VERSION 3.23)
project(xc0n)
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

# local source files
file(GLOB_RECURSE PROJECT_SOURCES src/*.cpp)

# combine sources
set(SOURCES ${PROJECT_SOURCES})

# build application
add_executable(xc0n ${SOURCES})

target_include_directories(xc0n PUBLIC ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(xc0n PRIVATE glfw glad::glad stb::stb assimp::assimp)

if (WIN32)
    target_link_libraries(xc0n PRIVATE opengl32)
elseif (APPLE)
    target_link_libraries(xc0n PRIVATE "-framework OpenGL")
elseif (UNIX)
    target_link_libraries(xc0n PRIVATE GL)
endif()