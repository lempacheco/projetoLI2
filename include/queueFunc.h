#pragma once

#include "../include/dataStructs.h"
#include <stdlib.h>
#include <stdio.h>

int dequeue (Queue *dq, Pos *x); 
void enqueue (Queue *dq, Pos p); 
int isEmptyQ (Queue *dq); 
void initQueue (Queue *dq); 
void liberaQueue (Queue *q); 
Queue copiaQueue(Queue* q); 