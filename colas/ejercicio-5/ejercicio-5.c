#include <stdio.h>
#include <stdlib.h>
#include "../TADs/tipo_elemento.h"
#include "../TADs/colas.h"
#include "ejercicio-5.h"

Cola intercambiar(Cola C, Cola aux){
    TipoElemento X;
    while(!c_es_vacia(C)){
      X = c_desencolar(C);
         c_encolar(aux,X);

    }
    return aux;
}

bool existeNumero(Cola C, int num){
TipoElemento X;
Cola aux = c_crear();
bool existe = false;

    while (!c_es_vacia(C)){
    X = c_desencolar(C);

    if (X->clave == num){
        existe = true;
    }
    c_encolar(aux,X);

    }

    C = intercambiar(aux,C);

    return existe;
}






void carga (Cola C1){

    int num;
    char c;


    printf("Ingrese un número para cargar a la cola (Ingrese una letra para finalizar la cola.): ");

    while(scanf("%d", &num) == 1){

    if (existeNumero(C1, num)){
        printf("El número ingresado ya existe en la cola \n");

        carga(C1);
    }
        TipoElemento X = te_crear(num);
        c_encolar(C1, X);
        while ((c = getchar()) != '\n' && c != EOF);
    };

    while ((c = getchar()) != '\n' && c != EOF);
    printf("Cola cargada!\n");
    c_mostrar(C1);
    total(C1);

}


void total(Cola C1){
    Cola colaAux = c_crear();
    Cola C2 = c_crear();
    TipoElemento X;
    int totalElementos = 0;

    while(!c_es_vacia(C1)){
        X = c_desencolar(C1);
        totalElementos++;
         c_encolar(colaAux,X);
         c_encolar(C2,X);
    }
    divisores(colaAux,C2,totalElementos);
}




void divisores(Cola cola,Cola C2, int totalElementos){
    Cola colaAux1 = c_crear();
    Cola colaAux2 = c_crear();
    TipoElemento X;
    TipoElemento X2;
    int cantidad = 0;

    for(int i = 1; i <= totalElementos; i ++){
        X = c_desencolar(cola);
        c_encolar(colaAux1,X);


        while(!c_es_vacia(C2)){
            X2 = c_desencolar(C2);
            if(X2->clave % X->clave){
                cantidad++;
            }
            c_encolar(colaAux2,X2);
        }
        if(cantidad == totalElementos){
           printf("El divisor total es : %d\n",X->clave);
        }
        else if (totalElementos / 2 >= cantidad){
            printf("El divisor parcial es : %d\n",X->clave);
        }
        C2 = intercambiar(colaAux2,C2);
        cantidad = 0;

    }

}
//LA COMPLEJIDAD ALGORÍTMICA
/*La solución al problema es de orden cuadrática O(n^2) porque se utilizaron dos bucles iterativos
de forma anidada*/


