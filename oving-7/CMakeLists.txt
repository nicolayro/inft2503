cmake_minimum_required(VERSION 3.1)

project(oving-7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(fraction main.cpp fraction.cpp)
add_executable(set main2.cpp set.cpp)


