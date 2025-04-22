#include "include/listasFunc_test.h"

void testar_posPertence() {
    Pos posicoes[] = {{'a',1}, {'b',2}, {'c',3}};
    NodePosicao* lista = criarListaCom(posicoes, 3);

    CU_ASSERT_EQUAL(posPertence(lista, 0, 0), 1); // 'a',1
    CU_ASSERT_EQUAL(posPertence(lista, 1, 1), 1); // 'b',2
    CU_ASSERT_EQUAL(posPertence(lista, 2, 2), 1); // 'c',3
    CU_ASSERT_EQUAL(posPertence(lista, 3, 3), 0); // 'd',4
    liberaListaPos(lista);
}

void testar_listasIguais() {
    Pos posA[] = {{'a',1}, {'b',2}, {'c',3}};
    Pos posB[] = {{'c',3}, {'b',2}, {'a',1}};
    Pos posC[] = {{'a',1}, {'b',2}};
    
    NodePosicao* listaA = criarListaCom(posA, 3);
    NodePosicao* listaB = criarListaCom(posB, 3);
    NodePosicao* listaC = criarListaCom(posC, 2);

    CU_ASSERT_TRUE(listasIguais(listaA, listaB));
    CU_ASSERT_FALSE(listasIguais(listaA, listaC));
    liberaListaPos(listaA);
    liberaListaPos(listaB);
    liberaListaPos(listaC);
}

void testar_pertenceAoGrupo() {
    Pos posA[] = {{'a',1}, {'b',2}};
    Pos posB[] = {{'c',3}, {'d',4}};
    
    NodePosicao* listaA = criarListaCom(posA, 2);
    NodePosicao* listaB = criarListaCom(posB, 2);

    NodeGrupo* grupo = NULL;
    grupo = adicionarLista(grupo, listaA, 1);

    CU_ASSERT_TRUE(pertenceAoGrupo(listaA, grupo));
    CU_ASSERT_FALSE(pertenceAoGrupo(listaB, grupo));

    liberaListaPos(listaB);
    liberaGrupos(grupo);
}

void testar_adicionarPos() {
    NodePosicao* lista = NULL;
    lista = adicionarPos(lista, 0, 0); // a,1
    lista = adicionarPos(lista, 0, 0); // duplicado
    lista = adicionarPos(lista, 1, 1); // b,2

    int count = 0;
    for (NodePosicao* p = lista; p != NULL; p = p->prox) count++;

    CU_ASSERT_EQUAL(count, 2);

    liberaListaPos(lista);
}

void testar_adicionarLista() {
    Pos pos1[] = {{'a',1}, {'b',2}};
    Pos pos2[] = {{'c',3}};

    NodePosicao* lista1 = criarListaCom(pos1, 2);
    NodePosicao* lista2 = criarListaCom(pos2, 1);

    NodeGrupo* grupo = NULL;
    grupo = adicionarLista(grupo, lista1, 5);
    grupo = adicionarLista(grupo, lista1, 5); // testar duplicado
    grupo = adicionarLista(grupo, lista2, 9);

    int count = 0;
    for (NodeGrupo* g = grupo; g != NULL; g = g->prox) count++;

    CU_ASSERT_EQUAL(count, 2);

    liberaGrupos(grupo);
}

void testar_ordenaLista() {
    Pos posicoes[] = {{'c',3}, {'a',1}, {'b',2}};
    NodePosicao* lista = criarListaCom(posicoes, 3);
    lista = ordenaLista(lista);

    CU_ASSERT_EQUAL(lista->p.l, 'a');
    CU_ASSERT_EQUAL(lista->prox->p.l, 'b');
    CU_ASSERT_EQUAL(lista->prox->prox->p.l, 'c');
    liberaListaPos(lista);
}