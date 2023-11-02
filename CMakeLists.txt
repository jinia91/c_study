cmake_minimum_required(VERSION 3.24)
project(hello_world C)

set(CMAKE_C_STANDARD 11)

add_library(hello_world library.c SpinLock.c Mutex.c Mutex.c)
