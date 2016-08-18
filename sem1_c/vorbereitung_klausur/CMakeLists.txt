cmake_minimum_required(VERSION 3.6)
project(vorbereitung_klausur)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    plan_main.c)

add_executable(vorbereitung_klausur ${SOURCE_FILES})