#include <stdio.h>
#include <stdlib.h>
#include "ejercicio3.h"
#include "../TADs/pilas.h"
#include "../TADs/tipo_elemento.h"


int main()
{
    Pila pila1 = p_crear();
    Pila pila2 = p_crear();

    cargar_pila(&pila1);
    cargar_pila(&pila2);

    printf("\nComparando las pilas......\n");
    comparacion(&pila1, &pila2);

    return 0;
}
