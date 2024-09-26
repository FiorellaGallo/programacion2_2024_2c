#include <stdio.h>
#include <stdlib.h>
#include "../TADs/pilas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio-4.h"

void validaciones (int *num, int *base){
    int resultado;

    while (1) {
        printf("Introduce un número decimal: ");
        if (scanf("%d", num) == 1) {
            break;
        } else {
            printf("Entrada no válida. Introduce un número decimal.\n");
            while (getchar() != '\n');
        }
    }

    do {
        printf("Introduce un número para la base (entre 2 y 16): ");
        resultado = scanf("%d", base);

        if (resultado == 0 || *base < 2 || *base > 16) {
            printf("\nBase inválida. La base debe estar entre 2 y 16.\n");
            while (fgetc(stdin) != '\n');
        }
    } while (resultado == 0 || *base < 2 || *base > 16);

}


int main()
{
    Pila P1 = p_crear();
    int num ,base;
    validaciones(&num,&base);
    conversion(num,P1,base);
}
