#include <stdio.h>

struct grade{
    unsigned int sum, counter, grade;
}

Grade initilize_grade()
{
    Grade g;
    g = (Grade) malloc (sizeof(struct grade));
    g.sum = 0;
    g.counter = 0;
    g.grade = 0;
    return g;
}

unsigned int read_grade()
{
    unsigned int aux;
    scanf("%u", %aux);
    return aux;
}

void update_grade(Grade g, unsigned int grade)
{
    g->sum += grade;
    g->counter++;
    c->grade = c->sum/c->counter;
}

void free_grade(Grade g)
{
    free(g);
}