#include "../include/stackMats.h"

/* int push(Stack *s, char c) {
    if (s->cabeca < s->tam) {
        s->dados[s->cabeca++] = c;
        return 0;
    }

    int novoTam = s->tam + 1;
    char *novoDados = realloc(s->dados, sizeof(char) * novoTam);

    if (novoDados == NULL) {
        return -1; // erro de alocação
    }

    s->dados = novoDados;
    s->tam = novoTam;

    s->dados[s->cabeca++] = c;

    return 0;
} */

void initStackMat(StackMat *s){
    s->tam = 1;
    s->dados = malloc(sizeof(Matriz) * s->tam);
    initMatriz(&s->dados[0]);
    s->cabeca = -1;
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
    m->matriz = NULL;
    m->L = 0;
    m->C = 0;
}

void liberaStackMat(StackMat *s){
    for (int i = 0; i <= s->cabeca; i++) {
        liberaMatriz(&s->dados[i]);
    }
    free(s->dados);
    s->dados = NULL;
    s->cabeca = -1;
    s->tam = 0;
}

void push(StackMat *s, Matriz *m){
    if (s->cabeca + 1 >= s->tam) {
        s->tam++;
        s->dados = realloc(s->dados, sizeof(Matriz) * s->tam);
    }

    s->cabeca++;

    // Aloca espaço para a matriz interna e copia os dados
    s->dados[s->cabeca].matriz = NULL;
    copiaMatriz(&s->dados[s->cabeca], m);
}

int pop(StackMat *s, Matriz* m){
    if (isEmpty(s)) {
        printf("Não há mais comandos para retroceder.");
        return -1;
    }

    copiaMatriz(m, &(s->dados[s->cabeca]));
    liberaMatriz(&(s->dados[s->cabeca])); 
    s->cabeca--;
    return 0;
}

void copiaMatriz(Matriz *dest, Matriz *src){

    if (dest->matriz != NULL) liberaMatriz(dest);

    dest->L = src->L;
    dest->C = src->C;

    dest->matriz = malloc(sizeof(char*) * src->L);
    for (int i = 0; i < src->L; i++) {
        dest->matriz[i] = malloc(sizeof(char) * src->C);
        for (int j = 0; j < src->C; j++) {
            dest->matriz[i][j] = src->matriz[i][j];
        }
    }
    if (src->matriz == NULL) {
        if (dest->matriz != NULL) liberaMatriz(dest);

        dest->L = 0;
        dest->C = 0;
        dest->matriz = NULL;
        return;
    }
}