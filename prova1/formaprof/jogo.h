#ifndef _JOGO
    #define _JOGO

    typedef struct{
        char nome1[30];
        int gols1;
        char nome2[30];
        int gols2;
    } tJogo;

    void lerJogos(tJogo *);
#endif