#include "../include/interface.h"

/*
    Imprime a *cauda* (demais elementos) de uma lista de posições na interface `ncurses`.

    Esta função ignora o primeiro elemento da lista e imprime todas as demais posições
    no formato `(letra, número)`.
*/
void imprimeCaudaNcurses(NodePosicao* lista, int* linha) {
    if (lista == NULL || lista->prox == NULL) {
        mvprintw((*linha)++, 3, "(nenhuma posição)");
        return;
    }

    NodePosicao* atual = lista->prox;
    while (atual != NULL) {
        mvprintw((*linha)++, 3, "(%c, %d)", atual->p.l + 'a', atual->p.c);
        atual = atual->prox;
    }
}

/*
    Imprime a *cabeça* de uma lista de posições na interface `ncurses`, usando coordenadas no formato `(letra, número)`. 

*/

void imprimeCabecaNcurses(NodePosicao* lista, int* linha) {
    if (lista != NULL) {
        mvprintw((*linha)++, 3, "(%c, %d)", lista->p.l + 'a', lista->p.c);
    }
}

/*
    Imprime os grupos de posições inválidas na matriz usando a interface `ncurses`.

    Esta função percorre uma lista de grupos (`NodeGrupo*`) que representam violações às regras do jogo. 
    Para cada grupo, imprime uma descrição com base no tipo de restrição:
    
    - m == 0: Grupo de posições riscadas (`#`) ligadas ortogonalmente — imprime a posição principal (cabeça)
    e as demais posições relacionadas (cauda).
    - m == 1: Grupo de posições com letras maiúsculas repetidas na mesma linha ou coluna — imprime todas
    as posições envolvidas.
    - Outro valor de m: Considerado tipo desconhecido.
 
    As posições são exibidas no formato `(letra, número)`.
 
*/

void imprimeGruposNcurses(NodeGrupo* grupo, int* linha) {
    if (grupo == NULL) {
        mvprintw((*linha)++, 0, "Não houve quaisquer posições inválidas atingidas.");
        return;
    }

    NodeGrupo* atualGrupo = grupo;

    while (atualGrupo != NULL) {
        if (atualGrupo->m == 0 && atualGrupo->cabeca != NULL) {
            mvprintw((*linha)++, 0,
                "A posição (%c,%d) tem as seguintes posições riscadas na ortogonal:",
                atualGrupo->cabeca->p.l + 'a', atualGrupo->cabeca->p.c);

            imprimeCaudaNcurses(atualGrupo->cabeca, linha);

        } else if (atualGrupo->m == 1 && atualGrupo->cabeca != NULL) {
            mvprintw((*linha)++, 0,
                "As posições estão brancas duplicadas na mesma linha/coluna:");

            // imprime a cabeça na coluna 3
            mvprintw((*linha)++, 3, "(%c,%d)",
                atualGrupo->cabeca->p.l + 'a', atualGrupo->cabeca->p.c);

            // imprime a cauda na coluna 3
            NodePosicao* atual = atualGrupo->cabeca->prox;
            while (atual != NULL) {
                mvprintw((*linha)++, 3, "(%c,%d)", atual->p.l + 'a', atual->p.c);
                atual = atual->prox;
            }

        } else {
            mvprintw((*linha)++, 0, "Tipo de restrição desconhecido.");
        }

        (*linha)++; // linha em branco entre grupos
        atualGrupo = atualGrupo->prox;
    }
}

/*
    Exibe um tutorial com comandos e regras do jogo usando `ncurses`.

    Limpa a tela e apresenta uma lista de comandos disponíveis no jogo, bem como as principais regras de funcionamento.
*/

void mostraTutorial() {

    clear();

    attron(COLOR_PAIR(1));
    attron(A_BOLD);
    mvprintw(1, 0, "TUTORIAL");
    mvprintw(3, 0, "COMANDOS:");
    attroff(COLOR_PAIR(1));
    attroff(A_BOLD);

    char *linhas[] = {
        "g (ficheiro) -> grava o estado atual do jogo num ficheiro",
        "l (ficheiro) -> lê um jogo guardado em um ficheiro",
        "b <letra><número> -> coloca a coordenada em maiúscula",
        "r <letra><número> -> risca a coordenada",
        "v -> verifica restrições",
        "a -> ajuda o jogador",
        "A -> aplica ajuda enquanto possível",
        "D -> indica o número de casa incorretas em relação à resolução do tabuleiro", 
        "H -> ativa ajuda intercalada", 
        "R -> resolve o tabuleiro",
        "d -> desfazaz o último comando executado", 
        "s -> sai do jogo"
    };

    for (int i = 0; i < 12; i++) mvprintw(4 + i, 2, "%s", linhas[i]);

    attron(COLOR_PAIR(1));
    attron(A_BOLD);
    mvprintw(16, 0, "REGRAS DO JOGO:");
    attroff(COLOR_PAIR(1));
    attroff(A_BOLD);

    mvprintw(17, 2, "Cada casa contém um símbolo (uma letra inicialmente minúscula);");
    mvprintw(18, 2, "Apenas uma réplica por linha/coluna pode estar em branco;");
    mvprintw(19, 2, "Todas as outras réplicas desse símbolo têm que ser riscadas (substituídas por um cardinal);");
    mvprintw(20, 2, "Cada casa riscada exige vizinhos ortogonais brancos;");
    mvprintw(21, 2, "Caminho ortogonal entre todas as casas brancas é necessário;");

    mvprintw(LINES - 2, 0, "ENTER para continuar...");
    refresh();
    while (getch() != '\n');

}
/*
    Executa ações no terminal com base no comando inserido e no valor do resultado `r`.

    valores de retorno:
    -  1: Indica que o jogo deve ser encerrado.
    - -1: Indica que a matriz não deve ser adicionado a stack.
    -  0: Comando tratado normalmente.

    Também lida com mensagens associadas aos valores de retorno:
    -  1: Exibe mensagem de saída.
    -  2: Exibe a mensagem "desfazendo...".
    -  3: Exibe a mensagem "comando desconhecido".
    - -1: Representa erro.
*/

int executaComando(char *linha, int r, NodeGrupo *grupos) {
    if (strcmp(linha, "D") == 0) {
        mvprintw(LINES - 1, 0, "Existe %d casa(s) errada(s).", r);
        refresh(); napms(1000);
        return 0;
    }
   
    if (strcmp(linha, "v") == 0) {
        clear(); int l = 0;
        mvprintw(l++, 0, r == 7 ? "Existe um caminho ortogonal entre todas as casas brancas." : "Não existe caminho ortogonal entre todas as casas brancas.");
        l++;
        imprimeGruposNcurses(grupos, &l);
        liberaGrupos(grupos);
        mvprintw(LINES - 2, 0, "ENTER para continuar...");
        refresh(); while (getch() != '\n');
        return 0;
    }
   
    if (r == 1) {
        clear(); mvprintw(LINES - 1, 0, "Saindo do jogo...");
        refresh(); napms(1000);
        return 1;
    }
   
    if (r == 2) {
        mvprintw(LINES - 1, 0, "Desfazendo..."); refresh(); napms(500);
    } else if (r == 3) {
        mvprintw(LINES - 1, 0, "Comando desconhecido."); refresh(); napms(500);
    }
   
    return (r == -1) ? -1 : 0;
}

/*
    Esta função exibe a matriz do jogo e permite ao jogador digitar comandos,
    que são interpretados e executados. Também permite navegar na matriz com as setas
    do teclado e acessar o tutorial com o comando `t`.
*/

int escolheComandosNcurses(Matriz *m, StackMat *s, Queue *q, int *scrollLinha, int *scrollColuna) {
    char linha[100] = ""; 
    int pos = 0;
    int r1=42; 
    NodeGrupo *grupos = NULL;

    noecho();
    keypad(stdscr, TRUE);

    while (r1==42) {
        
        clear();
        mostraMatriz(m, *scrollLinha, *scrollColuna);
        mvprintw(LINES - 3, 0, "Digite o comando (ENTER para confirmar, 't' para tutorial): ");
        mvprintw(LINES - 2, 0, "%s", linha); move(LINES - 2, pos);
        refresh();
        int ch = getch();

        if (ch == KEY_UP && *scrollLinha > 0) {
            (*scrollLinha)--;
        } else if (ch == KEY_DOWN && *scrollLinha + 15 < m->L) {
            (*scrollLinha)++;
        } else if (ch == KEY_LEFT && *scrollColuna > 0) {
            (*scrollColuna)--;
        } else if (ch == KEY_RIGHT && *scrollColuna + 15 < m->C) {
            (*scrollColuna)++;
        } else if ((ch == KEY_BACKSPACE || ch == 127 || ch == '\b') && pos > 0) {
            pos--;
            linha[pos] = '\0';
        } else if (ch == '\n') {
            linha[pos] = '\0'; 
            if (strcmp(linha, "t") == 0) {
                mostraTutorial();
                r1=0; 
            }
            else {
                int r = escolheComandos(m, s, q, linha, &grupos);
                int resultado = executaComando(linha, r, grupos);
                if (resultado != 0) r1 = resultado; 
                else {
                    pos = 0; linha[0] = '\0';
                }
            }

        } 
        else if (isprint(ch) && pos < 99) linha[pos++] = ch, linha[pos] = '\0';
    }
    return r1;
}