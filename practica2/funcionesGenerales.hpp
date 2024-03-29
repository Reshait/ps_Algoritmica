#ifndef __FUNCIONES_GENERALES__
#define __FUNCIONES_GENERALES__

#include <sstream>
#include <cmath>
#include <cstring>
#include "tiempo.hpp"
#include "combinatorio.hpp"
#include "hanoi.hpp"

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::stringstream;


void pideDatos(int &desde, int &hasta){

	do{
		cout << "Introduzca el valor DESDE el que realizar iteraciones.: ";
		cin >> desde;

		if(desde <= 0)
			cout << "ERROR. El valor DESDE no puede ser igual o menor que 0." << endl;
	
	}while(desde <= 0);

	do{
		cout << "Introduzca el valor HASTA el que realizar iteraciones.: ";
		cin >> hasta;

		if(hasta <= desde)
			cout << "ERROR. El valor HASTA no puede ser igual o menor que el valor de DESDE." << endl;
	
	}while(hasta <= desde);	

}


void pideDatos(int &valorN){

	do{
		cout << "Introduzca el valor N (cantidad de discos).: ";
		cin >> valorN;

		if(valorN <= 0)
			cout << "ERROR. El valor N no puede ser igual o menor que 0." << endl;
	
	}while(valorN <= 0);

}


void copiaMatriz(const vector<vector<double> > &original, vector<vector<double> > &copia){
	for(unsigned int i= 0; i < original.size(); i ++)
		for(unsigned int j = 0; j < original.size(); j++)
			copia[i][j] = original[i][j];
}


template <class T>
void imprimeVector(const std::vector<T> &vectorTiempos){
    for(unsigned int i = 0; i < vectorTiempos.size(); i++)
        cout << vectorTiempos.at(i) << "\t"; 
    cout << endl;     
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


int preguntaPorImpresion(){
	int quiereImprimir; 
	do{
		cout << "¿Quiere observar la representación por pantalla? " << endl;
		cout << "0.- NO" << endl;
		cout << "1.- SI" << endl;
		cin >> quiereImprimir;	

	}while(quiereImprimir != 0 && quiereImprimir !=1);


	return quiereImprimir;
}


void rellenaVectorOrigen(int num, vector<string> &vOrigen){
    stringstream aux;
    for(int i = num; i > 0; i--){
        aux << i;
        vOrigen.push_back(aux.str());
        aux.str(std::string());
    }
}


void rellenaTiemposObservados(const int apartado, const int &valorMin,const int &valorMax, vector<double> &vTiemposObservados){
	Clock Cronometro;
	double sumTiempo;
	vector<stTabla> vEstructuras;
	vector<string> vOrigen, vDestino, vAux;
	int quiereImprimir;

	if(apartado == 4)
		quiereImprimir = preguntaPorImpresion();


	for(int i = valorMin; i <= valorMax; i ++){
		sumTiempo = 0;

		if(apartado == 1){  			// apartado combinatorio - Recursividad Cnk = Cn-1,k-1 + Cn-1,k.

			for(int j = 0; j <= i; j++){
				Cronometro.start();
				cout << combinatorioRecursivo(i, j) << endl;
				Cronometro.stop();	
				sumTiempo += Cronometro.elapsed();
			}

		}
		else if(apartado == 2){			// apartado combinatorio - Recursividad con tabla.
			for(int j = 0; j <= i; j++){
				Cronometro.start();
				cout << combinatorioRecursivo(i, j, vEstructuras) << endl;
				Cronometro.stop();	
				sumTiempo += Cronometro.elapsed();
			}
		}

		else if(apartado == 3){			// apartado combinatorio - Algoritmo NO recursivo.
			for(int j = 0; j <= i; j++){
				Cronometro.start();		
				cout << combinatorioIterativo(i,j) << endl;
				Cronometro.stop();	
				sumTiempo += Cronometro.elapsed();						
			}	
			
		}

		else{							// apartado Hanoi

			inicializaTorres(vOrigen, vDestino, vAux);

			rellenaVectorOrigen(i, vOrigen);

			if(quiereImprimir){
				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
				cout << endl;
				cout << "Se parte de las siguientes Torres..:" << endl;
				imprime(vOrigen,vAux,vDestino);
				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
			}

			Cronometro.start();
			hanoi(vOrigen, vDestino, vAux, vOrigen.size(), quiereImprimir);
			Cronometro.stop();
			sumTiempo = Cronometro.elapsed();					
		}				
		
		cout << "Han transcurrido..:\t" << Cronometro.elapsed() << " µs" << endl;
		
		if(apartado == 2 || apartado == 3)
			sumTiempo = sumTiempo/(i + 1);

		vTiemposObservados.push_back(sumTiempo);
		cout << endl;
	}	
}

//esta función realiza el ajuste a polinómico o exponencial
double tiempoEstimado(const int apartado, const vector<double> &vAs, const int &Ni){
	double tiempoEstimado = 0.0;

	for(unsigned int i = 0; i < vAs.size(); i++){
		if(apartado == 1)  					// Ajuste tipo Polinómico
			tiempoEstimado += vAs[i] * pow(Ni,i);
		else if(apartado == 2)				// Ajuste tipo Exponencial
			tiempoEstimado += vAs[i] * pow(2,i*Ni);
	}

	return tiempoEstimado;
}


void calculaTiemposEstimados(const int apartado, const int &valorMin, const int &valorMax, vector<double> &vTiemposEstimados, vector<double> &vAs){
	for(int i = valorMin; i <= valorMax; i ++){
		vTiemposEstimados.push_back(tiempoEstimado(apartado, vAs, i));
	}
}


void imprimeResultadosEnFichero(const int &valorMin, const vector<double> &vTiemposObservados, const vector<double> &vTiemposEstimados){
	std::ofstream fo;

	fo.open("Datos.txt"); 
	
	for(unsigned int i = 0, ni = valorMin; i < vTiemposObservados.size(); i++, ni ++)
		fo << ni << " " << vTiemposObservados[i] << " " << vTiemposEstimados[i] << "\n";
	
	fo.close();	
}


double tiempoEstimado(const vector<double> &vAs, const int &Ni){
	double tiempoEstimado = 0.0;

	for(unsigned int i = 0; i < vAs.size(); i++)
		tiempoEstimado += vAs[i] * pow(Ni,i);

	return tiempoEstimado;
}


void microSegundosAanios(double microSegRecibidos){
  
	double segundos = 0, minutos = 0, horas = 0, dias = 0, meses = 0, anios = 0;  
  
	if(microSegRecibidos >= pow(10,6)){
		segundos = microSegRecibidos/pow(10,6);     
	  
		if(segundos >= 60){
	    	minutos = segundos/60;
	    	segundos = fmod(segundos, 60);  

	    	if(minutos >= 60){
	    		horas = minutos/60;
	      		minutos = fmod(minutos, 60);

	      		if(horas >= 24){
	        		dias = horas/24;
	        		horas = fmod(horas, 24);
	          
	        		if(dias >= 30){
	          			meses = dias/30;
	          			dias = fmod(dias, 30);
	    
	          			if(meses >= 12){
	            			anios = meses/12;
	            			meses = fmod(meses, 12);
	          			}
	        
	        		} 
	      
	      		}
	    
	    	}   
	  
	  	} 
  
	}

	cout << "Los microsegundos " << microSegRecibidos << " equivalen a..:" << endl;
	if(anios > 0)
		cout << (int)anios << " años, ";
	if(meses > 0)
		cout << (int)meses << " meses, ";
	if(dias > 0)
		cout << (int)dias << " días, ";
 	cout  << (int)horas << " horas, "  << (int)minutos << " minutos, " <<  (int)segundos << " segundos";
 	cout << endl;

}


//apartado 1 = polinómico, 2 = exponencial
void prediccion(const int apartado, vector<double> vAs){
	int quierePredecir = 0;
	int nPredicho = 0;
	
	do{
		cout << "¿Desea realizar una predicción?" << endl;
		cout << "0.- No" << endl;
		cout << "1.- Si" << endl;            
        cin >> quierePredecir;
		
		if(	quierePredecir != 0 && quierePredecir != 1){
           	system("tput setaf 1");
           	cout << "Error: Debe de introducir 0 ó 1" << endl;
           	system("tput sgr0");
        }

        if(quierePredecir == 1){
			cout << "Introduzca el valor de n a predecir..: " << endl;
			cin >> nPredicho;
			microSegundosAanios(std::abs(tiempoEstimado(apartado, vAs, nPredicho)));
		}

	}while(quierePredecir != 1 && quierePredecir != 0);

}


template <class T>
void inicializaVectores(vector<T> &vTiemposObservados, vector<T> &vTiemposEstimados, vector<T> &vAs){
		vTiemposObservados.clear();
		vTiemposEstimados.clear();
		vAs.clear();
}

template <class T>
void imprimeEcuacionAjuste(int apartado, vector<T> &vAs){
	cout << "t = ";
	if(apartado == 1 || apartado == 4){
		for(unsigned int i = 0; i < vAs.size(); i++){
			if(i == 0)
				cout << vAs[i] << " + ";
			else if(i == vAs.size()-1)
				cout << vAs[i] << "*2^n";
			else
				cout << vAs[i] << "n^" << i << " + ";		
		}		
	}
	else{
		for(unsigned int i = 0; i < vAs.size(); i++){
			if(i == 0)
				cout << vAs[i] << " + ";
			else if(i == vAs.size()-1)
				cout << vAs[i] << "n^" << i;
			else
				cout << vAs[i] << "n^" << i << " + ";		
		}			
	}
	cout << endl;
}

//void imprimeVector(const std::vector<Moneda> &vMonetario);

#endif
