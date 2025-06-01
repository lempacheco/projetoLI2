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


int branco (Matriz *, Pos, Matriz*);
int riscar (Matriz *, Pos);
int escolheComandos(Matriz *m, StackMat *s, Queue *q, char *linha, NodeGrupo** grupos);
int comandoD(Matriz* m, StackMat* s);
int comandoV(Matriz* m, Queue* q, NodeGrupo** grupos);
int comandosLG(Matriz* m, StackMat* s, char* linha);
int comandoA(Matriz* m, StackMat* s, Queue* q, char* linha);
int comandoR(Matriz* m, StackMat* s, Queue* q, char* linha);
int comandoRB(Matriz* m, StackMat* s, Queue* q, char* linha);

