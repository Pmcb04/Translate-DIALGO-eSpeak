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

"#"				        BEGIN(COMMENT1); 
<COMMENT1>"\n"			{BEGIN(0); return '\n';}
<COMMENT1>.             ;

[P][E][R][S][O][N][A][J][E][S]          {return PERSONAJES;}
[D][E][F][I][N][I][C][I][O][N][E][S]    {return DEFINICIONES;}
[E][S][C][E][N][A]                      {return ESCENA;}
[F][I][N][E][S][C][E][N][A]             {return FINESCENA;}

[p][a][u][s][a]                         {return PAUSA;}
[m][e][n][s][a][j][e]                   {return MENSAJE;}
[r][e][p][e][t][i][r]                   {return REPETIR;}
[s][i]                                  {return SI;}
[s][i][_][n][o]                         {return SI_NO;}

[d][e][s][p][a][c][i][o]                {return DESPACIO;}
[d][e][p][r][i][s][a]                   {return DEPRISA;}
[g][r][i][t][a][n][d][o]                {return GRITANDO;}
[v][o][z][ ][b][a][j][a]                {return VOZ_BAJA;}

[e][n]                                  {strcpy(yylval.c_cadena, yytext); return EN;}
[e][n][-][u][s]                         {strcpy(yylval.c_cadena, yytext); return EN_US;}
[e][s]                                  {strcpy(yylval.c_cadena, yytext); return ES;}
[e][s][-][l][a]                         {strcpy(yylval.c_cadena, yytext); return ES_LA;}
[p][t]                                  {strcpy(yylval.c_cadena, yytext); return PT;}
[i][t]                                  {strcpy(yylval.c_cadena, yytext); return IT;}
[f][r]                                  {strcpy(yylval.c_cadena, yytext); return FR;}

[m]                                     {strcpy(yylval.c_cadena, yytext); return MASCULINO;}
[f]                                     {strcpy(yylval.c_cadena, yytext); return FEMENINO;}


[d][i][v]                               return DIV;
[a][n][d]                               return AND;
[o][r]                                  return OR;
[n][o][t]                               return NOT;
[>][=]                                  return MAYORIGUAL;
[<][=]                                  return MENORIGUAL;
[=][=]                                  return IGUAL2;
[!][=]                                  return DISTINTO;
[+][+]                                  {return CONCATENACION;}
[t][r][u][e]                            {yylval.c_bool = true; return TRUE;}
[f][a][l][s][e]                         {yylval.c_bool = false;  return FALSE;}

{identificadorNombre}                   {strcpy(yylval.c_identificador, yytext); return ID_NOMBRE;}
{identificadorCadena}                   {strcpy(yylval.c_identificador, yytext); return ID_CADENA;}
{identificadorGeneral}                  {strcpy(yylval.c_identificador, yytext); return ID_GENERAL;}
{cadena}                                {strcpy(yylval.c_cadena, yytext); return CADENA;}

{real}			                        {yylval.c_real = atof(yytext); return REAL;}
{entero}		                        {yylval.c_entero = atoi(yytext);return NUMERO;}
\n			                            {return '\n';}
[\t ]			                        ;	
. 			                            return (yytext[0]);
%%

