#ifndef ejercicio2_h
#define ejercicio2_h
#include <stdio.h>
#include "../TADs/colas.h"

void cargar_cola(Cola cola);
bool elementoEnCola(Cola cola, TipoElemento elemento);
Cola colarElemento(Cola cola, TipoElemento elemento, unsigned int posicion);
Cola eliminarApariciones(Cola cola, TipoElemento clave);
int contarElementos(Cola cola);
Cola copiarCola (Cola cola_original);
Cola invertirCola (Cola cola_original);

#endif //ejercicio2_h
