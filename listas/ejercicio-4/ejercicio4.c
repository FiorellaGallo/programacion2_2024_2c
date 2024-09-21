#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../TADs/listas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio4.h"

void comparacion(Lista Lista1, Lista Lista2){
    int mayor_lista1 = 0, mayor_lista2 = 0;

    if(l_longitud(Lista1) < l_longitud(Lista2)){
        for(int i = l_longitud(Lista2); l_longitud(Lista2) > l_longitud(Lista1); i--){
            l_eliminar(Lista2, i);
        }
    } else if(l_longitud(Lista1) > l_longitud(Lista2)){
        for(int i = l_longitud(Lista1); l_longitud(Lista1) > l_longitud(Lista2); i--){
            l_eliminar(Lista1, i);
        }
    }

    printf("\n\nSe ajustan las listas para obtener la misma longitud.\n\n");
    l_mostrar(Lista1);
    l_mostrar(Lista2);

    Iterador iter1 = iterador(Lista1);
    Iterador iter2 = iterador(Lista2);
    while(hay_siguiente(iter1)){
        TipoElemento x = siguiente(iter1);
        TipoElemento y = siguiente(iter2);
        if(x->clave > y->clave){
            mayor_lista1++;
        } else if (x->clave < y->clave){
            mayor_lista2++;
        }
    }

    if(mayor_lista1 > mayor_lista2){
        printf("\nRESULTADO: La Lista1 es mayor que la Lista2.\n");
    } else if(mayor_lista1 < mayor_lista2){
        printf("\nRESULTADO: La Lista1 es menor que la Lista2.\n");
    } else {
        printf("\nRESULTADO: Las listas son iguales.\n");
    }
}

// La complejidad algorítmica de la función "comparacion" es de orden lineal
// ya que, al tratarse de iteración de listas, el tiempo empleado para la
// solución del problema crece a medida que las listas son más extensas,
// es decir, que a mayor tamaño de la lista, mayor n.



