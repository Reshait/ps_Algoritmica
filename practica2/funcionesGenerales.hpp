#ifndef __FUNCIONES_GENERALES__
#define __FUNCIONES_GENERALES__

#include <cmath>

using std::cout;
using std::cin;
using std::vector;

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

void pideDatos(double &valorN){

	do{
		cout << "Introduzca el valor N (cantidad de discos).: ";
		cin >> valorN;

		if(valorN <= 0)
			cout << "ERROR. El valor N no puede ser igual o menor que 0." << endl;
	
	}while(valorN <= 0);

}

    /*!\brief Imprime vector de tiempos
    */
template <class T>
void imprimeVector(const std::vector<T> &vectorTiempos){
	for(unsigned int i = 0; i < vectorTiempos.size(); i++)
		cout << vectorTiempos.at(i) << "\t"; 
	cout << endl;     
}


void copiaMatriz(const vector<vector<double> > &original, vector<vector<double> > &copia){
	for(unsigned int i= 0; i < original.size(); i ++)
		for(unsigned int j = 0; j < original.size(); j++)
			copia[i][j] = original[i][j];
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

double tiempoEstimado(const vector<double> &vAs, const int &Ni){
	double tiempoEstimado = 0.0;

	for(unsigned int i = 0; i < vAs.size(); i++)
		tiempoEstimado += vAs[i] * pow(Ni,i);

	return tiempoEstimado;
}

void microSegundosAanios(double microSegRecibidos){
  
//	double microsegundos = 0.0;
	double segundos = 0.0;  
	double minutos = 0.0;
	double horas = 0.0;
	double dias = 0.0;
	double meses = 0.0;
	double anios = 0.0;
  
	if(microSegRecibidos >= pow(10,6)){
		segundos = microSegRecibidos/pow(10,6);     
//		microsegundos = fmod(microSegRecibidos, pow(10,6)); 
	  
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

void prediccion(vector<double> vAs){
	bool quierePredecir = 0;
	int nPredicho = 0;
	
	do{
		cout << endl;
		cout << "¿Desea realizar una predicción?" << endl;
		cout << "0.- Para terminar" << endl;
		cout << "1.- Si quiere realizar una predicción para un determinado N" << endl;
		cout << "\tIntroduzca una opción >> ";
		cin >> quierePredecir;
	}while(quierePredecir != 1 && quierePredecir != 0);

	if(quierePredecir){
		cout << "Introduzca el valor de n a predecir..: " << endl;
		cin >> nPredicho;
//		tiempoEstimado(vAs, nPredicho);
		microSegundosAanios(tiempoEstimado(vAs, nPredicho));
	}	
}

#endif
