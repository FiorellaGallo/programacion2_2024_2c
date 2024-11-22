#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"

int entero_entre(int min, int max) {
    int numero;
    int resultado;

    do {
        printf("(entre %d y %d): ", min, max);
        resultado = scanf("%d", &numero);

        if (resultado != 1) {
            printf("Entrada invalida. Ingrese un numero entero.\n");
            while (getchar() != '\n');
        } else if (numero < min || numero > max) {
            printf("El numero esta fuera del rango (%d - %d). Intente de nuevo.\n", min, max);
        }

    } while (resultado != 1 || numero < min || numero > max);

    return numero;
}

int leer_entero(const char *mensaje, int min, int max) {
    int numero;
    int resultado;

    do {
        printf("%s (%d - %d): ", mensaje, min, max);
        resultado = scanf("%d", &numero);

        if (resultado != 1) {
            printf("Error: por favor, ingrese un número entero válido.\n");
            while (getchar() != '\n');
        } else if (numero < min || numero > max) {
            printf("El número debe estar entre %d y %d. Inténtelo de nuevo.\n", min, max);
        } else {
            break;
        }
    } while(1);

    return numero;
}
