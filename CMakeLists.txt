cmake_minimum_required(VERSION 3.20.0)
project(PathFinder VERSION 1.0.0 LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(NoInSourceBuilds)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src bin)
add_subdirectory(test)
