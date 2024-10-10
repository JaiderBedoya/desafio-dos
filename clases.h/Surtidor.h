#ifndef SURTIDOR_H
#define SURTIDOR_H
#include <string>
#include <iostream>
#include <fstream>
#include <random>
using namespace std;

class Surtidor {
private:
    string codigo;
    string modelo;
    string estacionPerteneciente;
    bool estado;
public:
    void reportarVenta(string tipoCombustible,unsigned short int cantidadCombustibleVendida);
    void venderCombustible(string tipoCombustible, unsigned short int cantidadRequerida, unsigned short int cantidadDisponible);


}

#endif
