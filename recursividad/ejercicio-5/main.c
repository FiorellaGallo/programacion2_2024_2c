#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ejercicio5.h"

void validaciones(char *numero){
    const char *digitos = "0123456789";

    printf("Ingrese un número sin los puntos de los miles: ");
    fgets(numero,20,stdin);

    int longitud = strlen(numero);

    if(numero[longitud-1] == '\n')
    numero[longitud-1] = '\0';

    if (strlen(numero)|| strcmp(numero, " ") == 0){
        printf("No se ingreso ningún número\n");
        while(getchar()!= '\n');
        validaciones(numero);

    }

    if (strspn(numero, digitos) == longitud){
        printf("No es un número válido\n");
        while(getchar()!= '\n');
        validaciones(numero);

    }

}



int main()
{
    char *numero = malloc(sizeof(char));
    validaciones(numero);


    printf("Numero separado por miles: ");
    separadorMiles(numero);

    return 0;
}
