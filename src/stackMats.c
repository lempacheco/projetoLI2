#include "../include/stackMats.h"

void initStackMat(StackMat *s){
    s->tam = 1;
    s->dados = malloc(sizeof(Matriz) * s->tam);
    s->comandos = malloc(sizeof(char) * s->tam);
    initMatriz(&s->dados[0]);
    initMatriz(&s->mInicial);
    s->cabeca = -1;
    s->ajuda = 0; 
}

void initMatriz(Matriz* m){
    m->L = 0;
    m->C = 0;
    m->matriz = NULL;
}

int isFull(StackMat *s){
    return s->cabeca == s->tam - 1;
}

int isEmpty(StackMat *s){
    return s->cabeca == -1;  
}

void liberaMatriz(Matriz *m){
    for (int i = 0; i < m->L; i++) {
        free(m->matriz[i]);
    }
    free(m->matriz); 
    initMatriz(m);
}

void liberaStackMat(StackMat *s){
    for (int i = 0; i <= s->cabeca; i++) {
        liberaMatriz(&s->dados[i]);
    }
    free(s->dados);
    free(s->comandos);
    s->dados = NULL;
    s->cabeca = -1;
    s->tam = 0;
    liberaMatriz(&s->mInicial);
}

void push(StackMat *s, Matriz *m, char comando){
    if (s->cabeca + 1 >= s->tam) {
        s->tam++;
        s->dados = realloc(s->dados, sizeof(Matriz) * s->tam);
        s->comandos = realloc(s->comandos, sizeof(char) * s->tam);
    }

    s->cabeca++;

    s->comandos[s->cabeca] = comando;
    initMatriz(&s->dados[s->cabeca]);
    copiaMatriz(&s->dados[s->cabeca], m);
}

int pop(StackMat *s, Matriz* m){
    if (isEmpty(s)) {
        return -1;
    }

    copiaMatriz(m, &(s->dados[s->cabeca]));
    liberaMatriz(&(s->dados[s->cabeca])); 
    s->comandos[s->cabeca] = '\0';
    s->cabeca--;
    return 0;
}

void copiaMatriz(Matriz *dest, Matriz *src){

    if (dest->matriz != NULL) liberaMatriz(dest);
    if (src->matriz == NULL) {
        dest->L = 0;
        dest->C = 0;
        dest->matriz = NULL;
        return;
    }
    dest->L = src->L;
    dest->C = src->C;

    dest->matriz = malloc(sizeof(char*) * src->L);
    for (int i = 0; i < src->L; i++) {
        dest->matriz[i] = malloc(sizeof(char) * src->C);
        for (int j = 0; j < src->C; j++) {
            dest->matriz[i][j] = src->matriz[i][j];
        }
    }
}