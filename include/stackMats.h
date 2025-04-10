#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "../include/dataStructs.h"

void init(StackMat *s);
int isFull(StackMat *s);
int isEmpty(StackMat *s);
void push(StackMat *s, Matriz *m);
void pop(StackMat *s, Matriz* r);
void copiaMatriz(Matriz* dest, Matriz* src);