#ifndef _IMOVEL
    #define _IMOVEL
    #include <stdio.h>
    #include "triangulo.h"
    #include "retangulo.h"
    #include "trapezio.h"
    #include "casa.h"
    #include "apartamento.h"
    #include "categoria.h"
    #include "espec.h"
    #define MAX_NOME 40

    typedef struct 
    {
        char tipo_imovel[7],
             nome_proprietario[MAX_NOME];
        unsigned int id;
        tCategoria categoria;
        float preco,
              area;
    } tImovel;

    int identifica_categoria(tImovel *);
    void le_imovel(tImovel *, FILE *);
    void modifica_imovel(tImovel *, tImovel *);
    void preco_imovel(tImovel *);
    void area_imovel(tImovel *);
    int imovel_limite_area_preco(tImovel *, tEspec *);
    int compara_id(tImovel *, tImovel *);
    void acrescenta_id(tImovel *, int);
    int compara_quartos(tImovel *, tImovel *);
    int compara_preco(tImovel *, tImovel *);
    int compara_area(tImovel *, tImovel *);
    int identifica_id(tImovel *);
    int imovel_identifica_argiloso(tImovel *);
    void imovel_apresenta_identificador(tImovel *, FILE *);

#endif