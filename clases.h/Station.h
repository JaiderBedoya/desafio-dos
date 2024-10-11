#ifndef STATION_H
#define STATION_H
#include <string>
#include <iostream>
#include <fstream>
#include <random>
using namespace std;

class Station {
    private:
        string nombre;
        string codigo;
        string gerente;
        string region;
        string ubicacion;
        unsigned short int tanque[3] = {0,0,0};
        unsigned short int numeroSurtidores;
        unsigned short int surtidoresActivos;
        
    public:
        
        Station();
        Station(string nombre, string codigo, string gerente, string region, string ubicacion, unsigned short int numeroSurtidores, unsigned short int surtidoresActivos);
        ~Station();
        
        string getNombre() const;
        string getCodigo() const;
        string getGerente() const;
        string getRegion() const;
        string getUbicacion() const;
        unsigned short int getNumeroSurtidores() const;
        unsigned short int getSurtidoresActivos() const;
        unsigned short int getCombustibleRegular() const;
        unsigned short int getCombustiblePremium() const;
        unsigned short int getCombustibleEcoExtra() const;
        
        void setNombre(string nuevoNombre);
        void setCodigo(string nuevoCOdigo);
        void setGerente(string nuevoGerente);
        void setRegion(string nuevaRegion);
        void setUbicacion(string nuevaUbicacion);
        void setNumeroSurtidores(unsigned short int nuevoNumeroSurtidores);
        void setSurtidoresActivos(unsigned short int numeroSurtidoresActivos);
        
        void agregarSurtidor(string codigo);
        void eliminarSurtidor(string codigo, string modelo);
        void activarSurtidor(bool activacion, string modelo);
        void consultarHistoricoSurtidor(string codigo, string modelo);
        void asignarLitrosAlTanque(unsigned short int* tanque, unsigned short int tamanio = 3);
  
};

#endif
