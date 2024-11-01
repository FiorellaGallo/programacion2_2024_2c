#include <stdio.h>
#include <stdlib.h>
#include "../TADs/arbol-binario.h"
#include "../TADs/nodo.h"
#include "ejercicio2.h"
#include "../TADs/tipo_elemento.h"

int main()
{

    printf("---- CARGA DE ARBOL ----\n");

    ArbolBinario A = a_crear();
    cargar_arbol(A);


    Lista hojas = guardar_hojas(A);
    printf("---------LISTA DE HOJAS DEL ARBOL---------\n");
    l_mostrar(hojas);


    Lista interiores = guardar_nodos_interiores(A);
    printf("---------LISTA DE NODOS INTERIORES DEL ARBOL---------\n");
    l_mostrar(interiores);

    Lista ocurrencias = guardar_ocurrencias(A);
    printf("---------POSICION EN MEMORIA DE OCURRENCIAS DE LA CLAVE ---------\n");
    l_mostrar(ocurrencias);

    return 0;
}
