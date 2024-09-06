#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include"ejercicio9.h"

/*Para este ejercicio se utilizo recursión indirecta y
recursión directa en la función "multiplicacionYSustraccion"*/
int divisiblePor7(int n){
    int resultado;

    //Caso base
    if(n < 70){
        if(n % 7 == 0 || n == 0){
            resultado = 1;
        }else{
            resultado = 0;
        }
    }else{
       resultado = multiplicacionYSustraccion(n);

    }
    return resultado;
};

int multiplicacionYSustraccion (int n){
    int producto, nuevoNumero, diferencia, ultimoDigito, resultado;
    //obtengo el producto del último dígito por 2
    ultimoDigito = n % 10;
    producto = ultimoDigito * 2;

    // Elimino el último dígito y realizo una sustracción
    nuevoNumero = n/10;
    diferencia = nuevoNumero - producto;

    //Llamada recursiva
    if(diferencia >= 70){
        resultado = multiplicacionYSustraccion(diferencia);
    }else{
        resultado = divisiblePor7(diferencia);
    }
    return resultado;
};
