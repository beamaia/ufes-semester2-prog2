#ifndef _PAIS
    #define _PAIS

    typedef struct{
        int codigo;
        int ouro;
        int prata;
        int bronze;
    } tPais;

    void inicializa_pais(tPais *, int);
    void apresenta_pais(tPais *);
    int compara_paises(tPais *, tPais *);
    int codigo_igual(tPais *, tPais *);
    void adiciona_medalha(tPais *, int);
    void adiciona_medalhas(tPais *, int, int, int);

#endif