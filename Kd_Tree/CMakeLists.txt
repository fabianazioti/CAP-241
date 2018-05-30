cmake_minimum_required(VERSION 2.8.12)

project(kdtree)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Bring the headers, such as .h into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
set(SOURCES src/main.cpp)
set(HDR_FILES include/kdtree.hpp)

#However, the file(GLOB...) allows for wildcard additions:
#file(GLOB SOURCES "src/*.cpp")

#file(GLOB HDR_FILES "include/*.hpp")

add_executable(kdtree ${SOURCES} ${HDR_FILES})

