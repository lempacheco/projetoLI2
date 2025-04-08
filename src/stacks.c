#include "../include/dataStructs.h"
#include "../include/stacks.h"

int push (Stack *s, char c){
    
    if (s->cabeca < s-> tam) {
        s-> dados[s->cabeca++] = c; return 0; 
    } else {
        s->tam++; 
        s->dados = realloc (s->dados, sizeof(char)*s->tam); 
    }

    return 0; 
}

