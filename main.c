#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int division(int m, int n, float *resto){
    if(abs(m) < abs(n)){
        *resto = m;
        return 0;
    }
    return 1 + division(m - n, n, resto);
}


int main()
{
    int m, n, cociente, signo;
    float resto;
    float resultado_decimal = 0;

    while (m != 0)
    {
        printf("\n\nSi desea salir del sistema, ingrese 0 en el dividendo.\n");
        printf("Ingrese el dividendo: ");
        scanf("%d", &m);
        fflush(stdin);

        if (m == 0) { printf("\nSaliste del sistema."); return 0; }

        printf("Ingrese el divisor: ");
        scanf("%d", &n);

        if(n == 0){
            printf("\nError al dividir por 0");
            printf("\n\nSi desea salir del sistema, ingrese 0 en el dividendo.\n");
            printf("Ingrese el dividendo: ");
            scanf("%d", &m);
            fflush(stdin);

            if (m == 0) { printf("\nSaliste del sistema."); return 0; }

            printf("Ingrese el divisor: ");
            scanf("%d", &n);
        }

        signo = (m < 0) ^ (n < 0) ? -1 : 1;

        cociente = (division(abs(m), abs(n), &resto));
        cociente *= signo;

        if (resto > 0){
            if (signo < 0){
                resultado_decimal = cociente - (float)resto / abs(n);
                printf("\nRESULTADO = %.6f", resultado_decimal);
            } else {
                resultado_decimal = cociente + (float)resto / abs(n);
                printf("\nRESULTADO = %.6f", resultado_decimal);
            }
        } else {
            printf("\nRESULTADO: %d", cociente);
        }
    }

    return 0;
}
