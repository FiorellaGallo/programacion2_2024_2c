#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ejercicio8.h"

ListaFinal *crearLista(int capacidad){
    ListaFinal *lista = (ListaFinal *)malloc(sizeof(ListaFinal));
    lista->subconjuntos = (Subconjunto *)malloc(capacidad * sizeof(Subconjunto));
    lista->cantidad = 0;
    return lista;
};

//La variable se llama "tamano" porque me toma "Ñ" como caracter especial
void agregarSubconjuntos(int conjunto[], int tamano, ListaFinal *lista) {
    int i;


    Subconjunto subconjunto_nuevo;
    subconjunto_nuevo.numeros = (int *)malloc(tamano * sizeof(int));

    for(i = 0; i < tamano; i++){
        subconjunto_nuevo.numeros[i] = conjunto[i];
    }
    subconjunto_nuevo.cantidad = tamano;


    lista->subconjuntos[lista->cantidad] = subconjunto_nuevo;
    lista->cantidad++;

};

void subconjuntosQueSumanN(int conjunto[], int n,int largo,int pos, int conjunto_actual[], int actual_tam, ListaFinal *lista){

    if (n == 0){
        agregarSubconjuntos(conjunto_actual,actual_tam, lista);
        return;
    }

    if (pos == largo || n < 0) return;


    conjunto_actual[actual_tam] = conjunto[pos];
    subconjuntosQueSumanN(conjunto, n - conjunto[pos], largo, pos + 1, conjunto_actual, actual_tam + 1, lista);


    subconjuntosQueSumanN(conjunto, n, largo, pos + 1, conjunto_actual, actual_tam, lista);

};

void mostrarLista(ListaFinal *lista) {
    for (int i = 0; i < lista->cantidad; i++) {
        printf("{");
        for (int j = 0; j < lista->subconjuntos[i].cantidad; j++) {
            printf("%d", lista->subconjuntos[i].numeros[j]);
            if (j < lista->subconjuntos[i].cantidad - 1) printf(", ");
        };
        printf("}\n");
    };
};
