#include "include/resolve_test.h"

void testar_resolve(){
    //1 matriz resolvivel
    int r1;
    char matriz1[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };
    char matriz2[5][5] = {
        "E#ADC",
        "DC#E#",
        "B#DCE",
        "CDE#B",
        "A#CB#"
    };

    Matriz m1In = criaMatriz(5, 5, matriz1);
    Matriz m1Fin = criaMatriz(5, 5, matriz2);
    Matriz m1Inicial;
    copiaMatriz(&m1Inicial, &m1In);

    Queue q1;
    initQueue(&q1);

    r1 = resolve(&m1In, &m1Inicial, &q1);
    CU_ASSERT_EQUAL(r1, 1);
    comparaMatrizes(&m1In,&m1Fin);

    liberaMatriz(&m1In);
    liberaMatriz(&m1Fin);
    liberaMatriz(&m1Inicial);
    liberaQueue(&q1);

    //2 matriz resolvida
    int r2;
    Matriz m2In = criaMatriz(5, 5, matriz2);
    Matriz m2Fin = criaMatriz(5, 5, matriz2);
    Matriz m2Inicial = criaMatriz(5,5,matriz1);

    Queue q2;
    initQueue(&q2);

    r2 = resolve(&m2In, &m2Inicial, &q2);
    CU_ASSERT_EQUAL(r2, -1);
    comparaMatrizes(&m2In,&m2Fin);

    liberaMatriz(&m2In);
    liberaMatriz(&m2Fin);
    liberaMatriz(&m2Inicial);
    liberaQueue(&q2);

    //3 matriz impossivel
    /*
    int r3;
    char matriz3[5][5] = {
        "aaaba",
        "aabaa",
        "abaaa",
        "babab",
        "babab"
    };
    Matriz m3In = criaMatriz(5, 5, matriz3);
    Matriz m3Fin = criaMatriz(5, 5, matriz3);
    Matriz m3Inicial = criaMatriz(5,5,matriz3);

    Queue q3;
    initQueue(&q3);

    r3 = resolve(&m3In, &m3Inicial, &q3);
    CU_ASSERT_EQUAL(r3, 0);
    comparaMatrizes(&m3In,&m3Fin);

    liberaMatriz(&m3In);
    liberaMatriz(&m3Fin);
    liberaMatriz(&m3Inicial);
    liberaQueue(&q3);   */
}

void testar_resolveAAXA() {
    char mat[1][4] = {"aaca"};
    Matriz m = criaMatriz(1, 4, mat);
    Grupos g;
    g.gs = malloc(sizeof(Grupo) * 2);
    g.cab = 0;
    g.gs[0].p2 = (Pos){0, 1};
    g.gs[0].p3 = (Pos){0, 3};

    resolveAAXA(&m, &g);
    CU_ASSERT_EQUAL(m.matriz[0][1], '#');
    CU_ASSERT_EQUAL(m.matriz[0][3], '#');

    free(g.gs);
    liberaMatriz(&m);
}

void testar_resolveABA() {
    char mat[3][3] = {"aba", "bbb", "ccc"};
    Matriz m = criaMatriz(3, 3, mat);
    Grupos g;
    g.gs = malloc(sizeof(Grupo) * 2);
    g.cab = 0;
    g.gs[0].p1 = (Pos){0, 0};
    g.gs[0].p2 = (Pos){0, 1};

    resolveABA(&m, &g);
    CU_ASSERT_EQUAL(m.matriz[0][0], '#');
    CU_ASSERT_EQUAL(m.matriz[0][1], 'B');

    free(g.gs);
    liberaMatriz(&m);
}

void testar_encontraAAXA() {
    //1 Horizontal
    int r1;
    char mat1[1][5] = {"aaba"};
    Matriz m1 = criaMatriz(1, 5, mat1);
    Grupos g1;
    g1.gs = malloc(sizeof(Grupo) * 2);
    g1.cab = -1;

    r1 = encontraAAXA(&m1, &g1);
    CU_ASSERT_EQUAL(r1, 1);
    CU_ASSERT_EQUAL(g1.gs[0].p3.c, 3);
    
    free(g1.gs);
    liberaMatriz(&m1);

    //2 Vertical
    int r2;
    char mat2[5][1] = {
        "a",
        "a",
        "b",
        "c",
        "a"
    };
    Matriz m2 = criaMatriz(5, 1, mat2);
    Grupos g2;
    g2.gs = malloc(sizeof(Grupo) * 2);
    g2.cab = -1;

    r2 = encontraAAXA(&m2, &g2);
    CU_ASSERT_EQUAL(r2, 1);
    CU_ASSERT_EQUAL(g2.gs[0].p3.l, 4);
    
    free(g2.gs);
    liberaMatriz(&m2);

    //3 Nenhum
    int r3;
    char mat3[3][5] = {
        "abcde",
        "fghij",
        "klmno"
    };
    Matriz m3 = criaMatriz(3, 5, mat3);
    Grupos g3;
    g3.gs = malloc(sizeof(Grupo) * 2);
    g3.cab = -1;

    r3 = encontraAAXA(&m3, &g3);
    CU_ASSERT_EQUAL(r3, 0);

    free(g3.gs);
    liberaMatriz(&m3);
}

void testar_encontraABA() {
    //1 Horizontal
    int r1;
    char mat1[3][3] = {
        "aba",
        "ccc",
        "ddd"
    };
    Matriz m1 = criaMatriz(3, 3, mat1);
    Grupos g1;
    g1.gs = malloc(sizeof(Grupo) * 2);
    g1.cab = -1;

    r1=encontraABA(&m1, &g1);
    CU_ASSERT_EQUAL(r1, 1);
    CU_ASSERT_EQUAL(g1.cab, 0);
    CU_ASSERT_EQUAL(g1.gs[0].p1.c, 0);
    CU_ASSERT_EQUAL(g1.gs[0].p3.c, 2);

    free(g1.gs);
    liberaMatriz(&m1);

    //2 Vertical
    int r2;
    char mat2[3][3] = {
        "aab",
        "cab",
        "aab"
    };
    Matriz m2 = criaMatriz(3, 3, mat2);
    Grupos g2;
    g2.gs = malloc(sizeof(Grupo) * 2);
    g2.cab = -1;
    
    r2 = encontraABA(&m2, &g2);
    CU_ASSERT_EQUAL(r2, 1);
    CU_ASSERT(g2.gs[0].p1.l == 0 || g2.gs[0].p3.l == 2); // linha vertical
    
    free(g2.gs);
    liberaMatriz(&m2);

    //3 Nenhum
    int r3;
    char mat3[3][3] = {
        "abc",
        "def",
        "ghi"
    };
    Matriz m3 = criaMatriz(3, 3, mat3);
    Grupos g3;
    g3.gs = malloc(sizeof(Grupo) * 2);
    g3.cab = -1;

    r3 = encontraABA(&m3, &g3);
    CU_ASSERT_EQUAL(r3, 0);

    free(g3.gs);
    liberaMatriz(&m3);
}


void testar_retrocedeCaminho() {
    //1 grupo ABA p1 == #
    char mat1[3][3] = {"#b#", "abc", "def"};
    char matInicial1[3][3] = {"aba", "abc", "def"};

    Matriz m1 = criaMatriz(3, 3, mat1);
    Matriz mi1 = criaMatriz(3, 3, matInicial1);

    Grupos g1;
    g1.gs = malloc(sizeof(Grupo) * 2);
    g1.cab = 0;
    g1.gs[0].b = 1;
    g1.gs[0].p1 = (Pos){0, 0};
    g1.gs[0].p3 = (Pos){0, 2};

    int r1 = retrocedeCaminho(&m1, &mi1, &g1);
    CU_ASSERT_EQUAL(m1.matriz[0][0], 'a');
    CU_ASSERT_EQUAL(m1.matriz[0][2], '#');
    CU_ASSERT_EQUAL(r1, 1);

    free(g1.gs);
    liberaMatriz(&m1);
    liberaMatriz(&mi1);

    //2 grupo ABA p3 == #
    char mat2[1][3] = {
        "Ab#"
    };
    char matInicial2[1][3] = {
        "aba"
    };
    Matriz m2 = criaMatriz(1, 3, mat2);
    Matriz m2i = criaMatriz(1, 3, matInicial2);
    Grupos g2;
    g2.cab = 0;
    g2.gs = malloc(sizeof(Grupo)*2);
    g2.gs[0].b = 1;
    g2.gs[0].p1 = (Pos){0, 0};
    g2.gs[0].p3 = (Pos){0, 2};
    int r2 = retrocedeCaminho(&m2, &m2i, &g2);
    CU_ASSERT_EQUAL(g2.cab, -1);
    CU_ASSERT_EQUAL(r2, 0);
    free(g2.gs); 
    liberaMatriz(&m2); 
    liberaMatriz(&m2i);

    //3 grupo AAXA p1 != #
    char mat3[1][4] = {
        "abca"
    };
    char matInicial3[1][4] = {
        "abca"
    };
    Matriz m3 = criaMatriz(1, 4, mat3);
    Matriz m3i = criaMatriz(1, 4, matInicial3);
    Grupos g3;
    g3.cab = 0;
    g3.gs = malloc(sizeof(Grupo)*2);
    g3.gs[0].b = 0;
    g3.gs[0].p1 = (Pos){0, 0};
    g3.gs[0].p2 = (Pos){0, 1};
    g3.gs[0].p3 = (Pos){0, 3};
    int r3 = retrocedeCaminho(&m3, &m3i, &g3);
    CU_ASSERT_EQUAL(m3.matriz[0][1], 'b');
    CU_ASSERT_EQUAL(m3.matriz[0][0], '#');
    CU_ASSERT_EQUAL(r3, 1);
    free(g3.gs);
    liberaMatriz(&m3); 
    liberaMatriz(&m3i);

    //4 grupo AAXA p2 != #
    char mat4[1][4] = {
        "#bc#"
    };
    char matInicial4[1][4] = {
        "abca"
    };
    Matriz m4 = criaMatriz(1, 4, mat4);
    Matriz m4i = criaMatriz(1, 4, matInicial4);
    Grupos g4;
    g4.cab = 0;
    g4.gs = malloc(sizeof(Grupo)*2);
    g4.gs[0].b = 0;
    g4.gs[0].p1 = (Pos){0, 0};
    g4.gs[0].p2 = (Pos){0, 1};
    g4.gs[0].p3 = (Pos){0, 3};
    int r4 = retrocedeCaminho(&m4, &m4i, &g4);
    CU_ASSERT_EQUAL(m4.matriz[0][3], 'a');
    CU_ASSERT_EQUAL(m4.matriz[0][1], '#');
    CU_ASSERT_EQUAL(r4, 1);
    free(g4.gs); 
    liberaMatriz(&m4); 
    liberaMatriz(&m4i); 

    //5 grupo AAXA p3 != #
    char mat5[1][4] = {
        "##ca"
    };
    char matInicial5[1][4] = {
        "abca"
    };
    Matriz m5 = criaMatriz(1, 4, mat5);
    Matriz m5i = criaMatriz(1, 4, matInicial5);
    Grupos g5;
    g5.cab = 0;
    g5.gs = malloc(sizeof(Grupo)*2);
    g5.gs[0].b = 0;
    g5.gs[0].p1 = (Pos){0, 0};
    g5.gs[0].p2 = (Pos){0, 1};
    g5.gs[0].p3 = (Pos){0, 3};
    int r5 = retrocedeCaminho(&m5, &m5i, &g5);
    CU_ASSERT_EQUAL(g5.cab, -1);
    CU_ASSERT_EQUAL(m5.matriz[0][0], 'a');
    CU_ASSERT_EQUAL(m5.matriz[0][1], 'b');
    CU_ASSERT_EQUAL(r5, -1);
    free(g5.gs); 
    liberaMatriz(&m5); 
    liberaMatriz(&m5i);

    //6 Não da para retroceder
    char matAtual6[3][3] = {"abc","def","ghi"};
    char matInicial6[3][3] = {"abc","def","ghi"};
    Matriz m6 = criaMatriz(3, 3, matAtual6);
    Matriz m6i = criaMatriz(3, 3, matInicial6);
    Grupos g6;
    g6.cab = -1;
    g6.gs = malloc(sizeof(Grupo));
    int r6 = retrocedeCaminho(&m6, &m6i, &g6);
    CU_ASSERT_EQUAL(r6, -1);
    free(g6.gs);
    liberaMatriz(&m6); liberaMatriz(&m6i);
    
}


void testar_ganhou(){

    //1 jogo completo e valido
    Matriz m1;
    int r1;
    char mat1[5][5] = {
        "E#ADC",
        "DC#E#",
        "B#DCE",
        "CDE#B",
        "A#CB#"
    };
    m1=criaMatriz(5,5,mat1);
    r1=ganhou(&m1);
    CU_ASSERT_EQUAL(r1,1);
    liberaMatriz(&m1);

    //2 jogo completo e não valido

    Matriz m2;
    int r2;
    char mat2[5][5] = {
        "B#FFB",
        "BFDFA",
        "ECGBF",
        "HDHBE",
        "DDCEE",
    };
    m2=criaMatriz(5,5,mat2);
    r2=ganhou(&m2);
    CU_ASSERT_EQUAL(r2,0);
    liberaMatriz(&m2);

    //3 jogo incompleto
    Matriz m3;
    int r3;
    char mat3[5][5] = {
        "B#ffb",
        "bfdfa",
        "ecgbf",
        "hdhbe",
        "ddcee",
    };
    m3=criaMatriz(5,5,mat3);
    r3=ganhou(&m3);
    CU_ASSERT_EQUAL(r3,0);
    liberaMatriz(&m3);
}

void testar_tudoBranco(){
    Matriz m,mExpected;
    char mat[5][5] = {
        "B#ffb",
        "bfdfa",
        "ecgbf",
        "hdhbe",
        "ddcee",
    };
    char matExpected[5][5] = {
        "B#FFB",
        "BFDFA",
        "ECGBF",
        "HDHBE",
        "DDCEE",
    };
    m=criaMatriz(5,5,mat);
    mExpected= criaMatriz(5,5,matExpected);
    tudoBranco(&m);
    comparaMatrizes(&m,&mExpected);
    liberaMatriz(&m);
    liberaMatriz(&mExpected);
}