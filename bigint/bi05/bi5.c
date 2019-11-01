#include <stdio.h>
#include <string.h>

typedef struct{
    char num[101];
    int num_int[101];
    int tam;
} Int_Grande;


int le_int_grande(Int_Grande *n)
{
    int mul;
    scanf("%s %d", n->num, &mul);
    n->tam = strlen(n->num);
    return mul;
}

void transforma_numero(Int_Grande *n)
{
    for(int i = 0; i < n->tam; i++)
    {
        n->num_int[i] = n->num[i] - '0';
    }
}

void inverte_numeros(Int_Grande *n)
{
    int aux;
    for(int i = 0; i < n->tam/2; i++)
    {
        aux = n->num_int[i];
        n->num_int[i] = n->num_int[n->tam - i - 1];
        n->num_int[n->tam - i - 1] = aux;
    }
}

void copia_numero(Int_Grande *n1, Int_Grande *n2)
{
    for(int i = 0; i < n1->tam; i++)
    {
        n2->num_int[i] = n1->num_int[i];
    }

    n2->tam = n1->tam;
}

void soma_numeros(Int_Grande *n1, Int_Grande *n2)
{
    for(int i = 0; i < n2->tam; i++)
    {
        n2->num_int[i] += n1->num_int[i];

        if(n2->num_int[i] > 9)
        {
            n2->num_int[i + 1] += n2->num_int[i]/10;
            n2->num_int[i] = n2->num_int[i]%10;
            if(i == n2->tam - 1)
                n2->tam++;
        }
    }
}

void anula_num(Int_Grande *n)
{
        n->num_int[0] = 0;
        n->tam = 1;
}

void multiplica_numeros(Int_Grande *n, int mul)
{
    Int_Grande aux;
    copia_numero(n, &aux);
    
    if(mul > 1)
    {
        soma_numeros(&aux, n);
        for(int i = 1; i < mul - 1; i++)
        {
            soma_numeros(&aux, n);
        }
    }
    if(mul == 0)
        anula_num(n);
}


void apresenta_int_grande(Int_Grande n)
{
    for(int i = 0; i < n.tam; i++)
    {
        printf("%d", n.num_int[i]);
    }
    printf("\n");
}

int main()
{
    Int_Grande num;
    int mul;

    mul = le_int_grande(&num);
    transforma_numero(&num);
    inverte_numeros(&num);
    multiplica_numeros(&num, mul);
    inverte_numeros(&num);
    apresenta_int_grande(num);
}