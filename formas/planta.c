#include <stdio.h> 
#include "ponto.h"
#include "retangulo.h"
#include "circulo.h"
#include "triangulo.h"
#include "planta.h"

leia_planta(tPlanta *);
apresenta_planta(tPlanta *);
ordena(tPlanta *,  int(*compara)(tComodo *, tComodo *));