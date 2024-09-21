#include <stdio.h>
#include <stdlib.h>
#include "../TADs/tipo_elemento.h"
#include "../TADs/listas.h"
#include "ejercicio_6.h"

void cargar_listas(Lista* L){
    int num;
    char c;

    while(1){
        if(scanf("%d",&num) == 1){
            TipoElemento X = te_crear(num);
            l_agregar(L, X);
        }else{
            scanf("%c",&c);
            if(c == '*'){
                break;
            }else{
                printf("Entrada no válida.Solo se permiten números.Intente nuevamente:\n");
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }
    }
}

bool comparar(Lista* L2, Lista* L1){
    TipoElemento X;
    Iterador ite;
    ite = iterador(L2);

    while(hay_siguiente(ite)){
        X = siguiente(ite);
        if(!l_buscar(L1,X->clave)){
            printf("\nRESULTADO: L2 no es sublista de L1\n");
            return false;
        }
    }
    printf("\nRESULTADO: L2 es sublista de L1\n");
}

//COMPLEJIDAD ALGORITMICA

/*La función "comparar" presenta una complejidad algorítmica de orden cuadrática, ya que para buscar todos
los elementos de L2 en L1 requiero recorrer ambas listas. El recorrido de L2 se realiza con el while, y por
cada elemento de L2, la función l_buscar realiza una búsqueda lineal en L1, lo que introduce una complejidad
de O(n) por cada elemento de L2. Como resultado, la complejidad total es O(n * m), donde n es el tamaño de L1
y m el tamaño de L2.*/

