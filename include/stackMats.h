#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dataStructs.h"
#include "../include/mensagens.h"

void initStackMat(StackMat *s);
int isFull(StackMat *s);
int isEmpty(StackMat *s);
void liberaMatriz(Matriz *m);
void liberaStackMat(StackMat *s); 
void push(StackMat *s, Matriz *m, char comando);
int pop(StackMat *s, Matriz* r);
void copiaMatriz(Matriz* dest, Matriz* src);
void initMatriz(Matriz* m);