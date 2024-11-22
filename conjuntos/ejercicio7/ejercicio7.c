#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../TADs/listas.h"
#include "ejercicio7.h"
#include "../TADs/tipo_elemento.h"
#include "../TADs/conjuntos.h"
#include "../TADs/arbol-avl.h"



Conjunto cargar_conjunto(Conjunto cto){


    int num;
    char c;

    printf("Ingrese el numero o una letra para terminar\n");
    while(scanf("%d", &num) == 1){
        cto_agregar(cto, te_crear(num));
        printf("Ingrese el numero o una letra para terminar\n");
    }

    while ((c = getchar()) != '\n' && c != EOF);
    cto_mostrar(cto);
    return cto;
}

void cargar_todos(Conjunto cto_A,Conjunto cto_B,Conjunto cto_C){

    printf("CARGANDO CONJUNTO A:\n");
    cto_A = cargar_conjunto(cto_A);
    printf("CARGANDO CONJUNTO B:\n");
    cto_B = cargar_conjunto(cto_B);
    printf("CARGANDO CONJUNTO C:\n");
    cto_C = cargar_conjunto(cto_C);

}

int es_subconjunto(Conjunto cto_A,Conjunto cto_B){

    Conjunto rta = cto_diferencia(cto_A, cto_B);
    int cant_original = cto_cantidad_elementos(cto_A);
    int cant_diferencia = cto_cantidad_elementos(rta);


    int parcial = (cant_original)-(cant_diferencia);
    int respuesta;

    if(cto_es_vacio(rta)){
        respuesta = 0;
    }else if(parcial >= (cant_original)/2){
        respuesta = 1;
    }else{
        respuesta = 2;
    }

    return respuesta;

}


void calcular_conjuntos(Conjunto cto_A,Conjunto cto_B){

    int respuesta;

    respuesta = es_subconjunto(cto_A, cto_B);

    if(respuesta == 0)printf(" es subconjunto de ");
    else if(respuesta == 1) printf(" es subconjunto parcial de ");
    else printf(" no es subconjunto de ");

}







