#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../TADs/pilas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio6.h"

Pila pilaIterativa(Pila pila, int eliminar){
    Pila pilaAux = p_crear();
    Pila pilaResultado = p_crear();
    Pila pilaResultadoAux = p_crear();

    TipoElemento elem;

    while(!p_es_vacia(pila)){
        elem = p_desapilar(pila);
        if(elem->clave != eliminar){
            p_apilar(pilaResultadoAux, elem);
        }
        p_apilar(pilaAux, elem);
    }

    while(!p_es_vacia(pilaResultadoAux)){
        elem = p_desapilar(pilaResultadoAux);
        p_apilar(pilaResultado, elem);
    }

    p_mostrar(pilaResultado);

    while(!p_es_vacia(pilaAux)){
        elem = p_desapilar(pilaAux);
        p_apilar(pila, elem);
    }

    return pilaResultado;
}

// La complejidad algorítmica de la función "pilaIterativa" es de orden lineal
// O(n) ya que se trata de "iterar" una pila una única vez, por lo que el tiempo
// empleado para la solución del problema crece a medida que las pilas son de mayor tamaño.

Pila pilaRecursiva(Pila pila, int eliminar){
    if(p_es_vacia(pila)){
        return p_crear();
    }

    TipoElemento elem = p_desapilar(pila);
    Pila nueva_pila = pilaRecursiva(pila, eliminar);

    if(elem->clave != eliminar){
        p_apilar(nueva_pila, elem);
    }

    p_apilar(pila, elem);

    return nueva_pila;
}

// La complejidad algorítmica de la función "pilaRecursiva" es de orden lineal
// O(n) ya que cada elemento de la pila se recorre una vez para desapilar
// y otra vez para apilarlo nuevamente. Aunque sean dos operaciones, se realizan sobre cada
// elemento , por lo que la complejidad aumenta mientras la pila sea de mayor tamaño.
