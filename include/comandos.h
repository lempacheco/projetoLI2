#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <ncurses.h>
#include "../include/condicoes.h"
#include "../include/listasFunc.h"
#include "../include/leFicheiro.h"
#include "../include/dataStructs.h"
#include "../include/gravaFicheiro.h"
#include "../include/stackMats.h"
#include "../include/condicoes.h"
#include "../include/listasFunc.h"
#include "../include/resolve.h"
#include "../include/ajuda.h"
#include "../include/mensagens.h"
#include "../include/interface.h"
#include "../include/dicas.h"

#define RET_INVALIDO -1
#define RET_OK 0
#define RET_SAIR 1
#define RET_DESFAZ 2
#define RET_COMANDO_DESCONHECIDO 3


int branco (Matriz *, Pos, Matriz*);
int riscar (Matriz *, Pos);
int escolheComandosFromString(Matriz *m, StackMat *s, Queue *q, const char *linha, NodeGrupo** grupos);
int retroceder(Matriz *, StackMat *); 