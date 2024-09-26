#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ejercicio8.h"
#include "../TADs/tipo_elemento.h"
#include "../TADs/pilas.h"

Pila cantidadApariciones(Pila pila) {
    if(p_es_vacia(pila)) {
        printf("Error. La pila está vacía\n");
        return NULL;
    }

    Pila pilaAux = p_crear();
    TipoElemento elemAux;
    int valorMax = -1;
    int valorMin = valorMax;


    //desapilar y guardar max y min
    while(!p_es_vacia(pila)) {
        elemAux = p_desapilar(pila);
        if(elemAux->clave > valorMax){
            valorMax = elemAux->clave;
        }
        if(elemAux->clave < valorMin){
            valorMin = elemAux->clave;
        }
        p_apilar(pilaAux, elemAux);
    }

    //array para contar apariciones
    int rango = valorMax - valorMin + 1;
    int* apariciones = calloc(rango, sizeof(int));;

    for(int i = 0; i < rango; i++){
        apariciones[i] = 0;
    }

    //volver a apilar en la original y contar apariciones
    while(!p_es_vacia(pilaAux)) {
        elemAux = p_desapilar(pilaAux);
        apariciones[elemAux->clave - valorMin]++;
        p_apilar(pila, elemAux);
    }

    Pila pilaResultados = p_crear();

    //cargar nueva pila con valores y apariciones
    for(int i = 0; i <= rango; i++) {
        if(apariciones[i] > 0) {
            TipoElemento nuevoElem = te_crear(i + valorMin);
            nuevoElem->valor = malloc(sizeof(int));
            //asignar num de apariciones a nuevoElem->valor que es un puntero
            *(int *)(nuevoElem->valor) = apariciones[i];
            p_apilar(pilaResultados, nuevoElem);
        }
    }
    free(apariciones);
    return pilaResultados;
}

void mostrarApariciones(Pila pila){
    Pila pilaAux = p_crear();
    TipoElemento elem;

    //desapilar y mostrar clave con cant de apariciones
    while(!p_es_vacia(pila)){
        elem = p_desapilar(pila);
        printf("%d:%d ", elem->clave, *(int *)(elem->valor));
        p_apilar(pilaAux, elem);
    }

    //volver a apilar
    while(!p_es_vacia(pilaAux)) {
        elem = p_desapilar(pilaAux);
        p_apilar(pila, elem);
    }
}


// La complejidad algorítmica de la funcion cantidadApariciones es de O(n + m):
// La pila se desapila para encontrar el valor maximo y minimo, recorriendo cada elemento
// una vez. Si la pila tiene n elemento, el tiempo que lleva desapilarlos es proporcional
// a n: O(n)
// Pero luego se trabaja con un array que tiene el tamaño del rango de valores de la pila,
// por lo que la complejidad es O(m), donde m es el rango de valores
// Como resultado obtenemos que la complejidad es de O(n + m)
