cmake_minimum_required(VERSION 3.6)
project(hallo_welt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    hallo_welt.c)

add_executable(hallo_welt ${SOURCE_FILES})