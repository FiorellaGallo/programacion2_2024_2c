#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../TADs/arbol-binario.h"
#include "../TADs/nodo.h"
#include "../TADs/tipo_elemento.h"

bool ingresoEntero(int *n) {
    char s[10];
    *n = 0;
    int signo = 1;
    bool numeroValido = false;

    while(!numeroValido) {
        printf("Ingrese un numero o '.' para salir \n");
        scanf("%s", s);

        if (s[0] == '.' && s[1] == '\0') {
            return false;
        }

        int i = 0;
        *n = 0;
        signo = 1;

        if (s[0] == '-'){
            signo = -1;
            i = 1;
        }

        numeroValido = true;
        for(;s[i] !='\0'; i++) {
            if((s[i] >= '0') && (s[i] <= '9')) {
                *n = *n * 10 + (s[i] - 48);
            } else {
                printf("Entrada invalida\n");
                numeroValido = false;
                break;
            }
        }

        if(numeroValido) {
            *n = *n * signo;
        }
    }
    return true;
}

bool Cargar_SubArbol(ArbolBinario A, NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool continuar = ingresoEntero(&n);

    if (!continuar) {
        return false;
    }

    if(!a_es_lleno(A)){
        X= te_crear(n);

        if(sa == -1) N1 = a_conectar_hi(A, N, X);
        else if(sa == 1) N1 = a_conectar_hd(A, N, X);
        else N1 = a_establecer_raiz(A, X);

        if (N1 != NULL) {
            if (!Cargar_SubArbol(A, N1, -1)) return false;
            if (!Cargar_SubArbol(A, N1, 1)) return false;
        }
    }
    return true;
}

void cargar_arbol_binario(ArbolBinario A){
    Cargar_SubArbol(A, NULL, 0);
}

int main()
{
    ArbolBinario arbol1 = a_crear();
    ArbolBinario arbol2 = a_crear();

    printf("Cargar arbol 1:\n");
    cargar_arbol_binario(arbol1);

    printf("Cargar arbol 2:\n");
    cargar_arbol_binario(arbol2);

    if (sonEquivalentes(arbol1, arbol2)) {
        printf("Los arboles son equivalentes.\n");
    } else {
        printf("Los arboles no son equivalentes.\n");
    }

    return 0;
}
