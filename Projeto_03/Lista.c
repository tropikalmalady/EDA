#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Musica.h"

//Privado------------------------

Elemento *aloca_elemento( void *info, int tam ) {
	Elemento *p = malloc( sizeof(Elemento) );
	if( p == NULL )
		return NULL; // Erro, falta de mem?ria!
	p->info = malloc( tam );
	if( p->info == NULL ){
		free(p);
		return NULL; // Erro, falta de mem?ria!
	}
	memcpy(p->info, info, tam);
	return p; // Sucesso!
}

//-------------------------------


void inicializa_lista( Lista *p, int t ){
	p->tamInfo = t;
	p->cabeca = NULL;
	p->qtd = 0;
}

int lista_vazia ( Lista l ){
	return l.cabeca == NULL;
}

int insere_inicio( Lista *p, void *info ){
	Elemento *novo = aloca_elemento( info, p->tamInfo );
	if( novo == NULL )
		return 0; // Erro, falta de mem?ria!

	novo->proximo = p->cabeca;
	p->cabeca = novo;
	p->qtd++;
	return 1; // Sucesso!
}

int remove_inicio( Lista *p, void *info ){
	if( lista_vazia( *p ) )
		return ERRO_LISTA_VAZIA;

	Elemento *aux = p->cabeca;
	memcpy( info, aux->info, p->tamInfo );
	p->cabeca = aux->proximo;
	free( aux->info );
	free( aux );
	p->qtd--;
	return 1; // Sucesso!
}

int insere_fim( Lista *p, void *info ){
	if( lista_vazia( *p ) )
		return insere_inicio( p, info );

	Elemento *aux = p->cabeca;
	while( aux->proximo != NULL )
		aux = aux->proximo;

	Elemento *novo = aloca_elemento( info, p->tamInfo );
	if( novo == NULL )
    	return 0; // Erro, falta de mem?ria!

	aux->proximo = novo;
	novo->proximo = NULL;
	p->qtd++;
	return 1; // Sucesso!
}

int remove_fim( Lista *p, void *info ){
   if( lista_vazia( *p ) )
      return ERRO_LISTA_VAZIA;
   if( p->qtd == 1 )
      return remove_inicio( p, info );
   Elemento *aux = p->cabeca;
   while( aux->proximo->proximo != NULL )
      aux = aux->proximo;
   Elemento *ultimo = aux->proximo;
   memcpy( info, ultimo->info, p->tamInfo );
   free( ultimo->info );
   free( ultimo );
   aux->proximo = NULL;
   p->qtd--;
   return 1; // Sucesso!
}

int insere_pos( Lista *p, void *info , int pos ){
	if( pos < 0 || pos > p->qtd )
		return ERRO_POS_INVALIDA;
		
	if( pos == 0 )
		return insere_inicio( p, info );
	
	Elemento *aux = p->cabeca;
	int cont;
	for( cont = 0 ; cont < pos-1 ; cont++ )
		aux = aux->proximo; // Vai at? elemento em pos-1
	
	Elemento *novo = aloca_elemento( info, p->tamInfo );
	if( novo == NULL )
		return 0; // Erro, falta de mem?ria!
	
	novo->proximo = aux->proximo;
	aux->proximo = novo;
	p->qtd++;
	return 1; // Sucesso!
}

int remove_pos( Lista *p, void *info , int pos, void (*mostra)(void *) ){
	if( lista_vazia( *p ) )
		return ERRO_LISTA_VAZIA;

	if( pos < 0 || pos >= p->qtd )
		return ERRO_POS_INVALIDA;
	
	if( pos == 0 )
		return remove_inicio( p, info );

	Elemento *aux = p->cabeca;
	int cont, confirma;
	for( cont = 0 ; cont < pos-1 ; cont++ )
		aux = aux->proximo; // Vai at? pos-1 
	
	Elemento *remover=aux->proximo;
	printf("\n%d - ", cont +1);
	mostra( remover->info );
	printf("\nDeseja mesmo remover esta musica?\n1 = SIM, 2=NAO: ");
	scanf("%d", &confirma);
	if (confirma==1) {
		Elemento *x = aux->proximo;
		aux->proximo = x->proximo;
		memcpy( info, x->info, p->tamInfo );
		free( x->info );
		free( x );
		p->qtd--;
		printf("\nMusica removida!");
		return 1; // Sucesso!
	} else {
		printf("\nMusica nao foi removida!");
		return 2;
	}
}

int le_valor( Lista l, void *info , int pos ){
	if( lista_vazia( l ) )
		return ERRO_LISTA_VAZIA;

	if( pos < 0 || pos >= l.qtd )
		return ERRO_POS_INVALIDA;
		
	Elemento *aux = l.cabeca;
	int cont;
	for( cont = 0 ; cont < pos ; cont++ )
		aux = aux->proximo; // Vai at? elemento em pos
	memcpy( info, aux->info, l.tamInfo );
	return 1; // Sucesso!
}

int modifica_valor( Lista l, void *info , int pos ){
	if( lista_vazia( l ) )
		return ERRO_LISTA_VAZIA;

	if( pos < 0 || pos >= l.qtd )
		return ERRO_POS_INVALIDA;
		
	Elemento *aux = l.cabeca;
	int cont;
	for( cont = 0 ; cont < pos ; cont++ )
		aux = aux->proximo; // Vai at? elemento em pos
	
	memcpy( aux->info, info, l.tamInfo );
	return 1; // Sucesso!
}

int insere_ordem( Lista *p, void *info , int (*compara)(void*, void*) ){
	Elemento *aux = p->cabeca;
	int cont = 0;

	while( aux != NULL && compara( info, aux->info ) > 0 ){
		aux = aux->proximo;
		cont++;
	}

	return insere_pos( p, info, cont );
}


void mostra_lista( Lista l, void (*mostra)(void *) ){
	if( lista_vazia( l ) )
		printf("Lista vazia!\n");
	else{
		printf("Dados da lista (%d elementos):\n", l.qtd );
		Elemento *p = l.cabeca;
		int cont = 0; // cont ? o ?ndice do elemento dentro da lista.
		while( p != NULL ){
			printf("\n%d - ", cont);
			mostra( p->info ); // Invoca??o por callback
			p = p->proximo;
			cont++;
		}
	}
	printf("\n--------------------------------\n");
}

int conta_elementos( Lista l ){
	int cont = 0;
	Elemento *p = l.cabeca;
	while( p != NULL ){
		cont++;
		p = p->proximo;
	}
	return cont;
}

void limpa_lista( Lista *l ){
	Elemento *p = l->cabeca;
	while( p != NULL ){
		Elemento *prox = p->proximo;
		free( p->info );
		free( p );
		p = prox;
	}
	l->cabeca = NULL;
	l->qtd = 0;
}

// Quest?o 2
int busca( Lista l, void *info, int (*compara)(void*, void*) ){
	int cont = 0;
	Elemento *p = l.cabeca;
	while( p != NULL ){ // Enquanto houver elementos na lista
		if( compara( p->info, info ) == 0 )
			return cont;  // Retorna cont, indicando que encontrou no ?ndice 'cont'.
		
		p = p->proximo;
		cont++;
	}
	return -1; // Percorreu a lista, mas n?o encontrou!
}

Lista busca_varios( Lista l, void *info, int (*compara)(void*, void*) ){
	Lista result;
	inicializa_lista( &result, sizeof(int) ); // Lista de inteiros, pois s?o ?ndices

	int cont = 0;
	Elemento *p = l.cabeca;
	while( p != NULL ){ // Enquanto houver elementos na lista
		if( compara( p->info, info ) == 0 )
			insere_fim( &result, &cont ); // Guarda na lista de ?ndices o valor de 'cont'
		
		p = p->proximo;
		cont++;
	}
	return result; // Retorna a lista de ?ndices
}
