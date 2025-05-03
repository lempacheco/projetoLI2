#include "../include/ajuda.h"

int ajuda(Matriz* m, Queue* q) {//retorna -1 se o tabuleiro for inválido (as funções nem correm), 0 se as funções correm mas n muda nada, 1 se mudou alguma coisa
    NodeGrupo* grupos = NULL;
    Matriz t;
    
    if (ganhou(m)) return 0;

    initMatriz(&t);
    copiaMatriz(&t, m); // salvar estado inicial)

    if (verificar(m, &grupos)) {
        liberaGrupos(grupos); grupos = NULL;

        riscarIguaisDeLetraBranca(m, &grupos);

        liberaGrupos(grupos); grupos = NULL;
        pintarVizinhosDeRiscadas(m, &grupos);
        liberaGrupos(grupos); grupos = NULL;

        manterCaminho(m, q, &grupos);
        liberaGrupos(grupos); grupos = NULL;

    } else {
        mensagens("O tabuleiro atual é inválido.");
        liberaGrupos(grupos); grupos = NULL;
        liberaMatriz(&t);
        return -1;
    }

    
    if (!verificar(m, &grupos)) {
        liberaGrupos(grupos); grupos = NULL;

        copiaMatriz(m, &t);
        liberaMatriz(&t);
        return -1;
    }

    if (!saoIguais(&t, m)){
        liberaMatriz(&t);
        return 1;
    }

    int mudou = !saoIguais(m, &t);

    liberaMatriz(&t);
    liberaGrupos(grupos);

    if (mudou) return 1;
    return 0;
}


void riscarIguaisDeLetraBranca(Matriz* m, NodeGrupo** grupos){
    for(int i=0; i<m->L; i++){
        for(int j=0; j<m->C; j++){
            if (isupper(m->matriz[i][j]) && m->matriz[i][j]!='#'){
                for(int l=0; l<m->L; l++){
                    if(tolower(m->matriz[i][j]) == m->matriz[l][j]){
                        char t = m->matriz[l][j];
                        m->matriz[l][j] = '#';
                        if(!verificar(m, grupos)) m->matriz[l][j] = t;
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
            else if (verificaCaminho(m, q) || !verificar(m, grupos)){
                m->matriz[i][j] = t;
            }
        }
    }
}

int saoIguais(Matriz* m1, Matriz* m2){
    int i, j;
    int r = 1;
    if(m1->L != m2->L) return 0; 
    if(m1->C != m2->C) return 0; 

    if (m1->matriz == NULL){
        if(m1->matriz != m2->matriz) return 0;
    }else{
        for (i = 0; i < m1->L && r; i++) {
            for (j = 0; j < m1->C && r; j++) {
                r = (m1->matriz[i][j] == m2->matriz[i][j]);
            }
        }
    }

    return r;
}

int ajudaSempre(Matriz* m, Queue* q){
    int c = 0; 
    while (ajuda(m, q) == 1) c++;
    if (c == 0) return -1; 

    return 0; 
    
}