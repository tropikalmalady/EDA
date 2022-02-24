#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pilha.h"
#include "Fila.h"
#include "Matriz.h"

int main() {
    int vert, A, B, i, j, valor;
    Matriz m;
    Pilha p;
    Fila f;
    int *status;
    int *antecessores;
    printf("Certifique-se de colocar a matriz que representa o grafo no arquivo grafo.txt!!");
    printf("\nDigite o numero de vertices do grafo: ");
    scanf("%d", &vert);
    inicializa_matriz(&m, vert, vert);
    status=malloc(sizeof(int)*vert);
    for (i=0; i<vert; i++){
        status[i]=0;
    }
    antecessores=malloc(sizeof(int)*vert);
    for (i=0; i<vert; i++){
        antecessores[i]=0;
    }
    inicializa_fila (&f, vert);
    /*for (i=0; i<vert; i++){
        for (j=0; j<vert; j++){
            printf("\nDigite o grafo em forma de matriz adjacente: ");
            printf("\n[%d][%d]: ", i+1, j+1);
            scanf("%d", &valor);
            set_matriz(&m, i, j, valor);
        }
    }*/
    carrega_matriz_arquivo("grafo.txt", &m, vert);
    printf("\nDigite por qual vertice deseja iniciar (A): ");
    scanf("%d", &A);
    A--;
    printf("\nDigite por qual vertice deseja finalizar (B): ");
    scanf("%d", &B);
    B--;
    status[A]=1;
    inserir(&f, A);
    int achou=0;
    int x;
    do {
        remover(&f, &x);
        if (x==B) {
            achou=1;
        } else {
            for (i=0; i<vert; i++){
                if (m.dados[x][i]==1){
                    if (status[i]==0) {
                        status[i]=1;
                        antecessores[i]=x;
                        inserir(&f, i);      
                    }
                }
            }
        }
    } while ((f.n != 0) && (achou==0));
    if (achou==1) {
        inicializa_pilha(&p, vert);
        do {
            empilha(&p, x);
            x=antecessores[x];
        } while (x != 0);
        do {
            desempilha(&p, &x);
            printf ("%d ", x+1);
        } while (p.topo!=-1);
    } else {
        printf ("\nB nao eh alcancavel a partir de A!");
    }
    desaloca_fila(&f);
    desaloca_pilha(&p);
    free(status);
    free(antecessores);
    printf ("\nAutores: Lincolnn Palhares e Felipe Hansen");
    return 0;
}

