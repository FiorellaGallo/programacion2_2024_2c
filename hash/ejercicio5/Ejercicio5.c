#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../TADs/arbol-avl.h"
#include "../TADs/tabla_hash.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio5.h"

#define ITERACIONES_INTERNAS 1000

double tiempo_busqueda_avl(ArbolAVL arbol, int *claves, int num_claves, int repeticiones) {
    struct timespec inicio, fin;
    double tiempo_total = 0.0;

    for (int r = 0; r < repeticiones; r++) {
        for (int i = 0; i < num_claves; i++) {
            clock_gettime(CLOCK_MONOTONIC, &inicio);
            for (int j = 0; j < ITERACIONES_INTERNAS; j++) {
                avl_buscar(arbol, claves[i]);
            }
            clock_gettime(CLOCK_MONOTONIC, &fin);
            // Calcular el tiempo en microsegundos
            double duracion = (fin.tv_sec - inicio.tv_sec) * 1e6 + (fin.tv_nsec - inicio.tv_nsec) / 1000.0;
            tiempo_total += duracion;
        }
    }
    return tiempo_total / (num_claves * repeticiones * ITERACIONES_INTERNAS);
}


double tiempo_busqueda_tabla_hash(TablaHash tabla, int *claves, int num_claves, int repeticiones) {
    struct timespec inicio, fin;
    double tiempo_total = 0.0;

    for (int r = 0; r < repeticiones; r++) {
        for (int i = 0; i < num_claves; i++) {
            clock_gettime(CLOCK_MONOTONIC, &inicio);
            for (int j = 0; j < ITERACIONES_INTERNAS; j++) {
                th_recuperar(tabla, claves[i]);
            }
            clock_gettime(CLOCK_MONOTONIC, &fin);
            // Calcular el tiempo en microsegundos
            double duracion = (fin.tv_sec - inicio.tv_sec) * 1e6 + (fin.tv_nsec - inicio.tv_nsec) / 1000.0;
            tiempo_total += duracion;
        }
    }
    return tiempo_total / (num_claves * repeticiones * ITERACIONES_INTERNAS);
}
