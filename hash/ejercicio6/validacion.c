#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacion.h"

int esFechaValida(int anio, int mes, int dia) {
    time_t T;
    T = time(NULL);
    struct tm *fecha;
    fecha = localtime(&T);

    if (anio < 2020 || anio > 2023 || mes < 1 || mes > 12 || dia < 1) {
        return 0;
    }

    int diasEnMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) {
        diasEnMes[1] = 29;
    }

    if (dia > diasEnMes[mes - 1]) {
        return 0;
    }

    return 1;
}

int ValidarFecha(char *FechaStr){
    int i, CodigoHash = 0,Dia = 0, Mes = 0, Anio = 0 ,Valida;
    char C;

    if(strlen(FechaStr) > 10){
        return -1;
    }

    for ( i = 0; i < strlen(FechaStr); i++){
        C = FechaStr[i];
        if(C >= '0' && C <= '9'){
            if(i<2){
                if(i == 0){
                    Dia = Dia + (C - 48);
                    Dia = Dia * 10;
                }else{Dia = Dia + (C - 48);}

            }else if(i<5){
                if(i == 3){
                    Mes = Mes + (C - 48);
                    Mes = Mes * 10;
                }else{Mes = Mes + (C - 48);}
            }else{
                if(i == 9){
                    Anio = Anio + (C - 48);
                }else{
                    Anio = Anio + (C - 48);
                    Anio = Anio * 10;
                }
            }
        }else if((i == 2 || i == 5) && C != '/'){
            return -1;
        }else if((C < '0' || C > '9') && C != '/'){
            return -1;
        }
    }

    Valida = esFechaValida(Anio, Mes, Dia);
    if(Valida == 0){
        return -1;
    }else{
        CodigoHash = CodigoHash + Anio;
        CodigoHash = CodigoHash * 100;
        CodigoHash = CodigoHash + Mes;
        CodigoHash = CodigoHash * 100;
        CodigoHash = CodigoHash + Dia;
    }

    return CodigoHash;
}

int CadenaValida(char entrada[],  char permitidos[]) {
    int valido = 1 , i;
    entrada[strcspn(entrada, "\n")] = '\0';
    for (i = 0; entrada[i] != '\0' && valido != 0; i++) {
           entrada[i] = toupper(entrada[i]);
           if (strrchr(permitidos,  entrada[i]) == NULL) {
               printf("Cadena invalida...\n");
               valido = 0;
            }
    }
    return valido;
}
