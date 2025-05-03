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
    /* int r3;
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
    liberaQueue(&q3);  */
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

/* 
void testar_retrocedeCaminho() {
    // Caso 1: Retrocede em um grupo ABA, onde p1 está riscado
    char matriz1[3][3] = {
        "a#b",
        "abc",
        "def"
    };
    char matrizInicial1[3][3] = {
        "abb",
        "abc",
        "def"
    };

    Matriz m1 = criaMatriz(3, 3, matriz1);
    Matriz mInicial1 = criaMatriz(3, 3, matrizInicial1);
    
    Grupos caminho1;
    caminho1.cab = 0;
    caminho1.gs[0].b = 1;
    caminho1.gs[0].p1.l = 0; caminho1.gs[0].p1.c = 1; // '#'
    caminho1.gs[0].p3.l = 0; caminho1.gs[0].p3.c = 2;

    int r1 = retrocedeCaminho(&m1, &mInicial1, &caminho1);
    CU_ASSERT_EQUAL(r1, 1);
    CU_ASSERT_EQUAL(m1.matriz[0][1], matrizInicial1[0][1]);
    CU_ASSERT_EQUAL(m1.matriz[0][2], '#');

    liberaMatriz(&m1);
    liberaMatriz(&mInicial1);

    // Caso 2: Retrocede em um grupo AAXA, onde p3 não está riscado
    char matriz2[3][3] = {
        "#Ab",
        "aAc",
        "d#f"
    };
    char matrizInicial2[3][3] = {
        "aAb",
        "aAc",
        "dAf"
    };

    Matriz m2 = criaMatriz(3, 3, matriz2);
    Matriz mInicial2 = criaMatriz(3, 3, matrizInicial2);

    Grupos caminho2;
    caminho2.cab = 0;
    caminho2.gs[0].b = 0;
    caminho2.gs[0].p1.l = 0; caminho2.gs[0].p1.c = 0; // '#'
    caminho2.gs[0].p2.l = 1; caminho2.gs[0].p2.c = 1;
    caminho2.gs[0].p3.l = 2; caminho2.gs[0].p3.c = 1;

    int r2 = retrocedeCaminho(&m2, &mInicial2, &caminho2);
    CU_ASSERT_EQUAL(r2, 1);
    CU_ASSERT_EQUAL(m2.matriz[0][0], matrizInicial2[0][0]);
    CU_ASSERT_EQUAL(m2.matriz[1][1], '#');

    liberaMatriz(&m2);
    liberaMatriz(&mInicial2);

    // Caso 3: Caminho vazio
    Matriz m3 = criaMatriz(2, 2, (char[2][2]){{'a','b'},{'c','d'}});
    Matriz mInicial3 = criaMatriz(2, 2, (char[2][2]){{'a','b'},{'c','d'}});

    Grupos caminho3;
    caminho3.cab = -1;

    int r3 = retrocedeCaminho(&m3, &mInicial3, &caminho3);
    CU_ASSERT_EQUAL(r3, -1);

    liberaMatriz(&m3);
    liberaMatriz(&mInicial3);
}
 */

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