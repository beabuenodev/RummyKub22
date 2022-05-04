#ifndef fichas_h
#define fichas_h

#include "colores.h"
#include "ajustes.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Constantes y tipos
struct tFicha {
	tColor color;
	int num;
};

//Funciones
void inicializarColor(tFicha& ficha, int f); // Inicializa un color para la ficha dependiendo del número de la fila de la Bolsa
int fichaToString(tFicha ficha); // Devuelve el color y el numero de una ficha
bool operator== (const tFicha& ficha1, const tFicha& ficha2); // Ajusta al operador == para que compare si dos fichas son iguales (su color y num son iguales)
bool fichaVacia(const tFicha& ficha); // Indica si la ficha está vacía (num == -1 && color == Libre)
#endif