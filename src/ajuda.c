#include "../include/ajuda.h"

int ajuda(Matriz* m, Queue* q){
    NodeGrupo* grupos = NULL;
    int r;
    Matriz t;
    initMatriz(&t);
    copiaMatriz(&t, &m);

    if (verificar(m, &grupos)){
        riscarIguaisDeLetraBranca(m, &grupos);
        pintarVizinhosDeRiscadas(m, &grupos);
        manterCaminho(m, q, &grupos);
        r = 0;
    }else{
        printf("O tabuleiro atual é inválido.\n");
        r = -1;
    }

    if (!verificar(m, &grupos)){
        copiaMatriz(&m, &t);
    }

    liberaMatriz(&m);
    liberaGrupos(grupos);

    return r;
}

void riscarIguaisDeLetraBranca(Matriz* m, NodeGrupo** grupos){
    for(int i=0; i<m->L; i++){
        for(int j=0; j<m->C; j++){
            if (isupper(m->matriz[i][j]) && m->matriz[i][j]!='#'){
                for(int l=0; l<m->L; l++){
                    if(tolower(m->matriz[i][j]) == m->matriz[l][j]){
                        char t = m->matriz[l][j];
                        m->matriz[l][j] = '#';
                        if(!verificar(m, grupos)){
                            m->matriz[l][j] = t;
                        }
                    }
                }
                for(int c=0; c<m->C; c++){
                    if(tolower(m->matriz[i][j]) == m->matriz[i][c]){
                        char t = m->matriz[i][c];
                        m->matriz[i][c] = '#';
                        if(!verificar(m, grupos)) m->matriz[i][c] = t;
                    }
                }
            }
        }
    }
}

void pintarVizinhosDeRiscadas(Matriz* m, NodeGrupo** grupos){
    int i, j;
    for (i=0; i<m->L; i++){
        for (j=0; j<m->C; j++){
            if (m->matriz[i][j]=='#'){
                if (i+1<m->L){
                    m->matriz[i+1][j] = toupper(m->matriz[i+1][j]);
                    if(!verificar(m, grupos)) m->matriz[i+1][j] = tolower(m->matriz[i+1][j]);
                } 

                if (i-1>=0){
                    m->matriz[i-1][j] = toupper(m->matriz[i-1][j]);
                    if(!verificar(m, grupos)) m->matriz[i-1][j] = tolower(m->matriz[i-1][j]);
                } 

                if (j+1<m->C){
                    m->matriz[i][j+1] = toupper(m->matriz[i][j+1]);
                    if(!verificar(m, grupos)) m->matriz[i][j+1] = tolower(m->matriz[i][j+1]);
                } 

                if (j-1>=0){
                    m->matriz[i][j-1] = toupper(m->matriz[i][j-1]);
                    if(!verificar(m, grupos)) m->matriz[i][j-1] = tolower(m->matriz[i][j-1]);
                }
            }
        }
    }
}

void manterCaminho(Matriz* m, Queue* q, NodeGrupo** grupos){
    int i, j;
    char t;
    for (i=0; i<m->L; i++){
        for (j=0; j<m->C; j++){
            t = m->matriz[i][j];
            m->matriz[i][j] = '#';
            if (!verificaCaminho(m, q)){
                m->matriz[i][j] = toupper(t);
            }
            if (verificaCaminho(m, q) || !verificar(m, grupos)){
                m->matriz[i][j] = t;
            }
        }
    }
}