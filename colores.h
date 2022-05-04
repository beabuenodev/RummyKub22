#ifndef colores_h
#define colores_h

#include <iostream>
#include <string>

using namespace std;

//constantes y tipos

enum tColor { ROJO, VERD, AZUL, AMAR, LIBRE };
const int NUM_COLORES = 4;

//cabeceras
void colorTexto(tColor color);

#endif