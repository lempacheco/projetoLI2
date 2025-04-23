#pragma once

#include <stdlib.h>
#include <ctype.h>
#include "../include/dataStructs.h"
#include "../include/comandos.h"
#include "../include/condicoes.h"

int ajuda(Matriz* m, Queue* q);
void riscarIguaisDeLetraBranca(Matriz* m, NodeGrupo** grupos);
void pintarVizinhosDeRiscadas(Matriz* m, NodeGrupo** grupos);
void manterCaminho(Matriz* m, Queue* q, NodeGrupo** grupos);