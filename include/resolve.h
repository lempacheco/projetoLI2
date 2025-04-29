#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/dataStructs.h"
#include "../include/stackMats.h"
#include "../include/ajuda.h"
#include "../include/condicoes.h"

typedef struct grupo{
    Pos p1;
    Pos p2;
    Pos p3;
    int b; //1 - ABA; 0 - AAXA;
}Grupo;

typedef struct grupos{
    Grupo* gs;
    int cab;
    int tam;
}Grupos;

int resolve(Matriz* m, Queue* q);
int encontraABA(Matriz* m, Grupos* caminho);
int encontraAAXA(Matriz* m, Grupos* caminho);
void resolveABA(Matriz* m, Grupos* caminho);
void resolveAAXA(Matriz* m, Grupos* caminho);
int retrocedeCaminho(Matriz* m, Matriz* mInicial, Grupos* caminho);
int ganhou(Matriz* m);
void tudoBranco(Matriz* m);