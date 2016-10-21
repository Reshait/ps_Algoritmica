#ifndef __HANOI__
#define __HANOI__
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using std::vector;
using std::string;

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


// sacado de http://codereview.stackexchange.com/questions/116312/towers-of-hanoi-redux

    void muestra(std::string const &etiqueta, vector<int> c) {
        std::cout << etiqueta;
        std::copy(c.begin(), c.end(), std::ostream_iterator<int>(std::cout, "\t"));
        std::cout << "\n";
    }

    void imprime(const vector<int> &a, const vector<int> &b, const vector<int> &c){
        muestra("Orig:\t ", a);
        muestra("Auxi:\t ", b);
        muestra("Dest:\t ", c);
        std::cout << "\n";
    }

/*
void hanoi(int n,int com, int aux, int fin){

if(n==1){
printf(“%c->%c”,com,fin);
}
else{
hanoi(n-1,com,fin,aux);
printf(“\n%c->%c\n”,com,fin);
hanoi(n-1,aux,com,fin);
}
}
*/

/*
void hanoi(vector<int> &vOrigen, vector<int> &vAux, vector<int> &vDestino,int nDiscos){

	if(nDiscos == 1){
 //       imprime(vOrigen,vAux,vDestino);     
        mueveDisco(vOrigen, vDestino);   
 //       imprime(vOrigen,vAux,vDestino);     
      

	}

	else{
		hanoi(vOrigen, vDestino, vAux, nDiscos - 1);
		mueveDisco(vOrigen, vDestino);
        if(nDiscos % 2)
            imprime(vOrigen,vAux,vDestino);             
        else
             imprime(vDestino,vAux,vOrigen);                      
		hanoi(vAux, vOrigen, vDestino, nDiscos - 1);
	}
} 
*/

void displayTowers() {
    cout << "src: ";
    for (vector<int >::const_iterator iter = source.begin(); iter != source.end(); iter++)
        cout << *iter << " ";
    cout << " | ";
    cout << "dest: ";
    for (vector<int >::const_iterator iter = destin.begin(); iter != destin.end(); iter++)
        cout << *iter << " ";
    cout << " | ";
    cout << "temp: ";
    for (vector<int >::const_iterator iter = tempo.begin(); iter != tempo.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}
    
void hanoi(vector<int> &vOrigen, vector<int> &vAux, vector<int> &vDestino,int nDiscos){

    if (nDiscos > 0) {
        hanoi(vOrigen, vAux, vDestino, size - 1);
        vOrigen.push_back(vDestino.back());
        vDestino.pop_back();
        displayTowers();
        hanoiTower(vAux, vDestino, vOrigen, size - 1);
     }
}
/*
void hanoi(vector<int> &vOrigen, vector<int> &vAux, vector<int> &vDestino, unsigned int &nMovimientos){
	assert(vOrigen.size() >= 0);
	vector<int> vOrigenMenosUno;

	nMovimientos++;

	if(vOrigen.size() == 1){
		vDestino.push_back(vOrigen[0]);
		vOrigen.pop_back();
	}
	else{
		vOrigenMenosUno = vOrigen;
		vOrigenMenosUno.pop_back();
		hanoi(vOrigenMenosUno, vAux, vDestino, nMovimientos);			
	}
	vDestino.push_back(vOrigen[vOrigen.size()-1]);
	vOrigen.pop_back();

	hanoi(vAux, vOrigen, vDestino, nMovimientos);

}
*/
void rellenaVectorOrigen(int num, vector<int> &vOrigen){
	for(int i = num; i > 0; i--)
		vOrigen.push_back(i);
}

#endif