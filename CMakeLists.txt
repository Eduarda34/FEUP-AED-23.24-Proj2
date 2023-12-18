cmake_minimum_required(VERSION 3.26)
project(airport)

set(CMAKE_CXX_STANDARD 17)

add_executable(airport main.cpp
        src/header/airport.h
        src/airport.cpp
        src/header/coordinate.h
        src/coordinate.cpp)
