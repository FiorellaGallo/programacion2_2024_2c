#ifndef EJERCICIO9_H_INCLUDED
#define EJERCICIO9_H_INCLUDED
#include "../TADs/arbol-avl.h"

void mostrar_pre_orden(NodoArbol N);
bool ingresoEntero(int *n);
void cargar_subArbol(ArbolBinario A,NodoArbol N, int sa);
void cargar_arbol(ArbolBinario A);
void agregar_a_avl(ArbolAVL a_avl, NodoArbol nodo);
ArbolAVL pasar_a_avl(ArbolBinario A);

#endif // EJERCICIO9_H_INCLUDED
