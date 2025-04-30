#include "../include/comandos.h"

// Problema com a posição (+1)

/* Recebe como argumentos uma matriz, e uma posição, e põe o elemento que esta na posição a branco. 
   Isto é, coloca o caracter em maiúsculas. 
*/

int branco (Matriz *m, Pos p, Matriz* mInicial){
    int l = p.l - 1; 
    int c = p.c - 1; 

    if (l < 0 || c < 0 || l >= m->L || c >= m->C) {
        return 1;
    } else if(isupper(m->matriz[l][c])){
        mensagens("Casa já está branca."); 
        return -1;
    } else if(m->matriz[l][c] == '#'){
        m->matriz[l][c] = toupper(mInicial->matriz[l][c]); 
    }else{
        m->matriz[l][c] = toupper(m->matriz[l][c]);
    }
    return 0; 
}

/* Recebe como argumentos uma matriz, e uma posição, e risca o elemento que esta na posição. 
   Isto é, substitui o caracter para '#'. 
*/

int riscar (Matriz *m, Pos p){
    int l = p.l - 1; 
    int c = p.c - 1;

    if (l < 0 || c < 0 || l >= m->L || c >= m->C) {
        return 1;
    } else if(m->matriz[l][c]== '#') {
        mensagens ("Casa já está riscada.");
        return -1; 
    } else m->matriz[l][c] = '#'; 

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

int escolheComandos (Matriz *m, StackMat *s, Queue *q){
    int pl = 0;
    char pc = '\0'; 

    char c; 
    int r=0; 
    char* nomeFile;
    int i;

    c = fgetc(stdin);
    while (c == ' ' || c == '\n') c = fgetc(stdin);

    if (c == 0) r = RET_COMANDO_DESCONHECIDO; 

    if (c == 's') { 
        return 1; 
    }  

    if (c == 'd') {
        if (!pop(s, m)) {
            return RET_DESFAZ;  
        }
        return 0;
    }
    
    /* if (c == 'v') {
        int t = 0; 
        NodeGrupo* grupos = NULL;
        int absald = verificar(m, &grupos);
        t = verificaCaminho(m, q);
        if (t==1){
            printf("\nExiste um caminho ortogonal entre quaisquer duas casas brancas no tabuleiro.\n"); 
        } else {
            printf("\nNão existe um caminho ortogonal entre quaisquer duas casas brancas no tabuleiro.\n"); 
        }

        imprimeGrupos(grupos);
        liberaGrupos(grupos); 
        return r; 
        
    } */

    if (c == 'l') {
        push(s, m, c); 
        nomeFile = malloc(sizeof(char));
        nomeFile[0] = getchar(); //ignora o espaço
        for (i=0; (nomeFile[i] = getchar())!='\n'; i++){
            nomeFile = realloc(nomeFile, sizeof(char)*(i+2));
        }
        nomeFile[i] = '\0';
        char* caminhoM = malloc(sizeof(char)*(i+5));
        strcpy(caminhoM, "lib/");
        strcat(caminhoM, nomeFile); 

        char* caminhoS = malloc(sizeof(char)*(i+14));
        strcpy(caminhoS, "lib/history/");
        strcat(caminhoS, nomeFile); 

        r = leFicheiro(caminhoM, caminhoS, m, s);
        free(nomeFile);
        free(caminhoM);
        free(caminhoS);
        return r; 
    }

    if (c == 'g') {

        nomeFile = malloc(sizeof(char));
        nomeFile[0] = getchar(); //ignora o espaço
        for (i=0; (nomeFile[i] = getchar())!='\n'; i++){
            nomeFile = realloc(nomeFile, sizeof(char)*(i+2));
        }
        nomeFile[i] = '\0';
        char* caminhoM = malloc(sizeof(char)*(i+5));
        strcpy(caminhoM, "lib/");
        strcat(caminhoM, nomeFile); 

        char* caminhoS = malloc(sizeof(char)*(i+14));
        strcpy(caminhoS, "lib/history/");
        strcat(caminhoS, nomeFile); 

        r = gravaFicheiro(caminhoM, caminhoS, m, s); 
        free(nomeFile);
        free(caminhoM);
        free(caminhoS);
        return r; 
    }

    if (c == 'a') { 
        push(s,m,c);
        r = ajuda(m, q);
        if (r==1) r=0;
        return r; 
    }

    if (c == 'R') { 
        push(s,m,c);
        resolve(m, q); 
        return 0; 
    }

    if (c == 'A'){
        s->ajuda = 1; // ativou

    }

    if (c == 'G'){
        push(s,m,c);
        geraTabuleiro(m); 
        return 0; 
    }
 
    if (c == 'r' || c == 'b'){
        push(s, m, c);

        char comando = getchar();

        while (comando == ' ' || comando == '\n') {
            if (comando == '\n') return -1;
            comando = getchar();
        }
        
        pc = comando;
        comando = getchar();

        while (comando == ' ' || comando == '\n') {
            if (comando == '\n') return -1;
            comando = getchar();
        }
        
        while (comando >= '0' && comando <= '9') {
            pl = (pl * 10) + (comando - '0');
            comando = getchar();
        }

        if (pc - 'a' < 0 || pc - 'a' >= m->C || pl <= 0 || pl > m->L) {
            mensagens("Comando inválido");
        } else {
            Pos p = {pl, pc - 'a' + 1}; 
            if (c == 'b') {
                r = branco(m, p, &s->mInicial);
                if (s->ajuda == 1){
                    ajuda(m,q); 
                }
            } 
            else if (c == 'r') {
                r = riscar(m, p);
                if (s->ajuda == 1){
                    ajuda(m,q); 
                }
            } else {
                mensagens("Comando inválido");
            }
        }
    
    }

    if (c != 'a' && c != 'r' && c != 'b' && c != 'v' && c != 'g' && c != 'l' && c != 'd' && c != 's' && c!='A' && c != 'R' && c != 'G'){
        r = RET_COMANDO_DESCONHECIDO; 
    }

    return r; 

}
