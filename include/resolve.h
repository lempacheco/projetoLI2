#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/dataStructs.h"
#include "../include/stackMats.h"
#include "../include/ajuda.h"
#include "../include/condicoes.h"


void resolveTabuleiro(Matriz* m, Queue* q); 
int posicaoPertence(Pos* array, int tamanho, Pos p);
int encontraPrimeiroRepetido(Matriz* m, Pos* p1, Pos* p2, int a, int b); 
int ganhou(Matriz* m); 