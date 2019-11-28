#ifndef _AUX
    #define _AUX

    typedef struct{
        unsigned int grade, student_id, 
                     classes, course;
    } aux;

    typedef aux * Aux;

    Aux initialize_aux();
    void read_aux(Aux);
    void free_aux(Aux);

    Aux initialize_aux()
    {
        Aux a;
        a = (Aux) malloc(sizeof(aux));
        a->grade = 0;
        a->student_id = 0;
        a->classes = 0;
        a->course = 0;
        return a;
    }

    void read_aux(Aux a)
    {
        scanf("%u%u%u%u")
    }
#endif