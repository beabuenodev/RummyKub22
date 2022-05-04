#include "fichas.h"

using namespace std;

void inicializarColor(tFicha& ficha, int f) {
	switch (f) { //inicializamos el color seg�n el numero de fila
	case 0:
	case 4:
		ficha.color = ROJO;
		break;
	case 1:
	case 5:
		ficha.color = VERD;
		break;
	case 2:
	case 6:
		ficha.color = AZUL;
		break;
	case 3:
	case 7:
		ficha.color = AMAR;
		break;
	}
}

int fichaToString(tFicha ficha) {

	int aux;
	colorTexto(ficha.color);
	if (ficha.num != -1)
		aux = ficha.num;
	else
		aux = 0;

	return aux;
}

bool operator== (const tFicha& ficha1, const tFicha& ficha2) { //operador para comprobar que dos fichas son iguales
	if (ficha1.num == ficha2.num && ficha1.color == ficha2.color)
		return true;
	else
		return false;
}

bool fichaVacia(const tFicha& ficha) { // funcion para ver si una ficha es vac�a (LIBRE, -1)
	tFicha fichavacia = { LIBRE, -1 };

	if (ficha == fichavacia)
		return true;
	else
		return false;
}

