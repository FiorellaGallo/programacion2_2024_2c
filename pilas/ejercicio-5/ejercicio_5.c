#include <stdio.h>
#include <stdlib.h>
#include "../TADs/pilas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio_5.h"

void carga (Pila* P1){
    int num;
    char c;

    while(1){
        if(scanf("%d",&num) == 1){
            TipoElemento X = te_crear(num);
            p_apilar(P1, X);
        }else{
            scanf("%c",&c);
            if(c == '*'){
                break;
            }else{
                printf("Entrada no válida.Solo se permiten números.Intente nuevamente:\n");
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }
    }
}

void invertir(Pila* P1){
    Pila *copia = p_crear();
    Pila *auxiliar= p_crear();
    printf("Pila ingresada.");
     p_mostrar(P1);

    while(!p_es_vacia(P1)){
        TipoElemento X = p_desapilar(P1);
        p_apilar(auxiliar,X);

    }

    while(!p_es_vacia(auxiliar)){
        TipoElemento X = p_desapilar(auxiliar);
        p_apilar(P1,X);
        p_apilar(copia,X);
    }

    while(!p_es_vacia(copia)){
        TipoElemento X = p_desapilar(copia);
        p_apilar(auxiliar,X);

    }

    free(copia);
    printf("\nPila original.");
    p_mostrar(P1);
    printf("\nPila invertida.");
    p_mostrar(auxiliar);
}


                        /*COMPLEJIDAD ALGORITMICA*/
/*La complejidad que presenta la siguiente resolución es de Orden lineal O(N).
El crecimiento de las operaciones es lineal respecto del número de elementos en la pila.
Todas las operaciones claves(apilar,desapilar,mostrar)son O(1),pero se repiten n veces,
lo que da como resultado un comportamiento lineal en relación al tamaño de la pila.*/
