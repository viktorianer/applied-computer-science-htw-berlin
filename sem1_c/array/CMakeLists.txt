cmake_minimum_required(VERSION 3.6)
project(array)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    array_main.c
    arrays.c
    arrays.h
    interaktionen.c
    interaktionen.h
    statistik.c
    statistik.h
    zahlensystem.c
    zahlensystem.h)

add_executable(array ${SOURCE_FILES})