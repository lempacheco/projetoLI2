#pragma once

#define MAX 26

typedef struct pos {
    char l; 
    int c; 
} Pos; 

typedef struct matriz {
    
    int L; 
    int C; 
    char matriz [MAX][MAX]; 

} Matriz;