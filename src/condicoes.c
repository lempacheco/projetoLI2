#include <stdlib.h>
#include "../include/condicoes.h"

// 0 falso 1  vdd

// verifica se a casa ortogonal a um ariscada esta riscda tbm
int verifRiscadaOrt (Matriz *m, int J, int I){
 
    if (J<m->L-1 && m->matriz[J+1][I] == '#') return 0;
    if (J>0 && m->matriz[J-1][I] == '#') return 0;
    if (I<m->C-1 && m->matriz[J][I+1] == '#') return 0; 
    if (I>0 && m->matriz[J][I-1] == '#') return 0; 

    return 1; 
}


int verifBranco (Matriz *m, int J, int I){
    int r=1;    
    for (int j=0; j<m->L; j++){
        if (j!=J && m->matriz[j][I] == m->matriz[J][I]) r=0; 
    }
    for (int i=0; i<m->C; i++){
        if (i!=I && m->matriz[J][i] == m->matriz[J][I]) r=0; 
    }
    return r; 
}

int verificar (Matriz *m){
    int r=1; 

    for (int j=0; r==1 && j<m->L; j++){
        for (int i=0; r==1 && i<m->C; i++){
            if (isupper(m->matriz[j][i])){
                r=verifBranco(m, j, i); 
            }
            if (m->matriz[j][i] == '#') {
               r= verifRiscadaOrt(m, j, i); 
            }
        
        }
    }
    if (r==0) {
        printf("Execução errada");
    }
    return r; 
}