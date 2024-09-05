#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include "ejercicio2.h"

int sumas_sucesivas(int m, int n){
    int total = 0;

    if(n > 0){
        total = m + sumas_sucesivas(m, n-1);
    }
    return total;
}



