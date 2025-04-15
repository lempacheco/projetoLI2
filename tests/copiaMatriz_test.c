#include "include/copiaMatriz_test.h"


void testar_copiaMatriz () {
    int i, j;

    // 1
    Matriz m1,m2;
    char matriz1[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    m1.L = 5;
    m1.C = 5;
    m1.matriz = malloc(sizeof(char*) * m1.L);
    for (i = 0; i < m1.L; i++) {
        m1.matriz[i] = malloc(sizeof(char) * m1.C);
        for (j = 0; j < m1.C; j++) {
            m1.matriz[i][j] = matriz1[i][j];
        }
    }

    copiaMatriz(&m2,&m1);
    CU_ASSERT_EQUAL(m2.L, 5);
    CU_ASSERT_EQUAL(m2.C, 5);
    for (i = 0; i < m1.L; i++) {
        for (j = 0; j < m2.C; j++) {
            CU_ASSERT_EQUAL(m2.matriz[i][j], m1.matriz[i][j]);
        }
        free(m1.matriz[i]);
        free(m2.matriz[i]);
    }
    free(m1.matriz);
    free(m2.matriz);
}