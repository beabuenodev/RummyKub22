//FP2 - RummyKub V.2
//Nombre y Apellidos: Beatriz Bueno Almagro 1ºB

#include "colores.h"

using namespace std;

void colorTexto(tColor color) {
	switch (color) {
	case AMAR:
		cout << "\033[1;40;33m";
		break;
	case AZUL:
		cout << "\033[40;34m";
		break;
	case ROJO:
		cout << "\033[40;31m";
		break;
	case VERD:
		cout << "\033[40;32m";
		break;
	case LIBRE:
		cout << "\033[40;37m";
		break;
	}
}