#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "Red.h"
#include "Station.h"
#include "FuncionesAnexas.h"

const unsigned short int retornarValorPrecioCombustibleRegion(string& tipoCombustible, string& region, Red& redNacional);
string devolverCodigoSurtidorAleatorio(Surtidor* arregloSurtidores, unsigned short int& tamanioArregloSurtidores, Station& estacionAdministrada);
void activarDesactivarSurtidor(bool activar, unsigned short int& tamanioArregloSurtidores, Surtidor* surtidoresEnELArchivo, Station& estacionAdministrada);
Station* pedirDatosEstacionNueva(Station* arregloEstaciones, unsigned short int& tamanioArreglo);
Surtidor* pedirDatosSurtidorNuevo(Station& estacionAdministrada, Surtidor* arregloSurtidores, unsigned short int& tamanioArreglo);
void venderCombustible(Surtidor* surtidoresEnELArchivo, unsigned short int& tamanioArregloSurtidores, Station& estacionAdministrada, Red& redNacional);
string obtenerPosicionEstacionParaEliminar(Station* estacionesEnELArchivo, unsigned short int& tamanioArregloEstaciones);
unsigned short int obtenerPosicionSurtidorParaEliminar(Surtidor* surtidoresEnELArchivo, unsigned short int& tamanioArregloSurtidores);
void consultarHistoricoSurtidor(Surtidor* surtidoresEnELArchivo, unsigned short int& tamanioArregloSurtidores, Station& estacionAdministrada);
void fijarPrecios(Red& redNacional);
void desplegarMenuPrincipal();
void desplegarMenuPrincipal();
void desplegarMenuRed();
void menu();

#endif
