#ifndef _TURMA
    #define _TURMA
    #define MAX_ALUNOS 100
    #include "data.h"
    #include "aluno.h"
    
    typedef struct{
    tAluno aluno[MAX_ALUNOS];
    int qtd_alunos;
    } tTurma;

    void leia_turma(tTurma *);
    void ordena(tTurma * ccomp, int (*compar)(tAluno *, tAluno *));
    void troca_alunos(tTurma*, int);
    void apresenta_turma(tTurma *);
    void apresenta_aniversariantes(tTurma *, tData hoje);
    void apresenta_excelentes(tTurma *);
    void apresenta_binario(tTurma);


#endif