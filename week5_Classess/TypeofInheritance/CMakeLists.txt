cmake_minimum_required(VERSION 3.29)

# set the project name
project(TypeofInheritance)
set(CMAKE_CXX_STANDARD 21)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(new_target single_inheritance.cpp
        multiple_inheritance.cpp
        hierarchical_inheritance.cpp
        multilevel_inheritance.cpp)
