#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Station.h"
#include "Surtidor.h"
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <ctype.h>

Station leerDatosEstacion(const string datosEstacion);
bool verificacionFuga(unsigned short int);
unsigned short int contarCaracteresEnString(const string cadenaCaracteres, const string caracterParaContar);
unsigned short int contarLineasEnArchivo(const string& nombreArchivo);
void llenarArregloEstaciones(Station* arregloEstaciones, const string& nomArchivo);
Surtidor leerDatosSurtidor(const string datosSurtidor);
void llenarArregloSurtidores(Surtidor* arregloSurtidores, const string& nomArchivo);
bool esValidoFormatoGerente(const string& gerente);
bool esValidoFormatoUbicacion(const std::string& ubicacion);
string obtenerFechaActual();
unsigned short int numeroAletatorio(unsigned short int minimo, unsigned short int maximo);

#endif
