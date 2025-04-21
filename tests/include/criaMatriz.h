#pragma once

#include <stdio.h> 
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../../include/dataStructs.h"
#include "../../include/stackMats.h"


Matriz criaMatriz (int linhas, int colunas, char elemMatriz[linhas][colunas]); 
void comparaMatrizes(Matriz* m1, Matriz* m2);
StackMat criaStackMat (int cabeca, int tam, int linhas, int colunas, char arrDados[tam][linhas][colunas], char* comandos);
void comparaStackMats(StackMat* s1, StackMat* s2);
StackG criaStackG (int cabeca, int tam,int* jaExistia, int* lenNomes,char** nomesFicheiros, int linhas, int colunas, char arrDados[tam][linhas][colunas]);
void comparaStackG(StackG* s1,StackG* s2);