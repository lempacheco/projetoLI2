#pragma once

typedef struct pos {
    char l; 
    int c; 
} Pos; 

typedef struct matriz {
    
    int L; 
    int C; 
    char** matriz;

} Matriz;

typedef struct {
    char *dados;
    int cabeca;
    int tam;
} Stack;

typedef struct StackMat{
    Matriz *dados;
    int cabeca;
    int tam;
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

