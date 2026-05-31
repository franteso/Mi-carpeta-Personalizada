#include <iostream>
#include "funciones/strings.hpp"
#include "tads/parte1/Coll.hpp"
#include "tads/parte2/List.hpp"
#include "tads/parte2/Map.hpp"
#include "funciones/files.hpp"
#include "headerVUELOS.hpp"

using namespace std;
int main() {
    // Recorrer y guardar vuelos
    FILE* f1 = fopen("VUELOS.DAT", "rb");
    RVuelo vueloActual;
    vueloActual.vuelos = read<Vuelo>(f1);
    Map<int, RVuelo> vuelos = map<int, RVuelo>();

    while (!feof(f1)) {
        mapPut(vuelos, vueloActual.vuelos.idVue, vueloActual);
        vueloActual.vuelos = read<Vuelo>(f1);
    }
    fclose(f1);


    FILE* f = fopen("RESERVAS.DAT","rb");
    RReserva reservaActual;    
    reservaActual.res = read<Reserva>(f);
    
    while (!feof(f)) {
        bool acepto = asignarReservaActual(reservaActual,&vuelos);
        if (acepto) {
         asignarleMillasACliente(&reservaActual,vuelos);    
        }
        reservaActual.res = read<Reserva>(f);
    }
    recorrerVuelos(vuelos);
    fclose(f);
    
    return 0;
}
