#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

void raiz (int a, int b, int c, float *r1, float *r2) {
    (*r1) = (-b + sqrt((b*b) - (4*a*c)))/(2*a);
    (*r2) = (-b - sqrt((b*b) - (4*a*c)))/(2*a);
}

int main()
{
    float x1;
    float x2;
    int a, b, c;
    printf ("Digite os coeficientes a, b e c.");
    printf ("\na: ");
    scanf ("%d", &a);
    printf ("\nb: ");
    scanf ("%d", &b);
    printf ("\nc: ");
    scanf ("%d", &c);
    raiz (a, b, c, &x1, &x2);
    printf ("As raizes sao: %.2f e %.2f\n", x1, x2);
    system ("pause");
    return 0;
}