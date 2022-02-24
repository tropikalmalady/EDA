
#define ERRO_COORD_INVALIDA -1

typedef struct{
	int **dados;
	int lin, col;
}Matriz;

void inicializa_matriz( Matriz *p, int l, int c );
void mostra_matriz( Matriz m );
int set_matriz( Matriz *p, int i, int j, int valor );
int get_matriz( Matriz m, int i, int j, int *p_valor );
int compara_matrizes( Matriz m1, Matriz m2 );
int carrega_matriz_arquivo( char *nome_arq, Matriz *p , int dim);
