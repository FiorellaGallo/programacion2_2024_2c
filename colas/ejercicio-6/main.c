#include <stdio.h>
#include <stdlib.h>
#include "../TADs/colas.h"
#include "../TADs/pilas.h"
#include "../TADs/listas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio6.h"

#define CANTIDAD_ELEMENTOS 10

int main() {
     Pila pila = p_crear();
    Cola cola = c_crear();
    Lista lista = l_crear();

    srand(time(NULL));

    for (int i = 0; i < CANTIDAD_ELEMENTOS; i++) {
        int numero_aleatorio = rand() % 10;
        TipoElemento elemento = te_crear(numero_aleatorio);
        p_apilar(pila, elemento);
        printf("Elemento %d agregado a la pila\n", numero_aleatorio);
    }

    for (int i = 0; i < CANTIDAD_ELEMENTOS; i++) {
        int numero_aleatorio = rand() % 10;
        TipoElemento elemento = te_crear(numero_aleatorio);
        c_encolar(cola, elemento);
        printf("Elemento %d agregado a la cola\n", numero_aleatorio);
    }

    Lista comunes = encontrarComunes(pila, cola, lista);
    l_mostrar(comunes);
    return 0;
}
