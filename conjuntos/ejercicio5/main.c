#include <stdio.h>
#include <stdlib.h>
#include "../TADs/conjuntos.h"
#include "ejercicio5.h"


int main()
{
    Conjunto conjunto_1 = cto_crear();
    Conjunto conjunto_2 = cto_crear();
    Conjunto resultado = cto_crear();

    conjunto_1 = carga(conjunto_1);
    conjunto_2 = carga(conjunto_2);

    resultado = diferencia_simetrica(conjunto_1,conjunto_2,resultado);
    cto_mostrar(resultado);

    return 0;
}
