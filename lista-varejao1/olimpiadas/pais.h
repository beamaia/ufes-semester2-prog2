#ifndef _PAIS
    #define _PAIS
    #define MAX_NOME 30

    typedef struct {
        int codigo;
        int ouro;
        int prata;
        int bronze;
    } tPais;

    void inicializaPais (tPais* p, int cod);
    void incrementaMedalhaPais (tPais* p, int tipo);
    void incrementaMedalhasPais (tPais* p, int o, int pr, int b);
    int compMedalhas(tPais* p, tPais* s);
    void apresentaPais(tPais* p);

#endif