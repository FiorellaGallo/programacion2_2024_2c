#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ejercicio3.h"

void validacion(int *n){
    int c;

    printf("Ingrese un número para calcular fibonacci: \n");
    while(scanf("%d", n) != 1 || *n < 0){
        printf("Por favor ingrese un número válido: ");
       while ((c = getchar()) != '\n' && c != EOF);
    };

}

int main()
{
    int *n = malloc(sizeof(int));
    int res;
    validacion(n);
    res = calcularFibonacci(*n);
    printf("resultado: %d\n", res);

    free(n);

    return 0;
}
