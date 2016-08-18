cmake_minimum_required(VERSION 3.6)
project(char_ausgabe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    char_ausgabe.c)

add_executable(char_ausgabe ${SOURCE_FILES})