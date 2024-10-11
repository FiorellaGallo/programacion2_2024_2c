#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../TADs/colas.h"
#include "../TADs/tipo_elemento.h"
#include "ejercicio7.h"

void clientes(Cola cola1, Cola cola2, Cola cola3, int tiempo){
    Cola colas[3] = {cola1, cola2, cola3};
    int colaAct = 0;
    int cliente_atendido[3] = {0, 0, 0};

    while (!c_es_vacia(cola1) || !c_es_vacia(cola2) || !c_es_vacia(cola3)) {
        Cola cola = colas[colaAct];

        if (!c_es_vacia(cola)) {
            TipoElemento cliente = c_desencolar(cola);
            int minutosCliente = cliente->clave;

            if (minutosCliente <= tiempo) {
                printf("Cliente %d de Cola %d termino de ser atendido.\n", cliente_atendido[colaAct] + 1, colaAct + 1);
                cliente_atendido[colaAct]++;
            }
            else {
                cliente->clave = minutosCliente - tiempo;
                c_encolar(cola, cliente);
            }
        }

        colaAct = (colaAct + 1) % 3;
    }
}
