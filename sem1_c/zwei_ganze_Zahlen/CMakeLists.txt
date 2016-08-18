cmake_minimum_required(VERSION 3.6)
project(zwei_ganze_Zahlen)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    interaktionen.c
    interaktionen.h
    zahlensystem.c
    zahlensystem.h
    zwei_ganze_zahlen_main.c)

add_executable(zwei_ganze_Zahlen ${SOURCE_FILES})