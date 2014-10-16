cmake_minimum_required(VERSION 2.8)

project(simple)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

include_directories(../../gravity11)

add_executable(simple simple.cpp)

target_link_libraries(simple gravity11)
