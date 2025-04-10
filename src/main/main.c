
#include "../../include/comandos.h"
#include "../../include/matrizRandom.h"
#include "../../include/output.h"
#include "../../include/leFicheiro.h"


int main (){

    Matriz m;
    Stack s; 

    s.dados = malloc(sizeof(char)); 

    printf(">>> ");

    while (escolheComandos(&m) != 1) {
        mostraMatriz(&m);
    }

    for (int i=0; i<m.L; i++){
        free(m.matriz[i]);
    }
    free(m.matriz);
    free(s.dados); 

    return 0; 
    
}

