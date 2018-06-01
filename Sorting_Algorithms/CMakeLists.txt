cmake_minimum_required(VERSION 2.8.12)

project(sort_alg)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2")

#Bring the headers, such as .h into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
set(SOURCES src/main.cpp src/sort.cpp)
set(HDR_FILES include/sort.hpp)

add_executable(sort_alg ${SOURCES} ${HDR_FILES})
