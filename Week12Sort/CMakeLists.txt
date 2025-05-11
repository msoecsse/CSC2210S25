cmake_minimum_required(VERSION 3.29)
project(Week12Sort)

set(CMAKE_CXX_STANDARD 20)

add_executable(Week12Sort main.cpp)

add_executable(Week12SelectionSort SelectionSort.cpp)
add_executable(Week12InsertionSort InsertionSort.cpp)
add_executable(Week12MergeSort MergeSort.cpp)
add_executable(Week12QuickSort QuickSort.cpp)
add_executable(Week12HeapSort HeapSort.cpp)
add_executable(Week12RadixSort RadixSort.cpp)
add_executable(Week12BucketSort BucketSort.cpp)
add_executable(Week12ShellSort ShellSort.cpp)
add_executable(Week12BubbleSort BubbleSort.cpp)
add_executable(Week12BubbleSortperformance BubbleSortperformance.cpp
        stopwatch.cpp)
add_executable(Week12TimSort TimSort.cpp)
add_executable(Week12SortExercise Exercise.cpp)
add_executable(ShellSortVisual ShellSortVisual.cpp)
