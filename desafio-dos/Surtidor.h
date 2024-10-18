#ifndef SURTIDOR_H
#define SURTIDOR_H
#include <string>
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <sstream>
#include <iomanip>
class Surtidor;
#include "FuncionesAnexas.h"
using namespace std;

class Surtidor {
private:
    string codigo;
    string modelo;
    string estacionPerteneciente;
    bool estado;
public:

    Surtidor(string codigo_, string modelo_, string estacionPerteneciente_, bool estado_);
    Surtidor();
    ~Surtidor();

    string getCodigo() const;
    string getModelo() const;
    string getEstacionPerteneciente() const;
    bool getEstado() const;

    void setCodigo(string nuevoCodigo);
    void setModelo(string nuevoModelo);
    void setEstacionPerteneciente(string nuevaEstacionPerteneciente);
    void setEstado(bool nuevoEstado);

    void reportarVenta(string& tipoCombustible,unsigned short int cantidadCombustibleVendida, string& metodoPago, unsigned int& numeroDocumento, unsigned int dineroEnCop,string& codigoSurtidor);

};
#endif
