#include "../include/resolve.h"

void aplicarPadraoABA(Matriz* m){
    for (int i=0; i < m->L; i++){
        for (int j=0; j < m->C-2; j++){

            if(m->matriz[i][j]==m->matriz[i][j+2] &&
                m->matriz[i][j] != '#' && m->matriz[i][j+2] != '#' &&
                m->matriz[i][j+1] != '#' &&
                m->matriz[i][j] != m->matriz[i][j+1]){
                    
                    char temp = m->matriz[i][j];
                    m->matriz[i][j] = '#'; 
                    
                    NodeGrupo* grupos = NULL; 
                    if(!verificar(m, &grupos)) {
                        m->matriz[i][j] = temp; 
                        m->matriz[i][j+2] = '#'; 
                    }
                    liberaGrupos(grupos); 
            }     
        }
    }

    for (int j=0; j<m->C; j++){
        for(int i=0; i<m->L-2; i++){
            if(m->matriz[i][j]==m->matriz[i+2][j] &&
                m->matriz[i][j] != '#' && m->matriz[i+2][j] != '#' &&
                m->matriz[i+1][j] != '#' &&
                m->matriz[i][j] != m->matriz[i+1][j]) {

                    char temp = m->matriz[i][j];
                    m->matriz[i][j] = '#';

                    NodeGrupo* grupos = NULL; 
                    if(!verificar(m, &grupos)) {
                        m->matriz[i][j] = temp; 
                        m->matriz[i+2][j] = '#'; 
                    }
                    liberaGrupos(grupos); 
                }
        }
    }
} 

void aplicarPadraoAAA (Matriz* m){
    for (int i = 0; i < m->L; i++) {
        for (int j = 0; j < m->C-1; j++){
            if (m->matriz[i][j] == m->matriz[i][j+1] && 
                m->matriz[i][j] != '#' && m->matriz[i][j+1] != '#'){

                    char temp1 = (m->matriz[i][j]); 
                    int k = j+2;

                    while(k < m->C){
                        if ((m->matriz[i][k]) == temp1 && m->matriz[i][k] != '#') {

                        // Primeiro: SEMPRE riscar o último A
                        char temp2 = m->matriz[i][k];
                        m->matriz[i][k] = '#';

                        NodeGrupo* grupos = NULL;

                        char temp3 = m->matriz[i][j];
                        m->matriz[i][j] = '#';

                        if (!verificar(m, &grupos)) {
                            // Se riscar o primeiro A não for válido, tenta o segundo
                            m->matriz[i][j] = temp3;
                            m->matriz[i][j+1] = '#';

                            if (!verificar(m, &grupos)) {
                                // Se nem riscar o segundo funcionar, desfaz tudo
                                m->matriz[i][j+1] = temp3;
                                m->matriz[i][k] = temp2;
                            }
                        }

                        liberaGrupos(grupos);

                        break; // depois de tratar, para
                    }
                    k++;
                }
            }
        }
    }

    for (int j = 0; j < m->C; j++) {
        for (int i = 0; i < m->L-1; i++) {
            if (m->matriz[i][j] == m->matriz[i+1][j] &&
                m->matriz[i][j] != '#' && m->matriz[i+1][j] != '#') {

                char temp1 = m->matriz[i][j];
                int k = i+2;

                while (k < m->L) {
                    if (m->matriz[k][j] == temp1 && m->matriz[k][j] != '#') {

                        char temp2 = m->matriz[k][j];
                        m->matriz[k][j] = '#';

                        NodeGrupo* grupos = NULL;

                        char temp3 = m->matriz[i][j];
                        m->matriz[i][j] = '#';

                        if (!verificar(m, &grupos)) {
                            m->matriz[i][j] = temp3;
                            m->matriz[i+1][j] = '#';

                            if (!verificar(m, &grupos)) {
                                m->matriz[i+1][j] = temp3;
                                m->matriz[k][j] = temp2;
                            }
                        }

                        liberaGrupos(grupos);

                        break;
                    }
                    k++;
                }
            }
        }
    }
}


void resolveTabuleiro(Matriz* m, Queue* q) {
    int mudou;

    do {
        mudou = 0;

        aplicarPadraoABA(m);   // Resolver padrões ABA
        aplicarPadraoAAA(m);   // Resolver padrões AA.A

        int resultadoAjuda = ajuda(m, q); // Aplicar ajuda
        if (resultadoAjuda == 1) {
            mudou = 1;
        } else if (resultadoAjuda == -1) {
            printf("Tabuleiro inválido após ajuda.\n");
            return;
        }

        if (resolverDuplicadosControlado(m, q)) { // Resolver duplicados de forma controlada
            mudou = 1;
        }

    } while (mudou); // Continua enquanto conseguir mudar
}


int resolverDuplicadosControlado(Matriz* m, Queue* q) {
    for (int i = 0; i < m->L; i++) {
        for (int j = 0; j < m->C; j++) {
            if (islower(m->matriz[i][j])) {

                for (int k = j + 1; k < m->C; k++) {
                    if (m->matriz[i][k] == m->matriz[i][j]) {
                        // Encontrou duplicados na mesma linha
                        if (resolverTentativa(m, q, i, j, i, k)) {
                            return 1;
                        }
                    }
                }
            }
        }
    }

    for (int j = 0; j < m->C; j++) {
        for (int i = 0; i < m->L; i++) {
            if (islower(m->matriz[i][j])) {

                for (int k = i + 1; k < m->L; k++) {
                    if (m->matriz[k][j] == m->matriz[i][j]) {
                        // Encontrou duplicados na mesma coluna
                        if (resolverTentativa(m, q, i, j, k, j)) {
                            return 1;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

#include "../include/resolve.h"

int resolverTentativa(Matriz* m, Queue* q, int i1, int j1, int i2, int j2) {
    Matriz copia;
    initMatriz(&copia);
    copiaMatriz(&copia, m); // salvar estado inicial

    // Tentativa 1: pintar primeiro
    m->matriz[i1][j1] = toupper(m->matriz[i1][j1]);
    if (verificar(m, NULL)) {
        if (ajuda(m, q) == 1) {
            liberaMatriz(&copia);
            return 1;
        }
    }
    copiaMatriz(m, &copia); // desfaz

    // Tentativa 2: pintar o segundo
    m->matriz[i2][j2] = toupper(m->matriz[i2][j2]);
    if (verificar(m, NULL)) {
        if (ajuda(m, q) == 1) {
            liberaMatriz(&copia);
            return 1;
        }
    }
    copiaMatriz(m, &copia);

    // Tentativa 3: riscar o primeiro
    m->matriz[i1][j1] = '#';
    if (verificar(m, NULL)) {
        if (ajuda(m, q) == 1) {
            liberaMatriz(&copia);
            return 1;
        }
    }
    copiaMatriz(m, &copia);

    // Tentativa 4: riscar o segundo
    m->matriz[i2][j2] = '#';
    if (verificar(m, NULL)) {
        if (ajuda(m, q) == 1) {
            liberaMatriz(&copia);
            return 1;
        }
    }
    copiaMatriz(m, &copia);

    liberaMatriz(&copia);
    return 0; // Nenhuma tentativa deu certo
}
