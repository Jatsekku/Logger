cmake_minimum_required(VERSION 3.15)
project(logger)

add_subdirectory(include)
add_subdirectory(src)

option(BUILD_EXAMPLES "Build examples switch" ON)

if (BUILD_EXAMPLES)
    message(STATUS "Building exmaples")
    add_subdirectory(example)
endif()
