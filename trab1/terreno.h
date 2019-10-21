#ifndef _TERRENO
    #define _TERRENO
    #include <stdio.h>
    
    typedef struct 
    {
        char solo;
        unsigned int preco;
    } tTerreno;
    
    void le_terreno(tTerreno *, FILE *);
    float fator_preco_terreno(tTerreno *);
#endif