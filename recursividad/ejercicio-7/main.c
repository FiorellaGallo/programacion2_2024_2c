#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ejercicio7.h"

void validaciones(char *entrada) {
    printf("Ingrese las ondas digitales con H y L \n");
    fgets(entrada, 25, stdin);
    //Eliminar salto de linea
    if(entrada[strlen(entrada)-1] == '\n') {
        entrada[strlen(entrada)-1] = '\0';
    }
    //Verificar que no este vacia
    if(strlen(entrada) == 0 || strcmp(entrada, " ") == 0) {
        printf("No se ingreso nada \n");
        while(getchar() != '\n');
        validaciones(entrada);
    }
    //Verificar que sea h o l
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (tolower(entrada[i]) != 'h' && tolower(entrada[i]) != 'l') {
            printf("Entrada invalida. Ingresar 'h' o 'l' \n");
            validaciones(entrada);
        }
    }
}

int main()
{
    char *entrada = malloc(25* sizeof(char));
    char *salida = malloc(25* sizeof(char));

    if (entrada == NULL) {
        printf("Error de asignacion de memoria\n");
        return 1;
    }

    validaciones(entrada);

    ondasDigitales(entrada, salida, 0);

    printf("%s\n", salida);

    free(entrada);
    free(salida);

    return 0;
}
