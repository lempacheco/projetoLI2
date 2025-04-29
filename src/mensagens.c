#include "../include/mensagens.h"

void mensagens(char s[]){

    mvprintw(LINES - 1, 0, "%s", s);
    refresh();
    napms(1000);

}