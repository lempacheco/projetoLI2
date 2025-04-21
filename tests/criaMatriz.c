#include "include/criaMatriz.h"

Matriz criaMatriz (int linhas, int colunas, char elemMatriz[linhas][colunas]) {
    Matriz m; 
    m.L = linhas;  
    m.C = colunas;
    if(linhas==0||colunas==0){
        m.matriz = NULL;
        return m;
    }
    m.matriz = malloc(linhas * sizeof(char*));
    for (int i=0; i< linhas; i++) {
       m.matriz[i]= malloc(colunas * sizeof(char)); 
       for (int j=0; j< colunas; j++){
           m.matriz[i][j]=elemMatriz[i][j]; 
       }
    }

    return m; 
}

void comparaMatrizes(Matriz* m1, Matriz* m2){
    int i, j;
    CU_ASSERT_EQUAL(m1->L, m2->L); 
    CU_ASSERT_EQUAL(m1->C, m2->C);

    if (m1->matriz == NULL){
        CU_ASSERT_EQUAL(m1->matriz, m2->matriz);
    }else{
        for (i = 0; i < m1->L; i++) {
            for (j = 0; j < m1->C; j++) {
                CU_ASSERT_EQUAL(m1->matriz[i][j], m2->matriz[i][j]);
            }
        }
    }
}

StackMat criaStackMat (int cabeca, int tam, int linhas, int colunas, char arrDados[tam][linhas][colunas],char* comandos) {
    StackMat s;
    initStackMat(&s);
    s.cabeca = cabeca;  
    s.tam = tam;  

    s.dados = realloc(s.dados, tam * sizeof(Matriz));
    s.comandos = realloc(s.comandos, tam * sizeof(char));
    for (int i=0; i< tam; i++) {
       s.dados[i] = criaMatriz(linhas, colunas, arrDados[i]);
       s.comandos[i] = comandos[i];
    }

    return s; 
}

void comparaStackMats(StackMat* s1, StackMat* s2){
    int i;
    CU_ASSERT_EQUAL(s1->cabeca, s2->cabeca); 
    CU_ASSERT_EQUAL(s1->tam, s2->tam);

    for (i = 0; i < s1->tam; i++) {
        comparaMatrizes(&s1->dados[i], &s2->dados[i]);
    }
}

StackG criaStackG (int cabeca, int tam,int* jaExistia, int* lenNomes,char** nomesFicheiros, int linhas, int colunas, char arrDados[tam][linhas][colunas]) {
    StackG s;
    initStackG(&s);
    s.cabeca = cabeca;  
    s.tam = tam;   

    s.matrizes = malloc(tam * sizeof(Matriz));
    for (int i=0; i< tam; i++) {
       s.matrizes[i] = criaMatriz(linhas, colunas, arrDados[i]);
    }

    s.jaExistia = malloc(tam * sizeof(int));
    s.lenNomes = malloc( tam * sizeof(int));
    for (int i=0;i<tam;i++){
        s.jaExistia[i]=jaExistia[i];
        s.lenNomes[i]=lenNomes[i];
    }
    s.nomesFicheiros = malloc( tam * sizeof(char*));
    for (int i = 0; i < tam; i++) {
        s.nomesFicheiros[i] = malloc((lenNomes[i] + 1) * sizeof(char));
        strcpy(s.nomesFicheiros[i], nomesFicheiros[i]);
}


    return s; 
}

void comparaStackG(StackG* s1,StackG* s2){//nao dá para comparar matrizes já que não é colocado nenhum valor na matriz no push e no pop
    int i;
    CU_ASSERT_EQUAL(s1->cabeca, s2->cabeca); 
    CU_ASSERT_EQUAL(s1->tam, s2->tam);

    for (i=0;i<s1->tam;i++){
        CU_ASSERT_EQUAL(s1->jaExistia[i],s2->jaExistia[i]);
        CU_ASSERT_EQUAL(s1->lenNomes[i],s2->lenNomes[i]);
    }
    for(i=0;i<s1->tam;i++){
        CU_ASSERT_EQUAL(strcmp(s1->nomesFicheiros[i],s2->nomesFicheiros[i]),0);
    }
    
}