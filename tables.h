/*
 *      Proyecto Teoría de Lenguaje
 * 	Fichero : tables.h
 *	Autor : Pedro Miguel Carmona Broncano && Rubén Marín Lucas
 */

#ifndef TABLES_H
#define TABLES_H 

#include <cstring>
#include <iostream>
#include <string>
using namespace std;


enum TIPO_ROW{
	T_ASIGN_CAD, T_ASIGN_ENT, T_ASIGN_REAL, T_ASIGN_LOG, T_FRASE, T_PAUSA, T_MENSAJE, T_BUCLE, T_CONDICIONAL
};

typedef char tipo_cadena[255];

union tipo_data{
	int data_entero;
	float data_real;
	bool data_bool;
	tipo_cadena data_cadena;
};

struct Row {
	TIPO_ROW tipo;
	tipo_data data;
	
	Row(){

	}

	Row(int data, TIPO_ROW tipo){
		this->data.data_entero = data;
		this->tipo = tipo;
	}

	Row(float data, TIPO_ROW tipo){
		this->data.data_real = data;
		this->tipo = tipo;
	}

	Row(bool data, TIPO_ROW tipo){
		this->data.data_bool = data;
		this->tipo = tipo;
	}

	Row(tipo_cadena data, TIPO_ROW tipo){
		strcpy(this->data.data_cadena, data);
		this->tipo = tipo;
	}
};

const int MAX_INFO_TABLES = 100;
typedef Row rows[MAX_INFO_TABLES];


class Table {
	private: 
		rows table;
		int num_rows;
		int repeats;

	public: 
		/*
		* Constructor por defecto de la clase Table
		*/
		Table();

		/*
		* Constructor parametrizado de la clase Table
		*/
		Table(int repeats);
		
		/*
		* Metodo que se encarga de añadir la table a la estructura
		* Si existe ya en la estructura -> No hace nada
		* Si no existe en la estructura -> Añade la tabla a la estructura
		*/
		void add(Row row);

		/*
		* Metodo que optiene el row de la linea line y lo devuelve
		* PRE{line <= num_rows}
		*/
		void get(int line, Row &row);

		/*
		* Metodo que procesa la tabla, repeats veces las instrucciones que tenga y las suelta en salida
		*/
		void run(ofstream &salida);

		/*
		* Metodo que procesa la linea y las suelta en salida
		*/
		void runRow(int index, ofstream &salida);

		/*
		* Metodo que se encarga de imprimir toda la estructura con información en el fichero de salida "salida"
		*/
		void printTable(ofstream &salida);

		/*
		* Metodo que se encarga de imprimir toda la estructura con información en consola
		*/
		void printTable();

		/*
		* Destructor por defecto de la clase Table
		*/
		~Table();

};

#endif /* TABLES_H */
