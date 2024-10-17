#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Station.h"
#include "Surtidor.h"
#include "Red.h"
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <ctype.h>
using namespace std;


unsigned short int contarLineasEnArchivo(const string& nombreArchivo);
unsigned short int contarCaracteresEnString(const string cadenaCaracteres, const char caracterParaContar);
Station leerDatosEstacion(const string datosEstacion);
void llenarArregloEstaciones(Station* arregloEstaciones, const string& nomArchivo);
Surtidor leerDatosSurtidor(const string datosSurtidor);
void llenarArregloSurtidores(Surtidor* arregloSurtidores, const string& nomArchivo);
string obtenerFechaActual();
unsigned short int numeroAletatorio(unsigned short int minimo, unsigned short int maximo);
void escribirDatosSurtidoresEnArchivo(Surtidor* arregloSurtidores, unsigned short int tamanioArreglo);
void escribirDatosEstacionesEnArchivo(Station* arregloEstaciones, unsigned short int tamanioArreglo);
short int obtenerIdxSurtidorEliminar(Surtidor* arregloSurtidores, string& codigoSurtidorAEliminar, unsigned short int& tamanioArreglo);
short int obtnerIdxEstacionEliminar(Station* arregloEstaciones, string& codigoEstacionAEliminar, unsigned short int& tamanioArreglo);
bool esValidoFormatoGerente(const string& gerente);
bool esValidoFormatoUbicacion(const string& ubicacion);
short int encontrarStringEnArreglo(string* arregloStrings, unsigned short int tamanioArreglo, string& stringAEncontrar);
string generarCodigoEstacion(Station* arregloEstaciones, unsigned short int& tamanioArreglo);
string generarCodigoSurtidor(Surtidor* arregloSurtidores, unsigned short int& tamanioArreglo);
void reportarCantidadLitrosVendidosCategoriaCombustible(Surtidor* arregloSurtidores, unsigned short int& tamanioArregloSurtidores, const string& codigoEstacion, bool fuga, Station& estacionAdministrada);
bool verificarTipoDocumento(string& documento);
void montoTotalVentasCategoriaCombustible(Surtidor* arregloSurtidores, unsigned short int& tamanioArregloSurtidores, const string& codigoEstacion);


#endif
