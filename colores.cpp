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

tColor inicializarColor(int f) {
	tColor color;
	switch (f) { //inicializamos el color según el numero de fila
	case 0:
	case 4:
		color = ROJO;
		break;
	case 1:
	case 5:
		color = VERD;
		break;
	case 2:
	case 6:
		color = AZUL;
		break;
	case 3:
	case 7:
		color = AMAR;
		break;
	}

	return color;
}
