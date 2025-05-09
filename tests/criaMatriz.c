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

NodePosicao* criarListaCom(Pos posicoes[], int n) {
    NodePosicao* lista = NULL;
    for (int i = 0; i < n; i++) {
        lista = adicionarPos(lista, posicoes[i].l - 'a', posicoes[i].c - 1);
    }
    return lista;
}

Queue criaQueue(int tam, int cap,Pos* p){
    Queue q;
    q.cap = cap;
    q.tam = tam;
    q.inicio = 0;
    q.valores = malloc(sizeof(Pos) * cap);
    if (p==NULL){
        q.valores=NULL;
    }
    else{
        for (int i = 0; i < tam; i++) {
            q.valores[i] = p[i];
        }
    }
    return q;
}

void comparaQueue(Queue* q1,Queue* q2){
    int i;
    CU_ASSERT_EQUAL(q1->cap, q2->cap); 
    CU_ASSERT_EQUAL(q1->tam, q2->tam);
    CU_ASSERT_EQUAL(q1->inicio, q2->inicio);

    for (i=0;i<q1->tam;i++){
        CU_ASSERT_EQUAL(q1->valores[i].c,q2->valores[i].c);
        CU_ASSERT_EQUAL(q1->valores[i].l,q2->valores[i].l);
    }
}