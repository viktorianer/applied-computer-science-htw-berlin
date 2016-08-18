cmake_minimum_required(VERSION 3.6)
project(mehrwertsteuer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    mehrwertsteuer_berechnungen.c
    mehrwertsteuer_berechnungen.h
    mehrwertsteuer_main.c)

add_executable(mehrwertsteuer ${SOURCE_FILES})