#include <stdio.h>
#include <stdlib.h>
#include "../TADs/conjuntos.h"
#include "ejercicio7.h"
#include "../TADs/tipo_elemento.h"


int main()
{

    Conjunto cto_A=cto_crear();
    Conjunto cto_B=cto_crear();
    Conjunto cto_C=cto_crear();
    cargar_todos(cto_A,cto_B,cto_C);

    printf("A");
    calcular_conjuntos(cto_A,cto_B);
    printf("B\n");

    printf("A");
    calcular_conjuntos(cto_A,cto_C);
    printf("C\n");

    printf("B");
    calcular_conjuntos(cto_B,cto_A);
    printf("A\n");

    printf("B");
    calcular_conjuntos(cto_B,cto_C);
    printf("C\n");

    printf("C");
    calcular_conjuntos(cto_C,cto_A);
    printf("A\n");

    printf("C");
    calcular_conjuntos(cto_C,cto_B);
    printf("B\n");
    return 0;
}
