/*! 
  \file     cabecera.hpp
  \brief    Funciones de cabecera para mostrar mis datos personales
  \author   Teófilo Rojas Mata
  \date     28/09/2016
*/

#ifndef __CABECERA_HPP__
#define __CABECERA_HPP__

using std::cout;
using std::endl;

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
       
#endif