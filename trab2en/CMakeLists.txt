cmake_minimum_required(VERSION 3.12.3)
project(trab2en C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(trab2en
        apt.c
        apt.h
        catalog.c
        catalog.h
        category.c
        category.h
        house.c
        house.h
        lot.c
        lot.h
        lot_category.c
        lot_category.h
        main.c
        properties.c
        properties.h
        rectangle.c
        rectangle.h
        trapezoid.c
        trapezoid.h
        triangle.c
        triangle.h
        spec.c
        spec.h)
