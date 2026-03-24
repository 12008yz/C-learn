cmake_minimum_required(VERSION 3.20)

project(cpp_starter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cpp_starter src/main.cpp)

option(BUILD_WEEK01 "Build week 01 memory exercise" ON)
option(BUILD_WEEK02 "Build week 02 RAII exercise" ON)

if(BUILD_WEEK01)
    add_subdirectory(exercises/week01_memory)
endif()

if(BUILD_WEEK02)
    add_subdirectory(exercises/week02_raii)
endif()
