#ifndef _CASA
    #define _CASA
    #include <stdio.h>
    #include "residencia.h"

    typedef struct
    {
        tResidencia res;
        float area_pav,
              area_livre;
        unsigned int num_pav,
                     preco_pav,
                     preco_livre;
    } tCasa;

    void le_casa(tCasa *, FILE *);
    float preco_casa(tCasa *);
    float area_cons_casa(tCasa *);
    int casa_compara_quartos(tCasa *, tCasa *);
#endif
    