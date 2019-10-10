#include <stdio.h>
#include "pais.h"

    void inicializaPais (tPais* p, int cod){
        p->codigo = cod;
        p->ouro = p->prata = p->bronze = 0;
    }

    void incrementaMedalhaPais (tPais* p, int tipo){
	 switch (tipo) {
	     case 0: p->ouro++;
	     break;
 	     case 1: p->prata++;
	     break;            
  	     case 2:  p->bronze++;
	 }
    }

    void incrementaMedalhasPais (tPais* p, int o, int pr, int b){
        p->ouro+=o;
        p->prata+=pr;
        p->bronze+=b;
    }

    int compMedalhas(tPais* p, tPais* s){
        if (p->ouro > s->ouro){
            return 0;
        }
        if (p->ouro == s->ouro && p->prata > s->prata){
            return 0;
        }
        if (p->ouro == s->ouro && p->prata == s->prata  && p->bronze > s->bronze){
            return 0;
        }
        if (p->ouro == s->ouro && p->prata == s->prata  && p->bronze == s->bronze){
            return p->codigo > s->codigo;
        }
        return 1;
    }
    
    void apresentaPais(tPais* p){
        printf ("%d %d %d %d\n", p->codigo, p->ouro, p->prata, p->bronze);
    }




