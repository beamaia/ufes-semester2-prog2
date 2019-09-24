#include <stdio.h>

struct aluno{
    char nome[81], matricula[8], turma;
    float p1, p2, p3;
};

typedef struct aluno Aluno;
void imprime_aprovados(int n, Aluno* turma);

void imprime_aprovados(int n, Aluno* turma)
{
    int i;
    float mf;
    for(i = 0; i < n; i++)
    {
        mf = (turma[i].p1 + turma[i].p2 + turma[i].p3)/3;
        if(mf > 7)
        {
            printf("Mat: %s, Nome: %s, Turma: %c, MF: %.2f\n", turma[i].matricula,
                                                             turma[i].nome,
                                                             turma[i].turma,
                                                             mf);
        }
    }
}