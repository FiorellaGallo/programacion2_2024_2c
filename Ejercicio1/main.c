#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ejercicio1.h"

void validaciones(char *palabra){

    printf("Ingrese una palabra:");
    fgets(palabra,15,stdin);
    if(palabra[strlen(palabra)-1] == '\n')
    palabra[strlen(palabra)-1] = '\0';

    if (strlen(palabra) == 0 || strcmp(palabra, " ") == 0){
        printf("No se ingreso ninguna palabra\n");
        while(getchar()!= '\n');
        validaciones(palabra);

    }else if (isdigit(*palabra)){
        printf("Usted ingreso un número\n");
        while(getchar()!= '\n');
        validaciones(palabra);
    }

    if(strlen(palabra) == 14 && palabra[15] != '\n'){
        printf("Supera el la cantidad de caracteres permitidos\n");
        while(getchar()!= '\n');
        validaciones(palabra);

    }else if(strchr(palabra, ' ') != NULL){
        printf("Solo se puede ingresar una palabra\n");
        while(getchar()!= '\n');
        validaciones(palabra);
    }
}


int main(){
    char *palabra = malloc(15 * sizeof(char));

    if (palabra == NULL) {
        printf("Error de asignación de memoria\n");
        return 1;
    }

    validaciones(palabra);
    bool resultado = palindromo(palabra);

    if(resultado){
        printf("True\n");
    }else{
        printf("False\n");
    }
    free(palabra);
    //system("pause");
    return 0;
}


