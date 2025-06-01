#include "../include/mensagens.h"

/*
    Exibe uma mensagem temporária no rodapé da tela (`ncurses`).
*/
void mensagens(char s[]){

    mvprintw(LINES - 1, 0, "%s", s);
    refresh();
    napms(1000);

}

/* 
    Limpa qualquer mensagem exibida anteriormente no rodapé da tela (`ncurses`).
*/

void limpaMensagens (){
    move(LINES-1, 0);
    clrtoeol();
    refresh();
}