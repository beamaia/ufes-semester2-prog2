#include <stdio.h>
#include <stdlib.h>
#define MAX 40

typedef struct{
    int *vetor;
    int tam;
    int tam_max;
    int i;
    int tam_seq;
} Entrada;

Entrada inicializa_vetor()
{
    Entrada ent;

    ent.tam = ent.tam_seq = ent.i = 0;
    ent.tam_max = MAX;
    ent.vetor = (int*) malloc(sizeof(int) * ent.tam_max);

    return ent;
}

void expande_vetor(Entrada *vet)
{
    Entrada *aux = (Entrada *) malloc(sizeof(Entrada));
    aux->tam = vet->tam;
    aux->tam_max = vet->tam_max + MAX;
    aux->vetor = (int *) malloc(sizeof(int) * aux->tam_max);
    for(int i = 0; i < aux->tam; i++)
        aux->vetor[i] = vet->vetor[i];

    free(vet->vetor);
    vet->vetor = aux->vetor;
}

void leitura(Entrada *ent)
{
    int num;
    char esp;

    while (scanf("%d%c", &num, &esp) == 2)
    {
        if (ent->tam_max == ent->tam)
            expande_vetor(ent);

        ent->vetor[ent->tam++] = num;

        if (esp == '\n')
            break;
    }
}

int procura_sequencia(Entrada *ent)
{
    int cont = 0, cont_vezes = 0, add = 0, tam_seq = 0, cont_seq = 0, i_seq = 0, cont_maior = 0;
    for(int i = 0; i < ent->tam - 1; i++)
    {
        while( i + cont < ent->tam - 1 && ent->vetor[i + cont] + 1 == ent->vetor[i + 1 + cont])
        {
            cont++;
        }

        if(cont)
            cont++;

        for(int j = i + cont; j < ent->tam && cont > 0; j++)
        {
            while(ent->vetor[i + add] == ent->vetor[j + add] && (j + add) < ent->tam && add < cont)
            {
                add++;
            }

            if(add == cont)
            {
                cont_vezes++;
                j += cont - 1;
            }

            add = 0;
        }

        if(cont_vezes > cont_seq || (cont > 0 && !cont_seq))
        {
            i_seq = i;
            tam_seq = cont;
            cont_seq = cont_vezes + 1;
        }

        cont_vezes = 0;
        cont = 0;
    }

    ent->tam_seq = tam_seq;
    ent->i = i_seq;

    return cont_seq;
}

void apresenta(Entrada ent, int qtd)
{
    printf("%d", ent.vetor[ent.i]);
    for(int i = 1; i < ent.tam_seq; i++)
    {
        printf(" %d", ent.vetor[ent.i + i]);
    }
    printf("\n%d\n", qtd);
}

int main()
{
    Entrada vetor = inicializa_vetor();
    int qtd;
    leitura(&vetor);
    if(vetor.tam > 1) {
        qtd = procura_sequencia(&vetor);
        if(qtd)
            apresenta(vetor, qtd);
        else
            printf("0\n");
    }
    else
        printf("0\n");
    free(vetor.vetor);
    return 0;
}