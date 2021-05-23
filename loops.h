/*
 *      Proyecto Teoría de Lenguaje
 * 	Fichero : loops.h
 *	Autor : Pedro Miguel Carmona Broncano && Rubén Marín Lucas
 */

#ifndef LOOPS_H
#define LOOPS_H

#include <cstring>
#include <iostream>
#include <string>
#include "tables.h"
using namespace std;

const int MAX_INFO_LOOPS = 100;
typedef Table* loops[MAX_INFO_LOOPS];


class Loops {
    private:
	 loops ls;
	 int num_loops;

 	
   public:
    	
		/*
		* Constructor por defecto de la clase Loops
		*/
		Loops();
		
		/*
		* Metodo que se encarga de añadir la table a la estructura
		* Si existe ya en la estructura -> No hace nada
		* Si no existe en la estructura -> Añade la tabla a la estructura
		*/
		void add(Table *&table, int repeats);

		/*
		* Metodo que busca una tabla en la estructura y lo devuelve
		* PRE{el tabla debe existir en la estructura}
		*/
		void get(int index, Table *&table);

		/*
		* Metodo que se encarga de imprimir toda la estructura con información en el fichero de salida "salida"
		*/
		void printLoops(ofstream &salida);

		/*
		* Metodo que se encarga de imprimir toda la estructura con información en consola
		*/
		void printLoops();

		/*
		* Destructor por defecto de la clase Loops
		*/
		~Loops();
 };


#endif /* LOOPS_H */
