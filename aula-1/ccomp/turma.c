#include <stdio.h>
#include "turma.h"
#include "aluno.h"
#include "data.h"

void leia_turma(tTurma * ccomp)
{
    int i;

    for(i = 0; i < MAX_ALUNOS; i++)
    {

        leia_aluno(&ccomp->aluno[i]);
        if(nao_tem_aluno(&ccomp->aluno[i]))
            break;
    }
    ccomp->qtd_alunos = i;
}

void troca_alunos(tTurma * ccomp, int j)
{
    tAluno temp;
    temp = ccomp->aluno[j];
    ccomp->aluno[j] = ccomp->aluno[j + 1];
    ccomp->aluno[j + 1] = temp;
}

void ordena(tTurma * ccomp, int (*compar)(tAluno *, tAluno *)) 
{
    for(int i = 0; i < ccomp->qtd_alunos - 1; i++)
        for(int j = 0; j < ccomp->qtd_alunos - 1 - i; j++) 
            if((*compar)(&ccomp->aluno[j], &ccomp->aluno[j + 1]))
                troca_alunos(ccomp, j);
}

void apresenta_turma(tTurma * ccomp)
{
    printf("\n");
    for(int i = 0; i < ccomp->qtd_alunos; i++)
    {
        imprime_informacoes(&ccomp->aluno[i]);
    }
}

void apresenta_aniversariantes(tTurma * ccomp, tData hoje)
{
    printf("\n\n\n**************");
    printf("\nAniversariantes:");

    for(int i = 0; i < ccomp->qtd_alunos; i++)
    {
        if(tem_aniversario(&ccomp->aluno[i], hoje))
            imprime_informacoes(&ccomp->aluno[i]);
    }

    printf("\n\n**************");

}

void apresenta_excelentes(tTurma * ccomp)
{   
    printf("\n\n\n**************");
    printf("\nExcelentes:");

    for(int i = 0; i < ccomp->qtd_alunos; i++)
    {
        if(aluno_excelente(&ccomp->aluno[i]))
            imprime_informacoes(&ccomp->aluno[i]);
    }

    printf("\n\n**************");

}