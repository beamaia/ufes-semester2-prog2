#include <stdio.h>
#include "jogo.h"

void lerJogo(tJogo *j)
{
    scanf("%s", j->nome1);
    scanf("%d", &j->gols1);
    scanf("%s", j->nome2);
    scanf("%s", &j->gols2);
}