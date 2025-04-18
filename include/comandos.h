#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/leFicheiro.h"
#include "../include/dataStructs.h"
#include "../include/gravaFicheiro.h"
#include "../include/stackMats.h"


int mostraMatriz (Matriz *);
int branco (Matriz *, Pos);
int riscar (Matriz *, Pos);
int escolheComandos (Matriz *, StackMat *);
int retroceder(Matriz *, StackMat *); 