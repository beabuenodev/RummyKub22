#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "colores.h"
#include "fichas.h"
#include "bolsa.h"

using namespace std;

//Constantes y tipos
struct tSoporte {
	tFicha fichas[41];
	int contador;
};

//Funciones
void mostrar(const tSoporte& soporte); // Muestra los soportes
void ordenarPorNum(tSoporte& soporte); //Ordena el soporte crecientemente, primero por números y luego por colores
void ordenarPorColor(tSoporte& soporte); //Ordena el soporte crecientemente, primero por color y luego por números
void robar(tBolsa& bolsa, tSoporte& soporte, int faux, int num, const tAjustes& ajustes); //Roba una ficha de la bolsa
void mostrarEscaleras(tSoporte& soporte); // Muestras las escaleras que se pueden formar con el soporte
void mostrarSeries(tSoporte& soporte); // Muestra las series que se pueden formar con el soporte
void sugerir(tSoporte& soporte); // Sugiere escaleras y series sobre un soporte
void eliminarFicha(tSoporte& soporte, tFicha ficha); // Elimina una ficha del soporte

