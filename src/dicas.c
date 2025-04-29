#include "../include/dicas.h"

int dicas (Matriz* m){
    Matriz* m1;
    int count=0;
    copiaMatiz(&m1,&m);
    resolveTabuleiro(&m1);
    for (int i=0;i<m->L;i++){
        for (int j=0;j<m->C;j++){
            if(m->matriz[i][j]!=islower && m->matriz[i][j]!= m1->matriz[i][j]) count++;
        }
    }
    liberaMatriz(&m1);
    return count;
}