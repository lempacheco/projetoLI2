#include "../include/listasFunc.h"


//TODO: verificar se o elemento já esta na lista, e não adicionar.

/*
 Verifica se se uma determindada posição pertence a lista. 
*/
int posPertence (NodePosicao* lista, int linha, int coluna){
    
    while(lista != NULL) {
        if (lista->p.l == linha && lista->p.c == coluna + 1) {
            return 1; 
        }

        lista=lista->prox; 
    }
    return 0; 
}

/*
 Verifica se duas listas são iguais. 
*/

int listasIguais(NodePosicao* a, NodePosicao* b) {
    int cA = 0, cB = 0;

    NodePosicao* pa = a;
    while (pa != NULL) {
        cA++;
        if (!posPertence(b, pa->p.l , pa->p.c - 1)) return 0;
        pa = pa->prox;
    }

    NodePosicao* pb = b;
    while (pb != NULL) {
        cB++;
        if (!posPertence(a, pb->p.l, pb->p.c - 1)) return 0;
        pb = pb->prox;
    }

    return cA == cB;  // 1 se são iguais, 0 se diferentes
}

/*
 Verifica se uma determinada lista pertence a um grupo.  
*/

int pertenceAoGrupo(NodePosicao* lista, NodeGrupo* grupo) {
    while (grupo != NULL) {
        if (listasIguais(grupo->cabeca, lista)) return 1;
        grupo = grupo->prox;
    }
    return 0;
}


/*
 Adiciona uma determinada posição na lista. 
 Nesta função a posição é adicionada no final da lista.  
*/
NodePosicao* adicionarPos (NodePosicao* lista, int linha, int coluna) {
    
    if (posPertence(lista, linha, coluna) == 1){
        return lista; 
    }

    NodePosicao* novaPos = malloc(sizeof(NodePosicao));

    novaPos->p.l = linha; 
    novaPos->p.c = coluna + 1;
    novaPos->prox = NULL; 

    if (lista == NULL) {
        return novaPos;  
    } 
    
    NodePosicao* atual=lista; 
    while (atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = novaPos; 

    return lista; 
}

/*
 A função adiciona uma lista a um grupo, caso esta lista já não pertença ao grupo. 
 Atribui uma menasagem a cada lista.   
*/

NodeGrupo* adicionarLista (NodeGrupo* grupo, NodePosicao* lista, int mensagem) {
    
    if (pertenceAoGrupo(lista,grupo)==1) {return grupo;}
    
    NodeGrupo* novoGrupo = malloc(sizeof(NodeGrupo));
    novoGrupo->cabeca = lista;
    novoGrupo->m = mensagem;  
    novoGrupo->prox = NULL; 

    if (grupo == NULL) return novoGrupo;

    NodeGrupo* atual = grupo; 
    while (atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = novoGrupo;  
    return grupo; 
}

void liberaGrupos(NodeGrupo* lista) {
    while (lista != NULL) {
        NodeGrupo* grupoAtual = lista;
        lista = lista->prox;

        // Corrigido: usar "cabeca" em vez de "lista"
        NodePosicao* pos = grupoAtual->cabeca;
        while (pos != NULL) {
            NodePosicao* tempPos = pos;
            pos = pos->prox;
            free(tempPos);
        }

        free(grupoAtual);
    }
}

void liberaListaPos(NodePosicao* lista) {
    while (lista != NULL) {
        NodePosicao* temp = lista;
        lista = lista->prox;
        free(temp);
    }
}


