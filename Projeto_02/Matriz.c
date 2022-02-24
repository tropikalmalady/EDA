#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"

void inicializa_matriz( Matriz *p, int l, int c ){
	p->lin = l;
	p->col = c;
	
	p->dados = malloc( sizeof(int *) * l );
	int i, j;
	for( i = 0 ; i < l ; i++ ){
		p->dados[i] = calloc(c, sizeof(int) );
		/*
		p->dados[i] = malloc( sizeof(int) * c );
		for( j = 0 ; j < c; j++ )
			p->dados[i][j] = 0;
		*/
	}
}

void mostra_matriz( Matriz m ){
	printf("Dados da matriz %dx%d:\n", m.lin, m.col);
	int i, j;
	for( i = 0 ; i < m.lin ; i++ ){
		for( j = 0 ; j < m.col ; j++ )
			printf("%4d ", m.dados[i][j]);
		printf("\n");
	}
	printf("\n");
}

int set_matriz( Matriz *p, int i, int j, int valor ){
	if( i >= p->lin || j >= p->col )
		return ERRO_COORD_INVALIDA;
	
	p->dados[i][j] = valor;
	return 1; // Sucesso.	
}

int get_matriz( Matriz m, int i, int j, int *p_valor ){
	if( i >= m.lin || j >= m.col )
		return ERRO_COORD_INVALIDA;
	
	*p_valor = m.dados[i][j];
	return 1; // Sucesso.	
}

int compara_matrizes( Matriz m1, Matriz m2 ){
	if( m1.lin != m2.lin || m1.col != m2.col )
		return 0; // Falso, s�o diferentes!
	
	int i, j;
	for( i = 0 ; i < m1.lin ; i++ )
		for( j = 0 ; j < m1.col ; j++ )
			if( m1.dados[i][j] != m2.dados[i][j] )
				return 0; // Falso, s�o diferentes!
				
	return 1; // Verdadeiro, s�o iguais!
}
int carrega_matriz_arquivo( char *nome_arq, Matriz *p, int dim ){
    FILE *f = fopen( nome_arq, "rt" );
    if( f == NULL ) {
        return 0;	}// 0 (falso) --> erro no arquivo ou arquivo não existe!
	int i,j;
    inicializa_matriz( p, dim, dim );

    for( i = 0 ; i < dim ; i++ ) {
        for( j = 0 ; j < dim ; j++ ){
            int valor;
            fscanf( f, "%d", &valor);
            set_matriz( p , i, j, valor );
        }
	}
    fclose( f );
    return 1; // 1 (verdadeiro) --> carga realizada!
}
