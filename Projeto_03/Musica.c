#include "Musica.h"
#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostra_musica(Musica m) {
	printf("Titulo: %s, Duracao: %d, Estilo: %s, Artista: %s, Nacionalidade: %s, Data: %d/%d/%d\n", m.nome, m.duracao, m.estilo, m.artista.nome_art, m.artista.nacionalidade, m.data.dia, m.data.mes, m.data.ano);
}
/*
int carrega_arquivo( char *nome_arq, Musica *m, Lista *lV, int *ln ){
	FILE *f = fopen( nome_arq, "rt");
	if( f == NULL ){
		return 0; // Erro!
	}
	int n=8;
	Lista l;
	char c, letra = '\n';
	//fscanf(f, "%d", &n);
	inicializa_lista(&l, sizeof(Musica));
	l.qtd=n;
	Musica *v[n];
	int i;
	for( i = 0 ; i < n ; i++ ){
		fscanf(f, " %[^\n]", v[i]->nome);
		fscanf(f, "%d", &v[i]->duracao);
		fscanf(f, " %[^\n]", v[i]->estilo);
		fscanf(f, " %[^\n]", v[i]->artista.nome_art);
		fscanf(f, " %[^\n]", v[i]->artista.nacionalidade);
		fscanf(f, "%d", &v[i]->data.dia);
		fscanf(f, "%d", &v[i]->data.mes);
		fscanf(f, "%d", &v[i]->data.ano);
		insere_ordem(&l, &v[i], compara_musicas_nome);
	}
	fclose( f );
	*lV = l;
	*ln = n;
	return 1; // Sucesso!
} */

void mostra_mus(void *x){
	Musica *m = x;
	mostra_musica(*m);
}

int compara_musicas_nome(void *a, void *b) {
	Musica *m1 = a, *m2 = b;
	return strcmp(m1->nome, m2->nome);
}

int compara_musicas_nome_art(void *a, void *b) {
	Musica *m1 = a, *m2 = b;
	return strcmp(m1->artista.nome_art, m2->artista.nome_art);
}

int compara_musicas_nome_est(void *a, void *b) {
	Musica *m1 = a, *m2 = b;
	return strcmp(m1->estilo, m2->estilo);
}
