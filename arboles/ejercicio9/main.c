#include <stdio.h>
#include <stdlib.h>
#include "../TADs/arbol-binario.h"
#include "ejercicio9.h"
#include "../TADs/arbol-avl.h"

int main()
{
    printf("---- CARGA DE ARBOL ----\n");

    ArbolBinario A = a_crear();
    cargar_arbol(A);
    NodoArbol raiz = a_raiz(A);
    printf("ARBOL BINARIO\n");
    mostrar_pre_orden(raiz);

    ArbolAVL a_avl = pasar_a_avl(A);
    printf("\n ARBOL AVL\n");
    mostrar_pre_orden(a_avl->raiz);



    return 0;
}
