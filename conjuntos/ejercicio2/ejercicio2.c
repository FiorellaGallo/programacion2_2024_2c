#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"
#include "../TADs/conjuntos.h"
#include "../TADs/listas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio2.h"

void acciones(Conjunto ConjuntoA, Conjunto ConjuntoB, Conjunto Resu){
    int accion;

    do {
            printf("\n1: Union / 2: Interseccion / 3: Diferencia / 4: Pertenencia / 0: Salir\n");
            accion = leer_entero("Seleccione una opcion", 0, 4);

            switch (accion) {
                case 1:
                    Resu = cto_union(ConjuntoA, ConjuntoB);
                    printf("Resultado de la union:\n");
                    cto_mostrar(Resu);
                    break;
                case 2:
                    Resu = cto_interseccion(ConjuntoA, ConjuntoB);
                    printf("Resultado de la interseccion:\n");
                    cto_mostrar(Resu);
                    break;
                case 3:
                    Resu = cto_diferencia(ConjuntoA, ConjuntoB);
                    printf("Resultado de la diferencia:\n");
                    cto_mostrar(Resu);
                    break;
                case 4: {
                    int clave = leer_entero("Ingrese una clave a buscar", 0, 1000);
                    if (cto_pertenece(ConjuntoA, clave)) {
                        printf("\nLa clave %d pertenece al Conjunto A\n", clave);
                    }
                    if (cto_pertenece(ConjuntoB, clave)) {
                        printf("\nLa clave %d pertenece al Conjunto B\n", clave);
                    }
                    if (!cto_pertenece(ConjuntoA, clave) && !cto_pertenece(ConjuntoB, clave)) {
                        printf("\nLa clave %d no pertenece a ninguno de los Conjuntos.\n", clave);
                    }
                    break;
                }
            }
        } while (accion != 0);
}
