#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ejercicio3.h"

int calcularFibonacci(int n) {
    if(n > 45) {
        printf("El valor maximo permitido es 45\n");
        return -1;
    }
    if (n <= 1) {
        return n;
    } else {
        return calcularFibonacci(n-1) + calcularFibonacci(n-2);
    }
}

