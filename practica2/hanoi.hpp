#ifndef __HANOI__
#define __HANOI__
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include "funcionesGenerales.hpp"
using std::vector;
using std::string;

struct Torre
{
    vector<int> v;
    string nombre;
};


template <class T>
void mueveDisco(vector<T> &a, vector<T> &b) {
	b.push_back(a.back());
	a.pop_back();
}

template <class T>
void imprimeVector(const std::vector<T> &vectorTiempos){
    for(unsigned int i = 0; i < vectorTiempos.size(); i++)
        cout << vectorTiempos.at(i) << "\t"; 
    cout << endl;     
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
            imprimeVector(c);  
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


void hanoi(vector<string> &vOrigen, vector<string> &vAux, vector<string> &vDestino, int nDiscos, bool quiereImprimir){
    if(nDiscos == 1){
        mueveDisco(vOrigen, vDestino); 
        if(quiereImprimir)
            imprime(vOrigen,vAux,vDestino);
    }

    else{
        hanoi(vOrigen, vDestino, vAux, nDiscos - 1, quiereImprimir);
        if(vOrigen.size() > 1){
            mueveDisco(vOrigen, vDestino);  //para nDiscos 2 está moviendo de origen a Auxiliar// Destino = auxiliar cuando nDiscos 2
            if(quiereImprimir)
                imprime(vOrigen,vAux,vDestino);     
            hanoi(vAux, vOrigen, vDestino, nDiscos - 1, quiereImprimir); 
        }            
    }
}

#endif