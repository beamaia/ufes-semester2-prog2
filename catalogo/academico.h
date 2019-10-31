#ifndef _ACADEMICO
    #define _ACADEMICO
    #define MAX_NOM 30

    typedef struct Academico* Academico;

    Academico le_nome();
    Academico le_academico();
    int comp_nome(Academico, Academico);
    int comp_matricula(Academico, Academico);
    int comp_idade(Academico, Academico);
    void apresenta_academico(Academico);
    void libera_nome(Academico);
    void libera_academico(Academico);
   
#endif   
