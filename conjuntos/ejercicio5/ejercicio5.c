#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../TADs/conjuntos.h"
#include "ejercicio5.h"
#include "../TADs/tipo_elemento.h"
#include "../TADs/listas.h"


int entero(int min, int max) {
    int valor;
    char buffer;

    while (1) {
        if (scanf("%d", &valor) == 1) {
            if (valor >= min && valor <= max) {
                return valor;
            } else {
                printf("El número debe estar entre %d y %d. Intente de nuevo:\n", min, max);
            }
        } else {
            printf("Entrada inválida. Ingrese un número entero:\n");
            while ((buffer = getchar()) != '\n' && buffer != EOF);
        }
    }
}

Conjunto carga (Conjunto C ){
    TipoElemento X;
    int i, cantidad;
    printf("Ingrese la cantidad de elementos que desea cargar en el conjunto (entre 0 y 100): ");
    cantidad = entero(0,100);

    for(i = 1; i <= cantidad; i++){
        printf("Ingrese la clave %d: ",i);
        int clave = entero(0,2000);

        if(cto_es_vacio(C) || !cto_pertenece(C, clave)){
            X = te_crear(clave);
            cto_agregar(C,X);
        }else{
            printf("La clave %d ya existe en el conjunto y no será agregada.\n",clave);
        }
    }
    return C;
}

Conjunto diferencia_simetrica(Conjunto conjunto_1, Conjunto conjunto_2, Conjunto resultado){
    TipoElemento Xa, Xb;
    int cantidadA, cantidadB, mayor_cantidad,i;

    cantidadA = cto_cantidad_elementos(conjunto_1);
    cantidadB = cto_cantidad_elementos(conjunto_2);

    if (cantidadA > cantidadB){
        mayor_cantidad = cantidadA;
    }else {
        mayor_cantidad = cantidadB;
    }

    for (i = 1; i <= mayor_cantidad; i++)
    {
        Xa = cto_recuperar(conjunto_1,i);
        Xb = cto_recuperar(conjunto_2,i);

        if (Xa==NULL || Xb==NULL){

            if (Xa == NULL && Xb != NULL  && (!cto_pertenece(resultado,Xb->clave))){
                cto_agregar(resultado,Xb);

            }else if(Xb == NULL && Xa != NULL  &&(!cto_pertenece(resultado,Xa->clave))){
                cto_agregar(resultado,Xa);
            }
        }
         else if(Xa->clave != Xb->clave){

             bool perteneceXa = cto_pertenece(conjunto_2,Xa->clave);
             bool perteneceXb = cto_pertenece(conjunto_1,Xb->clave);

             if (!perteneceXa){
                cto_agregar(resultado, Xa);
             }

             if (!perteneceXb){
             cto_agregar(resultado,Xb);
             }

        }

    }

    return resultado;

}





