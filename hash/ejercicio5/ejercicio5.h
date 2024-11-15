#ifndef ejercicio5_h
#define ejercicio5_h
#include <stdio.h>
#include "../TADs/arbol-avl.h"
#include "../TADs/tabla_hash.h"

double tiempo_busqueda_avl(ArbolAVL arbol, int *claves, int num_claves, int repeticiones);
double tiempo_busqueda_tabla_hash(TablaHash tabla, int *claves, int num_claves, int repeticiones);

#endif //ejercicio5_h
