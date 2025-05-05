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

    CU_ASSERT_EQUAL(r2, -1);
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

    CU_ASSERT_EQUAL(r5, -1);
    CU_ASSERT_EQUAL(m5.matriz[0][1], 'C');

    

    for (int i = 0; i < m5.L; i++) {
        free(m5.matriz[i]);
    }
    free(m5.matriz);

    for (int i = 0; i < m1I.L; i++) {
        free(m1I.matriz[i]);
    }
    free(m1I.matriz);
}

void testar_escolheComandos(){
    
    char matrizExpected1[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    Matriz m1 = criaMatriz(5,5,matrizExpected1); 

    // comando s

    Queue q1;
    initQueue(&q1);
    NodeGrupo* grupos1 = NULL;
    StackMat s1;
    initStackMat(&s1);

    char *linha1 = "s"; 
    int r1 = escolheComandos(&m1, &s1, &q1, linha1, &grupos1); 
    CU_ASSERT_EQUAL(r1, 1);

    liberaGrupos(grupos1); 
    liberaMatriz(&m1);
    liberaStackMat(&s1);
    liberaQueue(&q1); 

    // comando d 

    Queue q2;
    initQueue(&q2);
    NodeGrupo* grupos2 = NULL;

    char matrizExpected2[5][5] = {
        "ecAdc",
        "dcdec",
        "bd##e",
        "cdeeb",
        "accbb"
    };

    Matriz m2 = criaMatriz(5,5,matrizExpected2); 

    char dadosExpected1[2][5][5] = {{  
        "ecAdc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"}, 
    {
        "ecAdc",
        "dcdec",
        "bd#ce",
        "cdeeb",
        "accbb"
    }};

    char comandos1[2] = {'b','r'};
    StackMat s2 = criaStackMat(1, 2, 5, 5, dadosExpected1, comandos1);

    char *linha2 = "d"; 
    int r2 = escolheComandos(&m2, &s2, &q2, linha2, &grupos2); 
    CU_ASSERT_EQUAL(r2, 2);

    liberaGrupos(grupos2); 
    liberaMatriz(&m2);
    liberaStackMat(&s2);
    liberaQueue(&q2); 

    // v

    Queue q3;
    initQueue(&q3);
    NodeGrupo* grupos3 = NULL;
    StackMat s3;
    initStackMat(&s3);

    // não existe caminho
    char matrizExpected3[5][5] = {
        "e#Adc",
        "#cdec",
        "bddee",
        "cdeeb",
        "accbb"
    };

    Matriz m3 = criaMatriz(5,5,matrizExpected3); 

    char *linha3 = "v"; 
    int r3 = escolheComandos(&m3, &s3, &q3, linha3, &grupos3); 
    CU_ASSERT_EQUAL(r3, 8);

    liberaGrupos(grupos3); 
    liberaMatriz(&m3);
    liberaStackMat(&s3);
    liberaQueue(&q3);


    Queue q4;
    initQueue(&q4);
    NodeGrupo* grupos4 = NULL;
    StackMat s4;
    initStackMat(&s4);

    // não existe caminho
    char matrizExpected4[5][5] = {
        "edAdc",
        "#cdec",
        "b#dee",
        "cde#b",
        "aC#bb"
    };

    Matriz m4 = criaMatriz(5,5,matrizExpected4); 

    char *linha4 = "v"; 
    int r4 = escolheComandos(&m4, &s4, &q4, linha4, &grupos4); 
    CU_ASSERT_EQUAL(r4, 7);

    liberaGrupos(grupos4); 
    liberaMatriz(&m4);
    liberaStackMat(&s4);
    liberaQueue(&q4);

    // a
    // caso válido
    char matrizExpected5[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    Matriz m5 = criaMatriz(5,5,matrizExpected5); 
    Queue q5;
    initQueue(&q5);
    NodeGrupo* grupos5 = NULL;
    StackMat s5;
    initStackMat(&s5);

    char *linha5 = "a"; 
    int r5 = escolheComandos(&m5, &s5, &q5, linha5, &grupos5); 
    CU_ASSERT_EQUAL(r5, 0);

    liberaGrupos(grupos5); 
    liberaMatriz(&m5);
    liberaStackMat(&s5);
    liberaQueue(&q5); 

    // caso inválido
    char matrizExpected6[5][5] = {
        "#cadc",
        "##dec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    Matriz m6 = criaMatriz(5,5,matrizExpected6); 
    Queue q6;
    initQueue(&q6);
    NodeGrupo* grupos6 = NULL;
    StackMat s6;
    initStackMat(&s6);

    char *linha6 = "a"; 
    int r6 = escolheComandos(&m6, &s6, &q6, linha6, &grupos6); 
    CU_ASSERT_EQUAL(r6, -1);

    liberaGrupos(grupos6); 
    liberaMatriz(&m6);
    liberaStackMat(&s6);
    liberaQueue(&q6); 

    // comando R
    char matrizExpected7[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    Matriz m7 = criaMatriz(5,5,matrizExpected7); 

    Queue q7;
    initQueue(&q7);
    NodeGrupo* grupos7 = NULL;
    StackMat s7;
    initStackMat(&s7);

    char *linha7 = "R"; 
    int r7 = escolheComandos(&m7, &s7, &q7, linha7, &grupos7); 
    CU_ASSERT_EQUAL(r7, 0);

    liberaGrupos(grupos7); 
    liberaMatriz(&m7);
    liberaStackMat(&s7);
    liberaQueue(&q7); 

    char matrizExpected8[5][5] = {
        "ecadc",
        "d#dec",
        "###ce",
        "cDeeD",
        "aC#bb"
    };

    Matriz m8 = criaMatriz(5,5,matrizExpected8); 

    Queue q8;
    initQueue(&q8);
    NodeGrupo* grupos8 = NULL;
    StackMat s8;
    initStackMat(&s8);

    char *linha8 = "R"; 
    int r8 = escolheComandos(&m8, &s8, &q8, linha8, &grupos8); 
    CU_ASSERT_EQUAL(r8, 0);

    liberaGrupos(grupos8); 
    liberaMatriz(&m8);
    liberaStackMat(&s8);
    liberaQueue(&q8);

    // comando a

    char matrizExpected9[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    Matriz m9 = criaMatriz(5,5,matrizExpected9); 

    Queue q9;
    initQueue(&q9);
    NodeGrupo* grupos9 = NULL;
    StackMat s9;
    initStackMat(&s9);

    char *linha9 = "a"; 
    int r9 = escolheComandos(&m9, &s9, &q9, linha9, &grupos9); 
    CU_ASSERT_EQUAL(r9, 0);

    liberaGrupos(grupos9); 
    liberaMatriz(&m9);
    liberaStackMat(&s9);
    liberaQueue(&q9); 

    char matrizExpected10[5][5] = {
        "E#ADC",
        "DC#E#",
        "B#DCE",
        "CDE#B", 
        "A#CB#"
    };

    Matriz m10 = criaMatriz(5,5,matrizExpected10); 

    Queue q10;
    initQueue(&q10);
    NodeGrupo* grupos10 = NULL;
    StackMat s10;
    initStackMat(&s10);

    char *linha10 = "a"; 
    int r10 = escolheComandos(&m10, &s10, &q10, linha10, &grupos10); 
    CU_ASSERT_EQUAL(r10, -1);

    liberaGrupos(grupos10); 
    liberaMatriz(&m10);
    liberaStackMat(&s10);
    liberaQueue(&q10); 

    char matrizExpected11[7][8] = {
        "#Hffbgdd",
        "Bfdfaahe",
        "ecgbfhgb",
        "hdhbegfg",
        "ddceefgg",
        "hfbcafdc",
        "dabcgdbc"
   
    };

    Matriz m11 = criaMatriz(7,8,matrizExpected11); 

    Queue q11;
    initQueue(&q11);
    NodeGrupo* grupos11 = NULL;
    StackMat s11;
    initStackMat(&s11);

    char *linha11 = "a"; 
    int r11 = escolheComandos(&m11, &s11, &q11, linha11, &grupos11); 
    CU_ASSERT_EQUAL(r11, -1);

    liberaGrupos(grupos11); 
    liberaMatriz(&m11);
    liberaStackMat(&s11);
    liberaQueue(&q11); 

    // comando r

    char matrizExpected12[7][8] = {
        "#Hffbgdd",
        "Bfdfaahe",
        "ecgbfhgb",
        "hdhbegfg",
        "ddceefgg",
        "hfbcafdc",
        "dabcgdbc"
   
    };

    Matriz m12 = criaMatriz(7,8,matrizExpected12); 

    Queue q12;
    initQueue(&q12);
    NodeGrupo* grupos12 = NULL;
    StackMat s12;
    initStackMat(&s12);

    char *linha12 = "r b 1"; 
    int r12 = escolheComandos(&m12, &s12, &q12, linha12, &grupos12); 
    CU_ASSERT_EQUAL(r12, 0);
    CU_ASSERT_EQUAL(m12.matriz[0][1], '#');

    liberaGrupos(grupos12); 
    liberaMatriz(&m12);
    liberaStackMat(&s12);
    liberaQueue(&q12); 


    char matrizExpected13[7][8] = {
        "#Hffbgdd",
        "Bfdfaahe",
        "ecgbfhgb",
        "hdhbegfg",
        "ddceefgg",
        "hfbcafdc",
        "dabcgdbc"
   
    };

    Matriz m13 = criaMatriz(7,8,matrizExpected13); 

    Queue q13;
    initQueue(&q13);
    NodeGrupo* grupos13 = NULL;
    StackMat s13;
    initStackMat(&s13);

    char *linha13 = "r a 1"; 
    int r13 = escolheComandos(&m13, &s13, &q13, linha13, &grupos13); 
    CU_ASSERT_EQUAL(r13, 0);
    CU_ASSERT_EQUAL(m13.matriz[0][0], '#');

    liberaGrupos(grupos13); 
    liberaMatriz(&m13);
    liberaStackMat(&s13);
    liberaQueue(&q13); 


    char matrizExpected14[7][8] = {
        "#Hffbgdd",
        "Bfdfaahe",
        "ecgbfhgb",
        "hdhbegfg",
        "ddceefgg",
        "hfbcafdc",
        "dabcgdbc"
   
    };

    Matriz m14 = criaMatriz(7,8,matrizExpected14); 

    Queue q14;
    initQueue(&q14);
    NodeGrupo* grupos14 = NULL;
    StackMat s14;
    initStackMat(&s14);

    char *linha14 = "r j 1"; 
    int r14 = escolheComandos(&m14, &s14, &q14, linha14, &grupos14); 
    CU_ASSERT_EQUAL(r14, 0);
    CU_ASSERT_EQUAL(m14.matriz[0][10], '#');

    liberaGrupos(grupos14); 
    liberaMatriz(&m14);
    liberaStackMat(&s14);
    liberaQueue(&q14); 


    // comando b


    Matriz m15 = criaMatriz(7,8,matrizExpected12); 

    Queue q15;
    initQueue(&q15);
    NodeGrupo* grupos15 = NULL;
    StackMat s15;
    initStackMat(&s15);

    char *linha12 = "r b 1"; 
    int r12 = escolheComandos(&m12, &s12, &q12, linha12, &grupos12); 
    CU_ASSERT_EQUAL(r12, 0);
    CU_ASSERT_EQUAL(m12.matriz[0][1], '#');

    liberaGrupos(grupos12); 
    liberaMatriz(&m12);
    liberaStackMat(&s12);
    liberaQueue(&q12); 


    char matrizExpected13[7][8] = {
        "#Hffbgdd",
        "Bfdfaahe",
        "ecgbfhgb",
        "hdhbegfg",
        "ddceefgg",
        "hfbcafdc",
        "dabcgdbc"
   
    };

    Matriz m13 = criaMatriz(7,8,matrizExpected13); 

    Queue q13;
    initQueue(&q13);
    NodeGrupo* grupos13 = NULL;
    StackMat s13;
    initStackMat(&s13);

    char *linha13 = "r a 1"; 
    int r13 = escolheComandos(&m13, &s13, &q13, linha13, &grupos13); 
    CU_ASSERT_EQUAL(r13, 0);
    CU_ASSERT_EQUAL(m13.matriz[0][0], '#');

    liberaGrupos(grupos13); 
    liberaMatriz(&m13);
    liberaStackMat(&s13);
    liberaQueue(&q13); 


    char matrizExpected14[7][8] = {
        "#Hffbgdd",
        "Bfdfaahe",
        "ecgbfhgb",
        "hdhbegfg",
        "ddceefgg",
        "hfbcafdc",
        "dabcgdbc"
   
    };

    Matriz m14 = criaMatriz(7,8,matrizExpected14); 

    Queue q14;
    initQueue(&q14);
    NodeGrupo* grupos14 = NULL;
    StackMat s14;
    initStackMat(&s14);

    char *linha14 = "r j 1"; 
    int r14 = escolheComandos(&m14, &s14, &q14, linha14, &grupos14); 
    CU_ASSERT_EQUAL(r14, 0);
    CU_ASSERT_EQUAL(m14.matriz[0][10], '#');

    liberaGrupos(grupos14); 
    liberaMatriz(&m14);
    liberaStackMat(&s14);
    liberaQueue(&q14); 


}