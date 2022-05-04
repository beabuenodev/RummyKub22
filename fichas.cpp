#include "colores.h"
#include "fichas.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string fichaToString(tFicha ficha) {

	string aux;

	switch (ficha.color) { // Construye un string para mostrar la ficha
	case ROJO: //Primero con el color
		aux = "rojo ";
		break;
	case VERD:
		aux = "verd ";
		break;
	case AZUL:
		aux = "azul ";
		break;
	case AMAR:
		aux = "amar ";
		break;
	case LIBRE:
		aux = "    ";
		break;
	}

	aux += to_string(ficha.num); //Y se le añade el número

	return aux;
}

bool operator== (const tFicha& ficha1, const tFicha& ficha2) { //operador para comprobar que dos fichas son iguales
	if (ficha1.num == ficha2.num && ficha1.color == ficha2.color)
		return true;
	else
		return false;
}

bool fichaVacia(const tFicha& ficha) { // funcion para ver si una ficha es vacía (LIBRE, -1)
	tFicha fichavacia = { LIBRE, -1 };

	if (ficha == fichavacia)
		return true;
	else
		return false;
}

