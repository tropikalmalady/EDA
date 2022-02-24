typedef struct {
	char nome_art[30];
	char nacionalidade[20];
} Artista;

typedef struct {
	int dia, mes, ano;
} Data;

typedef struct {
	char nome[30];
	int duracao;
	char estilo[20];
	Artista artista;
	Data data;
} Musica;

void mostra_musica(Musica m);
void mostra_mus(void *x);
int compara_musicas_nome(void *a, void *b);
int compara_musicas_nome_art(void *a, void *b);
int compara_musicas_nome_est(void *a, void *b);
//int carrega_arquivo( char *nome_arq, Musica *m, void *l, int *ln );
