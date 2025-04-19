#include "../include/gravaFicheiro.h"

/* Guarda a matriz fornecida num ficheiro com nome especificado,
   criando o caminho como "lib/<nome>". O ficheiro é escrito no seguinte formato:
   
   - Primeira linha: <L> <C> (número de linhas e colunas, como caracteres).
   - Linhas seguintes: conteúdo da matriz, linha a linha. 
*/

int gravaFicheiro(char* nome, Matriz* m){
    FILE* fp; 
    int r=0;
    int j=0,i=0; 

    fp = fopen(nome, "w");
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
    return r; 
}

void existeFicheiro(char* nomeFile, int lenNome, StackG* sg){
    FILE* fp;
    char* temp = malloc(sizeof(char));
    if ((fp = fopen(nomeFile, "r")) != NULL){//o ficheiro existe
        if (fgets(temp, 1, fp) != NULL){//tinha algo dentro do ficheiro
            pushG(sg, 2, nomeFile, lenNome);//esta funçao já incrementa o sg->cabeca
            leFicheiro(nomeFile, &sg->matrizes[sg->cabeca]); //guarda a matriz que estava no ficheiro
        }/* else{//não tinha nada dentro do ficheiro
            pushG(sg, 1, nomeFile, lenNome);//esta funçao já incrementa o sg->cabeca
            initMatriz(&sg->matrizes[sg->cabeca]);
        } */
        fclose(fp);
    }else{//o ficheiro não existe
        pushG(sg, 0, nomeFile, lenNome);
        initMatriz(&sg->matrizes[sg->cabeca]);
    }

    free(temp);
}

void retrocedeG(StackG* sg){    
    if (sg->jaExistia[sg->cabeca] == 2){
        gravaFicheiro(sg->nomesFicheiros[sg->cabeca], &sg->matrizes[sg->cabeca]);
    }/* else if (sg->jaExistia[sg->cabeca] == 1){
        FILE* fp = fopen(sg->nomesFicheiros[sg->cabeca], "w"); //automaticamente apaga os conteudos do ficheiro
        fclose(fp);
    } */else{
        if (remove(sg->nomesFicheiros[sg->cabeca])){
            printf("Erro: ficheiro não removido.");
        }
    }

    popG(sg);
}