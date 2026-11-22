cmake_minimum_required(VERSION 3.30)
project(orc)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.1.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

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
target_link_libraries(orc PRIVATE SFML::Graphics)