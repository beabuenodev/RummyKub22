#ifndef jugadas_h
#define jugadas_h

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "colores.h"
#include "fichas.h"
#include "bolsa.h"
#include "soporte.h"
#include "soportes.h"

using namespace std;

// Constantes y tipos
typedef tFicha tJugada[13];

// Funciones
void inicializarJugada(tJugada jugada, tAjustes ajustes); // Inicializa una jugada con todas las fichas libres a num -1

bool esEscalera(const tJugada& jugada); // Comprueba si una jugada es escalera
bool esSerie(const tJugada& jugada); // Comprueba si una jugada es serie

void nuevaJugada(tSoporte& soporte, tJugada& jugada, int& jcont); //Crea una nueva jugada con fichas del soporte
bool puedePonerFicha(tJugada jugada, tFicha ficha, bool& iniciojugada); // Devuelve true si puede poner la ficha y falso en otro caso 
void ponerFicha(tJugada& jugada, tFicha& ficha, bool iniciojugada); // Coloca la ficha
#endif