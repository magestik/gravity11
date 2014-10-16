cmake_minimum_required(VERSION 2.8)

project(gravity11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

file(GLOB_RECURSE SRC ./*.cpp ./*.h ./*.inl)

include_directories(./)

add_library(gravity11 STATIC ${SRC})
