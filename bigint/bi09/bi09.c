//
// Created by bea on 11/15/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 100

typedef struct{
    char *num;
    int tam;
    int max_tam;
} Int_Grande;

void inicializa_int_grande(Int_Grande *n)
{
    n->num = (char *) malloc(sizeof(char)*n->max_tam);

    for(int i = 0; i < n->max_tam; i++)
    {
        n->num[i] = 0;
    }
}

//void numero_inicial(Int_Grande *n)
//{
//    n->tam = 1;
//    n->max_tam = MAX_NUM;
//    inicializa_int_grande(n);
//    n->num[0] = 1;
//}

Int_Grande expande_int_grande(Int_Grande *n)
{
    Int_Grande aux;
    aux.max_tam = n->max_tam + MAX_NUM;
    aux.tam = n->tam;
    inicializa_int_grande(&aux);

    for(int i = 0; i < n->tam; i++)
    {
        aux.num[i] = n->num[i];
    }

    free(n->num);

    return aux;
}

void libera_numero(Int_Grande *n)
{
    free(n->num);
}

void inverte_numeros(Int_Grande *n)
{
    char aux;
    for(int i = 0; i < n->tam/2; i++)
    {
        aux = n->num[i];
        n->num[i] = n->num[n->tam - i - 1];
        n->num[n->tam - i - 1] = aux;
    }
}

void soma_numeros(Int_Grande *n1, Int_Grande *n2)
{
    for(int i = 0; i < n1->tam; i++)
    {
        if(i == n1->max_tam - 1)
            *n1 = expande_int_grande(n1);

        n1->num[i] += n2->num[i];

        if(n1->num[i] > 9)
        {
            n1->num[i + 1] += n1->num[i]/10;
            n1->num[i] = n1->num[i] % 10;
            if(i == n1->tam - 1)
                n1->tam++;
        }
    }
}

void copia_numero(Int_Grande *n, Int_Grande *aux)
{
    for(int i = 0; i < aux->tam; i++)
    {
        aux->num[i] = n->num[i];
    }
}

void multiplica_numeros(Int_Grande *n, int mul)
{
    Int_Grande aux;

    aux.max_tam = n->max_tam;
    aux.tam = n->tam;
    inicializa_int_grande(&aux);
    copia_numero(n, &aux);

    for(int i = 1; i < mul; i++)
    {
        soma_numeros(n, &aux);
    }

    libera_numero(&aux);
}

void apresenta_int_grande(Int_Grande *n)
{
    for(int i = 0; i < n->tam; i++)
    {
        printf("%d", n->num[i]);
    }
}

//void fatori   al_numero(Int_Grande *n, int mul)
//{
//    numero_inicial(n);
//
//    for(int i = 1; i < mul; i++)
//    {
//        multiplica_numeros(n, i + 1);
//    }
//}

int main()
{
    Int_Grande num;
    int mul;

    scanf("%d", &mul);

//    clock_t start = clock();

    if(mul == 0 || mul == 1)
    {
        printf("1");
//        clock_t stop = clock();
//        double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
//        printf("\nTime elapsed: %.5f\n", elapsed);
        return 0;
    }

    num.tam = 1;
    num.max_tam = MAX_NUM;
    inicializa_int_grande(&num);
    num.num[0] = 1;

    for(int i = 1; i < mul; i++)
    {
        multiplica_numeros(&num, i + 1);
    }

    inverte_numeros(&num);
    apresenta_int_grande(&num);
//    clock_t stop = clock();
//    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
//    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}
