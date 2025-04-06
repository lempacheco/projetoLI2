
#include "etapa1.h"

int main (){

    Matriz m;
    matriz1.L = 5;
    matriz1.C = 5;

    leTamanhoMatriz(&m); 
    matrizRandom(&m); 
    mostraMatriz(&m); 

    while (escolheComandos(&m) != 1) {
        mostraMatriz(&m);
    }

    return 0; 
    
}

