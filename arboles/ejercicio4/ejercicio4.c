#include <stdio.h>
#include <stdlib.h>
#include "ejercicio4.h"
#include "../TADs/arbol-binario.h"
#include "../TADs/listas.h"
#include  "../TADs/nodo.h"
#include  "../TADs/colas.h"


void pre_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        x = n_recuperar(N);
        printf(" %d", x->clave);
        pre_orden(n_hijoizquierdo(N));
        pre_orden(n_hijoderecho(N));
    }
}

void cargar_arbol_n_ario(ArbolBinario A){
    TipoElemento X ;
    int clave;
    char c;
    printf("Ingrese la clave del nodo raíz: ");
    while(1){
        if(scanf("%d", &clave) == 1){
            X = te_crear(clave);
            NodoArbol nodo = a_establecer_raiz(A, X);
            cargar_hijos(A,nodo);
            break;
        }else{
            scanf("%c",&c);
            if(c == '*'){
                break;
            }else{
                printf("Entrada no válida\n");
                printf("Se permiten solo números.Intente nuevamente:\n");
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }

    }
}

void cargar_hijos(ArbolBinario A, NodoArbol N){
    char entrada[10];
    int hijos ;
    printf("--------------------------------------------------------------\n");
    printf("¿Cuántos hijos tiene el nodo con clave %d (Si no tiene ingresar 0)? ", N->datos->clave);
    scanf("%d", &hijos);

    NodoArbol ultimo_nodo = NULL;

    for (int i = 0; i < hijos; i++) {
        int clave_hijo;
        TipoElemento hijo;
        printf("--------------------------------------------------------------\n");
        printf("Ingrese la clave del hijo %d (o '.' si no tiene hijo): ", i + 1);
        scanf("%s", &entrada);

        if (strcmp(entrada, ".") == 0) {
            continue;
        }
        clave_hijo= 0;
         for (int j = 0; entrada[j] != '\0'; j++) {
            if (entrada[j] < '0' || entrada[j] > '9') {
                printf("Entrada inválida, por favor ingrese un número.\n");
                i--; // Reintentar el mismo hijo
                continue;
            }
            clave_hijo = clave_hijo * 10 + (entrada[j] - '0');
        }

        hijo = te_crear(clave_hijo);

         NodoArbol nuevo_hijo;
        if (ultimo_nodo == NULL) {
            // Primer hijo va a la izquierda
            nuevo_hijo = a_conectar_hi(A, N, hijo);
        } else {
            // Conectar el nuevo hijo como hermano derecho del último hijo
            nuevo_hijo = a_conectar_hd(A, ultimo_nodo, hijo);
        }

        // Actualizar el último nodo
        ultimo_nodo = nuevo_hijo;

        // Llamar recursivamente para cargar los hijos del nuevo hijo
         cargar_hijos(A, nuevo_hijo);
    }


}

void anchura(ArbolBinario A){
    Lista* L;
    NodoArbol N;
    TipoElemento X;

    if (!a_es_vacio(A)){
        L = l_crear();
        N = a_raiz(A);

        X = te_crear_con_valor(0, N);
        l_agregar(L, X);

        while (!l_es_vacia(L)){
            X = l_recuperar(L,1);
            N = (NodoArbol) X->valor;
            l_eliminar(L, 1);
            printf(" %d ", n_recuperar(N)->clave);

            NodoArbol hijo = n_hijoizquierdo(N);
            if (hijo) {
                X = te_crear_con_valor(0, hijo);
                 l_agregar(L, X);

                NodoArbol hermano = n_hijoderecho(hijo);
                while (hermano) {
                    X = te_crear_con_valor(0, hermano);
                    l_agregar(L, X);
                    hermano = n_hijoderecho(hermano);
                }
            }
        }
    }
}

int cantidad_hojas(ArbolBinario A){
    int contador = 0;
    if (!a_es_vacio(A)) {
        NodoArbol N = a_raiz(A);
        incrementa_contador(N, &contador);
    }
    return contador;
}

void incrementa_contador(NodoArbol N, int *contador){
     if (N == NULL) {
        return;
    }
    if (n_hijoizquierdo(N) == NULL) {
        (*contador)++;
    }
    incrementa_contador(n_hijoizquierdo(N),contador);
    incrementa_contador(n_hijoderecho(N),contador);
}

bool recursividad(NodoArbol Nb, NodoArbol Nc){
    if (Nb == NULL && Nc == NULL) {
        return true;
    }

    if ((Nb == NULL && Nc != NULL) || (Nb != NULL && Nc == NULL)) {
        return false;
    }
    NodoArbol hi_B = n_hijoizquierdo(Nb);
    NodoArbol hd_B = n_hijoderecho(Nb);
    NodoArbol hi_C = n_hijoizquierdo(Nc);
    NodoArbol hd_C = n_hijoderecho(Nc);

    if ((hi_B != NULL && hi_C == NULL )|| (hi_B == NULL && hi_C != NULL )){
        return false;

    }
    if ((hd_B != NULL && hd_C == NULL )|| (hd_B == NULL && hd_C != NULL )){
        return false;
    }
     return recursividad(hi_B, hi_C) && recursividad(hd_B, hd_C);
}

bool comparar(ArbolBinario B, ArbolBinario C){

    if (!a_es_vacio(B) && !a_es_vacio(C)) {
        NodoArbol Nb = a_raiz(B);
        NodoArbol Nc = a_raiz(C);

        if (!recursividad(Nb, Nc)) {
            printf("FALSO\n");
            return false;
        }
    }
    printf("TRUE\n");
    return true;

}

int busqueda(NodoArbol N, int clave, int padre) {
    if (N == NULL) {
        return -1;
    }

    if (N->datos->clave == clave) {
        return padre;
    }

    int resultado_hi = busqueda(n_hijoizquierdo(N), clave, N->datos->clave);
    if (resultado_hi != -1) {
        return resultado_hi;
    }

    return busqueda(n_hijoderecho(N), clave, padre);
}

void busqueda_padre(ArbolBinario A, int clave) {
    NodoArbol raiz = a_raiz(A);

    if (raiz == NULL || raiz->datos->clave == clave) {
        printf("El nodo no tiene padre o el árbol está vacío.\n");
        return;
    }

    int padre = busqueda(raiz, clave, -1);

    if (padre != -1) {
        printf("El padre es: %d\n", padre);
    } else {
        printf("Nodo no encontrado en el árbol.\n");
    }
}

Lista hermanos(ArbolBinario A, int clave){
    Lista* L;
    Lista* hermanos;
    NodoArbol N;
    TipoElemento X;

    if (!a_es_vacio(A)){
        L = l_crear();
        hermanos = l_crear();
        N = a_raiz(A);

        X = n_recuperar(N);

        if (X->clave == clave){
            printf("El nodo ingresado no tiene hermanos. Es la raíz\n");
            return NULL;
        }

        X = te_crear_con_valor(0, N);
        l_agregar(L, X);
        bool encontro = false;

        while (!l_es_vacia(L) && !encontro){
            X = l_recuperar(L,1);
            N = (NodoArbol) X->valor;
            l_eliminar(L, 1);

            NodoArbol hijo = n_hijoizquierdo(N);
            if (hijo) {
                 X = te_crear_con_valor(0, hijo);
                 l_agregar(L, X);
                 TipoElemento X2 = n_recuperar(hijo);
                 if(clave != X2->clave){
                    l_agregar(hermanos,X2);
                 }else{
                    encontro = true;
                 }

                NodoArbol hermano = n_hijoderecho(hijo);
                while (hermano) {
                    X = te_crear_con_valor(0, hermano);
                    l_agregar(L, X);
                    X2 = n_recuperar(hermano);
                    if(clave != X2->clave){
                     l_agregar(hermanos,X2);
                    }else{
                        encontro = true;
                    }
                    hermano = n_hijoderecho(hermano);
                }

               if(encontro){
                    l_mostrar(hermanos);
               }else{
                     while(!l_es_vacia(hermanos)){
                        l_eliminar(hermanos,1);
                     }
               }

            }
        }

        if(encontro){
            if (l_longitud(hermanos) == 0) {
                printf("El nodo selecionado no tiene hermanos\n");
                return NULL;
            }

            return hermanos;
        }
        printf("La clave  no se encontró\n");
        return NULL;
    }
}










