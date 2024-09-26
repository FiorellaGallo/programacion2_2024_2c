#ifndef EJERCICIO2_H_INCLUDED
#define EJERCICIO2_H_INCLUDED
#include "../TADs/pilas.h"

void cargar_pila(Pila *pila);
void buscar(Pila *pila,int clave);
void insertar(Pila *pila, int pos, int elemento);
void eliminar(Pila *pila, int clave);
void intercambiar(Pila *pila, int pos1, int pos2);
void duplicar(Pila *pila);
int contar(Pila *pila);
#endif // EJERCICIO2_H_INCLUDED
