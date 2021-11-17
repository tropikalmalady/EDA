#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <strings.h>
#include <time.h>

void cacula_hora(int totalMinutos, int *ph, int *pm) {
    *ph = totalMinutos/60;
    *pm = totalMinutos%60;
    int dias;
    dias = *ph/24;
    if (dias>1) {
        *ph = *ph - (24*dias);
        printf ("\nPassou-se %d dias.", dias);
    }
}

int main()
{   
    int minutos, hora_atual, minuto_atual;
    printf ("Quantos minutos se passaram desde a meia-noite: ");
    scanf ("%d", &minutos);
    cacula_hora (minutos, &hora_atual, &minuto_atual);
    printf ("\nHora atual: %dh %dmin\n", hora_atual, minuto_atual);
    system ("pause");
    return 0;
}