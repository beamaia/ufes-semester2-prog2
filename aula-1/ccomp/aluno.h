#ifndef _ALUNO
    #define _ALUNO
    #define MAX_NOME 50
    #include "data.h"

    typedef struct{
        int matricula;
        char nome[MAX_NOME];
        float cr;
        tData niver;
        tData ingresso;
        int situacao;
    } tAluno;

    tAluno leia_aluno();
    void imprime_informacoes(tAluno);
    int compara_nomes(tAluno, tAluno);
    int compara_matriculas(int, int);
    int compara_cr(int, int);
    int aluno_aniversariante(tData, tData);
    int tem_aniversario(tAluno, tData);
    int aluno_excelente(tAluno);
    int nao_tem_aluno(tAluno);
#endif