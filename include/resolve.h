#include <stdio.h>
#include <stdlib.h>
#include "../include/dataStructs.h"

typedef struct rep{
    int freq;
    char simbolo;
    int* i;
    int* j;
}Rep;

void resolveTabuleiro(Matriz* m);
void encontraRep(Matriz* m, Rep* rep, int a, int b);
void realocaRep(Rep* rep, int tamRep);
void realocaIJ(Rep* rep, int i);
int existe(char c, Rep* rep, int tamRep);