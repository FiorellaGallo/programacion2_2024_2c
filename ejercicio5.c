#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ejercicio5.h"

void separarMiles(char *numero, int longitud) {
    if (longitud <= 3) {
        printf("%s", numero);
    } else {
        char temp[4];
        strncpy(temp, numero, 3);
        temp[3] = '\0';

        separarMiles(numero + 3, longitud - 3);
        printf(",%s", temp);
    }
}

void separadorMiles(char numero[]) {
    int longitud = strlen(numero);

    separarMiles(numero, longitud);
}
