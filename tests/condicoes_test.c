#include "include/condicoes_test.h"

/*
void testar_verifRiscadaOrt(){

    // Caso nenhum '#' nas 4 direções
    char matrizExpected1[5][5] = {
        "ecadc",
        "dcdec",
        "bd#ce",
        "cdeeb",
        "accbb"
    };

    Matriz m1 = criaMatriz(5,5,matrizExpected1); 
    int r1 = verifRiscadaOrt(&m1, 2, 2); 
    CU_ASSERT_EQUAL(r1, 1);

    liberaMatriz(&m1); 

    // Caso em que há um # em cima 
    char matrizExpected2[5][5] = {
        "e#adc",
        "d#dec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    Matriz m2 = criaMatriz(5,5,matrizExpected2); 
    int r2 = verifRiscadaOrt(&m2, 1, 1); 
    CU_ASSERT_EQUAL(r2, 0);

    liberaMatriz(&m2); 

    // Caso em que há um # em baixo 
    char matrizExpected3[5][5] = {
        "ecadc",
        "d#dec",
        "b#dce",
        "cdeeb",
        "accbb"
    };

    Matriz m3 = criaMatriz(5,5,matrizExpected3); 
    int r3 = verifRiscadaOrt(&m3, 1, 1); 
    CU_ASSERT_EQUAL(r3, 0);

    liberaMatriz(&m3); 

    // Caso em que há um # na direita 
    char matrizExpected4[5][5] = {
        "ecadc",
        "d##ec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    Matriz m4 = criaMatriz(5,5,matrizExpected4); 
    int r4 = verifRiscadaOrt(&m4, 1, 1); 
    CU_ASSERT_EQUAL(r4, 0);

    liberaMatriz(&m4);

    // Caso em que há um # na esquerda
    char matrizExpected5[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "c##eb",
        "accbb"
    };

    Matriz m5 = criaMatriz(5,5,matrizExpected5); 
    int r5 = verifRiscadaOrt(&m5, 3, 2); 
    CU_ASSERT_EQUAL(r5, 0);

    liberaMatriz(&m5);
    

    // Caso válido
    char matrizExpected6[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "c#deb",
        "accbb"
    };

    Matriz m6 = criaMatriz(5,5,matrizExpected6); 
    int r6 = verifRiscadaOrt(&m6, 1, 1); 
    CU_ASSERT_EQUAL(r6, 1);

    liberaMatriz(&m6);


    // Caso válido
    char matrizExpected7[5][5] = {
        "ecadc",
        "dcd#c",
        "bddce",
        "c#deb",
        "accbb"
    };

    Matriz m7 = criaMatriz(5,5,matrizExpected7); 
    int r7 = verifRiscadaOrt(&m7, 3, 2); 
    CU_ASSERT_EQUAL(r7, 0);

    liberaMatriz(&m7);
}

void testar_verifBranco(){

    // Caso nenhuma casa pintada a branco na mesma linha/coluna 
    char matrizExpected1[5][5] = {
        "ecadc",
        "dAdec",
        "bd#ce",
        "cdeeb",
        "accbb"
    };

    Matriz m1 = criaMatriz(5,5,matrizExpected1); 
    int r1 = verifBranco(&m1, 2, 2); 
    CU_ASSERT_EQUAL(r1, 1);

    liberaMatriz(&m1); 

    // Caso em nenhuma casa pintada a branco na mesma linha/coluna 
    char matrizExpected2[5][5] = {
        "ecadc",
        "Dsdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    Matriz m2 = criaMatriz(5,5,matrizExpected2); 
    int r2 = verifBranco(&m2, 1, 0); 
    CU_ASSERT_EQUAL(r2, 1);

    liberaMatriz(&m2); 

    // Caso em que há casa pintada a branco na mesma coluna 
    char matrizExpected3[5][5] = {
        "ecadc",
        "daDec",
        "b#Dce",
        "cdeeb",
        "accbb"
    };

    Matriz m3 = criaMatriz(5,5,matrizExpected3); 
    int r3 = verifBranco(&m3, 1, 2); 
    CU_ASSERT_EQUAL(r3, 0);

    liberaMatriz(&m3); 

    // Caso em que há casa pintada de branco, porém com letra diferentes
    char matrizExpected4[5][5] = {
        "ecadc",
        "da#ec",
        "bdDce",
        "cdEeb",
        "accbb"
    };

    Matriz m4 = criaMatriz(5,5,matrizExpected4); 
    int r4 = verifBranco(&m4, 2, 2); 
    CU_ASSERT_EQUAL(r4, 1);

    liberaMatriz(&m4);

    // Caso em que há casa pintada de branco na mesma linha
    char matrizExpected5[5][5] = {
        "eCadC",
        "dcdec",
        "bddce",
        "c##eb",
        "accbb"
    };

    Matriz m5 = criaMatriz(5,5,matrizExpected5); 
    int r5 = verifBranco(&m5, 0, 1); 
    CU_ASSERT_EQUAL(r5, 0);

    liberaMatriz(&m5);
    

    // Caso válido
    char matrizExpected6[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "cCdeb",
        "accbb"
    };

    Matriz m6 = criaMatriz(5,5,matrizExpected6); 
    int r6 = verifBranco(&m6, 3, 1); 
    CU_ASSERT_EQUAL(r6, 1);

    liberaMatriz(&m6);


    // Caso válido
    char matrizExpected7[5][5] = {
        "ecadc",
        "dcd#c",
        "bDdce",
        "c#Deb",
        "accbb"
    };

    Matriz m7 = criaMatriz(5,5,matrizExpected7); 
    int r7 = verifBranco(&m7, 3, 2); 
    CU_ASSERT_EQUAL(r7, 1);

    liberaMatriz(&m7);
}*/