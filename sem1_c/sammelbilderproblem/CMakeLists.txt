cmake_minimum_required(VERSION 3.6)
project(sammelbilderproblem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    arrays.c
    arrays.h
    interaktionen.c
    interaktionen.h
    sammelbilderproblem.c
    sammelbilderproblem.h
    sammelbilderproblem_main.c
    statistik.c
    statistik.h
    zahlensystem.c
    zahlensystem.h)

add_executable(sammelbilderproblem ${SOURCE_FILES})