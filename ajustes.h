#ifndef ajustes_h
#define ajustes_h

//FP2 - RummyKub V.2
//Nombre y Apellidos: Beatriz Bueno Almagro 1ºB

#include <iostream>
#include <string>

using namespace std;

//tipos
struct tAjustes { //Guarda ajustes básicos
	int numFichas;
	int iniFichas;
	int numJugadores;
};

//funciones
tAjustes inicializarAjustes(int numFichas, int iniFichas, int numJugadores); //inicializa los ajustes indicados
#endif