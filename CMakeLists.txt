cmake_minimum_required(VERSION 3.5)

project(CarFinder LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES
        "*.h"
        "*.cpp"
    )

add_executable(CarFinder ${SOURCES})
