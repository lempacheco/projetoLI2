
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


#define MAX 26

// Problema com a posição (+1)

typedef struct pos {
    int l; 
    int c; 
} Pos; 

typedef struct matriz {
    
    int L; 
    int C; 
    char matriz [MAX][MAX]; 

} Matriz;


int mostraMatriz (Matriz *m) {
    int i, j; 

    for(i=0; i<m->L; i++){
        for (j=0; j<m->C; j++){
            printf("%c",m->matriz[i][j]); 
        }
        printf("\n"); 
    }
    printf("\n");

    return 0; 
}

int leTamanhoMatriz (Matriz *m) {
    int r=0;  

    if (scanf("%d %d", &m->L, &m->C) != 2 || m->L > MAX || m->C > MAX || m->L < 0 || m->C < 0) r=1;

    return r; 
}

void matrizRandom (Matriz *m) {

    srand(time(0));  

    for (int i=0; i<m->L; i++){
        for (int j=0; j<m->C; j++){
            m->matriz[i][j] = (char)(rand() % (122-97+1) + 97);
        }
    }
}

int main(){
    
    Matriz m; 

    leTamanhoMatriz(&m); 
    matrizRandom(&m); 
    mostraMatriz(&m); 

    return 0; 
}