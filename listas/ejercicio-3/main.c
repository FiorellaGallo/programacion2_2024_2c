#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../TADs/listas.h"
#include "ejercicio3.h"

bool ingresoEntero(int* n) {
    char s[10];
    bool resultado = true;
    *n = 0;
    int signo = 1;
    bool numeroValido = false;

    while (!numeroValido) {
        printf("Ingrese un numero o '.' para salir: \n");
        scanf("%s", s);

        if(s[0] == '.') {
            return false;
        }

        int i = 0;
        *n = 0;
        signo = 1;

        // ver si el primer caracter es - (numero negativo)
        if(s[0] == '-') {
            signo = -1;
            //empezar a iterar desde el primer numero (sin contar -)
            i = 1;
        }

        numeroValido = true;
        for (; s[i] != '\0'; i++) {
            if ((s[i]>='0') && (s[i]<='9')) {
                *n = *n * 10 + (s[i] - 48);
            } else {
                printf("Entrada invalida.\n");
                numeroValido = false;
                break;
            }
        }

        if(numeroValido) {
            *n = *n * signo;
        }
    }
    return resultado;
}

int main() {
    int n;
    bool b;

    Lista L1 = l_crear();
    do {
            if(l_es_llena(L1)) {
            printf("La lista ya se lleno.\n");
            break;
        }
        b = ingresoEntero(&n);
        if(b) l_agregar(L1, te_crear(n));
    }while(b);

    l_mostrar(L1);

    Lista L2 = l_crear();
    do {
            if(l_es_llena(L2)) {
            printf("La lista ya se lleno.\n");
            break;
        }
        b = ingresoEntero(&n);
        if(b) l_agregar(L2, te_crear(n));
    }while(b);

    l_mostrar(L2);

    bool res;

    res = determinarMultiplo(L1, L2);
    if(res) {
        printf("L2 es multiplo de L1");
    } else {
        printf("L2 no es multiplo de L1");
    }

    return 0;
}
