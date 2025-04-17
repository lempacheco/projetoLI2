#include "include/copiaMatriz_test.h"


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