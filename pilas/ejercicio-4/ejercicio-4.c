#include <stdio.h>
#include <stdlib.h>
#include "../TADs/pilas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio-4.h"


void conversion (int num, Pila P1,int base){
    int cociente = 0;
    int resto = 0;

    if(p_es_llena(P1)){
        printf("El número que se ingreso supera el tamaño de la pila al convertirlo a base %d\n",base);
        printf("Aumente el tamaño de la pila en la implementación del TADs\n");
        exit(1);
    }

    if(num >= base){

        resto = num % base;
        cociente = num / base;
        TipoElemento X = te_crear(resto);

        p_apilar(P1,X);
        conversion(cociente, P1, base);

    }else{
        TipoElemento ultimo = te_crear(num);
        p_apilar(P1,ultimo);
        hexadecimal(P1,base);
    }


}

void hexadecimal(Pila P1, int base){
    char *numHexa = (char *)malloc(50 * sizeof(char));
    int valor = 0;
    int i = 0;

    while (!p_es_vacia(P1)) {
        TipoElemento valor = p_desapilar(P1);

        if (valor->clave >= 10) {

            numHexa[i++] = valor->clave - 10 + 'A';

        }else{
           numHexa[i++] = valor->clave  + '0';

        }

    }
    numHexa[i] = '\0';
    printf("Valor expresado en una base de %d : %s\n",base,numHexa);
 }

 /*COMPLEJIDAD ALGORITMICA*/
/*La complejidad de la siguiente solución es de Orden lineal * logaritmo (O(n log n)).
    En la primera función, se observa una recursividad dentro de la condición if, donde N se divide por la base
    repetidamente mientras NUM sea mayor que la base. Esto implica que la función es de orden logarítmico (O(log n)).
    La segunda función contiene un bucle while que itera a lo largo de la pila, lo que le otorga una complejidad de
    orden lineal (O(n)).*/








