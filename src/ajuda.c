#include "../include/ajuda.h"

int ajuda(Matriz* m, Queue* q) {//retorna -1 se o tabuleiro for inválido (as funções nem correm), 0 se as funções correm mas n muda nada, >0 se mudou alguma coisa
    NodeGrupo* grupos = NULL;
    int r=0;
    Matriz t;
    
    initMatriz(&t);
    copiaMatriz(&t, m);

    liberaGrupos(grupos);
    grupos = NULL;

    if (verificar(m, &grupos)) {
        liberaGrupos(grupos); grupos = NULL;
        r += riscarIguaisDeLetraBranca(m, &grupos);

        liberaGrupos(grupos); grupos = NULL;
        r += pintarVizinhosDeRiscadas(m, &grupos);

        liberaGrupos(grupos); grupos = NULL;
        r += manterCaminho(m, q, &grupos);
    } else {
        printf("O tabuleiro atual é inválido.\n");
        r = -1;
    }


    liberaGrupos(grupos); grupos = NULL;
    if (!verificar(m, &grupos)) {
        copiaMatriz(m, &t);
        printf("O tabuleiro já não é válido");
        r = -1;
    }

    liberaMatriz(&t);
    liberaGrupos(grupos);

    return r;
}


int riscarIguaisDeLetraBranca(Matriz* m, NodeGrupo** grupos){//return: 0 n mudou nada, 1 mudou
    int r=0;

    for(int i=0; i<m->L; i++){
        for(int j=0; j<m->C; j++){
            if (isupper(m->matriz[i][j]) && m->matriz[i][j]!='#'){
                for(int l=0; l<m->L; l++){
                    if(tolower(m->matriz[i][j]) == m->matriz[l][j]){
                        char t = m->matriz[l][j];
                        m->matriz[l][j] = '#';
                        if(!verificar(m, grupos)) m->matriz[l][j] = t;
                        else if (r==0 && verificar(m, grupos)) r=1;
                    }
                }
                for(int c=0; c<m->C; c++){
                    if(tolower(m->matriz[i][j]) == m->matriz[i][c]){
                        char t = m->matriz[i][c];
                        m->matriz[i][c] = '#';
                        if(!verificar(m, grupos)) m->matriz[i][c] = t;
                        else if (r==0 && verificar(m, grupos)) r=1;
                    }
                }
            }
        }
    }

    return r;
}

int pintarVizinhosDeRiscadas(Matriz* m, NodeGrupo** grupos){
    int i, j;
    int r=0;

    for (i=0; i<m->L; i++){
        for (j=0; j<m->C; j++){
            if (m->matriz[i][j]=='#'){
                if (i+1<m->L){
                    m->matriz[i+1][j] = toupper(m->matriz[i+1][j]);
                    if(!verificar(m, grupos)) m->matriz[i+1][j] = tolower(m->matriz[i+1][j]);
                    else if (r==0 && verificar(m, grupos)) r=1;
                } 

                if (i-1>=0){
                    m->matriz[i-1][j] = toupper(m->matriz[i-1][j]);
                    if(!verificar(m, grupos)) m->matriz[i-1][j] = tolower(m->matriz[i-1][j]);
                    else if (r==0 && verificar(m, grupos)) r=1;
                } 

                if (j+1<m->C){
                    m->matriz[i][j+1] = toupper(m->matriz[i][j+1]);
                    if(!verificar(m, grupos)) m->matriz[i][j+1] = tolower(m->matriz[i][j+1]);
                    else if (r==0 && verificar(m, grupos)) r=1;
                } 

                if (j-1>=0){
                    m->matriz[i][j-1] = toupper(m->matriz[i][j-1]);
                    if(!verificar(m, grupos)) m->matriz[i][j-1] = tolower(m->matriz[i][j-1]);
                    else if (r==0 && verificar(m, grupos)) r=1;
                }
            }   
        }
    }

    return r;
}

int manterCaminho(Matriz* m, Queue* q, NodeGrupo** grupos){
    int i, j;
    char t;
    int r=0;

    for (i=0; i<m->L; i++){
        for (j=0; j<m->C; j++){
            t = m->matriz[i][j];
            m->matriz[i][j] = '#';
            if (!verificaCaminho(m, q)){
                m->matriz[i][j] = toupper(t);
            }
            else if (verificaCaminho(m, q) || !verificar(m, grupos)){
                m->matriz[i][j] = t;
            }else if (r==0 && verificar(m, grupos)) r=1;
        }
    }

    return r;
}
