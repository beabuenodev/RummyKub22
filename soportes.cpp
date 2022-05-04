#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "soportes.h"

using namespace std;

void repartir(tBolsa& bolsa, tSoportes& soportes, const tAjustes& ajustes) { //Reparte según el archivo datos.in
	tFicha aux;
	int filacolor, num;

	for (int j = 0; j < ajustes.numJugadores; j++) {
		for (int i = 0; i < ajustes.iniFichas; i++) {
			//La sacamos de la bolsa y la ponemos en el soporte
			soportes[j].fichas[i] = sacarFicha(bolsa, ajustes);
			soportes[j].contador++;
		}
	}

}

void siguienteTurno(int& turno, tSoportes soportes, tAjustes ajustes) {
	if (turno != ajustes.numJugadores)
		turno++;
	else //Si el turno es el de el ultimo jugador, se pasa al primero
		turno = 1;

	cout << "Turno para el jugador " << turno << " ...\n";
	mostrar(soportes[turno - 1]);
}


