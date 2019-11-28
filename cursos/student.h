#ifndef _STUDENT
    #define _STUDENT

    typedef struct student * Student;

    Student initialize_student();
    int is_this_the_student(Student, unsigned int);
    void update_student(Student, unsigned int);
    
#endif