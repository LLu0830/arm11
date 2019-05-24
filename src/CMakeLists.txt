cmake_minimum_required(VERSION 3.14)
project(src C)

set(CMAKE_C_STANDARD 11)

add_executable(src
        assemble.c
        emulate.c)