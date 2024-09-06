#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<stdbool.h>
#include"ejercicio9.h"


void validaciones(int *n){
    printf("Ingrese un número: ");
    int resultado = scanf("%d", n);

    if (resultado == 0){
        printf("Se ha ingresado un caracter\n");
        while(fgetc(stdin) != '\n');
        validaciones(n);
    }else{
         int caracter = fgetc(stdin);
         if (caracter != '\n' && caracter != EOF) {
            printf("Se han ingresado caracteres\n");
            while (fgetc(stdin) != '\n');
            validaciones(n);
        } else if (*n == -1) {
            printf("Se excedió el rango de tamaño\n");
            validaciones(n);
        }
    }

}


int main(){
    int*n = malloc( 32 * sizeof(int));
    validaciones(n);
    int resultado = divisiblePor7(*n);

    if(resultado == 1){
        printf("True");
    }else{
        printf("False");
    }
    free(n);
    //system("pause");
    return 0 ;
};
