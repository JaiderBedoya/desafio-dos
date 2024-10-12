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
                case 1:
                cout<<"\nmodificar region norte\n";
                break;
                
                case 2:
                cout<<"\nmodificar region centro\n";
                break;
                
                case 3:
                cout<<"\n modificar region sur\n";
                break;
                
                case 4:
                break;
                
                default:
                break;
            }
        
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
            std::cin.ignore(1000,'\n');
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

