#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <strings.h>
#include <time.h>
#define PI 3.14

void calcula_circulo(float raio, float *pPerimetro, float *pArea) {
    *pPerimetro = 2*PI*raio;
    *pArea = PI*(raio*raio);
}

int main()
{   
    float raio, perimetro, area;
    printf ("Digite o raio do circulo: ");
    scanf ("%f", &raio);
    calcula_circulo (raio, &perimetro, &area);
    printf ("Perimetro: %.2f\nArea: %.2f\n", perimetro, area);
    system ("pause");
    return 0;
}