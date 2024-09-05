#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "ejercicio10.h"


int main()
{
    int N = 0;
    int B = 0;
    int size = 0;

    printf("Ingrese un número explosivo:\n");
    scanf("%d",&N);
    while(fgetc(stdin) != '\n');
    printf("Ingrese un número bomba(menor al número de explosivos):\n");
    scanf("%d",&B);
    while(fgetc(stdin) != '\n');

    int* fragmentos = explosion(N,B,&size);

    printf("Fragmentos: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", fragmentos[i]);
    }
    printf("\n");

    free(fragmentos);

    return 0;
}
