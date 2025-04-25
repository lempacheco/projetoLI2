#include "../include/gravaFicheiro.h"
#include<ncurses.h>

/* Guarda a matriz fornecida num ficheiro com nome especificado,
   criando o caminho como "lib/<nome>". O ficheiro é escrito no seguinte formato:
   
   - Primeira linha: <L> <C> (número de linhas e colunas, como caracteres).
   - Linhas seguintes: conteúdo da matriz, linha a linha. 
*/

int gravaFicheiro(char* nomeM, char* nomeS, Matriz* m, StackMat* s){
    FILE* fpM; 
    FILE* fpS;
    int r=0;

    //matriz
    fpM = fopen(nomeM, "w");
    if (fpM == NULL) {
        mensagens("Erro ao abrir o ficheiro.");
        return -1; 
    }
    
    if (gravaMatriz(m, fpM)) return -1;
    fclose(fpM);

    //stackMat
    fpS = fopen(nomeS, "w");
    if (fpS == NULL) {
        mensagens("Erro ao abrir o ficheiro.");
        return -1; 
    }

    if (gravaStackMat(s,fpS)) return -1;
    fclose(fpS);
    
    return r; 
}

int gravaMatriz(Matriz* m, FILE* fp){
    int i, j;

    if (fprintf(fp, "%d %d\n", m->L, m->C) < 0) return 1; 

    for (i=0; i<m->L; i++){
        for (j=0; j<m->C; j++){
            if (fputc(m->matriz[i][j], fp) == EOF) return 1;
        }
        if (i != m->L-1)
            if (fputc('\n', fp) == EOF) return 1;
    }

    return 0;
}

int gravaStackMat(StackMat* s, FILE* fp){
    int i;

    //s->cabeca e s->tam
    if (fprintf (fp, "%d %d\n", s->cabeca, s->tam) < 0) return 1;

    for (i=0; i <= s->cabeca; i++){
        //comando
        if (fputc(s->comandos[i], fp) == EOF) return 1;

        //matriz
        if (fputc('\n', fp) == EOF) return 1;
        if (gravaMatriz(&s->dados[i], fp)) return 1;

        if (fputc('\n', fp) == EOF) return 1;
    }

    return 0;
} 