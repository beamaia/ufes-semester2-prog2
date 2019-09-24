#include <stdio.h>
#include <string.h>

typedef struct{
    char num[100];
} tIntGrande;

void trocaPrint(tIntGrande num1)
{
    int len1, i, j;
    int vet1[100];
    int vai1 = 0;

    len1 = strlen(num1.num);
    printf("%d\n", len1);
    for(i = 0; i < len1; i++)
    {
        vet1[i] = num1.num[i] - 48;
        printf("->%d %d\n", i, vet1[i]);
    }

    vet1[len1 - 1] += 1;

    for(i = len1 - 1; i >= 0 && len1 <= 99; i--)
    {
        if(vet1[i] > 9)
        {
            vet1[i] = 0;

            if(i == 0)
            {

                for(j = len1 - 2; j > 0; j--)
                {
                    vet1[j] = vet1[j - 1];
                }

                vai1 = 1;
                vet1[0] = 1;
            }
            else
            {
                vet1[i - 1] += 1;
            }
        }
        else
            break;
    }

    for(i = 0; i < (vai1 + len1); i++)
    {
        printf("%d = %d\n",i, vet1[i]);
    }
}

int main()
{
    tIntGrande n;
    scanf("%s", n.num);
    trocaPrint(n);
}