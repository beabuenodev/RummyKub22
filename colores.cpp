
#include "colores.h"
#include <iostream>
#include <string>

using namespace std;

void inicializarColor(tFicha& ficha, int f) {
	switch (f) { //inicializamos el color según el numero de fila
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