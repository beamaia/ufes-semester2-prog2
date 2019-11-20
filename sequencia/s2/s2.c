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

    ent.tam = 0;
    ent.tam_max = MAX;
    ent.vetor = (int*) malloc(sizeof(int) * ent.tam_max);

    return ent;
}

Entrada * expande_vetor(Entrada *vet)
{
    Entrada *aux = (Entrada *) malloc(sizeof(Entrada));
    aux->tam = vet->tam;
    aux->tam_max = vet->tam_max + MAX;
    aux->vetor = (int *) malloc(sizeof(int) * aux->tam_max);
    free(vet->vetor);
    free(vet);
    return aux;
}

void leitura(Entrada *ent)
{
    int num;
    char esp;

    while (scanf("%d%c", &num, &esp) == 2)
    {
        if (ent->tam_max == ent->tam)
            ent = expande_vetor(ent);

        ent->vetor[ent->tam++] = num;

        if (esp == '\n')
            break;
    }
}

int procura_sequencia(Entrada *ent)
{
    int cont = 0, cont_vezes = 0, add = 0, maior = 0, tam_seq = 0;
    for(int i = 0; i < ent->tam; i++)
    {
        for(int j = 0;j < ent->tam; j++)
        {
            while(ent->vetor[i + add++] == ent->vetor[j + add])
            {
                cont++;
            }

            if(cont_vezes == 0 && cont > 0)
            {
                cont_vezes++;
                tam_seq = cont;
                j += cont;
                cont = 0;
                continue;
            }

            if(cont == tam_seq)
            {
                cont_vezes++;
                j += cont;
                cont = 0;
            }
        }

        if(cont_vezes > maior)
        {
            maior = cont_vezes;
            ent->i = i;
            ent->tam_seq = tam_seq;
        }
    }

    return cont_vezes;
}

void apresenta(Entrada ent, int qtd)
{
    for(int i = 0; i < ent.tam_seq; i++)
    {
        printf("%d ", ent.vetor[ent.i + i]);
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
        apresenta(vetor, qtd);
    }
    else
        printf("0\n");
    free(vetor.vetor);
    return 0;
}