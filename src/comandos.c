#include "../include/comandos.h"

// Problema com a posição (+1)

int branco (Matriz *m, Pos p){
    
    if (m->matriz[p.l][p.c] != '#' && !(isupper(m->matriz[p.l][p.c])))
    m->matriz[(p.l)-1][(p.c)-1] = toupper(m->matriz[(p.l)-1][(p.c)-1]); 

    return 0; 
}

int riscar (Matriz *m, Pos p){
    
    if (!(isupper(m->matriz[p.l][p.c])))
    m->matriz[(p.l)-1][(p.c)-1] = '#'; 

    return 0; 
}
 
int escolheComandos (Matriz *m){
    int pl, pc; 
    char c; 
    int r=0; 

    if (scanf(" %c", &c)!=1)r=1;        
    if (c == 's') {
        r=1; 
        printf("Saindo do jogo.\n"); 
        return r; 
    }  

    if (scanf("%d" "%d", &pl, &pc)!=2) r=1;
    else if (pl < 0 || pc < 0 || pl >= (m->L) || pc >= (m->C)) {
        r=1; 
    }
    else {
        Pos p = {pl, pc}; 
        if (c == 'b') {
            branco(m, p);
            r=0; 
        } 
        else if (c == 'r') {
            riscar(m, p);
            r=0; 
        }
        else printf("Comando inválido\n"); 
    }

    return r; 

}


