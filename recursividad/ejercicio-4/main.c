#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ejercicio4.h"

int validacion(char dato[]) {
    for (int i = 0; dato[i] != '\0'; i++) {
        if (i == 0 && dato[i] == '-') {
            continue;
        }

        if (!isdigit(dato[i])) {
            return 0;
        }
    }
    return 1;
}

int main(){
    char m_char[50], n_char[50];
    int m = -1, n, cociente, signo;
    float resto;
    float resultado_decimal = 0;

    while (m != 0){

         printf("\n\nSi desea salir del sistema, ingrese 0 en el dividendo.\n");

        do {
            printf("Ingrese el dividendo (0 para salir): ");
            scanf("%s", m_char);

            if (validacion(m_char)) {
                m = atoi(m_char);
            } else {
                printf("\nDato incorrecto en el dividendo.\n\n");
                m = -1;
            }
        } while (m == -1);

        if (m == 0) {
            printf("\nSaliste del sistema.");
            return 0;
        }

        do {
            printf("Ingrese el divisor: ");
            scanf("%s", n_char);

            if (validacion(n_char)) {
                n = atoi(n_char);
                if (n == 0) {
                    printf("Error: No se puede dividir por 0.\n");
                }
            } else {
                printf("Dato incorrecto en el divisor.\n");
                n = 0;
            }
        } while (n == 0);

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
