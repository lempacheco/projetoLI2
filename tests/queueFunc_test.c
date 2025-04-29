#include "include/queueFunc_test.h"

void testar_initQueue(){
    //1
    Queue q1;

    initQueue(&q1);

    CU_ASSERT_EQUAL(q1.cap, 10);
    CU_ASSERT_EQUAL(q1.inicio, 0);
    CU_ASSERT_EQUAL(q1.tam, 0);

    liberaQueue(&q1);
}

void testar_isEmptyQ(){
    // 1;
    Queue q1;
    Pos pos1;
    int r1;
    pos1.c=1;
    pos1.l=2;
    
    initQueue(&q1);
    enqueue(&q1,pos1);
    r1=isEmptyQ(&q1);
    CU_ASSERT_EQUAL(r1, 0);
    liberaQueue(&q1);

    // 2
    Queue q2;
    int r2;
    initQueue(&q2);
    r2=isEmptyQ(&q2);
    CU_ASSERT_EQUAL(r2, 1);
    liberaQueue(&q2);
}

void testar_enqueue(){
    //1 - Queue Cheia
    Pos* listaPosIn1=malloc(sizeof(Pos));
    Pos* listaPosF1=malloc(2*sizeof(Pos));
    Pos pos1;

    pos1.c=3;
    pos1.l=4;
    listaPosIn1[0].c=1;
    listaPosIn1[0].l=2;
    listaPosF1[0].c=1;
    listaPosF1[0].l=2;
    listaPosF1[1].c=3;
    listaPosF1[1].l=4;
    Queue q1In = criaQueue(1, 1,listaPosIn1);
    Queue q1F = criaQueue(2, 2, listaPosF1);

    enqueue(&q1In, pos1);

    comparaQueue(&q1In,&q1F);

    free(listaPosIn1);
    free(listaPosF1);
    liberaQueue(&q1In);
    liberaQueue(&q1F);
    //2 - Queue com elementos
    Pos* listaPosIn2=malloc(sizeof(Pos));
    Pos* listaPosF2=malloc(2*sizeof(Pos));
    Pos pos2;

    pos2.c=3;
    pos2.l=4;
    listaPosIn2[0].c=1;
    listaPosIn2[0].l=2;
    listaPosF2[0].c=1;
    listaPosF2[0].l=2;
    listaPosF2[1].c=3;
    listaPosF2[1].l=4;
    Queue q2In = criaQueue(1, 10,listaPosIn2);
    Queue q2F = criaQueue(2, 10, listaPosF2);

    enqueue(&q2In, pos2);
    comparaQueue(&q2In,&q2F);

    free(listaPosIn2);
    free(listaPosF2);
    liberaQueue(&q2In);
    liberaQueue(&q2F);

    //3 - Queue vazia
    Queue q3;
    initQueue(&q3);
    Pos pos3;
    pos3.c=3;
    pos3.l=4;

    enqueue(&q3, pos3);

    CU_ASSERT_EQUAL(q3.cap,10);
    CU_ASSERT_EQUAL(q3.inicio, 0);
    CU_ASSERT_EQUAL(q3.tam, 1);
    CU_ASSERT_EQUAL(q3.valores[0].c, 3);
    CU_ASSERT_EQUAL(q3.valores[0].l, 4);

    liberaQueue(&q3);
}
void testar_dequeue(){
    Pos* listaPos=malloc(sizeof(Pos)*4);

    //1 - Queue com elementos
    Pos* listaPosIn1=malloc(sizeof(Pos));
    int r1;

    listaPosIn1[0].c=1;
    listaPosIn1[0].l=2;
    
    Queue q1In = criaQueue(1, 10,listaPosIn1);
    Queue q1F;
    q1F.cap = 10;
    q1F.tam = 1;
    q1F.inicio = 0;
    q1F.valores=NULL;

    r1=dequeue(&q1In,listaPos);
    comparaQueue(&q1In,&q1F);
    CU_ASSERT_EQUAL(r1,0);
    CU_ASSERT_EQUAL(listaPos[0].c,1);
    CU_ASSERT_EQUAL(listaPos[0].l,2);

    free(listaPosIn1);
    liberaQueue(&q1In);
    liberaQueue(&q1F);

    //2 Queue vazia
    Queue q2In;
    int r2;
    initQueue(&q2In);
    
    Queue q2F;
    q2F.cap = 10;
    q2F.tam = 0;
    q2F.inicio = 0;
    q2F.valores=NULL;

    r2=dequeue(&q2In,listaPos);
    printf("\n%d %d",q2In.tam,q2In.inicio);
    CU_ASSERT_EQUAL(q2In.tam,0);
    CU_ASSERT_EQUAL(q2In.cap,10);
    CU_ASSERT_EQUAL(q2In.inicio,0);
    CU_ASSERT_EQUAL(r2,1);

    liberaQueue(&q2In);
    liberaQueue(&q2F);

    free(listaPos);
}