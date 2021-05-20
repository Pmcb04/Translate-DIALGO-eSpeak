%{

/*
 *      Proyecto Teoría de Lenguaje
 * 	Fichero : lexico.l
 *	Autor : Pedro Miguel Carmona Broncano && Rubén Marín Lucas
 */

#include "expresiones.h"
#include "identifiers.h"
#include <math.h>
#include <iostream>
#include <string>

int n_lineas;
%}

%option noyywrap
%x COMMENT1

digito [0-9]
mayuscula [A-ZÑ]
minuscula [a-zñ]
entero {digito}+
letra [a-zA-ZñÑ_]
caracter [a-zA-ZñÑ0-9_]
cadena ["][^"]*["]
identificadorNombre {mayuscula}{caracter}*
identificadorCadena [_]{caracter}*
identificadorGeneral {minuscula}{caracter}* 
real {entero}[.]{entero}?|{entero}?[.]{entero}
 
%%

"#"				                        BEGIN(COMMENT1); 
<COMMENT1>"\n"			                {BEGIN(0); return '\n';}
<COMMENT1>.                             ;

PERSONAJES                              return PERSONAJES;
DEFINICIONES                            return DEFINICIONES;
ESCENA                                  return ESCENA;
FINESCENA                               return FINESCENA;

pausa                                   return PAUSA;
mensaje                                 return MENSAJE;

despacio                                {strcpy(yylval.c_cadena, "-s 80 ");  return TONO;}
deprisa                                 {strcpy(yylval.c_cadena, "-s 300 "); return TONO;}
gritando                                {strcpy(yylval.c_cadena, "-a 200 "); return TONO;}
voz[ ]baja                              {strcpy(yylval.c_cadena, "-a 30 ");  return TONO;}

en                                      {strcpy(yylval.c_cadena, yytext); return IDIOMA;}
en-us                                   {strcpy(yylval.c_cadena, yytext); return IDIOMA;}
es                                      {strcpy(yylval.c_cadena, yytext); return IDIOMA;}
es-la                                   {strcpy(yylval.c_cadena, yytext); return IDIOMA;}
pt                                      {strcpy(yylval.c_cadena, yytext); return IDIOMA;}
it                                      {strcpy(yylval.c_cadena, yytext); return IDIOMA;}
fr                                      {strcpy(yylval.c_cadena, yytext); return IDIOMA;}

m                                       {strcpy(yylval.c_cadena, yytext); return VOZ;}
f                                       {strcpy(yylval.c_cadena, yytext); return VOZ;}

si                                      return SI;
si_no                                   return SI_NO;
repetir                                 return REPETIR;

[d][i][v]                               return DIV;
[a][n][d]                               return AND;
[o][r]                                  return OR;
[n][o][t]                               return NOT;
[>][=]                                  return MAYORIGUAL;
[<][=]                                  return MENORIGUAL;
[=][=]                                  return IGUAL2;
[!][=]                                  return DISTINTO;
[+][+]                                  return CONCATENACION;
[t][r][u][e]                            {yylval.c_bool = true; return TRUE;}
[f][a][l][s][e]                         {yylval.c_bool = false;  return FALSE;}

{identificadorNombre}                   {strcpy(yylval.c_identificador, yytext); return ID_NOMBRE;}
{identificadorCadena}                   {strcpy(yylval.c_identificador, yytext); return ID_CADENA;}
{identificadorGeneral}                  {strcpy(yylval.c_identificador, yytext); return ID_GENERAL;}
{cadena}                                {strcpy(yylval.c_cadena, yytext); return CADENA;}

{real}			                        {yylval.c_real = atof(yytext); return REAL;}
{entero}		                        {yylval.c_entero = atoi(yytext);return NUMERO;}
\n			                            return '\n';
[\t ]			                        ;	
. 			                            return (yytext[0]);
%%

