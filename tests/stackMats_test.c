#include "include/stackMats_test.h"

void testar_initStackMat() {
    Matriz mExpected = {0,0,NULL};

    //1
    StackMat s1;

    initStackMat(&s1);

    comparaMatrizes(&s1.dados[0], &mExpected);
    CU_ASSERT_EQUAL(s1.cabeca, -1);
    CU_ASSERT_EQUAL(s1.tam, 1);

    liberaStackMat(&s1);
}

void testar_initMatriz(){
    Matriz mExpected = {0,0,NULL};

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

    StackMat s1 = criaStackMat(1, 2, 5, 5, dadosMatrizes);
    StackMat s2 = criaStackMat(1, 2, 5, 5, dadosMatrizes);

    char matriz1[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "c#d#b",
        "accbb"
    };
    Matriz m1 = criaMatriz(5, 5, matriz1);

    push(&s1, &m1);

    comparaMatrizes(&s1.dados[0], &s2.dados[0]);
    comparaMatrizes(&s1.dados[1], &s2.dados[1]);
    comparaMatrizes(&s1.dados[2], &m1);
    CU_ASSERT_EQUAL(s1.cabeca, 2);
    CU_ASSERT_EQUAL(s1.tam, 3);

    liberaStackMat(&s1);
    liberaStackMat(&s2);

    //2 - stack vazia e matriz com elementos
    StackMat s3;
    initStackMat(&s3);

    push(&s3, &m1);

    comparaMatrizes(&s3.dados[0], &m1);
    CU_ASSERT_EQUAL(s3.cabeca, 0);
    CU_ASSERT_EQUAL(s3.tam, 1);

    liberaMatriz(&m1);
    liberaStackMat(&s3);

    //3 - stack com elementos e matriz vazia
    StackMat s4 = criaStackMat(1, 2, 5, 5, dadosMatrizes);
    StackMat s5 = criaStackMat(1, 2, 5, 5, dadosMatrizes);

    Matriz m2;
    initMatriz(&m2);

    push(&s4, &m2);

    comparaMatrizes(&s4.dados[2], &m2);
    CU_ASSERT_EQUAL(s4.cabeca, 2);
    CU_ASSERT_EQUAL(s4.tam, 3);

    liberaStackMat(&s4);
    liberaStackMat(&s5);

    //4 - stack vazia e matriz vazia
    StackMat s6;
    initStackMat(&s6);

    push(&s6, &m2);

    comparaMatrizes(&s6.dados[0], &m2);
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

    StackMat s1 = criaStackMat(1, 2, 5, 5, dadosMatrizes);
    StackMat s2 = criaStackMat(1, 2, 5, 5, dadosMatrizes);

    Matriz m1;
    int r1 = pop(&s1, &m1);

    comparaMatrizes(&s1.dados[0], &s2.dados[0]);
    comparaMatrizes(&m1, &s2.dados[1]);
    CU_ASSERT_EQUAL(s1.cabeca, 0);
    CU_ASSERT_EQUAL(s1.tam, 2);
    CU_ASSERT_EQUAL(r1, 0);

    liberaMatriz(&m1);
    liberaStackMat(&s1);
    liberaStackMat(&s2);

    //2 - stack com elementos e matriz vazia
    StackMat s3 = criaStackMat(1, 2, 5, 5, dadosMatrizes);
    StackMat s4 = criaStackMat(1, 2, 5, 5, dadosMatrizes);

    Matriz m2;
    initMatriz(&m2);

    push(&s3, &m2);

    Matriz m3;
    int r2 = pop(&s3, &m3);

    comparaMatrizes(&s3.dados[0], &s4.dados[0]);
    comparaMatrizes(&s3.dados[1], &s4.dados[1]);
    comparaMatrizes(&m3, &m2);
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

    liberaStackMat(&s4);
    liberaStackMat(&s5);
}