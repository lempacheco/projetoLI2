#include "../include/dicas.h"


int dicas (Matriz* m, Matriz* mInicial,  Queue* q){
    Matriz m1;
    initMatriz(&m1);

    Queue q1; 
    q1 = copiaQueue(q);
    int count=0;
    copiaMatriz(&m1,m);
    resolve(&m1, mInicial, &q1);
    limpaMensagens(); 
    for (int i=0;i<m->L;i++){
        for (int j=0;j<m->C;j++){
            if(!islower(m->matriz[i][j]) && m->matriz[i][j]!= m1.matriz[i][j]) count++;
        }
    }
    liberaMatriz(&m1); 
    liberaQueue(&q1);
    return count; 
} 