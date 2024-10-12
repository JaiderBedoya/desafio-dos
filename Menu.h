#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "red.h"
#include "Station.h"
#include "FuncionesAnexas.h"
void menuRed(Red& redNacional);
void menuEstacion();
void verificarFugas();
void simularVenta();
void menu(Red& redNacional);
void fijarPrecios(Red& redNacional);
void agregarEstación();
#endif
