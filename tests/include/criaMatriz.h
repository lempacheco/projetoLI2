#pragma once

#include <stdio.h> 
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../../include/dataStructs.h"
#include "../../include/stackMats.h"
#include "../../include/listasFunc.h"


Matriz criaMatriz (int linhas, int colunas, char elemMatriz[linhas][colunas]); 
void comparaMatrizes(Matriz* m1, Matriz* m2);
StackMat criaStackMat (int cabeca, int tam, int linhas, int colunas, char arrDados[tam][linhas][colunas], char* comandos);
void comparaStackMats(StackMat* s1, StackMat* s2);
NodePosicao* criarListaCom(Pos posicoes[], int n);