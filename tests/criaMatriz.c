#include "include/criaMatriz.h"

Matriz criaMatriz (int linhas, int colunas, char elemMatriz[linhas][colunas]) {
    Matriz m; 
    m.L = linhas;  
    m.C = colunas;  

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

StackMat criaStackMat (int cabeca, int tam, int linhas, int colunas, char arrDados[tam][linhas][colunas]) {
    StackMat s;
    initStackMat(&s);
    s.cabeca = cabeca;  
    s.tam = tam;  

    s.dados = realloc(s.dados, tam * sizeof(Matriz));
    for (int i=0; i< tam; i++) {
       s.dados[i] = criaMatriz(linhas, colunas, arrDados[i]);
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