cmake_minimum_required(VERSION 3.6)
project(fahrtenkosten)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    fahrtenkosten_main.c
    interaktionen.c
    interaktionen.h
    kosten.c
    kosten.h
    laengeneinheiten.c
    laengeneinheiten.h
    rauminhalt.c
    rauminhalt.h
    verbrauch.c
    verbrauch.h
    waehrungen.c
    waehrungen.h
    zahlensystem.c
    zahlensystem.h)

add_executable(fahrtenkosten ${SOURCE_FILES})