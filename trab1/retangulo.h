#ifndef _RETANGULO
    #define _RETANGULO

    typedef struct 
    {
        float lado1;
        float lado2;
        float area;
        tTerreno terreno;
    }tRetangulo;

    void le_retangulo(tRetangulo *, FILE *);
    void area_retangulo(tRetangulo *);
    float preco_retangulo(tRetangulo *);