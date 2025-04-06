
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "etapa1.h"

// Problema com a posição (+1)

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

int branco (Matriz *m, Pos p){
    
    if (m->matriz[p.l][p.c] != '#' && !(isupper(m->matriz[p.l][p.c])))
    m->matriz[p.l][p.c] = toupper(m->matriz[p.l][p.c]); 

    return 0; 
}

int riscar (Matriz *m, Pos p){
    
    if (!(isupper(m->matriz[p.l][p.c])))
    m->matriz[p.l][p.c] = '#'; 

    return 0; 
}
 
int escolheComandos (Matriz *m){
    int pl, pc; 
    int c; 
    int r; 

    if (scanf(" %c" "%d" "%d", &c, &pl, &pc)!=3) r=1;
    else if (pl < 0 || pc < 0 || pl >= (m->L) || pc >= (m->C)) {
        r=1; 
    }
    else {
        Pos p = {pl, pc}; 
        if (c == 'b') {
            branco(m, p);
            r=0; 
        } 
        else if (c == 'r') {
            riscar(m, p);
            r=0; 
        }
        else r=1; 
    }

    return r; 

}

int main (){

    Matriz matriz1;
    matriz1.L = 5;
    matriz1.C = 5;


    const char dados[25] = {
        'e', 'c', 'a', 'd', 'c',
        'd', 'c', 'd', 'e', 'c',
        'b', 'd', 'd', 'c', 'e',
        'c', 'd', 'e', 'e', 'b',
        'a', 'c', 'c', 'b', 'b'
    };

    int k = 0;
    for (int i = 0; i < matriz1.L; i++) {
        for (int j = 0; j < matriz1.C; j++) {
            matriz1.matriz[i][j] = dados[k++];
        }
    }

    mostraMatriz(&matriz1); 

    while (escolheComandos(&matriz1) != 1) {
        mostraMatriz(&matriz1);
    }

    return 0; 
    
}

