#ifndef EJERCICIO2_H_INCLUDED
#define EJERCICIO2_H_INCLUDED
#include "../TADs/listas.h"

void mostrar_pre_orden(NodoArbol N);
bool ingresoEntero(int *n);
void cargar_subArbol(ArbolBinario A,NodoArbol N, int sa);
void cargar_arbol(ArbolBinario A);
Lista guardar_hojas(ArbolBinario A);
void buscar_hojas(NodoArbol nodo, Lista *hojas);
Lista guardar_nodos_interiores(ArbolBinario A);
void buscar_nodos_interiores(NodoArbol nodo, Lista *interiores);
Lista guardar_ocurrencias(ArbolBinario A);
void buscar_clave(NodoArbol *nodo,Lista *ocurrencias, int clave);
#endif // EJERCICIO2_H_INCLUDED
