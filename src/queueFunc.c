#include "../include/queueFunc.h"

/* Inicializa corretamente a queue. */

void initQueue (Queue *dq){
    int tamanhoInicial = 10; 
    dq->inicio = 0;
    dq->cap = tamanhoInicial; 
    dq->tam = 0; 
    dq->valores = malloc(tamanhoInicial*sizeof(Pos)); 
}

/* Verifica se não há nenhum valor dentro da queue. */

int isEmptyQ (Queue* dq){
    if(dq->tam == 0) return 1; 
    else return 0; 
}

/* Coloca um valor no final da queue. */

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

/* Retira o valor no inicio da queue. */

int dequeue(Queue *q, Pos *x) {
    if (q->tam == 0) return 1; // Fila vazia

    *x = q->valores[q->inicio];

    q->inicio++;
    if (q->inicio == q->cap) q->inicio = 0;

    q->tam--;
    return 0;
}

/* Libera corretamente uma queue. */

void liberaQueue (Queue *q){
    free(q->valores); 
    q->cap=0; 
    q->inicio=0; 
    q->tam=0; 

}

/* Recebe uma queue e copia-a para uma queue nova,
   e retorna essa queue.
*/

Queue copiaQueue(Queue* q) {
    Queue nova;
    nova.cap = q->cap;
    nova.tam = q->tam;
    nova.inicio = q->inicio;

    if (q->valores != NULL && q->cap > 0) {
        nova.valores = malloc(sizeof(Pos) * q->cap);
        for (int i = 0; i < q->cap; i++) {
            nova.valores[i] = q->valores[i];
        }
    } else {
        nova.valores = NULL;
    }

    return nova;
}
