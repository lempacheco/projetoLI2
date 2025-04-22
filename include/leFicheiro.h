#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "../include/dataStructs.h"
#include "../include/stackMats.h"


int leFicheiro(char* nome, Matriz *m, StackMat* s);
void leMatriz(Matriz* m, FILE* fp);