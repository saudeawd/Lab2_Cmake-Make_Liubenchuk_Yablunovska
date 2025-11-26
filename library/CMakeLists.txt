cmake_minimum_required(VERSION 3.15)
project(myvector_library VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(myvector STATIC myvector.cpp)
add_library(myvector_shared SHARED myvector.cpp)

set_target_properties(myvector_shared PROPERTIES OUTPUT_NAME "myvector")
