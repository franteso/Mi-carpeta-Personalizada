#ifndef MAIN_HPP
#define MAIN_HPP value




struct Ciudad 
{ 
   int idCiu; 
   char descr[20]; 
   int millas; 
}; 

struct RCiudad
{
Ciudad city;
int reservas;
};

struct Vuelo 
{ 
   int idVue;  
   int cap;  
   int idOri; // idCiu origen 
   int idDes; // idCiu destino
};  
struct RVuelo
{
   Vuelo vuelos;
   int rechazados;
   bool completo;
};

struct Reserva 
{ 
   int idCli; 
   int idVue;  
   int cant; 
};
struct RReserva
{
 Reserva res;
 int cantmillas;
};

bool asignarReservaActual(RReserva reservaActual, Map <int,RVuelo>* vuelos) {
   RVuelo* vueloReservado = mapGet(*vuelos,reservaActual.res.idVue);
   if (vueloReservado->vuelos.cap < reservaActual.res.cant) {
      vueloReservado->rechazados += reservaActual.res.cant;
      return false;
   } else {
      vueloReservado->vuelos.cap = vueloReservado->vuelos.cap - reservaActual.res.cant;
      return true;
   }
//busco el vuelo del cliente
//me fijo si hay capacidad, si no hay devuelvo false y no suma capacidad a vuelo
//si hay capacidad, le resto la capacidad, devuelvo true

}




void asignarleMillasACliente(RReserva* reservaActual,Map <int,RVuelo> vuelos)
{
   FILE* f = fopen("CIUDADES.DAT","rb");
   RCiudad ciudadBuscada;
   ciudadBuscada.city = read<Ciudad>(f);
   Ciudad destino;
   Ciudad origen;
   while (!feof(f)) {

      RVuelo* vueloReservado = mapGet(vuelos,reservaActual->res.idVue);
      if (vueloReservado->vuelos.idDes ==  ciudadBuscada.city.idCiu ) {
         ciudadBuscada.reservas++;
         destino = ciudadBuscada.city;
      }
      if (vueloReservado->vuelos.idOri == ciudadBuscada.city.idCiu ) {
         origen = ciudadBuscada.city;
      }
   ciudadBuscada.city = read<Ciudad>(f);
   }
   reservaActual->cantmillas = (destino.millas - origen.millas) * reservaActual->res.cant;
   fclose(f);
   //abrir archivo ciudades
   //recorrerlo en busca de ciudad origen y ciudad destino
   // hacer la resta de estas
   // asingarle las millas al cliente por la cant, y ademas sumarle cant a 1 al contador de visitas de la ciudad destino
}

void recorrerVuelos(Map <int,RVuelo> vuelos) {
   mapReset(vuelos);
   while (mapHasNext(vuelos)) {
      RVuelo* vueloActual = mapNextValue(vuelos);
      if (vueloActual->vuelos.cap == 0) {
         vueloActual->completo = true;
      } else {
         vueloActual->completo = false;
      }
   }
   //recorrer vuelos y fijarme si estan con cap = 0,
}

#endif