cmake_minimum_required(VERSION 3.12.3)
project(banco)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(new_bank new_bank.c)
