cmake_minimum_required(VERSION 3.2)
project(SideScroller)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES src/main.cpp src/main.cpp src/player.cpp src/player.h src/Game.cpp src/Game.h)
add_executable(SideScroller ${SOURCE_FILES} src/main.cpp)

target_link_libraries(SideScroller SDL2main SDL2)