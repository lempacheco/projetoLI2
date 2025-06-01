#include "../include/resolve.h"

/* Recebe a matriz em jogo a matriz inicial e uma queue
   Resolve o tabuleiro seguindo padrões ABA ou AAXA presentes nele.
   Pode retornar:
    - 1 se o tabuleiro foi resolvido com sucesso;
    - 0 se o tabuleiro é impossível;
    - -1 se já estava resolvido.
*/

int resolve(Matriz* m, Matriz* mInicial, Queue* q){
    
    Grupos caminho;
    caminho.gs = malloc(sizeof(Grupo));
    caminho.tam=1;
    caminho.cab=-1;
    int r=1; 

    if (ganhou(m)){
        mensagens("O tabuleiro já está resolvido.");

        free(caminho.gs);
        return -1;
    }

    copiaMatriz(m, mInicial);

    if (!encontraABA(m, &caminho)){
        if (!encontraAAXA(m, &caminho)){
            tudoBranco(m);
            if (!ganhou(m)){
                mensagens("Tabuleiro é impossível.");

                free(caminho.gs);
                return 0;
            }else{
                free(caminho.gs);
                return 1;
            }
        }else{
            resolveAAXA(m, &caminho);
        }
    }else{
        resolveABA(m, &caminho);
    }

    while(ajuda(m, q, 0) == 1);

    while(!ganhou(m) && r==1){
        if (!encontraABA(m, &caminho)){
            if (!encontraAAXA(m, &caminho)){
                if (retrocedeCaminho(m, mInicial, &caminho) == -1){
                    mensagens("Tabuleiro é impossível.");

                    free(caminho.gs);
                    r = 0;
                }
            }else{
                resolveAAXA(m, &caminho);
            }
        }else{
            resolveABA(m, &caminho);
        }

        while(ajuda(m, q, 0) == 1);
    }

    free(caminho.gs);

    return r;
}

/* Recebe a matriz e uma stack com os grupos de padrões. 
   Procura pelo padrão ABA ao longo da linha ou coluna e adiciona o grupo correspondente na stack.
   Pode retornar:
    - 1 se encontrou um padrão ABA.
    - 0 caso contrário. 
*/

int encontraABA(Matriz* m, Grupos* caminho){
    int r=0; 
    // Verifica padrões horizontais
    for (int i = 0; i < m->L && r==0; i++) {
        for (int j = 0; j < m->C - 2 && r==0; j++) {
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
                r= 1;
            }
        }
    }

    // Verifica padrões verticais
    for (int j = 0; j < m->C && r==0; j++) {
        for (int i = 0; i < m->L - 2 && r==0; i++) {
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
                r=1;
            }
        }
    }

    return r;
}

/* Recebe a matriz e uma stack com os grupos de padrões. 
   Procura pelo padrão AAXA ao longo da linha ou coluna e adiciona o grupo correspondente na stack.
   Pode retornar:
    - 1 se encontrou um padrão AAXA.
    - 0 caso contrário. 
*/

int encontraAAXA(Matriz* m, Grupos* caminho){
    int r=0; 
    // Verifica padrões horizontais
    for (int i = 0; i < m->L && r==0; i++) {
        for (int j = 0; j < m->C - 3 && r==0; j++) { // Começa verificando as duas primeiras letras
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
                    r = 1;
                }
            }
        }
    }

    // Verifica padrões verticais
    for (int j = 0; j < m->C && r==0; j++) {
        for (int i = 0; i < m->L - 3 && r==0; i++) { // Começa verificando as duas primeiras letras
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
                    r = 1;
                }
            }
        }
    }

    return r;
}

/* Recebe a matriz e uma stack com os grupos de padrões. 
   Tenta resolver grupos do tipo ABA, risca o primeiro caractere e pinta o do meio de branco. */

void resolveABA(Matriz* m, Grupos* caminho){
    m->matriz[caminho->gs[caminho->cab].p1.l][caminho->gs[caminho->cab].p1.c] = '#';
    m->matriz[caminho->gs[caminho->cab].p2.l][caminho->gs[caminho->cab].p2.c] = toupper(m->matriz[caminho->gs[caminho->cab].p2.l][caminho->gs[caminho->cab].p2.c]);
}

/* Recebe a matriz e uma stack com os grupos de padrões. 
   Tenta resolver grupos do tipo AAXA, risca os caracteres A do meio e do fim. */

void resolveAAXA(Matriz* m, Grupos* caminho){
    m->matriz[caminho->gs[caminho->cab].p2.l][caminho->gs[caminho->cab].p2.c] = '#';
    m->matriz[caminho->gs[caminho->cab].p3.l][caminho->gs[caminho->cab].p3.c] = '#';
}

/* Recebe a matriz com alterações feitas pela retroceder, a matriz inicial e uma stack 
   com os grupos de padrões.
   Retrocede de uma jogada anterior com base na Stack.
   Pode retornar:
     - 1 se conseguiu retroceder nesta iteração.
     - 0 se precisou voltar mais.
     - -1 se não há mais movimentos para voltar. */

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

/* Recebe uma matriz.
   Verifica se essa matriz ganhou o jogo, ou seja, há caminho ortogonal entre
   as casas brancas e não há infingimentos de regras e todas as casas estão ou
   riscadas ou pintadas de branco.
   Pode retornar:
    - 1 se ganhou;
    - 0 se não;
*/

int ganhou(Matriz* m){
    NodeGrupo* grupo=NULL;
    if (!verificar(m, &grupo)) {liberaGrupos(grupo); return 0;}

    int r = 1;
    for (int i=0; i<m->L && r; i++){
        for (int j=0; j<m->C && r; j++){
            if (m->matriz[i][j] != '#' && !isupper(m->matriz[i][j])) r=0;
        }
    }
    if (grupo != NULL) liberaGrupos(grupo);
    return r;
}

/* Recebe uma matriz.
   Pinta todas as letras minusculas peresntes na matriz de branco.
*/

void tudoBranco(Matriz* m){
    for (int i=0; i<m->L; i++){
        for (int j=0; j<m->C; j++){
            if (m->matriz[i][j] != '#' && !isupper(m->matriz[i][j])) m->matriz[i][j] = toupper(m->matriz[i][j]);
        }
    }
}