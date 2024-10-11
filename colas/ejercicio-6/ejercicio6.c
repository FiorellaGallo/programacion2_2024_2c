#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ejercicio6.h"
#include "../TADs/tipo_elemento.h"
#include "../TADs/colas.h"
#include "../TADs/pilas.h"
#include "../TADs/listas.h"

#define MAX_CAPACIDAD 100

Lista encontrarComunes(Pila pila, Cola cola, Lista lista) {
    Pila pila_copia = p_crear();
    Cola cola_copia = c_crear();

    while (!p_es_vacia(pila)) {
        TipoElemento elem_pila = p_tope(pila);
        p_apilar(pila_copia, te_crear(elem_pila->clave));
        p_desapilar(pila);
    }

    while (!c_es_vacia(cola)) {
        TipoElemento elem_cola = c_recuperar(cola);
        c_encolar(cola_copia, te_crear(elem_cola->clave));
        c_desencolar(cola);
    }

    int pos_pila = 1, pos_cola;
    char buffer[100];

    while (!p_es_vacia(pila_copia)) {
        TipoElemento elem_pila = p_tope(pila_copia);
        p_desapilar(pila_copia);

        pos_cola = 1;

        while (!c_es_vacia(cola_copia)) {
            TipoElemento elem_cola = c_recuperar(cola_copia);

            if (elem_pila->clave == elem_cola->clave) {
                sprintf(buffer, "%d:%d:%d", elem_pila->clave, pos_pila, pos_cola);
                printf("Agregando a lista comunes: %s\n", buffer);
                l_agregar(lista, te_crear(elem_pila->clave));
                l_agregar(lista, te_crear(elem_cola->clave));
            }

            c_desencolar(cola_copia);
            pos_cola++;
        }
        pos_pila++;
    }

    return lista;
}
