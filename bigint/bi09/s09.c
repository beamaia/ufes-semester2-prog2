#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>


#define MAX_EXP 100
typedef struct{
    int *num;
    int tam;
    int max;
} tIntGrande;


tIntGrande* Aumenta(tIntGrande *inte){
    inte->max += MAX_EXP;

    tIntGrande *aux = (tIntGrande *) malloc (sizeof(tIntGrande));

    aux->num = (int *) malloc (sizeof(int) * inte->max);

    int i;

    aux->max = inte->max;

    aux->tam = inte->tam;


    for(i = 0; i < inte->tam; i++){
        aux->num[i] = inte->num[i];
    }

    free(inte->num);

    free(inte);

    return aux;
}


tIntGrande* Inverte(tIntGrande *inte){
    tIntGrande *aux = (tIntGrande *) malloc (sizeof(tIntGrande));

    aux->max = inte->max;
    aux->tam = inte->tam;

    aux->num = (int *) malloc(sizeof(int) * aux->max);

    int i, j;


    for(i = 0, j = aux->tam - 1; i < inte->tam && j >= 0; i++, j--){
        aux->num[j] = inte->num[i];
    }

    free(inte->num);
    free(inte);

    return aux;
}


void Soma(tIntGrande *int1, tIntGrande *int2){
    int i, j;


    for(i = 0, j = 0; i < int1->tam && j < int2->tam; i++, j++){
        int1->num[i] += int2->num[j];
        if(int1->num[i] >= 10 && i < int1->tam - 1){
            int1->num[i] -= 10;
            int1->num[i+1] += 1;
        }
        if(i == int1->tam - 1 && int1->num[i] >= 10){
            int1->num[i] -= 10;
            int1->tam++;
            int1->num[i+1] = 1;
        }
    }

    for(i = 0; i < int1->tam; i++){
        if(int1->num[i] >= 10 && i < int1->tam - 1){
            int1->num[i] -= 10;
            int1->num[i+1] += 1;
        }
        if(i == int1->tam - 1 && int1->num[i] >= 10){
            int1->num[i] -= 10;
            int1->tam++;
            int1->num[i+1] += 1;
        }
    }
}


tIntGrande* Mult_Soma(tIntGrande *inte, int x){
    int i, z;

    tIntGrande *aux = (tIntGrande *) malloc (sizeof(tIntGrande));

    aux->max = inte->max;
    aux->tam = inte->tam;

    aux->num = (int *) malloc(sizeof(int) * aux->max);


    for(i = 0; i < inte->tam; i++){
        aux->num[i] = inte->num[i];
    }

    for(z = 1; z < x; z++){
        if((aux->max - 1) == aux->tam)
            aux = Aumenta(aux);
        Soma(aux, inte);
    }


    return aux;
}


tIntGrande* Inicializa(){
    tIntGrande *inte;

    inte = (tIntGrande *) malloc (sizeof(tIntGrande));

    inte->tam = 0;
    inte->max = MAX_EXP;

    inte->num = (int *) malloc (sizeof(int) * MAX_EXP);

    for(int i = 0; i < inte->max; i++){
        inte->num[i] = 0;
    }

    return inte;
}


int main(){
    tIntGrande *val = Inicializa();

    unsigned int x;

    scanf("%d", &x);
    clock_t start = clock();
    if(x == 1 || x == 0){
        printf("1");
        return 0;
    }

    int i;

    val->num[0] = x * (x - 1);


    val->tam = 1;


    for(i = 0; i < val->tam; i++){
        if((val->max - 1) == val->tam)
            val = Aumenta(val);
        while(val->num[i] >= 10 && i < val->tam - 1){
            val->num[i] -= 10;
            val->num[i+1] += 1;    
        }
        while(i == val->tam - 1 && val->num[i] >= 10){
            val->num[i] -= 10;
            val->tam++;
            val->num[i+1] = 1;  
            while(val->num[i] >= 10 && i < val->tam - 1){
                val->num[i] -= 10;
                val->num[i+1] += 1;    
            }
        }
    }


    for(i = x - 2; i > 1; i--){
        if((val->max - 1) == val->tam)
            val = Aumenta(val);
        val = Mult_Soma(val, i);
    }

    for(i = val->tam - 1; i >= 0; i--){
        printf("%d", val->num[i]);
    }
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}