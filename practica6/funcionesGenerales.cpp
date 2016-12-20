#include "funcionesGenerales.hpp"

bool Lugar (int fila, vector<int> vReinas)
{
	for(int i=0; i < fila; i++)
	{
		if(vReinas[i]==vReinas[fila] || abs(vReinas[i]-vReinas[fila]) == abs(i - fila))
		{
			return false;
		}
	
	}
	return true;
}

void imprimirTablero (vector<int> vReinas, int nReinas)
{
	for(int i = 0; i < nReinas; i++){
		cout << "\t"; 
		for(int j = 0; j < nReinas; j++){
			if(vReinas[i] == j+1)
			    cout << "\033[1;32m 1\033[0m" << " ";
			else
				cout << " 0 ";
		}

		cout << endl;
	}
	cout << "\t";
	for(int i = 0; i < nReinas;i++)
    	cout << "━━━";
    cout << endl;
}

void realizarXreinas ()
{
	int nReinas;
	pideNumeroDeReinas(nReinas);
	bool dibujarTableros = pideDibujarTableros();

	vector<int> vReinas(nReinas,-1);
	vReinas[0] = 0;
	int k = 0; 							// me posiciono en la primera fila
	int nSolucion = 0;

	vector < vector<int> > vSolucion; 	//Estructura de datos para guardar todas las soluciones
		
	
	while( k >= 0)
	{
		vReinas[k]++;

		while( (vReinas[k] <= nReinas) && (Lugar(k,vReinas)==false))
		{
			vReinas[k]++;
		}
		
		if(vReinas[k] <= nReinas)
		{
			if(k == nReinas-1)
			{
				if(dibujarTableros)
					imprimirTablero(vReinas, nReinas);
				vSolucion.push_back(vReinas);		
				nSolucion++;		
			}
			else
			{
				k++;
				vReinas[k] = 0;
			}
		}
		else
		{
			k--;
		}
	}

	imprimeInfoSoluciones(vSolucion, nReinas);
}


void imprimeError(string const &comparacion, int const &nReinas){
    system("tput setaf 1");
	cout << "ERROR: El número de reinas debe ser " << comparacion << " que " << nReinas << endl;
    system("tput sgr0");	
}

void pideNumeroDeReinas(int &nReinas){
	do{
		cabecera(6);		
		imprimeEnunciado();

		cout << "Introduzca un número entero de reinas..:  ";
		cin >> nReinas;	

		if(nReinas < 1){

			string comparacion;

			if(nReinas  == 0)
				comparacion = "mayor";

			imprimeError(comparacion, nReinas);

			introParaContinuar();	
		}	

	}while(nReinas < 1);

}

bool pideDibujarTableros(){
	char c;
	cout << "¿Desea dibujar Los tableros?[s/n]" << endl;
	cin >> c;
	
	if(c == 's' or c == 'S')
		return true;
	else
		return false;

}

void imprimeInfoSoluciones(vector < vector<int> > const &vSolucion, int nReinas){
	for(unsigned int i=0; i<vSolucion.size(); i++)
	{
		cout << "Solucion " << i << " -> [ ";
		for(int j = 0; j < nReinas; j++)
		{
			cout << vSolucion[i][j] << " " ;
		}
		cout << "]"<<endl;
	}

	cout << "Total soluciones: " << vSolucion.size() << endl;
}