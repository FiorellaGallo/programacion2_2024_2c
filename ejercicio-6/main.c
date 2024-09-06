#include <stdio.h>
#include <stdlib.h>
#include "ejercicio6.h"

int main()
{
    int chinos;
    printf("\nIngrese el nivel de la delegacion china que desea ver entre 1 y 50. Ingrese 0 para salir del sistema: ");

    while (1) {
        if (scanf("%d", &chinos) != 1) {
            fflush(stdin);
            while(fgetc(stdin) != '\n');

            printf("\Dato incorrecto. Ingrese un numero entre 1 y 50 (0 para salir): ");
            continue;
        }

        if (chinos == 0) {
            printf("\nSaliste del sistema.\n");
            return 0;
        }
        if (chinos < 1 || chinos > 50) {
            printf("Nivel de delegacion fuera de rango. Ingrese un numero entre 1 y 50 (0 para salir): ");
            continue;
        }
        printf("La delegacion china de nivel %d se ve asi:\n", chinos);
        delegacion(chinos);

        printf("\nIngrese el nivel de la delegacion china que desea ver. Ingrese 0 para salir del sistema: ");
    }

    return 0;
}
