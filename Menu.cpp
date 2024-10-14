#include "Menu.h"

void agregarEstacion(){
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
        cout<<"Ingrese gerente de la estacion, formato 'nombre apellido'\n>>>";
        cin.clear();
        getline(cin,gerente);
        if(!esValidoFormatoGerente(gerente)){
            
            cout<<"\nX Formato invalido, intente de nuevo X\n";
        }
        else{
            break;
        }
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
        if(!esValidoFormatoUbicacion(ubicacion)){
            cout<<"\nX Formato invalido, intente de nuevo X\n";
        }
        else{
            break;
        }
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
        
        if (cin.fail() || opcion < 1 || opcion > 4) {
            cin.clear(); 
            std::cin.ignore(1000,'\n');
            cout << "\n X Formato invalido, Intente de nuevo. X\n";
        } 
        else {
            switch(opcion){
                unsigned short int _precioNorteRegular;
                unsigned short int _precioNortePremium;
                unsigned short int _precioNorteEcoextra;
                unsigned short int _precioCentroRegular;
                unsigned short int _precioCentroPremium;
                unsigned short int _precioCentroEcoextra;
                unsigned short int _precioSurRegular;
                unsigned short int _precioSurPremium;
                unsigned short int _precioSurEcoextra;

                case 1:
                cout<<"\nmodificar region norte\n";
                while(true){
                    cout<<"precio de Regular\n>>>";
                    cin>>_precioNorteRegular;
                    
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout<<"\nX Formato invalido, intente de nuevo X\n";
                    }else{
                        break;
                    }
                }
                redNacional.setPrecioNorteRegular(_precioNorteRegular);
                while(true){
                    cout<<"precio de Premium\n>>>";
                    cin>>_precioNortePremium;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout<<"\nX Formato invalido, intente de nuevo X\n";
                    }else{
                        break;
                    }
                }
                redNacional.setPrecioNortePremium(_precioNortePremium);
                while(true){
                    cout<<"precio de Ecoextra\n>>>";
                    cin>>_precioNorteEcoextra;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout<<"\nX Formato invalido, intente de nuevo X\n";
                    }else{
                        break;
                    }
                }
                redNacional.setPrecioNorteEcoextra(_precioNorteEcoextra);
                break;
                
                case 2:
                cout<<"\nmodificar region centro\n";
                while(true){
                    cout<<"precio de Regular\n>>>";
                    cin>>_precioCentroRegular;
                        if(cin.fail()){
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout<<"\nX Formato invalido, intente de nuevo X\n";
                    }else{
                        break;
                    }
                }
                redNacional.setPrecioCentroRegular(_precioCentroRegular);
                while(true){
                    cout<<"precio de Premium\n>>>";
                    cin>>_precioCentroPremium;
                        if(cin.fail()){
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout<<"\nX Formato invalido, intente de nuevo X\n";
                    }else{
                        break;
                    }
                }
                redNacional.setPrecioCentroPremium(_precioCentroPremium);
                while(true){
                    cout<<"precio de Ecoextra\n>>>";
                    cin>>_precioCentroEcoextra;
                        if(cin.fail()){
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout<<"\nX Formato invalido, intente de nuevo X\n";
                    }else{
                        break;
                    }
                }
                redNacional.setPrecioCentroEcoextra(_precioCentroEcoextra);
                break;
                
                case 3:
                cout<<"\n modificar region sur\n";
                while(true){
                    cout<<"precio de Regular\n>>>";
                    cin>>_precioSurRegular;
                        if(cin.fail()){
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout<<"\nX Formato invalido, intente de nuevo X\n";
                    }else{
                        break;
                    }
                }
                redNacional.setPrecioSurRegular(_precioSurRegular);
                while(true){
                    cout<<"precio de Premium\n>>>";
                    cin>>_precioSurPremium;
                        if(cin.fail()){
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout<<"\nX Formato invalido, intente de nuevo X\n";
                    }else{
                        break;
                    }
                }
                redNacional.setPrecioSurPremium(_precioSurPremium);
                while(true){
                    cout<<"precio de Ecoextra\n>>>";
                    cin>>_precioSurEcoextra;
                        if(cin.fail()){
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout<<"\nX Formato invalido, intente de nuevo X\n";
                    }else{
                        break;
                    }
                }
                redNacional.setPrecioSurEcoextra(_precioSurEcoextra);
                break;
                
                case 4:
                break;
                
                default:
                break;
            }
        cout<<redNacional.getPrecioNorteRegular()<<endl;
        cout<<redNacional.getPrecioNortePremium()<<endl;
        cout<<redNacional.getPrecioNorteEcoextra()<<endl;
        cout<<redNacional.getPrecioCentroRegular()<<endl;
        cout<<redNacional.getPrecioCentroPremium()<<endl;
        cout<<redNacional.getPrecioCentroEcoextra()<<endl;
        cout<<redNacional.getPrecioSurRegular()<<endl;
        cout<<redNacional.getPrecioSurPremium()<<endl;
        cout<<redNacional.getPrecioSurEcoextra()<<endl;


        if(opcion == 4){
            break;
        }
        }
    }   
    
}
void menuRed(Red& redNacional)
{
    while(true){
        
    cout<<"\n  --A entrado en gestión de la red--\n\n"
        "1.-Agregar estacion de servicio.\n"
        "2.-Eliminar una estación de servicio.\n"
        "3.-Calcular monto total de ventas de cada E/S\n"
        "4.-Fijar precios del combustible\n"
        "5.-Volver al menú principal\n"
        ">>> ";
    
    unsigned short int opcion;
    
    cin>>opcion;
    
    if (cin.fail() || opcion < 1 || opcion > 5) {
            cin.clear(); 
            cin.ignore(1000,'\n');
            cout << "\n X Formato invalido, intente de nuevo X\n" << endl;
        } else {
            
    
    switch(opcion){
        case 1:
        agregarEstacion();
        break;
        
        case 2:
        redNacional.borrarES();
        break;
        
        case 3:
        //calcularVentasCadaEst();
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
}

void menuEstacion()
{
    while(true){
        
    cout<<"\n  --A entrado en gestión de estacion de servicio--\n\n"
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
    
    if (cin.fail() || opcion < 1 || opcion > 7) {
            cin.clear(); 
            std::cin.ignore(1000, '\n');
            cout << "\n X Formato inválido, intente de nuevo. X\n" << endl;
        } else {
            
    
    switch(opcion){
        case 1:
        //aggElimSurti();
        break;
        
        case 2:
        //actDesactSurti();
        break;
        
        case 3:
        //historicoCadaSurti();
        break;
        
        case 4:
        //litrosVendidos();
        break;
        
        case 5:
        //simularventa();
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
}

void verificarFugas()
{
    cout<<"\n A seleccionado sistema nacional de verificación de fugas\n\n"
        "--- verificando existencia de fugas...---\n\n";
}

void simularVenta()
{
    cout<<"\nSimular venta\n";
}

void menu(Red& redNacional)
{
    while(true){
            
        
            
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
        
        if (cin.fail() || opcion < 1 || opcion > 5) {
                cin.clear(); 
                std::cin.ignore(1000, '\n');
                cout << "\n X Formato invalido, intente de nuevo X\n" << endl;
            } else {
                
        
        switch(opcion){
            case 1:
            menuRed(redNacional);
            break;
            
            case 2:
            menuEstacion();
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
}
