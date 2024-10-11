#include "red.h"

Red::Red(unsigned short int _estaciones,unsigned short int _precioNorteRegular, unsigned short int _precioNortePremium, unsigned short int _precioNorteEcoextra, unsigned short int _precioCentroRegular, unsigned short int _precioCentroPremium, unsigned short int _precioCentroEcoextra, unsigned short int _precioSurRegular, unsigned short int _precioSurPremium, unsigned short int _precioSurEcoextra): estaciones(_estaciones), precioNorteRegular(_precioNorteRegular), precioNortePremium(_precioSurPremium), precioNorteEcoextra(_precioNorteEcoextra), precioCentroRegular(_precioCentroRegular), precioCentroPremium(_precioCentroPremium), precioCentroEcoextra(_precioCentroEcoextra), precioSurRegular(_precioSurRegular), precioSurPremium(_precioSurPremium), precioSurEcoextra(_precioSurEcoextra){}
Red::~Red(){}
unsigned short int Red::getEstaciones() const {
    return estaciones;
}

unsigned short int Red::getPrecioNorteRegular() const{
    return precioNorteRegular;
}

unsigned short int Red::getPrecioNortePremium() const{
    return precioNortePremium;
}

unsigned short int Red::getPrecioNorteEcoextra() const{
    return precioNorteEcoextra;
}

unsigned short int Red::getPrecioCentroRegular() const{
    return precioCentroRegular;
}

unsigned short int Red::getPrecioCentroPremium() const{
    return precioCentroPremium;
}

unsigned short int Red::getPrecioCentroEcoextra() const{
    return precioCentroEcoextra;
}

unsigned short int Red::getPrecioSurRegular() const{
    return precioSurRegular;
}

unsigned short int Red::getPrecioSurPremium() const{
    return precioSurPremium;
}

unsigned short int Red::getPrecioSurEcoextra() const{
    return precioSurEcoextra;
}

void Red::setEstaciones(unsigned short int _estaciones){
    estaciones = _estaciones;
}

void Red::setPrecioNorteRegular(unsigned short int _precioNorteRegular){
    precioNorteRegular = _precioNorteRegular;
}

void Red::setPrecioNortePremium(unsigned short int _precioNortePremium){
    precioNortePremium = _precioNortePremium;
}

void Red::setPrecioNorteEcoextra(unsigned short int _precioNorteEcoextra){
    precioNorteEcoextra = _precioNorteEcoextra;
}

void Red::setPrecioCentroRegular(unsigned short int _precioCentroRegular){
    precioCentroRegular = _precioCentroRegular;
}

void Red::setPrecioCentroPremium(unsigned short int _precioCentroPremium){
    precioCentroPremium = _precioCentroPremium;
}

void Red::setPrecioCentroEcoextra(unsigned short int _precioCentroEcoextra){
    precioCentroEcoextra = _precioCentroEcoextra;
}

void Red::setPrecioSurRegular(unsigned short int _precioSurRegular){
    precioSurRegular = _precioSurRegular;
}

void Red::setPrecioSurPremium(unsigned short int _precioSurPremium){
    precioSurPremium = _precioSurPremium;
}

void Red::setPrecioSurEcoextra(unsigned short int _precioSurEcoextra){
    precioSurEcoextra = _precioSurEcoextra;
}

void Red::agregarES() {
    string nombre;
    string codigo;
    string gerente;
    string region;
    string ubicacion;
    string surtidores;
    string surtidoresActivos;
    
     cout<<"Ingrese nombre de la estación\n>>>";
     cin>>nombre;
     
     cout<<"Ingrese gerente de la estación\n>>>";
     cin>>gerente;
     
     cout<<"Ingrese región\n>>";
     cin>>region;
     
     cout<<"Ingrese Ubicacion"
     
    }
    

 
 
