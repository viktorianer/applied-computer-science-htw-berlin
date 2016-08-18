cmake_minimum_required(VERSION 3.6)
project(lotto)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    arrays.c
    arrays.h
    interaktionen.c
    interaktionen.h
    lotto.c
    lotto.h
    lotto_main.c
    statistik.c
    statistik.h
    zahlensystem.c
    zahlensystem.h)

add_executable(lotto ${SOURCE_FILES})