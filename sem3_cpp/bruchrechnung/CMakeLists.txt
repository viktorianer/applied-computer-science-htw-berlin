cmake_minimum_required(VERSION 3.6)
project(bruchrechnung)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    bruch.c++
    bruch.h
    bruchrechner.c++
    bruchrechner.h
    bruchrechnung_main.c++
    sortierung.c++
    sortierung.h
    zufallsgenerator.c++
    zufallsgenerator.h)

add_executable(bruchrechnung ${SOURCE_FILES})