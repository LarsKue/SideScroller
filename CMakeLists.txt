project(SideScroller)

cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

# Copy assets folder into build directory
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy libraries into build directory
configure_file(lib/dlls/SDL2.dll SDL2.dll COPYONLY)
configure_file(lib/dlls/SDL2_image.dll SDL2_image.dll COPYONLY)
configure_file(lib/dlls/libpng16-16.dll libpng16-16.dll COPYONLY)
configure_file(lib/dlls/zlib1.dll zlib1.dll COPYONLY)

set(SOURCE_FILES src/main.cpp src/player.cpp src/player.h src/Game.cpp src/Game.h src/TextureManager.cpp src/TextureManager.h src/GameObject.h src/GameObject.cpp)
add_executable(SideScroller ${SOURCE_FILES})

target_link_libraries(SideScroller SDL2main SDL2 SDL2_image)