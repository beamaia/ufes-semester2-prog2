#include "data.h"
#include "aluno.h"
#include "turma.h"
#include <stdio.h>

int main()
{
    tData hoje;
    pergunta_data();
    hoje = leia_data();

    tTurma ccomp;

    ccomp = leia_turma();
    printf("%d\n", ccomp.qtd_alunos);
    ccomp = ordena_nome(ccomp);
    printf("%d\n", ccomp.qtd_alunos);
   
    apresenta_turma(ccomp);
    apresenta_aniversariantes(ccomp, hoje);
    apresenta_excelentes(ccomp);

    return 0;
}