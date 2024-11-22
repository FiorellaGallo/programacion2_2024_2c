#include <stdio.h>
#include <stdlib.h>
#include "../TADs/conjuntos.h"
#include "validacion.h"
#include "../TADs/listas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio3.h"

Conjunto cto_carga(){
    printf("ingrese la cantidad de elementos a cargar ");
    int cant=entero_entre(0,100);
    Conjunto resu=cto_crear();
    TipoElemento x;
    int i=-1;
    while(cant>0){
        printf("Ingrese el elemento: ");
        i=entero_entre(0,1000);
        x=te_crear(i);
        cto_agregar(resu,x);
        cant--;
    }
    return resu;
}


Conjunto ctos_carga(int cant){
    int i=1;
    Conjunto resu=cto_crear();
    TipoElemento x;
    while(cant>0){
        printf("\nConjunto %i:\n",i);
        x=te_crear_con_valor(i,cto_carga());
        cto_agregar(resu,x);
        i++;
        cant--;
    }
    return resu;
}

int main(){

    printf("Ingrese la cantidad de conjuntos a cargar ");
    int cant = entero_entre(0,10);
    Conjunto a=ctos_carga(cant);

    printf("\nEl conjunto union de los conjuntos es:\n");
    cto_mostrar(cto_ctos_union(a,cant));

    printf("\nEl conjunto interseccion de los conjuntos es:\n");
    cto_mostrar(cto_ctos_interseccion(a,cant));
}
