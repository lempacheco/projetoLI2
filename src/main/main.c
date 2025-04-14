
#include "../../include/comandos.h"
#include "../../include/matrizRandom.h"
#include "../../include/output.h"
#include "../../include/leFicheiro.h"
#include "../../include/dataStructs.h"
#include "../../include/stackMats.h"

int main (){

    Matriz m;
    m.L = 0;
    m.C = 0;
    StackMat s; 
    initStackMat(&s); 

    printf(">>> ");

    while (escolheComandos(&m, &s) != 1) {
        mostraMatriz(&m);
    }

    liberaMatriz(&m);
    liberaStackMat(&s); 

    return 0; 
    
}

