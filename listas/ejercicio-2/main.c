#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../TADs/tipo_elemento.h"
#include "../TADs/listas.h"
#include "ejercicio_2.h"

int validaciones(){
    int num;
    printf("Ingrese un número: ");
    int resultado = scanf("%d", &num);

    if (resultado == 0){
        printf("Se ha ingresado un caracter\n");
        while(fgetc(stdin) != '\n');
        validaciones(num);
    }else{
         int caracter = fgetc(stdin);
         if (caracter != '\n' && caracter != EOF) {
            printf("Se han ingresado caracteres\n");
            while (fgetc(stdin) != '\n');
            validaciones(num);
        }
    }
    return num;

}

int main(){
    TipoElemento X;
    Lista* L1 ;
    Lista* L2;
    int opcion;

    L1 = l_crear();
    L2 = l_crear();
    printf("Las lista fue creada correctamente\n");

    printf("Ingrese los números de la primera lista (Pulse * para finalizar):\n");
    cargar_listas(L1);

    printf("Ingrese los números de la segunda lista (Pulse * para finalizar):\n");
    cargar_listas(L2);

    l_mostrar(L1);
    l_mostrar(L2);

    printf("\n");
    if(!l_es_vacia(L1)||!l_es_vacia(L2)){

        do{
            printf("\n--------------MENÚ DE OPCIONES----------------\n");
            printf("1.Lista de valores de L1 que no están en L2\n");
            printf("2.Lista de valores de L2 que no están en L1\n");
            printf("3.Valores comunes en ambas listas(L1 y L2)\n");
            printf("4.Promedio de ambas listas\n");
            printf("5.Valor máximo de ambas listas y su posición ordinal\n");
            printf("6.Valor mínimo de ambas listas y su posición ordinal\n");
            printf("7.Nueva lista con los múltiplos\n");
            printf("8.Lista con números al azar únicos\n");
            printf("9.Salir\n");
            printf("\n\nIntroduzca una opción(1-9): ");
            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    buscador(L1,L2);
                    break;

                case 2:
                    buscador(L2,L1);
                    break;

                case 3:
                    valoresComunes(L1,L2);
                    break;

                case 4:
                    printf("\nPromedio de la primera lista: ");
                    promedioPorLista(L1);
                    printf("\nPromedio de la segunda lista: ");
                    promedioPorLista(L2);
                    break;

                case 5:
                    maxValor(L1);
                    maxValor(L2);
                    break;

                case 6:
                    minValor(L1);
                    minValor(L2);
                    break;

                case 7:
                    int num = validaciones();
                    multiplo(L1, num);
                    break;

                case 8:
                    int cantidad = 0;
                    printf("Ingrese la cantidad de número al azar deseados: ");
                    scanf("%d",&cantidad);
                    if (cantidad < 0 ) {
                        printf("La cantidad ingresada es un número negativo\n");
                        return;
                    }
                    numAzar(L2,cantidad);
                    break;

            }
        }while (opcion != 9);
    }else{
        printf("Las listas están vacias\n\n");
    }

    return 0;

}
