#include <stdio.h>
#include "medalhas.h"

tMedalhas le_medalhas()
{
    tMedalhas medalhas;

    printf("QUANTIDADE DE MEDALHAS DE OURO:\n");
    scanf("%d", &medalhas.ouro);
    printf("QUANTIDADE DE MEDALHAS DE PRATA:\n");
    scanf("%d", &medalhas.prata);
    printf("QUANTIDADE DE MEDALHAS DE BRONZE:\n");
    scanf("%d", &medalhas.bronze);

    return medalhas;
}
int compara_medalhas(tMedalhas pais1, tMedalhas pais2)
{
    if(pais1.ouro > pais2.ouro)
        return 1;
    else if(pais1.ouro == pais2.ouro)
        if(pais1.prata > pais2.prata)
            return 1;
        else if(pais1.prata == pais2.prata)
            if(pais1.bronze > pais2.bronze )
                return 1;
    
    return 0;
}

int calcula_total(tMedalhas medalhas)
{
    return medalhas.ouro + medalhas.prata + medalhas.bronze;
}

int tem_medalha(tMedalhas medalhas)
{
    if(medalhas.total > 0)
        return 1;
    return 0;
}

void apresenta_medalhas(tMedalhas medalhas)
{
    printf("|     OURO     |\n");
    printf("|%-14|\n", medalhas.ouro);
    printf("|     PRATA    |\n");
    printf("|%-14|\n", medalhas.prata);
    printf("|    BRONZE    |\n");
    printf("|%-14|\n", medalhas.bronze);
}