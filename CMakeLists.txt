cmake_minimum_required(VERSION 3.15)
project(grep)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES src/main.cpp src/classes/*.cpp src/classes/*.h)

add_executable(grep ${SOURCES})