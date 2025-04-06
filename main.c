
#include "etapa1.h"
#include "matrizRandom.h"

int main (){

    Matriz m;

    leTamanhoMatriz(&m); 
    matrizRandom(&m); 
    mostraMatriz(&m); 

    while (escolheComandos(&m) != 1) {
        mostraMatriz(&m);
    }

    return 0; 
    
}

