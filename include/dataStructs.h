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
    char *comandos;
    int cabeca;
    int tam;
} StackMat;

typedef struct stackG{
    Matriz* matrizes;
    int* jaExistia; //0 = não existia, 1 = existia mas não tinha nada lá dentro, 2 = existia e tinha uma matriz lá dentro
    char** nomesFicheiros;
    int* lenNomes;
    int cabeca;
    int tam;
} StackG;