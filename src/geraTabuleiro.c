/* #include "../include/geraTabuleiro.h"

void geraTabuleiro(Matriz* m){
    int i, j, k, t;
    char c;
    char ant;
    int count;

    NodeGrupo* grupos = NULL;

    srand(time(0));

    //liberta matriz anterior
    liberaMatriz(m);
    initMatriz(m);

    //gera o número de linhas e colunas
    //m->L = rand() % (26 - 1 + 1) + 1;
    //m->C = rand() % (26 - 1 + 1) + 1;
    m->L = m->C = 5;

    //número de símbolos da solução do tabuleiro, exceto o #
    int nSimbolos = max(m->L, m->C);

    //array de simbolos possiveis da solução do tabuleiro
    char simbolos[nSimbolos];

    for (i=0; i<nSimbolos; i++){
        simbolos[i] = 'A' + i;
    }

    //preenche matriz:
    //põe valores que a verificar não vai ligar
    m->matriz = malloc(sizeof(char*)*m->L);
    for(i=0; i<m->L; i++){
        m->matriz[i] = malloc(sizeof(char)*m->C);
        for (j=0; j<m->C; j++){ 
            m->matriz[i][j] = 'a';
        }
    }

    //preencher completamente de forma a que o tabuleiro continue válido
    //pega num indice random
    t = rand() % ((nSimbolos-1) - 0 + 1) + 0;

    for(i=0; i<m->L; i++){
        j=0;
        for (k=t; j!=nSimbolos; k++){
            m->matriz[i][j] = simbolos[k]; 

            if (k==(nSimbolos-1)){
                k=-1;
            }

            j++;
        }
        if (t==(nSimbolos-1)){
            t=0;
        }else{
            t+=1;
        }
    }
} */

#include "../include/geraTabuleiro.h"

void geraTabuleiro(Matriz* m){
    int solution_count = 0;
    char*** solutions = NULL;
    while(solution_count != 1){
        geraTabuleiroAleatorio(m);
        procuraSolucoes(m, solutions, &solution_count);
        for(int i=0; i<solution_count; i++){
            for (int j=0; j<m->L; j++){
                free(solutions[i][j]);
            }
            free(solutions[i]);
        }
        free(solutions);
        solutions = NULL;
    }
}

void geraTabuleiroAleatorio(Matriz* m){
    int i, j, k;
    char c;
    NodeGrupo* grupos = NULL;

    srand(time(0));

    //liberta matriz anterior
    liberaMatriz(m);
    initMatriz(m);

    //gera o número de linhas e colunas
    //m->L = rand() % (26 - 1 + 1) + 1;
    //m->C = rand() % (26 - 1 + 1) + 1;
    m->L = m->C = 5;

    //número de símbolos da solução do tabuleiro
    int nSimbolos = max(m->L, m->C) + 1;

    //array de simbolos possiveis da solução do tabuleiro
    char simbolos[nSimbolos];

    simbolos[0] = '#';
    for (i=1; i<nSimbolos; i++){
        simbolos[i] = 'A' + (i-1);
    }

    //preenche matriz:
    //põe valores que a verificar não vai ligar
    m->matriz = malloc(sizeof(char*)*m->L);
    for(i=0; i<m->L; i++){
        m->matriz[i] = malloc(sizeof(char)*m->C);
        for (j=0; j<m->C; j++){ 
            m->matriz[i][j] = 'a';
        }
    }

    //preenche com valores a sério
    for(i=0; i<m->L; i++){
        for (j=0; j<m->C; j++){ 
            //pega num carater random
            c = simbolos[rand() % ((nSimbolos-1) - 0 + 1) + 0];

            //se esse carater for igual ao q ja esta na matriz, pega noutro
            while (c == m->matriz[i][j]){
                c = simbolos[rand() % ((nSimbolos-1) - 0 + 1) + 0];
            }

            //poe esse carater na matriz
            m->matriz[i][j] = c;

            //se o tabuleiro n for valido, tenta com todos os carateres possiveis ate ser valido
            for (k=0; !verificar(m, &grupos) && k < nSimbolos; k++){
                liberaGrupos(grupos); grupos = NULL;
                m->matriz[i][j] = simbolos[k];
            }

            //se nenhum carater conseguir por o tabuleiro valido, entao o problema esta mais para tras, por isso volta atras
            if (!verificar(m, &grupos)){
                liberaGrupos(grupos); grupos = NULL;
                if (j==0){
                    i--;
                    j=m->C-2;
                }else{
                    j-=2;
                }
            }
        }
    }

    //debug
    FILE* fp = fopen("debug.txt", "w");
    for (i=0; i<m->L; i++){
        for(j=0; j<m->C; j++){
            fprintf(fp, "%c ", m->matriz[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    //pôr tudo a minúsculas que está branco, e o que está riscado põe uma minúscula qualquer que seja repetida na linha
    for (i=0; i<m->L; i++){
        for (j=0; j<m->C; j++){
            if (m->matriz[i][j] == '#'){
                k = rand() % ((m->L-1) - 0 + 1) + 0;
                while(m->matriz[k][j]=='#'){
                    k = rand() % ((m->L-1) - 0 + 1) + 0;
                }
                m->matriz[i][j] = tolower(m->matriz[k][j]);
            }else{
                m->matriz[i][j] = tolower(m->matriz[i][j]);
            }
        }
    }

    //debug
    fp = fopen("debug.txt", "a");
    for (i=0; i<m->L; i++){
        for(j=0; j<m->C; j++){
            fprintf(fp, "%c ", m->matriz[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    liberaGrupos(grupos);
}

/* void geraTabuleiro(Matriz* m){
    int i, j, k;
    char c;
    char ant;

    NodeGrupo* grupos = NULL;

    srand(time(0));

    //liberta matriz anterior
    liberaMatriz(m);
    initMatriz(m);

    //gera o número de linhas e colunas
    //m->L = rand() % (26 - 1 + 1) + 1;
    //m->C = rand() % (26 - 1 + 1) + 1;
    m->L = m->C = 5;

    //número de símbolos da solução do tabuleiro, exceto o #
    int nSimbolos = max(m->L, m->C);

    //array de simbolos possiveis da solução do tabuleiro
    char simbolos[nSimbolos];

    for (i=0; i<nSimbolos; i++){
        simbolos[i] = 'A' + i;
    }

    //preenche matriz:
    //põe valores que a verificar não vai ligar
    m->matriz = malloc(sizeof(char*)*m->L);
    for(i=0; i<m->L; i++){
        m->matriz[i] = malloc(sizeof(char)*m->C);
        for (j=0; j<m->C; j++){ 
            m->matriz[i][j] = 'a';
        }
    }

    //preencher completamente de forma a que o tabuleiro continue válido
    for(i=0; i<m->L; i++){
        for (j=0; j<m->C; j++){
            //pega num carater random
            c = simbolos[rand() % ((nSimbolos-1) - 0 + 1) + 0];

            //se esse carater for igual ao q ja esta na matriz, pega noutro
            ant = m->matriz[i][j];
            while (c == ant){
                c = simbolos[rand() % ((nSimbolos-1) - 0 + 1) + 0];
            }

            //poe esse carater na matriz
            m->matriz[i][j] = c;

            //se o tabuleiro n for valido, tenta com todos os carateres possiveis ate ser valido
            for (k=0; !verificar(m, &grupos) && k < nSimbolos; k++){
                liberaGrupos(grupos); grupos = NULL;
                if (ant != simbolos[k]) m->matriz[i][j] = simbolos[k];
            }

            //se nenhum carater conseguir por o tabuleiro valido, entao o problema esta mais para tras, por isso volta atras
            if (!verificar(m, &grupos)){
                liberaGrupos(grupos); grupos = NULL;
                if (j==0){
                    i--;
                    j=m->C-2;
                }else{
                    j-=2;
                }
            }
        }
    }
} */

int max(int a, int b){
    if (a>b) return a;
    else return b;
}

// Check if all white cells are connected
int all_white_connected(int** is_white, int N, int M) {
    int visited[N][M];
    visited[0][0] = 0;
    int queue[N * M][2];
    int front = 0, back = 0;

    // Find the first white cell
    int found = 0;
    for (int i = 0; i < N && !found; i++) {
        for (int j = 0; j < M && !found; j++) {
            if (is_white[i][j]) {
                queue[back][0] = i;
                queue[back][1] = j;
                back++;
                visited[i][j] = 1;
                found = 1;
            }
        }
    }

    if (!found) return 1;  // no white cell is trivially connected

    // BFS
    while (front < back) {
        int x = queue[front][0];
        int y = queue[front][1];
        front++;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int ni = x + dx[d], nj = y + dy[d];
            if (ni >= 0 && ni < N && nj >= 0 && nj < M && is_white[ni][nj] && !visited[ni][nj]) {
                visited[ni][nj] = 1;
                queue[back][0] = ni;
                queue[back][1] = nj;
                back++;
            }
        }
    }

    // Check if all white cells were visited
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (is_white[i][j] && !visited[i][j])
                return 0;

    return 1;
}

// Validate board configuration
int valid_config(int** is_white, int N, int M) {
    // Check if adjacent blacks exist
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!is_white[i][j]) {
                int dx[] = {-1, 1, 0, 0};
                int dy[] = {0, 0, -1, 1};
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < N && nj >= 0 && nj < M && !is_white[ni][nj])
                        return 0;
                }
            }
        }
    }

    return all_white_connected(is_white, N, M);
}

// Save solution
void save_solution(int* solution_count, char*** solutions, Matriz* m, int** is_white) {
    if (*solution_count >= 1000) return;

    for (int i = 0; i < m->L; i++)
        for (int j = 0; j < m->C; j++)
            solutions[*solution_count][i][j] = is_white[i][j] ? m->matriz[i][j] - 32 : '#';  // Uppercase or '#'

    (*solution_count)++;
    solutions = realloc(solutions, sizeof(char**)*(*solution_count+1));
    solutions[(*solution_count)] = realloc(solutions[(*solution_count)], sizeof(char*)*(m->L));
    for (int i=0; i<m->L; i++){
        solutions[(*solution_count)][i] = realloc(solutions[(*solution_count)][i], sizeof(char*)*(m->C));
    }
}

// Check if symbol has been used in the same row/column
int can_be_white(int row, int col, Matriz* m, int** is_white) {
    char symbol = m->matriz[row][col];
    for (int i = 0; i < m->L; i++)
        if (is_white[i][col] && m->matriz[i][col] == symbol)
            return 0;

    for (int j = 0; j < m->C; j++)
        if (is_white[row][j] && m->matriz[row][j] == symbol)
            return 0;

    return 1;
}

// Recursive backtracking
void backtrack(int pos, int** is_white, int* solution_count, char*** solutions, Matriz* m) {
    if (pos == m->L * m->C) {
        if (valid_config(is_white, m->L, m->C)) {
            save_solution(solution_count, solutions, m, is_white);
        }
        return;
    }

    int row = pos / m->C;
    int col = pos % m->C;

    // Try making it white
    if (can_be_white(row, col, m, is_white)) {
        is_white[row][col] = 1;
        backtrack(pos + 1, is_white, solution_count, solutions, m);
        is_white[row][col] = 0;
    }

    // Try black (skip)
    backtrack(pos + 1, is_white, solution_count, solutions, m);
}

void procuraSolucoes(Matriz* m, char*** solutions, int* solution_count) {
    solutions = malloc(sizeof(char**));
    solutions[0] = malloc(sizeof(char*)*m->L);
    for(int i=0; i<m->C; i++){
        solutions[0][i] = malloc(sizeof(char)*m->C);
    }
    *solution_count = 0;
    int** is_white;
    is_white = malloc(sizeof(int*)*m->L);
    for (int i=0; i<m->C; i++){
        is_white[i] = malloc(sizeof(int)*m->C);
    }
    is_white[0][0] = 0;
    
    backtrack(0, is_white, solution_count, solutions, m);
    /* printf("Número de soluções: %d\n", solution_count);
    for (int k = 0; k < solution_count; k++) {
        printf("\nSolução %d:\n", k + 1);
        for (int i = 0; i < m->L; i++) {
            for (int j = 0; j < m->C; j++) {
                printf("%c ", solutions[k][i][j]);
            }
            printf("\n");
        }
    } */
}