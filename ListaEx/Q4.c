#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <strings.h>
#include <time.h>

void max_min(int vet[], int tam, int *pMin, int *pMax) {
*pMin=vet[0];
*pMax=vet[0];
for (int i=1; i<tam; i++) {
    if (vet[i]>*pMax) {
        *pMax=vet[i];
    }
    if (vet[i]<*pMin) {
        *pMin=vet[i];
    }
}
}

int main ()
{
int tamanho, minValor, maxValor;
printf ("DIgite o tamanho do vetor: ");
scanf ("%d", &tamanho);
int vetor[tamanho];
for (int i=0; i<tamanho; i++) {
    printf ("\nDigite o valor de posicao %d do vetor: ", i);
    scanf ("%d", &vetor[i]);
}
max_min(vetor, tamanho, &minValor, &maxValor);
printf("\nO maior valor do vetor eh %d e o menor eh %d.\n", maxValor, minValor);
system("pause");
return 0;
}