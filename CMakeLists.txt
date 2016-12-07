cmake_minimum_required(VERSION 3.5)
project(StackExpressionSolver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c stack.h util.h varlist.h)
add_executable(StackExpressionSolver ${SOURCE_FILES})