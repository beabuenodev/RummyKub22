#pragma once

#include "colores.h"
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
string fichaToString(tFicha ficha); // Devuelve el color y el numero de una ficha
bool operator== (const tFicha& ficha1, const tFicha& ficha2); // Ajusta al operador == para que compare si dos fichas son iguales (su color y num son iguales)
bool fichaVacia(const tFicha& ficha); // Indica si la ficha está vacía (num == -1 && color == Libre)
