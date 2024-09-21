#include <stdio.h>
#include <stdlib.h>
#include "../TADs/listas.h"
#include "../TADs/tipo_elemento.h"
#include <time.h>

void cargar_listas(Lista* L){
    int num;
    char c;

    while(1){
        if(scanf("%d",&num) == 1){
            TipoElemento X = te_crear(num);
            l_agregar(L, X);
        }else{
            scanf("%c",&c);
            if(c == '*'){
                break;
            }else{
                printf("Entrada no válida.Solo se permiten números.Intente nuevamente:\n");
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }
    }
}

Lista buscador(Lista* L1, Lista* L2) {
    int i, j;
    Lista L3 = l_crear();

    for (i = 1; i <= l_longitud(L1); i++) {
        int encontrado = 0;
        TipoElemento X1 = l_recuperar(L1, i);

        for (j = 1; j <= l_longitud(L2); j++) {
            TipoElemento X2 = l_recuperar(L2, j);

            if (X1->clave == X2->clave) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            l_agregar(L3, X1);
        }
    }
    printf("\n");
    l_mostrar(L3);
    return L3;
}

Lista valoresComunes(Lista* L1, Lista* L2) {
    int i, j;
    Lista L3 = l_crear();

    for (i = 1; i <= l_longitud(L1); i++) {
        int encontrado = 0;
        TipoElemento X1 = l_recuperar(L1, i);

        for (j = 1; j <= l_longitud(L2); j++) {
            TipoElemento X2 = l_recuperar(L2, j);

            if (X1->clave == X2->clave) {
                l_agregar(L3, X1);
            }
        }
    }
    if(l_longitud(L3)== 0){
        printf("\n No se encontraron valores en común\n");
    }else{
        printf("\n");
        l_mostrar(L3);
        return L3;
    }
}

float promedioPorLista(Lista* L){
    TipoElemento X;
    Iterador ite;
    ite = iterador(L);
    float suma = 0;
    float promedio;

    while(hay_siguiente(ite)){
        X = siguiente(ite);
        suma = suma + X->clave;
    }
    promedio = suma / l_longitud(L);
    printf("%.2f\n",promedio);
    return promedio;
}

void maxValor(Lista* L){
    TipoElemento X;
    Iterador ite;
    ite = iterador(L);
    int mayor = 0;
    int pos = 1;
    int posMayor = 0;

    while(hay_siguiente(ite)){
        X = siguiente(ite);
        if (X->clave > mayor){
            mayor = X->clave;
            posMayor = pos;
        }
        pos++;
    }

    X = l_buscar(L,mayor);
    if (X != NULL) {
        printf("Valor máximo: %d Posición ordinal: %d \n",X->clave, posMayor);
    }
}

void minValor(Lista* L){
    TipoElemento X;
    Iterador ite;
    ite = iterador(L);
    int menor = 100;
    int pos = 1;
    int posMenor = 0;

    while(hay_siguiente(ite)){
        X = siguiente(ite);
        if (X->clave < menor){
            menor = X->clave;
            posMenor = pos;
        }
        pos++;
    }

    X = l_buscar(L,menor);
    if (X != NULL) {
        printf("Valor mínimo: %d Posición ordinal: %d \n",X->clave, posMenor);
    }
}

Lista recursividad (Iterador ite,int num, Lista L3){
    TipoElemento X;

    if(!hay_siguiente(ite)){
        if(l_es_vacia(L3)){
            printf("No hay ningún múltiplo de %d en la lista\n",num);
        }else{
          l_mostrar(L3);

        }
         return L3;
    }

    X = siguiente(ite);
    int resto = (X->clave) % num;
    if (resto == 0){
            l_agregar(L3,X);

    }
    recursividad(ite,num,L3);
}

void multiplo(Lista* L, int num){
    Iterador ite;
    ite = iterador(L);
    Lista L3 = l_crear();
    recursividad(ite,num,L3);
}

Lista numAzar(Lista* L, int num){
    TipoElemento X ;
    srand(time(NULL));
    int longitud = l_longitud(L);
    int AUX = 0;

    for(int i = longitud; i < num + longitud;i++){
        AUX = (rand()%200);
        while(l_buscar(L,AUX) != NULL){
            AUX =(rand()%200);
        }
        X = te_crear(AUX);
        l_agregar(L,X);

    }
    l_mostrar(L);
    return(L);

}



