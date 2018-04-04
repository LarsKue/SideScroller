project(SideScroller)

cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

#set(SOURCE_FILES src/main.cpp src/player.cpp src/player.h src/Game.cpp src/Game.h src/TextureManager.cpp src/TextureManager.h src/GameObject.h src/GameObject.cpp src/Map.h src/Map.cpp)
file(GLOB SOURCES src/*.cpp)
add_executable(SideScroller ${SOURCES})

target_link_libraries(SideScroller SDL2main SDL2 SDL2_image)

# Copy assets folder into build directory
add_custom_command(
        TARGET SideScroller PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E
        remove_directory ${CMAKE_SOURCE_DIR}/cmake-build-debug/assets)

add_custom_command(
        TARGET SideScroller POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E
        copy_directory ${CMAKE_SOURCE_DIR}/assets ${CMAKE_SOURCE_DIR}/cmake-build-debug/assets)

# Copy libraries into build directory
add_custom_command(
        TARGET SideScroller POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E
        copy_directory ${CMAKE_SOURCE_DIR}/lib/dlls ${CMAKE_SOURCE_DIR}/cmake-build-debug)

# release
add_custom_command(
        TARGET SideScroller PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E
        remove_directory ${CMAKE_SOURCE_DIR}/cmake-build-release/assets)

add_custom_command(
        TARGET SideScroller POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E
        copy_directory ${CMAKE_SOURCE_DIR}/assets ${CMAKE_SOURCE_DIR}/cmake-build-release/assets)

# Copy libraries into build directory
add_custom_command(
        TARGET SideScroller POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E
        copy_directory ${CMAKE_SOURCE_DIR}/lib/dlls ${CMAKE_SOURCE_DIR}/cmake-build-release)