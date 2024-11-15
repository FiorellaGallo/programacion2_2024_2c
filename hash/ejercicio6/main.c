#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ejercicio6.h"
#include "../TADs/listas.h"
#include "../TADs/tabla_hash.h"
#include "validacion.h"

static const int TAMANIO_MAXIMO = 110;
static const int NRO_PRIMO = 107;

int hashFunctionNroPrimo(int a) {
    return (a % NRO_PRIMO);
}

int main (){

    bool MENU = true;
    char tecla;

    TablaHash Vacunados;
    Vacunados = th_crear(TAMANIO_MAXIMO, &hashFunctionNroPrimo);

    while(MENU){
        printf("              MENU: \n");
        printf("1. Cargar datos de los vacunados\n");
        printf("2. Buscar vacunados por fecha\n");
        printf("3. Mostrar tabla hash\n");
        printf("0. Salir\n");

        printf("Seleccione una opcion: ");
            scanf("%c", &tecla);
            fflush(stdin);
        if(tecla >= '0' && tecla <= '3'){
            if(tecla == '1'){
                system("cls");
                CargarDatos(Vacunados);
            }else if(tecla == '2'){
                system("cls");
                BuscarVacunadosPorFecha(Vacunados);

            }else if(tecla == '3'){
                system("cls");
                th_mostrar(Vacunados);
                system("pause");
            }else if(tecla == '0'){MENU = false;}
        }
        tecla = ' ';
        fflush(stdin);
        system("cls");
    }

    return 0;
}
