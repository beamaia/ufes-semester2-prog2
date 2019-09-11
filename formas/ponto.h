#ifndef _PONTO
    #define _PONTO

    typedef struct{
        int x, y;
    } tPonto;

    void leia_ponto(tPonto *);
    void apresenta_ponto(tPonto *);
    int distancia(tPonto *, tPonto *);
#endif