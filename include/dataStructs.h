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
    Matriz mInicial;
    int ajuda; 
} StackMat;

// Lista interna: posições
typedef struct NodePosicao {
    Pos p;
    struct NodePosicao* prox;
} NodePosicao;

// Lista externa: lista de posições
typedef struct NodeGrupo {
    int m; 
    NodePosicao* cabeca;       // Cabeça da sublista
    struct NodeGrupo* prox;      // Próximo grupo
} NodeGrupo;

typedef struct queue { 
    int cap; 
    int tam; 
    int inicio;  
    Pos *valores; 
} Queue; 