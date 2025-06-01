#include "../include/mensagens.h"

void mensagens(char s[]){

    mvprintw(LINES - 1, 0, "%s", s);
    refresh();
    napms(1000);

}

void limpaMensagens (){
    move(LINES-1, 0);
    clrtoeol();
    refresh();
}