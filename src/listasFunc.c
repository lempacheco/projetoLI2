#include "../include/listasFunc.h"

// node* lista = NULL; 
//TODO: verificar se o elemento já esta na lista, e não adicionar.

int posPertence (NodePosicao* lista, int linha, int coluna){
    
    while(lista != NULL) {
        if (lista->p.l == linha && lista->p.c == coluna + 1) {
            return 1; 
        }

        lista=lista->prox; 
    }
    return 0; 
}

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

int pertenceAoGrupo(NodePosicao* lista, NodeGrupo* grupo) {
    while (grupo != NULL) {
        if (listasIguais(grupo->cabeca, lista)) return 1;
        grupo = grupo->prox;
    }
    return 0;
}

// deve adicionar no final 
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

/* NodePosicao* ordenaLista (NodePosicao* lista) {
    if (lista == NULL) return lista; 
    
    int trocou = 1; 

    while (trocou) {
        trocou=0; 
        NodePosicao* atual = lista; 

        for(; atual->prox !=NULL && trocou; atual=atual->prox) {

            NodePosicao* prox = atual->prox;

            // Comparar: primeiro por linha (char), depois por coluna (int)
            if (atual->p.l > prox->p.l || (atual->p.l == prox->p.l && atual->p.c > prox->p.c)) {
                
                Pos temp = atual->p; 
                atual->p = prox->p;
                prox->p = temp;  
                
                trocou=1; 
            }
        }
        atual=NULL; 
    } 

    return lista; 
} */

void imprimeCauda (NodePosicao* lista) {
    if (lista == NULL) {
        printf("  (nenhuma posição)\n");
        return;
    }

    NodePosicao* atual = lista->prox; 
  
    while (atual != NULL) {
        printf(" (%c, %d)\n", (atual->p.l)+'a', atual->p.c); 
        atual = atual->prox; 
    }
}


void imprimeCabeca (NodePosicao* lista){
    if (lista != NULL)
        printf(" (%c, %d) ", (lista->p.l) + 'a', lista->p.c); 
}
    

void imprimeGrupos (NodeGrupo* grupo) {
    
    if (grupo == NULL) {
        printf("Não houve quaisquer posições inválidas atingidas.\n"); 
    }

    NodeGrupo* atualGrupo = grupo;

    while (atualGrupo != NULL) {
        if (atualGrupo->m == 0) {
            printf("A posicão");
            imprimeCabeca(atualGrupo->cabeca);
            printf("tem as seguintes posições riscadas na ortogonal:\n");
            imprimeCauda(atualGrupo->cabeca);

        } else if (atualGrupo->m == 1) {
            printf("As seguintes posições estão brancas duplicadas na mesma linha/coluna:\n");
            imprimeCabeca(atualGrupo->cabeca);
            printf("\n"); 
            imprimeCauda(atualGrupo->cabeca); 

        } else {
            printf("Tipo de restrição desconhecido:\n");
        }

        
        atualGrupo = atualGrupo->prox;
        printf("\n");
    }
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


