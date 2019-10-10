#include <stdio.h>
#include "pais.h"
#include "competicao.h"


int main() { 
    int tipo = 0;
    int codigo;
    tPais p;
    tCompeticao cp;
    inicializaCompeticao(&cp);
    scanf ("%d", &codigo);
    while (codigo) {
         inicializaPais(&p, codigo);    
         incrementaMedalhaPais (&p, tipo++%3);
         atualizaCompeticao(&cp, &p);  
         scanf ("%d", &codigo);
    }
    ordenaCompeticao(&cp, compMedalhas);
    apresentaCompeticao(&cp);
    liberaCompeticao(&cp);	
    return 0;
}
