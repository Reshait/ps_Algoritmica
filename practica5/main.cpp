#include "cabecera.hpp"
#include "funcionesGenerales.hpp"
#include "moneda.hpp"

using namespace std;

int main(){
	int opcion;
	cabecera(4);

	do{
//		vMonetario.clear();
//		vSolucion.clear();

		opcion = menu();

		switch(opcion){

				
			case 1:
				cabecera(5);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ Cambio de Monedas ┃" << endl;
				cout << "\t┗━━━━━━━━━━━━━━━━━━━┛" << endl;	

				realizarCambio();		

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