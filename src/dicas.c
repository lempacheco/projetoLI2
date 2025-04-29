#include "../include/dicas.h"

int dicas (Matriz* m, Queue* q){
    Matriz* m1;
    int count=0;
    copiaMatriz(m1,m);
    resolve(m1,q);
    for (int i=0;i<m->L;i++){
        for (int j=0;j<m->C;j++){
            if(!islower(m->matriz[i][j]) && m->matriz[i][j]!= m1->matriz[i][j]) count++;
        }
    }
    liberaMatriz(m1);
    return count;
}