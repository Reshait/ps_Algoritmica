#ifndef __FUNCIONES_GENERALES__
#define __FUNCIONES_GENERALES__

using std::cout;
using std::cin;
using std::vector;

void pideDatos(double &valorN, double &valorK){

	do{
		cout << "Introduzca el valor N.: ";
		cin >> valorN;

		if(valorN <= 0)
			cout << "ERROR. El valor N no puede ser igual o menor que 0." << endl;
	
	}while(valorN <= 0);

	do{
		cout << "Introduzca el valor k.: ";
		cin >> valorK;

		if(valorK > valorN)
			cout << "ERROR. El valor K no puede ser mayor que el valor de N." << endl;

	}while(valorK > valorN);

}

void pideDatos(double &valorN){

	do{
		cout << "Introduzca el valor N.: ";
		cin >> valorN;

		if(valorN <= 0)
			cout << "ERROR. El valor N no puede ser igual o menor que 0." << endl;
	
	}while(valorN <= 0);

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


#endif
