#include "../include/comandos.h"

/* 
    Recebe como argumentos uma matriz, e uma posição, e põe o elemento que esta na posição a branco. 
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

/* 
    Recebe como argumentos uma matriz, e uma posição, e risca o elemento que esta na posição. 
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

/* 
    Interpreta comandos inseridos pelo utilizador via stdin
    e executa a ação correspondente sobre a matriz fornecida.
  
    Comandos suportados:
    - 's': Sai do jogo (imprime mensagem e retorna 1).
    - 'l <nome>': Lê um ficheiro e carrega o conteúdo na matriz.
    - 'g <nome>': Grava o conteúdo atual da matriz num ficheiro.
    - 'b <linha><coluna>': Coloca a posição especificada em branco (maiúscula).
    - 'r <linha><coluna>': Risca a posição especificada (coloca '#').
    - 'd' : retrocede o último comando executado. 
    - 'v' : verifica o estado do jogo.
    - 'a' : ajuda o jogador. 
    - 'A' : Ajuda o jogador, até não ser mais possíveil. 
    - 'R' : resolve o jogo. 
    - 'D' : Indica o número de casas que não estão de acordo com a solução.
    - 'H' : Ajuda o jogador intercaladamente. 
*/

int escolheComandos(Matriz *m, StackMat *s, Queue *q, char *linha, NodeGrupo** grupos) {
    int i = 0;
    
    while (linha[i] == ' ') i++; 
    char c = linha[i++]; 
     
    if (c == '\0') return 3;

    if (strcmp(linha, "s") == 0) return 1; 
    if (strcmp(linha, "d") == 0) return comandoD(m, s);
    if (strcmp(linha, "v") == 0) return comandoV(m, q, grupos);
    if (c == 'l' || c == 'g') return comandosLG(m, s, linha);
    if (strcmp(linha, "a") == 0) return comandoA(m, s, q, linha);
    if (strcmp(linha, "R") == 0) return comandoR(m, s, q, linha);
    if (strcmp(linha, "H") == 0) { s->ajuda = 1; return 0; }
    if (strcmp(linha, "A") == 0) {
        push(s, m, c); 
        return ajudaSempre(m, q);}
    if (strcmp(linha, "D") == 0) return dicas(m, &s->mInicial, q);
    if (c == 'b' || c == 'r') return comandoRB(m, s, q, linha); 

    return 3; 

}

/* 
    Tenta recuperar o último estado salvo da matriz a partir da pilha 'StackMat'.  
    Caso a pilha esteja vazia, exibe uma mensagem de erro informando que não há comandos para desfazer.
*/

int comandoD (Matriz* m, StackMat* s){

    if (isEmpty(s)) mensagens ("Não há mais comandos para retroceder."); 
    if (!pop(s, m)){
        return 2;
    } 
    return 0;
}

/* 
    Verifica o estado atual da matriz e valida se há um caminho possível. 
    Resultados da verificação:
    - 7: Caminho válido foi encontrado na matriz
    - 8: Nenhum caminho válido foi encontrado
*/

int comandoV (Matriz* m, Queue* q, NodeGrupo** grupos){
    int r=0; 

    verificar(m, grupos);
        int t = verificaCaminho(m, q);
        if (t==1) r = 7; 
        else r = 8; 
 
        return r;
}

/* 
    Executa os comandos de leitura ('l') ou gravação ('g') de ficheiros para a matriz ; 

    Exemplo de uso: 
    - "l exemplo.txt" → carrega dados de "lib/exemplo.txt" e "lib/history/exemplo.txt"
    - "g exemplo.txt" → grava dados em "lib/exemplo.txt" e "lib/history/exemplo.txt"
*/

int comandosLG (Matriz* m, StackMat* s, char* linha){
    int r=0; 
    char* nomeFile;
    int i = 0;

    while (linha[i] == ' ') i++;   // pular espaços
    char c = linha[i++];           // obter 'l' ou 'g'

    while (linha[i] == ' ') i++;
    int len = strlen(&linha[i]);
    if (len == 0) return 3;

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

/* 
    Executa o comando de ajuda, sugerindo uma jogada válida ao jogador.
*/

int comandoA (Matriz* m, StackMat* s, Queue* q, char* linha){
    int r=0; 
    char c = linha[0]; 

    push(s, m, c);
    r = ajuda(m, q);
    if (r == 1)
        return 0;
    else if (r == 0)
        return -1; 
    else
        return r;
}
/*
    Executa o comando de resolução automática da matriz.
*/

int comandoR (Matriz* m, StackMat* s, Queue* q, char* linha){
    int r=0; 
    char c = linha[0]; 

    push(s, m, c);
    r = resolve(m, &s->mInicial, q);
    if (r==1) r=0;
    return r;
}

/* 
    Executa os comandos de riscar ('r') ou pintar de branco ('b') uma posição na matriz.

    Exemplo de entrada válida:
    - r c 3  Risca a casa da coluna 'c' e linha 3
    - b a 1  Pinta de branco a casa da coluna 'a' e linha 1
*/

int comandoRB (Matriz* m, StackMat* s, Queue* q, char* linha){
    int i=0; 
    int pl = 0;
    char pc = '\0'; 
    int r = 0;

    while (linha[i] == ' ') i++;   // pular espaços
    char c = linha[i++];           
    
    push(s, m, c);

        while (linha[i] == ' ') i++;
        pc = linha[i++];

        while (linha[i] == ' ') i++;

        while (linha[i] >= '0' && linha[i] <= '9') {
            pl = (pl * 10) + (linha[i] - '0');
            i++;
        }

        
        if (pc - 'a' < 0 || pc - 'a' >= m->C || pl <= 0 || pl > m->L) {
            mensagens("Posição inválida.");
            return -1;
        }

        while (linha[i]!='\0'){
            if (linha[i] != ' ') {
                mensagens ("Comando inválido."); 
                return -1; 
            } 
            i++; 
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