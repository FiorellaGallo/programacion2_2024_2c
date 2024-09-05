#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "ejercicio10.h"

void validaciones(int *N, int *B) {
    int c;

    printf("Ingrese un numero explosivo:\n");
    while(scanf("%d", N) != 1 || *N <= 0){
        printf("Por favor ingrese un numero valido: ");
        while ((c = getchar()) != '\n' && c != EOF);
    };

    printf("Ingrese un numero bomba(menor al numero explosivo):\n");
    while(scanf("%d", B) != 1 || *B <= 0 || *B >= *N){
        printf("Por favor ingrese un numero valido: ");
        while ((c = getchar()) != '\n' && c != EOF);
    };
}


int main()
{
    int N = 0;
    int B = 0;
    int size = 0;

    validaciones(&N, &B);

    int* fragmentos = explosion(N,B,&size);

    printf("Fragmentos: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", fragmentos[i]);
    }
    printf("\n");

    free(fragmentos);

    return 0;
}
