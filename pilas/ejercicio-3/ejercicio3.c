#include <stdio.h>
#include <stdlib.h>
#include "ejercicio3.h"
#include "../TADs/pilas.h"
#include "../TADs/tipo_elemento.h"

void cargar_pila(Pila *pila){

    int num;
    char c;

    printf("INGRESE UN NÚMERO PARA CARGAR LA PILA (UNA LETRA PARA SALIR): ");

    while(scanf("%d", &num) == 1){
        TipoElemento elemento = te_crear(num);
        p_apilar(*pila, elemento);
        printf("ELEMENTO: ");
        while ((c = getchar()) != '\n' && c != EOF);
    };

    while ((c = getchar()) != '\n' && c != EOF);
    printf("Pila cargada!\n");
    p_mostrar(*pila);

};

void comparacion(Pila *pila1, Pila *pila2){

    Pila pila_aux = p_crear();
    TipoElemento elemento1;
    TipoElemento elemento2;
    bool dif = false;

    while(!p_es_vacia(*pila1) && !p_es_vacia(*pila2)){

        elemento1 = p_desapilar(*pila1);
        elemento2 = p_desapilar(*pila2);

        if(elemento1->clave != elemento2->clave){
            dif = true;
            printf("Las pilas SON DIFERENTES\n");
            return;
        }else{
            p_apilar(pila_aux,elemento1);
            p_apilar(pila_aux,elemento2);
        };
    };

    while(!p_es_vacia(pila_aux)){

        elemento2 = p_desapilar(pila_aux);
        elemento1 = p_desapilar(pila_aux);
        p_apilar(*pila2, elemento2);
        p_apilar(*pila1, elemento1);
    };

    if(!dif){
        printf("Las pilas SON IGUALES\n");
    };
    p_mostrar(*pila1);
    p_mostrar(*pila2);
};

/*
    La complejidad algoritmica de la funcion comparacion es lineal O(n),
    ya que tanto el primer bloque de la funcion como el segundo tienen una
    complejidad de O(n) porque en ambas partes los ciclos dependen de la cantidad
    de elementos que tengan las pilas.
*/
