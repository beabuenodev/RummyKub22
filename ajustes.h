#ifndef ajustes_h
#define ajustes_h

//FP2 - RummyKub V.2
//Nombre y Apellidos: Beatriz Bueno Almagro 1�B

#include <iostream>
#include <string>

using namespace std;

//tipos
struct tAjustes { //Guarda ajustes b�sicos
	int numFichas;
	int iniFichas;
	int numJugadores;
};

//funciones
tAjustes incializarAjustes(int numFichas, int iniFichas, int numJugadores); //inicializa los ajustes indicados
#endif