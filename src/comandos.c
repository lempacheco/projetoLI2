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

int escolheComandosFromString(Matriz *m, StackMat *s, Queue *q, const char *linha, NodeGrupo** grupos) {
    int pl = 0;
    char pc = '\0'; 
    int r = 0;
    char* nomeFile;
    int i = 0;
    char c;
     
    // Pula espaços iniciais
    while (linha[i] == ' ') i++;
    c = linha[i++];

    if (c == '\0') return RET_COMANDO_DESCONHECIDO;

    if (c == 's') return 1;

    if (c == 'd') {
        if (!pop(s, m)) return RET_DESFAZ;
        return 0;
    }

    if (c == 'v') {
  
        int t = 0; 
        
        verificar(m, grupos);
        t = verificaCaminho(m, q);
        if (t==1) r=7; 
        else r = 8;  
 
        return r; 
    }

    if (c == 'l' || c == 'g') {
        while (linha[i] == ' ') i++;
        int len = strlen(&linha[i]);
        if (len == 0) return RET_COMANDO_DESCONHECIDO;

        nomeFile = malloc(len + 1);
        strcpy(nomeFile, &linha[i]);

        char* caminhoM = malloc(len + 5);
        strcpy(caminhoM, "lib/");
        strcat(caminhoM, nomeFile);

        char* caminhoS = malloc(len + 14);
        strcpy(caminhoS, "lib/history/");
        strcat(caminhoS, nomeFile);

        if (c == 'l')
            r = leFicheiro(caminhoM, caminhoS, m, s);
        else
            r = gravaFicheiro(caminhoM, caminhoS, m, s);

        free(nomeFile);
        free(caminhoM);
        free(caminhoS);
        return r;
    }

    if (c == 'a') {
        push(s, m, c);
        r = ajuda(m, q);
        return (r == 1) ? 0 : r;
    }

    if (c == 'R') {
        push(s, m, c);
        resolve(m, q);
        return 0;
    }

    if (c == 'A') {
        s->ajuda = 1;
        return 0;
    }

    if (c == 'b' || c == 'r') {
        push(s, m, c);

        while (linha[i] == ' ') i++;
        pc = linha[i++];

        while (linha[i] == ' ') i++;

        while (linha[i] >= '0' && linha[i] <= '9') {
            pl = (pl * 10) + (linha[i] - '0');
            i++;
        }

        if (pc - 'a' < 0 || pc - 'a' >= m->C || pl <= 0 || pl > m->L) {
            mensagens("Comando inválido");
            return RET_COMANDO_DESCONHECIDO;
        }

        Pos p = {pl, pc - 'a' + 1};
        if (c == 'b') {
            r = branco(m, p, &s->mInicial);
            if (s->ajuda == 1) ajuda(m, q);
        } else {
            r = riscar(m, p);
            if (s->ajuda == 1) ajuda(m, q);
        }

        return r;
    }

    return RET_COMANDO_DESCONHECIDO;
}

