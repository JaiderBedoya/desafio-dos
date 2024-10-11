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
    unsigned short int tamañoArregloDatos = (contarCaracteresEnString(datosEstacion, '|')+1);
    
    
    for(char caracter : datosEstacion){
        if(caracter == '|'){
            contadorPalabras++;
            continue;
        }
        datos[contadorPalabras] += caracter;
    }
    
    Station nuevaEstacion(datos[0], datos[1], datos[2], datos[3], datos[4], stoi(datos[5]), stoi(datos[6]));
    
    return nuevaEstacion;
  
}


void llenarArregloEstaciones(Station* arregloEstaciones, const string& nomArchivo){
    
    ifstream file(nomArchivo);
    if (!file.is_open()) {
        cerr << "Error abriendo archivo: " << nomArchivo << endl;
        return ;
    }
    unsigned short int posicionArregloEstaciones = 0;
    
    string linea;
    
    while (getline(file, linea)) { 
        arregloEstaciones[posicionArregloEstaciones] = leerDatosEstacion(linea);
        posicionArregloEstaciones++;
    }
    
    file.close();
    //std::cout<<"Informacion de estaciones recopilada satisfactoriamente..."<<endl<<endl;
}

Surtidor leerDatosSurtidor(const string datosSurtidor){
    string modeloSurtidor, codigoSurtidor, estacionPerteneciente, estadoSurtidor;

    string datos[4] = {codigoSurtidor, modeloSurtidor, estacionPerteneciente, estadoSurtidor};
    
    unsigned short int contadorPalabras = 0;
    unsigned short int tamañoArregloDatos = (contarCaracteresEnString(datosSurtidor, '|')+1);
    
    
    for(char caracter : datosSurtidor){
        if(caracter == '|'){
            contadorPalabras++;
            continue;
        }
        datos[contadorPalabras] += caracter;
    }
    Surtidor nuevoSurtidor(datos[0], datos[1], datos[2], true);
    if(datos[3] == "0"){
        Surtidor surtidorEnFalso(datos[0], datos[1], datos[2], false); 
        nuevoSurtidor = surtidorEnFalso;
    }
    
    return nuevoSurtidor;
}

void llenarArregloSurtidores(Surtidor* arregloSurtidores, const string& nomArchivo){
    
    ifstream file(nomArchivo);
    if (!file.is_open()) {
        cerr << "Error abriendo archivo: " << nomArchivo << endl;
        return ;
    }
    unsigned short int posicionArregloSurtidores = 0;
    
    string linea;
    
    while (getline(file, linea)) { 
        arregloSurtidores[posicionArregloSurtidores] = leerDatosSurtidor(linea);
        posicionArregloSurtidores++;
    }
    
    file.close();
}

string obtenerFechaActual(){
    
    time_t t = time(nullptr);
    tm* tm_ptr = localtime(&t);

    ostringstream oss;
    oss << std::put_time(tm_ptr, "%Y-%m-%d %H:%M:%S");

    string fecha_hora = oss.str();
    
    size_t pos = fecha_hora.find(' ');
    string fecha = fecha_hora.substr(0, pos);
    string hora = fecha_hora.substr(pos + 1);
    
    size_t pos_h = hora.find(':');
    string horas = hora.substr(0, pos_h);
    size_t pos_m = hora.find(':', pos_h + 1);
    string minutos = hora.substr(pos_h + 1, pos_m - pos_h - 1);
    string segundos = hora.substr(pos_m + 1);
    
    //Estas siguientes lineas de codigo son por el contexto en el que me encuentro, en mi chromebook la libreria ctime funciona mal y no convierte el estandar utc a utc-5
    
    unsigned short int horaNumero = stoi(hora);
    //Restarle 5 es porque en colombia se usa el utc 5
    horaNumero -= 5;
    
    if(horaNumero < 12){
        hora = "0" + to_string(horaNumero);
    }
    else{
        hora = to_string(horaNumero);
    }
    string fechaActual = fecha+" "+hora+":"+minutos+":"+segundos;
    
    return fechaActual;
}

unsigned short int numeroAletatorio(unsigned short int minimo, unsigned short int maximo){
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<> distribucion(minimo, maximo); 
    
    return distribucion(gen);
    
}
