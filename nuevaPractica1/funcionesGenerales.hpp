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
	for(int i= 0; i < original.size(); i ++)
		for(int j = 0; j < original.size(); j++)
			copia[i][j] = original[i][j];
}


void imprimeMatriz(const vector<vector<double> > &matriz){
	int cuentaIntro = 0;
	for(int i = 0; i < matriz.size(); i++){
		cout << "\t" ;
		for(int j = 0; j < matriz.size(); j++){
			cout << matriz[i][j] << " \t";
			
			cuentaIntro ++;					
			if(cuentaIntro == matriz.size()){
				cout << endl;
				cuentaIntro = 0;
			}
		}
	}
}

void generaMatrizValoresAleatorios(int tam){
	vector<vector<double> > matriz (tam, vector<double> (tam));

	for(int i = 0; i < tam; i++)
		for(int j = 0; j < tam; j++)
			matriz[i][j] = -10+((double)rand() /RAND_MAX) * (20);

	imprimeMatriz(matriz);

}



#endif
