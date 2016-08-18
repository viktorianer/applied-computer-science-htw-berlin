cmake_minimum_required(VERSION 3.6)
project(tilgungsplan)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    interaktionen.c
    interaktionen.h
    tilgungsplan_main.c
    zinsgeschaeft.c
    zinsgeschaeft.h)

add_executable(tilgungsplan ${SOURCE_FILES})