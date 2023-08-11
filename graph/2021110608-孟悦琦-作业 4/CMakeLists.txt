cmake_minimum_required(VERSION 3.23)
project(graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(graph main.cpp GraphMatrix.cpp GraphMatrix.h GraphLink.cpp GraphLink.h TranUtil.cpp TranUtil.h)
