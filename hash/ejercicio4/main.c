#include <stdio.h>
#include <stdlib.h>
#include "../TADs/tabla_hash.h"
#include "ejercicio4.h"
#include "../TADs/tipo_elemento.h"




int main()
{
    int opcion;
    TablaHash tabla;

    do{
        printf("SELECCIONE LA OPCION QUE DESEA REALIZAR\n");
        printf("1. cargar alumnos a la tabla\n");
        printf("2. eliminar un alumno\n");
        printf("3. agregar un alumno\n");
        printf("4. salir\n");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                tabla = cargar_tabla_nueva();
                break;
            case 2:
                eliminar(tabla);
                break;
            case 3:
                tabla = cargar_alumnos(tabla);
                break;

        }

    }while(opcion != 4);



    return 0;
}
