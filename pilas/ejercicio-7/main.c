#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "ejercicio7.h"
#include "../TADs/pilas.h"
#include "../TADs/tipo_elemento.h"

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
    int opcion = 1;

    while(1){

        int num;
        bool verif;

        Pila pila1 = p_crear();
        do{
            verif = ingresarNumero(&num);
            if(verif) p_apilar(pila1, te_crear(num));

        }while(verif);

        printf("\nPila 1 apilada. Cargar Pila 2.\n\n");

        Pila pila2 = p_crear();
        do{
            verif = ingresarNumero(&num);
            if(verif) p_apilar(pila2, te_crear(num));

        }while(verif);

        printf("\nPILA 1\n");
        p_mostrar(pila1);
        printf("\nPILA 2\n");
        p_mostrar(pila2);

        elementosComun(pila1, pila2);

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
