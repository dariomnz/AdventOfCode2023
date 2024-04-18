cmake_minimum_required(VERSION 3.10)
project(AdventOfCode3)

include_directories(../lib_source)

set(MYLIB_BINARY_DIR ${CMAKE_BINARY_DIR}/lib)
file(MAKE_DIRECTORY ${MYLIB_BINARY_DIR})

add_subdirectory(../lib_source ${MYLIB_BINARY_DIR})

add_executable(main main.c)
target_link_libraries(main txtFile strUtils)
add_executable(main2 main2.c)
target_link_libraries(main2 txtFile strUtils)
