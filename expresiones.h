/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_EXPRESIONES_H_INCLUDED
# define YY_YY_EXPRESIONES_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMERO = 258,                  /* NUMERO  */
    REAL = 259,                    /* REAL  */
    DIV = 260,                     /* DIV  */
    AND = 261,                     /* AND  */
    OR = 262,                      /* OR  */
    NOT = 263,                     /* NOT  */
    TRUE = 264,                    /* TRUE  */
    FALSE = 265,                   /* FALSE  */
    MAYORIGUAL = 266,              /* MAYORIGUAL  */
    MENORIGUAL = 267,              /* MENORIGUAL  */
    IGUAL2 = 268,                  /* IGUAL2  */
    DISTINTO = 269,                /* DISTINTO  */
    PERSONAJES = 270,              /* PERSONAJES  */
    DEFINICIONES = 271,            /* DEFINICIONES  */
    ESCENA = 272,                  /* ESCENA  */
    FINESCENA = 273,               /* FINESCENA  */
    ID_GENERAL = 274,              /* ID_GENERAL  */
    ID_NOMBRE = 275,               /* ID_NOMBRE  */
    ID_CADENA = 276,               /* ID_CADENA  */
    PAUSA = 277,                   /* PAUSA  */
    MENSAJE = 278,                 /* MENSAJE  */
    CADENA = 279,                  /* CADENA  */
    EN = 280,                      /* EN  */
    EN_US = 281,                   /* EN_US  */
    ES = 282,                      /* ES  */
    ES_LA = 283,                   /* ES_LA  */
    PT = 284,                      /* PT  */
    IT = 285,                      /* IT  */
    FR = 286,                      /* FR  */
    DESPACIO = 287,                /* DESPACIO  */
    DEPRISA = 288,                 /* DEPRISA  */
    GRITANDO = 289,                /* GRITANDO  */
    VOZ_BAJA = 290,                /* VOZ_BAJA  */
    MASCULINO = 291,               /* MASCULINO  */
    FEMENINO = 292,                /* FEMENINO  */
    CONCATENACION = 293,           /* CONCATENACION  */
    SI = 294,                      /* SI  */
    SI_NO = 295,                   /* SI_NO  */
    menos = 296                    /* menos  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 43 "expresiones.y"

 int c_entero;
 float c_real;
 bool c_bool;
 char c_identificador[25];
 char c_cadena[255];
  
 struct{
       float valor;
       bool esReal;
 } c_expresion_arit;


#line 119 "expresiones.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXPRESIONES_H_INCLUDED  */
