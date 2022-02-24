#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Musica.h"

int main(int argc, char *argv[]) {
	Lista l;
	Musica m1, mBusca;
	Musica *removida;
	char busca[30];
	int opcao;
	int i, idx, rm;
	int menu=1;
	inicializa_lista(&l, sizeof(Musica));
	/*int x =carrega_arquivo("musicas.txt", &m1, &l, &l.qtd);
	if (x) {
		printf("\nArquivo de musicas carregado.");
	} else {
		printf("\nArquivo noo foi carregado.");
	}*/
	while (menu) {
		printf("\n-------------------------------------");
		printf("\n1 - Mostrar lista de musicas");
		printf("\n2 - Cadastrar musica nova");
		printf("\n3 - Buscar musicas pelo nome");
		printf("\n4 - Buscar musicas pelo artista");
		printf("\n5 - Buscar musicas pelo estilo");
		printf("\n6 - Remover musica pelo indice");
		printf("\n7 - Sair do programa");
		printf("\n-------------------------------------");
		printf("\nOpcao escolhida: ");
		scanf("%d", &opcao);
		switch (opcao) {
			case 1:
				mostra_lista(l, mostra_mus);
				break;
			case 2:
				printf("\n-------------------------------------");
				printf("\nDigite o nome da musica: ");
				scanf(" %[^\n]", m1.nome);
				printf("\nDigite a duracao em segundos: ");
				scanf("%d", &m1.duracao);
				printf("\nDigite o estilo da musica: ");
				scanf(" %[^\n]", m1.estilo);
				printf("\nDigite o nome do artista: ");
				scanf(" %[^\n]", m1.artista.nome_art);
				printf("\nDigite a nacionalidade do artista: ");
				scanf(" %[^\n]", m1.artista.nacionalidade);
				printf("\nDigite o dia em que foi lancada: ");
				scanf("%d", &m1.data.dia);
				printf("\nDigite o mes em que foi lancada: ");
				scanf("%d", &m1.data.mes);
				printf("\nDigite o ano em que foi lancada: ");
				scanf("%d", &m1.data.ano);
				if (compara_musicas_nome==0 && compara_musicas_nome_art==0) {
					printf("\nMusica repetida. N�o foi possivel cadastrar.");
				} else {
					insere_ordem(&l, &m1, compara_musicas_nome);
				}
				break;
			case 3:
				printf("\nBuscar por nome da musica: ");
				scanf("%s", busca);
				strcpy(mBusca.nome, busca);
				Lista indices = busca_varios(l, &mBusca, compara_musicas_nome);
				if (lista_vazia(indices)) {
					printf("\nMusica nao encontrada.\n");
				} else {
					printf("\nMusicas encontradas nos seguintes indices:\n");
					for (i=0; le_valor(indices, &idx, i)!= ERRO_POS_INVALIDA; i++) {
						printf("\n%d - ", idx);
						le_valor( l, &mBusca, idx );
						mostra_musica(mBusca);
					}
					limpa_lista(&indices);
				}
				break;
			case 4:
				printf("\nBuscar por nome do artista: ");
				scanf("%s", busca);
				strcpy(mBusca.artista.nome_art, busca);
				indices = busca_varios(l, &mBusca, compara_musicas_nome_art);
				if (lista_vazia(indices)) {
					printf("\nMusica nao encontrada.\n");
				} else {
					printf("\nMusicas encontradas nos seguintes indices:\n");
					for (i=0; le_valor(indices, &idx, i)!= ERRO_POS_INVALIDA; i++) {
						printf("\n%d - ", idx);
						le_valor( l, &mBusca, idx );
						mostra_musica(mBusca);
					}
					limpa_lista(&indices);
				}
				break;
			case 5:
				printf("\nBuscar por estilo: ");
				scanf("%s", busca);
				strcpy(mBusca.estilo, busca);
				indices = busca_varios(l, &mBusca, compara_musicas_nome_est);
				if (lista_vazia(indices)) {
					printf("\nMusica nao encontrada.\n");
				} else {
					printf("\nMusicas encontradas nos seguintes indices:\n");
					for (i=0; le_valor(indices, &idx, i)!= ERRO_POS_INVALIDA; i++) {
						printf("\n%d - ", idx);
						le_valor( l, &mBusca, idx );
						mostra_musica(mBusca);
					}
					limpa_lista(&indices);
				}
				break;
			case 6:
				printf("\nDigite o indice da musica que deseja remover: ");
				scanf("%d", &rm);
				remove_pos(&l, &removida, rm, mostra_mus);
				break;
			case 7:
				printf("\n");
				menu=0;	
				break;
			default:
				printf("Opcao invalida. Digite novamente.");
		}
	}
	system ("pause");
	return 0;
}
