#define MAX 10

typedef struct pos {
    int l; 
    int c; 
} Pos; 

typedef struct matriz {
    
    int L; 
    int C; 
    char matriz [MAX][MAX]; 

} Matriz;

int mostraMatriz (Matriz *);
int branco (Matriz *, Pos);
int riscar (Matriz *, Pos);
int escolheComandos (Matriz *);