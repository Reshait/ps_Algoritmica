/*! 
  \file     cabecera.hpp
  \brief    Funciones de cabecera para mostrar mis datos personales
  \author   Teófilo Rojas Mata
  \date     28/09/2016
*/

#ifndef __CABECERA_HPP__
#define __CABECERA_HPP__

#include <cstdio>  // para el getchar

using std::cout;
using std::endl;
using std::cin;
/*! 
  \brief Muestra la cabecera de la práctica con mis datos personales.
  \post Ninguna
  \sa cabecera()
  \param x tipo entero con el número de la práctica.
*/
void cabecera(int x){
    system("clear");
    system("tput bold");

    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃ Teófilo Rojas Mata, Práctica " << x << " de Algorítmica ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    system("tput sgr0");
    cout << endl;
}

void introParaContinuar(){
    cout << "==========================================" << endl;
    cout << "Presione la tecla 'Intro' para continuar..." << endl;
    cin.ignore().get();
}

int menu(){
    int opcion;
    bool primeraVez = true;

    do{
        cabecera(1);
        
        cout << "1.- Para realizar el apartado de las matrices." << endl;
        cout << "2.- Para realizar el apartado de fibonacci." << endl;
        cout << "0.- Para Salir." << endl;
        
        if(primeraVez == false){
          if(opcion != 1 && opcion != 0 && opcion != 2){
              system("tput setaf 1");
              cout << "Error: Debe de introducir 0, 1 ó 2" << endl;
              system("tput sgr0");
          }
        }
        
        cout << "\tIntroduzca una opción >> ";
        cin >> opcion;
        std::getchar();
        
        if(primeraVez)
          primeraVez = false;     

    }while(opcion != 1 && opcion != 0 && opcion != 2);


    return opcion;

}
       
#endif