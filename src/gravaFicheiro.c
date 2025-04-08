#include "../include/gravaFicheiro.h"

int gravaFicheiro(char* nome, int lenNome, Matriz* m){
    FILE* fp; 
    int r=0;
    int j=0,i=0;
    char* caminho = malloc(sizeof(char)*(lenNome+5));

    strcpy(caminho, "lib/");
    strcat(caminho, nome);  

    fp = fopen(caminho, "w");
    if (fp == NULL) {
        printf ("Erro ao abrir o ficheiro.");
        return 1; 
    }
    
    if (fputc(m->L+'0', fp) == EOF) return 1;
    if (fputc(' ', fp) == EOF) return 1;
    if (fputc(m->C+'0', fp) == EOF) return 1;
    if (fputc('\n', fp) == EOF) return 1;

    for (i=0; i<m->L; i++){
        for (j=0; j<m->C; j++){
            if (fputc(m->matriz[i][j], fp) == EOF) return 1;
        }
        if (i != m->L-1)
            if (fputc('\n', fp) == EOF) return 1;
    }

    fclose(fp); 
    free(caminho);
    return r; 
}