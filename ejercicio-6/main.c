#include <stdio.h>
#include <stdlib.h>
#include "ejercicio6.h"

int main()
{
    int chinos;

    printf("\nIngrese el nivel de la delegación china que desea ver. Ingrese 0 para salir del sistema: ");
    scanf("%d", &chinos);
    fflush(stdin);

    if (chinos == 0) {printf("Saliste."); return 0;}

    while (chinos != 0){
        if(chinos > 50 || chinos < 1){
            printf("\nNivel de delegación fuera de rango, ingrese nuevamente (0 para salir del sistema): ");
            scanf("%d", &chinos);
            fflush(stdin);
        } else {
            printf("La delegación china de nivel %d se ve así: \n", chinos);
            delegacion(chinos);
            printf("\n\nIngrese el nivel de la delegación china que desea ver. Ingrese 0 para salir del sistema: ");
            scanf("%d", &chinos);
            fflush(stdin);
        }
        if (chinos == 0){
            printf("Saliste del sistema.");
            return 0;
        }
    }


    return 0;
}
