/*! 
  \file     fibonacci.hpp
  \brief    Función para calcular el número de fibonacci.
  \author   Teófilo Rojas Mata
  \date     03/10/2016
*/

#ifndef __FIBONACCI_H__
#define __FIBONACCI_H__

/*! 
  \brief fibonacci calcula el valor de la ecuación de fibonacci.
  \post Ninguna
  \sa fibonacci()
  \param n, entero, número inicial.
*/
int fibonacci(int n){
    if(n == 0 || n == 1)
       return n;
    else
       return fibonacci(n - 2) + fibonacci(n - 1);
}

#endif