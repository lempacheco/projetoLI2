#include "include/leFicheiro_test.h"

void testar_leFicheiro() {
    int i, j;

    //1
    Matriz m1;
    int r1 = leFicheiro("exemplo.txt", &m1);
    char matrizExpected1[5][5] = {  "ecadc",
                                    "dcdec",
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

    for (i=0; i<m1.L; i++){
        free(m1.matriz[i]);
    }
    free(m1.matriz);

    //2
    Matriz m2;
    int r2 = leFicheiro("elfjeiofheifhewofj.txt", &m2);

    CU_ASSERT_EQUAL(r2, 1);
}