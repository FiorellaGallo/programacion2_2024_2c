#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ejercicio2.h"
#include "../TADs/tipo_elemento.h"
#include "../TADs/colas.h"
#include "../TADs/pilas.h"

void cargar_cola(Cola cola) {
    char input[20];
    int num;
    while (1) {
        printf("Ingrese un numero (o '*' para finalizar): ");
        scanf("%s", input);

        if (input[0] == '*') {
            break;
        }

        if (sscanf(input, "%d", &num) == 1) {
            TipoElemento elem = te_crear(num);
            if (!c_encolar(cola, elem)) {
                printf("Cola llena, no se pueden agregar mas elementos.\n");
                break;
            }
            printf("Numero %d encolado correctamente.\n", num);
        } else {
            printf("Entrada invalida, intente nuevamente.\n");
        }
    }
}

bool elementoEnCola(Cola cola, TipoElemento elemento){
    Cola colaAux = c_crear();
    TipoElemento elem;
    bool aparece = false;

    while(!c_es_vacia(cola)){
        elem = c_desencolar(cola);
        if(elem->clave == elemento->clave){
            aparece = true;
        }
        c_encolar(colaAux, elem);
    }
    while(!c_es_vacia(colaAux)){
        elem = c_desencolar(colaAux);
        c_encolar(cola, elem);
    }
    return aparece;
}

Cola colarElemento(Cola cola, TipoElemento elemento, unsigned int posicion){
    Cola cola_auxiliar = c_crear();
    int i = 0;

    while (!c_es_vacia(cola)) {
        if (i == posicion) {
            c_encolar(cola_auxiliar, elemento);
        }
        TipoElemento elemento = c_desencolar(cola);
        c_encolar(cola_auxiliar, elemento);
        i++;
    }

    if (i <= posicion) {
        c_encolar(cola_auxiliar, elemento);
    }

    return cola_auxiliar;
}

Cola eliminarApariciones(Cola cola, TipoElemento clave) {
    Cola cola_aux = c_crear();
    TipoElemento elem_actual;

    while (!c_es_vacia(cola)) {
        elem_actual = c_desencolar(cola);

        if (elem_actual->clave != clave->clave) {
            c_encolar(cola_aux, elem_actual);
        }
    }


    while (!c_es_vacia(cola_aux)) {
        elem_actual = c_desencolar(cola_aux);
        c_encolar(cola, elem_actual);
    }
    printf("Se han eliminado todas las apariciones del elemento con clave %d.\n", clave->clave);
    return cola;
}

int contarElementos(Cola cola) {
    int contador = 0;
    Cola cola_aux = c_crear();
    TipoElemento elem_actual;

    while (!c_es_vacia(cola)) {
        elem_actual = c_desencolar(cola);
        contador++;
        c_encolar(cola_aux, elem_actual);
    }


    while (!c_es_vacia(cola_aux)) {
        elem_actual = c_desencolar(cola_aux);
        c_encolar(cola, elem_actual);
    }

    return contador;
}

Cola copiarCola (Cola cola_original) {
    Cola cola_copia = c_crear();
    Cola cola_aux = c_crear();
    TipoElemento elemento_actual;

    while (!c_es_vacia(cola_original)) {
        elemento_actual = c_desencolar(cola_original);
        c_encolar(cola_copia, elemento_actual);
        c_encolar(cola_aux, elemento_actual);
    }


    while (!c_es_vacia(cola_aux)) {
        elemento_actual = c_desencolar(cola_aux);
        c_encolar(cola_original, elemento_actual);
    }

    return cola_copia;
}

Cola invertirCola (Cola cola_original) {
    Cola cola_invertida = c_crear();
    Pila pila = p_crear();


    while (!c_es_vacia(cola_original)) {
        TipoElemento elemento = c_desencolar(cola_original);
        p_apilar(pila, elemento);
    }

    while (!p_es_vacia(pila)) {
        TipoElemento elemento = p_desapilar(pila);
        c_encolar(cola_invertida, elemento);
    }

    free(pila);

    return cola_invertida;
}
