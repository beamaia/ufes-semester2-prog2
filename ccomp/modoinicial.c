#include <stdio.h>
#include "data.h"
#include "aluno.h"
#include "turma.h"
#include "modoinicial.h"

void mensagem_escolha_organizacao()
{
    printf("Escolha um modo de organização:\n");
    printf("(1) Nome (2) Matricula (3) CR\n");
}

void escolha_organizacao(tTurma * ccomp)
{
    mensagem_escolha_organizacao();

    int escolha;
    scanf("%d", &escolha);

    switch(escolha)
    {
        case 1: 
            ordena(ccomp, compara_nomes);
            break;
        case 2: 
            ordena(ccomp, compara_matriculas);
            break;
        case 3: 
            ordena(ccomp, compara_cr);
            break;
        default:
            break;
    }
}

void mensagem_escolha_apresentacao()
{
    printf("Escolha o que você quer visualizar:\n");
    printf("(1) Turma (2) Alunos Aniversariantes (3) Alunos Excelentes\n");
}

void escolha_apresentacao(tTurma * ccomp, tData hoje)
{
    mensagem_escolha_apresentacao();

    int escolha;
    scanf("%d", &escolha);

    switch(escolha)
    {
        case 1: 
            apresenta_turma(ccomp);
            break;
        case 2: 
            apresenta_aniversariantes(ccomp, hoje);
            break;
        case 3: 
            apresenta_excelentes(ccomp);
            break;
        default:
            break;
    }
}

void escolha(tTurma *ccomp, tData hoje)
{
    escolha_organizacao(ccomp);
    escolha_apresentacao(ccomp, hoje);
}

