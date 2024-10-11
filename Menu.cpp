#include "Menu.h"

void fijarPrecios(Red& redNacional){
    cout<<"Ingrese "
    
    
}
void menuRed(Red& redNacional)
{
    while(true){
        
    cout<<"\n  --A entrado en gestón de la red--\n\n"
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
            std::cin.ignore('\n');
            cout << "\n X Entrada inválida. Intente de nuevo. X\n" << endl;
        } else {
            
    
    switch(opcion){
        case 1:
        redNacional.agregarES();
        break;
        
        case 2:
        //eliminarEst();
        break;
        
        case 3:
        //calcularVentasCadaEst();
        break;
        
        case 4:
        fijarPrecios(Red& redNacional);
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
            cout << "\n X Entrada inválida. Intente de nuevo. X\n" << endl;
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
    cout<<" A seleccionado sistema nacional de verificación de fugas\n\n"
    "--- verificando existencia de fugas...---\n\n";
}

void simularVenta()
{
    cout<<"simular venta\n";
}

void menu(Red& redNacional)
{
    while(true){
            
        
            
        cout<<"\n-----BIENVENIDO A LA RED NACIONAL DE TERMAX-----\n\n"<<
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
                cout << "\n X Entrada inválida. Intente de nuevo. X\n" << endl;
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
                cout << "\nGracias por usar el sistema. <<Hasta pronto>>\n";
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
