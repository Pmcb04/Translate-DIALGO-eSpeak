/*
 *      Proyecto Teoría de Lenguaje
 * 	Fichero : characters.cpp
 *	Autor : Pedro Miguel Carmona Broncano && Rubén Marín Lucas
 */
 
#include <iostream> 
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include "characters.h"
using namespace std;


const char separator    = ' ';
const int numWidth      = 25;


Characters::Characters(){
	num_characters = 0;	
}

void Characters::add(Character character){

	if(!isExists(character.id)){ // si existe en la estructura no tiene que contar como uno nuevo
		if(character.gender == "m"){
			num_men++;
			character.numCharacter = num_men;
		}else if(character.gender == "f"){
			num_women++;
			character.numCharacter = num_women;
		}

		chs[num_characters] = character;
		num_characters++;

	}
}

void Characters::get(string id, Character &character){
	
	bool enc = false;
	int i = 0;
		
	while(!enc && i < num_characters)
		if(chs[i].id == id)
			enc = true;
		else
			i++; 

	character = chs[i];
}


bool Characters::isExists(string id){
	
	int i = 0;
	bool enc = false;
	
	while(!enc && i < num_characters)
		if(chs[i].id == id)
			enc = true;
		else
			i++;

	return enc;
}


template<typename T> void printElement(T t, const int& width, ofstream &salida)
{
    salida << left << setw(width) << setfill(separator) << t;
}


void Characters::printCharacters(ofstream &salida){
	
	salida << endl;
	salida << "Lista de personajes:" << endl << endl;
		
			printElement("ID", numWidth, salida);
			printElement("LANGUAJE", numWidth, salida);
			printElement("GENDER", numWidth, salida);
			printElement("NUM CHARACTER", numWidth, salida);
			printElement("LINE DECLARATION", numWidth, salida);
			salida << endl << "---------------------------------------------------------------------------------------------------------------------------" << endl << endl;


	for (int i = 0; i < num_characters; i++){
		
			printElement(chs[i].id, numWidth, salida);
			printElement(chs[i].languaje, numWidth, salida);
			printElement(chs[i].gender, numWidth, salida);
			printElement(chs[i].numCharacter, numWidth, salida);
			printElement(chs[i].line, numWidth, salida);
			salida << endl;
	}
		
	cout << endl;
}

template<typename T> void printElement(T t, const int& width)
{
    cout << left << setw(width) << setfill(separator) << t;
}


void Characters::printCharacters(){

	cout << endl;
	cout << "Lista de personajes:" << endl << endl;
		

			printElement("ID", numWidth);
			printElement("LANGUAJE", numWidth);
			printElement("GENDER", numWidth);
			printElement("NUM CHARACTER", numWidth);
			printElement("LINE DECLARATION", numWidth);
			cout << endl << "---------------------------------------------------------------------------------------------------------------------------" << endl << endl;

	for (int i = 0; i < num_characters; i++){
		
			printElement(chs[i].id, numWidth);
			printElement(chs[i].languaje, numWidth);
			printElement(chs[i].gender, numWidth);
			printElement(chs[i].numCharacter, numWidth);
			printElement(chs[i].line, numWidth);
			cout << endl;
	}
		
	cout << endl;
}

Characters::~Characters(){
}
