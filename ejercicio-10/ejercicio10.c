#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "ejercicio10.h"


int* explosion(int N, int B, int* size) {
    int* fragmentos = (int*)malloc(N * sizeof(int));
    *size = 0;
    auxiliar(N, B, fragmentos, size);

    return fragmentos;

}

void auxiliar(int N, int B,int* fragmentos, int* size) {

    if(N <= B){
         fragmentos[(*size)++] = N;
    }else{
        int num1= N/B;
        int num2 = N - num1;

        auxiliar(num1, B,fragmentos, size);
        auxiliar(num2, B, fragmentos,size);
    }

    return fragmentos;
}














