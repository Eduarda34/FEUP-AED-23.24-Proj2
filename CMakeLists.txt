cmake_minimum_required(VERSION 3.21)
project(airport)

set(CMAKE_CXX_STANDARD 14)

add_executable(airport main.cpp
        src/header/airport.h
        src/airport.cpp
        src/header/coordinate.h
        src/coordinate.cpp)
