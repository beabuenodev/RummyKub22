#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "soportes.h"

using namespace std;

void repartir(tBolsa& bolsa, tSoportes& soportes, const tAjustes& ajustes) { //Reparte aleatoriamente
	for (int j = 0; j < ajustes.numJugadores; j++) {
		for (int i = 0; i < ajustes.iniFichas; i++) {
			//La sacamos de la bolsa y la ponemos en el soporte
			nuevaFicha(soportes[j], sacarFicha(bolsa, ajustes));
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

void delSoportes(tSoportes& soportes, tAjustes ajustes) {
	for (int j = 0; j < ajustes.numJugadores; j++) 
		delete[] soportes[j].fichas;
}