#include <stdio.h>
#include <string.h>

typedef struct{
    char num[100];
} tIntGrande;

void troca(tIntGrande n, int * vet, int * len)
{   
    int i;
    for(i = 0; i < *len; i++)
    {
        vet[i] = n.num[i] - 48;
    }
}

void soma(int *vet, int * len)
{
    int i, j;
    vet[*len - 1] = vet[*len - 1] + 1;
    for(i = *len - 1; i > 0 && *len <= 99; i--)
    {
        if(vet[i] > 9 && *len != 1)
        {
            vet[i] = vet[i] - 10;
            vet[i - 1] = vet[i - 1] +1;
        }
        else
        {
            break;
        } 
    }
}

void imprime(int * vet, int len)
{
    int i;
    for(i = 0; i < len; i++)
        printf("%d", vet[i]);
}

int main()
{
    tIntGrande n;
    int vet[100], len;
    scanf("%s", n.num);
    len = strlen(n.num);
    troca(n, vet, &len);
    soma(vet, &len);
    imprime(vet, len);
}