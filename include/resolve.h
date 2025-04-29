#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/dataStructs.h"
#include "../include/stackMats.h"
#include "../include/ajuda.h"
#include "../include/condicoes.h"


void resolveTabuleiro(Matriz* m, Queue* q); 
int resolverDuplicadosControlado(Matriz* m, Queue* q);
void aplicarPadraoAAA (Matriz* m); 
void aplicarPadraoABA(Matriz* m); 
int resolverTentativa(Matriz* m, Queue* q, int i1, int j1, int i2, int j2);