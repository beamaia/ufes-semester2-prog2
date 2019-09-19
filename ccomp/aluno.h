#ifndef _ALUNO
    #define _ALUNO
    #define MAX_NOME 50
    #include "data.h"
    #include <stdio.h>
    typedef struct{
        int matricula;
        char nome[MAX_NOME];
        float cr;
        tData niver;
        tData ingresso;
        int situacao;
    } tAluno;

    void leia_aluno(tAluno *);
    void imprime_informacoes(tAluno *, FILE *);
    int compara_nomes(tAluno *, tAluno *);
    int compara_matriculas(tAluno *, tAluno *);
    int compara_cr(tAluno *, tAluno *);
    int aluno_aniversariante(tData, tData);
    int tem_aniversario(tAluno *, tData);
    int aluno_excelente(tAluno *);
    int nao_tem_aluno(tAluno *);
#endif