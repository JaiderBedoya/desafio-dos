#include "FuncionesAnexas.h"

unsigned short int contarLineasEnArchivo(const string& nombreArchivo){
    unsigned short int contadorLineas = 0;
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error abriendo archivo: " << nombreArchivo << endl;
        return 0;
    }

    string linea;
    while (getline(archivo, linea)) { 
        if (!linea.empty()) { 
            contadorLineas++;
        }
    }

    archivo.close();
    return contadorLineas;
}
    

unsigned short int contarCaracteresEnString(const string cadenaCaracteres, const char caracterParaContar){
    unsigned short int contadorCaracter = 0;
    for(char caracter : cadenaCaracteres){
        if(caracter == caracterParaContar){
            contadorCaracter++;
        }
    }
    return contadorCaracter;
}

Station leerDatosEstacion(const string datosEstacion){
    string nombreEstacion, codigoEstacion, gerenteEstacion, regionEstacion, ubicacionEStacion, numeroSurtidores, surtidoresActivos;

    string datos[7] = {nombreEstacion, codigoEstacion, gerenteEstacion, regionEstacion, ubicacionEStacion, numeroSurtidores, surtidoresActivos};
    
    unsigned short int tanqueCombustibles[3];
    
    unsigned short int contadorPalabras = 0;
    unsigned short int tamañoArregloDatos = (contarCaracteresEnString(datosEstacion, ':')+1);
    
    
    for(char caracter : datosEstacion){
        if(caracter == ':'){
            contadorPalabras++;
            continue;
        }
        datos[contadorPalabras] += caracter;
    }
    
    Station nuevaEstacion(datos[0], datos[1], datos[2], datos[3], datos[4], stoi(datos[5]), stoi(datos[6]));
    
    return nuevaEstacion;
  
}



