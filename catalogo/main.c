#include "academico.h"

int main()
{
    Academico a;
    a = le_academico();
    apresenta_academico(a);
    libera_academico(a);
    return 0;
}