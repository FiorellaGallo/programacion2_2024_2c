#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../TADs/listas.h"
#include "../TADs/tabla_hash.h"
#include "../TADs/tipo_elemento.h"
#include "validacion.h"
#include "ejercicio6.h"

void CargarDatos(TablaHash Vacunados){
    TipoElemento X, P, R, T;
    Lista VacPorFecha;
    VacPorFecha = l_crear();
    const char s[2] = ",";
    char DNI[15], NomYApe[30],Fecha[15] ,*Datos, *v, *DNIVal, DatosVal[60];
    char PermitidosDNI[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
    int i, CodHash;
    bool NomCorrecto =false;
    Datos = calloc(60,sizeof(char));
    printf("(La fecha de vacunacion es desde el año 2020 hasta 2023)\n");
    printf("Ingrese la fecha de vacunacion con el formato dd/mm/yyyy:\n");
    gets(Fecha);
    fflush(stdin);

    //Validar fecha y generar el codigo hash
    CodHash = ValidarFecha(Fecha);

    while(CodHash == -1){
        printf("Fecha Invalida\n");
        printf("(La fecha de vacunacion es desde el año 2020 hasta 2023)\n");
        printf("Ingrese la fecha de vacunacion con el formato dd/mm/yyyy:\n");
        gets(Fecha);
        fflush(stdin);
        CodHash = ValidarFecha(Fecha);
    }


    printf("Ingrese el DNI de la persona vacunada:\n");
    gets(DNI);
    fflush(stdin);
    while(CadenaValida(DNI, PermitidosDNI) == 0 || strlen(DNI) != 8){
        printf("Error, ingrese un DNI valido:\n");
        gets(DNI);
        fflush(stdin);
    }

    if (th_recuperar(Vacunados,CodHash) != NULL){
        R = th_recuperar(Vacunados, CodHash);
        for (i = 1; i <= l_longitud(R->valor) ; i++)
        {
            T = l_recuperar(R->valor,i);
            strcpy(DatosVal, T->valor);
            DNIVal = strtok(DatosVal, s);
            DNIVal = strtok(NULL, s);
            if(strcmp(DNI, DNIVal) == 0){
                printf("La persona con el DNI ingresado ya fue cargada para esta fecha\n");
                system("pause");
                return;
            }
        }
    }

    printf("Ingrese el nombre y apellido de la persona vacunada:\n");
    gets(NomYApe);
    fflush(stdin);
    v = NomYApe;

    while(!NomCorrecto){
        NomCorrecto = true;
        while(*v != '\0' && NomCorrecto){
            if(*v >= 'A' && *v <= 'z'){
                NomCorrecto = true;
                if(*v > 'Z' && *v < 'a'){
                    NomCorrecto = false;
                }
            }else if(*v < 'A' || *v > 'z'){
                NomCorrecto = false;
                if(*v == ' '){NomCorrecto = true;}
            }
            v++;
        }
        if(!NomCorrecto){
            printf("El nombre ingresado tiene caracteres no validos, ingrese nuevamente.\n");
            printf("Ingrese el nombre y apellido de la persona vacunada:\n");
            gets(NomYApe);
            fflush(stdin);
            v = NomYApe;
            }

    }

    strcat(Datos, Fecha);
    strcat(Datos, s);
    strcat(Datos, DNI);
    strcat(Datos, s);
    strcat(Datos, NomYApe);

    X = te_crear_con_valor(CodHash, Datos);

    if (th_recuperar(Vacunados,X->clave) == NULL){
        P = te_crear_con_valor(X->clave, VacPorFecha);
        l_agregar(P->valor,X);
        th_insertar(Vacunados,P);
    }else{
        P = th_recuperar(Vacunados, X->clave);
        l_agregar(P->valor,X);
    }
    system("cls");
    printf("Datos cargados correctamente\n");
    system("pause");
}

void BuscarVacunadosPorFecha(TablaHash Vacunados){
    TipoElemento X, X2;
    int i, Codigo;
    char Fecha[15];
    char Datos[60], *DNI, *NomYApe,*Fe;
    const char s[2] = ",";
    Fe = calloc(15,sizeof(char));
    DNI = calloc(15,sizeof(char));
    NomYApe = calloc(30,sizeof(char));
    printf("(La fecha de vacunacion es desde el año 2020 hasta 2023)\n");
    printf("Ingrese la fecha de vacunacion con el formato dd/mm/yyyy:\n");
    gets(Fecha);
    fflush(stdin);

    Codigo = ValidarFecha(Fecha);
    while(Codigo == -1){
        printf("Fecha Invalida.\n");
        printf("(La fecha de vacunacion es desde el año 2020 hasta 2023)\n");
        printf("Ingrese la fecha de vacunacion con el formato dd/mm/yyyy:\n");
        gets(Fecha);
        fflush(stdin);
        Codigo = ValidarFecha(Fecha);
    }

    X = th_recuperar(Vacunados,Codigo);

    if(X == NULL){
        printf("No hay vacunados en la fecha ingeresada\n");
    }else{

        for ( i = 1; i <= l_longitud(X->valor) ; i++)
        {
            X2 = l_recuperar(X->valor,i);
            printf("--------------------------------------\n");
            strcpy(Datos, X2->valor);
            Fe = strtok(Datos, s);
            DNI = strtok(NULL, s);
            NomYApe = strtok(NULL, s);

            printf("Fecha: ");
            printf("%s\n", Fe);
            printf("DNI: ");
            printf("%s\n", DNI);
            printf("Nombre y apellido: ");
            printf("%s\n", NomYApe);

        }
    }
    printf("--------------------------------------\n");
    system("pause");

}
