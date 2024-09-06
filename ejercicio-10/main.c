#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "ejercicio10.h"


void validarEntrada(int *n){
    int resultado = scanf("%d", n);

    if (resultado == 0){
        printf("Se ha ingresado un caracter\n");
        while(fgetc(stdin) != '\n');
            printf("Ingrese un número: ");

        validarEntrada(n);
    }else{
         int caracter = fgetc(stdin);
         if (caracter != '\n' && caracter != EOF) {
            printf("Se han ingresado caracteres\n");
            while (fgetc(stdin) != '\n');
            printf("Ingrese un número: ");

            validarEntrada(n);
        } else if (*n == -1) {
            printf("Se excedió el rango de tamaño\n");
                printf("Ingrese un número: ");

            validarEntrada(n);
        }
    }

}


void validaciones(int *N, int *B) {

    printf("Ingrese un número explosivo:\n");
    validarEntrada(N);


    printf("Ingrese un número bomba(menor al número explosivo):\n");
    validarEntrada(B);

    while(*B >= *N){
        printf("Ingrese un número bomba(menor al número explosivo):\n");
        validarEntrada(B);
    }
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
