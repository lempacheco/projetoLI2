#include "include/leFicheiro_test.h"

void testar_leFicheiro() {
    int i, j;

    //1
    Matriz m1;
    StackMat s1;
    int r1 = leFicheiro("lib/teste1.txt", "lib/history/teste1.txt", &m1, &s1);
    char matrizExpected1[5][5] = {  "ecAdc",
                                    "dcd#c",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};

    CU_ASSERT_EQUAL(r1, 0);
    CU_ASSERT_EQUAL(m1.L, 5);
    CU_ASSERT_EQUAL(m1.C, 5);
    for (i=0; i<m1.L; i++){
        for (j=0; j<m1.C; j++){ 
            CU_ASSERT_EQUAL(m1.matriz[i][j], matrizExpected1[i][j]);
        }
    }

    liberaMatriz(&m1);
    liberaStackMat(&s1);

    //3
    Matriz m3;
    StackMat s3;
    initMatriz (&m3); 
    int r3 = leFicheiro("lib/teste6.txt", "lib/history/teste6.txt", &m3, &s3);
    char matrizExpected3[21][21] = {"qbnjtjmsfmkdophomalra",
        "lgdhctmionqojjgbrspfa",
        "tlldjrsqjgmgacbhoeqia",
        "eerjabfjsdjqrnntpimha",
        "aahklmecbldspndqpomga",
        "srmaqebgkqnjklmngctda",
        "fcatgrdkbolamiqrjenga",
        "ilednckpoqjrdifhlbhaa",
        "jppihffstscbrkrjbmgda",
        "bgjorqlghrkmdseainnta",
        "klpfiohamdsregehhdrfa",
        "smkcfbtgeialqnjihpska",
        "gfhmnihbebdkcqnpksala",
        "mtmkospnecqhkdieqjfma",
        "cmibnajfgsrpnosmslnqa",
        "aornscpeahgtlbijmmqca",
        "mqscjdklpaffchjnerina",
        "fngsmhrclobafeckeijoa",
        "oempnnbrckhsibadfqqja",
        "rjtrldomkeqpsdacpkdpa",
        "qbnjtjmsfmkdophomalra"
        };

    CU_ASSERT_EQUAL(r3, 0);
    CU_ASSERT_EQUAL(m3.L, 21);
    CU_ASSERT_EQUAL(m3.C, 21);
    for (i=0; i<m3.L; i++){
        for (j=0; j<m3.C; j++){ 
            CU_ASSERT_EQUAL(m3.matriz[i][j], matrizExpected3[i][j]);
        }
    }

    liberaMatriz(&m3);
    liberaStackMat(&s3);

    //2
    Matriz m2;
    StackMat s2;
    int r2 = leFicheiro("lib/elfjeiofheifhewofj.txt", "lib/history/elfjeiofheifhewofj.txt", &m2, &s2);

    CU_ASSERT_EQUAL(r2, 1);
} 