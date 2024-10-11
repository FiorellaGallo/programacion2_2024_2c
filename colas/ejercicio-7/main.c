#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../TADs/colas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio7.h"

void cargar(Cola cola){
    int minutos;
    char c;

    printf("Ingrese el tiempo que necesita el cliente para ser atendido o un valor no numerico para finalizar la carga de clientes: ");

    while(scanf("%d",&minutos) == 1 && !c_es_llena(cola)){
        if(minutos >= 0){
            TipoElemento min = te_crear(minutos);
            c_encolar(cola, min);
        }
        else {
            printf("\nError, minutos en negativo.\n");
        }
        printf("Ingrese el tiempo que necesita el cliente o un valor no numerico para finalizar la carga de clientes: ");
        while (fgetc(stdin) != '\n');
    }
    while (fgetc(stdin) != '\n');
}


int main()
{
    int opcion = 1;

    while(1){

        int tiempo;

        Cola cola1 = c_crear();
        Cola cola2 = c_crear();
        Cola cola3 = c_crear();

        printf("Cargar cola1: \n");
        cargar(cola1);

        printf("\nCargar cola2: \n");
        cargar(cola2);

        printf("\nCargar cola3: \n");
        cargar(cola3);

        printf("\nColas: \n");
        c_mostrar(cola1);
        c_mostrar(cola2);
        c_mostrar(cola3);

        printf("Ingrese el tiempo en el que sera atendido cada cliente: ");
        scanf("%d", &tiempo);
        while (fgetc(stdin) != '\n');

        clientes(cola1, cola2, cola3, tiempo);

        printf("\n\nIngrese 0 para salir o cualquier otra entrada para continuar: ");
        scanf("%d", &opcion);
        while(fgetc(stdin) != '\n');

        if (opcion == 0){
            printf("\nSaliste del sistema.\n");
            break;
        } else {
            continue;
        }
    }

    return 0;
}
