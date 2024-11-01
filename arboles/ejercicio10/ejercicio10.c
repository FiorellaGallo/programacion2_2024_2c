#include <stdio.h>
#include <stdlib.h>
#include "../TADs/arbol-avl.h"
#include "../TADs/arbol-binario-busqueda.h"
#include "../TADs/nodo.h"
#include "../TADs/tipo_elemento.h"

int altura(NodoArbol nodo) {
    if (nodo == NULL) return -1;
    int alturaIzq = altura(nodo->hi);
    int alturaDer = altura(nodo->hd);
    return 1 + (alturaIzq > alturaDer ? alturaIzq : alturaDer);
}

void cargarArboles(ArbolAVL arbol_avl, ArbolBinarioBusqueda arbol_abb){
    int cantidadNum;
    int numeros[cantidadNum];
    char c;

    for(int k = 0; k < 1; k++){
        printf("Ingrese la cantidad de numeros que quiere cargar (entre 1 y 15): ");
        scanf("%d", &cantidadNum);
        while ((c = getchar()) != '\n' && c != EOF);

        if (cantidadNum < 1 || cantidadNum > 15) {
            printf("Numero invalido. Debe estar entre 1 y 15.\n");
            k--;
            continue;
        }

        printf("Ingrese %d numeros entre 1 y 100:\n", cantidadNum);
        for (int j = 0; j < cantidadNum; j++) {
            do{
                printf("Numero %d: ", j+1);
                scanf("%d", &numeros[j]);

                if(numeros[j] < 1 || numeros[j] > 100){
                    printf("Error, numero fuera del rango.\n");
                }
                while ((c = getchar()) != '\n' && c != EOF);
            }while(numeros[j] < 1 || numeros[j] > 100);
        }
    }
    for (int i = 0; i < cantidadNum; i++) {
        TipoElemento elem = te_crear(numeros[i]);

        TipoElemento repetido_avl = avl_buscar(arbol_avl, numeros[i]);
        if(repetido_avl == NULL){
            avl_insertar(arbol_avl, elem);
        } else {
            printf("%d ya esta en el arbol AVL.\n", numeros[i]);
        }

        TipoElemento repetido_abb = abb_buscar(arbol_abb, numeros[i]);
        if(repetido_abb == NULL){
            abb_insertar(arbol_abb, elem);
        } else {
            printf("%d ya esta en el arbol ABB.\n", numeros[i]);
        }

    }
}

void comparar(int repeticiones){

    int acum_altura_avl = 0;
    int acum_altura_abb = 0;

    for(int i = 0; i < repeticiones; i++){
        ArbolAVL arbol_avl = avl_crear();
        ArbolBinarioBusqueda arbol_abb = abb_crear();
        cargarArboles(arbol_avl, arbol_abb);

        int altura_avl = altura(avl_raiz(arbol_avl));
        int altura_abb = altura(abb_raiz(arbol_abb));

        printf("Altura Arbol AVL: %d\n", altura_avl);
        printf("Altura Arbol ABB: %d\n", altura_abb);

        acum_altura_avl += altura_avl;
        acum_altura_abb += altura_abb;
    }

    printf("Promedio de altura de AVL: %d\n", acum_altura_avl / repeticiones);
    printf("Promedio de altura de ABB: %d\n", acum_altura_abb / repeticiones);
}


// Se puede concluir que los árboles AVL, al tener menos altura que los árboles ABB debido
// a que están balanceados, tienen un rendimiento superior en sus operaciones cuando se
// trabaja con una gran cantidad de datos. Esto se debe a que la complejidad algorítmica
// de las operaciones en los ABB es de orden lineal O(n), pero en los AVL es de orden
// logarítmico O(log n). Mientras mayor es el problema, O(log n) < O(n).
