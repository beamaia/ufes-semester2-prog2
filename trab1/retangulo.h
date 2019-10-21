#ifndef _RETANGULO
    #define _RETANGULO
    #include <stdio.h>
    #include "terreno.h"

    typedef struct 
    {
        tTerreno ter;
        float lado1,
              lado2;
    } tRetangulo;
    
    void le_retangulo(tRetangulo *, FILE *);
    float area_retagulo(tRetangulo *);
    float preco_retangulo(tRetangulo *);
#endif