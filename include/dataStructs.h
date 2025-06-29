#pragma once

typedef struct pos {
    int l; 
    int c; 
} Pos; 

typedef struct matriz {
    
    int L; 
    int C; 
    int** visitada; 
    char** matriz;

} Matriz;

typedef struct StackMat{
    Matriz *dados; 
    char *comandos;
    int cabeca;
    int tam;
    Matriz mInicial; // estado inicial da matriz
    int ajuda;  // flag se o modo de ajuda automática está ativado
} StackMat;

// lista interna: posições
typedef struct NodePosicao {
    Pos p;
    struct NodePosicao* prox;
} NodePosicao;

// lista externa: lista de posições
typedef struct NodeGrupo {
    int m;                     // mensagem 
    NodePosicao* cabeca;       // cabeça da sublista
    struct NodeGrupo* prox;      // próximo grupo
} NodeGrupo;

typedef struct queue { 
    int cap; 
    int tam; 
    int inicio;  
    Pos *valores; 
} Queue; 