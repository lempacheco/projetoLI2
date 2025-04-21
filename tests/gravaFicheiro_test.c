#include "include/gravaFicheiro_test.h"


void testar_gravaFicheiro() {
    int i, j;

    // 1
    Matriz m1;
    char matrizExpected1[5][5] = {
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
            m1.matriz[i][j] = matrizExpected1[i][j];
        }
    }


    int r1 = gravaFicheiro("teste1.txt", &m1);
    CU_ASSERT_EQUAL(r1, 0);
    
    for (i = 0; i < m1.L; i++) {
        for (j = 0; j < m1.C; j++) {
            CU_ASSERT_EQUAL(m1.matriz[i][j], matrizExpected1[i][j]);
        }
        free(m1.matriz[i]);
    }
    free(m1.matriz);
    
    leFicheiro("teste1.txt", &m1);
    CU_ASSERT_EQUAL(m1.L, 5);
    CU_ASSERT_EQUAL(m1.C, 5);
    for (i = 0; i < m1.L; i++) {
        for (j = 0; j < m1.C; j++) {
            CU_ASSERT_EQUAL(m1.matriz[i][j], matrizExpected1[i][j]);
        }
        free(m1.matriz[i]);
    }
    free(m1.matriz);


    // 2
    Matriz m2;
    char matrizExpected2[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    m2.L = 5;
    m2.C = 5;
    m2.matriz = malloc(sizeof(char*) * m2.L);
    for (i = 0; i < m2.L; i++) {
        m2.matriz[i] = malloc(sizeof(char) * m2.C);
        for (j = 0; j < m2.C; j++) {
            m2.matriz[i][j] = matrizExpected2[i][j];
        }
    }


    int r2 = gravaFicheiro("teste2.txt", &m2);
    CU_ASSERT_EQUAL(r2, 0);
    
    for (i = 0; i < m2.L; i++) {
        for (j = 0; j < m2.C; j++) {
            CU_ASSERT_EQUAL(m2.matriz[i][j], matrizExpected2[i][j]);
        }
        free(m2.matriz[i]);
    }
    free(m2.matriz);
    
    leFicheiro("teste2.txt", &m2);
    CU_ASSERT_EQUAL(m2.L, 5);
    CU_ASSERT_EQUAL(m2.C, 5);
    for (i = 0; i < m2.L; i++) {
        for (j = 0; j < m2.C; j++) {
            CU_ASSERT_EQUAL(m2.matriz[i][j], matrizExpected2[i][j]);
        }
        free(m2.matriz[i]);
    }
    free(m2.matriz);


    // 3
    Matriz m3;
    char matrizExpected3[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    m3.L = 5;
    m3.C = 5;
    m3.matriz = malloc(sizeof(char*) * m3.L);
    for (i = 0; i < m3.L; i++) {
        m3.matriz[i] = malloc(sizeof(char) * m3.C);
        for (j = 0; j < m3.C; j++) {
            m3.matriz[i][j] = matrizExpected3[i][j];
        }
    }


    int r3 = gravaFicheiro("teste3.txt", &m3);
    CU_ASSERT_EQUAL(r3, 0);
    
    for (i = 0; i < m3.L; i++) {
        for (j = 0; j < m3.C; j++) {
            CU_ASSERT_EQUAL(m3.matriz[i][j], matrizExpected3[i][j]);
        }
        free(m3.matriz[i]);
    }
    free(m3.matriz);
    
    leFicheiro("teste3.txt", &m3);
    CU_ASSERT_EQUAL(m3.L, 5);
    CU_ASSERT_EQUAL(m3.C, 5);
    for (i = 0; i < m3.L; i++) {
        for (j = 0; j < m3.C; j++) {
            CU_ASSERT_EQUAL(m3.matriz[i][j], matrizExpected3[i][j]);
        }
        free(m3.matriz[i]);
    }
    free(m3.matriz);

    // 4
    Matriz m4;
    char matrizExpected4[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    m4.L = 5;
    m4.C = 5;
    m4.matriz = malloc(sizeof(char*) * m4.L);
    for (i = 0; i < m4.L; i++) {
        m4.matriz[i] = malloc(sizeof(char) * m4.C);
        for (j = 0; j < m4.C; j++) {
            m4.matriz[i][j] = matrizExpected4[i][j];
        }
    }


    int r4 = gravaFicheiro("teste4.txt", &m4);
    CU_ASSERT_EQUAL(r4, 0);
    
    for (i = 0; i < m4.L; i++) {
        for (j = 0; j < m4.C; j++) {
            CU_ASSERT_EQUAL(m4.matriz[i][j], matrizExpected4[i][j]);
        }
        free(m4.matriz[i]);
    }
    free(m4.matriz);
    
    leFicheiro("teste4.txt", &m4);
    CU_ASSERT_EQUAL(m4.L, 5);
    CU_ASSERT_EQUAL(m4.C, 5);
    for (i = 0; i < m4.L; i++) {
        for (j = 0; j < m4.C; j++) {
            CU_ASSERT_EQUAL(m4.matriz[i][j], matrizExpected4[i][j]);
        }
        free(m4.matriz[i]);
    }
    free(m4.matriz);


    // 5
    Matriz m5;
    char matrizExpected5[9][9] = {
        "idaeegfgb",
        "hicidebgf",
        "gbadhbafe",
        "iafibhged",
        "dggfabbhc",
        "ecbgcfifd",
        "dfefgibab",
        "feghagcgi",
        "bghedadib"
    };
    m5.L = 9;
    m5.C = 9;
    m5.matriz = malloc(sizeof(char*) * m5.L);
    for (i = 0; i < m5.L; i++) {
        m5.matriz[i] = malloc(sizeof(char) * m5.C);
        for (j = 0; j < m5.C; j++) {
            m5.matriz[i][j] = matrizExpected5[i][j];
        }
    }


    int r5 = gravaFicheiro("teste5.txt", &m5);
    CU_ASSERT_EQUAL(r5, 0);
    
    for (i = 0; i < m5.L; i++) {
        for (j = 0; j < m5.C; j++) {
            CU_ASSERT_EQUAL(m5.matriz[i][j], matrizExpected5[i][j]);
        }
        free(m5.matriz[i]);
    }
    free(m5.matriz);

    leFicheiro("teste5.txt", &m5);
    CU_ASSERT_EQUAL(m5.L, 9);
    CU_ASSERT_EQUAL(m5.C, 9);
    for (i = 0; i < m5.L; i++) {
        for (j = 0; j < m5.C; j++) {
            CU_ASSERT_EQUAL(m5.matriz[i][j], matrizExpected5[i][j]);
        }
        free(m5.matriz[i]);
    }
    free(m5.matriz);

}