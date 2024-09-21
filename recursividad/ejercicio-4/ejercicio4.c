#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ejercicio4.h"

float division(int m, int n, float *resto){
    if(abs(m) < abs(n)){
        *resto = m;
        return 0;
    }
    return 1 + division(m - n, n, resto);
}
