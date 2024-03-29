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

int maior_len(int n1, int n2)
{
    if(n1 >= n2)
        return n1;
    else
        return n2;    
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
    tIntGrande n1, n2;
    scanf("%s %s", n1.num, n2.num);
    
    int vet1[100], vet2[100], vetsoma[100], len1, len2, len;
    len1 = strlen(n1.num);
    len2 = strlen(n2.num);
    torna_int(vet1, n1, len1);
    torna_int(vet2, n2, len2);
    soma_vets(vet1, vet2, vetsoma, len1, len2);
    len = maior_len(len1, len2);
    transforma_soma(vetsoma, len);
    imprime_soma(vetsoma, len);

    return 0;
}