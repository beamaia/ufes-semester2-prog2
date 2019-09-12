#include "ponto.h"
#include "retangulo.h"
#include "circulo.h"
#include "triangulo.h"
#include "planta.h"

void main()
{
    tPlanta planta;
    leia_planta(&planta);
    ordena(&planta, compara_perimetro);
    apresenta_planta(&planta);
}