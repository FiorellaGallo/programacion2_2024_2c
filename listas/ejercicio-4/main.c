#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../TADs/listas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio4.h"

bool ingresarNumero(int *num) {
    char input[100];

    printf("Ingresa un numero para agregar a la lista o cualquier valor no numerico para finalizar la carga: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        int i = 0;
        if (input[0] == '-') {
            i++;
        }

        for (; input[i] != '\0' && input[i] != '\n'; i++) {
            if (!isdigit(input[i])) {
                return false;
            }
        }
        *num = atoi(input);
        return true;
    }

    return false;
}


int main(){

    int opcion;

    while(1){

        int num;
        bool verif;

        Lista Lista1 = l_crear();
        do{
            verif = ingresarNumero(&num);
            if(verif) l_agregar(Lista1, te_crear(num));
        }while(verif);

        printf("\nLista 1 cargada. Ahora cargar Lista 2: \n\n");

        Lista Lista2 = l_crear();
        do{
            verif = ingresarNumero(&num);
            if(verif) l_agregar(Lista2, te_crear(num));
        }while(verif);

        printf("\nLISTA 1\n");
        l_mostrar(Lista1);
        printf("\nLISTA 2\n");
        l_mostrar(Lista2);

        comparacion(Lista1, Lista2);

        printf("Ingrese 0 para salir o cualquier otra entrada para continuar: ");
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
