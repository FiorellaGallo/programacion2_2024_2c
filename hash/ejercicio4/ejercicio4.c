#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../TADs/listas.h"
#include "ejercicio4.h"
#include "../TADs/tipo_elemento.h"
#include "../TADs/tabla_hash.h"

static int TAMANIO_MAXIMO;

struct RegistroAlumno{
    int legajo;
    char apellido[50];
    char nombre[50];
    char direccion[50];
    char telefono[20];
};

typedef  struct RegistroAlumno *Alumno;


int hash_funtion(int clave){
    return (clave%TAMANIO_MAXIMO);
}


TipoElemento ingresar_alumno(){

    char c;
    Alumno alumno= malloc(sizeof(struct RegistroAlumno));

    printf("Ingrese el legajo: ");
    scanf("%d", &alumno->legajo);
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Ingrese el apellido: ");
    fgets((alumno->apellido), sizeof(alumno->apellido),stdin);
    printf("Ingrese el nombre: ");
    fgets(alumno->nombre, sizeof(alumno->nombre),stdin);
    printf("Ingrese la direccion: ");
    fgets(alumno->direccion, sizeof(alumno->direccion),stdin);
    printf("Ingrese el numero de telefono: ");
    fgets(alumno->telefono, sizeof(alumno->telefono),stdin);


    TipoElemento alumno_cargado= te_crear_con_valor(alumno->legajo, alumno);

    return alumno_cargado;
}

TablaHash cargar_tabla_nueva(){

    int tamanio;
    printf("Ingrese el tamaño maximo de la lista: ");
    scanf("%d", &tamanio);
    TAMANIO_MAXIMO = tamanio;

    TablaHash tabla = th_crear(TAMANIO_MAXIMO,&hash_funtion);
    tabla = cargar_alumnos(tabla);
    return tabla;
}

TablaHash cargar_alumnos(TablaHash tabla){

    char entrada;

    while(entrada != 46){

        TipoElemento alumno = ingresar_alumno();
        th_insertar(tabla, alumno);

        printf("INGRESE UN . (punto) SI DESEA NO CARGAR MAS ALUMNOS\n");
        scanf("%c", &entrada);
    };

    th_mostrar(tabla);
    return tabla;
}

void eliminar(TablaHash tabla){

    int clave;
    printf("Ingrese la clave que desea eliminar: ");
    scanf("%d", &clave);
    bool eliminacion = th_eliminar(tabla, clave);

    if(!eliminacion){
         printf("NO SE PUDO ELIMINAR CORRECTAMENTE\n");
        return;
    };
    printf("ELIMINACION HECHA\n");
    th_mostrar(tabla);
}
