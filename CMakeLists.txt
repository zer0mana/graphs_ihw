cmake_minimum_required(VERSION 3.25)
project(ihw3)

set(CMAKE_CXX_STANDARD 17)

add_executable(ihw3 main.cpp graph/complete_graph.h graph/connected_graph.h graph/sparse_graph.h graph/base_graph.h search_functions.h)
