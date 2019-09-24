#include <stdio.h>

typedef struct{
    int dia, mes, ano;
} data;

data leData();
void imprimeData (data atual);

data leData()
{
    data d;
    scanf("%d%d%d", &d.dia, &d.mes, &d.ano);
    return d;
}

void imprimeData (data atual)
{
    printf("A data informada eh %.2d/%.2d/%.4d.", atual.dia, atual.mes, atual.ano);
}

int main()
{
    data atual;
    atual = leData();
    imprimeData(atual);
    return 0;
}