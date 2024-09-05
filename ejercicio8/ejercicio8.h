#ifndef EJERCICIO8_H_INCLUDED
#define EJERCICIO8_H_INCLUDED

typedef struct {
    int *numeros;
    int cantidad;

} Subconjunto;

typedef struct {
    Subconjunto *subconjuntos;
    int cantidad;
} ListaFinal;

ListaFinal *crearLista(int capacidad);

void agregarSubconjuntos(int conjunto[], int tamano, ListaFinal *lista);

void subconjuntosQueSumanN(int conjunto[], int n,int largo,int pos, int conjunto_actual[], int actual_tam, ListaFinal *lista);

void mostrarLista(ListaFinal *lista);

#endif // EJERCICIO8_H_INCLUDED
