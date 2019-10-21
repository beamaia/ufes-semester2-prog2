#ifndef _RESIDENCIA
    #define _RESIDENCIA
    #include <stdio.h>

    typedef struct{
        unsigned int num_quartos,
                     num_vagas; 
    } tResidencia;

    void le_residencia(tResidencia *, FILE *);
    int residencia_compara_quartos(tResidencia *, tResidencia *);
#endif