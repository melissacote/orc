cmake_minimum_required(VERSION 3.30)
project(orc)

set(CMAKE_CXX_STANDARD 20)

add_executable(orc app/main.cpp
        core/Map.cpp
        core/Map.h
        core/MapParsing.cpp
        core/MapParsing.h
        core/GameState.cpp
        core/GameState.h
        core/Position.h)
target_include_directories(orc PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_options(orc PRIVATE -Wall -Wextra -Wpedantic)
