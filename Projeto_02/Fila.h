// Algumas constantes �teis
#define ERRO_FILA_VAZIA -1
#define ERRO_FILA_CHEIA -2

typedef struct{
   int *dados; // dados da fila 
   int inicio;     // �ndice do in�cio da fila
   int n;          // qtd. de elementos da fila
   int capacidade;
} Fila;

void inicializa_fila ( Fila *f, int c );
int fila_vazia ( Fila f );
int fila_cheia ( Fila f );
int inserir ( Fila *f, int info );
int remover ( Fila *f, int *info );
void mostra_fila ( Fila f );
void desaloca_fila( Fila *f );

