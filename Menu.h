#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "Red.h"
#include "Station.h"
#include "FuncionesAnexas.h"

void menu();
Station pedirDatosEstacion();
void fijarPrecios(Red& redNacional);
void menuRed(Red& redNacional, Station* arregloEstaciones, unsigned short int& tamanioArregloEstaciones);
void menuEstacion();
void verificarFugas();
void simularVenta();
void activarDesactivarSurtidor(bool activar, unsigned short int& tamanioArregloSurtidores, Surtidor* surtidoresEnELArchivo, Station* estacionAdministrada);
void consultarHistoricoSurtidor(Surtidor* surtidoresEnELArchivo, unsigned short int& tamanioArregloSurtidores, Station& estacionAdministrada);
void menuDefinitivo();

#endif
