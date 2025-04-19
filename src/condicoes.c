#include <stdlib.h>
#include "../include/listasFunc.h"
#include "../include/condicoes.h"


 int verifRiscadaOrt(Matriz *m, int J, int I, NodeGrupo** grupo) {
    NodePosicao* lista = NULL;

    // Verifica cada vizinho ortogonal e adiciona se for #
    if (J < m->L - 1 && m->matriz[J + 1][I] == '#')
        lista = adicionarPos(lista, J + 1, I);

    if (J > 0 && m->matriz[J - 1][I] == '#')
        lista = adicionarPos(lista, J - 1, I);

    if (I < m->C - 1 && m->matriz[J][I + 1] == '#')
        lista = adicionarPos(lista, J, I + 1);

    if (I > 0 && m->matriz[J][I - 1] == '#')
        lista = adicionarPos(lista, J, I - 1);

    // Só adiciona grupo se houver pelo menos 1 vizinho #
    if (lista != NULL) {
        lista = adicionarPos(lista, J, I);  // Adiciona a posição original
        *grupo = adicionarLista(*grupo, ordenaLista(lista), 0);
        return 0;
    }

    return 1; // nenhum vizinho #
}

int verifBranco (Matriz *m, int J, int I, NodeGrupo** grupo){
    int r=1;    
    //linha
    NodePosicao* listaLinha = NULL; 
    for (int j=0; j<m->L; j++){
        if (j!=J && m->matriz[j][I] == m->matriz[J][I]){
            listaLinha = adicionarPos(listaLinha, j, I); 
            listaLinha = adicionarPos(listaLinha, J, I);
            r = 0; 
        } 
    }

    if (listaLinha != NULL && listaLinha->prox != NULL) {
        *grupo = adicionarLista(*grupo, ordenaLista(listaLinha), 1); 
    }

    // coluna
    NodePosicao* listaColuna = NULL; 
    for (int i=0; i<m->C; i++){
        if (i!=I && m->matriz[J][i] == m->matriz[J][I]) {
   
            listaColuna = adicionarPos(listaColuna, J, i); 
            listaColuna = adicionarPos(listaColuna, J, I);
            r = 0; 
        }
    }

    if (listaColuna != NULL && listaColuna->prox != NULL){
        *grupo = adicionarLista(*grupo, ordenaLista(listaColuna), 1); 
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
