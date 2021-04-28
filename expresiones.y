%{

/*
 *      Proyecto Teoría de Lenguaje
 * 	Fichero : expresiones.y
 *	Autor : Pedro Miguel Carmona Broncano && Rubén Marín Lucas
 */

#include <string>
#include <fstream>
#include <iostream> 
#include <sstream>
#include "identifiers.h"
using namespace std;

 
//elementos externos al analizador sintácticos por haber sido declarados en el analizador léxico      			
extern int n_lineas;
extern int yylex();
extern FILE* yyin;

//definición de procedimientos auxiliares
void yyerror(const char* s){         /*    llamada por cada error sintactico de yacc */
	cout << "Error sintáctico en la línea "<< n_lineas << " : "  << s <<endl;	
}

//Zona de definiciones
bool errorSemantico = false; 
bool errorVariable = false;
int n_escena;
Identifiers ids;
Info info;
TIPO tipo;
ofstream salida;

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
%type <c_bool> expr_log
%type <c_expresion_arit> expr_arit
%type <c_cadena> expr_cadena
%type <c_cadena> CADENA
%type <c_cadena> idioma
%type <c_cadena> voz

%start entrada
%token NUMERO REAL DIV AND OR NOT TRUE FALSE MAYORIGUAL MENORIGUAL IGUAL2 DISTINTO 
%token PERSONAJES DEFINICIONES ESCENA FINESCENA 
%token ID_GENERAL ID_NOMBRE ID_CADENA 
%token PAUSA MENSAJE REPETIR SI SI_NO CADENA 
%token EN EN_US ES ES_LA PT IT FR
%token DESPACIO DEPRISA GRITANDO VOZ_BAJA
%token MASCULINO FEMENINO
%token CONCATENACION

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

salto: '\n'          {n_lineas++;}
      | salto '\n'  {n_lineas++;}

entrada: 	
      |entrada linea  
      ;

      
linea: ID_GENERAL '=' expr_arit    {
                                    if(!errorVariable && !errorSemantico){
                                          if(!ids.isExists($1))
                                                ($3.esReal)? ids.add(Info($1, n_lineas, $3.valor)) : ids.add(Info($1, n_lineas, (int)$3.valor));
                                          else if($3.esReal && ids.getTipo($1) == TIPO::T_REAL)
                                                ids.setValor($1, $3.valor);
                                          
                                          else if(!$3.esReal && ids.getTipo($1) == TIPO::T_ENT)
                                                ids.setValor($1, (int)$3.valor);                                          
                                          else{

                                                cout << "Error semantico en la linea " << n_lineas << ", la variable " << $1 << " es de tipo ";
                                                
                                                tipo = ids.getTipo($1); // averiguamos el tipo de $1, es decir de la variable

                                                switch (tipo) {
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
                                          if(!ids.isExists($1))
                                                ids.add(Info($1, n_lineas, $3));
                                          else if(ids.getTipo($1) == TIPO::T_BOOL)
                                                ids.setValor($1, $3);
                                          else{

                                                cout << "Error semantico en la linea " << n_lineas << ", la variable " << $1 << " es de tipo ";
                                                
                                                tipo = ids.getTipo($1); // averiguamos el tipo de $1, es decir de la variable

                                                switch (tipo) {
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

      | PERSONAJES {cout << "bloque personajes linea " << n_lineas << endl;} salto
      | DEFINICIONES {cout << "bloque definiciones linea " << n_lineas << endl;} salto
      | ESCENA expr_arit ':' {
                                    if(!$2.esReal){
                                          if($2.valor > n_escena){
                                                salida << "echo Inicio de la escena " << $2.valor << endl;
                                                n_escena = $2.valor;
                                          }
                                          else
                                                cout << "Error semantico en la linea " << n_lineas << ", la escena " << $2.valor << " no puede ser procesada" <<  endl;
                                    }
                                    else
                                          cout << "Error semantico en la linea " << n_lineas << ", el número de escena debe ser de tipo ENTERO" << endl;
      
      
                              } salto
      | FINESCENA {salida << "echo Fin de la escena " << n_escena << endl; } salto
      | PAUSA expr_arit {salida << "sleep " << $2.valor << endl;} salto
      | REPETIR expr_arit {cout << "detectado repetir " << $2.valor << " (real=" << $2.esReal << ") linea " << n_lineas << endl;}
      | MENSAJE expr_cadena  {salida << "echo " << strncpy($2, $2+1, strlen($2-2)) << endl;} salto // TODO completar salida
      | SI '(' expr_log ')' '{' {cout << "detectado si (condicion=" << $3 << ") linea "  << n_lineas << endl;} salto
      | SI_NO '{' {cout << "detectado si_no linea " << n_lineas << endl;} salto

      | ID_CADENA '=' expr_cadena {cout << "asignacion id_cadena " << $1 <<  ", " << $3 << endl;
      
                                     if(!errorVariable && !errorSemantico){
                                          if(!ids.isExists($1))
                                                ids.add(Info($1, n_lineas, $3));
                                          else if(ids.getTipo($1) == TIPO::T_CADENA)
                                                ids.setValor($1, $3);
                                          else{

                                                cout << "Error semantico en la linea " << n_lineas << ", la variable " << $1 << " es de tipo ";
                                                
                                                tipo = ids.getTipo($1); // averiguamos el tipo de $1, es decir de la variable

                                                switch (tipo) {
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

      | ID_NOMBRE '=' '<' idioma ',' voz '>' salto { cout << "asignacion nombre " << $1 << "," << $4 << "," << $6 <<  " linea " << n_lineas << endl;}

      | ID_NOMBRE ':' expr_cadena                              { cout << "personaje " << " [" << $1 << "] " << " dice : " << $3 << endl; } salto
      | ID_NOMBRE  '[' ']' ':' expr_cadena                     { cout << "personaje " << " [" << $1 << "] " << " dice : " << $5 << endl; } salto
      | ID_NOMBRE  '[' entonacion ']' ':' expr_cadena          { cout << "personaje " << " [" << $1 << "] " << " dice : " << $6 << " con entonación   " << endl; } salto


      | error salto  {yyerrok; errorSemantico = false; errorVariable = false;}	   
	;

expr_cadena : 
      CADENA                                   {strcpy($$, $1);}
      | ID_CADENA                              {cout << "id_cadena" << endl; strcpy($$, $1);}
      | expr_arit                              {cout << "expr_arit" << endl;}
      | expr_cadena CONCATENACION expr_cadena  {cout << "concatenacion cadena (" << $1 << ") cadena(" << $3 <<  ")" << endl; strcpy($$, $1); strcat($$, $3);}
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
                                                if(ids.getTipo($1) == TIPO::T_ENT){
                                                      $$.esReal = false;
                                                      ids.get($1, info);
                                                      $$.valor = info.valor.valor_entero;
                                                }
                                                else if(ids.getTipo($1) == TIPO::T_REAL){
                                                      $$.esReal = true;
                                                      ids.get($1, info);
                                                      $$.valor = info.valor.valor_real;
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

entonacion:
      DESPACIO                      {cout << "despacio" << endl;}
      | DEPRISA                     {cout << "deprisa" << endl;}
      | GRITANDO                    {cout << "gritando" << endl;}
      | VOZ_BAJA                    {cout << "voz_baja" << endl;}
      | entonacion ',' DESPACIO     {cout << "despacio coma" << endl;}
      | entonacion ',' DEPRISA      {cout << "deprisa coma" << endl;}
      | entonacion ',' GRITANDO     {cout << "gritando coma" << endl;}
      | entonacion ',' VOZ_BAJA     {cout << "voz_baja coma" << endl;}
      ;

idioma:
      EN                {strcpy($$, "en");}
      | EN_US           {strcpy($$, "en-us");}
      | ES              {strcpy($$, "es");}
      | ES_LA           {strcpy($$, "es-la");}
      | PT              {strcpy($$, "pt");}      
      | IT              {strcpy($$, "it");}
      | FR              {strcpy($$, "fr");}
      ;
voz:
      MASCULINO         {strcpy($$, "m");}
      |FEMENINO         {strcpy($$, "f");}
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
                        
                        yyin = fopen(argv[1], "rt");
                        salida.open(outfileName + ".txt");
                  
                        yyparse(); //llamada al analizador semantico
                  
                        salida.close();

                        ids.printIdentifiers();

                        return 0; 
                  }
                  	
            }else{
                  cout << argv[1] << ": ERROR el fichero de entrada debe ser formato .dia (name_file.dia)" << endl;
		      return -1;
            }
	
	}else{
		cout << argv[0] << ": ERROR en el número de elementos" << endl;
		return -1;
	}
}