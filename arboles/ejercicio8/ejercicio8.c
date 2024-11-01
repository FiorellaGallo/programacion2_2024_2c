#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../TADs/nodo.h"
#include "../TADs/arbol-binario.h"

int alturaArbol(NodoArbol nodo){
    if (nodo == NULL) return 0;

    int alturaHijo = alturaArbol(nodo->hi);
    int alturaHermano = alturaArbol(nodo->hd);

    return 1 + (alturaHijo > alturaHermano ? alturaHijo : alturaHermano);
}

int nivelNodo(NodoArbol raiz, int clave, int nivelActual) {
     if (raiz == NULL) {
        return -1;
    }
    if (raiz->datos->clave == clave) {
        return nivelActual;
    }

    int nivelIzq = nivelNodo(raiz->hi, clave, nivelActual + 1);
    if (nivelIzq != -1) {
        return nivelIzq;
    }

    int nivelDer = nivelNodo(raiz->hd, clave, nivelActual + 1);
    return nivelDer;
}

void listarNodosInternos(NodoArbol nodo){
    if (nodo == NULL) return;

    if (nodo->hi != NULL){
        printf("%d ", nodo->datos->clave);
    }
    listarNodosInternos(nodo->hi);
    listarNodosInternos(nodo->hd);
}



int verificarHojas(NodoArbol nodo, int *nivelHoja, int nivelActual) {
    if (nodo == NULL) {
        return 1;
    }

    if (nodo->hi == NULL && nodo->hd == NULL) {
        if (*nivelHoja == -1) {
            *nivelHoja = nivelActual;
        } else if (*nivelHoja != nivelActual) {
            return 0;
        }
    }

    return verificarHojas(nodo->hi, nivelHoja, nivelActual + 1) &&
           verificarHojas(nodo->hd, nivelHoja, nivelActual + 1);
}

int hojasMismoNivel(NodoArbol raiz) {
    int nivelHoja = -1;
    return verificarHojas(raiz, &nivelHoja, 0);
}

