#include "../include/leFicheiro.h"

/*  Lê o conteúdo de um ficheiro e carrega-o na matriz fornecida.

  O formato esperado do ficheiro é:
  - Primeira linha: dois dígitos separados por espaço, representando o número de linhas (L) e colunas (C) da matriz.
  - Linhas seguintes: caracteres da matriz, linha a linha.
*/

int leFicheiro(char* nomeMatriz, char* nomeStackMat, Matriz *m, StackMat* s) {
    FILE* fpM;
    FILE* fpS;   
    int r=0;

    //matriz
    fpM = fopen(nomeMatriz, "r");
    if (fpM == NULL) {
        printf ("Erro ao abrir o ficheiro.");
        return 1; 
    }

    if (m->matriz != NULL) liberaMatriz(m);
    
    leMatriz(m, fpM);
    fclose(fpM); 

    //stackMat
    if ((fpS = fopen(nomeStackMat, "r"))) //o ficheiro já existe
    {
        if (s->tam != 0){
            liberaStackMat(s);
            initStackMat(s);
        }
        leStackMat(s, fpS);
        fclose(fpS);
    }else{//o ficheiro não existe
        initStackMat(s);
    }

    return r; 
}  

void leMatriz(Matriz* m, FILE* fp){
    int i, j;
    char temp = fgetc(fp);

    m->L = 0;
    m->C = 0;
    for (i=0; temp != ' ' && temp != '\n'; i++){
        m->L += (temp-'0')*pow(10,i);
        temp = fgetc(fp);
    }
    temp = fgetc(fp);
    for (i=0; temp != ' ' && temp != '\n'; i++){
        m->C += (temp-'0')*pow(10,i);
        temp = fgetc(fp);
    }

    if (m->L <= 0 || m->C <= 0){
        m->matriz = NULL;
        printf ("Erro: ficheiro não contém uma matriz válida.");
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

void leStackMat(StackMat* s, FILE* fp){
    char temp;
    int i;

    //s->cabeca e s->tam
    s->cabeca = 0;
    s->tam = 0;
    temp = fgetc(fp);
    for (i=0; temp != ' ' && temp != '\n'; i++){
        if (temp == '-'){
            s->cabeca = -1;
            temp = ' '; //cabeca fica com o valor -1
        }
        else {
            s->cabeca += (temp-'0')*pow(10,i);
            temp = fgetc(fp);
        }
    }
    temp = fgetc(fp);
    for (i=0; temp != ' ' && temp != '\n'; i++){
        s->tam += (temp-'0')*pow(10,i);
        temp = fgetc(fp);
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