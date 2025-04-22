#include <stdlib.h>
#include "../include/listasFunc.h"
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
        lista = adicionarPos(lista, J, I);
        NodePosicao* listaOrdenada = ordenaLista(lista);

        // Só verifica se já pertence antes de liberar qualquer coisa
        if (pertenceAoGrupo(listaOrdenada, *grupo)) {
            liberaListaPos(listaOrdenada);  
        } else {
            *grupo = adicionarLista(*grupo, listaOrdenada, 0);
        }

        return 0;
    }

    return 1;
}

int verifBranco(Matriz *m, int J, int I, NodeGrupo** grupo) {
    int r = 1;

    // Verificação na linha
    NodePosicao* listaLinha = NULL;
    for (int j = 0; j < m->L; j++) {
        if (j != J && m->matriz[j][I] == m->matriz[J][I]) {
            listaLinha = adicionarPos(listaLinha, j, I);
        }
    }

    if (listaLinha != NULL) {
        listaLinha = adicionarPos(listaLinha, J, I);
        NodePosicao* listaOrdenada = ordenaLista(listaLinha);

        if (pertenceAoGrupo(listaOrdenada, *grupo)) {
            liberaListaPos(listaOrdenada);  // segura: só libera depois de verificar
        } else {
            *grupo = adicionarLista(*grupo, listaOrdenada, 1);
            r = 0;
        }
    }

    // Verificação na coluna
    NodePosicao* listaColuna = NULL;
    for (int i = 0; i < m->C; i++) {
        if (i != I && m->matriz[J][i] == m->matriz[J][I]) {
            listaColuna = adicionarPos(listaColuna, J, i);
        }
    }

    if (listaColuna != NULL) {
        listaColuna = adicionarPos(listaColuna, J, I);
        NodePosicao* listaOrdenada = ordenaLista(listaColuna);

        if (pertenceAoGrupo(listaOrdenada, *grupo)) {
            liberaListaPos(listaOrdenada);  // mesma lógica
        } else {
            *grupo = adicionarLista(*grupo, listaOrdenada, 1);
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
