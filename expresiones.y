%{

/*
 *      Proyecto Teoría de Lenguaje
 * 	Fichero : expresiones.y
 *	Autor : Pedro Miguel Carmona Broncano && Rubén Marín Lucas
 */

 //       | error salto  {yyerrok; errorSemantico = false; errorVariable = false;}	


#include <string>
#include <fstream>
#include <iostream> 
#include <sstream>
#include <cstring>
#include "identifiers.h"
#include "characters.h"
#include "loops.h"
using namespace std;

 
//elementos externos al analizador sintácticos por haber sido declarados en el analizador léxico      			
extern int n_lineas;
extern int yylex();
extern FILE* yyin;
extern int num_men;
extern int num_women;

//definición de procedimientos auxiliares
void yyerror(const char* s){         /*    llamada por cada error sintactico de yacc */
	cout << "Error sintáctico en la línea "<< n_lineas << " : "  << s <<endl;	
}

//Zona de definiciones

ofstream salida;
int n_loop;
int n_escena;
string str;
tipo_cadena tc;

bool ejecutar = false;
bool esBucle = false;
bool errorVariable = false;
bool errorSemantico = false; 


Character ch;
Characters chs;  

Loops ls;
Table *table;

Identifiers ids;
Identifier ident;
TIPO_IDENT tipo_ident;

%}

%union{
 int c_entero;
 float c_real;
 bool c_bool;
 char c_identificador[25];
 char c_cadena[255];
  
 struct{
       float valor;
       bool esReal;
 } c_expresion_arit;

}

%type <c_entero> NUMERO
%type <c_real> REAL

%type <c_identificador> ID_GENERAL
%type <c_identificador> ID_CADENA
%type <c_identificador> ID_NOMBRE

%type <c_bool> TRUE
%type <c_bool> FALSE
%type <c_cadena> CADENA

%type <c_bool> expr_log
%type <c_expresion_arit> expr_arit
%type <c_cadena> expr_cadena

%type <c_cadena> entonacion
%type <c_cadena> TONO
%type <c_cadena> IDIOMA
%type <c_cadena> VOZ

%start programa
%token NUMERO REAL DIV AND OR NOT TRUE FALSE MAYORIGUAL MENORIGUAL IGUAL2 DISTINTO 
%token PERSONAJES DEFINICIONES ESCENA FINESCENA 
%token ID_GENERAL ID_NOMBRE ID_CADENA     
%token PAUSA MENSAJE CADENA 
%token IDIOMA
%token TONO
%token VOZ
%token CONCATENACION
%token SI SI_NO REPETIR

%left CONCATENACION
%left OR
%left AND
%left IGUAL2 DISTINTO
%left '<' '>' MAYORIGUAL MENORIGUAL
%left '+' '-'   
%left '*' '/' DIV       
%left menos
%right NOT

%%

/*------------------------------------------------ programa ------------------------------------------------*/ 

salto: '\n'          {n_lineas++;}
      | salto '\n'   {n_lineas++;}
      ;

salto_opc:        
      | salto_opc '\n'  {n_lineas++;}
      ;


programa: salto_opc bloquePersonajes bloqueDefiniciones secEscena
      ;

/*------------------------------------------------ personaje ------------------------------------------------*/ 

bloquePersonajes: PERSONAJES {cout << "+++ bloque personajes linea " << n_lineas << endl;} salto secBloquePersonajes
      ;

secBloquePersonajes :  asignacionPersonaje
      | secBloquePersonajes asignacionPersonaje
      ;

asignacionPersonaje: ID_NOMBRE '=' '<' IDIOMA ',' VOZ '>' salto { cout << "-------- asignacion nombre " << $1 << "," << $4 << "," << $6 <<  " linea " << n_lineas << endl; chs.add(Character($1, n_lineas, $4, $6));} 
      ;

/*------------------------------------------------ definiciones ------------------------------------------------*/ 

bloqueDefiniciones: 
      | DEFINICIONES {cout << "+++ bloque definiciones linea " << n_lineas << endl;} salto secBloqueDefiniciones
      ;      

secBloqueDefiniciones: identificador
      | secBloqueDefiniciones identificador
      ;

identificador:identificadorCadena
      | identificadorGeneral


identificadorGeneral: ID_GENERAL '=' expr_arit    {
                                          if(!errorVariable && !errorSemantico){
                                                if(!ids.isExists($1))
                                                      if($3.esReal){
                                                            ids.add(Identifier($1, n_lineas, $3.valor));
                                                            cout << "-------- asignacion id_general real " << $1 <<  ", " << $3.valor << endl;     
                                                      } else{
                                                            ids.add(Identifier($1, n_lineas, (int)$3.valor)); 
                                                            cout << "-------- asignacion id_general entero " << $1 <<  ", " << $3.valor << endl;     
                                                      } 
                                                            
                                                else if($3.esReal && ids.getTipo($1) == TIPO_IDENT::T_REAL){
                                                      ids.setValor($1, $3.valor);
                                                      cout << "-------- actualizacion valor asignacion id_general real" << $1 <<  ", " << $3.valor << endl;     
                                                }
                                                
                                                else if(!$3.esReal && ids.getTipo($1) == TIPO_IDENT::T_ENT){
                                                      ids.setValor($1, (int)$3.valor);                                          
                                                      cout << "-------- actualizacion valor asignacion id_general entero" << $1 <<  ", " << $3.valor << endl;     
                                                }
                                                else{

                                                      cout << "********** Error semantico en la linea " << n_lineas << ", la variable " << $1 << " es de tipo ";
                                                      
                                                      tipo_ident = ids.getTipo($1); // averiguamos el tipo de $1, es decir de la variable

                                                      switch (tipo_ident) {
                                                      case T_ENT: cout << "entero "; break;
                                                      case T_REAL: cout << "real "; break;
                                                      case T_BOOL: cout << "bool "; break;
                                                      case T_CADENA: cout << "cadena "; break;
                                                      default: cout << "undefined "; break;
                                                      }

                                                      cout << "y no se le puede asignar un valor ";

                                                      if($3.esReal) cout << "real" << endl;
                                                      else cout << "entero" << endl;
                                                }
                                          }

                                          errorSemantico = false;
                                          errorVariable = false;

                                  } salto

      | ID_GENERAL '=' expr_log      {
                                   
                                          if(!errorVariable && !errorSemantico){
                                                if(!ids.isExists($1)){
                                                      ids.add(Identifier($1, n_lineas, $3));
                                                      cout << "-------- asignacion id_general logico" << $1 <<  ", " << $3 << endl;     
                                                }
                                                else if(ids.getTipo($1) == TIPO_IDENT::T_BOOL){
                                                      ids.setValor($1, $3);
                                                      cout << "-------- actualizacion valor asignacion id_general logico" << $1 <<  ", " << $3 << endl;     
                                                }
                                                else{

                                                      cout << "********** Error semantico en la linea " << n_lineas << ", la variable " << $1 << " es de tipo ";
                                                      
                                                      tipo_ident = ids.getTipo($1); // averiguamos el tipo de $1, es decir de la variable

                                                      switch (tipo_ident) {
                                                      case T_ENT: cout << "entero "; break;
                                                      case T_REAL: cout << "real "; break;
                                                      case T_BOOL: cout << "bool "; break;
                                                      case T_CADENA: cout << "cadena "; break;
                                                      default: cout << "undefined "; break;
                                                      }

                                                      cout << "y no se le puede asignar un valor bool" << endl;
                                                }                                          
                                          }

                                          errorSemantico = false;
                                          errorVariable = false;

                                 } salto 
      ;


identificadorCadena:  ID_CADENA '=' expr_cadena {
            
                                          if(!errorVariable && !errorSemantico){
                                                if(!ids.isExists($1)){
                                                      ids.add(Identifier($1, n_lineas, $3));
                                                      cout << "-------- asignacion id_cadena " << $1 <<  ", " << $3 << endl;     
                                                }
                                                else if(ids.getTipo($1) == TIPO_IDENT::T_CADENA){
                                                      ids.setValor($1, $3);
                                                      cout << "-------- actualizacion valor asignacion id_cadena " << $1 <<  ", " << $3 << endl;     
                                                }
                                                else{

                                                      cout << "********** Error semantico en la linea " << n_lineas << ", la variable " << $1 << " es de tipo ";
                                                      
                                                      tipo_ident = ids.getTipo($1); // averiguamos el tipo de $1, es decir de la variable

                                                      switch (tipo_ident) {
                                                      case T_ENT: cout << "entero "; break;
                                                      case T_REAL: cout << "real "; break;
                                                      case T_BOOL: cout << "bool "; break;
                                                      case T_CADENA: cout << "cadena "; break;
                                                      default: cout << "undefined "; break;
                                                      }

                                                      cout << "y no se le puede asignar un valor cadena" << endl;
                                                }                                     
                                          }

                                          errorSemantico = false;
                                          errorVariable = false;
      
                                    } salto 
      ;

/*------------------------------------------------ escena ------------------------------------------------*/ 

secEscena: escena
      | secEscena escena
      ;

escena:ESCENA expr_arit ':' {
                                    if(!$2.esReal){
                                          if($2.valor > n_escena){
                                                cout << "+++ Inicio de la escena " << $2.valor << endl;
                                                n_escena = $2.valor;
                                          }
                                          else
                                                cout << "Error semantico en la linea " << n_lineas << ", la escena " << $2.valor << " no puede ser procesada" <<  endl;
                                    }
                                    else
                                          cout << "Error semantico en la linea " << n_lineas << ", el número de escena debe ser de tipo ENTERO" << endl;
      
      
                              } salto secBloqueEscena FINESCENA {cout << "+++ Fin de la escena " << n_escena << endl; } salto
      ; 

secBloqueEscena: bloqueEscena      
      | secBloqueEscena bloqueEscena       
      ;

bloqueEscena: ID_NOMBRE ':' expr_cadena                        { cout << "-------- personaje " << " [" << $1 << "] "  << " en linea " << n_lineas << " dice : " << $3 << endl; 
                                                                  
                                                                  if(chs.isExists($1)){
                                                                        chs.get($1, ch);
                                                                        str = ch.languaje + "+";
                                                                        str += ch.gender;
                                                                        str += to_string(ch.numCharacter) + " ";
                                                                        strcpy(tc, str.c_str());
                                                                        strcat(tc, $3);
                                                                        
                                                                        if(esBucle)
                                                                              (*table).add(Row(tc, TIPO_ROW::T_FRASE)); 
                                                                        else
                                                                              salida << "espeak -v " << tc << endl;

                                                                  }

                                                               } salto
      | ID_NOMBRE  '[' ']' ':' expr_cadena                     { cout << "-------- personaje " << " [" << $1 << "] "  << " en linea " << n_lineas << " dice : " << $5 << endl; 
                                                                  
                                                                  if(chs.isExists($1)){
                                                                        chs.get($1, ch);
                                                                        str = ch.languaje + "+";
                                                                        str += ch.gender;
                                                                        str += to_string(ch.numCharacter) + " ";
                                                                        strcpy(tc, str.c_str());
                                                                        strcat(tc, $5);

                                                                        if(esBucle)
                                                                              (*table).add(Row(tc, TIPO_ROW::T_FRASE));
                                                                        else
                                                                              salida << "espeak -v " << tc << endl;
                                                                  }

                                                               } salto
      | ID_NOMBRE  '[' entonacion ']' ':' expr_cadena          { 
                                                                  cout << "-------- personaje " << " [" << $1 << "] " << " en linea " << n_lineas << " dice : " << $6 << " con entonación " << $3 << endl; 
                                                                  
                                                                  if(chs.isExists($1)){
                                                                        chs.get($1, ch);
                                                                        str = ch.languaje + "+";
                                                                        str += ch.gender;
                                                                        str += to_string(ch.numCharacter) + " ";
                                                                        strcpy(tc, str.c_str());
                                                                        strcat(tc, $3);
                                                                        strcat(tc, $6);

                                                                        if(esBucle)
                                                                              (*table).add(Row(tc, TIPO_ROW::T_FRASE)); 
                                                                        else
                                                                              salida << "espeak -v " << tc << endl;  
                                                                  } 


                                                               
                                                               } salto

      | MENSAJE expr_cadena                                    { 

                                                                  strcpy(tc, $2);
                                                                  cout << "-------- mensaje " << $2 << endl; 
                                                                  
                                                                  if(esBucle)
                                                                        (*table).add(Row(tc, TIPO_ROW::T_MENSAJE)); 
                                                                  else
                                                                        salida << "echo " << tc << endl;
                                                               } salto

      | PAUSA expr_arit                                        { 
                                                                  cout << "-------- pausa " << $2.valor << endl; 
                                                                  
                                                                  if(esBucle)
                                                                        (*table).add(Row($2.valor, TIPO_ROW::T_PAUSA)); 
                                                                  else
                                                                        salida << "sleep " << $2.valor << endl;
                                                                  
                                                               } salto
      // TODO #4 completar detección para fichero salida y bucle (identificador)
      | identificador
       // TODO #5 completar detección para fichero salida y bucle (condicional)
      | condicional      
      // TODO #6 completar detección para fichero salida y bucle (bucle)
      | bucle
      ;
/* para bucles anidados añadir una variable para indicar en que nivel de profundidad de bucles nos encontramos */
bucle: REPETIR expr_arit '{' salto {table = new Table($2.valor); esBucle = true; cout << "+++ repetir " << $2.valor <<  "(n_loop=" << n_loop <<  ") " << endl;}  secBloqueEscena '}' salto  {esBucle = false; ls.add((*table)); table->run(salida); cout << "+++ fin repetir " << $2.valor << endl; n_loop++;}

condicional: parteSi parteSiNo 
      ;

parteSi: SI '(' expr_log ')' salto_opc  '{' salto {ejecutar=$3;} secBloqueEscena '}' salto        {cout << "+++ bloque si ( condicion=" << $3 <<  ")" << endl;} 
      ;

parteSiNo: %prec SI
      | SI_NO  '{' salto {ejecutar = !ejecutar;} secBloqueEscena '}' salto              {cout << "+++ bloque sino " << endl;}
      ;

/*------------------------------------------------ entonacion ------------------------------------------------*/ 

entonacion: TONO                    {strcpy($$, $1);}
      | entonacion ',' TONO         {strcpy($$, $1); strcat($$, $3);}
      ;

/* ------------------------------------------------ expresiones ------------------------------------------------*/ 

expr_cadena : CADENA                           {strcpy($$, $1);}
      | ID_CADENA                              {strcpy($$, $1);} // TODO : obtener valor
      | expr_arit                              {string str = '"' + to_string($1.valor)  + '"'; strcpy($$, str.c_str());}
      | expr_cadena CONCATENACION expr_cadena  {cout << "-------- concatenacion cadena (" << $1 << ") cadena(" << $3 <<  ")" << endl; 
                                                string str1($1);  
                                                string str2($3);  

                                                str1 = str1.replace(0, 1, "");
                                                str1 = str1.replace(str1.length()-1, 1, "");

                                                str2 = str2.replace(0, 1, "");
                                                str2 = str2.replace(str2.length()-1, 1, "");

                                                str1 = '"' + str1 + str2 + '"';
                                                strcpy($$, str1.c_str());}
      ;     

expr_log : TRUE                               {$$ = true; }
      | FALSE                                 {$$ = false; }
      | expr_log AND expr_log                 {$$ = $1 and $3; }
      | expr_log OR expr_log                  {$$ = $1 or $3; }
      | NOT expr_log %prec NOT                {$$ = (not $2); }
      | '(' expr_log ')'		          {$$ =     $2; }
      | expr_arit '>' expr_arit               {$$ = ($1.valor > $3.valor)  ? true : false; } 
      | expr_arit MAYORIGUAL expr_arit        {$$ = ($1.valor >= $3.valor) ? true : false; } 
      | expr_arit '<' expr_arit               {$$ = ($1.valor < $3.valor)  ? true : false; } 
      | expr_arit MENORIGUAL expr_arit        {$$ = ($1.valor <= $3.valor) ? true : false; } 
      | expr_arit IGUAL2 expr_arit            {$$ = ($1.valor == $3.valor) ? true : false; } 
      | expr_arit DISTINTO expr_arit          {$$ = ($1.valor != $3.valor) ? true : false; } 
      | expr_log IGUAL2 expr_log              {$$ = ($1 == $3) ? true : false; } 
      | expr_log DISTINTO expr_log            {$$ = ($1 != $3) ? true : false; } 
      ;

expr_arit: NUMERO			                {$$.esReal = false; $$.valor = $1; } 
      | REAL                                  {$$.esReal = true;  $$.valor = $1; }      
      | ID_GENERAL                       {
                                          if(ids.isExists($1)){
                                                if(ids.getTipo($1) == TIPO_IDENT::T_ENT){
                                                      $$.esReal = false;
                                                      ids.get($1, ident);
                                                      $$.valor = ident.valor.valor_entero;
                                                }
                                                else if(ids.getTipo($1) == TIPO_IDENT::T_REAL){
                                                      $$.esReal = true;
                                                      ids.get($1, ident);
                                                      $$.valor = ident.valor.valor_real;
                                                }
                                                else{ 
                                                      cout << "Error semantico en la linea " << n_lineas << ", la variable " << $1 << " no es de tipo ENTERA o REAL" << endl;            
                                                      errorSemantico = true;
                                                }
                                          } 
                                          else{
                                                cout << "Error semantico en la linea " << n_lineas << ", la variable " << $1 << " no esta definida" << endl;
                                                errorVariable = true;
                                                
                                          }
                                    }            
      | expr_arit '+' expr_arit               {$$.esReal = $1.esReal || $3.esReal; $$.valor = ($$.esReal) ? $1.valor + $3.valor : int($1.valor) + int($3.valor); }
      | expr_arit '-' expr_arit               {$$.esReal = $1.esReal || $3.esReal; $$.valor = ($$.esReal) ? $1.valor - $3.valor : int($1.valor) - int($3.valor); }
      | expr_arit '*' expr_arit               {$$.esReal = $1.esReal || $3.esReal; $$.valor = ($$.esReal) ? $1.valor * $3.valor : int($1.valor) * int($3.valor); }
      
      | expr_arit '/' expr_arit               {$$.esReal = true; 
                                                if($3.valor == 0){ 
                                                      errorSemantico = true; 
                                                      cout << "Error semantico en la linea " << n_lineas << ", se ha detectado una división entre el número 0" << endl;
                                                } 
                                                else 
                                                      $$.valor = $1.valor / $3.valor;
                                              }

      | expr_arit DIV expr_arit               {$$.esReal = $1.esReal || $3.esReal; 
                                                if($3.valor == 0){ 
                                                      errorSemantico = true;
                                                      cout << "Error semantico en la linea " << n_lineas << ", se ha detectado una divisón entre el número 0" << endl;
                                                }else {
                                                      if($$.esReal){ 
                                                            errorSemantico = true; 
                                                           cout << "Error semantico en la linea " << n_lineas << ", el operador div no se puede usar con datos de tipo real " << endl;
                                                      } 
                                                      else 
                                                            $$.valor = int($1.valor) / int($3.valor);
                                                }
                                               }
                                                
      |'-' expr_arit %prec menos              {$$.esReal = $2.esReal ; $$.valor = ($2.esReal) ? -$2.valor : int(-$2.valor); }
      | '(' expr_arit ')'		          {$$.esReal = $2.esReal ; $$.valor = ($2.esReal) ?  $2.valor : int( $2.valor); }
      ;
%%

int main(int argc, char *argv[]){
     
      if(argc >= 2){
            if(strlen(argv[1]) > 5){

                  string outfile = argv[1];
                  string outfileExtension = outfile.substr(outfile.length()-3, outfile.length());
                  string outfileName = outfile.substr(0, outfile.length()-4);

                  if(outfileExtension.compare("dia") != 0){
                        cout << argv[1] << ": La extensión del archivo de entrada no es el correcto " << endl;
                        return -1;
                  }else{
                        n_lineas = 1;  
                        n_escena = 0;   
                        n_loop = 0;
                        
                        yyin = fopen(argv[1], "rt");
                        salida.open(outfileName + ".sh");
                  
                        yyparse(); //llamada al analizador semantico
                  
                        salida.close();

                        ids.printIdentifiers(); // mostramos los identificadores declarados
                        chs.printCharacters(); // mostramos los personajes declarados
                        ls.printLoops(); // mostramos los bucles declarados

                        return 0; 
                  }
                  	
            }else{
                  cout << argv[1] << ": Error el fichero de entrada debe ser formato .dia (name_file.dia)" << endl;
		      return -1;
            }
	
	}else{
		cout << argv[0] << ": Error en el número de elementos" << endl;
		return -1;
	}
}
