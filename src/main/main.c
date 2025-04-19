
#include "../../include/comandos.h"
#include "../../include/condicoes.h"
#include "../../include/matrizRandom.h"
#include "../../include/output.h"
#include "../../include/leFicheiro.h"
#include "../../include/dataStructs.h"
#include "../../include/stackMats.h"

int main (){

    Matriz m;
    initMatriz(&m);
    StackMat s; 
    initStackMat(&s);
    StackG sg;
    initStackG(&sg);

    printf(">>> ");

    while (escolheComandos(&m, &s, &sg) != 1) { 
        if (!(verificar(&m))){
            pop(&s,&m); 
        };
        mostraMatriz(&m);
    }

    liberaMatriz(&m);
    liberaStackMat(&s);
    liberaStackG(&sg);

    return 0; 
    
}