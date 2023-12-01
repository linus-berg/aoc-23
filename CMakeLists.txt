cmake_minimum_required(VERSION 3.26)
project(aoc)

set(CMAKE_CXX_STANDARD 17)

add_executable(aoc main.cpp
        utils/common.cpp
        utils/common.h
        days/1.cpp
        days/base.cpp
        days/1.h)
