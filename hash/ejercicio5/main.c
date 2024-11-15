#include <stdio.h>
#include <stdlib.h>
#include "ejercicio5.h"
#include "../TADs/arbol-avl.h"
#include "../TADs/tabla_hash.h"

int validar_entrada(char *mensaje, int min, int max) {
    char entrada[20];
    int numero;
    int es_valido;

    do {
        es_valido = 1;
        numero = 0;

        printf("%s", mensaje);
        scanf("%s", entrada);

        for (int i = 0; i < strlen(entrada); i++) {
            if (!isdigit(entrada[i])) {
                es_valido = 0;
                printf("Entrada invalida. Por favor, ingrese un numero valido.\n");
                break;
            }

            int digito = entrada[i] - '0';
            numero = numero * 10 + digito;

            if (numero > max) {
                es_valido = 0;
                printf("Por favor, ingrese un numero entre %d y %d.\n", min, max);
                break;
            }
        }

        if (es_valido && (numero < min || numero > max)) {
            es_valido = 0;
            printf("Por favor, ingrese un numero entre %d y %d.\n", min, max);
        }

    } while (!es_valido);

    return numero;
}


int funcion_hash(int clave, int tamano_tabla) {
    return clave % tamano_tabla;
}

int main() {
    int num_claves, repeticiones, rango_min, rango_max, INT_MAX = 2000;

    num_claves = validar_entrada("Ingrese el numero de claves a generar (1-2000): ", 1, 2000);
    repeticiones = validar_entrada("Ingrese el numero de repeticiones: ", 1, INT_MAX);
    rango_min = validar_entrada("Ingrese el rango minimo de claves: ", 1, INT_MAX);
    rango_max = validar_entrada("Ingrese el rango maximo de claves: ", rango_min, INT_MAX);

    int *claves = malloc(num_claves * sizeof(int));
    ArbolAVL arbol_avl = avl_crear();
    TablaHash tabla_hash = th_crear(num_claves, funcion_hash);

    srand(time(NULL));
    for (int i = 0; i < num_claves; i++) {
        claves[i] = rango_min + rand() % (rango_max - rango_min + 1);
        TipoElemento elemento = te_crear(claves[i]);
        avl_insertar(arbol_avl, elemento);
        th_insertar(tabla_hash, elemento);
    }

    double tiempo_promedio_avl = tiempo_busqueda_avl(arbol_avl, claves, num_claves, repeticiones);
    double tiempo_promedio_hash = tiempo_busqueda_tabla_hash(tabla_hash, claves, num_claves, repeticiones);


    printf("Tiempo promedio de acceso en AVL: %f segundos\n", tiempo_promedio_avl);
    printf("Tiempo promedio de acceso en Tabla Hash: %f segundos\n", tiempo_promedio_hash);


    if (tiempo_promedio_avl < tiempo_promedio_hash) {
        printf("Conclusion: El AVL fue mas rapido en promedio.\n");
    } else {
        printf("Conclusion: La Tabla Hash fue mas rapida en promedio.\n");
    }

    free(claves);

    return 0;
}
