#include "../include/resolve.h"

void resolveTabuleiro(Matriz* m){//matrizinicial
    //encontrar todos os repetidos em cada linha
    Rep* repL;
    repL = malloc(sizeof(Rep));
    repL[0].i = malloc(sizeof(int));
    repL[0].j = malloc(sizeof(int));

    encontraRep(m, repL, m->L, m->C);

    //encontrar todos os repetidos em cada coluna
    Rep* repC;
    repC = malloc(sizeof(Rep));
    repC[0].i = malloc(sizeof(int));
    repC[0].j = malloc(sizeof(int));

    encontraRep(m, repC, m->C, m->L);

    //
}

void encontraRep(Matriz* m, Rep* rep, int a, int b){
    int i, j;
    int temp;
    int tamRep = 1;

    for(i=0; i<a; i++){
        for (j=0; j<b; j++){
            if ((temp = existe(m->matriz[i][j], rep, tamRep)) != -1){
                rep[temp].freq++;
                rep[temp].i[rep[temp].freq] = i;
                rep[temp].j[rep[temp].freq] = j;
                realocaIJ(rep, rep[temp].freq+1);
            }else{
                rep[tamRep-1].freq = 1;
                rep[tamRep-1].simbolo = m->matriz[i][j];
                rep[tamRep-1].i[0] = i;
                rep[tamRep-1].j[0] = j;

                tamRep++;
                realocaRep(rep, tamRep);
            }
        }
    }
}

void realocaRep(Rep* rep, int tamRep){
    rep = realloc(rep, sizeof(Rep)*tamRep);
    rep[tamRep-1].i = malloc(sizeof(int));
    rep[tamRep-1].j = malloc(sizeof(int));
}

void realocaIJ(Rep* rep, int i){
    rep[i].i = realloc(rep[i].i, sizeof(int)*rep[i].freq);
    rep[i].j = realloc(rep[i].j, sizeof(int)*rep[i].freq);
}

int existe(char c, Rep* rep, int tamRep){//retorna -1 se n existe, o índice de rep onde está guardado se existe
    int i;
    int r = -1;
    for (i=0; i<tamRep; i++){
        if (c == rep[i].simbolo) r = i;
    }
    return r;
}