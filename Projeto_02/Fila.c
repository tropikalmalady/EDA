#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void inicializa_fila ( Fila *f, int c ){
	f->dados = malloc( sizeof(int) * c );
	f->inicio = 0;
	f->n = 0;
	f->capacidade = c;
}

int fila_vazia ( Fila f ) {
	return f.n == 0;
}

int fila_cheia ( Fila f ) {
	return f.n == f.capacidade;
}

int inserir ( Fila *f, int info ){
	if( fila_cheia ( *f ) )
		return ERRO_FILA_CHEIA;
	
	int fim = ( f->inicio + f->n ) % f->capacidade;
	f->dados[fim] = info;
	f->n++;
	return 1; // Sucesso
}

int remover ( Fila *f, int *info ){
	if( fila_vazia ( *f ) )
		return ERRO_FILA_VAZIA;
	
	*info = f->dados[f->inicio];
	f->inicio = (f->inicio + 1) % f->capacidade;
	f->n--;
	return 1; // Sucesso
}

void mostra_fila ( Fila f ){
	if( fila_vazia ( f ) )
		printf("Fila vazia!\n");
	else{
		printf("Dados da fila:\n");
		int i, cont;

		for( cont = 0, i = f.inicio ; cont < f.n ; cont++, i = (i + 1) % f.capacidade )
			printf("[%d] %d\n", i, f.dados[i]);
		
	}
	printf("\n");
}
void desaloca_fila( Fila *f ) {
	free( f->dados );
}


