#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../TADs/arbol-binario.h"
#include "../TADs/nodo.h"

bool nodosEquivalentes(NodoArbol nodo1, NodoArbol nodo2){
    if(nodo1 == NULL && nodo2 == NULL){
        return true;
    }

    if(nodo1 == NULL || nodo2 == NULL){
        return false;
    }

    TipoElemento elem1 = n_recuperar(nodo1);
    TipoElemento elem2 = n_recuperar(nodo2);

    return (elem1->clave == elem2->clave) &&
           nodosEquivalentes(n_hijoizquierdo(nodo1), n_hijoizquierdo(nodo2)) &&
           nodosEquivalentes(n_hijoderecho(nodo1), n_hijoderecho(nodo2));
}

bool sonEquivalentes(ArbolBinario arbol1, ArbolBinario arbol2) {
    return nodosEquivalentes(a_raiz(arbol1), a_raiz(arbol2));
}
