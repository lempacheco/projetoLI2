#pragma once

#include <stdlib.h>
#include <ctype.h>
#include "../include/dataStructs.h"
#include "../include/comandos.h"
#include "../include/condicoes.h"
#include "../include/stackMats.h"

int ajuda(Matriz* m, Queue* q);
int riscarIguaisDeLetraBranca(Matriz* m, NodeGrupo** grupos);
int pintarVizinhosDeRiscadas(Matriz* m, NodeGrupo** grupos);
int manterCaminho(Matriz* m, Queue* q, NodeGrupo** grupos);