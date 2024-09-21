#include <stdio.h>
#include <stdlib.h>
#include "ejercicio6.h"

void delegacion(int chinos){
    if (chinos == 1){
        printf("(-.-)");
    } else {
        printf("(-.");
        delegacion(chinos - 1);
        printf(".-)");
    }
}
