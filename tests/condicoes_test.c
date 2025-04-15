#include "include/condicoes_test.h"
#include <CUnit/CUnit.h> 

void testar_verifRiscadaOrt(){

    Matriz m1;
    m1.L = 5;
    m1.C = 5;
    
    m1.matriz = malloc(m1.L * sizeof(char*));
    for (int i = 0; i < m1.L; i++) {
        m1.matriz[i] = malloc(m1.C * sizeof(char));
    }

    char matrizExpected1[5][5] = {
        "#cadc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    for (int i = 0; i < m1.L; i++)
        for (int j = 0; j < m1.C; j++)
            m1.matriz[i][j] = matrizExpected1[i][j];

    int r1 = verifRiscadaOrt(&m1, 1, 1); 
    CU_ASSERT_EQUAL(r1, 0);

    for (int i = 0; i < m1.L; i++) {
        free(m1.matriz[i]);
    }
    free(m1.matriz);
}