#include "../include/interface.h"

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

void imprimeCabecaNcurses(NodePosicao* lista, int* linha) {
    if (lista != NULL) {
        mvprintw((*linha)++, 3, "(%c, %d)", lista->p.l + 'a', lista->p.c);
    }
}

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

            // imprime a cabeça com indentação 1x
            mvprintw((*linha)++, 3, "(%c,%d)",
                atualGrupo->cabeca->p.l + 'a', atualGrupo->cabeca->p.c);

            // imprime a cauda com indentação 2x
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


int mostraTutorial() {
    clear();
    attron(COLOR_PAIR(1));
    mvprintw(1, 0, "TUTORIAL");
    mvprintw(3, 0, "Comandos:");
    attroff(COLOR_PAIR(1));

    const char *linhas[] = {
        "g (ficheiro) -> gravar o estado atual do jogo num ficheiro",
        "l (ficheiro) -> ler o estado do jogo de um ficheiro",
        "b <letra><número> -> coloca a coordenada em maiúscula",
        "r <letra><número> -> coloca a coordenada riscada",
        "v -> verificar restrições",
        "a -> ajuda o jogador",
        "A -> autoajuda",
        "R -> resolver jogo",
        "s -> sair",
        "d -> desfazer comando"
    };

    for (int i = 0; i < 10; i++) mvprintw(4 + i, 2, "%s", linhas[i]);

    attron(COLOR_PAIR(1));
    mvprintw(14, 0, "Regras do jogo");
    attroff(COLOR_PAIR(1));
    mvprintw(15, 2, "Cada casa contém um símbolo minúsculo;");
    mvprintw(16, 2, "Apenas uma réplica por linha/coluna pode estar em branco;");
    mvprintw(17, 2, "Réplica riscada = cardinal;");
    mvprintw(18, 2, "Casa riscada exige vizinhos ortogonais brancos;");
    mvprintw(19, 2, "Caminho ortogonal entre todas as casas brancas necessário;");

    mvprintw(LINES - 2, 0, "ENTER para continuar...");
    refresh();
    while (getch() != '\n');
    return RET_OK;
}

int executaComando(char *linha, int r, NodeGrupo *grupos) {
    if (strcmp(linha, "D") == 0) {
        mvprintw(LINES - 1, 0, "Existem %d casas erradas.", r);
        refresh(); napms(1000);
        return RET_OK;
    }
   
    if (strcmp(linha, "v") == 0) {
        clear(); int l = 0;
        mvprintw(l++, 0, r == 7 ? "Existe caminho ortogonal entre todas as casas brancas." : "Não existe caminho ortogonal entre todas as casas brancas.");
        l++;
        imprimeGruposNcurses(grupos, &l);
        liberaGrupos(grupos);
        mvprintw(LINES - 2, 0, "ENTER para continuar...");
        refresh(); while (getch() != '\n');
        return RET_OK;
    }
   
    if (r == RET_SAIR) {
        clear(); mvprintw(LINES - 1, 0, "Saindo do jogo...");
        refresh(); napms(1000);
        return 1;
    }
   
    if (r == RET_DESFAZ) {
        mvprintw(LINES - 1, 0, "Desfazendo..."); refresh(); napms(500);
    } else if (r == RET_COMANDO_DESCONHECIDO) {
        mvprintw(LINES - 1, 0, "Comando desconhecido."); refresh(); napms(500);
    }
   
    return (r == RET_POP) ? RET_POP : RET_OK;
}


int escolheComandosNcurses(Matriz *m, StackMat *s, Queue *q, int *scrollLinha, int *scrollColuna) {
    char linha[100] = ""; int pos = 0;
    NodeGrupo *grupos = NULL;

    noecho();
    keypad(stdscr, TRUE);

    while (1) {
        clear();
        mostraMatriz(m, *scrollLinha, *scrollColuna);
        mvprintw(LINES - 3, 0, "Digite o comando (ENTER para confirmar, 't' para tutorial): ");
        mvprintw(LINES - 2, 0, "%s", linha); move(LINES - 2, pos);
        refresh();
        int ch = getch();

        if (ch == KEY_UP && *scrollLinha > 0) {
            (*scrollLinha)--;
        } else if (ch == KEY_DOWN && *scrollLinha + ALTURA_VISIVEL < m->L) {
            (*scrollLinha)++;
        } else if (ch == KEY_LEFT && *scrollColuna > 0) {
            (*scrollColuna)--;
        } else if (ch == KEY_RIGHT && *scrollColuna + LARGURA_VISIVEL < m->C) {
            (*scrollColuna)++;
        } else if ((ch == KEY_BACKSPACE || ch == 127 || ch == '\b') && pos > 0) {
            pos--;
            linha[pos] = '\0';
        } else if (ch == '\n') {
            linha[pos] = '\0'; 
            if (strcmp(linha, "t") == 0) return mostraTutorial();

            int r = escolheComandos(m, s, q, linha, &grupos);
            int resultado = executaComando(linha, r, grupos);
            if (resultado != RET_OK) return resultado;

            pos = 0; linha[0] = '\0';

        } 
        else if (pos < 99) linha[pos++] = ch, linha[pos] = '\0';
    }
    return 0;
}