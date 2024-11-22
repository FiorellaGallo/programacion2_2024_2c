#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Ejercicio6.h"

bool es_subconjunto_propio(Conjunto A, Conjunto B) {
    if (cto_cantidad_elementos(A) >= cto_cantidad_elementos(B)) {
        return false;
    }

    for (int i = 1; i <= cto_cantidad_elementos(A); i++) {
        TipoElemento elem = cto_recuperar(A, i);
        if (!cto_pertenece(B, elem->clave)) {
            return false;
        }
    }

    return true;
}

void determinar_subconjunto_propio(Conjunto a, Conjunto b) {
    bool a_es_subconjunto_b = es_subconjunto_propio(a, b);
    bool b_es_subconjunto_a = es_subconjunto_propio(b, a);

    if (a_es_subconjunto_b && b_es_subconjunto_a) {
        printf("Error: Ambos conjuntos son iguales. Ninguno es subconjunto propio.\n");
    } else if (a_es_subconjunto_b) {
        printf("A es subconjunto propio de B.\n");
    } else if (b_es_subconjunto_a) {
        printf("B es subconjunto propio de A.\n");
    } else {
        printf("Ningun conjunto es subconjunto propio del otro.\n");
    }
}
