// Autor/a: Beatriz Bueno Almagro
// Usuario Juez: B09
// email: beabueno@ucm.es	
// Compilador y S.O. utilizado: Visual Studio 2019, Windows 10
// Nombre del problema: Práctica Rummikub EJC 1
// Comentario general sobre la solución 
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "colores.h"
#include "fichas.h"
#include "bolsa.h"
#include "soporte.h"
#include "soportes.h"
#include "jugadas.h"
#include "tablero.h"

// Introduce más librerías si son necesarias
using namespace std;

struct tAjustes { //Guarda ajustes básicos
	int numFichas;
	int iniFichas;
	int numJugadores;
};

//llamadas funciones
void resuelveCaso();

//Funciones Parte 1
//Funciones Parte 2
int menu(); //Imprime el menu y devuelve la opción elegida

//Funciones Parte 3

//Funciones Parte 4
// el booleano iniciojugada indica si la ficha se debe colocar en el inicio de la jugada (en el caso de una escalera) 

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	std::ofstream out("datos.out");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

	resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
	system("PAUSE");
#endif

	return 0;
}


// resuelve el caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	//guardamos los ajustes iniciales
	tAjustes ajustes;

	cin >> ajustes.numFichas;
	cin >> ajustes.iniFichas;
	cin >> ajustes.numJugadores;

	//inicializamos la bolsa
	cout << "\n";
	tBolsa bolsa;
	inicializarBolsa(bolsa, ajustes);
	mostrar(bolsa, ajustes);

	//repartimos fichas
	tSoportes soportes;
	for (int s = 0; s < ajustes.numJugadores; s++) {
		soportes[s].contador = 0;
	}

	repartir(bolsa, soportes, ajustes);
	cout << "Fichas de la bolsa con todas las fichas repartidas\n";
	cout << "\n";
	mostrar(bolsa, ajustes);

	//empezamos a jugar
	int turno, opcion, faux, num;
	bool jugada = false, ganado = false;
	tTablero tablero;
	tablero.contador = 0;
	cin >> turno;
	cout << "Turno para el jugador " << turno << " ...\n";
	mostrar(soportes[turno - 1]);
	cout << "\n";
	opcion = menu();

	while (opcion != -1 && !ganado) { //Mientras no se lea -1 o algun jugador haya ganado...
		switch (opcion) {
		case 1: //Ordenar soporte por numero y luego color
			ordenarPorNum(soportes[turno - 1]);
			mostrar(soportes[turno - 1]);
			break;
		case 2: //Ordenar soporte por color y luego número
			ordenarPorColor(soportes[turno - 1]);
			mostrar(soportes[turno - 1]);
			break;
		case 3: //Sugerir escaleras o series que se pueden hacer con las fichas del soporte
			sugerir(soportes[turno - 1]);
			mostrar(soportes[turno - 1]);
			break;
		case 4: //Se intenta crear una jugada nueva o añadir una ficha a una jugada existente
			if (jugar(tablero, soportes[turno - 1])) 
				jugada = true;
			cout << "\n";
			mostrar(tablero);
			cout << "\n";
			cout << "\n";
			mostrar(soportes[turno - 1]);
			cout << "\n";
			if (soportes[turno - 1].contador == 0) // Si ya no hay fichas en el soporte del jugador, ha ganado. Se corta el bucle
				ganado = true;
			break;
		case 0: //Finaliza turno
			if (!jugada) { // Si no ha jugado este turno se roba una ficha
				cin >> faux;
				cin >> num;
				robar(bolsa, soportes[turno - 1], faux, num, ajustes);
				mostrar(soportes[turno - 1]);
				cout << "\n";
			}
			else {
				jugada = false;
			}
			siguienteTurno(turno, soportes, ajustes); // Se inicia el siguiente turno
		}
 		cout << "\n";
		if (!ganado) // Si no se gana, se vuelve al menu en el turno siguiente
			opcion = menu();
	}

	if (ganado) {
		cout << "El jugador " << turno << " ha ganado!\n"; //Mensaje de que un jugador ha ganado
	}
}

int menu() {
	int opcion;
	cin >> opcion;
	if (opcion != -1) { // Como en la opción -1 no se imprime el menú, esta es la unica forma de que pase los tests de domjudge
		cout << "1: Ordenar por num., ";
		cout << "2: Ordenar por color, ";
		cout << "3: Sugerir, ";
		cout << "4: Poner, ";
		cout << "0: Fin >>>  ";
		cout << opcion << "\n";
	}
	return opcion;
}
