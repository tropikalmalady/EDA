#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Matriz.h"

int main() {
    int vert, ini;
    Matriz m;
    Pilha p;
    int *status;
    printf("Certifique-se de colocar a matriz que representa o grafo no arquivo grafo.txt!!");
    printf("\nDigite o numero de vertices do grafo: ");
    scanf("%d", &vert);
    inicializa_matriz(&m, vert, vert);
    status=malloc(sizeof(int)*vert);
    for (int i; i<vert; i++){
        status[i]=0;
    }
    inicializa_pilha(&p, vert);
    int valor;
    /*for (int i=0; i<vert; i++){
        for (int j=0; j<vert; j++){
            printf("\nDigite o grafo em forma de matriz adjacente: ");
            printf("\n[%d][%d]: ", i+1, j+1);
            scanf("%d", &valor);
            set_matriz(&m, i, j, valor);
        }
    }*/
    carrega_matriz_arquivo("grafo.txt", &m, vert); //necessário usar o arquivo grafo.txt, caso contrário descomentar linhas acima!
    printf("\nDigite por qual vertice deseja iniciar: ");
    scanf("%d", &ini);
    ini--;
    empilha(&p, ini);
    int x;
    do {
        desempilha(&p, &x);
        if (status[x]==0) {
            printf("\n%d", x+1);
            status[x]=1;
            for (int i=0; i<vert; i++){
                if (m.dados[x][i]==1){
                    if (status[i]==0){
                        empilha(&p, i);
                    }
                }
            }
        }
    }  while(p.topo!=-1);
    printf("\nFim do programa! ");
    free(status);
    system ("pause");
    return 0;
}