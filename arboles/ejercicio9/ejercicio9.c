#include <stdio.h>
#include <stdlib.h>
#include "../TADs/arbol-binario.h"
#include "../TADs/nodo.h"
#include "ejercicio9.h"
#include "../TADs/tipo_elemento.h"
#include "../TADs/arbol-avl.h"


void mostrar_pre_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        x = n_recuperar(N);
        printf(" %d", x->clave);
        //x->clave= x->clave * 2;//borrar
        mostrar_pre_orden(n_hijoizquierdo(N));
        mostrar_pre_orden(n_hijoderecho(N));
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

void Cargar_SubArbol(ArbolBinario A, NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if(!a_es_lleno(A)){
        b= ingresoEntero(&n);
        if (b){
            X= te_crear(n);

            if(sa == -1) N1 = a_conectar_hi(A, N, X);
            else if(sa == 1) N1 = a_conectar_hd(A, N, X);
            else N1 = a_establecer_raiz(A, X);

            Cargar_SubArbol(A, N1, -1);
            Cargar_SubArbol(A, N1, 1);
        }
    }
}


void cargar_arbol(ArbolBinario A){
    Cargar_SubArbol(A, NULL, 0);
}




void agregar_a_avl(ArbolAVL a_avl, NodoArbol nodo){

    if(nodo == NULL){
        return;
    }

    avl_insertar(a_avl, nodo->datos);
    agregar_a_avl(a_avl, n_hijoizquierdo(nodo));
    agregar_a_avl(a_avl, n_hijoderecho(nodo));

}

ArbolAVL pasar_a_avl(ArbolBinario A){

    ArbolAVL a_avl = avl_crear();
    NodoArbol raiz = a_raiz(A);

    agregar_a_avl(a_avl, raiz);

    return a_avl;
}

// complejidad algoritmica: es de orden lineal porque el tiempo de ejecucion va a
// depender del tamaño del arbol, mientras mas elementos del árbol mas va a tardar el procesamiento
