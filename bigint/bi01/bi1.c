#include <stdio.h>
#include <string.h>

typedef struct{
    char num[100];
} tIntGrande;

int comparacao(tIntGrande num1, tIntGrande num2)
{
    int len1, len2, i;
    len1 = strlen(num1.num);
    len2 = strlen(num2.num);

    if(len1 > len2)
        return 1;
    else if(len1 < len2)
        return 2;

    for(i = 0; i < len1; i++)
    {
        if(num1.num[i] > num2.num[i])
            return 1;
        else if(num1.num[i] < num2.num[i])
            return 2;
    }

    return 3;
}

void imprimeResultado(int com)
{
    if(com == 3)
    {
        printf("IGUAL");
    }
    else if(com == 2)
    {
        printf("MENOR");
    }
    else if(com == 1)
    {
        printf("MAIOR");
    }
}

int main()
{
    tIntGrande num1, num2;
    scanf("%s", num1.num);
    scanf("%*c%s", num2.num);

    int com = comparacao(num1, num2);
    imprimeResultado(com);
    return 0;
}