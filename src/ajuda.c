#include "../include/ajuda.h"

/* 
    Recebe a matriz em jogo e a `Queue`.
    Faz as mudanças ao tabuleiro atual que podem ser inferidas pelas
    mudanças feitas pelo jogador anteriormente, sendo estas:
        - Riscar as letras iguais a uma letra na casa pintada de branco que estão na mesma
        linha ou coluna;
        - Pintar as casas á volta de uma casa riscada de branco;
        - pintar casas que sejam necessárias para existir caminhos entre as casas brancas.
   
     A função pode retornar:
        - -1 se o tabuleiro for inválido;
        - 0 se as funções correm mas não há mudanças no tabuleiro;
        - 1 se houve alterações na matriz.
*/

int ajuda(Matriz* m, Queue* q, int mostraMensagem) { 
    NodeGrupo* grupos = NULL;
    Matriz t;
    
    if (ganhou(m)) return 0;

    initMatriz(&t);
    copiaMatriz(&t, m); // cópia do estado original da matriz,para detectar alterações.

    if (verificar(m, &grupos)) {
        liberaGrupos(grupos); grupos = NULL;

        riscarIguaisDeLetraBranca(m, &grupos);
        liberaGrupos(grupos); grupos = NULL;
        
        pintarVizinhosDeRiscadas(m, &grupos);
        liberaGrupos(grupos); grupos = NULL;

        manterCaminho(m, q, &grupos);
        liberaGrupos(grupos); grupos = NULL;

    } else {
        if (mostraMensagem) mensagens("O tabuleiro atual é inválido.");
        liberaGrupos(grupos); grupos = NULL;
        liberaMatriz(&t);
        return -1;
    }

    
    if (!verificar(m, &grupos)) {
        liberaGrupos(grupos); grupos = NULL;
        if (mostraMensagem) mensagens("O tabuleiro não está de acordo com a solução.");
        copiaMatriz(m, &t);
        liberaMatriz(&t);
        return -1;
    } 

    if (!saoIguais(&t, m)){
        liberaMatriz(&t);
        return 1;
    }else{
        liberaMatriz(&t);
        if (mostraMensagem) mensagens("Já não há mais casas para mudar.");
        return 0;
    }
}

/* 
    Recebe a matriz do jogo e uma lista de grupo vazia.
    Percorre a matriz a procura de casas pintadas de branco,
    se encontrar uma vai ao longo da linha e depois coluna onde esta
    se encontra e tenta riscar de braco letras iguais à da casa
    riscada.
*/

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

/* Recebe a matriz do jogo e uma lista de grupo vazia.
   Percorre a matriz a procura de casas riscadas,
   se encontrar uma vai tentar pintar de branco as casas à sua volta.
*/

void pintarVizinhosDeRiscadas(Matriz* m, NodeGrupo** grupos){
    int i, j;

    for (i=0; i<m->L; i++){
        for (j=0; j<m->C; j++){
            if (m->matriz[i][j]=='#'){
                tentaPintar(m, i+1, j, grupos);
                tentaPintar(m, i-1, j, grupos);
                tentaPintar(m, i, j+1, grupos);
                tentaPintar(m, i, j-1, grupos);
            }   
        }
    }
}

/* 
    Recebe a matriz do jogo, uma `Queue` e uma lista de grupo vazia.
    Percorre a matriz e verifica se ao riscar a casa o não existir mais caminho
    ortogonal entre as casas brancas, a casa é riscada de branco e não 
    altera nada nos outros casos. 
*/

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

/* Recebe a matriz atualmente em jogo e a com as alterações da ajuda.
   Verifica se não há alterações entre elas.
*/

int saoIguais(Matriz* m1, Matriz* m2){
    int i, j;
    int r = 1;
    if(m1->L != m2->L) return 0; 
    if(m1->C != m2->C) return 0; 

    if (!m1->matriz || !m2->matriz) {return m1->matriz == m2->matriz;
    }else{
        for (i = 0; i < m1->L && r; i++) {
            for (j = 0; j < m1->C && r; j++) {
                r = (m1->matriz[i][j] == m2->matriz[i][j]);
            }
        }
    }

    return r;
}

/* Recebe a matriz a ser alterada, os valores correspondentes à linha e à coluna 
   e uma lista vazia de grupos.
   Tenta pintar de branca a casa correspondente.
   Não faz nada se pintar de branco causar infrações.
*/

void tentaPintar(Matriz* m, int i, int j, NodeGrupo** grupos) {
    if (i >= 0 && i < m->L && j >= 0 && j < m->C) {
        m->matriz[i][j] = toupper(m->matriz[i][j]);
        if (!verificar(m, grupos))
            m->matriz[i][j] = tolower(m->matriz[i][j]);
    }
}

/* Recebe uma matriz e uma `Queue*`.
   Utiliza a funçao ajuda até ela não fazer alterações.
   Não faz nada se a função `ajuda` der erro.
*/

int ajudaSempre(Matriz* m, Queue* q){
    int c = 0; 
    while (ajuda(m, q, 1) == 1) c++;
    if (c == 0) return -1; 

    return 0; 
    
}