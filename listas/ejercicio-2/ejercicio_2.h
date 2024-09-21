#ifndef EJERCICIO_2_H_INCLUDED
#define EJERCICIO_2_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

void cargar_listas(Lista* L);
Lista buscador(Lista* L1, Lista* L2);
Lista valoresComunes(Lista* L1, Lista* L2);
float promedioPorLista(Lista* L);
void maxValor(Lista* L);
void minValor(Lista* L);
void multiplo(Lista* L, int num);
Lista numAzar(Lista* L,int cantidad);


#endif
