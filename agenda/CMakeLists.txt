cmake_minimum_required(VERSION 3.15)
project(agenda C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(agenda
        agenda.c)
