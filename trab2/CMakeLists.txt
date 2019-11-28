cmake_minimum_required(VERSION 3.15)
project(trab2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(trab2
        apto.c
        apto.h
        casa.c
        casa.h
        catalogo.c
        catalogo.h
        categoria.c
        categoria.h
        espec.c
        espec.h
        imovel.c
        imovel.h
        main.c
        retangulo.c
        retangulo.h
        trapezio.c
        trapezio.h
        triangulo.c
        triangulo.h)
