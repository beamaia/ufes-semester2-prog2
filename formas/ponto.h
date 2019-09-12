#ifndef _PONTO
    #define _PONTO

    typedef struct{
        int x, y;
    } tPonto;

    void leia_ponto(tPonto *);
    void apresenta_ponto(tPonto *);
    float distancia(tPonto *, tPonto *);
#endif