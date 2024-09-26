#include <stdio.h>
#include <stdlib.h>
#include "../TADs/pilas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio8.h"

Pila cargarPila(Pila pila){
    int d;
    while(!p_es_llena(pila)){
        printf("Ingrese un valor para apilar o -1 para salir: \n");
        while(scanf("%d", &d) != 1) {
            printf("Error. Vuelva a ingresar el numero \n");
            while(getchar() != '\n');
        }
        if(d == -1){
            break;
        }

        TipoElemento elemento = malloc(sizeof(struct TipoElementoRep));
        if (elemento == NULL) {
            printf("Error al asignar memoria\n");
        }
        elemento->clave = d;
        elemento->valor = NULL;
        p_apilar(pila, elemento);
    }
    return pila;
}

int main()
{
    Pila pila = p_crear();
    cargarPila(pila);
    printf("La pila se cargo correctamente \n");
    p_mostrar(pila);

    Pila pilaRes;
    pilaRes = cantidadApariciones(pila);
    printf("Pila de valores y apariciones: \n");
    mostrarApariciones(pilaRes);

    return 0;
}
