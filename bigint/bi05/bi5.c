#include <stdio.h>
#include <string.h>

typedef struct{
    char num[100];
    int tam;
} tIntGrande;

void zera(int *vet, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vet[i] = 0;
    }
}

void transforma_int(int *vet1, int *vet2, tIntGrande *n)
{
    for(int i = 0; i < n->tam; i++)
    {
        vet1[i] = n->num[i] - '0';
        vet2[i] = n->num[i] - '0';
    }
}

void inverte(int *vet, int tam)
{
    int aux;
    for(int i = 0; i < tam/2; i++)
    {
        aux = vet[i];
        vet[i] = vet[tam - i - 1];
        vet[tam - i - 1] = aux;
    }
    // for(int i = 0; i < tam; i++)
    // {
    //     aux[i] = vet[i];
    // }
    // for(int i = 0; i < tam; i++)
    // {
    //     vet[i] = aux[tam - i - 1];
    // }
}

void transforma_bigint(int *vet, tIntGrande *n)
{
    int i;
    for(i = 0; i < n->tam; i++)
    {
        n->num[i] = vet[i] + '0';
    }
    n->num[i] = '\0';
}

void soma(int * vet, int * vetsoma, tIntGrande * n)
{
    int vai1;
    for(int i = 0; i < n->tam; i++)
    {
        vetsoma[i] += vet[i];
        if(vetsoma[i] > 9)
        {
            vai1 = vetsoma[i]/10;
            vetsoma[i] -= vai1 * 10;
            vetsoma[i + 1] += vai1;

            if(i + 1 == n->tam)
                n->tam++;
        }
    }
}

void mult(int *vet, int *vetsoma, tIntGrande *n, int mul)
{
    for(int i = 0; i < mul - 1; i++)
    {
        soma(vet, vetsoma, n);
    }
}

void apresenta(tIntGrande n)
{
    printf("%s\n", n.num);
}

int main()
{
    tIntGrande n1;
    int n2, vet[100], vetsoma[100];
    scanf("%s %d", n1.num, &n2);
    n1.tam = strlen(n1.num);
    zera(vet, n1.tam);
    zera(vetsoma, n1.tam);
    transforma_int(vet, vetsoma, &n1);
    inverte(vet, n1.tam);
    inverte(vetsoma, n1.tam);
    mult(vet, vetsoma, &n1, n2);
    inverte(vetsoma, n1.tam);
    transforma_bigint(vetsoma, &n1);
    apresenta(n1);
    return 0;
}