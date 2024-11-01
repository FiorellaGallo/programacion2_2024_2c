#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "ejercicio3.h"
#include "../TADs/arbol-binario.h"
#include "../TADs/tipo_elemento.h"
#include "../TADs/nodo.h"
#include "../TADs/listas.h"

void pre_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        x = n_recuperar(N);
        printf(" %d", x->clave);
        //x->clave= x->clave * 2;//borrar
        pre_orden(n_hijoizquierdo(N));
        pre_orden(n_hijoderecho(N));
    }
}

bool ingresoEntero(int* n){
    char s[10];
    bool resultado = true;
    *n=0;
    printf("Ingrese una clave numérica o '.' para nulo: ");
    scanf("%s", s);
    if (s[0]=='.'){
        resultado = false;
    }else{
        for (int i = 0; s[i] != '\0'; i++) {
            if ((s[i]>='0')&&(s[i]<='9')){
                *n = *n * 10 + (s[i] - 48);}
        }
    }

    return resultado;
}

void Carga_SubArbol(ArbolBinario A, NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;

    if(!a_es_lleno(A)){
        b = ingresoEntero(&n);
        if(b){
            X = te_crear(n);

            if(sa == -1) N1 = a_conectar_hi(A,N,X);
            else if(sa == 1) N1 = a_conectar_hd(A,N,X);
            else N1 = a_establecer_raiz(A,X);

            Carga_SubArbol(A,N1,-1);
            Carga_SubArbol(A,N1,1);
        }

    }
}

void carga_arbol_binario(ArbolBinario A){
    Carga_SubArbol(A,NULL,0);
}

NodoArbol busqueda(NodoArbol N, int clave){
    if (N == NULL) return NULL;

    NodoArbol hi = n_hijoizquierdo(N);
    NodoArbol hd = n_hijoderecho(N);

    if (hi!= NULL && hi->datos->clave == clave){
        return N;
    }
    if (hd!= NULL && hd->datos->clave == clave){
        return N;
    }
    NodoArbol resultado_hi = busqueda(hi, clave);
    if (resultado_hi != NULL) return resultado_hi;

    NodoArbol resultado_hd = busqueda(hd, clave);
    if (resultado_hd != NULL) return resultado_hd;


    return NULL;
}

void busqueda_padre(ArbolBinario A, int clave){
    NodoArbol raiz = a_raiz(A);

    if (raiz == NULL || raiz->datos->clave == clave) {
        printf("El nodo es la raíz\n");
    }else{
        NodoArbol N = busqueda(raiz,clave);
        printf("El padre es : %d\n",N->datos->clave);

    }
}

void lista_hijos(int clave, ArbolBinario A){
    NodoArbol raiz = a_raiz(A);
    if (recuperar_hijos(raiz, clave) == 0) {
        printf("Clave %i no encontrada en el árbol.\n", clave);
    }
}

int recuperar_hijos(NodoArbol N, int clave){
    if(N == NULL) return 0;
    if(N->datos->clave == clave){
        NodoArbol hi = n_hijoizquierdo(N);
        NodoArbol hd = n_hijoderecho(N);
        if(hi != NULL)
            printf("Hijo izquierdo : %i\n", hi->datos->clave);
        else
            printf("No hay hijo izquierdo.\n");

        if(hd != NULL)
            printf("Hijo derecho : %i\n", hd->datos->clave);
        else
            printf("No hay hijo derecho.\n");
        return 1;
    }
    if (recuperar_hijos(n_hijoizquierdo(N), clave)) return 1;
    return recuperar_hijos(n_hijoderecho(N), clave);
}

void hermano(ArbolBinario A, int clave){
    NodoArbol raiz = a_raiz(A);
    if( raiz->datos->clave == clave){
        printf("El nodo no tiene hermano\n");
    }
    recuperar_hermano(raiz,clave);
}

int recuperar_hermano(NodoArbol N, int clave){

    if (N == NULL) return 0;

    NodoArbol hi = n_hijoizquierdo(N);
    NodoArbol hd = n_hijoderecho(N);

     if (hi != NULL && hi->datos->clave == clave) {
        if (hd != NULL) {
            printf("El hermano es : %i\n", hd->datos->clave);
        } else {
            printf("No tiene hermano\n");
        }
        return;
    }

    if (hd != NULL && hd->datos->clave == clave) {
        if (hi != NULL) {
            printf("El hermano es : %i\n", hi->datos->clave);
        } else {
            printf("No tiene hermano\n");
        }
        return;
    }

    recuperar_hermano(hi,clave);
    recuperar_hermano(hd,clave);
}

int nivel_nodo(ArbolBinario A, int clave){
    int nivel = -1;
    nivelint(a_raiz(A), clave, &nivel, 0);
    return nivel;
}

void nivelint(NodoArbol Q, int Cbuscada, int *h, int c){
    TipoElemento X;
    if (Q != NULL) {
        X= n_recuperar(Q);
        if (X->clave == Cbuscada) {
            *h = c;
        }else{
            nivelint(n_hijoizquierdo(Q), Cbuscada, h, c+1);
            nivelint(n_hijoderecho(Q), Cbuscada, h, c+1);
        }
    }
}

NodoArbol busqueda_nodo(ArbolBinario A, NodoArbol N, int clave) {
    if (N == NULL) return NULL;
    if (N->datos->clave == clave) {
        return N;
    }
    NodoArbol resultado = busqueda_nodo(A, n_hijoizquierdo(N), clave);
    if (resultado == NULL) {
        resultado = busqueda_nodo(A, n_hijoderecho(N), clave);
    }
    return resultado;
}

int a_altura(ArbolBinario A, int clave){
    int altura=0;
    NodoArbol nodo = busqueda_nodo(A,a_raiz(A),clave);

     if (nodo == NULL) {
        printf("La clave %d no se encuentra en el árbol.\n", clave);
        return -1;
    }

    alturaSub(nodo,&altura,0);
    return altura;
}

void alturaSub(NodoArbol N, int *altura, int cantidad){
    if(N==NULL){
        if(cantidad>*altura){
            *altura=cantidad;}
    }else{
            alturaSub(n_hijoizquierdo(N),altura,cantidad+1);
            alturaSub(n_hijoderecho(N),altura,cantidad+1);
        }


}

void nodos_a_buscar(ArbolBinario A, int nivel_buscado){
    Lista* L;
    L = l_crear();
    busqueda_nivel(a_raiz(A), nivel_buscado, L,0);
    printf("En el nivel %i se encuentran los siguientes valores\n",nivel_buscado);
    l_mostrar(L);
}

void busqueda_nivel(NodoArbol N, int nivel_buscado,Lista* L, int nivel_actual){

    NodoArbol hi = n_hijoizquierdo(N);
    NodoArbol hd = n_hijoderecho(N);

    if(N == NULL) return ;

    if (nivel_actual == nivel_buscado) {
        l_agregar(L, N->datos);

    }else{

        busqueda_nivel(hi, nivel_buscado,L, nivel_actual + 1);
        busqueda_nivel(hd, nivel_buscado,L, nivel_actual + 1);
    }
}
