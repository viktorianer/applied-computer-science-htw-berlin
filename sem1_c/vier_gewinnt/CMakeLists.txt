cmake_minimum_required(VERSION 3.6)
project(vier_gewinnt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    arrays.c
    arrays.h
    interaktionen.c
    interaktionen.h
    statistik.c
    statistik.h
    vier_gewinnt.c
    vier_gewinnt.h
    vier_gewinnt_main.c
    zahlensystem.c
    zahlensystem.h)

add_executable(vier_gewinnt ${SOURCE_FILES})