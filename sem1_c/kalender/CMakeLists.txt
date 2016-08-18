cmake_minimum_required(VERSION 3.6)
project(kalender)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    interaktionen.c
    interaktionen.h
    kalender.c
    kalender.h
    kalender_main.c)

add_executable(kalender ${SOURCE_FILES})