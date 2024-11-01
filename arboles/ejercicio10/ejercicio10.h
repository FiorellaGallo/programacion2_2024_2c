#ifndef ejercicio10_h
#define ejercicio10_h
#include <stdio.h>
#include <stdlib.h>
#include "../TADs/arbol-avl.h"
#include "../TADs/arbol-binario-busqueda.h"
#include "../TADs/nodo.h"
#include "../TADs/tipo_elemento.h"

int altura(NodoArbol nodo);

void cargarArboles(ArbolAVL arbol_avl, ArbolBinarioBusqueda arbol_abb);

void comparar(int repeticiones);

#endif // ejercicio10_h
