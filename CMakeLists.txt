cmake_minimum_required(VERSION 3.16)
project(pong CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# raylib installed via Homebrew (brew install raylib)
find_package(raylib REQUIRED)

add_executable(pong main.cpp game.cpp player.cpp bullet.cpp enemy.cpp)
target_link_libraries(pong PRIVATE raylib)

if(APPLE)
    target_link_libraries(pong PRIVATE "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
endif()
