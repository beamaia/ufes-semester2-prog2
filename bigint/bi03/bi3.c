#include <stdio.h>
#include <string.h>

typedef struct{
    char num[100];
} tIntGrande;



int main()
{
    tIntGrande n;
    scanf("%s", n.num);

    int i, j, vet[100];
    for(i = 0; i < strlen(n.num); i++)
    {
        vet[i] = n.num[i] - 48;
    }    

    int len = strlen(n.num);
    vet[len - 1] = vet[len - 1] - 1;
    for(i = len - 1; i >= 0; i--)
    {
        if(vet[i] < 0 && len != 1)
        {
            vet[i] = 9;
            vet[i - 1] -= 1;
        }
        else if(vet[0] == 0 && len != 1)
        {
            for(j = 0; j < len - 1; j++)
            {
                vet[j] = vet[j + 1];
            }
            len = len - 1;
        }
        else
        {
            break;
        }     
    }

    for(i = 0; i<len; i++)
    {
        printf("%d",vet[i]);
    }

    return 0;
}