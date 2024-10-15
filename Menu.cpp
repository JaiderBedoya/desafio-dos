#include "Menu.h"


void agregarEstacion(Red& redNacional, Station* estacionesEnELArchivo, unsigned short int tamanioArregloEstaciones){
    
    std::cout<<endl<<"Estaciones: "<<endl<<endl;
    
    for(unsigned short int i= 0; i < tamanioArregloEstaciones; i++){
        std::cout<<estacionesEnELArchivo[i].getNombre()<<" ";
        std::cout<<estacionesEnELArchivo[i].getCodigo()<<" ";
        std::cout<<estacionesEnELArchivo[i].getGerente()<<" ";
        std::cout<<estacionesEnELArchivo[i].getRegion()<<" ";
        std::cout<<estacionesEnELArchivo[i].getUbicacion()<<" ";
        std::cout<<estacionesEnELArchivo[i].getNumeroSurtidores()<<" ";
        std::cout<<estacionesEnELArchivo[i].getSurtidoresActivos()<<endl;
    }
    
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
        /*
        if(!esValidoFormatoUbicacion(ubicacion)){
            cout<<"\nX Formato invalido, intente de nuevo X\n";
        }
        else{
            break;
        }*/
        break;
    }
    while(true){
        cout<<"Ingrese numero de surtidores\n>>>";
        cin>>numeroSurtidores;
        if(numeroSurtidores < 2 || numeroSurtidores > 12){
            cout<<"\nDeben haber minimo 2 surtidores y maximo 12\n";
        }else{
            break;
        }
        
    }
    while(true){
        cout<<"Ingrese numero de surtidores activos\n>>>";
        cin>>surtidoresActivos;
        if(surtidoresActivos > numeroSurtidores){
            cout<<"\nSolo tienes "<<numeroSurtidores<<" surtidores.\n";
        }else{
            break;
        }
    }
    string codigo;
    std::cout<<"Ingrese el codigo"<<endl;
    std::cin>> codigo;
    while(codigo.length() < 3 || codigo.length() > 3){
        std::cout<<"Hubo un error..."<<endl;
        std::cout<<"Ingrese el codigo"<<endl;
    std::cin >> codigo;
    }
    Station nuevaEstacion(nombre,codigo,gerente,region,ubicacion,numeroSurtidores,surtidoresActivos);
    redNacional.agregarEstacion(estacionesEnELArchivo,nuevaEstacion, tamanioArregloEstaciones);
    redNacional.setNumeroEstaciones(redNacional.getNumeroEstaciones()+1);
    
    std::cout<<endl<<"Estaciones: "<<endl<<endl;
    
    for(unsigned short int i= 0; i < tamanioArregloEstaciones; i++){
        std::cout<<estacionesEnELArchivo[i].getNombre()<<" ";
        std::cout<<estacionesEnELArchivo[i].getCodigo()<<" ";
        std::cout<<estacionesEnELArchivo[i].getGerente()<<" ";
        std::cout<<estacionesEnELArchivo[i].getRegion()<<" ";
        std::cout<<estacionesEnELArchivo[i].getUbicacion()<<" ";
        std::cout<<estacionesEnELArchivo[i].getNumeroSurtidores()<<" ";
        std::cout<<estacionesEnELArchivo[i].getSurtidoresActivos()<<endl;
    }
    
}

void eliminarEstacion(Red& redNacional, Station* estacionesEnELArchivo, unsigned short int tamanioArregloEstaciones){
    std::cout<<"Seleccione la estacion que desea eliminar..."<<endl;
    for(unsigned short int i= 0; i < tamanioArregloEstaciones; i++){
        std::cout<<estacionesEnELArchivo[i].getCodigo()<<" "<<i<<endl<<endl;
    }
    unsigned short int opcion;
    cin>>opcion;
    while(opcion < 0 && opcion > tamanioArregloEstaciones){
        std::cout<<"Error en elegir estacion, seleccione nuevamente..."<<endl;
        cin>>opcion;
    }
    if(estacionesEnELArchivo[opcion].getSurtidoresActivos() > 0){
        std::cout<<"No se puede eliminar la estacion ya que cuenta con surtidores activos..."<<endl;
        return;
    }
    else{
        redNacional.eliminarEstacion(estacionesEnELArchivo, opcion, tamanioArregloEstaciones);
        std::cout<<"Se elimino correctamente la estacion..."<<endl<<endl;
        
        std::cout<<endl<<"Estaciones: "<<endl<<endl;
    
                for(unsigned short int i= 0; i < tamanioArregloEstaciones; i++){
                    std::cout<<estacionesEnELArchivo[i].getNombre()<<" ";
                    std::cout<<estacionesEnELArchivo[i].getCodigo()<<" ";
                    std::cout<<estacionesEnELArchivo[i].getGerente()<<" ";
                    std::cout<<estacionesEnELArchivo[i].getRegion()<<" ";
                    std::cout<<estacionesEnELArchivo[i].getUbicacion()<<" ";
                    std::cout<<estacionesEnELArchivo[i].getNumeroSurtidores()<<" ";
                    std::cout<<estacionesEnELArchivo[i].getSurtidoresActivos()<<endl;
                }
    }
    
}

void calcularVentasCadaEstacion(){
    std::cout<<"Calculando ventas de cada estacion..."<<endl;
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
                
                std::cout<<"Se cambiaron correctamente los precios..."<<endl<<endl;
                cout<<redNacional.getPrecioNorteRegular()<<endl;
                cout<<redNacional.getPrecioNortePremium()<<endl;
                cout<<redNacional.getPrecioNorteEcoextra()<<endl;
                cout<<redNacional.getPrecioCentroRegular()<<endl;
                cout<<redNacional.getPrecioCentroPremium()<<endl;
                cout<<redNacional.getPrecioCentroEcoextra()<<endl;
                cout<<redNacional.getPrecioSurRegular()<<endl;
                cout<<redNacional.getPrecioSurPremium()<<endl;
                cout<<redNacional.getPrecioSurEcoextra()<<endl<<endl;
        
                break;
                
                case 4:
                break;
                
                default:
                break;
            }
        }
    }   
    
    
void menuRed(Red& redNacional, Station* estacionesEnELArchivo, unsigned short int& tamanioArregloEstaciones)
{
    while(true){
        
    cout<<"\n  --Ha entrado en gestión de la red--\n\n"
        "1.-Agregar estacion de servicio.\n"
        "2.-Eliminar una estación de servicio.\n"
        "3.-Calcular monto total de ventas de cada E/S\n"
        "4.-Fijar precios del combustible\n"
        "5.-Volver al menú principal\n"
        ">>> ";
    
    unsigned short int opcion;
    
    cin>>opcion;
        while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5){
            std::cout<<"Opcion invalida, ingrese una nuevamente..."<<endl;
        }
    
    switch(opcion){
        case 1:
        agregarEstacion(redNacional, estacionesEnELArchivo, tamanioArregloEstaciones);
        break;
        
        case 2:
        eliminarEstacion(redNacional, estacionesEnELArchivo, tamanioArregloEstaciones);
        break;
        
        case 3:
        calcularVentasCadaEstacion();
        break;
        
        case 4:
        fijarPrecios(redNacional);
        break;
        
        case 5:
        break;
        
        default:
        break;
    }
    if(opcion == 5){
        break;
    }
        }
    }

void agregarSurtidor(Station& estacionAdministrada, Surtidor* surtidoresEnELArchivo, unsigned short int& tamanioArregloSurtidores){
    
    std::cout<<endl<<"Surtidores: "<<endl<<endl;
    
    for(unsigned short int i= 0; i < tamanioArregloSurtidores; i++){
        std::cout<<surtidoresEnELArchivo[i].getCodigo()<<" ";
        std::cout<<surtidoresEnELArchivo[i].getModelo()<<" ";
        std::cout<<surtidoresEnELArchivo[i].getEstacionPerteneciente()<<" ";
        std::cout<<surtidoresEnELArchivo[i].getEstado()<<endl;
    }
    
    string modelo, estacionPerteneciente, codigo;
    bool estado;
    
    std::cout<<"Ingrese el modelo del surtidor: "<<endl;
    cin>>modelo;
    
    std::cout<<"Ingrese el codigo del surtidor: "<<endl;
    cin>>codigo;
    
    estacionPerteneciente = estacionAdministrada.getCodigo();
    estado = true;
    
    Surtidor nuevoSurtidor(codigo, modelo, estacionPerteneciente, estado);
    
    estacionAdministrada.agregarSurtidor(surtidoresEnELArchivo,nuevoSurtidor, tamanioArregloSurtidores );
    
    std::cout<<endl<<"Surtidores: "<<endl<<endl;
    
    for(unsigned short int i= 0; i < tamanioArregloSurtidores; i++){
        std::cout<<surtidoresEnELArchivo[i].getCodigo()<<" ";
        std::cout<<surtidoresEnELArchivo[i].getModelo()<<" ";
        std::cout<<surtidoresEnELArchivo[i].getEstacionPerteneciente()<<" ";
        std::cout<<surtidoresEnELArchivo[i].getEstado()<<endl;
    }
    
    std::cout<<"Se agrego correctamente el surtidor..."<<endl;
    
}

void eliminarSurtidor(Surtidor* surtidoresEnELArchivo, unsigned short int& tamanioArregloSurtidores, Station& estacionAdministrada){
            string codigosSurtidores[tamanioArregloSurtidores];
            std::cout<<"Escriba tal cual el codigo del surtidor que desea eliminar: "<<endl;
            for(unsigned short int i = 0; i < tamanioArregloSurtidores; i++){
                if (surtidoresEnELArchivo[i].getEstacionPerteneciente() == estacionAdministrada.getCodigo()){
                    codigosSurtidores[i] = surtidoresEnELArchivo[i].getEstacionPerteneciente();
                }
                else{
                    codigosSurtidores[i] = "0";
                }
                if(codigosSurtidores[i] != "0"){
                    std::cout<<codigosSurtidores[i]<<" ";
                }
            }
            string surtidorAEliminar;
            cin>>surtidorAEliminar;
            unsigned short int posicionSurtidorEliminar = encontrarStringEnArreglo(codigosSurtidores, tamanioArregloSurtidores, surtidorAEliminar);
            while( posicionSurtidorEliminar == -1){
                std::cout<<"El codigo de este surtidor no se encuentra en los disponibles, escriba nuevamente..."<<endl;
                cin>>surtidorAEliminar;
                posicionSurtidorEliminar = encontrarStringEnArreglo(codigosSurtidores, tamanioArregloSurtidores, surtidorAEliminar);
            }
            estacionAdministrada.eliminarSurtidor(surtidoresEnELArchivo, posicionSurtidorEliminar, tamanioArregloSurtidores);
            
            std::cout<<"Se elimino correctamente el surtidor..."<<endl;
}

void activarDesactivarSurtidor(bool activar, unsigned short int& tamanioArregloSurtidores, Surtidor* surtidoresEnELArchivo, Station& estacionAdministrada){
    
    string codigosSurtidores[tamanioArregloSurtidores];
    if(activar){
        std::cout<<"Escriba tal cual el codigo del surtidor que desea activar: "<<endl;
    }
    else{
        std::cout<<"Escriba tal cual el codigo del surtidor que desea desactivar: "<<endl;
    }
            
            for(unsigned short int i = 0; i < tamanioArregloSurtidores; i++){
                if (surtidoresEnELArchivo[i].getEstacionPerteneciente() == estacionAdministrada.getCodigo()){
                    codigosSurtidores[i] = surtidoresEnELArchivo[i].getEstacionPerteneciente();
                }
                else{
                    codigosSurtidores[i] = "0";
                }
                if(codigosSurtidores[i] != "0"){
                    std::cout<<codigosSurtidores[i]<<" ";
                }
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

void consultarHistoricoSurtidor(Surtidor* surtidoresEnELArchivo, unsigned short int& tamanioArregloSurtidores, Station& estacionAdministrada){
    for(unsigned short int i = 0; i < tamanioArregloSurtidores; i++){
        if(surtidoresEnELArchivo[i].getEstacionPerteneciente() == estacionAdministrada.getCodigo()){
            estacionAdministrada.consultarHistoricoSurtidor(surtidoresEnELArchivo[i].getCodigo());
        }
    }
}


void verificarFugas()
{
    std::cout<<"Verificando fugas..."<<endl;
}

void simularVenta()
{
    cout<<"Vendiendo...\n";
}

    

void menuEstacion(Station* estacionesEnELArchivo, unsigned short int tamanioArregloEstaciones, Surtidor* surtidoresEnELArchivo, unsigned short int tamanioArregloSurtidores, unsigned short int posicionEstacionAdministrada)
{   
    Station estacionAdministrada = estacionesEnELArchivo[posicionEstacionAdministrada];
    while(true){
        
    cout<<"\n  --Has entrado en gestión de estacion de servicio--\n\n"
        "1.-Agregar/eliminar un surtidor a una E/S.\n"
        "2.-Activar/desactivar un surtidor de una E/S.\n"
        "3.-Concultar el hisorico de transacciones de cada surtidor de la E/S.\n"
        "4.-Reportar la cantidad de litros vendida según cada categoría de combustible.\n"
        "5.-Simular una venta de combustible.\n"
        "6.-Asignar capacidad del tanque de suministro aleatorio entre 100 y 200 litros por categoría.\n"
        "7.-Volver al menú principal.\n"
        ">>> ";
    
    unsigned short int opcion;
    
    cin>>opcion;
    while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6 && opcion != 7 ){
        std::cout<<"Opcion invalida, ingrese una nuevamente..."<<endl;
        cin>>opcion;
    }
    

    switch(opcion){
        case 1:
        
        std::cout<<"\n1.-Agregar surtidor.\n2.-Eliminar surtidor\n\nIngrese una opcion para eliminar o agregar un surtidor de la estacion con codigo: "<<estacionAdministrada.getCodigo()<<endl;
        
        unsigned short int opcionAgregarOEliminar;
        cin>>opcionAgregarOEliminar;
        
        while (opcionAgregarOEliminar != 1 && opcionAgregarOEliminar != 2){
            std::cout<<"Ingrese una opcion para eliminar o agregar un surtidor valida: "<<endl;
            cin>>opcionAgregarOEliminar;
        }
        
        if(opcionAgregarOEliminar == 1){
            agregarSurtidor(estacionAdministrada, surtidoresEnELArchivo, tamanioArregloSurtidores); 
        }
        
        else if(opcionAgregarOEliminar == 2){
            eliminarSurtidor(surtidoresEnELArchivo, tamanioArregloSurtidores, estacionAdministrada);
        }
        
        break;
        
        case 2:
        
        std::cout<<"1.-Activar surtidor.\n2.-Desactivar surtidor\n\nIngrese una opcion para activar/desactivar el surtidor: \n\n";
        unsigned short int opcionActivar;
        cin>>opcionActivar;
        
        while(opcionActivar != 1 && opcionActivar != 2){
            std::cout<<"Ingrese una opcion valida..."<<endl;
            cin>>opcionActivar;
        }
        if(opcionActivar == 1){
            activarDesactivarSurtidor(true, tamanioArregloSurtidores, surtidoresEnELArchivo, estacionAdministrada);
        }else{
            activarDesactivarSurtidor(false, tamanioArregloSurtidores, surtidoresEnELArchivo, estacionAdministrada);
        }
        break;

        case 3:
        consultarHistoricoSurtidor(surtidoresEnELArchivo, tamanioArregloSurtidores, estacionAdministrada);
        break;
        
        case 4:
        //litrosVendidos();
        break;
        
        case 5:
        simularVenta();
        break;
        
        case 6:
        //asignar capacidad tanque;
        break;
        
        case 7:
        break;
        
        default:
            break;
    }
    if(opcion == 7){
        break;
    }
}
}

void menu(unsigned short int& tamanioArregloSurtidores, unsigned short int& tamanioArregloEstaciones, Station* estacionesEnELArchivo, Surtidor* surtidoresEnELArchivo, Red& redNacionalColombia)
{
    while(true){
        
        std::cout<<endl<<"Estaciones: "<<endl<<endl;
    
    for(unsigned short int i= 0; i < tamanioArregloEstaciones; i++){
        std::cout<<estacionesEnELArchivo[i].getNombre()<<" ";
        std::cout<<estacionesEnELArchivo[i].getCodigo()<<" ";
        std::cout<<estacionesEnELArchivo[i].getGerente()<<" ";
        std::cout<<estacionesEnELArchivo[i].getRegion()<<" ";
        std::cout<<estacionesEnELArchivo[i].getUbicacion()<<" ";
        std::cout<<estacionesEnELArchivo[i].getNumeroSurtidores()<<" ";
        std::cout<<estacionesEnELArchivo[i].getSurtidoresActivos()<<endl;
    }
            
        cout<<"\n  -----BIENVENIDO A LA RED NACIONAL DE TERMAX-----\n\n"<<
            "<Seleccione la opción que desee>\n\n"<<
            "1....Gestión de la red\n"<<
            "2....Gestión de estaciones de servicio\n"
            "3....Sistema nacional de verificación de fugas\n"
            "4....Simulación de ventas\n"
            "5....SALIR DEL SISTEMA\n"
            ">>> ";
        
        unsigned short int opcion;
        
        cin>>opcion;
        while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5){
            std::cout<<"Opcion invalida, ingrese una nuevamente..."<<endl;
            
        }
        unsigned short int indiceEstacionParaGestionar;
        switch(opcion){
            case 1:
            menuRed(redNacionalColombia, estacionesEnELArchivo, tamanioArregloEstaciones);
            break;
            
            case 2:
            std::cout<<"Elija la estacion que desea gestionar para acceder al menu: "<<endl;
            
            for(unsigned short int i= 0; i < tamanioArregloEstaciones; i++){
                std::cout<<i<<".-"<<estacionesEnELArchivo[i].getCodigo()<<" "<<endl;
            }
            unsigned short int opcionEstacion;
            cin>>opcionEstacion;
            while(opcion < 0 && opcionEstacion > tamanioArregloEstaciones){
                std::cout<<"Error en elegir estacion, seleccione nuevamente..."<<endl;
                cin>>opcionEstacion;
            }
            
            indiceEstacionParaGestionar = opcionEstacion;
            menuEstacion(estacionesEnELArchivo, tamanioArregloEstaciones, surtidoresEnELArchivo, tamanioArregloSurtidores, indiceEstacionParaGestionar);
            break;
            
            case 3:
            verificarFugas();
            break;
            
            case 4:
            simularVenta();
            break;
            
            case 5:
                cout << "\n<<Gracias por usar el sistema. Hasta pronto>>\n";
                break;
            
            default:
                break;
        }
        if(opcion == 5){
                break;
        }
            }
}
