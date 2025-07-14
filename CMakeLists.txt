cmake_minimum_required(VERSION 3.10...4.0)

project(Moon
        LANGUAGES CXX C
        DESCRIPTION "Moon Engine"
        VERSION 0.1.0
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(Moon)