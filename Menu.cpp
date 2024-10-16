#include <iostream>
#include "FuncionesAnexas.h"
#include "Menu.h"

Station* pedirDatosEstacionNueva(){
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
    Station* nuevaEstacion = new Station(nombre,codigo,gerente,region,ubicacion,numeroSurtidores,surtidoresActivos);
    return nuevaEstacion;
}
    
Surtidor* pedirDatosSurtidorNuevo(Station& estacionAdministrada){
    
    string modelo, estacionPerteneciente, codigo;
    bool estado;
    
    std::cout<<"Ingrese el modelo del surtidor: "<<endl;
    cin>>modelo;
    
    std::cout<<"Ingrese el codigo del surtidor: "<<endl;
    cin>>codigo;
    
    estacionPerteneciente = estacionAdministrada.getCodigo();
    estado = true;
    
    Surtidor* nuevoSurtidor = new Surtidor(codigo, modelo, estacionPerteneciente, estado);
    return nuevoSurtidor;
    
}    
    
    

short int obtenerPosicionEstacionParaEliminar(Station* estacionesEnELArchivo, unsigned short int& tamanioArregloEstaciones){
    while(true){
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
        return -1;
    }else{
        return opcion;
    }
    
    }
}


void simularVenta()
{
    cout<<"Vendiendo...\n";
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
  
  
  
  
  
void menuDefinitivo(){

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

        
    if(opcion == 1){
        
        //MENU RED
        
        while(true){
            
        cout<<"\n  --Ha entrado en gestión de la red--\n\n"
        "1.-Agregar estacion de servicio.\n"
        "2.-Eliminar una estación de servicio.\n"
        "3.-Calcular monto total de ventas de cada E/S\n"
        "4.-Fijar precios del combustible\n"
        "5.-Volver al menú principal\n"
        ">>> ";
    
        unsigned short int opcionMenuRed;
        cin>>opcionMenuRed;
        
        if(opcionMenuRed == 1){
            
           Station* nuevaEstacion = new Station();
           nuevaEstacion = pedirDatosEstacionNueva();
           redNacional.agregarEstacion(estacionesEnELArchivo, nuevaEstacion, tamanioArregloEstaciones);
           redNacional.setNumeroEstaciones(redNacional.getNumeroEstaciones()+1);
           delete nuevaEstacion;
            
        }
        else if(opcionMenuRed == 2){
            if(tamanioArregloEstaciones == 1){
                std::cout<<"Solo hay una estacion, no puedes borrarla..."<<endl;
            }else{
            short int posicionParaEliminar;
            posicionParaEliminar = obtenerPosicionEstacionParaEliminar(estacionesEnELArchivo, tamanioArregloEstaciones);
            if(posicionParaEliminar = -1){
                std::cout<<"Continuando..."<<endl;
            }else{
            redNacional.eliminarEstacion(estacionesEnELArchivo, opcionMenuRed, tamanioArregloEstaciones);
            std::cout<<"Se elimino correctamente la estacion..."<<endl<<endl;
            }
            }  
        }
        else if(opcionMenuRed == 3){
            std::cout<<"Opcion 3"<<endl;
            
        }
        else if(opcionMenuRed == 4){
            fijarPrecios(redNacional);
        }
        else if(opcionMenuRed == 5){
            std::cout<<"Saliendo al menu principal..."<<endl;
            break;
        }
        else{
            std::cout<<"Opcion invalida, ingrese una nuevamente..."<<endl;
        }
        
    }
}    
    

    else if(opcion == 2){
        
        //MENU ESTACION
        
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
        unsigned short int* posicionEstacionAdministrada = new unsigned short int;
        *posicionEstacionAdministrada = opcionEstacion;
        Station estacionAdministrada = estacionesEnELArchivo[*posicionEstacionAdministrada];
        
        std::cout<<endl<<"Si desea escojer otra estacion, salga y vuelva a entrar..."<<endl;
        
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
        
        unsigned short int opcionMenuEstacion;
    
        cin>>opcionMenuEstacion;
        while(opcionMenuEstacion != 1 && opcionMenuEstacion != 2 && opcionMenuEstacion != 3 && opcionMenuEstacion != 4 && opcionMenuEstacion != 5 && opcionMenuEstacion != 6 && opcionMenuEstacion != 7 ){
        std::cout<<"Opcion invalida, ingrese una nuevamente..."<<endl;
        cin>>opcionMenuEstacion;
        }
        if(opcionMenuEstacion == 1){
        Surtidor* nuevoSurtidor = new Surtidor();
        nuevoSurtidor = pedirDatosSurtidorNuevo(estacionAdministrada);
       
        estacionAdministrada.agregarSurtidor(surtidoresEnELArchivo, nuevoSurtidor, tamanioArregloSurtidores);
        estacionAdministrada.setNumeroSurtidores(estacionAdministrada.getNumeroSurtidores()+1);
        estacionAdministrada.setSurtidoresActivos(estacionAdministrada.getSurtidoresActivos()+1);
        
        std::cout<<"Se agrego el surtidor..."<<endl;
      
        delete nuevoSurtidor;
        
        }
        
        
        else if(opcionMenuEstacion == 2){
            
            unsigned short int* posicionParaEliminar = new unsigned short int;
            *posicionParaEliminar = obtenerPosicionSurtidorParaEliminar(surtidoresEnELArchivo, tamanioArregloSurtidores);
            estacionAdministrada.eliminarSurtidor(surtidoresEnELArchivo, posicionParaEliminar, tamanioArregloSurtidores);
            std::cout<<"Se elimino correctamente el surtidor..."<<endl<<endl;
            estacionAdministrada.setNumeroSurtidores(estacionAdministrada.getNumeroSurtidores()-1);
            estacionAdministrada.setSurtidoresActivos(estacionAdministrada.getSurtidoresActivos()-1);
            delete posicionParaEliminar;
        }
        
        
        else if(opcionMenuEstacion == 3){
            consultarHistoricoSurtidor(surtidoresEnELArchivo, tamanioArregloSurtidores, estacionAdministrada);
            
        }
        else if(opcionMenuEstacion == 4){
            estacionesEnELArchivo[0].reportarCantidadLitrosVendidosCategoriaCombustible();
        }
        else if(opcionMenuEstacion == 5){
            void simularVenta();
        }
        else if(opcionMenuEstacion == 6){
            estacionAdministrada.asignarLitrosAlTanque();
        }
        
        else if(opcionMenuEstacion == 7){
            std::cout<<"Saliendo"<<endl;
            delete posicionEstacionAdministrada;
            break;
        }
        else{
            std::cout<<"Opcion no valida, ingrese una opcion nuevamente..."<<endl;
        }
    }
        
    }
    else if(opcion == 3){
        std::cout<<"Opcion 3 menu principal"<<endl;
        
    }
    else if(opcion == 4){
        std::cout<<"Opcion 4 menu principal"<<endl;
    }
    else if(opcion == 5){
        std::cout<<"Gracias por usar el sistema, vuelva pronto..."<<endl;
        escribirDatosSurtidoresEnArchivo(surtidoresEnELArchivo, tamanioArregloSurtidores);
        escribirDatosEstacionesEnArchivo(estacionesEnELArchivo, tamanioArregloEstaciones);
        delete[] estacionesEnELArchivo;
        delete[] surtidoresEnELArchivo;
        return;
        break;
    }
    else{
       std::cout<<"Opcion invalida, ingrese una nuevamente..."<<endl; 
    }
    
}
//REPORTAR VENTA
/*
string codigoSurtidor = surtidoresEnELArchivo[0].getCodigo();
string tipoCombustible = "Regular";
string metodoPago = "Tdebito";
unsigned short int cantidadCombustible = 5;
unsigned int numeroDocumento = 1022144281;
unsigned short int dineroEnCop = 5000;

surtidoresEnELArchivo[0].reportarVenta(tipoCombustible, cantidadCombustible, metodoPago, numeroDocumento,dineroEnCop, codigoSurtidor);
*/

//PEDIR DATOS SURTIDOR
/*
string codigoVenta = "sbN";
string modelo = "pro2020";
string estacionPerteneciente = "A12";
bool estado = 0;

Surtidor nuevoSurtidor(codigoVenta, modelo, estacionPerteneciente, estado);

surtidoresEnELArchivo = estacionesEnELArchivo[0].agregarSurtidor(surtidoresEnELArchivo, nuevoSurtidor, tamanioArregloSurtidores);
*/
/*
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

Station* nuevaEstacion = new Station(nombre,codigo,gerente,region,ubicacion,numeroSurtidores,surtidoresActivos);

redNacional.agregarEstacion(estacionesEnELArchivo,nuevaEstacion, tamanioArregloEstaciones);

delete[] nuevaEstacion;
*/

return;
}
