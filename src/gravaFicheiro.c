#include "../include/gravaFicheiro.h"
#include <ncurses.h>

/*
    Guarda o estado de um jogo em ficheiros com os nomes dados, usando as funções `gravaMatriz` e `gravaStack`, 
    criando dois ficheiros: 
        - um que contém a matriz do jogo atual na diretoria 'lib'; 
        - outro que contém o histórico dos comandos na diretoria 'lib/history'.
*/

int gravaFicheiro(char* nomeM, char* nomeS, Matriz* m, StackMat* s){
    FILE* fpM; 
    FILE* fpS;
    int r=0;

    //matriz
    fpM = fopen(nomeM, "w");

    if (gravaMatriz(m, fpM)) return -1;
    fclose(fpM);

    //stackMat
    fpS = fopen(nomeS, "w");

    if (gravaStackMat(s,fpS)) return -1;
    fclose(fpS);
    
    return r; 
}

/* 
    Guarda a matriz fornecida num ficheiro. Escreve no seguinte formato:
   
    - Primeira linha: <L> <C> (número de linhas e colunas).
    - Linhas seguintes: conteúdo da matriz, linha a linha. 
*/

int gravaMatriz(Matriz* m, FILE* fp){
    int i, j, r=0;

    if (fprintf(fp, "%d %d\n", m->L, m->C) < 0) return 1; 

    for (i=0; i<m->L && r!=1; i++){
        for (j=0; j<m->C && r!=1; j++){
            if (fputc(m->matriz[i][j], fp) == EOF) r = 1;
        }
        if (i != m->L-1)
            if (fputc('\n', fp) == EOF) r=1;
    }

    return r;
}

/* Guarda a stackMat fornecida num ficheiro. Escreve no seguinte formato:
   
   - Primeira linha: <cabeça> <tamanho> (cabeça e tamanho da `stackMat`).
   - Linhas seguintes:
        - caracter a representar o comando utilizado
        - conteúdo da `stackMat`, matriz a matriz, usando a função `gravaMatriz`.
*/

int gravaStackMat(StackMat* s, FILE* fp){
    int i, r=0;

    //s->cabeca e s->tam
    if (fprintf (fp, "%d %d\n", s->cabeca, s->tam) < 0) return 1;

    for (i=0; i <= s->cabeca && r!=1; i++){
        //comando
        if (fputc(s->comandos[i], fp) == EOF) r= 1;

        //matriz
        if (fputc('\n', fp) == EOF) r= 1;
        if (gravaMatriz(&s->dados[i], fp)) r= 1;

        if (fputc('\n', fp) == EOF) r=1;
    }

    return r;
} 