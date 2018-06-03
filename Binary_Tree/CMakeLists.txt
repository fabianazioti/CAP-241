cmake_minimum_required(VERSION 2.8.12)

project(btree)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Bring the headers, such as .h into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
set(SOURCES src/main.cpp)
set(HDR_FILES include/btree.hpp)

add_executable(arv ${SOURCES} ${HDR_FILES})
