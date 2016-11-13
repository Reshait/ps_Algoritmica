#include "cabecera.hpp"
#include "funcionesGenerales.hpp"
#include "moneda.hpp"

using namespace std;

int main(){
	int opcion;
	cabecera(4);
	Moneda M("hola", 5);

	do{
		opcion = menu();

		switch(opcion){

				
			case 1:
				cabecera(4);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ Cambio de Monedas ┃" << endl;
				cout << "\t┗━━━━━━━━━━━━━━━━━━━┛" << endl;	

				cout << M;

//				cin >> M;

//				cout << M;

				introParaContinuar();
			break;


			case 0:
				cabecera(4);
				cout << "Saliendo ..." << endl;
			break;	


			default:
				cabecera(4);
				cout << "Opción introducida incorrecta." << endl;
				introParaContinuar();
			break;	
		}

	}while(opcion != 0);

}