#include "Surtidor.h"

//Constructor miembro a miembro
Surtidor::Surtidor(string codigo_, string modelo_, string estacionPerteneciente_, bool estado_): codigo(codigo_), modelo(modelo_), estacionPerteneciente(estacionPerteneciente_), estado(estado_){}
//Constructor por defecto
Surtidor::Surtidor():codigo(""), modelo(""), estacionPerteneciente(""), estado(false){};
//Destructor
Surtidor::~Surtidor(){};
//getters
string Surtidor::getCodigo() const {
    return codigo;
}
string Surtidor::getModelo() const {
    return modelo;
}
string Surtidor::getEstacionPerteneciente() const {
    return estacionPerteneciente;
}
bool Surtidor::getEstado() const {
    return estado;
}

//setters
void Surtidor::setCodigo(string nuevoCodigo){
    codigo = nuevoCodigo;
}
void Surtidor::setModelo(string nuevoModelo){
    modelo = nuevoModelo;
}
void Surtidor::setEstacionPerteneciente(string nuevaEstacionPerteneciente){
    estacionPerteneciente = nuevaEstacionPerteneciente;
}
void Surtidor::setEstado(bool nuevoEstado){
    estado = nuevoEstado;
}
void Surtidor::reportarVenta(string tipoCombustible,unsigned short int cantidadCombustibleVendida, unsigned short int costoCombustibleTotal){
    
}

