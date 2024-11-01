#ifndef EJERCICIO4_H_INCLUDED
#define EJERCICIO4_H_INCLUDED
#include "../TADs/arbol-binario.h"
#include "../TADs/listas.h"

void cargar_arbol_n_ario(ArbolBinario A);
void anchura(ArbolBinario A);
int cantidad_hojas(ArbolBinario A);
bool comparar(ArbolBinario B, ArbolBinario C);
void busqueda_padre(ArbolBinario A, int clave);
Lista hermanos(ArbolBinario A, int clave);
#endif // ejercicio4
