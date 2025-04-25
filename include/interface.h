#include <ncurses.h>
#include <stdio.h>
#include "../include/comandos.h"
#include "../include/output.h"

int escolheComandosNcurses(Matriz *m, StackMat *s, Queue *q, int *scrollLinha, int *scrollColuna); 
void imprimeGruposNcurses(NodeGrupo* grupo, int* linha); 
void imprimeCabecaNcurses(NodePosicao* lista, int* linha);
void imprimeCaudaNcurses(NodePosicao* lista, int* linha); 