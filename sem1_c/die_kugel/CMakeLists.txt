cmake_minimum_required(VERSION 3.6)
project(die_kugel)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    die_kugel_main.c
    interaktionen.c
    interaktionen.h
    laengeneinheiten.c
    laengeneinheiten.h
    mathe.c
    mathe.h)

add_executable(die_kugel ${SOURCE_FILES})