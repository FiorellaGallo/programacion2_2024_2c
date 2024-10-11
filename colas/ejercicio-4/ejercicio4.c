#include <stdlib.h>
#include <stdio.h>
#include "../TADs/tipo_elemento.h"
#include "../TADs/colas.h"
#include "ejercicio4.h"
#include "../TADs/listas.h"

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

void pasar_a_lista(Cola *cola, Lista *lista){

    TipoElemento ele;
    while(!c_es_vacia(*cola)){

        ele = c_desencolar(*cola);
        l_agregar(*lista, ele);
    }
}

Cola no_repetidos(Cola *cola){

    Lista lista = l_crear();
    Cola ele_no_repetidos = c_crear();
    Iterador iter1 = iterador(lista);
    Iterador iter2 = iterador(lista);
    TipoElemento ele;
    TipoElemento ele_buscar;
    TipoElemento buscador;

    pasar_a_lista(cola,&lista);

    int contador = 0;

    while(hay_siguiente(iter1)){
        ele_buscar = siguiente(iter1);

        while(hay_siguiente(iter2)){
            buscador = siguiente(iter2);
            if(ele_buscar->clave == buscador->clave){
                contador+=1;
            }
        }

        if(contador == 1){
            ele = l_recuperar(lista, ele_buscar->clave);
            c_encolar(ele_no_repetidos, ele);
        }

        iter2 = iterador(lista);
        contador=0;
    }

    iter1=iterador(lista);

     while(hay_siguiente(iter1)){
        ele_buscar = siguiente(iter1);
        ele = l_buscar(lista, ele_buscar->clave);
        c_encolar(*cola, ele);

    }

    return ele_no_repetidos;

}

//La complejidad algoritmica es de orden cuadratico,
//ya que por cada iteracion sobre la lista se multiplican
//los procesos haciendo cada vez mas costoso el tiempo de ejecucion
