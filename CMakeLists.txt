cmake_minimum_required(VERSION 3.26)
project(aoc)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost 1.83.0 COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

endif()

include_directories(include)

add_executable(aoc main.cpp
        utils/common.cpp
        utils/common.h
        days/Day1/Day1.cpp
        days/Day1/Day1.h
        days/Day2/Day2.cpp
        days/Day2/Day2.h
        days/Day2/Game.h
        days/Day2/GameSet.h
        days/Day2/const.h
        days/Day3/Day3.cpp
        days/Day3/Day3.h
        days/Day3/Grid.h
        include/base.h
        days/Day3/GridNumber.h
        days/Day4/Day4.cpp
        days/Day4/Day4.h
        days/Day4/Card.h)

if(Boost_FOUND)
    target_link_libraries(aoc ${Boost_LIBRARIES})
endif()