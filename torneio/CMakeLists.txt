cmake_minimum_required(VERSION 3.15)
project(torneio)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(torneio
        torneio.c)
