#ifndef soporte_h
#define soporte_h

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "fichas.h"
#include "bolsa.h"

using namespace std;

//Constantes y tipos
struct tSoporte {
	tFichaPtr fichas;
	int capacidad;
	int contador;
};

//Funciones
void mostrar(const tSoporte& soporte); // Muestra los soportes
void ordenarPorNum(tSoporte& soporte); //Ordena el soporte crecientemente, primero por n�meros y luego por colores
void ordenarPorColor(tSoporte& soporte); //Ordena el soporte crecientemente, primero por color y luego por n�meros
void robar(tBolsa& bolsa, tSoporte& soporte, const tAjustes& ajustes); //Roba una ficha de la bolsa
void mostrarEscaleras(tSoporte& soporte); // Muestras las escaleras que se pueden formar con el soporte
void mostrarSeries(tSoporte& soporte); // Muestra las series que se pueden formar con el soporte
void sugerir(tSoporte& soporte); // Sugiere escaleras y series sobre un soporte
void eliminarFicha(tSoporte& soporte, tFicha ficha); // Elimina una ficha del soporte
#endif
