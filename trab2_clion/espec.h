#ifndef _ESPEC
    #define _ESPEC
    #include <stdio.h>
    typedef struct espec * Espec;

    Espec inicializa_espec();
    void le_espec(Espec, FILE *);
    int espec_imovel_limite(float, float, Espec);
    unsigned int calcula_qtd_cara_espec(Espec, unsigned int);
    unsigned int calcula_qtd_argilosos_espec(Espec, unsigned int);
    int espec_id_limite(Espec esp, int escolha, unsigned int limite);
    int espec_id_zerado(Espec, int);
    int get_espec_letra(Espec esp, int escolha);
    void libera_espec(Espec esp);

    typedef struct identificadores * Identificadores;

    Identificadores inicializa_identificadores();
    void zera_id(Identificadores, int);
    void atribui_valor_id(Identificadores, unsigned int, int);
    void imprime_soma_id(Identificadores id);
    void libera_id(Identificadores id);

#endif