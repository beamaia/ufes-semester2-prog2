#ifndef _TRAPEZIO
    #define _TRAPEZIO
    #include <stdio.h>

    typedef struct 
    {
        float base1,
              base2,
              altura;
        char solo;
        unsigned int preco;
    } tTrapezio;
    
    void le_trapezio(tTrapezio *, FILE *);
    float area_trapezio(tTrapezio *);
    float preco_trapezio(tTrapezio *);
    int solo_argiloso_trapezio(tTrapezio *);

#endif