#include "include/dicas_test.h"

void testar_dicas(){
    // 1 diferente
    char mat1[5][5] = {
        "#cadc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    char matInicial1[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };


    Matriz m1 = criaMatriz(5,5,mat1); 
    Matriz mInicial1 = criaMatriz(5,5,matInicial1);
    Queue q1;
    initQueue(&q1);
    int r1 = dicas(&m1,&mInicial1,&q1); 
    CU_ASSERT_EQUAL(r1, 1);

    liberaMatriz(&m1); 
    liberaMatriz(&mInicial1);
    liberaQueue(&q1);

    // 0 diferentes
    char mat2[5][5] = {
        "Ecadc",
        "Dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };

    char matInicial2[5][5] = {
        "ecadc",
        "dcdec",
        "bddce",
        "cdeeb",
        "accbb"
    };


    Matriz m2 = criaMatriz(5,5,mat2); 
    Matriz mInicial2 = criaMatriz(5,5,matInicial2);
    Queue q2;
    initQueue(&q2);
    int r2 = dicas(&m2,&mInicial2,&q2); 
    CU_ASSERT_EQUAL(r2, 0);

    liberaMatriz(&m2); 
    liberaMatriz(&mInicial2);
    liberaQueue(&q2);
}
