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

void testar_leMatriz (){
    Matriz m1,m1Expected;
    FILE *fp;

    char matrizExpected1[5][5] = {  "ecAdc",
                                    "dcd#c",
                                    "bddce",
                                    "cdeeb",
                                    "accbb"};

    m1Expected=criaMatriz(5,5,matrizExpected1);
    fp = fopen("lib/teste1.txt", "r");
    leMatriz(&m1,fp);
    comparaMatrizes(&m1,&m1Expected);
    liberaMatriz(&m1);
    liberaMatriz(&m1Expected);
    fclose(fp);

    //2
    Matriz m2,m2Expected;
    initMatriz(&m2Expected);
    fp = fopen("lib/teste8.txt", "r");
    leMatriz(&m2,fp);
    comparaMatrizes(&m2,&m2Expected);
    liberaMatriz(&m2);
    liberaMatriz(&m2Expected);
    fclose(fp);

    //3
    Matriz m3,m3Expected;
    char matrizExpected3[11][11] = {  "aaaaaaaaaaa",
                                    "aaaaaaaaaaa",
                                    "aaaaaaaaaaa",
                                    "aaaaaaaaaaa",
                                    "aaaaaaaaaaa",
                                    "aaaaaaaaaaa",
                                    "aaaaaaaaaaa",
                                    "aaaaaaaaaaa",
                                    "aaaaaaaaaaa",
                                    "aaaaaaaaaaa",
                                    "aaaaaaaaaaa"};
    m3Expected=criaMatriz(11,11,matrizExpected3);
    fp = fopen("lib/teste9.txt", "r");
    leMatriz(&m3,fp);
    comparaMatrizes(&m3,&m3Expected);
    liberaMatriz(&m3);
    liberaMatriz(&m3Expected);
    fclose(fp);
}

void testar_leStackMat(){
    StackMat s1;
    FILE *fp;

    char dadosExpected1[1][5][5] = {{  
        "ecAdc",
        "dcd#c",
        "bddce",
        "cdeeb",
        "accbb"}};
    char comandos1[1] = {'b'};
    StackMat s1Expected = criaStackMat(0, 1, 5, 5, dadosExpected1, comandos1);
    fp = fopen("lib/history/teste1.txt", "r");
    leStackMat(&s1,fp);
    comparaStackMats(&s1,&s1Expected);
    liberaStackMat(&s1);
    liberaStackMat(&s1Expected);
    fclose(fp);

    //2
    StackMat s2, s2Expected;
    initStackMat(&s2Expected);
    fp = fopen("lib/history/teste8.txt", "r");
    leStackMat(&s2,fp);
    CU_ASSERT_EQUAL(s2.cabeca, s2Expected.cabeca); 
    CU_ASSERT_EQUAL(s2.tam, s2Expected.tam);
    liberaStackMat(&s2);
    liberaStackMat(&s2Expected);
    fclose(fp);
}

void testar_leNumero(){
    int x;
    FILE *fp;
    fp = fopen("lib/teste1.txt", "r");
    leNumero(&x,fp);
    CU_ASSERT_EQUAL(x,5);
    fclose(fp);
    
    //2
    fp = fopen("lib/history/teste8.txt", "r");
    leNumero(&x,fp);
    CU_ASSERT_EQUAL(x,-1);
    fclose(fp);
}