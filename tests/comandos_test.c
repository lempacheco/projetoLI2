#include "include/comandos_test.h"


void testar_riscar() {
    
    // 1 Caso normal

    Pos p1;
    p1.l = 1; 
    p1.c = 2;  // matriz[0][1]

    Matriz m1;
    m1.L = 5;
    m1.C = 5;
    
    m1.matriz = malloc(m1.L * sizeof(char*));
    for (int i = 0; i < m1.L; i++) {
        m1.matriz[i] = malloc(m1.C * sizeof(char));
    }

    char matrizExpected1[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    for (int i = 0; i < m1.L; i++)
        for (int j = 0; j < m1.C; j++)
            m1.matriz[i][j] = matrizExpected1[i][j];

    int r1 = riscar(&m1, p1);

    CU_ASSERT_EQUAL(r1, 0);
    CU_ASSERT_EQUAL(m1.matriz[0][1], '#');

    
    for (int i = 0; i < m1.L; i++) {
        free(m1.matriz[i]);
    }
    free(m1.matriz);

    // 2 Caso casa já esta riscada
    Pos p2;
    p2.l = 1; 
    p2.c = 2;  // matriz[0][1]

    Matriz m2;
    m2.L = 7;
    m2.C = 6;
    
    m2.matriz = malloc(m2.L * sizeof(char*));
    for (int i = 0; i < m2.L; i++) {
        m2.matriz[i] = malloc(m2.C * sizeof(char));
    }

    char matrizExpected2[7][6] = {
        "e#adca",
        "dcdeca",
        "bddcea",
        "cdeeba",
        "accbba", 
        "bddcea", 
        "cdeeba"
    };

    for (int i = 0; i < m2.L; i++)
        for (int j = 0; j < m2.C; j++)
            m2.matriz[i][j] = matrizExpected2[i][j];

    int r2 = riscar(&m2, p2);

    CU_ASSERT_EQUAL(r2, 0);
    CU_ASSERT_EQUAL(m2.matriz[0][1], '#');

    
    for (int i = 0; i < m2.L; i++) {
        free(m2.matriz[i]);
    }
    free(m2.matriz);

    // 3 Caso para o limite da matriz. 

    Pos p3;
    p3.l = 1; 
    p3.c = 5;  // matriz[0][4]

    Matriz m3;
    m3.L = 5;
    m3.C = 5;
    
    m3.matriz = malloc(m3.L * sizeof(char*));
    for (int i = 0; i < m3.L; i++) {
        m3.matriz[i] = malloc(m3.C * sizeof(char));
    }

    char matrizExpected3[5][5] = {
        "e#adc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    for (int i = 0; i < m3.L; i++)
        for (int j = 0; j < m3.C; j++)
            m3.matriz[i][j] = matrizExpected3[i][j];

    int r3 = riscar(&m3, p3);

    CU_ASSERT_EQUAL(r3, 0);
    CU_ASSERT_EQUAL(m3.matriz[0][4], '#');

    
    for (int i = 0; i < m3.L; i++) {
        free(m3.matriz[i]);
    }
    free(m3.matriz);

    // 4 Caso fora do limite da matriz

    Pos p4;
    p4.l = 1; 
    p4.c = 6;  // matriz[0][5]

    Matriz m4;
    m4.L = 5;
    m4.C = 5;
    
    m4.matriz = malloc(m4.L * sizeof(char*));
    for (int i = 0; i < m4.L; i++) {
        m4.matriz[i] = malloc(m4.C * sizeof(char));
    }

    char matrizExpected4[5][5] = {
        "e#adc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    for (int i = 0; i < m4.L; i++)
        for (int j = 0; j < m4.C; j++)
            m4.matriz[i][j] = matrizExpected4[i][j];

    int r4 = riscar(&m4, p4);

    CU_ASSERT_EQUAL(r4, 1);

    
    for (int i = 0; i < m4.L; i++) {
        free(m4.matriz[i]);
    }
    free(m4.matriz);

    // 5 Caso a casa esta em branco

    Pos p5;
    p5.l = 1; 
    p5.c = 2;  // matriz[0][1]

    Matriz m5;
    m5.L = 5;
    m5.C = 5;
    
    m5.matriz = malloc(m5.L * sizeof(char*));
    for (int i = 0; i < m5.L; i++) {
        m5.matriz[i] = malloc(m5.C * sizeof(char));
    }

    char matrizExpected5[5][5] = {
        "eCadc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    for (int i = 0; i < m5.L; i++)
        for (int j = 0; j < m5.C; j++)
            m5.matriz[i][j] = matrizExpected5[i][j];

    int r5 = riscar(&m5, p5);

    CU_ASSERT_EQUAL(r5, 0);
    CU_ASSERT_EQUAL(m5.matriz[0][1], '#');

    
    for (int i = 0; i < m5.L; i++) {
        free(m5.matriz[i]);
    }
    free(m5.matriz);
}

void testar_branco() {
    
    // 1 Caso normal

    Pos p1;
    p1.l = 1; 
    p1.c = 2;  // matriz[0][1]

    Matriz m1;
    m1.L = 5;
    m1.C = 5;
    
    m1.matriz = malloc(m1.L * sizeof(char*));
    for (int i = 0; i < m1.L; i++) {
        m1.matriz[i] = malloc(m1.C * sizeof(char));
    }
    
    Matriz m1I;
    m1I.L = 5;
    m1I.C = 5;
    
    m1I.matriz = malloc(m1I.L * sizeof(char*));
    for (int i = 0; i < m1I.L; i++) {
        m1I.matriz[i] = malloc(m1I.C * sizeof(char));
    }

    char matrizExpected1[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    for (int i = 0; i < m1.L; i++)
        for (int j = 0; j < m1.C; j++) {
            m1.matriz[i][j] = matrizExpected1[i][j];
            m1I.matriz[i][j] = matrizExpected1[i][j];
            }
    int r1 = branco(&m1, p1, &m1I);

    CU_ASSERT_EQUAL(r1, 0);
    CU_ASSERT_EQUAL(m1.matriz[0][1], 'C');

    
    for (int i = 0; i < m1.L; i++) {
        free(m1.matriz[i]);
    }
    free(m1.matriz);

    // 2 Caso em que a posição está riscada

    Pos p2;
    p2.l = 1; 
    p2.c = 2;  // matriz[0][1]

    Matriz m2;
    m2.L = 5;
    m2.C = 5;
    
    m2.matriz = malloc(m2.L * sizeof(char*));
    for (int i = 0; i < m2.L; i++) {
        m2.matriz[i] = malloc(m2.C * sizeof(char));
    }

    char matrizExpected2[5][5] = {
        "e#adc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    for (int i = 0; i < m2.L; i++)
        for (int j = 0; j < m2.C; j++)
            m2.matriz[i][j] = matrizExpected2[i][j];

    int r2 = branco(&m2, p2, &m1I);

    CU_ASSERT_EQUAL(r2, 0);
    CU_ASSERT_EQUAL(m2.matriz[0][1], 'C');

    
    for (int i = 0; i < m2.L; i++) {
        free(m2.matriz[i]);
    }
    free(m2.matriz);

    // 3 Caso para o limite da matriz. 

    Pos p3;
    p3.l = 1; 
    p3.c = 5;  // matriz[0][4]

    Matriz m3;
    m3.L = 5;
    m3.C = 5;
    
    m3.matriz = malloc(m3.L * sizeof(char*));
    for (int i = 0; i < m3.L; i++) {
        m3.matriz[i] = malloc(m3.C * sizeof(char));
    }

    char matrizExpected3[5][5] = {
        "e#adc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    for (int i = 0; i < m3.L; i++)
        for (int j = 0; j < m3.C; j++)
            m3.matriz[i][j] = matrizExpected3[i][j];

    int r3 = branco(&m3, p3, &m1I);

    CU_ASSERT_EQUAL(r3, 0);
    CU_ASSERT_EQUAL(m3.matriz[0][4], 'C');

    
    for (int i = 0; i < m3.L; i++) {
        free(m3.matriz[i]);
    }
    free(m3.matriz);

    // 4 Caso para fora do limite da matriz

    Pos p4;
    p4.l = 1; 
    p4.c = 6;  // matriz[0][5]
    
    Matriz m4;
    m4.L = 5;
    m4.C = 5;
        
    m4.matriz = malloc(m4.L * sizeof(char*));
    for (int i = 0; i < m4.L; i++) {
        m4.matriz[i] = malloc(m4.C * sizeof(char));
    }
    
    char matrizExpected4[5][5] = {
        "e#adc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };
    
    for (int i = 0; i < m4.L; i++)
        for (int j = 0; j < m4.C; j++)
            m4.matriz[i][j] = matrizExpected4[i][j];
    
    int r4 = branco(&m4, p4, &m1I);
    
    CU_ASSERT_EQUAL(r4, 1);
    
        
    for (int i = 0; i < m4.L; i++) {
        free(m4.matriz[i]);
    }
    free(m4.matriz);

    // 5 Caso para casa já em branco

    Pos p5;
    p5.l = 1; 
    p5.c = 2;  // matriz[0][1]

    Matriz m5;
    m5.L = 5;
    m5.C = 5;
    
    m5.matriz = malloc(m5.L * sizeof(char*));
    for (int i = 0; i < m5.L; i++) {
        m5.matriz[i] = malloc(m5.C * sizeof(char));
    }

    char matrizExpected5[5][5] = {
        "eCadc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    for (int i = 0; i < m5.L; i++)
        for (int j = 0; j < m5.C; j++)
            m5.matriz[i][j] = matrizExpected5[i][j];

    int r5 = branco(&m5, p5, &m1I);

    CU_ASSERT_EQUAL(r5, 0);
    CU_ASSERT_EQUAL(m5.matriz[0][1], 'C');

    
    for (int i = 0; i < m5.L; i++) {
        free(m5.matriz[i]);
    }
    free(m5.matriz);

    free(m1I.matriz);
}
