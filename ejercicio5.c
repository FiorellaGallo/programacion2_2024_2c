#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ejercicio5.h"

void separarMiles(char *numero, int longitud) {
    if (longitud <= 3) {
        printf("%s", numero);
    } else {
        separarMiles(numero, longitud - 3);
        printf(",%s", numero + longitud - 3);
    }
}

void separadorMiles(char numero[]) {
    int longitud = strlen(numero);

    separarMiles(numero, longitud);
}
