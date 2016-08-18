cmake_minimum_required(VERSION 3.6)
project(benzin_verbrauch)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    berechne_verbrauch_benzin.c
    berechne_verbrauch_benzin.h
    durchschnittsverbrauch_benzin_main.c
    erfasse_zahlen.c
    erfasse_zahlen.h
    interaktionen.c
    interaktionen.h)

add_executable(benzin_verbrauch ${SOURCE_FILES})