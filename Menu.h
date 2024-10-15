#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "Red.h"
#include "Station.h"
#include "FuncionesAnexas.h"

void menu(unsigned short int& tamanioArregloSurtidores, unsigned short int& tamanioArregloEstaciones, Station* estacionesEnELArchivo, Surtidor* surtidoresEnELArchivo, Red& redNacionalColombia);
void agregarEstacion(Red& redNacional, Station* estacionesEnELArchivo, unsigned short int tamanioArregloEstaciones);
void eliminarSurtidor(Surtidor* surtidoresEnELArchivo, unsigned short int& tamanioArregloSurtidores, Station& estacionAdministrada);
void fijarPrecios(Red& redNacional);
void menuRed(Red& redNacional, Station* arregloEstaciones, unsigned short int& tamanioArregloEstaciones);
void menuEstacion();
void verificarFugas();
void simularVenta();
void activarDesactivarSurtidor(bool activar, unsigned short int& tamanioArregloSurtidores, Surtidor* surtidoresEnELArchivo, Station* estacionAdministrada);
void consultarHistoricoSurtidor(Surtidor* surtidoresEnELArchivo, unsigned short int& tamanioArregloSurtidores, Station& estacionAdministrada);


#endif
