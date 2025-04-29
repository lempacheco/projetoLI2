#include "../include/queueFunc.h"

void initQueue (Queue *dq){
    int tamanhoInicial = 10; 
    dq->inicio = 0;
    dq->cap = tamanhoInicial; 
    dq->tam = 0; 
    dq->valores = malloc(tamanhoInicial*sizeof(Pos)); 
}

int isEmptyQ (Queue* dq){
    if(dq->tam == 0) return 1; 
    else return 0; 
}

void enqueue(Queue *q, Pos p) {
    if (q->tam == q->cap) {
        int novaCap = q->cap * 2;
        Pos *novosValores = malloc(sizeof(Pos) * novaCap);

        for (int i = 0; i < q->tam; i++) {
            int idx = q->inicio + i;
            if (idx >= q->cap) idx -= q->cap;
            novosValores[i] = q->valores[idx];
        }

        free(q->valores);
        q->valores = novosValores;
        q->cap = novaCap;
        q->inicio = 0;
    }

    int fim = q->inicio + q->tam;
    if (fim >= q->cap) fim -= q->cap;

    q->valores[fim] = p;
    q->tam++;
}


int dequeue(Queue *q, Pos *x) {
    if (q->tam == 0) return 1; // Fila vazia

    *x = q->valores[q->inicio];

    q->inicio++;
    if (q->inicio == q->cap) q->inicio = 0;

    q->tam--;
    return 0;
}

void liberaQueue (Queue *q){
    free(q->valores); 
    q->cap=0; 
    q->inicio=0; 
    q->tam=0; 
    free(q); 
}