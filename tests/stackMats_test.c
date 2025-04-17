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

    comparaMatrizes(&s4.dados[0], &m1);
    CU_ASSERT_EQUAL(s4.cabeca, 0);
    CU_ASSERT_EQUAL(s4.tam, 1);

    liberaMatriz(&m2);
    liberaStackMat(&s4);
    liberaStackMat(&s5);
}

void testar_pop(){}