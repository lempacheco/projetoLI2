#include <stdlib.h>
#include "../include/condicoes.h"
#include "../include/listasFunc.h"
#include "../include/comandos.h"


// Problema com a posição (+1)

/* Recebe como argumentos uma matriz, e uma posição, e põe o elemento que esta na posição a branco. 
   Isto é, coloca o caracter em maiúsculas. 
*/

int branco (Matriz *m, Pos p){
    int l = p.l - 'a'; 
    int c = p.c -1; 

    if (l < 0 || c < 0 || l >= m->L || c >= m->C) {
        return 1;
    } else if (m->matriz[l][c] != '#' && !(isupper(m->matriz[l][c]))) {
        m->matriz[l][c] = toupper(m->matriz[l][c]); 
    }
    return 0; 
}

/* Recebe como argumentos uma matriz, e uma posição, e risca o elemento que esta na posição. 
   Isto é, substitui o caracter para '#'. 
*/

int riscar (Matriz *m, Pos p){
    int l = p.l - 'a'; 
    int c = p.c - 1;

    if (l < 0 || c < 0 || l >= m->L || c >= m->C) {
        return 1;
    } else if (!(isupper(m->matriz[l][c]))) {
        m->matriz[l][c] = '#'; 
    }

    return 0; 
}

/* Interpreta comandos inseridos pelo utilizador via stdin
  e executa a ação correspondente sobre a matriz fornecida.
  
  Comandos suportados:
  - 's': Sai do jogo (imprime mensagem e retorna 1).
  - 'l <nome>': Lê um ficheiro e carrega o conteúdo na matriz.
  - 'g <nome>': Grava o conteúdo atual da matriz num ficheiro.
  - 'b <linha><coluna>': Coloca a posição especificada em branco (maiúscula).
  - 'r <linha><coluna>': Risca a posição especificada (coloca '#').
*/

int escolheComandos (Matriz *m, StackMat *s){
    char pl;
    int pc; 
    char c; 
    int r=0; 
    char* nomeFile;
    int i;

    c = fgetc(stdin);
    while (c == ' ' || c == '\n') c = fgetc(stdin);
    if (c == 0)r=1; 
    if (c == 's') { 
        r=1; 
        printf("Saindo do jogo.\n"); 
        return r; 
    }  
    if (c == 'd') {
        if (!pop(s, m)) printf("Retrocedendo...");  
        return r;
    }
    if (c == 'v') {
        NodeGrupo* grupos = NULL;
        verificar(m, &grupos);
        imprimeGrupos(grupos);
        liberaGrupos(grupos); 
        return r; 
        
    }
    if (c == 'l') {
        push(s, m, c); 
        nomeFile = malloc(sizeof(char));
        nomeFile[0] = getchar(); //ignora o espaço
        for (i=0; (nomeFile[i] = getchar())!='\n'; i++){
            nomeFile = realloc(nomeFile, sizeof(char)*(i+2));
        }
        nomeFile[i] = '\0';
        char* caminho = malloc(sizeof(char)*(i+5));
        strcpy(caminho, "lib/");
        strcat(caminho, nomeFile); 

        leFicheiro(caminho, m, s);
        free(nomeFile);
        free(caminho);
        return r; 
    }
    if (c == 'g') {
        push(s, m, c); 
        nomeFile = malloc(sizeof(char));
        nomeFile[0] = getchar(); //ignora o espaço
        for (i=0; (nomeFile[i] = getchar())!='\n'; i++){
            nomeFile = realloc(nomeFile, sizeof(char)*(i+2));
        }
        nomeFile[i] = '\0';
        char* caminho = malloc(sizeof(char)*(i+5));
        strcpy(caminho, "lib/");
        strcat(caminho, nomeFile); 

        gravaFicheiro(caminho, m, s); 
        free(nomeFile);
        free(caminho);
        return r; 
    }

    if (scanf(" %c" "%d", &pl, &pc)!=2) r=1;
    else if (pl-'a' < 0 || pc < 0 || pl-'a' >= (m->L) || pc > (m->C)) {
        r=1; 
    }
    else {
        Pos p = {pl, pc}; 
        if (c == 'b') {
            push(s, m, c);  
            branco(m, p);
            r=0; 
        } 
        else if (c == 'r') {
            push(s, m, c);  
            riscar(m, p);
            r=0; 
        }
        else printf("Comando inválido\n"); 
    }

    return r; 

}
