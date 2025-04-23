#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/condicoes.h"
#include "../include/listasFunc.h"
#include "../include/leFicheiro.h"
#include "../include/dataStructs.h"
#include "../include/gravaFicheiro.h"
#include "../include/stackMats.h"
#include "../include/condicoes.h"
#include "../include/listasFunc.h"
#include "../include/resolve.h"


int mostraMatriz (Matriz *);
int branco (Matriz *, Pos, Matriz*);
int riscar (Matriz *, Pos);
int escolheComandos (Matriz *, StackMat *, Queue *q);
int retroceder(Matriz *, StackMat *); 