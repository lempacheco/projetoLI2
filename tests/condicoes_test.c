#include "include/condicoes_test.h"


void testar_verifRiscadaOrt(){

    // Caso nenhum '#' nas 4 direções
    char matrizExpected1[5][5] = {
        "ecadc",
        "dcdec",
        "bd#ce",
        "cdeeb",
        "accbb"
    };

    NodeGrupo* grupo1 = NULL;
    Matriz m1 = criaMatriz(5,5,matrizExpected1); 
    int r1 = verifRiscadaOrt(&m1, 2, 2, &grupo1); 
    CU_ASSERT_EQUAL(r1, 1);

    liberaMatriz(&m1); 
    liberaGrupos(grupo1);

    // Caso em que há um # em cima 
    char matrizExpected2[5][5] = {
        "e#adc",
        "d#dec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    NodeGrupo* grupo2 = NULL;
    Matriz m2 = criaMatriz(5,5,matrizExpected2); 
    int r2 = verifRiscadaOrt(&m2, 1, 1, &grupo2); 
    CU_ASSERT_EQUAL(r2, 0);

    liberaMatriz(&m2); 
    liberaGrupos(grupo2);

    // Caso em que há um # em baixo 
    char matrizExpected3[5][5] = {
        "ecadc",
        "d#dec",
        "b#dce",
        "cdeeb",
        "accbb"
    };

    NodeGrupo* grupo3 = NULL;
    Matriz m3 = criaMatriz(5,5,matrizExpected3); 
    int r3 = verifRiscadaOrt(&m3, 1, 1, &grupo3); 
    CU_ASSERT_EQUAL(r3, 0);

    liberaMatriz(&m3); 
    liberaGrupos(grupo3);

    // Caso em que há um # na direita 
    char matrizExpected4[5][5] = {
        "ecadc",
        "d##ec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    NodeGrupo* grupo4 = NULL;
    Matriz m4 = criaMatriz(5,5,matrizExpected4); 
    int r4 = verifRiscadaOrt(&m4, 1, 1, &grupo4); 
    CU_ASSERT_EQUAL(r4, 0);

    liberaMatriz(&m4);
    liberaGrupos(grupo4);

    // Caso em que há um # na esquerda
    char matrizExpected5[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "c##eb",
        "accbb"
    };

    NodeGrupo* grupo5 = NULL;
    Matriz m5 = criaMatriz(5,5,matrizExpected5); 
    int r5 = verifRiscadaOrt(&m5, 3, 2, &grupo5); 
    CU_ASSERT_EQUAL(r5, 0);

    liberaMatriz(&m5);
    liberaGrupos(grupo5);
    

    // Caso válido
    char matrizExpected6[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "c#deb",
        "accbb"
    };

    NodeGrupo* grupo6 = NULL;
    Matriz m6 = criaMatriz(5,5,matrizExpected6); 
    int r6 = verifRiscadaOrt(&m6, 1, 1, &grupo6); 
    CU_ASSERT_EQUAL(r6, 1);

    liberaMatriz(&m6);
    liberaGrupos(grupo6);


    // Caso válido
    char matrizExpected7[5][5] = {
        "ecadc",
        "dcd#c",
        "bddce",
        "c#deb",
        "accbb"
    };

    NodeGrupo* grupo7 = NULL;
    Matriz m7 = criaMatriz(5,5,matrizExpected7); 
    int r7 = verifRiscadaOrt(&m7, 3, 2, &grupo7); 
    CU_ASSERT_EQUAL(r7, 0);

    liberaMatriz(&m7);
    liberaGrupos(grupo7);
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

    NodeGrupo* grupo1 = NULL;
    Matriz m1 = criaMatriz(5,5,matrizExpected1); 
    int r1 = verifBranco(&m1, 2, 2, &grupo1); 
    CU_ASSERT_EQUAL(r1, 1);

    liberaMatriz(&m1); 
    liberaGrupos(grupo1);

    // Caso em nenhuma casa pintada a branco na mesma linha/coluna 
    char matrizExpected2[5][5] = {
        "ecadc",
        "Dsdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    NodeGrupo* grupo2 = NULL;
    Matriz m2 = criaMatriz(5,5,matrizExpected2); 
    int r2 = verifBranco(&m2, 1, 0, &grupo2); 
    CU_ASSERT_EQUAL(r2, 1);

    liberaMatriz(&m2);
    liberaGrupos(grupo2); 

    // Caso em que há casa pintada a branco na mesma coluna 
    char matrizExpected3[5][5] = {
        "ecadc",
        "daDec",
        "b#Dce",
        "cdeeb",
        "accbb"
    };

    NodeGrupo* grupo3 = NULL;
    Matriz m3 = criaMatriz(5,5,matrizExpected3); 
    int r3 = verifBranco(&m3, 1, 2, &grupo3); 
    CU_ASSERT_EQUAL(r3, 0);

    liberaMatriz(&m3); 
    liberaGrupos(grupo3);

    // Caso em que há casa pintada de branco, porém com letra diferentes
    char matrizExpected4[5][5] = {
        "ecadc",
        "da#ec",
        "bdDce",
        "cdEeb",
        "accbb"
    };

    NodeGrupo* grupo4 = NULL;
    Matriz m4 = criaMatriz(5,5,matrizExpected4); 
    int r4 = verifBranco(&m4, 2, 2, &grupo4); 
    CU_ASSERT_EQUAL(r4, 1);

    liberaMatriz(&m4);
    liberaGrupos(grupo4);

    // Caso em que há casa pintada de branco na mesma linha
    char matrizExpected5[5][5] = {
        "eCadC",
        "dcdec",
        "bddce",
        "c##eb",
        "accbb"
    };

    NodeGrupo* grupo5 = NULL;
    Matriz m5 = criaMatriz(5,5,matrizExpected5); 
    int r5 = verifBranco(&m5, 0, 1, &grupo5); 
    CU_ASSERT_EQUAL(r5, 0);

    liberaMatriz(&m5);
    liberaGrupos(grupo5);
    

    // Caso válido
    char matrizExpected6[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "cCdeb",
        "accbb"
    };

    NodeGrupo* grupo6 = NULL;
    Matriz m6 = criaMatriz(5,5,matrizExpected6); 
    int r6 = verifBranco(&m6, 3, 1, &grupo6); 
    CU_ASSERT_EQUAL(r6, 1);

    liberaMatriz(&m6);
    liberaGrupos(grupo6);


    // Caso válido
    char matrizExpected7[5][5] = {
        "ecadc",
        "dcd#c",
        "bDdce",
        "c#Deb",
        "accbb"
    };


    NodeGrupo* grupo7 = NULL;
    Matriz m7 = criaMatriz(5,5,matrizExpected7); 
    int r7 = verifBranco(&m7, 3, 2, &grupo7); 
    CU_ASSERT_EQUAL(r7, 1);

    liberaMatriz(&m7);
    liberaGrupos(grupo7);
}

void testar_verificar(){

    // Caso válido 
    char matrizExpected1[5][5] = {
        "ecadc",
        "dAdec",
        "bd#ce",
        "cdeeb",
        "accbb"
    };

    NodeGrupo* grupo1 = NULL;
    Matriz m1 = criaMatriz(5,5,matrizExpected1); 
    int r1 = verificar(&m1, &grupo1); 
    CU_ASSERT_EQUAL(r1, 1);

    liberaMatriz(&m1); 
    liberaGrupos(grupo1);

    // Caso válido 
    char matrizExpected2[7][8] = {
        "ecadckg",
        "DshdEcy",
        "bd#td#e",
        "cdefesb",
        "acchB#s",
        "dRlthja"
    };

    NodeGrupo* grupo2 = NULL;
    Matriz m2 = criaMatriz(7,8,matrizExpected2); 
    int r2 = verificar(&m2, &grupo2); 
    CU_ASSERT_EQUAL(r2, 1);

    liberaMatriz(&m2);
    liberaGrupos(grupo2); 

    // Caso inválido 
    char matrizExpected3[5][5] = {
        "ecadc",
        "daDec",
        "b#Dce",
        "cdeeb",
        "accbb"
    };

    NodeGrupo* grupo3 = NULL;
    Matriz m3 = criaMatriz(5,5,matrizExpected3); 
    int r3 = verificar(&m3, &grupo3); 
    CU_ASSERT_EQUAL(r3, 0);

    liberaMatriz(&m3); 
    liberaGrupos(grupo3);

    // Caso inválido
    char matrizExpected4[10][10] = {
        "edcfhadchk",
        "dfwya#eclt",
        "bdgaD#ghqe",
        "cdEfchopeb",
        "accpodaybb", 
        "afhjloptft",
        "faesltdhtd",
        "rtsh##vsfa",
        "fsTbecdabf",
        "dardhbnzjs" 
    };

    NodeGrupo* grupo4 = NULL;
    Matriz m4 = criaMatriz(10,10,matrizExpected4); 
    int r4 = verificar(&m4, &grupo4); 
    CU_ASSERT_EQUAL(r4, 0);

    liberaMatriz(&m4);
    liberaGrupos(grupo4);

    // Caso válido
    char matrizExpected5[5][5] = {
        "eCadR",
        "dcdec",
        "bddce",
        "c#C#b",
        "accbb"
    };

    NodeGrupo* grupo5 = NULL;
    Matriz m5 = criaMatriz(5,5,matrizExpected5); 
    int r5 = verificar(&m5, &grupo5); 
    CU_ASSERT_EQUAL(r5, 1);

    liberaMatriz(&m5);
    liberaGrupos(grupo5);
    

    // Caso válido
    char matrizExpected6[5][5] = {
        "ecadc",
        "dc#ec",
        "b#d#e",
        "ABCDE",
        "#c#bb"
    };

    NodeGrupo* grupo6 = NULL;
    Matriz m6 = criaMatriz(5,5,matrizExpected6); 
    int r6 = verificar(&m6, &grupo6); 
    CU_ASSERT_EQUAL(r6, 1);

    liberaMatriz(&m6);
    liberaGrupos(grupo6);
}
