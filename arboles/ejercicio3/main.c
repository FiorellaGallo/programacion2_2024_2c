#include <stdio.h>
#include <stdlib.h>
#include "ejercicio3.h"
#include "../TADs/arbol-binario.h"
#include "../TADs/listas.h"

int main(){
    int clave, nivel,altura,repetir = 1;
    ArbolBinario A;
    A = a_crear();
    printf("--------CARGA DE ÁRBOL BINARIO---------\n");
    carga_arbol_binario(A);
    pre_orden(a_raiz(A));


    while(repetir){
        printf("\n\nIngrese el valor del nodo seleccionado para ejecutar el programa: ");
        scanf("%i", &clave);
        printf("-----------------------------------------------------\n");
        printf("NODO SELECCIONADO: %i\n",clave);
        printf("-----------------------------------------------------\n");
        busqueda_padre(A, clave);
        printf("-----------------------------------------------------\n");
        lista_hijos(clave, A);
        printf("-----------------------------------------------------\n");
        hermano(A, clave);
        printf("-----------------------------------------------------\n");
        nivel = nivel_nodo (A, clave);
        printf("Se encuentra en el nivel : %i\n",nivel);
        printf("-----------------------------------------------------\n");
        altura= a_altura(A,clave);
        printf("La altura del subarbol es : %i\n",altura);
        printf("-----------------------------------------------------\n");
        nodos_a_buscar(A, nivel);
        printf("-----------------------------------------------------\n");
        printf("¿Desea ejecutar nuevamente? (1: Sí, 0: No): ");
        scanf("%d", &repetir);
        while (repetir != 1 && repetir != 0) {
            printf("Entrada no válida. Por favor ingresa 1 para Sí o 0 para No: ");
            scanf("%d", &repetir);
        }
    }
    return 0;
}
