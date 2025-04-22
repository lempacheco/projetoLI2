#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/dataStructs.h"
#include "../include/queueFunc.h"
#include "../include/listasFunc.h"

int verifRiscadaOrt (Matriz *m, int J, int I, NodeGrupo** grupo); 
int verifBranco (Matriz *m, int J, int I, NodeGrupo** grupo); 
int verificar (Matriz *m, NodeGrupo** grupo); 
int verificaCaminho (Matriz *m, Queue *q); 
