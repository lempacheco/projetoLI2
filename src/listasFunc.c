#include "../include/listasFunc.h"


/*
 Verifica se se uma determindada posição pertence a lista. 
*/
int posPertence (NodePosicao* lista, int linha, int coluna){
    int r=0; 

    while(lista != NULL && r!=1) {
        if (lista->p.l == linha && lista->p.c == coluna + 1) {
            r=1; 
        } else lista=lista->prox; 
    }
    return r; 
}

/*
 Verifica se duas listas são iguais. 
*/

int listasIguais(NodePosicao* a, NodePosicao* b) {
    int cA = 0, cB = 0;
    int r=42; 

    NodePosicao* pa = a;
    while (pa != NULL && r== 42) {
        cA++;
        if (!posPertence(b, pa->p.l , pa->p.c - 1)) r= 0;
        else pa = pa->prox;
    }

    if (r==42){
 
        NodePosicao* pb = b;
        while (pb != NULL && r==42) {
            cB++;
            if (!posPertence(a, pb->p.l, pb->p.c - 1)) r= 0;
            else pb = pb->prox;
        }    
    }

    if (r!=42) return 0;  
    else return cA==cB; // 1 se são iguais, 0 se diferentes
}

/*
 Verifica se uma determinada lista pertence a um grupo.  
*/

int pertenceAoGrupo(NodePosicao* lista, NodeGrupo* grupo) {
    int r=0; 
    while (grupo != NULL) {
        if (listasIguais(grupo->cabeca, lista)) r= 1;
        grupo = grupo->prox;
    }
    return r;
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

/*
    Libera toda a memória alocada para uma lista encadeada de grupos (`NodeGrupo`).
*/

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

/*
    Libera toda a memória alocada para uma lista encadeada de posições (`NodePosicao`).
*/

void liberaListaPos(NodePosicao* lista) {
    while (lista != NULL) {
        NodePosicao* temp = lista;
        lista = lista->prox;
        free(temp);
    }
}


