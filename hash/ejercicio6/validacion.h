#ifndef validacion_h
#define validacion_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int esFechaValida(int anio, int mes, int dia);

int ValidarFecha(char *FechaStr);

int CadenaValida(char entrada[],  char permitidos[]);

#endif //validacion_h
