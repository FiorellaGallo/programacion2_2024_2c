#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ejercicio5.h"

void separarMiles(char *numero, int longitud) {
    if (longitud <= 3) {
        printf("%s", numero);
    } else {

        int primerGrupo = longitud % 3;
        if (primerGrupo == 0) {
            primerGrupo = 3;
        }
        for (int i = 0; i < primerGrupo; i++) {
            printf("%c", numero[i]);
        }
        printf(".");
        separarMiles(numero + primerGrupo, longitud - primerGrupo);
    }
}

void separadorMiles(char *numero) {
    int longitud = strlen(numero);

    if (numero[0] == '-') {

        printf("-");

        separarMiles(numero + 1, longitud - 1);
    } else {
        separarMiles(numero, longitud);
    }
}
