cmake_minimum_required(VERSION 3.1)

project(oving-2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(solution12 solution12.cpp)
add_executable(solution3 solution3.cpp commodity.cpp)
