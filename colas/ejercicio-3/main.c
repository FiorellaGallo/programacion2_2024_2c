#include <stdio.h>
#include <stdlib.h>
#include "ejercicio3.h"
#include "../TADs/colas.h"
#include "../TADs/tipo_elemento.h"


int main()
{

    Cola cola1= c_crear();
    Cola cola2= c_crear();

    cargar_cola(&cola1);
    printf("--------------- COLA 1 CARGADA ---------------\n\n");
    cargar_cola(&cola2);
    printf("--------------- COLA 2 CARGADA ---------------\n\n");

    comparacion(&cola1, &cola2);

    printf("COLA 1:\n");
    c_mostrar(cola1);
    printf("COLA 2:\n");
    c_mostrar(cola2);

    return 0;
}
