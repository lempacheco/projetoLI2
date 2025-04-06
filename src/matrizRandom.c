#include "../include/matrizRandom.h"

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