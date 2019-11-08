#ifndef _ESPEC
    #define _ESPEC
    #include <stdio.h>
    typedef struct espec * Espec;

    void inicializa_espec(Espec);
    void le_espec(Espec, FILE *);

    typedef struct identificadores * Identificadores;

    void inicializa_identificadores(Identificadores);
#endif