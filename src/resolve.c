#include "../include/resolve.h"

int resolve(Matriz* m, Queue* q){
    /* Matriz t;
    initMatriz(&t); */


    Grupos caminho;
    caminho.gs = malloc(sizeof(Grupo));
    caminho.tam=1;
    caminho.cab=-1;

    Matriz mInicial;
    initMatriz(&mInicial);
    copiaMatriz(&mInicial, m);

    if (!encontraABA(m, &caminho)){
        if (!encontraAAXA(m, &caminho)){
            tudoBranco(m);
            if (!ganhou(m)){
                mvprintw(1, 0, "Tabuleiro é impossível.");
                return 0;
            }else{
                return 1;
            }
        }else{
            resolveAAXA(m, &caminho);
        }
    }else{
        resolveABA(m, &caminho);
    }

    while(ajuda(m, q) == 1);

    while(!ganhou(m)){
        if (!encontraABA(m, &caminho)){
            if (!encontraAAXA(m, &caminho)){
                /* copiaMatriz(&t, m);
                if (verificaTudoBranco(&t) == 1){
                    tudoBranco(m);
                    return 1;
                } */
                if (retrocedeCaminho(m, &mInicial, &caminho) == -1){
                    mvprintw(1, 0, "Tabuleiro é impossível.");
                    return 0;
                }
            }else{
                resolveAAXA(m, &caminho);
            }
        }else{
            resolveABA(m, &caminho);
        }

        while(ajuda(m, q) == 1);
    }

    free(caminho.gs);
    liberaMatriz(&mInicial);

    return 1;
}

int encontraABA(Matriz* m, Grupos* caminho){
    // Verifica padrões horizontais
    for (int i = 0; i < m->L; i++) {
        for (int j = 0; j < m->C - 2; j++) {
            if (m->matriz[i][j] == m->matriz[i][j + 2] && m->matriz[i][j] != m->matriz[i][j + 1]) {
                (caminho->cab)++;
                caminho->gs[caminho->cab].p1.l = i;
                caminho->gs[caminho->cab].p1.c = j;
                caminho->gs[caminho->cab].p2.l = i;
                caminho->gs[caminho->cab].p2.c = j+1;
                caminho->gs[caminho->cab].p3.l = i;
                caminho->gs[caminho->cab].p3.c = j+2;
                caminho->gs[caminho->cab].b = 1;
                caminho->gs = realloc(caminho->gs, sizeof(Grupo)*((caminho->cab)+2));
                return 1;
            }
        }
    }

    // Verifica padrões verticais
    for (int j = 0; j < m->C; j++) {
        for (int i = 0; i < m->L - 2; i++) {
            if (m->matriz[i][j] == m->matriz[i + 2][j] && m->matriz[i][j] != m->matriz[i + 1][j]) {
                (caminho->cab)++;
                caminho->gs[caminho->cab].p1.l = i;
                caminho->gs[caminho->cab].p1.c = j;
                caminho->gs[caminho->cab].p2.l = i+1;
                caminho->gs[caminho->cab].p2.c = j;
                caminho->gs[caminho->cab].p3.l = i+2;
                caminho->gs[caminho->cab].p3.c = j;
                caminho->gs[caminho->cab].b = 1;
                caminho->gs = realloc(caminho->gs, sizeof(Grupo)*((caminho->cab)+2));
                return 1;
            }
        }
    }

    return 0;
}

int encontraAAXA(Matriz* m, Grupos* caminho){
    // Verifica padrões horizontais
    for (int i = 0; i < m->L; i++) {
        for (int j = 0; j < m->C - 3; j++) { // Começa verificando as duas primeiras letras
            if (m->matriz[i][j] == m->matriz[i][j + 1]) { // As duas primeiras letras são iguais (XX)
                int k = j + 2;
                // Verifica letras intermediárias diferentes de X
                while (k < m->C - 1 && m->matriz[i][k] != m->matriz[i][j]) {
                    k++;
                }
                // Verifica se a sequência termina com X
                if (k < m->C && m->matriz[i][k] == m->matriz[i][j]) {
                    (caminho->cab)++;
                    caminho->gs[caminho->cab].p1.l = i;
                    caminho->gs[caminho->cab].p1.c = j;
                    caminho->gs[caminho->cab].p2.l = i;
                    caminho->gs[caminho->cab].p2.c = j+1;
                    caminho->gs[caminho->cab].p3.l = i;
                    caminho->gs[caminho->cab].p3.c = k;
                    caminho->gs[caminho->cab].b = 0;
                    caminho->gs = realloc(caminho->gs, sizeof(Grupo)*((caminho->cab)+2));
                    return 1;
                }
            }
        }
    }

    // Verifica padrões verticais
    for (int j = 0; j < m->C; j++) {
        for (int i = 0; i < m->L - 3; i++) { // Começa verificando as duas primeiras letras
            if (m->matriz[i][j] == m->matriz[i + 1][j]) { // As duas primeiras letras são iguais (XX)
                int k = i + 2;
                // Verifica letras intermediárias diferentes de X
                while (k < m->L - 1 && m->matriz[k][j] != m->matriz[i][j]) {
                    k++;
                }
                // Verifica se a sequência termina com X
                if (k < m->L && m->matriz[k][j] == m->matriz[i][j]) {
                    (caminho->cab)++;
                    caminho->gs[caminho->cab].p1.l = i;
                    caminho->gs[caminho->cab].p1.c = j;
                    caminho->gs[caminho->cab].p2.l = i+1;
                    caminho->gs[caminho->cab].p2.c = j;
                    caminho->gs[caminho->cab].p3.l = k;
                    caminho->gs[caminho->cab].p3.c = j;
                    caminho->gs[caminho->cab].b = 0;
                    caminho->gs = realloc(caminho->gs, sizeof(Grupo)*((caminho->cab)+2));
                    return 1;
                }
            }
        }
    }

    return 0;
}

void resolveABA(Matriz* m, Grupos* caminho){
    m->matriz[caminho->gs[caminho->cab].p1.l][caminho->gs[caminho->cab].p1.c] = '#';
    m->matriz[caminho->gs[caminho->cab].p2.l][caminho->gs[caminho->cab].p2.c] = toupper(m->matriz[caminho->gs[caminho->cab].p2.l][caminho->gs[caminho->cab].p2.c]);
}

void resolveAAXA(Matriz* m, Grupos* caminho){
    m->matriz[caminho->gs[caminho->cab].p2.l][caminho->gs[caminho->cab].p2.c] = '#';
    m->matriz[caminho->gs[caminho->cab].p3.l][caminho->gs[caminho->cab].p3.c] = '#';
}

int retrocedeCaminho(Matriz* m, Matriz* mInicial, Grupos* caminho){
    if (caminho->cab == -1) return -1;

    if (caminho->gs[caminho->cab].b == 1){//é um ABA
        if (m->matriz[caminho->gs[caminho->cab].p1.l][caminho->gs[caminho->cab].p1.c] == '#'){
            //reseta o p1
            m->matriz[caminho->gs[caminho->cab].p1.l][caminho->gs[caminho->cab].p1.c] = mInicial->matriz[caminho->gs[caminho->cab].p1.l][caminho->gs[caminho->cab].p1.c];
            //risca o p3
            m->matriz[caminho->gs[caminho->cab].p3.l][caminho->gs[caminho->cab].p3.c] = '#';
        }else if(m->matriz[caminho->gs[caminho->cab].p3.l][caminho->gs[caminho->cab].p3.c] == '#'){
            //reseta o p3
            m->matriz[caminho->gs[caminho->cab].p3.l][caminho->gs[caminho->cab].p3.c] = mInicial->matriz[caminho->gs[caminho->cab].p3.l][caminho->gs[caminho->cab].p3.c];
            //volta atrás no caminho
            caminho->cab--;
            //aplica esta função à posição atual do caminho
            retrocedeCaminho(m, mInicial, caminho);

            return 0;
        }
    }else{//é um AAXA
        if (m->matriz[caminho->gs[caminho->cab].p1.l][caminho->gs[caminho->cab].p1.c] != '#'){
            //reseta o p2
            m->matriz[caminho->gs[caminho->cab].p2.l][caminho->gs[caminho->cab].p2.c] = mInicial->matriz[caminho->gs[caminho->cab].p2.l][caminho->gs[caminho->cab].p2.c];
            //risca o p1
            m->matriz[caminho->gs[caminho->cab].p1.l][caminho->gs[caminho->cab].p1.c] = '#';
            //o p3 continua riscado
        }else if(m->matriz[caminho->gs[caminho->cab].p2.l][caminho->gs[caminho->cab].p2.c] != '#'){
            //reseta o p3
            m->matriz[caminho->gs[caminho->cab].p3.l][caminho->gs[caminho->cab].p3.c] = mInicial->matriz[caminho->gs[caminho->cab].p3.l][caminho->gs[caminho->cab].p3.c];
            //risca o p2
            m->matriz[caminho->gs[caminho->cab].p2.l][caminho->gs[caminho->cab].p2.c] = '#';
            //o p1 continua riscado
        }else if(m->matriz[caminho->gs[caminho->cab].p3.l][caminho->gs[caminho->cab].p3.c] != '#'){
            //reseta o p1
            m->matriz[caminho->gs[caminho->cab].p1.l][caminho->gs[caminho->cab].p1.c] = mInicial->matriz[caminho->gs[caminho->cab].p1.l][caminho->gs[caminho->cab].p1.c];
            //reseta o p2
            m->matriz[caminho->gs[caminho->cab].p2.l][caminho->gs[caminho->cab].p2.c] = mInicial->matriz[caminho->gs[caminho->cab].p2.l][caminho->gs[caminho->cab].p2.c];
            //volta atrás no caminho
            caminho->cab--;
            //aplica esta função à posição atual do caminho
            return retrocedeCaminho(m, mInicial, caminho);

            return 0;
        }
    }

    return 1;
}

int ganhou(Matriz* m){
    NodeGrupo* grupo;
    if (!verificar(m, &grupo)) return 0;

    int r = 1;
    for (int i=0; i<m->L && r; i++){
        for (int j=0; j<m->C && r; j++){
            if (m->matriz[i][j] != '#' && !isupper(m->matriz[i][j])) r=0;
        }
    }
    return r;
}

void tudoBranco(Matriz* m){
    for (int i=0; i<m->L; i++){
        for (int j=0; j<m->C; j++){
            if (m->matriz[i][j] != '#' && !isupper(m->matriz[i][j])) m->matriz[i][j] = toupper(m->matriz[i][j]);
        }
    }
}

/* int verificaTudoBranco(Matriz* m){
    NodeGrupo* grupos = NULL;

    tudoBranco(m);

    int r = verificar(m, &grupos);

    liberaGrupos(grupos);

    return r;
} */
