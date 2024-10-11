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
        
        void reportarVenta(string tipoCombustible,unsigned short int cantidadCombustibleVendida, unsigned short int costoCombustibleTotal);
        void venderCombustible(string tipoCombustible, unsigned short int cantidadRequerida, unsigned short int cantidadDisponible);
};
#endif
