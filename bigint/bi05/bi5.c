#include <stdio.h>
#include <string.h>

typedef struct{
    char num[100];
} tIntGrande;

void imprime_soma(int * vet, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        printf("%d", vet[i]);
    }
    printf("\n");
}

void torna_int(int * vet, tIntGrande n, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        vet[i] = n.num[i] - 48;
    }
}


void soma_vets(int * vet1, int * vet2, int * vetsoma, int len1, int len2)
{
    int i;
    if(len1 >= len2)
    {
        vetsoma[len1 - 1] -= -1;
        for(i = 1; i <= len2; i++)
        {
            vetsoma[len1 - i] = vet1[len1 - i] + vet2[len2 - i];
        }
        for(; i <= len1; i++)
        {
            vetsoma[len1 - i] = vet1[len1 - i];
        }
    }
    else
    {
        vetsoma[len2 - 1] -= -1;
        for(i = 1; i <= len1; i++)
        {
            vetsoma[len2 - i] = vet1[len1 - i] + vet2[len2 - i];
        }
        for(; i <= len2; i++)
        {
            vetsoma[len2 - i] = vet2[len2 - i];
        }
    }
    
}


void transforma_soma(int * vetsoma, int len)
{
    int i;
    for(i = 1; i < len; i++)
    {
        if(vetsoma[len - i] > 9)
        {
            vetsoma[len - i] -= 10;
            vetsoma[len - 1 - i] += 1;
        }
    }
}

int main()
{
    tIntGrande n1;
    int n2, i;
    scanf("%s %d", n1.num, &n2);
    
    int vet[100], vetsoma[100], len;
    len = strlen(n1.num);
    torna_int(vet, n1, len);
    soma_vets(vet, vet, vetsoma, len, len);
    transforma_soma(vetsoma, len);
    for(i = 0; i < n2 - 1; i++)
    {
        soma_vets(vetsoma, vet, vetsoma, len, len);
        transforma_soma(vetsoma, len);
    }
    
    imprime_soma(vetsoma, len);

    return 0;
}