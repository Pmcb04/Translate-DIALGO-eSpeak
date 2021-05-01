/*
 *      Proyecto Teoría de Lenguaje
 * 	Fichero : characters.h
 *	Autor : Pedro Miguel Carmona Broncano && Rubén Marín Lucas
 */

#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <cstring>
#include <iostream>
using namespace std;
#include <string>

struct Character {
	string id;
	int line;
	string languaje;
	string gender;
	int numCharacter;

	Character(){
	}
	
	Character(string id, int line, string languaje, string gender){
		this->id = id;
		this->line = line;
		this->languaje = languaje;
		this->gender = gender;
		this->numCharacter = numCharacter;
	}

};

const int MAX_INFO_CHARACTERS = 10;
typedef Character characters[MAX_INFO_CHARACTERS];


class Characters {
    private:
	 characters chs;
     int num_characters;
	 int num_men;
     int num_women;

 	
   public:

	/*
	* Constructor por defecto de la clase Characters
	*/	
    Characters();
    
	/*
	* Metodo que se encarga de añadir los personajes a la estructura
	* Si existe ya en la estructura -> No hace nada
	* Si no existe en la estructura -> Añade el personajes a la estructura
	*/
	void add(Character character);

	/*
	* Metodo que busca un personajes en la estructura y lo devuelve
	* PRE{el personajes debe existir en la estructura}
	*/
	void get(string id, Character &character);

	/*
	* Metodo que se encarga de comprobar si id se encuentra en nuestra estructura
	* Si existe en nuestra estructura -> devuelve true
	* Si no existe en nuestra estructura -> devuelve false
	*/
	bool isExists(string id);


	/*
	* Metodo que se encarga de imprimir toda la estructura con información en el fichero de salida "salida"
	*/
	void printCharacters(ofstream &salida);

	/*
	* Metodo que se encarga de imprimir toda la estructura con información en consola
	*/
	void printCharacters();

	/*
	* Destructor por defecto de la clase Characters
	*/	
    ~Characters();
 };


#endif /* CHARACTERS_H */
