#include "../include/leFicheiro.h"

/*  Lê o conteúdo de um ficheiro e carrega-o na matriz fornecida.

  O formato esperado do ficheiro é:
  - Primeira linha: dois dígitos separados por espaço, representando o número de linhas (L) e colunas (C) da matriz.
  - Linhas seguintes: caracteres da matriz, linha a linha.
*/

int leFicheiro(char* nome, Matriz *m) {
    FILE* fp; 
    char temp;  
    int j=0,i=0;

    fp = fopen(nome, "r");
    if (fp == NULL) {
        printf ("Erro ao abrir o ficheiro.");
        return 1; 
    } 

    temp = fgetc(fp); 
    m->L = temp - '0'; 
    temp = fgetc(fp); 
    temp = fgetc(fp);
    m->C = temp - '0'; 
    temp = fgetc(fp); 

    if (m->L <= 0 || m->C <= 0){
        m->matriz = NULL;
        printf ("Erro: ficheiro não contém uma matriz válida.");
        return -1;
    }
    
    m->matriz = malloc(sizeof(char*)*m->L);
    m->matriz[0] = malloc(sizeof(char)*m->C);
    while ((temp=fgetc(fp))!=EOF){
         
        if (temp == '\n') {
            i++, j=0;
            m->matriz[i] = malloc(sizeof(char)*m->C);
        } else if (!(isspace(temp))) {
            m->matriz[i][j++] = temp;
        }
    }

    fclose(fp); 
    return 0; 
}  