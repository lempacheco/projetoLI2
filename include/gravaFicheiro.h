#include "../include/dataStructs.h"
#include "../include/leFicheiro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gravaFicheiro(char*, char*, Matriz*, StackMat*);
int gravaMatriz(Matriz* m, FILE* fp);
int gravaStackMat(StackMat* s, FILE* fp);