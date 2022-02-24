#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <strings.h>
#include <time.h>

float *clone( float *v, int n ){
float *vetorClone=malloc(sizeof(float)*n);
for (int i=0; i<n; i++)
    vetorClone[i] = v[i];
return vetorClone;
}

int main ()
{
int tam;
printf("Digite o tamanho do vetor: ");
scanf("%d", &tam);
float vetor[tam];
for (int i=0; i<tam; i++) {
    printf("\nDigite o valor de posicao %d do vetor:", i);
    scanf("%f", &vetor[i]);
}
float *vetorClone=clone(vetor, tam);
printf("\nVetor original: "); 
for (int i=0; i<tam; i++) {
    printf("%.2f, ", vetor[i]);
}
printf("\nVetor clone: ");
for (int i=0; i<tam; i++){
    printf("%.2f, ", vetorClone[i]);
}
free(vetorClone);
system("pause");
return 0;
}