#ifndef __FUNCIONES_GENERALES__
#define __FUNCIONES_GENERALES__

#include <cmath>
#include "tiempo.hpp"

using std::cout;
using std::cin;
using std::vector;

void pideDatos(int &valorMin, int &valorMax, int &valorInc){
	cout << "Introduzca el valor mínimo.: ";
	cin >> valorMin;

	do{
		cout << "Introduzca el valor máximo.: ";
		cin >> valorMax;

		if(valorMax <= valorMin)
			cout << "ERROR. El valor MÁXIMO no puede ser igual o menor que el valor MÍNIMO." << endl;
	
	}while(valorMax <= valorMin);

	do{
		cout << "Introduzca el valor incremental.: ";
		cin >> valorInc;

		if(valorInc < 1)
			cout << "ERROR. El valor INCREMENTAL no puede ser menor que 1." << endl;

	}while(valorInc < 1);

}


    /*!\brief Imprime vector de tiempos
    */
void imprimeVector(const std::vector<double> &vectorTiempos){
	for(unsigned int i = 0; i < vectorTiempos.size(); i++)
		cout << vectorTiempos.at(i) << "\t";

	cout << endl;      
}


void copiaMatriz(const vector<vector<double> > &original, vector<vector<double> > &copia){
	for(unsigned int i= 0; i < original.size(); i ++)
		for(unsigned int j = 0; j < original.size(); j++)
			copia[i][j] = original[i][j];
}


int fibonacci(int n){
    if(n == 0 || n == 1)
       return n;
    else
       return fibonacci(n - 2) + fibonacci(n - 1);
}


void imprimeMatriz(const vector<vector<double> > &matriz){
	unsigned int cuentaIntro = 0;
	for(unsigned int i = 0; i < matriz.size(); i++){
		cout << "\t" ;
		for(unsigned int j = 0; j < matriz.size(); j++){
			cout << matriz[i][j] << " \t";
			
			cuentaIntro ++;					
			if(cuentaIntro == matriz.size()){
				cout << endl;
				cuentaIntro = 0;
			}
		}
	}
}


double calculaDeterminante(vector<vector<double> > matriz){

    double factor, determ;
    int i,j,k,n = matriz.size();

    for (k = 0; k < n - 1; k++) {   
        for (i = k+1; i < n;  i++) {
            factor = matriz[i][k]/matriz[k][k];
            for (j = k+1; j < n ; j++) {
                matriz[i][j] = matriz[i][j] - factor * matriz[k][j];
            }
        }
    }

    determ = 1.;

    for (i = 0; i < n; i++) 
        determ = determ * matriz[i][i];

    return determ;
}

void generaMatrizValoresAleatorios(int tam){
	vector<vector<double> > matriz (tam, vector<double> (tam));

	for(int i = 0; i < tam; i++)
		for(int j = 0; j < tam; j++)
			matriz[i][j] = -10+((double)rand() /RAND_MAX) * (20);

	cout << "Determinante ..:\t" << calculaDeterminante(matriz) << endl;
}


void rellenaTiemposObservados(const int apartado, const int &valorMin,const int &valorMax,const int &valorInc,vector<double> &vTiemposObservados){
	Clock Cronometro;

	for(int i = valorMin; i <= valorMax; i += valorInc){
		if(apartado == 1){
			Cronometro.start();
			generaMatrizValoresAleatorios(i);
			Cronometro.stop();					
		}
		else{
			Cronometro.start();
			cout << "El valor resultante a Fibonacci " << i << " es..: " << fibonacci(i) << endl;		
			Cronometro.stop();					
		}
				
		cout << "Han transcurrido..:\t" << Cronometro.elapsed() << " µs" << endl;
					
		vTiemposObservados.push_back(Cronometro.elapsed());		
		cout << endl;
	}	
}


double tiempoEstimado(const vector<double> &vAs, const int &Ni){
	double tiempoEstimado = 0.0;

	for(unsigned int i = 0; i < vAs.size(); i++)
		tiempoEstimado += vAs[i] * pow(Ni,i);

	return tiempoEstimado;
}


void calculaTiemposEstimados(const int &valorMin, const int &valorMax, const int &valorInc, vector<double> &vTiemposEstimados, vector<double> &vAs){
	for(int i = valorMin; i <= valorMax; i += valorInc){
		vTiemposEstimados.push_back(tiempoEstimado(vAs, i));
	}
}


void imprimeResultadosEnFichero(const int &valorMin, const int &valorInc, const vector<double> &vTiemposObservados, const vector<double> &vTiemposEstimados){
	std::ofstream fo;

	fo.open("Datos.txt"); 
	
	for(unsigned int i = 0, ni = valorMin; i < vTiemposObservados.size(); i++, ni += valorInc)
		fo << ni << " " << vTiemposObservados[i] << " " << vTiemposEstimados[i] << "\n";
	
	fo.close();	
}
#endif
