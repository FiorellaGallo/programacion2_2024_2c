#include <stdio.h>
#include <stdlib.h>
#include "../TADs/arbol-avl.h"
#include "../TADs/arbol-binario-busqueda.h"
#include "../TADs/nodo.h"
#include "../TADs/tipo_elemento.h"

int main()
{
    int opcion = 1;

    while(1){

        char c;
        int repeticiones;

        do{
            printf("Ingrese la cantidad de veces que quiere repetir el proceso (entre 1 y 10): ");
            scanf("%d", &repeticiones);
            if(repeticiones < 1 || repeticiones > 10){
                printf("Error, numero fuera del rango.\n");
            }
            while ((c = getchar()) != '\n' && c != EOF);
        } while(repeticiones < 1 || repeticiones > 10);

        comparar(repeticiones);

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
