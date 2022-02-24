#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <strings.h>
#include <time.h>

char *repetidor( char *s, int n ){
int tam = strlen(s);
char *nova = malloc((tam*n)+1);
for (int i=0; i<tam; i++) {
    nova[i]=s[i];
}
int aux=1;
while (aux<n){
for (int i=0; i<tam; i++) {
    nova[i + (tam*aux)]=s[i];
}
aux++;
}
nova[(tam*n)]= '\0';
return nova;
}

int main()
{
int n;
printf ("Digite quantas vezes quer repetir a string: ");
scanf("%d", &n);
char stringOriginal[50];
printf("\nDigite a string: ");
scanf(" %[^\n]", stringOriginal);
if (n==0) {
    printf("\nOpcao invalida.");
}
if (n==1) {
    printf ("String nova: %s", stringOriginal);
}
char *stringRepetitida = repetidor(stringOriginal, n);
printf("\nA nova string eh: %s\n", stringRepetitida);
free(stringRepetitida);
system("pause");
return 0;
}