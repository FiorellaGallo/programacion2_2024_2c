#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../TADs/tipo_elemento.h"
#include "ejercicio7.h"
#include "../TADs/pilas.h"

Pila elementosComun(Pila pila1, Pila pila2){
    Pila pilaComunes = p_crear();
    Pila pilaAux1 = p_crear();
    Pila pilaAux2 = p_crear();

    TipoElemento item1, item2, dato1, dato2;

    while(!p_es_vacia(pila1)){
        item1 = p_desapilar(pila1);
        bool coincidencia = false;

        while(!p_es_vacia(pila2)){
            item2 = p_desapilar(pila2);
            if(item1->clave == item2->clave){
                coincidencia = true;
            }
            p_apilar(pilaAux2, item2);
        }

        if(coincidencia){
            p_apilar(pilaComunes, item1);
        }
        while(!p_es_vacia(pilaAux2)){
            dato2 = p_desapilar(pilaAux2);
            p_apilar(pila2, dato2);
        }
        p_apilar(pilaAux1, item1);
    }

    while(!p_es_vacia(pilaAux1)){
        dato1 = p_desapilar(pilaAux1);
        p_apilar(pila1, dato1);
    }

    printf("\nPILA CON ELEMENTOS COMUNES\n");
    p_mostrar(pilaComunes);

    printf("\nPILAS ORIGINALES CONSERVADAS\n");
    printf("\nPILA 1\n");
    p_mostrar(pila1);
    printf("\nPILA 2\n");
    p_mostrar(pila2);

    return pilaComunes;
}

// La complejidad algorítmica de la función "elementosComun"
// es de orden cuadrático O(n x m) ya que los elementos de la
// pila m se iterarán n veces, es decir, por cada elemento n
// se recorren todos los elementos m.

