#ifndef RED_H
#define RED_H
#include <iostream>
#include <string>
#include <algorithm>
class Red;
#include "Surtidor.h"
using namespace std;

class Red{
private:
    unsigned short int numeroEstaciones;
    unsigned short int precioNorteRegular;
    unsigned short int precioNortePremium;
    unsigned short int precioNorteEcoextra;
    unsigned short int precioCentroRegular;
    unsigned short int precioCentroPremium;
    unsigned short int precioCentroEcoextra;
    unsigned short int precioSurRegular;
    unsigned short int precioSurPremium;
    unsigned short int precioSurEcoextra;


public:
    Red(unsigned short int _numeroEstaciones,unsigned short int _precioNorteRegular, unsigned short int _precioNortePremium, unsigned short int _precioNorteEcoextra, unsigned short int _precioCentroRegular, unsigned short int _precioCentroPremium, unsigned short int _precioCentroEcoextra, unsigned short int _precioSurRegular, unsigned short int _precioSurPremium, unsigned short int _precioSurEcoextra);
    ~Red();

    unsigned short int getNumeroEstaciones() const;
    unsigned short int getPrecioNorteRegular() const;
    unsigned short int getPrecioNortePremium() const;
    unsigned short int getPrecioNorteEcoextra() const;
    unsigned short int getPrecioCentroRegular() const;
    unsigned short int getPrecioCentroPremium() const;
    unsigned short int getPrecioCentroEcoextra() const;
    unsigned short int getPrecioSurRegular() const;
    unsigned short int getPrecioSurPremium() const;
    unsigned short int getPrecioSurEcoextra() const;

    void setNumeroEstaciones(unsigned short int _estaciones);
    void setPrecioNorteRegular(unsigned short int _precioNorteRegular);
    void setPrecioNortePremium(unsigned short int _precioNortePremium);
    void setPrecioNorteEcoextra(unsigned short int _precioNorteEcoextra);
    void setPrecioCentroRegular(unsigned short int _precioCentroRegular);
    void setPrecioCentroPremium(unsigned short int _precioCentroPremium);
    void setPrecioCentroEcoextra(unsigned short int _precioCentroEcoextra);
    void setPrecioSurRegular(unsigned short int _precioSurRegular);
    void setPrecioSurPremium(unsigned short int _precioSurPremium);
    void setPrecioSurEcoextra(unsigned short int _precioSurEcoextra);

    void agregarEstacion(Station*& arregloEstaciones, Station* nuevaEstacion, unsigned short int& tamanio);
    void eliminarEstacion(Station*& arregloEstaciones, unsigned short int idxEstacionParaEliminar, unsigned short int& tamanio);

};


#endif
