#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "ejercicio1.h"

bool palindromo(char *palabra){
    bool resultado ;
    int largo = strlen(palabra);

    if (largo <= 1){
        resultado = true;
    }
    else if( tolower(palabra[0]) == tolower(palabra[largo - 1])){

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
