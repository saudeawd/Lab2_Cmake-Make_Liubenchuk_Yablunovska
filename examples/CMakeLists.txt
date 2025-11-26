cmake_minimum_required(VERSION 3.15)
project(vector_examples VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../library)

link_directories(${CMAKE_BINARY_DIR}/library)

add_executable(demo demo.cpp)
target_link_libraries(demo myvector)

if(APPLE)
    set(LIB_EXT ".dylib")
else()
    set(LIB_EXT ".so")
endif()


set(SHARED_LIB_NAME "libmyvector${LIB_EXT}")

add_custom_command(TARGET demo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_BINARY_DIR}/library/${SHARED_LIB_NAME}
        ${CMAKE_CURRENT_BINARY_DIR}
)
