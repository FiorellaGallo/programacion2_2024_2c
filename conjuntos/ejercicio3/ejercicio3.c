#include <stdio.h>
#include <stdlib.h>
#include "../TADs/conjuntos.h"
#include "validacion.h"
#include "../TADs/listas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio3.h"

Conjunto cto_ctos_union(Conjunto conjunto_a, int Cant){
    Conjunto resu=cto_crear();
    int i=1;
    TipoElemento x;
    while(Cant >= i){
        x=cto_recuperar(conjunto_a,i);
        Conjunto a=(Conjunto)x->valor;
        resu=cto_union(a,resu);
        i++;
    }
    return resu;
}


Conjunto cto_ctos_interseccion(Conjunto conjunto_a, int Cant){
    Conjunto resu=cto_ctos_union(conjunto_a,Cant);
    int i=1;
    TipoElemento x;
    while(Cant > i){
        x=cto_recuperar(conjunto_a,i);
        Conjunto a=(Conjunto)x->valor;
        resu=cto_interseccion(a,resu);
        i++;
    }
    return resu;
}
