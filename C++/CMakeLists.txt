cmake_minimum_required(VERSION 3.19)
project(C__)

set(CMAKE_CXX_STANDARD 14)

add_executable(C__ AOC_Clib/fileReader.h AOC_Clib/AOClib.h AOC_Clib/queueUtils.h D_07/main.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/D_07/input.in
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
