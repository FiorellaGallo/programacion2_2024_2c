#include <stdio.h>
#include <stdlib.h>
#include "../TADs/conjuntos.h"
#include "../TADs/listas.h"
#include"../TADs/tipo_elemento.h"



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

        if(cto_es_vacio(C) || (!cto_pertenece(C, clave))){
            X = te_crear(clave);
            cto_agregar(C,X);
        }else{
            printf("La clave %d ya existe en el conjunto y no será agregada.\n",clave);
        }
    }
    return C;
}

bool ConjuntosIguales(Conjunto a, Conjunto b){
    int canta=cto_cantidad_elementos(a);
    int cantb=cto_cantidad_elementos(b);



    int mayor;
    TipoElemento Ta;
    TipoElemento Tb;
    bool resu;
    if (canta>cantb)
    {
        mayor=canta;
    }else mayor= cantb;
    if (canta != cantb) return false;

    for (int i = 1; i <= canta; i++)
    {
        Ta = cto_recuperar(a, i);
        resu=false;
        for (int j = 1; j <= cantb; j++)
        {
            Tb = cto_recuperar(b, j);
            if (Ta->clave == Tb->clave) resu=true;
           if (resu==false && j == cantb) return false;
        }
    }
    return resu;
}
