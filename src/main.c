
#include "../include/comandos.h"
#include "../include/matrizRandom.h"
#include "../include/output.h"

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

