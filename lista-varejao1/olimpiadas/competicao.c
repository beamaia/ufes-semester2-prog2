#include <stdio.h>
#include <stdlib.h>
#include "pais.h"
#include "competicao.h"

    void inicializaCompeticao(tCompeticao* comp){
        comp->quantidadePaises = 0;
        comp->maxPaises = EXP_COMP;
        comp->pais = (tPais*) malloc (sizeof(tPais)*(comp->maxPaises));
	    if (!comp->pais) {
            printf ("Nao foi possivel alocar memoria!\n");
            exit(1);
	    }
    }

    void aumentaCompeticao(tCompeticao* comp){
        comp->maxPaises+=EXP_COMP;
        tPais* aux = (tPais*) malloc (sizeof(tPais)*(comp->maxPaises));
        if (!aux) {
            printf ("Nao foi possivel alocar memoria!\n");
            exit(1);
        }
        for (int i = 0; i < comp->quantidadePaises; i++){
            aux[i] = comp->pais[i];
        }
        free(comp->pais);
        comp->pais = aux;
    }

    void atualizaCompeticao(tCompeticao* comp, tPais* pais){
        for (int i = 0; i < comp->quantidadePaises; i++){
            if (comp->pais[i].codigo == pais->codigo){
                incrementaMedalhasPais(&comp->pais[i], pais->ouro, pais->prata, pais->bronze);
                return;
            }
        }
        if (comp->quantidadePaises == comp->maxPaises){
           aumentaCompeticao(comp); 
        }    
        comp->pais[comp->quantidadePaises++] = *pais;   
    }

    void apresentaCompeticao(tCompeticao* comp){
        for (int i = 0; i < comp->quantidadePaises; i++){
            apresentaPais(&comp->pais[i]);
        }
    }

    void ordenaCompeticao(tCompeticao* comp, int (*troca) (tPais*, tPais*)){
        tPais aux;
        for(int i=0; i < comp->quantidadePaises-1; i++){
            for(int j=0; j < comp->quantidadePaises-i-1; j++){
                if(troca(&comp->pais[j], &comp->pais[j+1])){
                    aux = comp->pais[j];
                    comp->pais[j] = comp->pais[j+1];
                    comp->pais[j+1] = aux;
                }
            }
        }
    }

    void liberaCompeticao(tCompeticao* comp){
        free(comp->pais);
    }

