#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/dataStructs.h"

int posPertence (NodePosicao* lista, int linha, int coluna); 
int listasIguais (NodePosicao* a, NodePosicao* b);
int pertenceAoGrupo (NodePosicao* lista, NodeGrupo* grupo); 
NodePosicao* adicionarPos (NodePosicao* lista, int linha, int coluna); 
NodeGrupo* adicionarLista (NodeGrupo* grupo, NodePosicao* lista, int mensagem); 
void imprimeLista (NodePosicao* lista); 
void imprimeGrupos (NodeGrupo* lista); 
void liberaGrupos(NodeGrupo* lista);
void liberaListaPos(NodePosicao* lista); 