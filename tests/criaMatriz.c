#include "include/criaMatriz.h"

Matriz criaMatriz (int linhas, int colunas, char elemMatriz[linhas][colunas]) {
    Matriz m; 
    m.L = linhas;  
    m.C = colunas;  

    m.matriz = malloc(linhas * sizeof(char*));
    for (int i=0; i< linhas; i++) {
       m.matriz[i]= malloc(colunas * sizeof(char)); 
       for (int j=0; j< colunas; j++){
           m.matriz[i][j]=elemMatriz[i][j]; 
       }
    }

    return m; 
}
