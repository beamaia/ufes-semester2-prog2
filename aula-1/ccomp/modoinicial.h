#ifndef _ESCOLHA
    #define _ESCOLHA
    #include <stdio.h>
    #include "data.h"
    #include "aluno.h"
    #include "turma.h"
    #include "modoinicial.h"

    void mensagem_escolha_organizacao();
    void escolha_organizacao(tTurma *);
    void mensagem_escolha_apresentacao();
    void escolha_apresentacao(tTurma *, tData);
    void escolha(tTurma *, tData);
#endif