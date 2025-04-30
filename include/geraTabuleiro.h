#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "../include/dataStructs.h"
#include "../include/stackMats.h"
#include "../include/condicoes.h"

void geraTabuleiro(Matriz* m);
void geraTabuleiroAleatorio(Matriz* m);
int max(int a, int b);
void procuraSolucoes(Matriz* m, char*** solutions, int* solution_count);
void backtrack(int pos, int** is_white, int* solution_count, char*** solutions, Matriz* m);
int can_be_white(int row, int col, Matriz* m, int** is_white);
void save_solution(int* solution_count, char*** solutions, Matriz* m, int** is_white);
int valid_config(int** is_white, int N, int M);
int all_white_connected(int** is_white, int N, int M);