#include "Red.h"

Red::Red(unsigned short int _numeroEstaciones,unsigned short int _precioNorteRegular, unsigned short int _precioNortePremium, unsigned short int _precioNorteEcoextra, unsigned short int _precioCentroRegular, unsigned short int _precioCentroPremium, unsigned short int _precioCentroEcoextra, unsigned short int _precioSurRegular, unsigned short int _precioSurPremium, unsigned short int _precioSurEcoextra): numeroEstaciones(_numeroEstaciones), precioNorteRegular(_precioNorteRegular), precioNortePremium(_precioSurPremium), precioNorteEcoextra(_precioNorteEcoextra), precioCentroRegular(_precioCentroRegular), precioCentroPremium(_precioCentroPremium), precioCentroEcoextra(_precioCentroEcoextra), precioSurRegular(_precioSurRegular), precioSurPremium(_precioSurPremium), precioSurEcoextra(_precioSurEcoextra){}

Red::~Red(){}

unsigned short int Red::getNumeroEstaciones() const {
    return numeroEstaciones;
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

void Red::setNumeroEstaciones(unsigned short int _numeroEstaciones){
    numeroEstaciones = _numeroEstaciones;
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

void Red::agregarEstacion(Station*& arregloEstaciones, Station* nuevaEstacion, unsigned short int& tamanio){

    Station* arregloNuevo = new Station[tamanio+1];
    
    
    for(unsigned short int i = 0; i < tamanio; i++){
        arregloNuevo[i] = arregloEstaciones[i];
    }
    
    arregloNuevo[tamanio] = *nuevaEstacion;
    delete[] arregloEstaciones;
    
    arregloEstaciones = arregloNuevo;
    tamanio++;
    std::cout<<"Se agrego la estacion correctamente..."<<endl;
}

void Red::eliminarEstacion(Station*& arregloEstaciones, unsigned short int idxEstacionParaEliminar, unsigned short int& tamanio){
    
    if (idxEstacionParaEliminar< 0 || idxEstacionParaEliminar >= tamanio) {
        std::cout <<"El indice de la estacion esta fuera del arreglo..."<<endl;
        return;
    }
    Station* nuevoArreglo = new Station[tamanio - 1];
    
    for (unsigned short int i = 0, j = 0; i < tamanio; i++) {
        if (i == idxEstacionParaEliminar) {
            continue;
        }
        else{
        nuevoArreglo[j] = arregloEstaciones[i];
        j++;
        }
    }
    
    delete[] arregloEstaciones;

    arregloEstaciones = nuevoArreglo;
    tamanio--;
}
/*
void calcularMontoVentasCategoriaCombustible(Surtidor* surtidoresEnArchivo, unsigned short int& tamanioArreglo){
    const string nomArchivo = "VentasSurtidores.txt";
    
    ifstream file(nomArchivo);
    if (!file.is_open()) {
        cerr << "Error abriendo archivo: " << nomArchivo << endl;
        return ;
    }
    string codigoSurtidores[tamanioArreglo];
    
    unsigned long int arregloVentasEstaciones[tamanioArreglo];
    for(unsigned short int i= 0; i < tamanioArreglo; i++){
        surtidoresEnArchivo[i] = surtidoresEnArchivo[i].getCodigo[];
    }
    
    unsigned short int posicionArregloEstaciones = 0;
    
    string linea;
    
    while (getline(file, linea)) { 
        string ventaCombustible;
        unsigned short int contadorCaracterSaltar = 0;
        for(char caracter : linea){
            if(caracter == '|'){
                contadorCaracterSaltar++;
            }
            if(contadorCaracterSaltar >= 5 && contadorCaracterSaltar <= 6){
                ventaCombustible
                
            }
        }
        arregloEstaciones[posicionArregloEstaciones] = leerDatosEstacion(linea);
        posicionArregloEstaciones++;
    }
    
    file.close();
    //std::cout<<"Informacion de estaciones recopilada satisfactoriamente..."<<endl<<endl;
}
*/ 
