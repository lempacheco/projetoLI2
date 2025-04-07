#include "../include/comandos.h"


// Problema com a posição (+1)

int branco (Matriz *m, Pos p){
    int l = p.l - 'a'; 
    int c = p.c -1; 

    if (m->matriz[l][c] != '#' && !(isupper(m->matriz[l][c])))
    m->matriz[l][c] = toupper(m->matriz[l][c]); 

    return 0; 
}

int riscar (Matriz *m, Pos p){
    int l = p.l - 'a'; 
    int c = p.c -1; 

    if (!(isupper(m->matriz[l][c])))
    m->matriz[l][c] = '#'; 

    return 0; 
}
 
int escolheComandos (Matriz *m){
    char pl;
    int pc; 
    char c; 
    int r=0; 
    char nomeFile[50];

    if (scanf(" %c", &c)!=1)r=1;        
    if (c == 's') {
        r=1; 
        printf("Saindo do jogo.\n"); 
        return r; 
    }  
    if (c == 'l') {
        if (scanf(" %s", &nomeFile)!=1) r=1; 
        leFicheiro(nomeFile, m); 
        return r; 
    }

    if (scanf(" %c" "%d", &(pl), &pc)!=2) r=1;
    else if (pl-'a' < 0 || pc < 0 || pl-'a' >= (m->L) || pc > (m->C)) {
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


