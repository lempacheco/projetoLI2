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
    if ((q)->tam == (q)->cap) {
        // Dobra a capacidade
        int novaCap = (q)->cap * 2;
        Pos *novosValores = malloc(sizeof(Pos) * novaCap);

        // Copia os elementos da fila circular antiga para nova
        for (int i = 0; i < (q)->tam; i++) {
            novosValores[i] = (q)->valores[((q)->inicio + i) % (q)->cap];
        }

        free((q)->valores);
        (q)->valores = novosValores;
        (q)->cap = novaCap;
        (q)->inicio = 0;
    }

    int fim = ((q)->inicio + (q)->tam) % (q)->cap;
    (q)->valores[fim] = p;
    (q)->tam++;
}

int dequeue(Queue *q, Pos *x) {
    if ((q)->tam == 0) return 1; // Fila vazia

    *x = (q)->valores[(q)->inicio];
    (q)->inicio = ((q)->inicio + 1) % (q)->cap;
    (q)->tam--;
    return 0;
}


void liberaQueue (Queue *q){
    free(q->valores); 
    q->cap=0; 
    q->inicio=0; 
    q->tam=0; 
}