#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Station.h"
#include <iostream>
#include <string>
#include <random>
#include <fstream>
using namespace std;

Station leerDatosEstacion(const string datosEstacion);
bool verificacionFuga(unsigned short int );
unsigned short int contarCaracteresEnString(const string cadenaCaracteres, const string caracterParaContar);
unsigned short int contarLineasEnArchivo(const string& nombreArchivo);


#endif