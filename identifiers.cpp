/*
 *      Proyecto Teoría de Lenguaje
 * 	Fichero : identifiers.cpp
 *	Autor : Pedro Miguel Carmona Broncano && Rubén Marín Lucas
 */
 
#include <iostream> 
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include "identifiers.h"
using namespace std;


const char separator    = ' ';
const int numWidth      = 25;


Identifiers::Identifiers(){
	num_identifiers = 0;	
}

void Identifiers::add(Info info){
	ids[num_identifiers] = info;
	num_identifiers++;
}

void Identifiers::get(string id, Info &info){
	
	bool enc = false;
	int i = 0;
		
	while(!enc && i < num_identifiers)
		if(ids[i].id == id)
			enc = true;
		else
			i++; 

	info = ids[i];
}

TIPO Identifiers::getTipo(string id){

	bool enc = false;
	int i = 0;
	
	while(!enc && i < num_identifiers)
		if(ids[i].id == id)
			enc = true;
		else
			i++;

	return ids[i].tipo;	
}

void Identifiers::setValor(string id, float valor){

	bool enc = false;
	int i = 0;
	
	while(!enc && i < num_identifiers)
		if(ids[i].id == id)
			enc = true;
		else
			i++;

	if(enc) ids[i].valor.valor_real = valor;	
}

void Identifiers::setValor(string id, int valor){

	bool enc = false;
	int i = 0;
	
	while(!enc && i < num_identifiers) 
		if(ids[i].id == id)
			enc = true;
		else
			i++;

	if(enc) ids[i].valor.valor_entero = valor;	
}


void Identifiers::setValor(string id, bool valor){

	bool enc = false;
	int i = 0;
	
	while(!enc && i < num_identifiers) 
		if(ids[i].id == id)
			enc = true;
		else
			i++;

	if(enc) ids[i].valor.valor_bool = valor;	
}


void Identifiers::setValor(string id, tipo_cadena valor){

	bool enc = false;
	int i = 0;
	
	while(!enc && i < num_identifiers)
		if(ids[i].id == id)
			enc = true;
		else
			i++;

	if(enc) strcpy(ids[i].valor.valor_cadena, valor);	
}

bool Identifiers::isExists(string id){
	
	int i = 0;
	bool enc = false;
	
	while(!enc && i < num_identifiers)
		if(ids[i].id == id)
			enc = true;
		else
			i++;

	return enc;
}


template<typename T> void printElement(T t, const int& width, ofstream &salida)
{
    salida << left << setw(width) << setfill(separator) << t;
}


void Identifiers::printIdentifiers(ofstream &salida){
	
	salida << endl;
	salida << "Lista de identificadores:" << endl << endl;
		
			printElement("ID", numWidth, salida);
			printElement("TIPO", numWidth, salida);
			printElement("LAST VALOR", numWidth, salida);
			printElement("LINE DECLARATION", numWidth, salida);
			salida << endl << "-------------------------------------------------------------------------------------------------------" << endl << endl;


	for (int i = 0; i < num_identifiers; i++){
		
		string print = (ids[i].valor.valor_bool == true)? "true" : "false" ;
		switch (ids[i].tipo)
		{
		case TIPO::T_ENT:
			printElement(ids[i].id, numWidth, salida);
			printElement("entero", numWidth, salida);
			printElement(ids[i].valor.valor_entero, numWidth, salida);
			printElement(ids[i].line, numWidth, salida);
			salida << endl;
			break;

		case TIPO::T_REAL:
			printElement(ids[i].id, numWidth, salida);
			printElement("real", numWidth, salida);
			printElement(ids[i].valor.valor_real, numWidth, salida);
			printElement(ids[i].line, numWidth, salida);
			salida << endl;
			break;	

		case TIPO::T_BOOL: 
			printElement(ids[i].id, numWidth, salida);
			printElement("logico", numWidth, salida);
			printElement(print, numWidth, salida);
			printElement(ids[i].line, numWidth, salida);
			salida << endl;
			break;	

		case TIPO::T_CADENA: 
			printElement(ids[i].id, numWidth, salida);
			printElement("cadena", numWidth, salida);
			printElement(ids[i].valor.valor_cadena, numWidth, salida);
			printElement(ids[i].line, numWidth, salida);
			salida << endl;
			break;	

		default:
			printElement(ids[i].id, numWidth, salida);
			printElement("undefined", numWidth, salida);
			printElement("ERRROR", numWidth, salida);
			printElement("ERROR", numWidth, salida);
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


void Identifiers::printIdentifiers(){

	cout << endl;
	cout << "Lista de identificadores:" << endl << endl;
		
			printElement("ID", numWidth);
			printElement("TIPO", numWidth);
			printElement("LAST VALOR", numWidth);
			printElement("LINE DECLARATION", numWidth);
			cout << endl << "-------------------------------------------------------------------------------------------------------" << endl << endl;


	for (int i = 0; i < num_identifiers; i++){
		
		string print = (ids[i].valor.valor_bool == true)? "true" : "false" ;
		switch (ids[i].tipo)
		{
		case TIPO::T_ENT:
			printElement(ids[i].id, numWidth);
			printElement("entero", numWidth);
			printElement(ids[i].valor.valor_entero, numWidth);
			printElement(ids[i].line, numWidth);
			cout << endl;
			break;

		case TIPO::T_REAL:
			printElement(ids[i].id, numWidth);
			printElement("real", numWidth);
			printElement(ids[i].valor.valor_real, numWidth);
			printElement(ids[i].line, numWidth);
			cout << endl;
			break;	

		case TIPO::T_BOOL: 
			printElement(ids[i].id, numWidth);
			printElement("logico", numWidth);
			printElement(print, numWidth);
			printElement(ids[i].line, numWidth);
			cout << endl;
			break;	

		case TIPO::T_CADENA: 
			printElement(ids[i].id, numWidth);
			printElement("cadena", numWidth);
			printElement(ids[i].valor.valor_cadena, numWidth);
			printElement(ids[i].line, numWidth);
			cout << endl;
			break;	

		default:
			printElement(ids[i].id, numWidth);
			printElement("undefined", numWidth);
			printElement("ERRROR", numWidth);
			printElement("ERROR", numWidth);
			cout << endl;
			break;
		}
	}
		
	cout << endl;
}

Identifiers::~Identifiers(){
}
