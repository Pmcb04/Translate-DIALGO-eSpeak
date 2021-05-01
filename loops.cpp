/*
 *      Proyecto Teoría de Lenguaje
 * 	Fichero : loops.cpp
 *	Autor : Pedro Miguel Carmona Broncano && Rubén Marín Lucas
 */

#include <iostream> 
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include "loops.h"
using namespace std;


const char separator    = ' ';
const int numWidth      = 25;

Loops::Loops(){
	this->num_loops = 0;
}

void Loops::add(Table table){
		ls[num_loops] = table;
		num_loops++;
}

void Loops::get(int index, Table &table){
	table = ls[index];
}

void Loops::printLoops(ofstream &salida){

	for (int i = 0; i < num_loops; i++){
		ls[i].printTable(salida);
	}
		
	cout << endl;

}

void Loops::printLoops(){

	for (int i = 0; i < num_loops; i++){
		ls[i].printTable();
	}
		
	cout << endl;
}

Loops::~Loops(){
}
