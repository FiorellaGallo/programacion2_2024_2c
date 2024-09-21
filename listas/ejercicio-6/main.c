#include <stdio.h>
#include <stdlib.h>
#include "../TADs/tipo_elemento.h"
#include "../TADs/listas.h"
#include "ejercicio_6.h"


int main(){
    TipoElemento X;
    Lista* L1 ;
    Lista* L2;
    L1 = l_crear();
    L2 = l_crear();
    printf("Las lista fue creada correctamente\n");

    printf("Ingrese los números de la primera lista (Pulse * para finalizar):\n");
    cargar_listas(L1);

    printf("Ingrese los números de la segunda lista (Pulse * para finalizar):\n");
    cargar_listas(L2);

    l_mostrar(L1);
    l_mostrar(L2);

    if(!l_es_vacia(L1) && !l_es_vacia(L2)){
         comparar(L2,L1);
    }else{
        printf("\nLista vacia\n");
    }

    return 0;
}
