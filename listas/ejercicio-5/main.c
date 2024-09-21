#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "../TADs/listas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio5.h"

bool validacionPolinomio(char *polinomio){

    fgets(polinomio, 50, stdin);

    for(int i=0; i<strlen(polinomio); i++){
        if(polinomio[i] == ' '){
            printf("Ingrese un polinomio con valores numericos enteros!\n");
          return false;
        };
        i++;
    };
    return true;
};


bool validacionNumero(double *x){

    char ingreso[50];

    if(fgets(ingreso, sizeof(ingreso), stdin) != NULL){

        for(int i=0; ingreso[i] != '\0' && ingreso[i] != '\n'; i++) {
            if (!isdigit(ingreso[i])) {
                if(ingreso[i] != '-'){
                    printf("Ingrese unicamente valores numericos!\n");
                    return false;
                }
            };
            i++;
        };
    };

    *x =atoi(ingreso);

    return true;
};

bool validacionIntervalo(double *intervalo){


    scanf("%lf", intervalo);

    if(*intervalo <= 0){
        printf("el intervalo debe ser un numero positivo\n");
        return false;
    };


    return true;
};



int main(){
    Lista lista_coef = l_crear();
    Lista lista_exponentes = l_crear();
    char *polinomio = malloc(50*sizeof(char));
    double x;
    double intervalo;
    bool validacion=false;



    do{
        printf("Ingrese el polinomio que desea calcular:");
        validacion = validacionPolinomio(polinomio);

        printf("Ingrese un valor para X:");
        validacion = validacionNumero(&x);

    }while(!validacion);

    if(!validacion){
        printf("error");
        return 1;
    }

    guardar_coeficientes(lista_coef, lista_exponentes,polinomio);
    calcular_x(x, lista_coef, lista_exponentes);



    validacion=false;


    do{
        printf("Ingrese un valor para generar un rango de valores para x: \n");
        validacion = validacionNumero(&x);

    }while(!validacion);


    validacion=false;

    do{
        printf("Ingrese un valor de intervalo: \n");
        validacion = validacionIntervalo(&intervalo);
    } while (!validacion);


    rango_valores(x, intervalo, lista_coef, lista_exponentes);


    free(polinomio);
    free(lista_coef);
    free(lista_exponentes);

    return 0;
}
