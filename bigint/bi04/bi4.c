#include <stdio.h>
#include <string.h>

typedef struct{
    char num[100];
} tIntGrande;

void torna_int(int * vet, tIntGrande n)
{
    int i;
    for(i = 0; i < strlen(n.num) + 1; i++)
    {
        printf("a");
        if(i == strlen(n.num))
            vet[i] = -1;
        else
            vet[i] = n.num[i] - 48;
        
    }
}

int len_vet(int * vet)
{
    int len, i;
    for(i = 1; ;i++)
    {
        if(i == -1)
            return i;
    }
}

void soma_vets(int * vet1, int * vet2, int * vetsoma)
{
    int i, len1, len2;
    len1 = len_vet(vet1);
    len2 = len_vet(vet2);
    if(len1 >= len2)
    {
        vetsoma[len1 - 1] = -1;
        for(i = 1; i < len2; i++)
        {
            vetsoma[len1 - 1 -i] = vet1[len1 - 1 - i] + vet2[len2 - 1 -i];
        }
        for(; i < len1; i++)
        {
            vetsoma[len1 - 1 - i] = vet1[len1 - 1 -i];
        }
    }
    else
    {
        vetsoma[len2 - 1] = -1;
        for(i = 1; i < len1; i++)
        {
            vetsoma[len2 - 1 -i] = vet1[len1 - 1 - i] + vet2[len2 - 1 -i];
        }
        for(; i < len2; i++)
        {
            vetsoma[len2 - 1 - i] = vet2[len2 - 1 -i];
        }
    }
    
}

void transforma_soma(int * vetsoma)
{
    int i, len;
    len = len_vet(vetsoma);

    for(i = 1; i < len - 1; i++)
    {
        if(vetsoma[len - 1 - i] > 9)
        {
            vetsoma[len - 1 - i] -= 10;
            vetsoma[len - 2 - i] += 1;
        }
    }
}

void imprime_soma(int * vet)
{
    int i, len;
    len = len_vet(vet);
    for(i = 0; i < len - 1; i++)
    {
        printf("%d", vet[i]);
    }
}

int main()
{
    tIntGrande n1, n2;
    scanf("%s %s", n1.num, n2.num);
    printf("%s %s", n1.num, n2.num);

    int vet1[100], vet2[100], vetsoma[100], len;
    torna_int(vet1, n1);
    torna_int(vet2, n2);
    soma_vets(vet1, vet2, vetsoma);

    printf("\n1: %d, 2:%d \n", len_vet(vet1), len_vet(vet2));
    // transforma_soma(vetsoma);
    // imprime_soma(vetsoma);

    return 0;
}