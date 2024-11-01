#ifndef ejercicio8_h
#define ejercicio8_h
#include <stdio.h>
#include "../TADs/nodo.h"
#include "../TADs/arbol-binario.h"

int alturaArbol(NodoArbol nodo);
int nivelNodo(NodoArbol nodo, int clave, int nivelActual);
void listarNodosInternos(NodoArbol nodo);
int verificarHojas(NodoArbol nodo, int *nivelHoja, int nivelActual);
bool hojasMismoNivel(NodoArbol raiz);


#endif //ejercicio8_h
