#include <stdio.h>
#include <stdlib.h>
#include "ejercicio4.h"
#include "../TADs/colas.h"
#include "../TADs/tipo_elemento.h"
#include "../TADs/listas.h"

int main()
{
    Cola cola = c_crear();
    cargar_cola(&cola);

    Cola ele_no_repetidos = no_repetidos(&cola);
    printf("ELEMENTOS NO REPETIDOS: \n");
    c_mostrar(ele_no_repetidos);

    return 0;
}
