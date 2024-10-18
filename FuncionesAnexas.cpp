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

    unsigned short int horaNumero = stoi(horas);
    //Restarle 5 es porque en colombia se usa el utc 5
    horaNumero -= 5;

    if(horaNumero < 10){
        horas = "0" + to_string(horaNumero);
    }
    else{
        horas = to_string(horaNumero);
    }
    string fechaActual = fecha+" "+horas+":"+minutos+":"+segundos;

    return fechaActual;
}

unsigned short int numeroAletatorio(unsigned short int minimo, unsigned short int maximo){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribucion(minimo, maximo);

    return distribucion(gen);

}

void escribirDatosSurtidoresEnArchivo(Surtidor* arregloSurtidores, unsigned short int tamanioArreglo){

    std::cout<<"Escribiendo datos surtidor..."<<endl;

    string nombreArchivo = "Surtidores.txt";

    std::ofstream archivoSurtidores(nombreArchivo, std::ios::out);

    if (!archivoSurtidores) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return ;
    }

    for(unsigned short int i = 0; i < tamanioArreglo; i++){
        Surtidor surtidorEnArreglo = arregloSurtidores[i];
        string informacionSurtidor = surtidorEnArreglo.getCodigo()+"|"+surtidorEnArreglo.getModelo()+"|"+surtidorEnArreglo.getEstacionPerteneciente()+"|"+to_string(surtidorEnArreglo.getEstado());
        archivoSurtidores << informacionSurtidor<< endl;
    }
    archivoSurtidores.close();

}


void escribirDatosEstacionesEnArchivo(Station* arregloEstaciones, unsigned short int tamanioArreglo){

    std::cout<<"Escribiendo datos estacion..." <<endl;

    string nombreArchivo = "Stations.txt";

    std::ofstream archivoEstaciones(nombreArchivo, std::ios::out);

    if (!archivoEstaciones) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return ;
    }

    for(unsigned short int i = 0; i < tamanioArreglo; i++){
        Station estacionEnArreglo = arregloEstaciones[i];
        string informacionEstacion = estacionEnArreglo.getNombre()+"|"+estacionEnArreglo.getCodigo()+"|"+estacionEnArreglo.getGerente()+"|"+estacionEnArreglo.getRegion()+"|"+estacionEnArreglo.getUbicacion()+"|"+to_string(estacionEnArreglo.getNumeroSurtidores())+"|"+to_string(estacionEnArreglo.getSurtidoresActivos());
        archivoEstaciones << informacionEstacion<< endl;
    }
    archivoEstaciones.close();

}

short int obtenerIdxSurtidorEliminar(Surtidor* arregloSurtidores, string& codigoSurtidorAEliminar, unsigned short int& tamanioArreglo){
    for(unsigned short int i = 0; i < tamanioArreglo; i++){
        if(arregloSurtidores[i].getCodigo() == codigoSurtidorAEliminar){
            return i;
        }
    }
    std::cout<<"No esta el surtidor en el arreglo..."<<endl;
    return -1;
}

short int obtnerIdxEstacionEliminar(Station* arregloEstaciones, string& codigoEstacionAEliminar, unsigned short int& tamanioArreglo){
    for(unsigned short int i = 0; i < tamanioArreglo; i++){
        if(arregloEstaciones[i].getCodigo() == codigoEstacionAEliminar){
            return i;
        }
    }
    std::cout<<"No esta la estacion en el arreglo..."<<endl;
    return -1;
}

bool esValidoFormatoGerente(const string& gerente) {
    bool espacioEncontrado = false;
    bool letraEncontrada = false;

    for (char c : gerente) {
        if (isspace(c)) {
            espacioEncontrado = true;
        } else if (!isalpha(c)) {
            return false;
        }else if(isalpha(c)){
            letraEncontrada = true;
        }else{
            return false;
        }
    }
    return espacioEncontrado && letraEncontrada;

}

bool esValidoFormatoUbicacion(const string& ubicacion) {
    if (ubicacion.length() != 10 ){
        return false;
    }else if (ubicacion[3] != 176 || ubicacion[4] != 'N' || ubicacion[4] != 'S' || ubicacion[4] != 'O' || ubicacion[4] != 'E' || ubicacion[9] != 'N' || ubicacion[9] != 'S' || ubicacion[9] != '0' || ubicacion[9] != 'E' || ubicacion[8] != 176){
        return true;
    }else{
        return false;
    }

}

short int encontrarStringEnArreglo(string* arregloStrings, unsigned short int tamanioArreglo, string& stringAEncontrar){
    for(unsigned short int i = 0; i < tamanioArreglo; i++){
        if(arregloStrings[i] == stringAEncontrar){
            return i;
        }
    }
    return -1;
}

string generarCodigoEstacion(Station* arregloEstaciones, unsigned short int& tamanioArreglo){

    //65-90 mayusculas
    //97-122 minusculas

    while(true){

        char letra = numeroAletatorio(65, 90);
        char primerNumero = numeroAletatorio(48,57);
        char segundoNumero = numeroAletatorio(48,57);

        string codigoNuevo;

        codigoNuevo += letra;
        codigoNuevo += primerNumero;
        codigoNuevo += segundoNumero;

        for(unsigned short int i = 0; i < tamanioArreglo; i++){
            if(arregloEstaciones[i].getCodigo() == codigoNuevo){
                break;
            }else if(i == tamanioArreglo-1 && (codigoNuevo != arregloEstaciones[i].getCodigo())){
                return codigoNuevo;
            }
        }
    }
}


string generarCodigoSurtidor(Surtidor* arregloSurtidores, unsigned short int& tamanioArreglo){

    //65-90 mayusculas
    //97-122 minusculas

    while(true){

        char primeraLetra = numeroAletatorio(97,122);
        char segundaLetra = numeroAletatorio(97,122);
        char terceraLetra = numeroAletatorio(65,90);

        string codigoNuevo;

        codigoNuevo += primeraLetra;
        codigoNuevo += segundaLetra;
        codigoNuevo += terceraLetra;

        for(unsigned short int i = 0; i < tamanioArreglo; i++){
            if(arregloSurtidores[i].getCodigo() == codigoNuevo){
                break;
            }else if(i == tamanioArreglo-1 && (codigoNuevo != arregloSurtidores[i].getCodigo())){
                return codigoNuevo;
            }
        }
    }
}

void reportarCantidadLitrosVendidosCategoriaCombustible(Surtidor* arregloSurtidores, unsigned short int& tamanioArregloSurtidores, const string& codigoEstacion, bool fuga, Station& estacionAdministrada){

    const string nomArchivo = "VentasSurtidores.txt";

    ifstream file(nomArchivo);
    if (!file.is_open()) {
        cerr << "Error abriendo archivo: " << nomArchivo << endl;
        return ;
    }

    unsigned long int litrosVendidosRegular, litrosVendidosPremium, litrosVendidosEcoExtra;

    litrosVendidosRegular = 0;
    litrosVendidosPremium = 0;
    litrosVendidosEcoExtra = 0;

    string Regular = "Regular";
    string Premium = "Premium";
    string EcoExtra = "EcoExtra";

    string litrosVendidos, primerDigito, segundoDigito, codigoSurtidor, linea;

    unsigned short int contadorCaracterDeterminante ;

    while (getline(file, linea)) {

        contadorCaracterDeterminante = 0;

        codigoSurtidor = "";

        codigoSurtidor += linea[linea.length()-3];
        codigoSurtidor += linea[linea.length()-2];
        codigoSurtidor += linea[linea.length()-1];

        short int posicionSurtidor;
        posicionSurtidor = obtenerIdxSurtidorEliminar(arregloSurtidores, codigoSurtidor, tamanioArregloSurtidores);

        if(posicionSurtidor != -1){

            if(linea.find(arregloSurtidores[posicionSurtidor].getCodigo()) != std::string::npos && (arregloSurtidores[posicionSurtidor].getEstacionPerteneciente() == codigoEstacion)){

                unsigned short int j = 0;
                while(true){

                    if(linea[j] == '|'){
                        contadorCaracterDeterminante++;
                    }
                    if(contadorCaracterDeterminante == 1 && linea.find(Regular) != std::string::npos){

                        litrosVendidos = "";

                        primerDigito = linea[j+1];
                        segundoDigito = linea[j+2];

                        litrosVendidos += primerDigito;
                        litrosVendidos += segundoDigito;

                        litrosVendidosRegular += stoi(litrosVendidos);
                        break;

                    }
                    else if(contadorCaracterDeterminante == 1 && linea.find(Premium) != std::string::npos){

                        litrosVendidos = "";

                        primerDigito = linea[j+1];
                        segundoDigito = linea[j+2];

                        litrosVendidos += primerDigito;
                        litrosVendidos += segundoDigito;

                        litrosVendidosPremium += stoi(litrosVendidos);
                        break;

                    }
                    else if(contadorCaracterDeterminante == 1 && linea.find(EcoExtra) != std::string::npos){

                        litrosVendidos = "";

                        primerDigito = linea[j+1];
                        segundoDigito = linea[j+2];

                        litrosVendidos += primerDigito;
                        litrosVendidos += segundoDigito;

                        litrosVendidosEcoExtra += stoi(litrosVendidos);
                        break;
                    }
                    j++;
                }
            }
        }
        else{
            std::cout<<"El surtidor con codigo: "<<codigoSurtidor<<" se elimino o no se encuentra..."<<endl;
        }
    }

    std::cout<<"Litros vendidos de combustible Regular: "<<litrosVendidosRegular<<" en la estacion: "<<codigoEstacion<<endl;
    std::cout<<"Litros vendidos de combustible Premium: "<<litrosVendidosPremium<<" en la estacion: "<<codigoEstacion<<endl;
    std::cout<<"Litros vendidos de combustible EcoExtra: "<<litrosVendidosEcoExtra<<" en la estacion: "<<codigoEstacion<<endl;

    if(fuga){
        std::cout<<"Verificando Fugas..."<<endl;
        if(litrosVendidosRegular+estacionAdministrada.getCombustibleRegular() < 190){
            std::cout<<endl<<"Hay una fuga en la estacion, especificamente con el tanque Regular..."<<endl;
        }else{
            std::cout<<endl<<"No hay fugas en el tanque Regular"<<endl;
        }
        if(litrosVendidosPremium+estacionAdministrada.getCombustiblePremium() < 190){
            std::cout<<endl<<"Hay una fuga en la estacion, especificamente con el tanque Premium..."<<endl;
        }else{
            std::cout<<endl<<"No hay fugas en el tanque Premium"<<endl;
        }
        if(litrosVendidosEcoExtra+estacionAdministrada.getCombustibleEcoExtra() < 190){
            std::cout<<endl<<"Hay una fuga en la estacion, especificamente con el tanque EcoExtra..."<<endl;
        }else{
            std::cout<<endl<<"No hay fugas en el tanque EcoExtra"<<endl;
        }

    }


    file.close();
}

bool verificarTipoDocumento(string& documento){

    for(char digito : documento){
        if(digito != '0' && digito != '1' && digito != '2' && digito != '3' && digito != '4' && digito != '5' && digito != '6' && digito != '7' && digito != '8' && digito != '9' ){
            return false;
        }
    }
    return true;
}


void montoTotalVentasCategoriaCombustible(Surtidor* arregloSurtidores, unsigned short int& tamanioArregloSurtidores, const string& codigoEstacion){

    const string nomArchivo = "VentasSurtidores.txt";

    ifstream file(nomArchivo);
    if (!file.is_open()) {
        cerr << "Error abriendo archivo: " << nomArchivo << endl;
        return ;
    }

    unsigned long long int dineroVendidoRegular, dineroVendidoPremium, dineroVendidoEcoExtra;

    dineroVendidoRegular = 0;
    dineroVendidoPremium = 0;
    dineroVendidoEcoExtra = 0;

    string Regular = "Regular";
    string Premium = "Premium";
    string EcoExtra = "EcoExtra";

    string cantidadVendida, dineroGanado,codigoSurtidor, linea;

    unsigned short int contadorCaracterDeterminante ;

    while (getline(file, linea)) {

        contadorCaracterDeterminante = 0;

        codigoSurtidor = "";

        codigoSurtidor += linea[linea.length()-3];
        codigoSurtidor += linea[linea.length()-2];
        codigoSurtidor += linea[linea.length()-1];

        short int posicionSurtidor;
        posicionSurtidor = obtenerIdxSurtidorEliminar(arregloSurtidores, codigoSurtidor, tamanioArregloSurtidores);

        if(posicionSurtidor != -1){

            if(linea.find(arregloSurtidores[posicionSurtidor].getCodigo()) != std::string::npos && (arregloSurtidores[posicionSurtidor].getEstacionPerteneciente() == codigoEstacion)){

                unsigned short int j = 0, copiaJ = 0;
                while(true){
                    if(linea[j] == '|'){
                        contadorCaracterDeterminante++;
                    }
                    if(contadorCaracterDeterminante == 5 && linea.find(Regular) != std::string::npos){

                        cantidadVendida = "";

                        copiaJ = j+1;
                        dineroGanado ="";
                        while(true){
                            dineroGanado += linea[copiaJ];
                            copiaJ++;
                            if(linea[copiaJ] == '|'){
                                break;
                            }
                        }
                        cantidadVendida += dineroGanado;

                        dineroVendidoRegular += stoi(cantidadVendida);
                        break;

                    }
                    else if(contadorCaracterDeterminante == 5 && linea.find(Premium) != std::string::npos){

                        cantidadVendida = "";

                        copiaJ = j+1;
                        dineroGanado ="";
                        while(true){
                            dineroGanado += linea[copiaJ];
                            copiaJ++;
                            if(linea[copiaJ] == '|'){
                                break;
                            }
                        }
                        cantidadVendida += dineroGanado;

                        dineroVendidoPremium += stoi(cantidadVendida);
                        break;

                    }
                    else if(contadorCaracterDeterminante == 5 && linea.find(EcoExtra) != std::string::npos){

                        cantidadVendida = "";

                        copiaJ = j+1;
                        dineroGanado ="";
                        while(true){
                            dineroGanado += linea[copiaJ];
                            copiaJ++;
                            if(linea[copiaJ] == '|'){
                                break;
                            }
                        }

                        cantidadVendida += dineroGanado;

                        dineroVendidoEcoExtra += stoi(cantidadVendida);
                        break;
                    }
                    j++;
                }
            }
        }
        else{
            std::cout<<"El surtidor con codigo: "<<codigoSurtidor<<" se elimino o no se encuentra..."<<endl;
        }
    }

    std::cout<<"Monto total vendido de combustible Regular: "<<dineroVendidoRegular<<" en la estacion: "<<codigoEstacion<<endl;
    std::cout<<"Monto total vendido combustible Premium: "<<dineroVendidoPremium<<" en la estacion: "<<codigoEstacion<<endl;
    std::cout<<"Monto total vendido combustible EcoExtra: "<<dineroVendidoEcoExtra<<" en la estacion: "<<codigoEstacion<<endl;


    file.close();
}
