#include <stdlib.h>
#include "../include/condicoes.h"


int verifRiscadaOrt(Matriz *m, int J, int I, NodeGrupo** grupo) {
    NodePosicao* lista = NULL;

    if (J < m->L - 1 && m->matriz[J + 1][I] == '#')
        lista = adicionarPos(lista, J + 1, I);
    if (J > 0 && m->matriz[J - 1][I] == '#')
        lista = adicionarPos(lista, J - 1, I);
    if (I < m->C - 1 && m->matriz[J][I + 1] == '#')
        lista = adicionarPos(lista, J, I + 1);
    if (I > 0 && m->matriz[J][I - 1] == '#')
        lista = adicionarPos(lista, J, I - 1);

    if (lista != NULL) {
        NodePosicao* novaLista = adicionarPos(NULL, J, I);
        novaLista->prox = lista;
        lista = novaLista;

        //só verifica se já pertence antes de liberar qualquer coisa
        if (pertenceAoGrupo(lista, *grupo)) {
            liberaListaPos(lista);  
        } else {
            *grupo = adicionarLista(*grupo, lista, 0);
        }

        return 0;
    }

    return 1;
}

int verifBranco(Matriz *m, int J, int I, NodeGrupo** grupo) {
    int r = 1;

    // verificação na linha
    NodePosicao* listaLinha = NULL;
    for (int j = 0; j < m->L; j++) {
        if (j != J && m->matriz[j][I] == m->matriz[J][I]) {
            listaLinha = adicionarPos(listaLinha, j, I);
        }
    }

    if (listaLinha != NULL) {
        listaLinha = adicionarPos(listaLinha, J, I);

        if (pertenceAoGrupo(listaLinha, *grupo)) {
            liberaListaPos(listaLinha);  //só libera depois de verificar
        } else {
            *grupo = adicionarLista(*grupo, listaLinha, 1);
            r = 0;
        }
    }

    // verificação na coluna
    NodePosicao* listaColuna = NULL;
    for (int i = 0; i < m->C; i++) {
        if (i != I && m->matriz[J][i] == m->matriz[J][I]) {
            listaColuna = adicionarPos(listaColuna, J, i);
        }
    }

    if (listaColuna != NULL) {
        listaColuna = adicionarPos(listaColuna, J, I);

        if (pertenceAoGrupo(listaColuna, *grupo)) {
            liberaListaPos(listaColuna);  
        } else {
            *grupo = adicionarLista(*grupo, listaColuna, 1);
            r = 0;
        }
    }

    return r;
}


int verificar(Matriz *m, NodeGrupo** grupo) {
    int valido = 1;  
    

    //linha
    for (int j = 0; j < m->L; j++) {
        //coluna
        for (int i = 0; i < m->C; i++) {
            if (isupper(m->matriz[j][i])) {
                if (!verifBranco(m, j, i, grupo)){
                    valido = 0;
                } 
            }

            if (m->matriz[j][i] == '#') { 
                if (!verifRiscadaOrt(m, j, i,grupo)) {
                    valido = 0;
                }
            }
        }
    }

    return valido;
}

int verificaCaminho (Matriz *m, Queue *q){
    int casasVisitadas = 0;
    int casasLivres = 0;  
    Pos temp; 
    
    m->visitada = malloc(sizeof(int*)*m->L); 
    for(int i=0; i<m->L; i++){
        m->visitada[i] = malloc(sizeof(int)*m->C); 
        for(int j=0; j<m->C; j++){
            m->visitada[i][j] = 0; 
        }
    }

    int encontrada = 0; 
    for (int i = 0; i < m->L; i++) {
        for (int j = 0; j < m->C; j++) {
            if (m->matriz[i][j] != '#') {
                casasLivres++;
                if (!encontrada) {
                    Pos pInicial = {i, j};
                    enqueue(q, pInicial);
                    encontrada = 1;
                }
            }
        }
    }

    while (!isEmptyQ(q)) {
        dequeue(q, &temp); 
        int i = temp.l; 
        int j = temp.c; 

        if (i >= 0 && i < m->L && j >= 0 && j < m->C) { 
            if (m->matriz[i][j] != '#' && m->visitada[i][j] == 0) {
                casasVisitadas++; 
                m->visitada[i][j] = 1;

                Pos p1 = {i + 1 , j};
                Pos p2 = {i, j + 1};
                Pos p3 = {i - 1, j};
                Pos p4 = {i, j - 1};

                if (i + 1 < m->L) {
                    enqueue(q, p1); 
                }
                if (j + 1 < m->C) {
                    enqueue(q, p2);
                }
                if (i - 1 >= 0) {
                    enqueue(q, p3);
                }
                if (j - 1 >= 0) {
                    enqueue(q, p4);
                }
            }
        }
    }

    for (int i = 0; i < m->L; i++) {
            free (m->visitada[i]); 
    }
    free(m->visitada); 


    return (casasVisitadas == casasLivres); 
}