#include "../include/mensagens.h"

void mensagens(char s[]){

    mvprintw(1, 0, "%s", s);
    refresh();
    napms(1000);

}