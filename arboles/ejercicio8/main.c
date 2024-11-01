#include <stdio.h>
#include <stdlib.h>
#include "../TADs/nodo.h"
#include "ejercicio8.h"

int leerEntero() {
    int numero;
    while (true) {
        printf("Ingrese un numero: ");
        if (scanf("%d", &numero) == 1) {
            while (getchar() != '\n');
            return numero;
        } else {
            printf("Entrada invalida. Por favor, ingrese un numero.\n");
            while (getchar() != '\n');
        }
    }
}

NodoArbol buscarNodo(NodoArbol raiz, int clave){
    if (raiz == NULL) return NULL;
    if (raiz->datos->clave == clave) return raiz;

    NodoArbol encontrado = buscarNodo(raiz->hi, clave);
    if (encontrado != NULL) return encontrado;

    return buscarNodo(raiz->hd, clave);
}

void agregarHijo(NodoArbol padre, NodoArbol hijo){
        if (n_hijoizquierdo(padre) == NULL) {
        padre->hi = hijo;
    } else if (n_hijoderecho(padre) == NULL) {
        padre->hd = hijo;
    }
}

bool nodoExiste(NodoArbol nodo, int clave) {
    return buscarNodo(nodo, clave) != NULL;
}


void cargarArbol(NodoArbol raiz){
   int clavePadre, claveHijo;
    NodoArbol nodoPadre, nodoHijo;

    while (1) {
        printf("Ingrese la clave del nodo padre o -1 para salir: ");
        clavePadre = leerEntero();

        if (clavePadre == -1) break;

        nodoPadre = buscarNodo(raiz, clavePadre);

        if (nodoPadre == NULL) {
            printf("Nodo de clave %d no encontrado. Creando nuevo nodo padre.\n", clavePadre);
            TipoElemento nuevoPadre = te_crear(clavePadre);
            nodoPadre = n_crear(nuevoPadre);
            agregarHijo(raiz, nodoPadre);
        }

        printf("Ingrese la clave del hijo a agregar o -1 para salir: ");
        claveHijo = leerEntero();

        if (claveHijo == -1) break;

        if (nodoExiste(raiz, claveHijo)) {
            printf("El nodo con clave %d ya existe. No se puede agregar.\n", claveHijo);
            continue;
        }

        TipoElemento te = te_crear(claveHijo);
        nodoHijo = n_crear(te);
        agregarHijo(nodoPadre, nodoHijo);
    }
}



int main()
{
    int claveRaiz;

    printf("Ingrese la clave de la raiz del arbol: \n");
    claveRaiz = leerEntero();

    TipoElemento te_raiz = te_crear(claveRaiz);
    NodoArbol raiz = n_crear(te_raiz);

    cargarArbol(raiz);

    int altura = alturaArbol(raiz);
    printf("Altura del arbol: %d\n", altura);


    printf("Ingrese la clave para buscar su nivel: ");
    int claveBuscada;
    scanf("%d", &claveBuscada);
    int nivel = nivelNodo(raiz, claveBuscada, 0);

    if (nivel != -1) {
        printf("Nivel del nodo con clave %d: %d\n", claveBuscada, nivel);
    } else {
        printf("Nodo con clave %d no encontrado en el arbol.\n", claveBuscada);
    }


    printf("Nodos internos: ");
    listarNodosInternos(raiz);
    printf("\n");


    int nivelHoja = -1;
    if (hojasMismoNivel(raiz)) {
        printf("Todas las hojas estan al mismo nivel.\n");
    } else {
        printf("Las hojas no estan al mismo nivel.\n");
    }

    return 0;
}
