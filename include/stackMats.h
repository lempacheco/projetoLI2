#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dataStructs.h"

void initStackMat(StackMat *s);
int isFull(StackMat *s);
int isEmpty(StackMat *s);
void liberaMatriz(Matriz *m);
void liberaStackMat(StackMat *s); 
void liberaStackG(StackG* sg);
void push(StackMat *s, Matriz *m, char comando);
void pushG(StackG *sg, int b, char* nomeFile, int lenNome);
int pop(StackMat *s, Matriz* r);
void popG(StackG* sg);
void copiaMatriz(Matriz* dest, Matriz* src);
void initMatriz(Matriz* m);
void initStackG(StackG* sg);