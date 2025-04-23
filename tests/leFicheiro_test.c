#include "include/leFicheiro_test.h"

void testar_leFicheiro() {
    int i, j;

    //1
    Matriz m1;
    StackMat s1;
    int r1 = leFicheiro("lib/teste1.txt", "lib/history/teste1.txt", &m1, &s1);
    char matrizExpected1[5][5] = {  "ecAdc",
                                    "dcd#c",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};

    CU_ASSERT_EQUAL(r1, 0);
    CU_ASSERT_EQUAL(m1.L, 5);
    CU_ASSERT_EQUAL(m1.C, 5);
    for (i=0; i<m1.L; i++){
        for (j=0; j<m1.C; j++){ 
            CU_ASSERT_EQUAL(m1.matriz[i][j], matrizExpected1[i][j]);
        }
    }

    liberaMatriz(&m1);
    liberaStackMat(&s1);

    //2
    Matriz m2;
    StackMat s2;
    int r2 = leFicheiro("lib/elfjeiofheifhewofj.txt", "lib/history/elfjeiofheifhewofj.txt", &m2, &s2);

    CU_ASSERT_EQUAL(r2, 1);
} 