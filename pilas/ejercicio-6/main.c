#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../TADs/pilas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio6.h"

bool ingresarNumero(int *num) {
    char input[100];
    int resultado = 0;
    bool esNegativo = false;

    printf("Ingresa un numero para apilar en la pila o cualquier valor no numerico para finalizar la carga: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        int i = 0;
        if (input[0] == '-') {
            esNegativo = true;
            i++;
        }

        for (; input[i] != '\0' && input[i] != '\n'; i++) {
            if (!isdigit(input[i])) {
                return false;
            }
            resultado = resultado * 10 + (input[i] - '0');
        }
        if(esNegativo){
            resultado = -resultado;
        }
        *num = resultado;
        return true;
    }
    return false;
}

int main()
{
    int opcion;

    while(1){

        int num;
        bool verif;
        int dato;

        Pila pila1 = p_crear();
        do{
            verif = ingresarNumero(&num);
            if(verif) p_apilar(pila1, te_crear(num));

        }while(verif);

        if(p_es_vacia(pila1)){
            printf("\nERROR, la pila esta vacia.\n");
            break;
        }

        printf("\nPila 1 apilada.\n\n");
        printf("Ingrese clave a eliminar: ");
        scanf("%d", &dato);

        // ITERATIVO
        printf("\nITERATIVO\n");
        printf("\nPILA ORIGINAL\n");
        p_mostrar(pila1);

        printf("\nPILA RESULTADO ITERATIVO\n");
        pilaIterativa(pila1, dato);

        printf("\nPILA ORIGINAL CONSERVADA\n");
        p_mostrar(pila1);

        // RECURSIVO
        printf("\nRECURSIVO\n");
        printf("\nPILA ORIGINAL\n");
        p_mostrar(pila1);

        printf("\nPILA RESULTADO RECURSIVO\n");
        Pila pila_nueva = pilaRecursiva(pila1, dato);
        p_mostrar(pila_nueva);

        printf("\nPILA ORIGINAL CONSERVADA\n");
        p_mostrar(pila1);

        printf("\n\nIngrese 0 para salir o cualquier otra entrada para continuar: ");
        scanf("%d", &opcion);
        while(fgetc(stdin) != '\n');

        if (opcion == 0){
            printf("\nSaliste del sistema.\n");
            break;
        } else {
            continue;
        }
    }
    return 0;
}
