#include "../include/dataStructs.h"
#include "../include/stacks.h"

int push(Stack *s, char c) {
    if (s->cabeca < s->tam) {
        s->dados[s->cabeca++] = c;
        return 0;
    }

    int novoTam = s->tam + 1;
    char *novoDados = realloc(s->dados, sizeof(char) * novoTam);

    if (novoDados == NULL) {
        return -1; // erro de alocação
    }

    s->dados = novoDados;
    s->tam = novoTam;

    s->dados[s->cabeca++] = c;

    return 0;
}
