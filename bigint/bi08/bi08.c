#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 100

typedef struct{
    char *num;
    int tam;
    int max_tam;
} Int_Grande;

Int_Grande * inicializa_int_grande(Int_Grande *n)
{
    n->num = (char *) malloc(sizeof(char)*n->max_tam);

    for(int i = 0; i < n->max_tam; i++)
    {
        n->num[i] = 0;
    }

    return n;
}

Int_Grande * numero_inicial()
{
    Int_Grande * n;
    n = (Int_Grande *) malloc(sizeof(Int_Grande));
    n->tam = 0;
    n->max_tam = MAX_NUM;
    n = inicializa_int_grande(n);
    return n;
}

Int_Grande * expande_int_grande(Int_Grande *n)
{
    Int_Grande * aux;
    aux = (Int_Grande *) malloc(sizeof(Int_Grande));
    n->max_tam += MAX_NUM;
    aux->max_tam = n->max_tam;
    aux->tam = n->tam;
    inicializa_int_grande(aux);

    for(int i = 0; i < n->tam; i++)
    {
        aux->num[i] = n->num[i];
    }

    free(n->num);
    free(n);

    return aux;
}

Int_Grande * le_int_grande()
{
    Int_Grande *n;
    char aux;

    n = numero_inicial();

    for(int i = 0; i < n->max_tam; i++)
    {
        scanf("%c", &aux);

        if(i == n->max_tam - 1)
        {
            n = expande_int_grande(n);
        }

        if(aux >= '0' && aux <= '9')
        {
            n->num[i] = aux;
            n->tam++;
        }

        else
            break;
    }

    return n;
}

void transforma_numero(Int_Grande * n)
{
    for(int i = 0; i < n->tam; i++)
    {
        n->num[i] = n->num[i] - '0';
    }
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

Int_Grande *soma_numeros(Int_Grande *n1, Int_Grande *n2)
{
    Int_Grande * soma = (Int_Grande *) malloc((sizeof(Int_Grande)));

    soma->tam = n1->tam;
    soma->max_tam = n1->max_tam;
    soma = inicializa_int_grande(soma);

    for(int i = 0; i < soma->tam; i++)
    {
        if(i == soma->max_tam - 1)
            soma = expande_int_grande(soma);

        soma->num[i] += n2->num[i] + n1->num[i];

        if(soma->num[i] > 9)
        {
            soma->num[i + 1] += soma->num[i]/10;
            soma->num[i] = soma->num[i] % 10;
            if(i == soma->tam - 1)
                soma->tam++;
        }
    }

    return soma;
}

void anula_num(Int_Grande *n)
{
    n->num[0] = 0;
    n->tam = 1;
}
Int_Grande * copia_numero(Int_Grande *n, Int_Grande *aux)
{
    for(int i = 0; i < aux->tam; i++)
    {
        aux->num[i] = n->num[i];
    }

    return aux;
}

Int_Grande * multiplica_numeros(Int_Grande *n, int mul)
{
    Int_Grande *aux = (Int_Grande *) malloc(sizeof(Int_Grande));
    aux->max_tam = n->max_tam;
    aux->tam = n->tam;
    aux = inicializa_int_grande(aux);
    aux = copia_numero(n, aux);

    if(mul > 1)
    {
        n = soma_numeros(n, aux);
        for(int i = 1; i < mul - 1; i++)
        {
            n = soma_numeros(n, aux);
        }
    }

    if(mul == 0)
        anula_num(n);

    return n;
}


void apresenta_int_grande(Int_Grande *n)
{
    for(int i = 0; i < n->tam; i++)
    {
        printf("%d", n->num[i]);
    }
    printf("\n");
}
void libera_numero(Int_Grande *n)
{
    free(n->num);
    free(n);
}

int main()
{
    Int_Grande * num1, *num_mul;
    int mul;

    num1 = le_int_grande();
    scanf("%d", &mul);
    transforma_numero(num1);
    inverte_numeros(num1);
    num_mul = multiplica_numeros(num1, mul);
    inverte_numeros(num_mul);
    apresenta_int_grande(num_mul);
    libera_numero(num_mul);
    libera_numero(num1);

    return 0;
}


