#include <stdio.h>
#include <stdlib.h>
#include "ejercicio8.h"

void validaciones(int *n, int suma){
    int c;
    printf("ingrese un numero: ");
    while(scanf("%d", n) != 1){
        printf("Por favor ingrese un numero: ");
        while ((c = getchar()) != '\n' && c != EOF);
    };

    while((*n > suma) || (*n < 0)){
        printf("Por favor ingrese un numero mayor a cero y menor o igual a %d :",suma);
        while ((c = getchar()) != '\n' && c != EOF);
        while(scanf("%d", n) != 1){
             printf("Por favor ingrese un numero: ");
            while ((c = getchar()) != '\n' && c != EOF);
        }
    };

}

int main(){
    int conjunto[]={10,3,1,7,4,2};
    int largo = sizeof(conjunto)/sizeof(conjunto[0]);

    int suma_conjunto = 0;
    for(int i=0; i< largo; i++){
        suma_conjunto += conjunto[i];
    };

    int *n = malloc(sizeof(int));

    validaciones(n,suma_conjunto);

    int pos=0;

    //array temporal para buscar subconjuntos en subconjuntosQueSumanN()
    int conjunto_actual[largo];

    int actual_tam = 0;

    //crear la lista donde van a ir los todos los subconjuntos
    ListaFinal *lista = crearLista(20);

    subconjuntosQueSumanN(conjunto, *n, largo, pos, conjunto_actual, actual_tam, lista);

    mostrarLista(lista);

    for (int i = 0; i < lista->cantidad; i++) {
        free(lista->subconjuntos[i].numeros);
    };

    free(lista->subconjuntos);

    free(lista);

    free(n);
    return 0;
};
