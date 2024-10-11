#include "Station.h"

//Constructor miembro a miembro
Station::Station(string nombre_, string codigo_, string gerente_, string region_, string ubicacion_, unsigned short int numeroSurtidores_, unsigned short int surtidoresActivos_): nombre(nombre_), codigo(codigo_), gerente(gerente_), region(region_), ubicacion(ubicacion_), numeroSurtidores(numeroSurtidores_), surtidoresActivos(surtidoresActivos_){}
//Constructor por defecto
Station::Station():nombre(""),codigo(""),gerente(""),region(""),ubicacion(""),numeroSurtidores(0),surtidoresActivos(0){};
//Destructor 
Station::~Station(){};
//getters
string Station::getNombre() const {
    return nombre;
}
string Station::getCodigo() const {
    return codigo;
}
string Station::getGerente() const {
    return gerente;
}
string Station::getRegion() const {
    return region;
}
string Station::getUbicacion() const {
    return ubicacion;
}
unsigned short int Station::getNumeroSurtidores() const {
    return numeroSurtidores;
}
unsigned short int Station::getSurtidoresActivos() const {
    return surtidoresActivos;
}
unsigned short int Station::getCombustibleRegular() const{
    return tanque[0];
}
unsigned short int Station::getCombustiblePremium() const{
    return tanque[1];
}
unsigned short int Station::getCombustibleEcoExtra() const{
    return tanque[2];
}

//setters
void Station::setNombre(string nuevoNombre){
    nombre = nuevoNombre;
}
void Station::setCodigo(string nuevoCodigo){
    codigo = nuevoCodigo;
}
void Station::setGerente(string nuevoGerente){
    gerente = nuevoGerente;
}
void Station::setRegion(string nuevaRegion){
    region = nuevaRegion;
}
void Station::setUbicacion(string nuevaUbicacion){
    ubicacion = nuevaUbicacion;
}
void Station::setNumeroSurtidores(unsigned short int nuevoNumeroSurtidores){
    numeroSurtidores = nuevoNumeroSurtidores;
}
void Station::setSurtidoresActivos(unsigned short int numeroSurtidoresActivos){
    numeroSurtidoresActivos = numeroSurtidoresActivos;
}

void asignarLitrosAlTanque(unsigned short int* tanque, unsigned short int tamanio = 3){
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<> distribucion(100, 200); 
    for(unsigned short int i = 0; i < tamanio; i++){
        tanque[i] = distribucion(gen);
    }
}
