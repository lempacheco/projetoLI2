#include "../include/leFicheiro.h"
#include <ncurses.h>

/*  Lê o conteúdo de ficheiros relativos a um jogo e carrega-o na matriz e na stackMat fornecida.

  O formato esperado do ficheiro são:
  - Primeira linha: dois dígitos separados por espaço, representando o número de linhas (L) e colunas (C) da matriz.
  - Linhas seguintes: caracteres da matriz, linha a linha.
*/

int leFicheiro(char* nomeMatriz, char* nomeStackMat, Matriz *m, StackMat* s) {
    FILE* fpM;
    FILE* fpS;   
    int r=0;

    //matriz atual
    fpM = fopen(nomeMatriz, "r");
    if (fpM == NULL) {
        mensagens ("Erro ao abrir o ficheiro.");
        return -1; 
    }

    if (m->matriz != NULL) liberaMatriz(m);
    
    leMatriz(m, fpM);
    fclose(fpM); 

    //stackMat

    if (s->tam != 0){
        liberaStackMat(s);
        initStackMat(s);
    }
  
    if ((fpS = fopen(nomeStackMat, "r"))) //o ficheiro já existe
    {

        leStackMat(s, fpS);
        fclose(fpS);
    }

    //matriz inicial na stackMat
    copiaMatriz(&s->mInicial, m);

    return r; 
}  

/*  Lê o conteúdo de um ficheiro e carrega-o na matriz fornecida.

  O formato esperado do ficheiro é:
  - Primeira linha: dois dígitos separados por espaço, representando o número de linhas (L) e colunas (C) da matriz.
  - Linhas seguintes: caracteres da matriz, linha a linha.
*/

void leMatriz(Matriz* m, FILE* fp){
    int i, j;
    char temp;
    
    leNumero(&m->L, fp);
    leNumero(&m->C, fp);

    if (m->L <= 0 || m->C <= 0){
        m->matriz = NULL;
        mensagens("Erro: ficheiro não contém uma matriz válida.");
    }
    
   
    m->matriz = malloc(sizeof(char*)*m->L);
    for (i=0; i<m->L; i++){
        m->matriz[i] = malloc(sizeof(char)*m->C);
        
        for (j=0; j<m->C; j++){
            temp = fgetc(fp); 
            while (temp == ' ' || temp == '\n'){//ignora espacos e newlines
                temp = fgetc(fp);
            }
            m->matriz[i][j] = temp;
             
        }
    }

    temp = fgetc(fp);
}

/*  Lê o conteúdo de um ficheiro e carrega-o na stackMat fornecida.

  O formato esperado do ficheiro é:
  - Primeira linha: dois dígitos separados por espaço, representando a cabeça e o tamanho da stackMat.
  - Linhas seguintes:
        - caracter a representar o comando utilizado
        - conteúdo da stackMat, matriz a matriz, lido usando a função leMatriz.
*/

void leStackMat(StackMat* s, FILE* fp){
    char temp;
    int i;

    //s->cabeca e s->tam
    leNumero(&s->cabeca, fp);
    leNumero(&s->tam, fp);

    if (s->cabeca <= -1 || s->tam <= 0){
        s->dados = NULL;
        s->comandos = NULL; 
        mensagens ("Erro: ficheiro não contém um histórico válido.");
    }

    s->comandos = realloc(s->comandos, sizeof(char)*s->tam);
    s->dados = realloc(s->dados, sizeof(Matriz) * s->tam);
    for (i=0; i<=s->cabeca; i++){
        //comando
        temp = fgetc(fp);
        s->comandos[i] = temp;
        temp = fgetc(fp);

        //matriz
        leMatriz(&s->dados[i], fp);
    }
}

/*
Lê um número qualquer de um ficheiro e guarda-o no int fornecido.
*/

void leNumero(int *x, FILE* fp) {
    *x = 0;
    int negativo = 0;
    char c = fgetc(fp);

    if (c == '-') {
        negativo = 1;
        c = fgetc(fp);
    }

    while (c >= '0' && c <= '9') {
        *x = (*x * 10) + (c - '0');
        c = fgetc(fp);
    }

    if (negativo) {
        *x = -*x;
    }
}
