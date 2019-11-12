cmake_minimum_required(VERSION 3.12)
project(trab2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
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
