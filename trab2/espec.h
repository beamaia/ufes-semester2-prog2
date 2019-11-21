#ifndef _ESPEC
    #define _ESPEC
    #include <stdio.h>
    typedef struct espec * Espec;

    Espec inicializa_espec();
    void le_espec(Espec, FILE *);
    int espec_imovel_limite(float, float, Espec);
    unsigned int calcula_qtd_cara_espec(Espec, unsigned int);
    unsigned int espec_fora_limite(Espec, int, unsigned int);
    unsigned int espec_id_zerado(Espec, int);

    typedef struct identificadores * Identificadores;

    Identificadores inicializa_identificadores();
    void zera_id(Identificadores, int);
    void atribui_valor_id(Identificadores, unsigned int, int);
    void imprime_soma_id(Identificadores id);
#endif