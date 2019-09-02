#include <stdio.h>
#include "turma.h"
#include "aluno.h"
#include "data.h"

tTurma leia_turma()
{
    tTurma ccomp;
    int i;

    for(i = 0; i < MAX_ALUNOS; i++)
    {

        ccomp.aluno[i] = leia_aluno();

        if(nao_tem_aluno(ccomp.aluno[i]))
            break;
    }

    ccomp.qtd_alunos = i;
    return ccomp;

}

tTurma troca_alunos(tTurma ccomp, int j)
{
    tAluno temp;
    temp = ccomp.aluno[j];
    ccomp.aluno[j] = ccomp.aluno[j + 1];
    ccomp.aluno[j + 1] = temp;
    return ccomp;
}

tTurma ordena_nome(tTurma ccomp)
{
    for(int i = 0; i < ccomp.qtd_alunos - 1; i++)
        for(int j = 0; j < ccomp.qtd_alunos - 1 - i; j++)
            if(compara_nomes(ccomp.aluno[j], ccomp.aluno[j + 1]))
                ccomp = troca_alunos(ccomp, j);
    
    return ccomp;
}

void apresenta_turma(tTurma ccomp)
{
    printf("\n");
    for(int i = 0; i < ccomp.qtd_alunos; i++)
    {
        imprime_informacoes(ccomp.aluno[i]);
    }
}

void apresenta_aniversariantes(tTurma ccomp, tData hoje)
{
    printf("\nAniversariantes: \n\n");

    for(int i = 0; i < ccomp.qtd_alunos; i++)
    {
        if(tem_aniversario(ccomp.aluno[i], hoje))
            imprime_informacoes(ccomp.aluno[i]);
    }
}

void apresenta_excelentes(tTurma ccomp)
{   
    printf("\nExcelentes: \n\n");

    for(int i = 0; i < ccomp.qtd_alunos; i++)
    {
        if(aluno_excelente(ccomp.aluno[i]))
            imprime_informacoes(ccomp.aluno[i]);
    }
}