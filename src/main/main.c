
#include "../../include/comandos.h"
#include "../../include/condicoes.h"
#include "../../include/matrizRandom.h"
#include "../../include/output.h"
#include "../../include/leFicheiro.h"
#include "../../include/dataStructs.h"
#include "../../include/stackMats.h"
#include "../../include/interface.h"
#include <ncurses.h>

int main() {
    // Inicializa o ncurses e configurações de cor
    initscr();
    start_color();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    Matriz m;
    initMatriz(&m);
    StackMat s; 
    initStackMat(&s);
    Queue q; 
    initQueue(&q); 

    int resultado = 0;

    // offsets de scroll mantidos entre execuções
    int scrollLinha = 0;
    int scrollColuna = 0;


    while (resultado != 1) {
        // Passa os offsets por referência e atualiza dentro da função
        resultado = escolheComandosNcurses(&m, &s, &q, &scrollLinha, &scrollColuna);

        if (resultado == -1) {
            pop(&s, &m);
        }

        if (resultado != 1) {
            mostraMatriz(&m, scrollLinha, scrollColuna);
        }
    }

    liberaMatriz(&m);
    liberaStackMat(&s);
    liberaQueue(&q);

    endwin();
    return 0;
}
