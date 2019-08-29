#include "data.h"
#include "aluno.h"
#include "turma.h"

int main()
{
    tData hoje;
    hoje = leia_data();

    tTurma ccomp;

    ccomp = leia_turma();
    ccomp = ordena_nome(ccomp);
    
    apresenta_turma(ccomp);

    apresenta_aniversariantes(ccomp, hoje);

    apresenta_excelentes(ccomp);

    return 0;
}