#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include "../TADs/arbol-binario.h"
#include "../TADs/listas.h"
#include "../TADs/nodo.h"
#include "ejercicio2.h"
#include "../TADs/tipo_elemento.h"

void mostrar_pre_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        x = n_recuperar(N);
        printf(" %d", x->clave);
        mostrar_pre_orden(n_hijoizquierdo(N));
        mostrar_pre_orden(n_hijoderecho(N));
    }
}

//     CARGAR ARBOL
bool ingresoEntero(int *n){
    char s[10];
    bool resultado = true;
    *n=0;
    printf("Ingrese un numero o '.'(un punto) para nulo: \n");
    scanf("%s",s);
    if (s[0] == '.'){
        resultado = false;
    }else{
        for (int i = 0; s[i] != '\0'; i++){
            if((s[i] >= '0') && (s[i] <= '9')){
                *n = *n * 10 + (s[i] - 48);
            }
        }
    }
    return resultado;
}


void cargar_subArbol(ArbolBinario A,NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol n1;
    int n;
    bool b;
    if(!a_es_lleno(A)){
        b = ingresoEntero(&n);
        if(b){
            X = te_crear(n);
            if(sa == -1) n1 = a_conectar_hi(A, N, X);
            else if (sa == 1) n1 = a_conectar_hd(A, N, X);
            else n1 = a_establecer_raiz(A, X);

            cargar_subArbol(A, n1, -1);
            cargar_subArbol(A, n1, 1);
        }
    }
}

void cargar_arbol(ArbolBinario A){
    cargar_subArbol(A, NULL, 0);
}


//    BUSCAR HOJAS
Lista guardar_hojas(ArbolBinario A){

    Lista hojas = l_crear();
    NodoArbol raiz = a_raiz(A);

    buscar_hojas(raiz, &hojas);

    return hojas;
}

void buscar_hojas(NodoArbol nodo, Lista *hojas){

    NodoArbol hijo_d = n_hijoderecho(nodo);
    NodoArbol hijo_i = n_hijoizquierdo(nodo);

    bool rama_nula_d = a_es_rama_nula(hijo_d);
    bool rama_nula__i = a_es_rama_nula(hijo_i);

    if(rama_nula_d && rama_nula__i){
        l_agregar(*hojas, nodo->datos);
    }
    if(!rama_nula__i){
        buscar_hojas(hijo_i, hojas);
    }
    if(!rama_nula_d){
        buscar_hojas(hijo_d, hojas);
    }

}


//  BUSCAR NODOS INTERIORES
Lista guardar_nodos_interiores(ArbolBinario A){

    Lista interiores = l_crear();
    NodoArbol raiz = a_raiz(A);

    NodoArbol hijo_d = n_hijoderecho(raiz);
    NodoArbol hijo_i = n_hijoizquierdo(raiz);

    buscar_nodos_interiores(hijo_i, &interiores);
    buscar_nodos_interiores(hijo_d, &interiores);

    return interiores;
}

void buscar_nodos_interiores(NodoArbol nodo, Lista *interiores){

    NodoArbol hijo_d = n_hijoderecho(nodo);
    NodoArbol hijo_i = n_hijoizquierdo(nodo);

    bool rama_nula_d = a_es_rama_nula(hijo_d);
    bool rama_nula_i = a_es_rama_nula(hijo_i);

    if(!rama_nula_i || !rama_nula_d){
        l_agregar(*interiores, nodo->datos);

        if(!rama_nula_i){
            buscar_nodos_interiores(hijo_i, interiores);
        }
        if(!rama_nula_d){
            buscar_nodos_interiores(hijo_d, interiores);
        }
    }

}

//    BUSCAR OCURRENCIAS DE UNA CLAVE INGRESADA POR TECLADO
Lista guardar_ocurrencias(ArbolBinario A){

    Lista ocurrencias = l_crear();

    NodoArbol raiz = a_raiz(A);
    int clave;
    printf("INGRESE LA CLAVE A BUSCAR: ");
    scanf("%d", &clave);

    buscar_clave(&raiz, &ocurrencias, clave);

    return ocurrencias;
}

void buscar_clave(NodoArbol *nodo,Lista *ocurrencias, int clave){

    if((*nodo)->datos->clave == clave){
        uintptr_t posicion = (uintptr_t)*nodo;
        l_agregar(*ocurrencias, te_crear(posicion));
    }

    NodoArbol hijo_d = n_hijoderecho(*nodo);
    NodoArbol hijo_i = n_hijoizquierdo(*nodo);

    bool rama_nula_d = a_es_rama_nula(hijo_d);
    bool rama_nula_i = a_es_rama_nula(hijo_i);

    if(!rama_nula_d)buscar_clave(&hijo_d, ocurrencias, clave);
    if(!rama_nula_i)buscar_clave(&hijo_i, ocurrencias, clave);

}

// COMPLEJIDAD ALGORITMICA
// punto 2-a: es de orden lineal 0(n)
// punto 2-b: es de orden lineal 0(n)
// punto 2-c: es de orden lineal 0(n)







