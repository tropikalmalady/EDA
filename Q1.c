#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <strings.h>
#include <time.h>

void troca_valor(float *x, float *y) {
    float aux;
    aux=*x;
    *x=*y;
    *y=aux;
}

int main()
{
    float a, b;
    printf ("Digite dois numeros.");
    printf("\na: ");
    scanf ("%f", &a);
    printf("\nb: ");
    scanf ("%f", &b);
    troca_valor (&a, &b);
    printf ("a: %.2f\nb: %.2f\n", a, b);
    system ("pause");
    return 0;
}