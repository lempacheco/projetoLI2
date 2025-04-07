#include "../include/leFicheiro.h"

int leFicheiro(char nome[], int lenNome, Matriz *m) {
    FILE* fp; 
    char temp;  
    int r=0;
    int j=0,i=0;
    char* caminho = malloc(sizeof(char)*(lenNome+5));

    strcpy(caminho, "lib/");
    strcat(caminho, nome);  

    fp = fopen(caminho, "r"); 
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
    free(caminho);
    return r; 

}