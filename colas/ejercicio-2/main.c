#include <stdio.h>
#include <stdlib.h>
#include "../TADs/colas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio2.h"

int main() {
    Cola C1 = c_crear();
    cargar_cola(C1);
    int opcion;
    TipoElemento elemento;
    unsigned int posicion;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Verificar si un elemento esta en la cola\n");
        printf("2. Colarse en una posicion\n");
        printf("3. Eliminar todas las apariciones de un elemento\n");
        printf("4. Contar elementos en la cola\n");
        printf("5. Copiar la cola\n");
        printf("6. Invertir la cola\n");
        printf("7. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingresa la clave del elemento a buscar: ");
                elemento = te_crear(0);
                scanf("%d", &elemento->clave);
                if (elementoEnCola(C1, elemento)) {
                    printf("El elemento con clave %d está en la cola.\n", elemento->clave);
                } else {
                    printf("El elemento con clave %d no está en la cola.\n", elemento->clave);
                }
                break;

            case 2:
                printf("Ingresa la clave del nuevo elemento: ");
                elemento = te_crear(0);
                scanf("%d", &elemento->clave);
                printf("Ingresa la posición donde colarse: ");
                scanf("%u", &posicion);
                C1 = colarElemento(C1, elemento, posicion);
                printf("Elemento con clave %d se ha agregado en la posición %u.\n", elemento->clave, posicion);
                c_mostrar(C1);
                break;

            case 3:
                printf("Ingresa la clave del elemento a eliminar: ");
                elemento = te_crear(0);
                scanf("%d", &elemento->clave);
                C1 = eliminarApariciones(C1, elemento);
                c_mostrar(C1);
                break;

            case 4:
                printf("Total de elementos en la cola: %d\n", contarElementos(C1));
                break;

            case 5:
                {
                    Cola cola_copia = copiarCola(C1);
                    printf("La cola ha sido copiada exitosamente.\n");
                    c_mostrar(cola_copia);
                }
                break;

            case 6:
                {
                    Cola cola_invertida = invertirCola(C1);
                    printf("La cola ha sido invertida exitosamente.\n");
                    c_mostrar(cola_invertida);
                }
                break;

            case 7:
                printf("Salida exitosa.\n");
                break;

            default:
                printf("Opción invalida. Elige nuevamente.\n");
        }
    } while (opcion != 7);

    return 0;
}
