#include "include/leFicheiro_test.h"

void testar_leFicheiro() {
    //1
    Matriz m1;
    StackMat s1;
    int r1;


    char matrizExpected1[5][5] = {  "ecAdc",
                                    "dcd#c",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};
    Matriz m1Expected = criaMatriz(5, 5, matrizExpected1);

    
    char dadosExpected1[1][5][5] = {{  "ecADc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"}};
    char comandos1[1] = {'b'};
    StackMat s1Expected = criaStackMat(0, 1, 5, 5, dadosExpected1, comandos1);
                                    
    r1 = leFicheiro("lib/teste7.txt", "lib/history/teste7.txt", &m1, &s1);


    CU_ASSERT_EQUAL(r1, 0);
    comparaMatrizes(&m1Expected, &m1);
    comparaStackMats(&s1Expected, &s1);

    liberaMatriz(&m1);
    liberaStackMat(&s1);
    liberaMatriz(&m1Expected);
    liberaStackMat(&s1Expected);

    //2
    Matriz m2;
    StackMat s2;
    int r2;
    r2 = leFicheiro("lib/elfjeiofheifhewofj.txt", "lib/history/elfjeiofheifhewofj.txt", &m2, &s2);

    CU_ASSERT_EQUAL(r2, -1);

    //3
    Matriz m3;
    StackMat s3;
    int r3;


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
    Matriz m3Expected = criaMatriz(21, 21, matrizExpected3);

    char dadosExpected3[1][21][21] = {{"q#njtjmsfmkdophomalra",
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
        }};
    char comandos3[1] = {'r'};
    StackMat s3Expected = criaStackMat(0, 1, 21, 21, dadosExpected3, comandos3);

    r3 = leFicheiro("lib/teste6.txt", "lib/history/teste6.txt", &m3, &s3);


    CU_ASSERT_EQUAL(r3, 0);
    comparaMatrizes(&m3Expected, &m3);
    comparaStackMats(&s3Expected, &s3);

    liberaMatriz(&m3);
    liberaStackMat(&s3);
    liberaMatriz(&m3Expected);
    liberaStackMat(&s3Expected);
} 