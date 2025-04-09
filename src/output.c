#include "../include/output.h"

/* Percorre a matriz fornecida e imprime os seus elementos no terminal. 
*/

int mostraMatriz (Matriz *m) {
    int i, j; 

    for(i=0; i<m->L; i++){
        for (j=0; j<m->C; j++){
            printf("%c",m->matriz[i][j]); 
        }
        printf("\n"); 
    }
    printf("\n");

    return 0; 
}