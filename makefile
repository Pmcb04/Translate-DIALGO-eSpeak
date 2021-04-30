#
#       Proyecto Teoría de Lenguaje
# 	Fichero : makefile
#	Autors : Pedro Miguel Carmona Broncano && Rubén Marín Lucas
#

OBJ = expresiones.o lexico.o identifiers.o characters.o

translate : $(OBJ)   #segunda fase de la traducción. Generación del código ejecutable 	
	g++ -o translate $(OBJ)	

expresiones.o : expresiones.c        	#primera fase de la traducción del analizador sintáctico
	g++ -c -o expresiones.o  expresiones.c 

identifiers.o : identifiers.cpp
	g++ -c identifiers.cpp

characters.o : characters.cpp
	g++ -c characters.cpp

lexico.o : lex.yy.c						#primera fase de la traducción del analizador léxico
	g++ -c -o lexico.o  lex.yy.c 	

expresiones.c : expresiones.y       	#obtenemos el analizador sintáctico en C
	bison -d -v -o expresiones.c expresiones.y

lex.yy.c: lexico.l						#obtenemos el analizador léxico en C
	flex lexico.l

clean : 
	rm  -f  *.c *.o 
