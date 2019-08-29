#ifndef _TURMA
    #define _TURMA
    #define MAX_ALUNOS 100
    #include "data.h"
    #include "aluno.h"
    
    typedef struct{
    tAluno aluno[MAX_ALUNOS];
    int qtd_alunos;
    } tTurma;

    tTurma leia_turma();
    tTurma troca_alunos(tTurma, int);
    tTurma ordena_nome(tTurma);
    void apresenta_turma(tTurma);
    void apresenta_aniversariantes(tTurma, tData hoje);
    void apresenta_excelentes(tTurma);

#endif