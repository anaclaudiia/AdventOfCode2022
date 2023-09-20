cmake_minimum_required(VERSION 3.16.3)
project(AdventoOfCode2022)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") # works
set(CMAKE_CXX_STANDARD 14) # enable C++14 standard
include_directories("${PROJECT_SOURCE_DIR}")

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/*.h"
        "${PROJECT_SOURCE_DIR}/*.hpp"
        "${PROJECT_SOURCE_DIR}/*.cpp"
        "${PROJECT_SOURCE_DIR}/*.c"
)

add_executable(main ${all_SRCS})

