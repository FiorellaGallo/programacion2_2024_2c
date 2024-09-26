#include <stdio.h>
#include <stdlib.h>
#include "ejercicio2.h"
#include "../TADs/pilas.h"
#include "../TADs/tipo_elemento.h"



void cargar_pila(Pila *pila){

    int num;
    char c;

    printf("INGRESE UN NUMERO PARA INGRESAR EN LA PILA (UNA LETRA PARA SALIR): ");

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


void buscar(Pila *pila, int clave){

    Pila pila_aux = p_crear();
    TipoElemento elemento;
    bool pertenece = false;

    while(!p_es_vacia(*pila)){
        elemento = p_desapilar(*pila);
        if(elemento->clave == clave){
            pertenece= true;
        };
        p_apilar(pila_aux, elemento);
    };

    if(p_es_vacia(*pila)){
        while(!p_es_vacia(pila_aux)){
            elemento = p_desapilar(pila_aux);
            p_apilar(*pila, elemento);
        };
    };

    if(pertenece){
        printf("El número %d pertenece a la pila\n", clave);
    }else{
        printf("El número %d no pertenece a la pila\n", clave);
    };

};

void insertar(Pila *pila, int pos, int elemento_nuevo){

    Pila pila_aux=p_crear();
    TipoElemento elemento;
    int tope = contar(pila);

    if(pos>(tope+1)){
        printf("Esa posicion no existe\n");
        return;
    };

    if(pos == (tope+1)){
        elemento = te_crear(elemento_nuevo);
        p_apilar(*pila, elemento);
        p_mostrar(*pila);
        return;
    };

    while(tope != pos){
        elemento = p_desapilar(*pila);
        p_apilar(pila_aux, elemento);
        tope--;
    };


    elemento = p_desapilar(*pila);
    p_apilar(pila_aux, elemento);

    elemento = te_crear(elemento_nuevo);
    p_apilar(*pila, elemento);

    while(!p_es_vacia(pila_aux)){
        elemento = p_desapilar(pila_aux);
        p_apilar(*pila, elemento);
    };

    p_mostrar(*pila);
}


void eliminar(Pila *pila, int clave){

    Pila pila_aux = p_crear();
    TipoElemento elemento;
    TipoElemento eliminado;

    while(!p_es_vacia(*pila)){
        elemento = p_desapilar(*pila);
        if(elemento->clave != clave){
            p_apilar(pila_aux, elemento);
        }else{
            eliminado = elemento;
        };
    };

    if(p_es_vacia(*pila)){
        while(!p_es_vacia(pila_aux)){
            elemento = p_desapilar(pila_aux);
            p_apilar(*pila, elemento);
        };
    };

    printf("Elemento eliminado: %d\n", eliminado->clave);
    p_mostrar(*pila);
};


int contar(Pila *pila){

    Pila pila_aux = p_crear();
    TipoElemento elemento;
    int contador = 0;

    while(!p_es_vacia(*pila)){
        contador++;
        elemento = p_desapilar(*pila);
        p_apilar(pila_aux, elemento);
    };
    while(!p_es_vacia(pila_aux)){
        elemento = p_desapilar(pila_aux);
        p_apilar(*pila, elemento);
    };
    return contador;

};

void intercambiar(Pila *pila, int pos1, int pos2){

    int tope=contar(pila);

    if(pos1>tope || pos2>tope){
        printf("Esa posicion no existe\n");
        return;
    };

    Pila pila_aux1 = p_crear();
    Pila pila_aux2 = p_crear();

    TipoElemento elemento;
    TipoElemento elemento_intercambio;

//DESAPILANDO PILA PRINCIPAL
    while(tope != pos2){
        elemento = p_desapilar(*pila);
        p_apilar(pila_aux1, elemento);
        tope--;
    };

    elemento = p_desapilar(*pila);
    elemento_intercambio = elemento;
    tope--;

    while(tope != pos1){
        elemento = p_desapilar(*pila);
        p_apilar(pila_aux2, elemento);
        tope--;
    };

    elemento = p_desapilar(*pila);
    p_apilar(pila_aux2, elemento);
    tope--;

//APILANDO PILA PRINCIPAL
    p_apilar(*pila, elemento_intercambio);
    elemento_intercambio = p_desapilar(pila_aux2);


    while(!p_es_vacia(pila_aux2)){
        elemento = p_desapilar(pila_aux2);
        p_apilar(*pila, elemento);
    };

    p_apilar(*pila, elemento_intercambio);

    while(!p_es_vacia(pila_aux1)){
        elemento = p_desapilar(pila_aux1);
        p_apilar(*pila, elemento);
    };

    printf("INTERCAMBIO:\n");
    p_mostrar(*pila);

};


void duplicar(Pila *pila){

    Pila pila2 = p_crear();
    Pila pila_aux = p_crear();
    TipoElemento elemento1;
    TipoElemento elemento2;

    while(!p_es_vacia(*pila)){
        elemento1 = p_desapilar(*pila);
        p_apilar(pila_aux, elemento1);
    };

    while(!p_es_vacia(pila_aux)){
        elemento1 = p_desapilar(pila_aux);
        elemento2 = elemento1;
        p_apilar(*pila, elemento2);
        p_apilar(pila2, elemento1);
    };

    printf("DUPLICACION:\n");
    printf("PILA 1\n");
    p_mostrar(*pila);
    printf("PILA 2\n");
    p_mostrar(pila2);
};


