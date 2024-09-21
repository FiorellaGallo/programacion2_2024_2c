#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include "../TADs/listas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio5.h"

void guardar_coeficientes(Lista lista_coef, Lista lista_exponentes, char *polinomio){

    int i = 0;
    int clave = 0;
    int signo = 1;
    int coeficiente = 0;
    int exponente = 0;
    char aux[10];
    int i_aux = 0;


    while(polinomio[i] != '\0'){


        if (isdigit(polinomio[i])){

            if(i > 0 && polinomio[i-1] == '-'){
                signo = -1;
            };

            i_aux = 0;
            while (isdigit (polinomio [i])){
                aux[i_aux] = polinomio[i];
                i_aux++;
                i++;
            };
            aux[i_aux] = '\0';

            coeficiente = atoi(aux) * signo;
            TipoElemento elemento_coef = te_crear(coeficiente);
            l_agregar(lista_coef, elemento_coef);

            if(polinomio[i] == 'x'){

                exponente = 1;
                TipoElemento elemento_exp = te_crear(exponente);
                l_agregar(lista_exponentes, elemento_exp);
                i++;

            }else{
                exponente = 0;
                TipoElemento elemento_exp = te_crear(exponente);
                l_agregar(lista_exponentes, elemento_exp);
                i++;
            };

            clave++;
        }else {
            i++;
        };

        signo = 1;

    };

};


void calcular_x(double x, Lista lista_coef, Lista lista_exponentes){

    double total = 0;
    Iterador iter_coef = iterador(lista_coef);
    Iterador iter_expo = iterador(lista_exponentes);
    TipoElemento coef_actual = siguiente(iter_coef);
    TipoElemento expo_actual = siguiente(iter_expo);

    while(hay_siguiente(iter_coef)){

        if(expo_actual->clave == 1){
            total += (x * expo_actual->clave)*coef_actual->clave;

        }else{
            total += coef_actual->clave;
        };

        coef_actual = siguiente(iter_coef);
        expo_actual = siguiente(iter_expo);
    };

    if(expo_actual->clave == 1){
        total += (x * expo_actual->clave)*coef_actual->clave;

    }else{
        total += (coef_actual->clave);

    };

    printf("Resultado de f(%.1lf): %.1lf\n", x, total);

    free(iter_coef);
    free(iter_expo);
}

void rango_valores(double x, double intervalo, Lista lista_coef, Lista lista_exponentes){

    int y;
    int mayor;
    int menor;

    if(x > 0){
        y = -x;
        mayor = x;
        menor = y;
    }else{
        y = abs(x);
        mayor = y;
        menor = x;
    };

    while(menor <= mayor){
        calcular_x(menor, lista_coef, lista_exponentes);
        menor += intervalo;
    }


}
