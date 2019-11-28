#ifndef _GRADE
    #define _GRADE

    typedef struct grade * Grade;

    Grade initilize_grade();
    unsigned int read_grade();
    void update_grade(Grade, unsigned int);
    void free_grade(Grade);

#endif