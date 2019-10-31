cmake_minimum_required(VERSION 3.12)
project(catalogo C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(catalogo
    academico.c
    academico.h
    catalogo.c
    catalogo.h
    main.c)
