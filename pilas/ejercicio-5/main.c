#include <stdio.h>
#include <stdlib.h>
#include "../TADs/pilas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio_5.h"

int main()
{
    Pila* P1 = p_crear();

    printf("Ingrese los números de la pila (Pulse * para finalizar):\n");
    carga(P1);

    invertir(P1);

}
