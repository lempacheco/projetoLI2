#include "../include/dataStructs.h"
#include "../include/leFicheiro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gravaFicheiro(char*, Matriz*);
void existeFicheiro(char* nomeFile, int lenNome, StackG* sg);
void retrocedeG(StackG* sg);