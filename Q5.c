#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <strings.h>
#include <time.h>

void max_vetor(float vet[], int tam, float *pMax, int *pIndice) {
*pIndice=0;
*pMax=vet[0];
for (int i=1; i<tam; i++) {
    if (vet[i]>*pMax) {
        *pMax=vet[i];
        *pIndice=i;
    }
}
}

int main ()
{
int tamanho, indice;
float maxValor;
printf ("DIgite o tamanho do vetor: ");
scanf ("%d", &tamanho);
float vetor[tamanho];
for (int i=0; i<tamanho; i++) {
    printf ("\nDigite o valor de posicao %d do vetor: ", i);
    scanf ("%f", &vetor[i]);
}
max_vetor(vetor, tamanho, &maxValor, &indice);
printf("\nO maior valor do vetor eh %.2f e o seu indice eh %d.\n", maxValor, indice);
system("pause");
return 0;
}