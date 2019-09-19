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
    FILE * turma;
    turma = fopen("turma", "wb");
    fwrite("\n", sizeof(char), 1, turma);
    for(int i = 0; i < ccomp->qtd_alunos; i++)
    {
        imprime_informacoes(&ccomp->aluno[i], turma);
    }
    fclose(turma);
}

void apresenta_aniversariantes(tTurma * ccomp, tData hoje)
{
    FILE * aniversario;
    aniversario = fopen("aniversario", "wb");
    printf("\n\n\n**************");
    printf("\nAniversariantes:");

    for(int i = 0; i < ccomp->qtd_alunos; i++)
    {
        if(tem_aniversario(&ccomp->aluno[i], hoje))
            imprime_informacoes(&ccomp->aluno[i], aniversario);
    }

    printf("\n\n**************");
    fclose(aniversario);
}

void apresenta_excelentes(tTurma * ccomp)
{   
    FILE * excelentes;
    excelentes = fopen("excelentes", "wb");
    printf("\n\n\n**************");
    printf("\nExcelentes:");

    for(int i = 0; i < ccomp->qtd_alunos; i++)
    {
        if(aluno_excelente(&ccomp->aluno[i]))
            imprime_informacoes(&ccomp->aluno[i], excelentes);
    }

    printf("\n\n**************");
    fclose(excelentes);
}

void apresenta_binario(tTurma ccomp)
{
    FILE * turma;
    turma = fopen("binario", "wb");
    fwrite(&ccomp, sizeof(tTurma), 1, turma);
    fclose(turma);
}