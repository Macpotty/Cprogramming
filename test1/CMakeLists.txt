cmake_minimum_required(VERSION 3.4)
project(test1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES test1.cpp)
add_executable(test1 ${SOURCE_FILES})