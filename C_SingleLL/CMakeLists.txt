cmake_minimum_required(VERSION 3.29)
project(C_SingleLL C)

set(CMAKE_C_STANDARD 11)

add_executable(C_SingleLL main.c
        list.h
        list.c)
