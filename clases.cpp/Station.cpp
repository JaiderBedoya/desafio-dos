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
void Station::setCombustibleRegular(unsigned short int cantidadCombustibleRegular){
    tanque[0] = cantidadCombustibleRegular;
}
void Station::setCombustiblePremium(unsigned short int cantidadCombustiblePremium){
    tanque[1] = cantidadCombustiblePremium;
}
void Station::setCombustibleEcoExtra(unsigned short int cantidadCombustibleEcoExtra){
    tanque[2] = cantidadCombustibleEcoExtra;
}


void Station::asignarLitrosAlTanque(){
    for(unsigned short int i = 0; i < 3; i++){
        unsigned short int numeroRandom = numeroAletatorio(100, 200);
        tanque[i] = numeroRandom;
    }
    std::cout<<endl<<"Se ha recargado el tanque..."<<endl;
}

void Station::imprimirDatosHistorico(string& fecha, string& tipoCombustible, string& cantidadCombustible, string& metodoPago, string& numeroDocumento, string& dineroEnCop, string& codigoDelSurtidor){
    std::cout<<endl<<"Fecha: "<<fecha<<endl;
    std::cout<<"Tipo de combustible vendido: "<<tipoCombustible<<endl;
    std::cout<<"Cantidad de combustible vendida: "<<cantidadCombustible<<endl;
    std::cout<<"Metodo de Pago: "<<metodoPago<<endl;
    std::cout<<"Numero de documento del cliente: "<<numeroDocumento<<endl;
    std::cout<<"Dinero cobrado por el servicio: "<<dineroEnCop<<endl;
    std::cout<<"Codigo del surtidor: "<<codigoDelSurtidor<<endl<<endl;
}

void Station::consultarHistoricoSurtidor(const string& codigoSurtidor){
    
    const string nomArchivo = "VentasSurtidores.txt";
    
    ifstream file(nomArchivo);
    if (!file.is_open()) {
        cerr << "Error abriendo archivo: " << nomArchivo << endl;
        return;
    }
    
    string linea;
    while (getline(file, linea)) { 
        if (linea.find(codigoSurtidor) != string::npos) {
            
            string fecha, tipoCombustible, cantidadCombustible, metodoPago, numeroDocumento,dineroEnCop, codigoDelSurtidor;
            string arregloDatosVenta[7] = {fecha, tipoCombustible, cantidadCombustible, metodoPago, numeroDocumento,dineroEnCop, codigoDelSurtidor};
            unsigned short int posicionArregloDatos = 0;
            
                for(char caracter : linea){
                    if(posicionArregloDatos == 7){
                        break;
                    }
                if(caracter == '|'){
                    posicionArregloDatos++;
                    continue;
                }
                else{
                arregloDatosVenta[posicionArregloDatos] += caracter;
                }
            }
            fecha = arregloDatosVenta[0];
            tipoCombustible = arregloDatosVenta[1];
            cantidadCombustible = arregloDatosVenta[2];
            metodoPago = arregloDatosVenta[3];
            numeroDocumento = arregloDatosVenta[4];
            dineroEnCop = arregloDatosVenta[5];
            codigoDelSurtidor = arregloDatosVenta[6];

            imprimirDatosHistorico(fecha, tipoCombustible, cantidadCombustible, metodoPago, numeroDocumento, dineroEnCop, codigoDelSurtidor);
        }
    }
    file.close();
}

void Station::agregarSurtidor(Surtidor*& arregloSurtidores, Surtidor* nuevoSurtidor, unsigned short int& tamanio){

    Surtidor* arregloNuevo = new Surtidor[tamanio+1];
    
    for(unsigned short int i = 0; i < tamanio; i++){
        arregloNuevo[i] = arregloSurtidores[i];
    }
    arregloNuevo[tamanio] = *nuevoSurtidor;
    
    delete[] arregloSurtidores;
    
    arregloSurtidores = arregloNuevo;
    tamanio++;
    
}

void Station::eliminarSurtidor(Surtidor*& arregloSurtidores, unsigned short int* idxSurtidorParaEliminar, unsigned short int& tamanio){
    
    if (*idxSurtidorParaEliminar < 0 || *idxSurtidorParaEliminar >= tamanio) {
        std::cout <<"El indice del surtidor esta fuera del arreglo..."<<endl;
        return;
    }
    Surtidor* nuevoArreglo = new Surtidor[tamanio - 1];
    
    for (unsigned short int i = 0, j = 0; i < tamanio; i++) {
        if (i == *idxSurtidorParaEliminar) {
            continue;
        }
        else{
        nuevoArreglo[j] = arregloSurtidores[i];
        j++;
        }
    }
    
    delete[] arregloSurtidores;

    arregloSurtidores = nuevoArreglo;
    tamanio--;
    
}  
