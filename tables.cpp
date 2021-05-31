/*
 *      Proyecto Teoría de Lenguaje
 * 	Fichero : tables.cpp
 *	Autor : Pedro Miguel Carmona Broncano && Rubén Marín Lucas
 */
 
#include <iostream> 
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include "tables.h"
using namespace std;


const char separator    = ' ';
const int numWidth      = 25;


Table::Table(){
	this->num_rows = 0;	
	this->repeats = 1;
	this->father = NULL;
}

Table::Table(int repeats){
	this->num_rows = 0;	
	this->repeats = repeats;
}

void Table::add(Row row){
		table[num_rows] = row;
		num_rows++;
}

void Table::get(int line, Row &row){
	row = table[line];
}

void Table::setFather(Table *&father){
	this->father = father;
}

void Table::getFather(Table *&father){
	father = this->father;
}


void Table::run(ofstream &salida){

	for (int i = 0; i < repeats; i++){
		for (int j = 0; j < num_rows; j++)
			runRow(j, salida);
	}

	cout << "----- Acabamos de procesar " << this << endl;
}

void Table::runRow(int index, ofstream &salida){

	Row row = table[index];

	switch (row.tipo)
	{
	case TIPO_ROW::T_ASIGN_CAD:
			salida << "asignacion cadena" << endl;
			break;

		case TIPO_ROW::T_ASIGN_ENT:
			salida << "asignacion entera" << endl;
			break;	

		case TIPO_ROW::T_ASIGN_REAL:
			salida << "asignacion real" << endl;
			break;	

		case TIPO_ROW::T_ASIGN_LOG: 
			salida << "asignacion logica" << endl;
			break;

        case TIPO_ROW::T_FRASE: 
			salida << "espeak -v " << row.data.data_cadena << endl; 
			break;

        case TIPO_ROW::T_MENSAJE: 
			salida << "echo " << row.data.data_cadena << endl;
			break;

        case TIPO_ROW::T_PAUSA: 
			salida << "sleep " << row.data.data_real << endl;
			break;
	
		case TIPO_ROW::T_CONDICIONAL:
			salida << "condicional" << endl;
			break;

		case TIPO_ROW::T_BUCLE:
			row.data.data_table->run(salida);
			break;

		default:
			salida << "";
			break;
		}

}


template<typename T> void printElement(T t, const int& width, ofstream &salida)
{
    salida << left << setw(width) << setfill(separator) << t;
}


void Table::printTable(ofstream &salida){

	salida << endl;
	salida << "Filas de la tabla: "<< this << " (repeats=" << this->repeats << ")" << endl << endl;		

			printElement("TYPE", numWidth, salida);
			printElement("VALUE", numWidth, salida);
			salida << endl << "-------------------------------------------------------------------------------------------------------" << endl << endl;

	for (int i = 0; i < num_rows; i++){
		
        string print = (table[i].data.data_bool)? "true" : "false" ;
		switch (table[i].tipo)
		{
		case TIPO_ROW::T_ASIGN_CAD:
			printElement("asignación cadena", numWidth, salida);
			printElement(table[i].data.data_cadena, numWidth, salida);
			salida << endl;
			break;

		case TIPO_ROW::T_ASIGN_ENT:
			printElement("asignación entera", numWidth, salida);
			printElement(table[i].data.data_entero, numWidth, salida);
			salida << endl;
			break;	

		case TIPO_ROW::T_ASIGN_REAL: 
			printElement("asignación real", numWidth, salida);
			printElement(table[i].data.data_real, numWidth, salida);
			salida << endl;
			break;	

		case TIPO_ROW::T_ASIGN_LOG: 
			printElement("asignación logica", numWidth, salida);
			printElement(print, numWidth, salida);
			salida << endl;
			break;

        case TIPO_ROW::T_FRASE: 
			cout << "frase" << endl;
			printElement("frase", numWidth, salida);
			printElement(table[i].data.data_cadena, numWidth, salida);			
            salida << endl;
			break;

        case TIPO_ROW::T_MENSAJE: 
			printElement("mensaje", numWidth, salida);
			printElement(table[i].data.data_cadena, numWidth, salida);			
            salida << endl;
			break;

        case TIPO_ROW::T_PAUSA: 
			printElement("pausa", numWidth, salida);
			printElement(table[i].data.data_real, numWidth, salida);			
            salida << endl;
			break;
	
		case TIPO_ROW::T_CONDICIONAL: 
			printElement("condicional", numWidth, salida);
			printElement("table", numWidth, salida);			
			salida << endl;
			break;

		case TIPO_ROW::T_BUCLE: 
			printElement("bucle", numWidth, salida);
			printElement(table[i].data.data_table, numWidth, salida);			
			salida << endl;
			break;

		default:
			printElement("undefined", numWidth, salida);
			printElement("ERRROR", numWidth, salida);
			salida << endl;
			break;
		}
	}
		
	cout << endl;

}

template<typename T> void printElement(T t, const int& width)
{
    cout << left << setw(width) << setfill(separator) << t;
}


void Table::printTable(){

	cout << endl;
	cout << "Filas de la tabla: "<< this << " (repeats=" << this->repeats << ")" << endl << endl;
		

			printElement("TYPE", numWidth);
			printElement("VALUE", numWidth);
			cout << endl << "-------------------------------------------------------------------------------------------------------" << endl << endl;

	for (int i = 0; i < num_rows; i++){
		
        string print = (table[i].data.data_bool)? "true" : "false" ;
		switch (table[i].tipo)
		{
		case TIPO_ROW::T_ASIGN_CAD:
			printElement("asignación cadena", numWidth);
			printElement(table[i].data.data_cadena, numWidth);
			cout << endl;
			break;

		case TIPO_ROW::T_ASIGN_ENT:
			printElement("asignación entera", numWidth);
			printElement(table[i].data.data_entero, numWidth);
			cout << endl;
			break;	

		case TIPO_ROW::T_ASIGN_REAL: 
			printElement("asignación real", numWidth);
			printElement(table[i].data.data_real, numWidth);
			cout << endl;
			break;	

		case TIPO_ROW::T_ASIGN_LOG: 
			printElement("asignación logica", numWidth);
			printElement(print, numWidth);
			cout << endl;
			break;

        case TIPO_ROW::T_FRASE: 
			printElement("frase", numWidth);
			printElement(table[i].data.data_cadena, numWidth);			
            cout << endl;
			break;

        case TIPO_ROW::T_MENSAJE: 
			printElement("mensaje", numWidth);
			printElement(table[i].data.data_cadena, numWidth);			
            cout << endl;
			break;

        case TIPO_ROW::T_PAUSA: 
			printElement("pausa", numWidth);
			printElement(table[i].data.data_real, numWidth);			
            cout << endl;
			break;
	
		case TIPO_ROW::T_CONDICIONAL: 
			printElement("condicional", numWidth);
			printElement("table", numWidth);			
			cout << endl;
			break;

		case TIPO_ROW::T_BUCLE: 
			printElement("bucle", numWidth);
			printElement(table[i].data.data_table, numWidth);			
			cout << endl;
			break;

		default:
			printElement("undefined", numWidth);
			printElement("ERRROR", numWidth);
			cout << endl;
			break;
		}
	}
		
	cout << endl;
}

Table::~Table(){
}
