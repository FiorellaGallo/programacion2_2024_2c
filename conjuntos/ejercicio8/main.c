#include <stdio.h>
#include <stdlib.h>
#include "../TADs/conjuntos.h"
#include "../TADs/listas.h"
#include"../TADs/tipo_elemento.h"
#include "ejercicio8.h"

int main()
{

    Conjunto a = cto_crear();
    Conjunto b = cto_crear();
    printf("Conjunto A\n");

    a=carga(a);
    printf("Conjunto B\n");

    b=carga(b);

    cto_mostrar(a);
    cto_mostrar(b);

    bool iguales = ConjuntosIguales(a,b);

    if (iguales){
    printf("Son iguales\n");

    }else printf("No son iguales\n");

    return 0;
}

// La complejidad es de O(n2).
