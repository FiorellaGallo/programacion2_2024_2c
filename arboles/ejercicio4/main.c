#include <stdio.h>
#include <stdlib.h>
#include "ejercicio4.h"
#include "../TADs/arbol-binario.h"
#include "../TADs/listas.h"

int main(){
    int resultado, clave;
    ArbolBinario A;
    ArbolBinario B;
    ArbolBinario C;
    A = a_crear();
    B = a_crear();
    C = a_crear();
    cargar_arbol_n_ario(A);
    printf("-------------------------------------------------------\n");
    printf("Árbol n-ario pasado a árbol binario:\n");
    pre_orden(a_raiz(A));
    printf("\n-------------------------------------------------------\n");
    printf("La anchura del árbol n-ario es: ");
    anchura(A);
    printf("\n-------------------------------------------------------\n");
    resultado = cantidad_hojas(A);
    printf("Cantidad de hojas del árbol n-ario: %i",resultado);
    printf("\n-------------------------------------------------------\n");
    printf("\n----------------COMPARAR ARBOLES GENERALES--------------\n");
    printf("\nCarga del primer árbol : \n\n");
    cargar_arbol_n_ario(B);
    printf("\nCarga del segundo árbol : \n\n");
    cargar_arbol_n_ario(C);
    printf("-------------------------------------------------------\n");
    printf("Primer árbol cargado:\n");
    pre_orden(a_raiz(B));
    printf("\nSegundo árbol cargado:\n");
    pre_orden(a_raiz(C));
    printf("\n¿Tienen la misma estructura?: \n");
    comparar(B,C);
    printf("-------------------------------------------------------\n");
    printf("BUSQUEDA DEL PADRE Y LOS HIJOS DEL ÁRBOL INICIAL");
    printf("\n\nIngrese el valor del nodo seleccionado para buscar su padre y a los hermanos: ");
    scanf("%i", &clave);
    printf("-----------------------------------------------------\n");
    printf("NODO SELECCIONADO: %i\n",clave);
    printf("-----------------------------------------------------\n");
    busqueda_padre(A, clave);
    printf("-----------------------------------------------------\n");
    printf("Hermanos de la clave seleccionada: \n");
    hermanos(A, clave);
    printf("-----------------------------------------------------\n");




    return 0;
}
