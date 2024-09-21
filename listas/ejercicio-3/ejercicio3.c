#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../TADs/listas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio3.h"


bool determinarMultiplo(Lista l1, Lista l2) {
    TipoElemento aux1, aux2, sigAux1, sigAux2;
    bool multiplo = true;
    bool escalar = true;
    int cociente = 0;

    Iterador i1 = iterador(l1);
    Iterador i2 = iterador(l2);

    while (hay_siguiente(i1) && hay_siguiente(i2)) {
            aux1 = siguiente(i1);
            aux2 = siguiente(i2);

        // verificar que la division de l2 por l1 de resto cero
        if (aux1->clave == 0 || aux2->clave % aux1->clave != 0) {
            multiplo = false;
            break;
        } else {
            //si l2 es multiplo de l1, ver si es multiplo por un escalar
            int nuevoCociente = aux2->clave / aux1->clave;

            if (cociente == 0) {
                cociente = nuevoCociente;
            } else if (nuevoCociente != cociente) {
                escalar = false;
            }
        }
    }

    //ver si alguna de las listas quedo con elementos, entonces no es multiplo
    if (hay_siguiente(i1) || hay_siguiente(i2)) {
        multiplo = false;
    }

    if (multiplo && escalar) {
        printf("L2 es multiplo de L1 por un escalar\n");
    } else {
        printf("L2 no es multiplo de L1 por un escalar\n");
    }

    return multiplo;
}
