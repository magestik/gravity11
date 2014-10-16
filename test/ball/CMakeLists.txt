cmake_minimum_required(VERSION 2.8)

project(ball)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

file(GLOB SRC *.h *.cpp)
find_package(SFML 2 COMPONENTS graphics window system REQUIRED)

include_directories(../../gravity11)
include_directories(. ${SFML_INCLUDE_DIR})

add_executable(ball ${SRC})

target_link_libraries(ball gravity11)
target_link_libraries(ball ${SFML_LIBRARIES})


