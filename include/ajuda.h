#pragma once

#include <stdlib.h>
#include <ctype.h>
#include "../include/dataStructs.h"
#include "../include/comandos.h"
#include "../include/condicoes.h"
#include "../include/resolve.h"
#include "../include/stackMats.h"

int ajuda(Matriz* m, Queue* q, int mostraMensagem);
void riscarIguaisDeLetraBranca(Matriz* m, NodeGrupo** grupos);
void pintarVizinhosDeRiscadas(Matriz* m, NodeGrupo** grupos);
void manterCaminho(Matriz* m, Queue* q, NodeGrupo** grupos);
int saoIguais(Matriz* m1, Matriz* m2);
void tentaPintar(Matriz* m, int i, int j, NodeGrupo** grupos); 
int ajudaSempre(Matriz* m, Queue* q);