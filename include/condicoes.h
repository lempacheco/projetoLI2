#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/dataStructs.h"

int verifRiscadaOrt (Matriz *m, int J, int I, NodeGrupo** grupo); 
int verifBranco (Matriz *m, int J, int I, NodeGrupo** grupo); 
int verificar (Matriz *m, NodeGrupo** grupo); 
