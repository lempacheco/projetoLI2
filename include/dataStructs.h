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