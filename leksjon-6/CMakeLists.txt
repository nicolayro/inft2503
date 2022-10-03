cmake_minimum_required(VERSION 3.1)

project(examples6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra")

add_executable(main main.cpp)
