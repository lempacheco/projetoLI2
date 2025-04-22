
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

    int resultado = 0; 

    printf(">>> ");

    while (resultado != 1) { 
        resultado = escolheComandos(&m, &s, &sg); 
    
        if (resultado == -1) {
            pop(&s, &m);
        }
    
        if (resultado == 0 || resultado == -1) {
            mostraMatriz(&m); 
        }
    }
    

    liberaMatriz(&m);
    liberaStackMat(&s);
    liberaStackG(&sg);

    return 0; 
    
}