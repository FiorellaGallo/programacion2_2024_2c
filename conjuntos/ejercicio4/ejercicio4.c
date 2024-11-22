#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../TADs/listas.h"
#include "ejercicio4.h"
#include "../TADs/tipo_elemento.h"
#include "../TADs/conjuntos.h"

Conjunto cargar_conjunto(){

    Conjunto cto = cto_crear();
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

void cargar_todos(){

    printf("CARGANDO CONJUNTO A:\n");
    Conjunto cto_A = cargar_conjunto();
    printf("CARGANDO CONJUNTO B:\n");
    Conjunto cto_B = cargar_conjunto();
    printf("CARGANDO CONJUNTO C:\n");
    Conjunto cto_C = cargar_conjunto();

    Conjunto rta1= cto_crear();
    Conjunto rta2= cto_crear();
    rta1 = cto_diferencia(cto_A, cto_B);
    rta2 = cto_diferencia(cto_B, cto_C);

    if(cto_es_vacio(rta1) && cto_es_vacio(rta2)){
        printf("A es subconjunto de B y B es subconjunto de C");
    }else if(cto_es_vacio(rta1) && !cto_es_vacio(rta2)){
        printf("A es subconjunto de B pero B NO es subconjunto de C\n");
    }else if(!cto_es_vacio(rta1) && cto_es_vacio(rta2)){
        printf("A NO es subconjunto de B y B es subconjunto de C\n");
    }else{
        printf("A NO es subconjunto de B y B NO es subconjunto de C");
    }

}
