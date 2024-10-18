#include <iostream>
#include "FuncionesAnexas.h"
#include "Menu.h"

const unsigned short int retornarValorPrecioCombustibleRegion(string& tipoCombustible, string& region, Red& redNacional){

    if(tipoCombustible == "Regular" && (region == "norte" || region == "Norte")){
        return redNacional.getPrecioNorteRegular();
    }
    else if(tipoCombustible == "Premium" && (region == "norte" || region == "Norte")){
        return redNacional.getPrecioNortePremium();
    }
    else if(tipoCombustible == "EcoExtra" && (region == "norte" || region == "Norte")){
        return redNacional.getPrecioNorteEcoextra();
    }
    else if(tipoCombustible == "Regular" && (region == "centro" || region == "Centro")){
        return redNacional.getPrecioCentroRegular();
    }
    else if(tipoCombustible == "Premium" && (region == "centro" || region == "Centro")){
        return redNacional.getPrecioCentroPremium();
    }
    else if(tipoCombustible == "EcoExtra" && (region == "centro" || region == "Centro")){
        return redNacional.getPrecioCentroEcoextra();
    }
    else if(tipoCombustible == "Regular" && (region == "sur" || region == "Sur")){
        return redNacional.getPrecioSurRegular();
    }
    else if(tipoCombustible == "Premium" && (region == "sur" || region == "Sur")){
        return redNacional.getPrecioSurPremium();
    }
    else if(tipoCombustible == "EcoExtra" && (region == "sur" || region == "Sur")){
        return redNacional.getPrecioSurEcoextra();
    }
    else{
        std::cout<<"Ocurrio un error..."<<endl;
        return 0;
    }
}

string devolverCodigoSurtidorAleatorio(Surtidor* arregloSurtidores, unsigned short int& tamanioArregloSurtidores, Station& estacionAdministrada){

    unsigned short int contadorSurtidoresActivos = 0;

    for(unsigned short int i = 0; i < tamanioArregloSurtidores; i++){
        if(arregloSurtidores[i].getEstacionPerteneciente() == estacionAdministrada.getCodigo()){
            contadorSurtidoresActivos++;
        }
    }
    string surtidoresActivosEnLaEstacion[contadorSurtidoresActivos];

    for(unsigned short int i = 0, j= 0; i < tamanioArregloSurtidores; i++){
        if(arregloSurtidores[i].getEstacionPerteneciente() == estacionAdministrada.getCodigo()){
            surtidoresActivosEnLaEstacion[j] = arregloSurtidores[i].getCodigo();
            j++;
        }
    }
    unsigned short int posicionSurtidorAleatorio = numeroAletatorio(0, contadorSurtidoresActivos);

    string surtidorAleatorio = surtidoresActivosEnLaEstacion[posicionSurtidorAleatorio];
    return surtidorAleatorio;
}


void activarDesactivarSurtidor(bool activar, unsigned short int& tamanioArregloSurtidores, Surtidor* surtidoresEnELArchivo, Station& estacionAdministrada){

    string codigosSurtidores[tamanioArregloSurtidores];

    for(unsigned short int i = 0; i < tamanioArregloSurtidores; i++){
        if (surtidoresEnELArchivo[i].getEstacionPerteneciente() == estacionAdministrada.getCodigo()){
            codigosSurtidores[i] = surtidoresEnELArchivo[i].getCodigo();
        }
        else{
            codigosSurtidores[i] = "0";
        }
        if(codigosSurtidores[i] != "0"){
            std::cout<<codigosSurtidores[i]<<" ";
        }
    }
    std::cout<<endl;
    if(activar){
        std::cout<<"Escriba tal cual el codigo del surtidor que desea activar: "<<endl;
    }
    else{
        std::cout<<"Escriba tal cual el codigo del surtidor que desea desactivar: "<<endl;
    }

    string surtidorActivar;
    cin>>surtidorActivar;
    unsigned short int posicionSurtidorActivar = encontrarStringEnArreglo(codigosSurtidores, tamanioArregloSurtidores, surtidorActivar);
    while( posicionSurtidorActivar == -1){
        std::cout<<"El codigo de este surtidor no se encuentra en los disponibles, escriba nuevamente..."<<endl;
        cin>>surtidorActivar;
        posicionSurtidorActivar = encontrarStringEnArreglo(codigosSurtidores, tamanioArregloSurtidores, surtidorActivar);
    }
    if(activar){
        if(surtidoresEnELArchivo[posicionSurtidorActivar].getEstado()){
            std::cout<<"El surtidor esta activo..."<<endl;
            return;
        }
        else{
            surtidoresEnELArchivo[posicionSurtidorActivar].setEstado(true);
            std::cout<<"Se activo el surtidor..."<<endl;
            return;
        }
    }else{
        if(surtidoresEnELArchivo[posicionSurtidorActivar].getEstado()){
            surtidoresEnELArchivo[posicionSurtidorActivar].setEstado(false);
            std::cout<<"Se desactivo el surtidor..."<<endl;
            return;
        }
        else{
            std::cout<<"El surtidor esta desactivado..."<<endl;
            return;
        }
    }
}

Station* pedirDatosEstacionNueva(Station* arregloEstaciones, unsigned short int& tamanioArreglo){
    string nombre;
    string gerente;
    string region;
    string ubicacion;
    unsigned short int numeroSurtidores;
    unsigned short int surtidoresActivos;

    cout<<"Ingrese nombre de la estacion\n>>>";
    cin>>nombre;
    while(nombre.length() < 3 || nombre.length() > 20){
        cout<<"X Formato invalido, intente de nuevo X\n";
        cout<<"Ingrese nombre de la estacion\n>>>";
        cin>>nombre;
    }
    cout<<"\nEl nombre es valido\n";

    while(true){
        cout<<"Ingrese nombre del gerente de la estacion\n>>>";
        string nombreGerente, apellidoGerente;
        cin>>nombreGerente;
        cout<<"Ingrese apellido del gerente de la estacion\n>>>";
        cin>>apellidoGerente;
        gerente = nombreGerente+" "+apellidoGerente;
        break;
    }
    cout<<"\n<El nombre es valido>\n";

    while(true){
        cout<<"Ingrese la región(norte,centro,sur)\n>>>";
        cin>>region;
        if( region != "norte" && region != "centro" && region != "sur"){
            cout<<"\nX Formato invalido, intente de nuevo X\n";
        }
        else{
            break;
        }
    }

    while(true){
        cout<<"Ingrese ubicación GPS, formato de ejemplo 123°N456°E\n>>>";
        cin>>ubicacion;
        break;
    }
    numeroSurtidores = 0;
    surtidoresActivos = 0;

    string codigo;
    codigo = generarCodigoEstacion(arregloEstaciones, tamanioArreglo);

    Station* nuevaEstacion = new Station(nombre,codigo,gerente,region,ubicacion,numeroSurtidores,surtidoresActivos);
    return nuevaEstacion;
}

Surtidor* pedirDatosSurtidorNuevo(Station& estacionAdministrada, Surtidor* arregloSurtidores, unsigned short int& tamanioArreglo){

    string modelo, estacionPerteneciente, codigo;
    bool estado;

    std::cout<<"Ingrese el modelo del surtidor: "<<endl;
    cin>>modelo;

    codigo = generarCodigoSurtidor(arregloSurtidores, tamanioArreglo);

    estacionPerteneciente = estacionAdministrada.getCodigo();
    estado = true;

    Surtidor* nuevoSurtidor = new Surtidor(codigo, modelo, estacionPerteneciente, estado);
    return nuevoSurtidor;

}


void venderCombustible(Surtidor* surtidoresEnELArchivo, unsigned short int& tamanioArregloSurtidores, Station& estacionAdministrada, Red& redNacional){

    string tipoDeCombustible, metodoDePago, numeroDocumento;
    unsigned short int cantidadRequerida;
    unsigned short int tipoTanqueCombustible;

    cout<<"Seleccione el tipo de combustible\n>>>";
    cin>>tipoDeCombustible;

    while(tipoDeCombustible != "Regular" && tipoDeCombustible != "Premium" && tipoDeCombustible != "EcoExtra" ){

        std::cout<<"Error en elegir el tipo de combustible..."<<endl;
        cout<<"Seleccione el tipo de combustible\n>>>";
        cin>>tipoDeCombustible;

    }

    cout<<"Seleccione el metodo de pago\n>>>";
    cin>>metodoDePago;

    while(metodoDePago != "Efectivo" && metodoDePago != "Tcredito" && metodoDePago != "Tdebito" ){
        std::cout<<"Error en elegir el metodo de pago..."<<endl;
        cout<<"Seleccione el metodo de pago\n>>>";
        cin>>metodoDePago;

    }
    cantidadRequerida = numeroAletatorio(3, 20);

    std::cout<<"Cantidad requerida: "<<cantidadRequerida<<endl;

    unsigned int precioEnCOP;

    string regionEstacion;
    regionEstacion = estacionAdministrada.getRegion();

    if(tipoDeCombustible == "Regular"){
        if(estacionAdministrada.getCombustibleRegular() == 0){
            std::cout<<"Sin combustible Regular en el tanque, asigne litros al tanque porfavor..."<<endl;
            return;
        }else if(cantidadRequerida > estacionAdministrada.getCombustibleRegular() && estacionAdministrada.getCombustibleRegular() != 0 ){
            std::cout<<"Se vendera el combustible disponible ya que hay menos del requerido..."<<endl;
            precioEnCOP = retornarValorPrecioCombustibleRegion(tipoDeCombustible, regionEstacion, redNacional)*estacionAdministrada.getCombustibleRegular();
            estacionAdministrada.setCombustibleRegular(0);
        }else{
            precioEnCOP = retornarValorPrecioCombustibleRegion(tipoDeCombustible, regionEstacion, redNacional)*cantidadRequerida;
            estacionAdministrada.setCombustibleRegular(estacionAdministrada.getCombustibleRegular()-cantidadRequerida);
        }


    }
    else if(tipoDeCombustible == "Premium"){
        if(estacionAdministrada.getCombustiblePremium() == 0){
            std::cout<<"Sin combustible Premium en el tanque, asigne litros al tanque porfavor..."<<endl;
            return;
        }else if(cantidadRequerida > estacionAdministrada.getCombustiblePremium() && estacionAdministrada.getCombustiblePremium() != 0 ){
            std::cout<<"Se vendera el combustible disponible ya que hay menos del requerido..."<<endl;
            precioEnCOP = retornarValorPrecioCombustibleRegion(tipoDeCombustible, regionEstacion, redNacional)*estacionAdministrada.getCombustiblePremium();
            estacionAdministrada.setCombustiblePremium(0);
        }else{
            precioEnCOP = retornarValorPrecioCombustibleRegion(tipoDeCombustible, regionEstacion, redNacional)*cantidadRequerida;
            estacionAdministrada.setCombustiblePremium(estacionAdministrada.getCombustibleRegular()-cantidadRequerida);
        }

    }

    else if(tipoDeCombustible == "EcoExtra"){
        if(estacionAdministrada.getCombustibleEcoExtra() == 0){
            std::cout<<"Sin combustible EcoExtra en el tanque, asigne litros al tanque porfavor..."<<endl;
            return;
        }else if(cantidadRequerida > estacionAdministrada.getCombustibleEcoExtra() && estacionAdministrada.getCombustibleEcoExtra() != 0 ){
            std::cout<<"Se vendera el combustible disponible ya que hay menos del requerido..."<<endl;
            precioEnCOP = retornarValorPrecioCombustibleRegion(tipoDeCombustible, regionEstacion, redNacional)*estacionAdministrada.getCombustibleEcoExtra();
            estacionAdministrada.setCombustibleEcoExtra(0);
        }else{
            precioEnCOP = retornarValorPrecioCombustibleRegion(tipoDeCombustible, regionEstacion, redNacional)*cantidadRequerida;
            estacionAdministrada.setCombustibleEcoExtra(estacionAdministrada.getCombustibleRegular()-cantidadRequerida);
        }
    }

    while(true){

        cout<<"Ingrese documento de identidad\n>>>";
        cin>>numeroDocumento;
        if(verificarTipoDocumento(numeroDocumento)){
            break;
        }
        else{
            std::cout<<"Formato invalido de documento..."<<endl<<endl;
        }
    }

    string codigoSurtidorRandom;
    codigoSurtidorRandom = devolverCodigoSurtidorAleatorio(surtidoresEnELArchivo, tamanioArregloSurtidores, estacionAdministrada);

    std::cout<<"Llego hasta aqui..."<<endl;

    unsigned int documentoCliente;

    documentoCliente = static_cast< unsigned int>(std::stoi(numeroDocumento));

    for(unsigned short int i = 0; i < tamanioArregloSurtidores; i++){
        if(surtidoresEnELArchivo[i].getCodigo() == codigoSurtidorRandom){
            surtidoresEnELArchivo[i].reportarVenta(tipoDeCombustible, cantidadRequerida, metodoDePago, documentoCliente , precioEnCOP, codigoSurtidorRandom);
            break;
        }
    }
    std::cout<<"Gracias por comprar con TERMAX, vuelva pronto..."<<endl;
}


string obtenerPosicionEstacionParaEliminar(Station* estacionesEnELArchivo, unsigned short int& tamanioArregloEstaciones){
    while(true){
        std::cout<<"Seleccione la estacion que desea eliminar..."<<endl;

        for(unsigned short int i= 0; i < tamanioArregloEstaciones; i++){
            std::cout<<estacionesEnELArchivo[i].getCodigo()<<" "<<i<<endl<<endl;
        }
        string opcion;
        cin>>opcion;

        std::cout<<"Surtidores Activos de la estacion "<<estacionesEnELArchivo[stoi(opcion)].getCodigo()<<": "<<estacionesEnELArchivo[stoi(opcion)].getSurtidoresActivos()<<endl;

        if(estacionesEnELArchivo[stoi(opcion)].getSurtidoresActivos() == 0){
            std::cout<<"SI"<<endl;
            return opcion;

        }else{
            std::cout<<"No se puede eliminar la estacion ya que cuenta con surtidores activos..."<<endl;
            return "-1";
        }

    }
}


unsigned short int obtenerPosicionSurtidorParaEliminar(Surtidor* surtidoresEnELArchivo, unsigned short int& tamanioArregloSurtidores){
    std::cout<<"Seleccione el surtidor que desea eliminar..."<<endl;

    for(unsigned short int i= 0; i < tamanioArregloSurtidores; i++){
        std::cout<<surtidoresEnELArchivo[i].getCodigo()<<" "<<i<<endl<<endl;
    }
    unsigned short int opcion;
    cin>>opcion;
    while(opcion < 0 && opcion > tamanioArregloSurtidores){
        std::cout<<"Error en elegir surtidor, seleccione nuevamente..."<<endl;
        cin>>opcion;
    }
    return opcion;

}

void consultarHistoricoSurtidor(Surtidor* surtidoresEnELArchivo, unsigned short int& tamanioArregloSurtidores, Station& estacionAdministrada){
    for(unsigned short int i = 0; i < tamanioArregloSurtidores; i++){
        if(surtidoresEnELArchivo[i].getEstacionPerteneciente() == estacionAdministrada.getCodigo()){
            estacionAdministrada.consultarHistoricoSurtidor(surtidoresEnELArchivo[i].getCodigo());
        }
    }
}


void fijarPrecios(Red& redNacional){

    while(true){
        cout<<"\nSeleccione región que desea modificar\n"
                "1--Norte\n"
                "2--Centro\n"
                "3--Sur\n"
                "4--Volver\n"
                ">>>";

        unsigned short int opcion;
        cin>>opcion;

        while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4){
            std::cout<<"Error en elegir region, seleccione nuevamente..."<<endl;
            cin>>opcion;
        }
        switch(opcion){
            unsigned int _precioNorteRegular;
            unsigned int _precioNortePremium;
            unsigned int _precioNorteEcoextra;
            unsigned int _precioCentroRegular;
            unsigned int _precioCentroPremium;
            unsigned int _precioCentroEcoextra;
            unsigned int _precioSurRegular;
            unsigned int _precioSurPremium;
            unsigned int _precioSurEcoextra;

        case 1:
            cout<<"\nModificar precios region norte\n";
            while(true){
                cout<<"precio de Regular\n>>>";
                cin>>_precioNorteRegular;
                while(_precioNorteRegular < 10000 || _precioNorteRegular  >= 4294967295){
                    std::cout<<"Precio fuera de rango, el minimo es 10000 COP por litro, ingrese precio nuevamente..."<<endl;
                    cin>>_precioNorteRegular;
                }
                break;
            }
            redNacional.setPrecioNorteRegular(_precioNorteRegular);

            while(true){
                cout<<"precio de Premium\n>>>";
                cin>>_precioNortePremium;
                while(_precioNortePremium < 10000 || _precioNortePremium  >= 4294967295){
                    std::cout<<"Precio fuera de rango, el minimo es 10000 COP por litro, ingrese precio nuevamente..."<<endl;
                    cin>>_precioNortePremium;
                }
                break;

            }
            redNacional.setPrecioNortePremium(_precioNortePremium);
            while(true){
                cout<<"precio de Ecoextra\n>>>";
                cin>>_precioNorteEcoextra;
                while(_precioNorteEcoextra < 10000 || _precioNorteEcoextra  >= 4294967295){
                    std::cout<<"Precio fuera de rango, el minimo es 10000 COP por litro, ingrese precio nuevamente..."<<endl;
                    cin>>_precioNorteEcoextra;
                }
                break;
            }
            redNacional.setPrecioNorteEcoextra(_precioNorteEcoextra);
            break;

        case 2:
            cout<<"\nmodificar region centro\n";
            while(true){
                cout<<"precio de Regular\n>>>";
                cin>>_precioCentroRegular;
                while(_precioCentroRegular < 10000 || _precioCentroRegular  >= 4294967295){
                    std::cout<<"Precio fuera de rango, el minimo es 10000 COP por litro, ingrese precio nuevamente..."<<endl;
                    cin>>_precioCentroRegular;
                }
                break;
            }
            redNacional.setPrecioCentroRegular(_precioCentroRegular);
            while(true){
                cout<<"precio de Premium\n>>>";
                cin>>_precioCentroPremium;
                while(_precioCentroPremium < 10000 || _precioCentroPremium  >= 4294967295){
                    std::cout<<"Precio fuera de rango, el minimo es 10000 COP por litro, ingrese precio nuevamente..."<<endl;
                    cin>>_precioCentroPremium;
                }
                break;
            }
            redNacional.setPrecioCentroPremium(_precioCentroPremium);
            while(true){
                cout<<"precio de Ecoextra\n>>>";
                cin>>_precioCentroEcoextra;
                while(_precioCentroEcoextra < 10000 || _precioCentroEcoextra  >= 4294967295){
                    std::cout<<"Precio fuera de rango, el minimo es 10000 COP por litro, ingrese precio nuevamente..."<<endl;
                    cin>>_precioCentroEcoextra;
                }
                break;

            }
            redNacional.setPrecioCentroEcoextra(_precioCentroEcoextra);
            break;

        case 3:
            cout<<"\n modificar region sur\n";
            while(true){
                cout<<"precio de Regular\n>>>";
                cin>>_precioSurRegular;
                while(_precioSurRegular < 10000 || _precioSurRegular  >= 4294967295){
                    std::cout<<"Precio fuera de rango, el minimo es 10000 COP por litro, ingrese precio nuevamente..."<<endl;
                    cin>>_precioSurRegular;
                }
                break;
            }
            redNacional.setPrecioSurRegular(_precioSurRegular);
            while(true){
                cout<<"precio de Premium\n>>>";
                cin>>_precioSurPremium;
                while(_precioSurPremium < 10000 || _precioSurPremium  >= 4294967295){
                    std::cout<<"Precio fuera de rango, el minimo es 10000 COP por litro, ingrese precio nuevamente..."<<endl;
                    cin>>_precioSurPremium;
                }
                break;
            }
            redNacional.setPrecioSurPremium(_precioSurPremium);
            while(true){
                cout<<"precio de Ecoextra\n>>>";
                cin>>_precioSurEcoextra;
                while(_precioSurEcoextra < 10000 || _precioSurEcoextra  >= 4294967295){
                    std::cout<<"Precio fuera de rango, el minimo es 10000 COP por litro, ingrese precio nuevamente..."<<endl;
                    cin>>_precioSurEcoextra;
                }
                break;
            }
            redNacional.setPrecioSurEcoextra(_precioSurEcoextra);

            break;

        case 4:
            break;

        default:
            break;
        }
        if(opcion == 4){
            std::cout<<"Se cambiaron correctamente los precios..."<<endl<<endl;
            cout<<"Precio por litro Norte Regular: "<<redNacional.getPrecioNorteRegular()<<endl<<endl;
            cout<<"Precio por litro Norte Premium: "<<redNacional.getPrecioNortePremium()<<endl<<endl;
            cout<<"Precio por litro Norte EcoExtra: "<<redNacional.getPrecioNorteEcoextra()<<endl<<endl;
            cout<<"Precio por litro Centro Regular: "<<redNacional.getPrecioCentroRegular()<<endl<<endl;
            cout<<"Precio por litro Centro Premium: "<<redNacional.getPrecioCentroPremium()<<endl<<endl;
            cout<<"Precio por litro Centro EcoExtra: "<<redNacional.getPrecioCentroEcoextra()<<endl<<endl;
            cout<<"Precio por litro Sur Regular: "<<redNacional.getPrecioSurRegular()<<endl<<endl;
            cout<<"Precio por litro Sur Premium: "<<redNacional.getPrecioSurPremium()<<endl<<endl;
            cout<<"Precio por litro Sur EcoExtra: "<<redNacional.getPrecioSurEcoextra()<<endl<<endl;
            break;
        }
    }
}


void desplegarMenuPrincipal(){

    cout<<"\n  -----BIENVENIDO A LA RED NACIONAL DE TERMAX-----\n\n"<<
        "<Seleccione la opción que desee>\n\n"<<
        "1....Gestión de la red\n"<<
        "2....Gestión de estaciones de servicio\n"
        "3....SALIR DEL SISTEMA\n"
        ">>> ";
}

void desplegarMenuEstacion(){
    cout<<"\n---Has entrado en gestión de estacion de servicio---\n\n"
            "1.-Agregar/eliminar un surtidor.\n"
            "2.-Activar/desactivar un surtidor.\n"
            "3.-Consultar el hisorico de transacciones de cada surtidor de la E/S.\n"
            "4.-Reportar la cantidad de litros vendida según cada categoría de combustible.\n"
            "5.-Simular una venta de combustible.\n"
            "6.-Asignar capacidad del tanque de suministro aleatorio entre 100 y 200 litros por categoría.\n"
            "7.-Verificar si hay fuga.\n"
            "8.-Calcular monto total de ventas.\n"
            "9.-Volver al menú principal.\n"
            ">>> ";
}

void desplegarMenuRed(){

    cout<<"\n  --Ha entrado en gestión de la red--\n\n"
            "1.-Agregar estacion de servicio.\n"
            "2.-Eliminar una estación de servicio.\n"
            "3.-Fijar precios del combustible\n"
            "4.-Volver al menú principal\n"
            ">>> ";
}



void menu(){

    //PROGRAMA PRINCIPAL

    const string nombreArchivoEstaciones = "Stations.txt";
    const string nombreArchivoSurtidores = "Surtidores.txt";

    unsigned short int tamanioArregloEstaciones = contarLineasEnArchivo(nombreArchivoEstaciones);
    unsigned short int tamanioArregloSurtidores = contarLineasEnArchivo(nombreArchivoSurtidores);

    Station* estacionesEnELArchivo = new Station[tamanioArregloEstaciones];
    Surtidor* surtidoresEnELArchivo = new Surtidor[tamanioArregloSurtidores];

    llenarArregloEstaciones(estacionesEnELArchivo, nombreArchivoEstaciones);
    llenarArregloSurtidores(surtidoresEnELArchivo, nombreArchivoSurtidores);

    Red redNacional(tamanioArregloEstaciones, 15000, 20000, 10000, 15000, 20000, 10000, 15000, 20000, 10000);

    while(true){

        //MENU PRINCIPAL

        desplegarMenuPrincipal();

        string opcionMenuPrincipal;;
        cin>>opcionMenuPrincipal;


        if(opcionMenuPrincipal == "1"){

            //MENU RED

            while(true){

                desplegarMenuRed();

                unsigned short int opcionMenuRed;
                cin>>opcionMenuRed;

                if(opcionMenuRed == 1){

                    Station* nuevaEstacion = new Station();

                    nuevaEstacion = pedirDatosEstacionNueva(estacionesEnELArchivo, tamanioArregloEstaciones);

                    redNacional.agregarEstacion(estacionesEnELArchivo, nuevaEstacion, tamanioArregloEstaciones);

                    delete nuevaEstacion;

                    redNacional.setNumeroEstaciones(redNacional.getNumeroEstaciones()+1);


                }
                else if(opcionMenuRed == 2){
                    if(tamanioArregloEstaciones == 1){
                        std::cout<<"Solo hay una estacion, no puedes borrarla..."<<endl;
                    }else{
                        short int posicionParaEliminar;
                        posicionParaEliminar = stoi(obtenerPosicionEstacionParaEliminar(estacionesEnELArchivo, tamanioArregloEstaciones));
                        if(posicionParaEliminar == -1){
                            std::cout<<"Continuando..."<<endl;
                        }else{
                            redNacional.eliminarEstacion(estacionesEnELArchivo, opcionMenuRed, tamanioArregloEstaciones);
                            std::cout<<"Se elimino correctamente la estacion..."<<endl<<endl;
                        }
                    }
                }
                else if(opcionMenuRed == 3){
                    fijarPrecios(redNacional);
                }
                else if(opcionMenuRed == 4){
                    std::cout<<"Saliendo al menu principal..."<<endl;
                    break;
                }
                else{
                    std::cout<<"Opcion invalida, ingrese una nuevamente..."<<endl;
                }
            }
        }


        else if(opcionMenuPrincipal == "2"){

            //MENU ESTACION

            std::cout<<"Elija la estacion que desea gestionar para acceder al menu: "<<endl;

            for(unsigned short int i= 0; i < tamanioArregloEstaciones; i++){
                std::cout<<i<<".-"<<estacionesEnELArchivo[i].getCodigo()<<" "<<endl;
            }
            unsigned short int opcionEstacion;
            cin>>opcionEstacion;
            while(opcionEstacion < 0 && opcionEstacion > tamanioArregloEstaciones){
                std::cout<<"Error en elegir estacion, seleccione nuevamente..."<<endl;
                cin>>opcionEstacion;
            }
            unsigned short int* posicionEstacionAdministrada = new unsigned short int;
            *posicionEstacionAdministrada = opcionEstacion;
            Station estacionAdministrada = estacionesEnELArchivo[*posicionEstacionAdministrada];

            std::cout<<endl<<"Si desea escojer otra estacion, salga y vuelva a entrar..."<<endl;

            while(true){

                desplegarMenuEstacion();

                string opcionMenuEstacion;
                cin>>opcionMenuEstacion;

                if(opcionMenuEstacion == "1"){

                    while(true){
                        std::cout<<endl<<"¿Que desea hacer? "<<endl<<endl;
                        std::cout<<"1.-Agregar Surtidor\n"
                                     "2.-Eliminar Surtidor"<<endl;

                        string opcionAgregarEliminar;
                        cin>>opcionAgregarEliminar;

                        if(opcionAgregarEliminar == "1"){

                            Surtidor* nuevoSurtidor = new Surtidor();
                            nuevoSurtidor = pedirDatosSurtidorNuevo(estacionAdministrada, surtidoresEnELArchivo, tamanioArregloSurtidores);

                            estacionAdministrada.agregarSurtidor(surtidoresEnELArchivo, nuevoSurtidor, tamanioArregloSurtidores);
                            estacionAdministrada.setNumeroSurtidores(estacionAdministrada.getNumeroSurtidores()+1);
                            estacionAdministrada.setSurtidoresActivos(estacionAdministrada.getSurtidoresActivos()+1);


                            delete nuevoSurtidor;

                            estacionAdministrada.setNumeroSurtidores(estacionAdministrada.getNumeroSurtidores()+1);
                            estacionAdministrada.setSurtidoresActivos(estacionAdministrada.getSurtidoresActivos()+1);

                            std::cout<<"Se agrego el surtidor..."<<endl;
                            break;

                        }
                        else if(opcionAgregarEliminar == "2"){

                            unsigned short int* posicionParaEliminar = new unsigned short int;
                            *posicionParaEliminar = obtenerPosicionSurtidorParaEliminar(surtidoresEnELArchivo, tamanioArregloSurtidores);

                            estacionAdministrada.eliminarSurtidor(surtidoresEnELArchivo, posicionParaEliminar, tamanioArregloSurtidores);

                            estacionAdministrada.setNumeroSurtidores(estacionAdministrada.getNumeroSurtidores()-1);
                            estacionAdministrada.setSurtidoresActivos(estacionAdministrada.getSurtidoresActivos()-1);

                            delete posicionParaEliminar;

                            std::cout<<"Se elimino correctamente el surtidor..."<<endl<<endl;
                            break;
                        }
                        else{
                            std::cout<<"Opcion invalida, seleccione otra: "<<endl;
                        }

                    }
                }

                else if(opcionMenuEstacion == "2"){

                    while(true){

                        std::cout<<"1.-Activar surtidor.\n2.-Desactivar surtidor\nIngrese una opcion para activar/desactivar el surtidor: \n";

                        string opcionActivar;
                        cin>>opcionActivar;

                        if(opcionActivar == "1"){
                            activarDesactivarSurtidor(true, tamanioArregloSurtidores, surtidoresEnELArchivo, estacionAdministrada);
                            break;
                        }
                        else if(opcionActivar == "2"){
                            activarDesactivarSurtidor(false, tamanioArregloSurtidores, surtidoresEnELArchivo, estacionAdministrada);
                            break;
                        }
                        else{
                            std::cout<<"Opcion invalida, ingrese nuevamente..."<<endl;
                        }
                    }
                }

                else if(opcionMenuEstacion == "3"){

                    std::cout<<"(Si no sale nada, es porque dicha estacion no ha vendido...) Imprimiendo historico:  "<<endl;

                    for(unsigned short int i = 0; i < tamanioArregloSurtidores; i++){
                        if(surtidoresEnELArchivo[i].getEstacionPerteneciente() == estacionAdministrada.getCodigo()){
                            estacionAdministrada.consultarHistoricoSurtidor(surtidoresEnELArchivo[i].getCodigo());
                        }
                    }

                }
                else if(opcionMenuEstacion == "4"){
                    reportarCantidadLitrosVendidosCategoriaCombustible(surtidoresEnELArchivo, tamanioArregloSurtidores, estacionAdministrada.getCodigo(), false, estacionAdministrada);
                }
                else if(opcionMenuEstacion == "5"){

                    venderCombustible(surtidoresEnELArchivo, tamanioArregloSurtidores, estacionAdministrada, redNacional);
                }
                else if(opcionMenuEstacion == "6"){
                    estacionAdministrada.asignarLitrosAlTanque();
                }
                else if(opcionMenuEstacion == "7"){
                    reportarCantidadLitrosVendidosCategoriaCombustible(surtidoresEnELArchivo, tamanioArregloSurtidores, estacionAdministrada.getCodigo(), true, estacionAdministrada);
                }
                else if(opcionMenuEstacion == "8"){
                    montoTotalVentasCategoriaCombustible(surtidoresEnELArchivo, tamanioArregloSurtidores, estacionAdministrada.getCodigo());
                }
                else if(opcionMenuEstacion == "9"){
                    std::cout<<"Saliendo"<<endl;
                    delete posicionEstacionAdministrada;
                    break;
                }

                else{
                    std::cout<<"Opcion no valida, ingrese una opcion nuevamente..."<<endl;
                }
            }

        }
        else if(opcionMenuPrincipal == "3"){

            escribirDatosSurtidoresEnArchivo(surtidoresEnELArchivo, tamanioArregloSurtidores);
            escribirDatosEstacionesEnArchivo(estacionesEnELArchivo, tamanioArregloEstaciones);

            delete[] estacionesEnELArchivo;
            delete[] surtidoresEnELArchivo;

            std::cout<<"Gracias por usar el sistema, vuelva pronto..."<<endl;

            return;
            break;

        }
        else{
            std::cout<<"Opcion invalida, ingrese una nuevamente..."<<endl;
        }

    }

    return;
}
