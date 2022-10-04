cmake_minimum_required(VERSION 3.1)

project(oving-6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra")

add_executable(chess chess.cpp)

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(server server.cpp)
target_link_libraries(server ${Boost_LIBRARIES})
