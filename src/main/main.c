
#include "../../include/comandos.h"
#include "../../include/matrizRandom.h"
#include "../../include/output.h"
#include "../../include/leFicheiro.h"


int main (){

    Matriz m;

    while (escolheComandos(&m) != 1) {
        mostraMatriz(&m);
    }

    for (int i=0; i<m.L; i++){
        free(m.matriz[i]);
    }
    free(m.matriz);

    return 0; 
    
}

