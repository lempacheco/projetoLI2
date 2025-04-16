#include "include/isStack_test.h"


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
    push(&S1,&m1);
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
    push(&S1,&m1);
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