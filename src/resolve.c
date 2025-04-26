#include "../include/resolve.h"

void resolveTabuleiro(Matriz* m, Queue* q){//matrizinicial
    int i=0; 
    int r; 
    Matriz mInicial; 
    initMatriz (&mInicial); 
    copiaMatriz(&mInicial, m); 
    Pos p1, p2; 
    Pos* jaRiscou = malloc(sizeof(Pos)); 
    int tamJaRiscou = 0; 
    int jaAdicionou = 0; 

    encontraPrimeiroRepetido(m, &p1, &p2, m->L, m->C); 

    while (!ganhou(m)){
        if (!posicaoPertence(jaRiscou, tamJaRiscou, p1)){
            m->matriz [p1.l][p1.c] = '#'; 
            r=0; 
        } else if (!posicaoPertence(jaRiscou, tamJaRiscou, p2)){
            m->matriz [p2.l][p2.c] = '#'; 
            r=0; 
            p1=p2; 
        } else {
            if(!ganhou(m) && encontraPrimeiroRepetido(m, &p1, &p2, m->L, m->C) == 0){
                copiaMatriz(m, &mInicial); 
            }
            r=1;
        }

        if(r==0){
            if (!jaAdicionou){ 
                jaRiscou[tamJaRiscou] = p1; 
                jaAdicionou = 1; 
                tamJaRiscou++;
                jaRiscou = realloc(jaRiscou, sizeof(Pos) * tamJaRiscou + 1);

            }
            while(ajuda(m,q) > 0);
            if(!ganhou(m) && encontraPrimeiroRepetido(m, &p1, &p2, m->L, m->C) == 0){
                copiaMatriz(m, &mInicial); 
                jaAdicionou = 0; 
            }
             
        }
    }
    free(jaRiscou);
}

int posicaoPertence(Pos* array, int tamanho, Pos p) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (array[i].l == p.l && array[i].c == p.c) {
            return 1; // Pertence
        }
    }
    return 0; // Não pertence
}


int encontraPrimeiroRepetido(Matriz* m, Pos* p1, Pos* p2, int a, int b) {
    int i, j, k;

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            char atual = m->matriz[i][j];

            // Procura novamente a partir da próxima casa
            for (k = j + 1; k < b; k++) {
                if (m->matriz[i][k] == atual) {
                    p1->l = i;
                    p1->c = j;
                    p2->l = i;
                    p2->c = k;
                    return 1; // Encontrou repetido na linha
                }
            }

            // Depois procura nas outras linhas
            for (k = i + 1; k < a; k++) {
                if (m->matriz[k][j] == atual) {
                    p1->l = i;
                    p1->c = j;
                    p2->l = k;
                    p2->c = j;
                    return 1; // Encontrou repetido na coluna
                }
            }
        }
    }

    return 0; // Não encontrou repetido
}

int ganhou(Matriz* m){
    int r=1; 
    NodeGrupo** grupo = NULL; 

    if (!verificar(m,grupo)){
        return 0; 
    }
    for(int i=0; i<m->L && r; i++){
        for(int j=0; j<m->C && r; j++){
            if (m->matriz[i][j] != '#' && !isupper(m->matriz[i][j])){
                r=0; // não resolveu; 
            }
        }
    }
    return r; 
}