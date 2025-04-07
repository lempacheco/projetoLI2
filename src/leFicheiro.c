#include "../include/leFicheiro.h"
#include <ctype.h>


int leFicheiro(char nome[], Matriz *m) {
    FILE* fp; 
    char temp;  
    int r=0;
    int j=0,i=0;
    char caminho[50]; 

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
    
    while ((temp=fgetc(fp))!=EOF){
         
        if (temp == '\n') {
            i++, j=0;
        } else if (!(isspace(temp))) {
            m->matriz[i][j++] = temp;
        }
    }

    fclose(fp); 
    return r; 

}