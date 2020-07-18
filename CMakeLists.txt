cmake_minimum_required(VERSION 3.0)

add_compile_options(-Wall -Wextra -Werror -Wpedantic)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11")

project(ImageProcessing)

add_executable(
    ImageProcessing
    test/main.cpp
    src/Image.cpp
    src/Image.h
)