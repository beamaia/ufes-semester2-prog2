 /*
Biblioteca com tipos e funcoes relacionadas as formas triangulo, 
retangulo e trapezio.
*/

#ifndef _FORMAS
    #define _FORMAS
    #include <stdio.h>

    typedef struct
    {
        float base;
        float altura;
    } tTriangulo;

    void le_triangulo(tTriangulo *, FILE *);
    float area_triangulo(tTriangulo *);
    
    typedef struct 
    {
        float lado1;
        float lado2;
    }tRetangulo;

    void le_retangulo(tRetangulo *, FILE *);
    float area_retangulo(tRetangulo *);

    typedef struct 
    {
        float base1;
        float base2;
        float altura;
    }tTrapezio;
    
    void le_trapezio(tTrapezio *, FILE *);
    float area_trapezio(tTrapezio *);

    typedef union 
    {
       tTriangulo triangulo;
       tRetangulo retangulo;
       tTrapezio trapezio;
    } tForma;
    
    void le_forma_triangulo(tForma *, FILE *);
    int area_forma_triangulo(tForma *);
    void le_forma_retangulo(tForma *, FILE *);
    int area_forma_retangulo(tForma *);
    void le_forma_trapezio(tForma *, FILE *);
    int area_forma_trapezio(tForma *);
    

#endif