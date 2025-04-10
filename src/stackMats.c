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

void init(StackMat *s){
    s->cabeca = -1;
    s->tam = 0;
}

int isFull(StackMat *s){
    return s->cabeca == s->tam - 1;
}

int isEmpty(StackMat *s){
    return s->cabeca == -1;  
}

void push(StackMat *s, Matriz *m){
    if (isEmpty(s)){
        s->dados = malloc(sizeof(Matriz));
    }

    if (isFull(s)){
        s->dados = realloc(s->dados, sizeof(char)*(++s->tam));
    }

    copiaMatriz(m ,&(s->dados[++s->cabeca]));
}

int pop(StackMat *s, Matriz* r){
    if (isEmpty(s)) {
        printf("Não há mais comandos para retroceder.");
        return -1;
    }

    copiaMatriz(r, &(s->dados[s->cabeca--]));
    s->tam--; 

    return 0; 
 
}

//TODO: verify if dest has enough space for src
void copiaMatriz(Matriz* dest, Matriz* src){
    for (int i=0; i<src->L; i++){
        for (int j=0; j<src->C; j++){
            dest->matriz[i][j] = src->matriz[i][j];
        }
    }
}