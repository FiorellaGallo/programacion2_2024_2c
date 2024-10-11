#include <stdlib.h>
#include <stdio.h>
#include "../TADs/tipo_elemento.h"
#include "../TADs/colas.h"
#include "ejercicio3.h"

void cargar_cola(Cola *cola){

    char c;
    int num;
    printf("ingrese numero o letra para finalizar: ");

    while(scanf("%d",&num) == 1){
        TipoElemento elemento = te_crear(num);
        c_encolar(*cola, elemento);
         printf("ingrese numero o letra para finalizar: ");
         while ((c = getchar()) != '\n' && c != EOF);
    }

    while ((c = getchar()) != '\n' && c != EOF);
    printf("COLA CARGADA\n");
    c_mostrar(*cola);

}

void recargar_colas(Cola *cola1, Cola *cola2, Cola cola_aux){

    TipoElemento elemento;

    if(!c_es_vacia(cola_aux)){

        elemento = c_desencolar(cola_aux);
        c_encolar(*cola1, elemento);

        elemento = c_desencolar(cola_aux);
        c_encolar(*cola2, elemento);

        recargar_colas(cola1,cola2,cola_aux);
    }

}

void comparacion(Cola *cola1, Cola *cola2){

    printf("COMPARANDO LAS COLAS....\n\n\n");
    Cola cola_aux=c_crear();
    TipoElemento ele1;
    TipoElemento ele2;


    while(!c_es_vacia(*cola1) && !c_es_vacia(*cola2)){
        ele1 = c_recuperar(*cola1);
        ele2 = c_recuperar(*cola2);

        if(ele1->clave != ele2->clave){

            printf("---------LAS COLAS SON DIFERENTES---------\n");

            while(!c_es_vacia(*cola1) && !c_es_vacia(*cola2)){
                ele1 = c_desencolar(*cola1);
                ele2 = c_desencolar(*cola2);
                c_encolar(cola_aux, ele1);
                c_encolar(cola_aux, ele2);
            }

            recargar_colas(cola1, cola2, cola_aux);
            return;
        }

        ele1 = c_desencolar(*cola1);
        ele2 = c_desencolar(*cola2);
        c_encolar(cola_aux, ele1);
        c_encolar(cola_aux, ele2);
    }

    printf("---------AMBAS COLAS TIENEN MISMO CONTENIDO---------\n");
    recargar_colas(cola1,cola2,cola_aux);

}

// La complejidad algoritmica es de orden lineal O(n) ya que
// el tiempo que tarde la ejecucion va a depender de la cantidad
// de elementos de la cola que tenga que procesar.
