#include "data.h"
#include "aluno.h"
#include "turma.h"
#include "modoinicial.h"
#include <stdio.h>

void main()
{
    tData hoje;
    pergunta_data();
    leia_data(&hoje);
    tTurma ccomp;
    leia_turma(&ccomp);
    escolha(&ccomp, hoje);
}
