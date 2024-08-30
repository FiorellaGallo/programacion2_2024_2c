#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "ejercicio1.h"

bool palindromo(char *palabra){
    bool resultado ;
    int largo = strlen(palabra);
    //caso base
    if (largo <= 1){
        resultado = true;
    }
    else if( palabra[0] == palabra[largo - 1]){
    /*Guardamos en memoria subcadena que es una copia de "palabra",
    sin el primer y último caracter. Luego llamamos nuevamente a la función(recursividad)*/
        char *subcadena = malloc(largo - 1);
        strncpy(subcadena, palabra + 1, largo - 2 );
        subcadena[largo - 2 ] = '\0';
        resultado = palindromo(subcadena);
        free(subcadena);
    }else{
        resultado = false;
    }
    return resultado;
}
