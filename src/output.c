#include "../include/output.h"

int mostraMatriz (Matriz *m) {
    int i, j; 

    printf("\n");
    
    for(i=0; i<m->L; i++){
        for (j=0; j<m->C; j++){
            printf("%c",m->matriz[i][j]); 
        }
        printf("\n"); 
    }
    printf("\n>>> ");

    return 0; 
}