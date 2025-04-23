#include "include/gravaFicheiro_test.h"


void testar_gravaFicheiro() {
    int i, j;

    // 1
    Matriz m1, m1Stack;
    StackMat s1;
    initStackMat(&s1);
    char matrizExpected1[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    m1 = criaMatriz(5,5,matrizExpected1);
    m1Stack = criaMatriz(5,5,matrizExpected1);
    push(&s1, &m1Stack, 'b');


    int r1 = gravaFicheiro("lib/teste1.txt", "lib/history/teste1.txt", &m1, &s1);
    CU_ASSERT_EQUAL(r1, 0);
    
    for (i = 0; i < m1.L; i++) {
        for (j = 0; j < m1.C; j++) {
            CU_ASSERT_EQUAL(m1.matriz[i][j], matrizExpected1[i][j]);
        }
    }
    liberaMatriz(&m1);
    liberaMatriz(&m1Stack);
    liberaStackMat(&s1);
    initStackMat(&s1);
    leFicheiro("lib/teste1.txt", "lib/history/teste1.txt", &m1, &s1);
    CU_ASSERT_EQUAL(m1.L, 5);
    CU_ASSERT_EQUAL(m1.C, 5);
    for (i = 0; i < m1.L; i++) {
        for (j = 0; j < m1.C; j++) {
            CU_ASSERT_EQUAL(m1.matriz[i][j], matrizExpected1[i][j]);
        }
    }
    liberaMatriz(&m1);
    liberaStackMat(&s1);


    // 2
    Matriz m2, m2Stack;
    StackMat s2;
    initStackMat(&s2);
    char matrizExpected2[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    m2 = criaMatriz(5,5,matrizExpected2);
    m2Stack = criaMatriz(5,5,matrizExpected2);
    
    push(&s2, &m2Stack, 'b');


    int r2 = gravaFicheiro("lib/teste2.txt", "lib/history/teste2.txt", &m2, &s2);
    CU_ASSERT_EQUAL(r2, 0);
    
    for (i = 0; i < m2.L; i++) {
        for (j = 0; j < m2.C; j++) {
            CU_ASSERT_EQUAL(m2.matriz[i][j], matrizExpected2[i][j]);
        }
    }
    liberaMatriz(&m2);
    liberaMatriz(&m2Stack);
    liberaStackMat(&s2);
    initStackMat(&s2);
    leFicheiro("lib/teste2.txt", "lib/history/teste2.txt", &m2, &s2);
    CU_ASSERT_EQUAL(m2.L, 5);
    CU_ASSERT_EQUAL(m2.C, 5);
    for (i = 0; i < m2.L; i++) {
        for (j = 0; j < m2.C; j++) {
            CU_ASSERT_EQUAL(m2.matriz[i][j], matrizExpected2[i][j]);
        }
    }
    liberaMatriz(&m2);
    liberaStackMat(&s2);


    // 3
    Matriz m3, m3Stack;
    StackMat s3;
    initStackMat(&s3);
    char matrizExpected3[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    m3 = criaMatriz(5,5,matrizExpected3);
    m3Stack = criaMatriz(5,5,matrizExpected3);
    push(&s3,&m3Stack,'b');

    int r3 = gravaFicheiro("lib/teste3.txt", "lib/history/teste3.txt", &m3, &s3);
    CU_ASSERT_EQUAL(r3, 0);
    
    for (i = 0; i < m3.L; i++) {
        for (j = 0; j < m3.C; j++) {
            CU_ASSERT_EQUAL(m3.matriz[i][j], matrizExpected3[i][j]);
        }
    }
    liberaMatriz(&m3);
    liberaMatriz(&m3Stack);
    liberaStackMat(&s3);
    initStackMat(&s3);
    leFicheiro("lib/teste3.txt", "lib/history/teste3.txt", &m3, &s3);
    CU_ASSERT_EQUAL(m3.L, 5);
    CU_ASSERT_EQUAL(m3.C, 5);
    for (i = 0; i < m3.L; i++) {
        for (j = 0; j < m3.C; j++) {
            CU_ASSERT_EQUAL(m3.matriz[i][j], matrizExpected3[i][j]);
        }
    }
    liberaMatriz(&m3);
    liberaStackMat(&s3);

    // 4
    Matriz m4,m4Stack;
    StackMat s4;
    initStackMat(&s4);
    char matrizExpected4[5][5] = {
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"
    };
    m4 = criaMatriz(5,5,matrizExpected4);
    m4Stack = criaMatriz(5,5,matrizExpected4);
    push(&s4,&m4Stack,'b');

    int r4 = gravaFicheiro("lib/teste4.txt", "lib/history/teste4.txt", &m4, &s4);
    CU_ASSERT_EQUAL(r4, 0);
    
    for (i = 0; i < m4.L; i++) {
        for (j = 0; j < m4.C; j++) {
            CU_ASSERT_EQUAL(m4.matriz[i][j], matrizExpected4[i][j]);
        }
    }
    liberaMatriz(&m4);
    liberaMatriz(&m4Stack);
    liberaStackMat(&s4);
    initStackMat(&s4);
    leFicheiro("lib/teste4.txt", "lib/history/teste4.txt", &m4, &s4);
    CU_ASSERT_EQUAL(m4.L, 5);
    CU_ASSERT_EQUAL(m4.C, 5);
    for (i = 0; i < m4.L; i++) {
        for (j = 0; j < m4.C; j++) {
            CU_ASSERT_EQUAL(m4.matriz[i][j], matrizExpected4[i][j]);
        }
    }
    liberaMatriz(&m4);
    liberaStackMat(&s4);


    // 5
    Matriz m5,m5Stack;
    StackMat s5;
    initStackMat(&s5);
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
    m5 = criaMatriz(9,9,matrizExpected5);
    m5Stack = criaMatriz(9,9,matrizExpected5);
    push(&s5, &m5Stack, 'b');


    int r5 = gravaFicheiro("lib/teste5.txt", "lib/history/teste5.txt", &m5, &s5);
    CU_ASSERT_EQUAL(r5, 0);
    
    for (i = 0; i < m5.L; i++) {
        for (j = 0; j < m5.C; j++) {
            CU_ASSERT_EQUAL(m5.matriz[i][j], matrizExpected5[i][j]);
        }
    }
    liberaMatriz(&m5);
    liberaMatriz(&m5Stack);
    liberaStackMat(&s5);
    initStackMat(&s5);
    leFicheiro("lib/teste5.txt","lib/history/teste5.txt", &m5,&s5);
    CU_ASSERT_EQUAL(m5.L, 9);
    CU_ASSERT_EQUAL(m5.C, 9);
    for (i = 0; i < m5.L; i++) {
        for (j = 0; j < m5.C; j++) {
            CU_ASSERT_EQUAL(m5.matriz[i][j], matrizExpected5[i][j]);
        }
    }
    liberaMatriz(&m5);
    liberaStackMat(&s5);
} 