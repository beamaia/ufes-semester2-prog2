#ifndef _TERRENO
    #define _TERRENO
    #include <stdio.h>

    typedef struct 
    {
        char solo;
        float preco_m2;
    } tTerreno;
    
    void le_terreno(tTerreno *, FILE *);
    float mult_preco_e_solo_terreno(tTerreno *);
#endif