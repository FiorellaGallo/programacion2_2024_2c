#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ejercicio7.h"

void ondasDigitales(char *entrada, char *salida, int posicion) {

    //comparar si llego al final de la cadena o esta vacia
    if(*entrada == '\0') {
        salida[posicion] = '\0';
        return;
    }

    char actual = tolower(*entrada);
    char anterior = (posicion == 0) ? '\0' : tolower(*(entrada - 1));

    if (actual == 'l') {
        if (anterior == 'h') {
            salida[posicion] = '|';
            salida[posicion + 1] = '_';
            posicion += 2;
        } else {
            salida[posicion] = '_';
            posicion++;
        }
    } else if ( actual == 'h') {
        if (anterior == 'l') {
            salida[posicion] = '|';
            salida[posicion + 1] = '-';
            posicion += 2;
        } else {
            salida[posicion] = '-';
            posicion++;
        }
    }

    //agregar espacio luego de cada caracter
    if (*(entrada + 1) != '\0') {
        salida[posicion] = ' ';
        posicion++;
    }

    //llamada recursiva que avanza al siguiente caracter para procesarlo (entrada + 1)
    ondasDigitales(entrada + 1, salida, posicion);
}
