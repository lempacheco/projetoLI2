#include "include/ajuda_test.h"

void testar_ajuda(){
    
    //1 - tabuleiro sem alterações
    Queue q1;
    initQueue(&q1);

    char matrizExpected1[5][5] = {  "ecadc",
                                    "dcdec",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};
    Matriz m1Expected = criaMatriz(5, 5, matrizExpected1);

    Matriz m1 = criaMatriz(5, 5, matrizExpected1);
    int r1;
    r1 = ajuda(&m1, &q1, 0);
    comparaMatrizes(&m1, &m1Expected);
    CU_ASSERT_EQUAL(r1, 0);

    liberaQueue(&q1);
    liberaMatriz(&m1);
    liberaMatriz(&m1Expected);
    //2 - tabuleiro com alterações mas sem nada para ajudar
    Queue q2;
    initQueue(&q2);

    char matrizExpected2[5][5] = {  "ecadc",
                                    "#cdec",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};
    Matriz m2Expected = criaMatriz(5, 5, matrizExpected2);

    Matriz m2 = criaMatriz(5, 5, matrizExpected2);
    int r2;
    r2 = ajuda(&m2, &q2, 0);
    comparaMatrizes(&m2, &m2Expected);
    CU_ASSERT_EQUAL(r2, -1);

    liberaQueue(&q2);
    liberaMatriz(&m2);
    liberaMatriz(&m2Expected);
    //3 - tabuleiro com 1 alteração e ajuda
    Queue q3;
    initQueue(&q3);

    char matrizActual3[5][5] = {  "#cadc",
                                    "dcdec",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};

    char matrizExpected3[5][5] = {  "#Cadc",
                                    "Dcdec",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};
    Matriz m3Expected = criaMatriz(5, 5, matrizExpected3);

    Matriz m3 = criaMatriz(5, 5, matrizActual3);
    int r3;
    r3 = ajuda(&m3, &q3, 0);
    comparaMatrizes(&m3, &m3Expected);
    CU_ASSERT_EQUAL(r3, 1);

    liberaQueue(&q3);
    liberaMatriz(&m3);
    liberaMatriz(&m3Expected);
    //4 - tabuleiro com várias alterações e ajuda
    Queue q4;
    initQueue(&q4);

    char matrizActual4[5][5] = {  "#ca#c",
                                    "dcdec",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};

    char matrizExpected4[5][5] = {  "#CA#c",
                                    "DcdEC",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};
    Matriz m4Expected = criaMatriz(5, 5, matrizExpected4);

    Matriz m4 = criaMatriz(5, 5, matrizActual4);
    int r4;
    r4 = ajuda(&m4, &q4, 0);
    comparaMatrizes(&m4, &m4Expected);
    CU_ASSERT_EQUAL(r4, 1);

    liberaQueue(&q4);
    liberaMatriz(&m4);
    liberaMatriz(&m4Expected);
}

void testar_saoIguais(){
    //1 diferentes
    char matrizExpected1[5][5] = {  "ecadc",
                                    "dcdec",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};
    char matrizExpected2[5][5] = {  "ecadc",
                                    "dcdec",
                                    "bddde",
                                    "cdeeb",
                                    "accbb"};

    Matriz m1 = criaMatriz(5, 5, matrizExpected1);
    Matriz m2 = criaMatriz(5, 5, matrizExpected2);
    int r1;
    r1 = saoIguais(&m1, &m2);
    CU_ASSERT_EQUAL(r1, 0);

    liberaMatriz(&m1);
    liberaMatriz(&m2);


    //2 iguais
    char matrizExpected3[5][5] = {  "ecadc",
                                    "dcdec",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};

    Matriz m3 = criaMatriz(5, 5, matrizExpected3);
    Matriz m4 = criaMatriz(5, 5, matrizExpected3);
    int r2;
    r2 = saoIguais(&m3, &m4);
    CU_ASSERT_EQUAL(r2, 1);

    liberaMatriz(&m3);
    liberaMatriz(&m4);

    //3 m1 nula e m2 nao nula, mas ambas com L e C iguais
    Matriz m5;
    m5.L = 5;
    m5.C = 5;
    m5.matriz = NULL;
    Matriz m6 = criaMatriz(5, 5, matrizExpected3);
    int r3;
    r3 = saoIguais(&m5, &m6);
    CU_ASSERT_EQUAL(r3, 0);

    liberaMatriz(&m6);
}

void testar_ajudaSempre(){
    //1 - tabuleiro sem alterações
    Queue q1;
    initQueue(&q1);

    char matrizExpected1[5][5] = {  "ecadc",
                                    "dcdec",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};
    Matriz m1Expected = criaMatriz(5, 5, matrizExpected1);

    Matriz m1 = criaMatriz(5, 5, matrizExpected1);
    int r1;
    r1 = ajudaSempre(&m1, &q1);
    comparaMatrizes(&m1, &m1Expected);
    CU_ASSERT_EQUAL(r1, -1);

    liberaQueue(&q1);
    liberaMatriz(&m1);
    liberaMatriz(&m1Expected);
    //2 - tabuleiro com alterações mas sem nada para ajudar
    Queue q2;
    initQueue(&q2);

    char matrizExpected2[5][5] = {  "ecadc",
                                    "#cdec",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};
    Matriz m2Expected = criaMatriz(5, 5, matrizExpected2);

    Matriz m2 = criaMatriz(5, 5, matrizExpected2);
    int r2;
    r2 = ajudaSempre(&m2, &q2);
    comparaMatrizes(&m2, &m2Expected);
    CU_ASSERT_EQUAL(r2, -1);

    liberaQueue(&q2);
    liberaMatriz(&m2);
    liberaMatriz(&m2Expected);
    //3 - tabuleiro com 1 alteração e ajuda
    Queue q3;
    initQueue(&q3);

    char matrizActual3[5][5] = {  "#cadc",
                                    "dcdec",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};

    char matrizExpected3[5][5] = {  "#CAD#",
                                    "D#deC",
                                    "BDdce",
                                    "Cdeeb",
                                    "A#Cbb"};
    Matriz m3Expected = criaMatriz(5, 5, matrizExpected3);

    Matriz m3 = criaMatriz(5, 5, matrizActual3);
    int r3;
    r3 = ajudaSempre(&m3, &q3);
    comparaMatrizes(&m3, &m3Expected);
    CU_ASSERT_EQUAL(r3, 0);

    liberaQueue(&q3);
    liberaMatriz(&m3);
    liberaMatriz(&m3Expected);
    //4 - tabuleiro com várias alterações e ajuda
    Queue q4;
    initQueue(&q4);

    char matrizActual4[5][5] = {  "#ca#c",
                                    "dcdec",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};

    char matrizExpected4[5][5] = {  "#CA#c",
                                    "DcdEC",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};
    Matriz m4Expected = criaMatriz(5, 5, matrizExpected4);

    Matriz m4 = criaMatriz(5, 5, matrizActual4);
    int r4;
    r4 = ajudaSempre(&m4, &q4);
    comparaMatrizes(&m4, &m4Expected);
    CU_ASSERT_EQUAL(r4, 0);

    liberaQueue(&q4);
    liberaMatriz(&m4);
    liberaMatriz(&m4Expected);
}