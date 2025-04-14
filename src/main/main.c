
#include "../../include/stackMat.h"
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
    init(&s); 

    s.dados = malloc(sizeof(char)); 

    printf(">>> ");

    while (escolheComandos(&m, &s) != 1) {
        mostraMatriz(&m);
    }

    for (int i=0; i<m.L; i++){
        free(m.matriz[i]);
    }
    free(m.matriz);
    free(s.dados); 

    return 0; 
    
}

