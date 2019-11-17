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

void libera_numero(Int_Grande *n)
{
    free(n->num);
    free(n);
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

    if(soma == NULL) {
        printf("Deu ruim\n");
        exit(1);
    }
    if(n2->tam > n1->tam)
    {
        soma->tam = n2->tam;
        soma->max_tam = n2->max_tam;
        n1->max_tam = n2->max_tam;
        n1 = expande_int_grande(n1);
    }
    else
    {
        soma->tam = n1->tam;
        soma->max_tam = n1->max_tam;
        n2->max_tam = n1->max_tam;
        n2 = expande_int_grande(n2);
    }

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

    libera_numero(n1);
    libera_numero(n2);
    return soma;
}

void apresenta_int_grande(Int_Grande *n)
{
    for(int i = 0; i < n->tam; i++)
    {
        printf("%d", n->num[i]);
    }
    printf("\n");
}

int main()
{
    Int_Grande * num1, * num2, *soma;

    num1 = le_int_grande();
    num2 = le_int_grande();
    transforma_numero(num1);
    transforma_numero(num2);
    inverte_numeros(num1);
    inverte_numeros(num2);
    soma = soma_numeros(num1, num2);
    inverte_numeros(soma);
    apresenta_int_grande(soma);
    libera_numero(soma);

    return 0;
}
