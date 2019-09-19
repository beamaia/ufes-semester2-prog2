#include <stdio.h>
#include "turma.h"

int main()
{
    FILE * leitura;
    tTurma turma;
    leitura = fopen("binario", "rb");
    for(int i = 0; i < 40; i++)
    {
        fread(&turma, sizeof(tTurma), 1, leitura);
    }
    fclose(leitura);
    return 0;
}