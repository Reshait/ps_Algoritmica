#ifndef __HANOI__
#define __HANOI__
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
using std::vector;
using std::string;
using std::stringstream;

struct Torre
{
    vector<int> v;
    string nombre;
};
//#include "funcionesGenerales.hpp"

/*
Entrada: Tres pilas de números origen, auxiliar, destino, con la pila origen ordenada

Salida: La pila destino

    si origen == { 1 } {\displaystyle \scriptstyle ==\{1\}} {\displaystyle \scriptstyle ==\{1\}} entonces
        mover el disco 1 de pila origen a la pila destino (insertarlo arriba de la pila destino)
        terminar
    si no
        hanoi( { 1 , … , n − 1 } {\displaystyle \scriptstyle \{1,\dots ,n-1\}} {\displaystyle \scriptstyle \{1,\dots ,n-1\}},origen,destino, auxiliar)     //mover todas las fichas menos la más grande (n) a la varilla auxiliar
    mover disco n a destino                //mover la ficha grande hasta la varilla final
    hanoi (auxiliar, origen, destino)          //mover todas las fichas restantes, 1...n–1, encima de la ficha grande (n)
    terminar

*/

void mueveDisco(vector<int> &a, vector<int> &b) {
	b.push_back(a.back());
	a.pop_back();
}

void mueveDisco(vector<string> &a, vector<string> &b) {
    b.push_back(a.back());
    a.pop_back();
}

void imprime(const vector<string> &a, const vector<string> &b, const vector<string> &c){
    string origen = "Orig..:";
    string auxiliar = "Auxi..:";

    if (a[0].compare(origen) == 0){
        imprimeVector(a);
        
        if (b[0].compare(auxiliar) == 0){
            imprimeVector(b); 
            imprimeVector(c);             
        }
        else{  
            imprimeVector(c);  //Este me falla
            imprimeVector(b); 
        }
        
        cout << endl;
    } 

    else if (b[0].compare(origen) == 0){
        imprimeVector(b);
        
        if (c[0].compare(auxiliar) == 0){
            imprimeVector(c); 
            imprimeVector(a);             
        }
        else{      
            imprimeVector(a); 
            imprimeVector(c); 
        }
        
        cout << endl;
    }  

    else if (c[0].compare(origen) == 0){
        imprimeVector(c);
        
        if (b[0].compare(auxiliar) == 0){
            imprimeVector(b); 
            imprimeVector(a);             
        }
        else{      
            imprimeVector(a); 
            imprimeVector(b); 
        }
        
        cout << endl;
    } 
}   

void hanoi(vector<string> &vOrigen, vector<string> &vAux, vector<string> &vDestino, int nDiscos){
    if(nDiscos == 1){
        mueveDisco(vOrigen, vDestino); 
        imprime(vOrigen,vAux,vDestino);
    }

    else{
        hanoi(vOrigen, vDestino, vAux, nDiscos - 1);
        if(vOrigen.size() > 1){
        mueveDisco(vOrigen, vDestino);  //para nDiscos 2 está moviendo de origen a Auxiliar// Destino = auxiliar cuando nDiscos 2
        imprime(vOrigen,vAux,vDestino);     
        hanoi(vAux, vOrigen, vDestino, nDiscos - 1); 
        }            
    }
}

/*
void rellenaVectorOrigen(int num, vector<int> &vOrigen){
	for(int i = num; i > 0; i--)
		vOrigen.push_back(i);
}
*/

void rellenaVectorOrigen(int num, vector<string> &vOrigen){
    stringstream aux;
    for(int i = num; i > 0; i--){
        aux << i;
        vOrigen.push_back(aux.str());
        aux.str(std::string());
    }
}
#endif