#include "include/stackMats_test.h"


void testar_initStackMat() {
    Matriz mExpected = {0,0,NULL,NULL};

    //1
    StackMat s1;

    initStackMat(&s1);

    comparaMatrizes(&s1.dados[0], &mExpected);
    CU_ASSERT_EQUAL(s1.cabeca, -1);
    CU_ASSERT_EQUAL(s1.tam, 1);

    liberaStackMat(&s1);
}

void testar_initMatriz(){
    Matriz mExpected = {0,0,NULL,NULL};

    //1
    Matriz m1;

    initMatriz(&m1);
    comparaMatrizes(&m1, &mExpected);
    CU_ASSERT_EQUAL(m1.matriz, mExpected.matriz);

    liberaMatriz(&m1);
}

void testar_push(){
    //1 - stack com elementos e matriz com elementos
    char dadosMatrizes[2][5][5] = {
        {
        "ecadc",
        "dcdec",
        "bddce",
        "cedeb",
        "accbb"
        },
        {
        "ecadc",
        "dcdec",
        "bddce",
        "c#deb",
        "accbb"
        }
    };

    char comandos[2]={'b','r'};

    StackMat s1 = criaStackMat(1, 2, 5, 5, dadosMatrizes,comandos);
    StackMat s2 = criaStackMat(1, 2, 5, 5, dadosMatrizes,comandos);

    char matriz1[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "c#d#b",
        "accbb"
    };
    Matriz m1 = criaMatriz(5, 5, matriz1);

    push(&s1, &m1,'b');

    comparaMatrizes(&s1.dados[0], &s2.dados[0]);
    comparaMatrizes(&s1.dados[1], &s2.dados[1]);
    comparaMatrizes(&s1.dados[2], &m1);
    CU_ASSERT_EQUAL(s1.comandos[0],'b');
    CU_ASSERT_EQUAL(s1.comandos[1],'r');
    CU_ASSERT_EQUAL(s1.comandos[2],'b');
    CU_ASSERT_EQUAL(s1.cabeca, 2);
    CU_ASSERT_EQUAL(s1.tam, 3);

    liberaStackMat(&s1);
    liberaStackMat(&s2);

    //2 - stack vazia e matriz com elementos
    StackMat s3;
    initStackMat(&s3);

    push(&s3, &m1,'b');

    comparaMatrizes(&s3.dados[0], &m1);
    CU_ASSERT_EQUAL(s3.comandos[0],'b');
    CU_ASSERT_EQUAL(s3.cabeca, 0);
    CU_ASSERT_EQUAL(s3.tam, 1);

    liberaMatriz(&m1);
    liberaStackMat(&s3);

    //3 - stack com elementos e matriz vazia
    StackMat s4 = criaStackMat(1, 2, 5, 5, dadosMatrizes, comandos);
    StackMat s5 = criaStackMat(1, 2, 5, 5, dadosMatrizes, comandos);

    Matriz m2;
    initMatriz(&m2);

    push(&s4, &m2,'b');

    comparaMatrizes(&s4.dados[2], &m2);
    CU_ASSERT_EQUAL(s4.comandos[2],'b');
    CU_ASSERT_EQUAL(s4.cabeca, 2);
    CU_ASSERT_EQUAL(s4.tam, 3);

    liberaStackMat(&s4);
    liberaStackMat(&s5);

    //4 - stack vazia e matriz vazia
    StackMat s6;
    initStackMat(&s6);

    push(&s6, &m2,'b');

    comparaMatrizes(&s6.dados[0], &m2);
    CU_ASSERT_EQUAL(s6.comandos[0],'b');
    CU_ASSERT_EQUAL(s6.cabeca, 0);
    CU_ASSERT_EQUAL(s6.tam, 1);

    liberaMatriz(&m2);
    liberaStackMat(&s6);
}



void testar_pop(){
    //1 - stack com elementos e matriz com elementos
    char dadosMatrizes[2][5][5] = {
        {
        "ecadc",
        "dcdec",
        "bddce",
        "cedeb",
        "accbb"
        },
        {
        "ecadc",
        "dcdec",
        "bddce",
        "c#deb",
        "accbb"
        }
    };

    char comandos[2]={'b', 'r'};

    StackMat s1 = criaStackMat(1, 2, 5, 5, dadosMatrizes, comandos);
    StackMat s2 = criaStackMat(1, 2, 5, 5, dadosMatrizes, comandos);

    Matriz m1;
    int r1 = pop(&s1, &m1);

    comparaMatrizes(&s1.dados[0], &s2.dados[0]);
    comparaMatrizes(&m1, &s2.dados[1]);
    CU_ASSERT_EQUAL(s1.comandos[0], 'b');
    CU_ASSERT_EQUAL(s1.cabeca, 0);
    CU_ASSERT_EQUAL(s1.tam, 2);
    CU_ASSERT_EQUAL(r1, 0);

    liberaMatriz(&m1);
    liberaStackMat(&s1);
    liberaStackMat(&s2);

    //2 - stack com elementos e matriz vazia
    StackMat s3 = criaStackMat(1, 2, 5, 5, dadosMatrizes, comandos);
    StackMat s4 = criaStackMat(1, 2, 5, 5, dadosMatrizes, comandos);

    Matriz m2;
    initMatriz(&m2);

    push(&s3, &m2,'b');

    Matriz m3;
    int r2 = pop(&s3, &m3);

    comparaMatrizes(&s3.dados[0], &s4.dados[0]);
    comparaMatrizes(&s3.dados[1], &s4.dados[1]);
    comparaMatrizes(&m3, &m2);
    CU_ASSERT_EQUAL(s3.comandos[0],s4.comandos[0]);
    CU_ASSERT_EQUAL(s3.comandos[1],s4.comandos[1]);
    CU_ASSERT_EQUAL(s3.cabeca, 1);
    CU_ASSERT_EQUAL(s3.tam, 3);
    CU_ASSERT_EQUAL(r2, 0);

    liberaMatriz(&m2);
    liberaMatriz(&m3);
    liberaStackMat(&s3);
    liberaStackMat(&s4);

    //3 - stack vazia
    StackMat s5;
    initStackMat(&s5);

    Matriz m4;
    int r3 = pop(&s5, &m4);

    CU_ASSERT_EQUAL(s5.cabeca, -1);
    CU_ASSERT_EQUAL(s5.tam, 1);
    CU_ASSERT_EQUAL(r3, -1);

    liberaStackMat(&s5);
}

void testar_isFull () {
    // 1
    Matriz m1;
    StackMat S1;
    int r1;
    char matriz1[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    m1=criaMatriz(5,5,matriz1);
    initStackMat(&S1);
    push(&S1,&m1,'b');
    r1=isFull(&S1);
    CU_ASSERT_EQUAL(r1, 1);
    liberaMatriz(&m1);
    liberaStackMat(&S1);

    // 2
    StackMat S2;
    int r2;
    initStackMat(&S2);
    r2=isFull(&S2);
    CU_ASSERT_EQUAL(r2, 0);
    liberaStackMat(&S2);
}

void testar_isEmpty () {
    // 1
    Matriz m1;
    StackMat S1;
    int r1;
    char matriz1[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    m1=criaMatriz(5,5,matriz1);
    initStackMat(&S1);
    push(&S1,&m1,'b');
    r1=isEmpty(&S1);
    CU_ASSERT_EQUAL(r1, 0);
    liberaMatriz(&m1);
    liberaStackMat(&S1);

    // 2
    StackMat S2;
    int r2;
    initStackMat(&S2);
    r2=isEmpty(&S2);
    CU_ASSERT_EQUAL(r2, 1);
    liberaStackMat(&S2);
}

void testar_copiaMatriz () {
    int i, j;

    // 1
    Matriz m1i,m1f;
    char matriz1i[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    m1i=criaMatriz(5,5,matriz1i);
    copiaMatriz(&m1f,&m1i);
    CU_ASSERT_EQUAL(m1f.L, 5);
    CU_ASSERT_EQUAL(m1f.C, 5);
    for (i = 0; i < m1f.L; i++) {
        for (j = 0; j < m1f.C; j++) {
            CU_ASSERT_EQUAL(m1f.matriz[i][j], m1i.matriz[i][j]);
        }
    }
    liberaMatriz(&m1i);
    liberaMatriz(&m1f);

    // 2
    Matriz m2i ,m2f;
    m2i=criaMatriz(0,0,matriz1i);
    copiaMatriz(&m2f,&m2i);
    CU_ASSERT_EQUAL(m2f.L, 0);
    CU_ASSERT_EQUAL(m2f.C, 0);
    CU_ASSERT_PTR_NULL(m2f.matriz);
    liberaMatriz(&m2i);
    liberaMatriz(&m2f);

    // 3
    Matriz m3i,m3f;
    char matriz3i[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    
    char matriz3f[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    m3i=criaMatriz(5,5,matriz3i);
    m3f=criaMatriz(5,5,matriz3f);
    copiaMatriz(&m3f,&m3i);
    CU_ASSERT_EQUAL(m3f.L, 5);
    CU_ASSERT_EQUAL(m3f.C, 5);
    for (i = 0; i < m3f.L; i++) {
        for (j = 0; j < m3f.C; j++) {
            CU_ASSERT_EQUAL(m3f.matriz[i][j], m3i.matriz[i][j]);
        }
    }
    liberaMatriz(&m3i);
    liberaMatriz(&m3f);

    // 4
    Matriz m4i,m4f;
    char matriz4i[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    
    char matriz4f[6][6] = {
        "ecAdca",
        "dcd#ca",
        "bddcea",
        "cdeeba",
        "accbba"
    };
    m4i=criaMatriz(5,5,matriz4i);
    m4f=criaMatriz(6,6,matriz4f);
    copiaMatriz(&m4f,&m4i);
    CU_ASSERT_EQUAL(m4f.L, 5);
    CU_ASSERT_EQUAL(m4f.C, 5);
    for (i = 0; i < m4f.L; i++) {
        for (j = 0; j < m4f.C; j++) {
            CU_ASSERT_EQUAL(m4f.matriz[i][j], m4i.matriz[i][j]);
        }
    }
    liberaMatriz(&m4i);
    liberaMatriz(&m4f);

    // 5
    Matriz m5i,m5f;
    char matriz5i[6][6] = {
        "ecAdca",
        "dcd#ca",
        "bddcea",
        "cdeeba",
        "accbba"
    };
    
    char matriz5f[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    m5i=criaMatriz(6,6,matriz5i);
    m5f=criaMatriz(5,5,matriz5f);
    copiaMatriz(&m5f,&m5i);
    CU_ASSERT_EQUAL(m5f.L, 6);
    CU_ASSERT_EQUAL(m5f.C, 6);
    for (i = 0; i < m5f.L; i++) {
        for (j = 0; j < m5f.C; j++) {
            CU_ASSERT_EQUAL(m5f.matriz[i][j], m5i.matriz[i][j]);
        }
    }
    liberaMatriz(&m5i);
    liberaMatriz(&m5f);

    // 6
    Matriz m6i,m6f;
    char matriz6i[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    
    char matriz6f[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    m6i=criaMatriz(5,5,matriz6i);
    m6f=criaMatriz(5,5,matriz6f);
    copiaMatriz(&m6f,&m6i);
    CU_ASSERT_EQUAL(m6f.L, 5);
    CU_ASSERT_EQUAL(m6f.C, 5);
    for (i = 0; i < m6f.L; i++) {
        for (j = 0; j < m6f.C; j++) {
            CU_ASSERT_EQUAL(m6f.matriz[i][j], m6i.matriz[i][j]);
        }
    }
    liberaMatriz(&m6i);
    liberaMatriz(&m6f);
} 