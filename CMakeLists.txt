cmake_minimum_required(VERSION 3.21)
project(airport)

set(CMAKE_CXX_STANDARD 14)

add_executable(airport
        main.cpp
        src/manager.cpp
        src/airport.cpp
        src/coordinate.cpp
        src/airlines.cpp
        src/data.cpp
        src/header/graph.h
        src/header/menu.h
        src/menu.cpp)


