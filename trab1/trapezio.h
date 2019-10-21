#ifndef _TRAPEZIO
    #define _TRAPEZIO
    #include <stdio.h>
    #include "terreno.h"

    typedef struct 
    {
        tTerreno ter;
        float base1,
              base2,
              altura;
    } tTrapezio;
    
    void le_trapezio(tTrapezio *, FILE *);
    float area_trapezio(tTrapezio *);
    float preco_trapezio(tTrapezio *);
#endif