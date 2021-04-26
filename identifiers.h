/*
 *      Proyecto Teoría de Lenguaje
 * 	Fichero : identifiers.h
 *	Autor : Pedro Miguel Carmona Broncano && Rubén Marín Lucas
 */

#ifndef IDENTIFIERS_H
#define IDENTIFIERS_H

#include <cstring>
 
enum TIPO{
	T_ENT, T_REAL, T_BOOL, T_CADENA
};

typedef char tipo_cadena[255];

union tipo_valor{
	int valor_entero;
	float valor_real;
	bool valor_bool;
	tipo_cadena valor_cadena;
};

#include <iostream>
using namespace std;
#include <string>

struct Info {
	string id;
	int line;
	tipo_valor valor;
	TIPO tipo;

	Info(){
	}
	
	Info(string id, int line, float valor){
		this->id = id;
		this->line = line;
		this->valor.valor_real = valor;
		this->tipo = TIPO::T_REAL;
	}

	Info(string id, int line, int valor){
		this->id = id;
		this->line = line;
		this->valor.valor_entero = valor;
		this->tipo = TIPO::T_ENT;
	}

	Info(string id, int line, bool valor){
		this->id = id;
		this->line = line;
		this->valor.valor_bool = valor;
		this->tipo = TIPO::T_BOOL;
	}

	Info(string id, int line, tipo_cadena valor){
		this->id = id;
		this->line = line;
		strcpy(this->valor.valor_cadena, valor);
		this->tipo = TIPO::T_CADENA;
	}

};

const int MAX_INFO = 100;
typedef Info identifier[MAX_INFO];


class Identifiers {
    private:
	 identifier ids;
     int num_identifiers;
 	
   public:
    	
    Identifiers();
    
	/*
	* Metodo que se encarga de añadir los identificadores a la estructura
	* Si existe ya en la estructura -> No hace nada
	* Si no existe en la estructura -> Añade el identificador a la estructura
	*/
	void add(Info info);

	/*
	* Metodo que busca un identificador en la estructura y lo devuelve{
	* PRE{el identificador deve existir en la estructura}
	*/
	void get(string id, Info &info);

	/*
	* Metodo que devuelve el tipo de la variable con identificador id
	* PRE{la variable con identificador id debe estar previamente guardada en la estructura}
	*/
	TIPO getTipo(string id);
	
	/*
	* Asigna el valor a la variable info que le pasemos por parametro
	* PRE {la variable con id, debe ser de tipo real}
	*/
	void setValor(string id, float valor);

	/*
	* Asigna el valor a la variable info que le pasemos por parametro
	* PRE {la variable con id, debe ser de tipo entero}
	*/
	void setValor(string id, int valor);

	/*
	* Asigna el valor a la variable info que le pasemos por parametro
	* PRE {la variable con id, debe ser de tipo bool}
	*/
	void setValor(string id, bool valor);

	/*
	* Asigna el valor a la variable info que le pasemos por parametro
	* PRE {la variable con id, debe ser de tipo tipo_cadena}
	*/
	void setValor(string id, tipo_cadena valor);

	/*
	* Metodo que se encarga de comprobar si id se encuentra en nuestra estructura
	* Si existe en nuestra estructura -> devuelve true
	* Si no existe en nuestra estructura -> devuelve false
	*/
	bool isExists(string id);


	/*
	* Metodo que se encarga de imprimir toda la estructura con información en el fichero de salida "salida"
	*/
	void printIdentifiers(ofstream &salida);

	/*
	* Metodo que se encarga de imprimir toda la estructura con información en consola"
	*/
	void printIdentifiers();

    ~Identifiers();
 };


#endif /* IDENTIFIERS_H */
