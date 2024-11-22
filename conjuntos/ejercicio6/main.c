#include <stdio.h>
#include <stdlib.h>
#include "Ejercicio6.h"

void cargar_conjunto(Conjunto c, const char *nombre) {
    int cantidad;
    printf("Cargando conjunto %s:\n", nombre);
    printf("Ingrese la cantidad de elementos del conjunto %s: ", nombre);
    while (scanf("%d", &cantidad) != 1 || cantidad <= 0) {
        printf("Por favor, ingrese un numero entero positivo: ");
        while (getchar() != '\n');
    }

    for (int i = 1; i <= cantidad; i++) {
        int clave;
        printf("Elemento %d de %s: ", i, nombre);
        while (scanf("%d", &clave) != 1) {
            printf("Entrada invalida. Intente de nuevo: ");
            while (getchar() != '\n');
        }
        TipoElemento elem = te_crear(clave);
        if (!cto_agregar(c, elem)) {
            printf("Error: No se pudo agregar el elemento %d al conjunto %s.\n", clave, nombre);
        }
    }
}

int main() {
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();

    cargar_conjunto(A, "A");
    cargar_conjunto(B, "B");

    determinar_subconjunto_propio(A, B);

    return 0;
}
