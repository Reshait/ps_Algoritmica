#ifndef __FUNCIONES_GENERALES__
#define __FUNCIONES_GENERALES__

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
/*	double determinante = 0, fProduct = 0;

	if ( matriz.size() == 2){
	    determinante = matriz[0][0] * matriz[1][1] - matriz[1][0] * matriz[0][1];
	}
		    
	else if (matriz.size() == 1)
		determinante = matriz[0][0];

	else {
	    for (unsigned int i = 0; i < matriz.size(); i++){
	        //  Multiplicacion de valores verticales de izquierda a derecha...
	        fProduct = 1.0;
	        for (unsigned int j = 0; j < matriz.size(); j++)
	            fProduct *= matriz[(i + j) % matriz.size()][j];
	        determinante += fProduct;
		     
	        //  Multiplicacion de valores verticales de derecha a izquierda...
	        fProduct = 1.0;
	        for (unsigned int j = 0; j < matriz.size(); j++)
	            fProduct *= matriz[(matriz.size() - 1) - ((i + j) % matriz.size())][j];
	        determinante -= fProduct;
	    }
	}
		     
	return determinante;	
*/
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

//	imprimeMatriz(matriz);

	cout << "Determinante ..:\t" << calculaDeterminante(matriz) << endl;

}

#endif
