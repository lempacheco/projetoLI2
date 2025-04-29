#include "../include/interface.h"

void imprimeCaudaNcurses(NodePosicao* lista, int* linha) {
    if (lista == NULL || lista->prox == NULL) {
        mvprintw((*linha)++, 0, "  (nenhuma posição)");
        return;
    }

    NodePosicao* atual = lista->prox;
    while (atual != NULL) {
        mvprintw((*linha)++, 0, "    (%c, %d)", atual->p.l + 'a', atual->p.c);
        atual = atual->prox;
    }
}

void imprimeCabecaNcurses(NodePosicao* lista, int* linha) {
    if (lista != NULL) {
        mvprintw((*linha)++, 0, "    (%c, %d)", lista->p.l + 'a', lista->p.c);
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
            mvprintw((*linha)++, 1, "(%c,%d)",
                atualGrupo->cabeca->p.l + 'a', atualGrupo->cabeca->p.c);

            // imprime a cauda com indentação 2x
            NodePosicao* atual = atualGrupo->cabeca->prox;
            while (atual != NULL) {
                mvprintw((*linha)++, 4, "(%c,%d)", atual->p.l + 'a', atual->p.c);
                atual = atual->prox;
            }

        } else {
            mvprintw((*linha)++, 0, "Tipo de restrição desconhecido.");
        }

        (*linha)++; // linha em branco entre grupos
        atualGrupo = atualGrupo->prox;
    }
}


int escolheComandosNcurses(Matriz *m, StackMat *s, Queue *q, int *scrollLinha, int *scrollColuna) {
    char linha[100];

    init_pair(1, COLOR_RED, COLOR_BLACK);

    mostraMatriz(m, *scrollLinha, *scrollColuna);
    refresh();

    int ch = getch();

    if (ch == KEY_UP && *scrollLinha > 0) (*scrollLinha)--;
    else if (ch == KEY_DOWN && *scrollLinha + ALTURA_VISIVEL < m->L) (*scrollLinha)++;
    else if (ch == KEY_LEFT && *scrollColuna > 0) (*scrollColuna)--;
    else if (ch == KEY_RIGHT && *scrollColuna + LARGURA_VISIVEL < m->C) (*scrollColuna)++;
    else if (ch == '\n') {
        move(0, 0);
        clrtoeol();
        mvprintw(0, 0, "Digite o comando: ");
        echo();
        getnstr(linha, 99);
        noecho();


        if (linha[0] == 'v') {
            // Executar o comando especial 'v' (verificação longa)
            NodeGrupo* grupos = NULL;
            verificar(m, &grupos);
            int caminho = verificaCaminho(m, q);

            clear();
            int l = 0;
            if (caminho == 1)
                mvprintw(l++, 0, "Existe um caminho ortogonal entre quaisquer duas casas brancas.");
            else
                mvprintw(l++, 0, "Não existe um caminho ortogonal entre quaisquer duas casas brancas.");

            l++;
            imprimeGruposNcurses(grupos, &l);
            liberaGrupos(grupos);

            mvprintw(LINES - 2, 0, "Pressione ENTER para continuar...");
            refresh();
            while (getch() != '\n');
            return RET_OK;
        }

        if (linha[0] == 't') {
            
            clear();
            attron(COLOR_PAIR(1));
            mvprintw(1, 0, "TUTORIAL");

            mvprintw(3, 0, "Comandos:");
            attroff(COLOR_PAIR(1));

            mvprintw(4, 2, "g (ficheiro) -> gravar o estado atual do jogo num ficheiro");
            mvprintw(5, 2, "l (ficheiro) -> ler o estado do jogo de um ficheiro ");
            mvprintw(6, 2, "b <letra minúscula><número> -> coloca a coordenada em maiúscula");
            mvprintw(7, 2, "r <letra minúscula><número> -> coloca a coordenada riscada");
            mvprintw(8, 2, "v -> verificar o estado do jogo e apontar todas as restrições violadas");
            mvprintw(9, 2, "a -> ajuda o jogador, funcionando como um autocompletador");
            mvprintw(10, 2, "A -> realiza automaticamente o comando 'a'");
            mvprintw(11, 2, "R -> resolver o jogo");
            mvprintw(12, 2, "s -> Sai do jogo");
            mvprintw(13, 2, "d -> desfaz o último comando executado ");

            attron(COLOR_PAIR(1));
            mvprintw(14, 0, "Regras do jogo");
            attroff(COLOR_PAIR(1));
            mvprintw(15, 2, "Cada casa contém um símbolo (uma letra inicialmente minúscula);");
            mvprintw(16, 2, "Em cada linha e coluna só pode existir uma única réplica de cada símbolo que é pintada a branco (coloca-se a letra em maiúsculas);");
            mvprintw(17, 2, "Todas as outras réplicas desse símbolo têm que ser riscadas (substituídas por um cardinal);");
            mvprintw(18, 2, "Se uma casa está riscada, todas as casas vizinhas ortogonais têm que estar pintadas a branco;");
            mvprintw(19, 2, "É necessário existir um caminho ortogonal entre todas as casas brancas do tabuleiro.");


            mvprintw(LINES - 2, 0, "Pressione ENTER para continuar...");
            refresh();
            while (getch() != '\n');
            return RET_OK;
        }

        // Simula stdin para escolheComandos
        int len = strlen(linha);
        ungetc('\n', stdin);
        for (int i = len - 1; i >= 0; i--) {
            ungetc(linha[i], stdin);
        }

        int r = escolheComandos(m, s, q);

        move(1, 0);
        clrtoeol();

        if (r == RET_SAIR) {
            mvprintw(1, 0, "Saindo do jogo...");
            refresh();
            napms(1000);
            return 1;

        } else if (r == RET_DESFAZ) {
            mvprintw(1, 0, "Retrocedendo...");
            refresh();
            napms(500);
            return 0;
            
        } else if (r == RET_COMANDO_DESCONHECIDO){
            mvprintw(1, 0, "Comando desconhecido.");
            refresh();
            napms(500);
            return 0;
        }

        refresh();
    }

    return 0;
}