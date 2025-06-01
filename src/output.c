#include "../include/output.h"
#include "../include/dataStructs.h" 
#include <ncurses.h>	
#include <ctype.h>

/* Percorre a matriz fornecida e imprime os seus elementos no terminal. 
*/


void mostraMatriz(Matriz *m, int scrollLinha, int scrollColuna) {
    int linhaOffset = 2, colunaOffset = 4;
    char letraColuna = 'a' + scrollColuna;

    init_pair(1, COLOR_RED, COLOR_BLACK);    // '#' riscado
    init_pair(2, COLOR_GREEN, COLOR_BLACK);  // minúsculo
    init_pair(3, COLOR_WHITE, COLOR_BLACK);  // maiúsculo
    init_pair(4, COLOR_BLACK, COLOR_WHITE);  // borda

    clear();

    //título 
    attron(COLOR_PAIR(4));
    // cabeçalho
    attron(COLOR_PAIR(4));

    mvprintw(linhaOffset, colunaOffset, "   ");
    for (int col = 0; col < 15 && (scrollColuna + col) < m->C; col++) {
        int x = colunaOffset + 3 + col * 2;
        
        // imprime um espaço
        mvprintw(linhaOffset, x, " ");
        
        // imprime a letra por cima 
        mvprintw(linhaOffset, x + 1, "%c", letraColuna + col);
    }
    

    attroff(COLOR_PAIR(4));

    // Corpo da matriz
    for (int i = 0; i < 15 && (scrollLinha + i) < m->L; i++) {
        attron(COLOR_PAIR(4));
        mvprintw(linhaOffset + 1 + i, colunaOffset, "%2d ", scrollLinha + i + 1);
        attroff(COLOR_PAIR(4));

        for (int j = 0; j < 15 && (scrollColuna + j) < m->C; j++) {
            char valor = m->matriz[scrollLinha + i][scrollColuna + j];

            if (valor == '#') attron(COLOR_PAIR(1));
            else if (isupper(valor)) attron(COLOR_PAIR(3));
            else attron(COLOR_PAIR(2));

            mvprintw(linhaOffset + 1 + i, colunaOffset + 4 + j * 2, "%c", valor);

            attroff(COLOR_PAIR(1));
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
        }
    }

    refresh();
}