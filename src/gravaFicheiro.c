#include "../include/gravaFicheiro.h"

/* Guarda a matriz fornecida num ficheiro com nome especificado,
   criando o caminho como "lib/<nome>". O ficheiro é escrito no seguinte formato:
   
   - Primeira linha: <L> <C> (número de linhas e colunas, como caracteres).
   - Linhas seguintes: conteúdo da matriz, linha a linha. 
*/

int gravaFicheiro(char* nome, Matriz* m, StackMat* s){
    FILE* fp; 
    int r=0;
    int i=0; 

    fp = fopen(nome, "w");
    if (fp == NULL) {
        printf ("Erro ao abrir o ficheiro.");
        return 1; 
    }
    
    //matriz m
    if (gravaMatriz(m, fp)) return 1;

    //s->cabeca e s->tam
    if (fputc('\n', fp) == EOF) return 1;

    if (fputc(s->cabeca+'0', fp) == EOF) return 1;
    if (fputc(' ', fp) == EOF) return 1;
    if (fputc(s->tam+'0', fp) == EOF) return 1;
    if (fputc('\n', fp) == EOF) return 1;

    for (i=0; i<=s->cabeca; i++){
        //comando
        if (fputc(s->comandos[i], fp) == EOF) return 1;

        //matriz
        if (fputc('\n', fp) == EOF) return 1;
        if (gravaMatriz(&s->dados[i], fp)) return 1;

        if (fputc('\n', fp) == EOF) return 1;
    }

    fclose(fp);
    return r; 
}

int gravaMatriz(Matriz* m, FILE* fp){
    int i, j;

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

    return 0;
}