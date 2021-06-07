/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "expresiones.y"


/*
 *      Proyecto Teoría de Lenguaje
 * 	Fichero : expresiones.y
 *	Autor : Pedro Miguel Carmona Broncano && Rubén Marín Lucas
 */


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


// banderas definidas para la utilizacion de bucles, condicionales y detenciones de errores
bool errorBucle;              // bandera que indica si se ha producido un error en un bucle
bool esBucle;                 // indica si estamos dentro de un bucle

bool errorCondicional;       // bandera que indica si se ha producido un error en un condicional 
bool ejecutar[100];           // vector de banderas que indican el bloque que se debe ejecutar del condicional
bool esCondicional[100];      // vector de banderas que indican si estamos dentro de un condicional

bool errorVariable;           // bandera que indica si existe un error relacionado con el tipo de variable
bool errorEscena;             // bandera que indica si se ha producido un error en una escena
bool errorSemantico;          // bandera que indica si se ha producido un error semantico

ofstream salida;              // flujo de datos hacia el fichero de salida
ofstream debug;              // flujo de datos hacia el fichero de debug

int n_escena;                 // contador que indica el numero de escena que nos encontramos
int n_condicional;            // contador que indica el numero de condicionales anidados, en cual nos encontramos

//definición de procedimientos auxiliares
void yyerror(const char* s){         /*    llamada por cada error sintactico de yacc */
	cout << "***** Error sintáctico en la línea "<< n_lineas << " : "  << s <<endl;	
      if(esCondicional[n_condicional]){
            ejecutar[n_condicional] = false;
            esCondicional[n_condicional] = false;
            n_condicional = 0;
            errorCondicional = true;
      }else errorCondicional = false;

      if(esBucle){
            errorBucle = true;
            esBucle = false;
      }
      else errorBucle = false;
}

//Zona de definiciones

string str;
tipo_cadena tc;

Character ch;
Characters chs;  

Loops ls;
Table *table;
Table *father;

Identifiers ids;
Identifier ident;
TIPO_IDENT tipo_ident;


#line 152 "expresiones.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "expresiones.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMERO = 3,                     /* NUMERO  */
  YYSYMBOL_REAL = 4,                       /* REAL  */
  YYSYMBOL_DIV = 5,                        /* DIV  */
  YYSYMBOL_AND = 6,                        /* AND  */
  YYSYMBOL_OR = 7,                         /* OR  */
  YYSYMBOL_NOT = 8,                        /* NOT  */
  YYSYMBOL_TRUE = 9,                       /* TRUE  */
  YYSYMBOL_FALSE = 10,                     /* FALSE  */
  YYSYMBOL_MAYORIGUAL = 11,                /* MAYORIGUAL  */
  YYSYMBOL_MENORIGUAL = 12,                /* MENORIGUAL  */
  YYSYMBOL_IGUAL2 = 13,                    /* IGUAL2  */
  YYSYMBOL_DISTINTO = 14,                  /* DISTINTO  */
  YYSYMBOL_PERSONAJES = 15,                /* PERSONAJES  */
  YYSYMBOL_DEFINICIONES = 16,              /* DEFINICIONES  */
  YYSYMBOL_ESCENA = 17,                    /* ESCENA  */
  YYSYMBOL_FINESCENA = 18,                 /* FINESCENA  */
  YYSYMBOL_ID_GENERAL = 19,                /* ID_GENERAL  */
  YYSYMBOL_ID_NOMBRE = 20,                 /* ID_NOMBRE  */
  YYSYMBOL_ID_CADENA = 21,                 /* ID_CADENA  */
  YYSYMBOL_PAUSA = 22,                     /* PAUSA  */
  YYSYMBOL_MENSAJE = 23,                   /* MENSAJE  */
  YYSYMBOL_CADENA = 24,                    /* CADENA  */
  YYSYMBOL_IDIOMA = 25,                    /* IDIOMA  */
  YYSYMBOL_TONO = 26,                      /* TONO  */
  YYSYMBOL_VOZ = 27,                       /* VOZ  */
  YYSYMBOL_CONCATENACION = 28,             /* CONCATENACION  */
  YYSYMBOL_SI = 29,                        /* SI  */
  YYSYMBOL_SI_NO = 30,                     /* SI_NO  */
  YYSYMBOL_REPETIR = 31,                   /* REPETIR  */
  YYSYMBOL_32_ = 32,                       /* '<'  */
  YYSYMBOL_33_ = 33,                       /* '>'  */
  YYSYMBOL_34_ = 34,                       /* '+'  */
  YYSYMBOL_35_ = 35,                       /* '-'  */
  YYSYMBOL_36_ = 36,                       /* '*'  */
  YYSYMBOL_37_ = 37,                       /* '/'  */
  YYSYMBOL_menos = 38,                     /* menos  */
  YYSYMBOL_39_n_ = 39,                     /* '\n'  */
  YYSYMBOL_40_ = 40,                       /* '='  */
  YYSYMBOL_41_ = 41,                       /* ','  */
  YYSYMBOL_42_ = 42,                       /* ':'  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_47_ = 47,                       /* '('  */
  YYSYMBOL_48_ = 48,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_salto = 50,                     /* salto  */
  YYSYMBOL_salto_opc = 51,                 /* salto_opc  */
  YYSYMBOL_programa = 52,                  /* programa  */
  YYSYMBOL_bloquePersonajes = 53,          /* bloquePersonajes  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_secBloquePersonajes = 55,       /* secBloquePersonajes  */
  YYSYMBOL_asignacionPersonaje = 56,       /* asignacionPersonaje  */
  YYSYMBOL_bloqueDefiniciones = 57,        /* bloqueDefiniciones  */
  YYSYMBOL_58_2 = 58,                      /* $@2  */
  YYSYMBOL_secBloqueDefiniciones = 59,     /* secBloqueDefiniciones  */
  YYSYMBOL_identificador = 60,             /* identificador  */
  YYSYMBOL_identificadorGeneral = 61,      /* identificadorGeneral  */
  YYSYMBOL_identificadorCadena = 62,       /* identificadorCadena  */
  YYSYMBOL_secEscena = 63,                 /* secEscena  */
  YYSYMBOL_escena = 64,                    /* escena  */
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_secBloqueEscena = 66,           /* secBloqueEscena  */
  YYSYMBOL_bloqueEscena = 67,              /* bloqueEscena  */
  YYSYMBOL_68_4 = 68,                      /* $@4  */
  YYSYMBOL_lineaEscena = 69,               /* lineaEscena  */
  YYSYMBOL_bucle = 70,                     /* bucle  */
  YYSYMBOL_71_5 = 71,                      /* $@5  */
  YYSYMBOL_condicional = 72,               /* condicional  */
  YYSYMBOL_parteSi = 73,                   /* parteSi  */
  YYSYMBOL_74_6 = 74,                      /* $@6  */
  YYSYMBOL_parteSiNo = 75,                 /* parteSiNo  */
  YYSYMBOL_76_7 = 76,                      /* $@7  */
  YYSYMBOL_entonacion = 77,                /* entonacion  */
  YYSYMBOL_expr_cadena = 78,               /* expr_cadena  */
  YYSYMBOL_expr_log = 79,                  /* expr_log  */
  YYSYMBOL_expr_arit = 80                  /* expr_arit  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      47,    48,    36,    34,    41,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,     2,
      32,    40,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   141,   141,   142,   145,   146,   150,   155,   155,   158,
     159,   162,   163,   168,   169,   169,   172,   173,   174,   177,
     178,   182,   228,   265,   302,   303,   306,   306,   335,   336,
     339,   340,   341,   341,   342,   343,   346,   374,   402,   433,
     454,   478,   478,   539,   542,   542,   563,   564,   564,   588,
     589,   594,   595,   613,   628,   651,   652,   653,   654,   655,
     656,   657,   658,   659,   660,   661,   662,   663,   664,   667,
     668,   669,   692,   693,   694,   696,   705,   719,   720
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMERO", "REAL",
  "DIV", "AND", "OR", "NOT", "TRUE", "FALSE", "MAYORIGUAL", "MENORIGUAL",
  "IGUAL2", "DISTINTO", "PERSONAJES", "DEFINICIONES", "ESCENA",
  "FINESCENA", "ID_GENERAL", "ID_NOMBRE", "ID_CADENA", "PAUSA", "MENSAJE",
  "CADENA", "IDIOMA", "TONO", "VOZ", "CONCATENACION", "SI", "SI_NO",
  "REPETIR", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "menos", "'\\n'",
  "'='", "','", "':'", "'['", "']'", "'{'", "'}'", "'('", "')'", "$accept",
  "salto", "salto_opc", "programa", "bloquePersonajes", "$@1",
  "secBloquePersonajes", "asignacionPersonaje", "bloqueDefiniciones",
  "$@2", "secBloqueDefiniciones", "identificador", "identificadorGeneral",
  "identificadorCadena", "secEscena", "escena", "$@3", "secBloqueEscena",
  "bloqueEscena", "$@4", "lineaEscena", "bucle", "$@5", "condicional",
  "parteSi", "$@6", "parteSiNo", "$@7", "entonacion", "expr_cadena",
  "expr_log", "expr_arit", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    60,    62,    43,    45,    42,    47,   287,    10,
      61,    44,    58,    91,    93,   123,   125,    40,    41
};
#endif

#define YYPACT_NINF (-113)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-33)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -113,    -7,     3,  -113,  -113,    13,  -113,    -3,  -113,    26,
    -113,     5,    -3,    84,    26,  -113,    -3,    28,  -113,    69,
    -113,    -5,  -113,  -113,  -113,    84,    84,   149,  -113,    32,
      40,  -113,    65,   103,   237,  -113,  -113,  -113,  -113,   172,
      84,    84,    84,    84,    84,    -3,   119,   153,   145,    -3,
    -113,  -113,  -113,    25,    25,  -113,  -113,    32,   104,   153,
    -113,  -113,   153,   246,   212,  -113,  -113,   -13,    61,    32,
     272,   132,  -113,   229,    87,   162,   153,   153,   153,   153,
      32,    84,    84,    84,    84,    84,    84,    32,   145,    32,
      -3,    11,    84,   145,   118,  -113,   249,  -113,   129,  -113,
    -113,   138,   137,  -113,   111,     4,  -113,  -113,    61,    61,
      61,    61,    61,    61,  -113,    32,   145,   -17,   196,   -13,
     153,    -3,  -113,    84,  -113,  -113,  -113,    -3,   -13,  -113,
     136,    58,    32,    32,   133,    32,   177,    78,    32,    32,
     145,   161,   147,  -113,    -3,    -3,   -13,  -113,   145,   113,
      32,    32,    32,   -13,    -3,   272,   272,    32,    32,    27,
      91,   272,    -3,    -3,   107,    32,    32,    -3,    32
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     7,     5,    13,     1,     0,    14,     0,
       2,     0,     0,     0,     6,    24,     0,     0,     3,     0,
       9,     0,    69,    70,    71,     0,     0,     0,    25,    12,
       0,    10,     0,     0,     0,    16,    20,    19,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    78,    76,    72,    73,    74,    75,    26,     0,     0,
      55,    56,     0,     0,     0,    52,    51,     0,    53,    18,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,    21,     0,    23,
       0,     0,     0,     0,     0,    31,     0,    28,     0,    30,
      34,    46,     0,    60,    57,    58,    67,    68,    62,    64,
      65,    66,    63,    61,    54,    35,     0,     0,     0,     0,
       0,     0,    29,     0,    33,     4,    43,     0,     0,    49,
       0,     0,    40,    39,     0,    27,     0,     0,    11,    36,
       0,     0,     0,     4,     0,     0,     0,    50,     0,     0,
      41,    47,    37,     0,     0,     0,     0,    38,    44,     0,
       0,     0,     0,     0,     0,    42,    48,     0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,   -12,  -112,  -113,  -113,  -113,  -113,   152,  -113,  -113,
    -113,    70,  -113,  -113,  -113,   165,  -113,    60,   -95,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,   -81,
     -57,    -2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    11,     1,     2,     5,     7,    19,    20,     9,    12,
      34,    95,    36,    37,    14,    15,    70,    96,    97,    98,
      99,   124,   155,   100,   101,   161,   126,   156,   131,    67,
      63,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,   122,    72,     6,    29,    74,    16,   114,     3,   129,
      76,    27,   119,   137,    32,    88,    33,    78,    79,   104,
     105,   106,   107,    38,    39,    17,    10,   130,    90,     8,
      40,   149,     4,    57,    18,   128,    10,    69,    52,    53,
      54,    55,    56,    13,    18,    64,    32,    91,    33,    92,
      93,    80,    87,   116,   117,    89,    94,    73,   -32,   146,
      75,    43,    44,   134,   122,   122,    40,   153,    30,   122,
      16,    18,    46,   162,    73,    73,    73,    73,   115,   108,
     109,   110,   111,   112,   113,    -8,    -8,    22,    23,    17,
     118,    35,    90,    76,    77,    41,    42,    43,    44,   141,
      78,    79,   142,    24,    50,    47,   132,   133,    90,   135,
      32,    91,    33,    92,    93,   138,   139,     4,    73,    25,
      94,   136,   -32,   145,    78,    79,    32,    91,    33,    92,
      93,    26,   150,   151,   152,   103,    94,   163,   -32,    76,
      77,   157,   158,    48,    58,    71,    78,    79,    22,    23,
     165,   166,     4,   167,    40,   168,    22,    23,   154,   102,
     123,    59,    60,    61,    24,   120,    65,    40,   125,    66,
     127,    31,    24,    81,    82,    83,    84,    40,   140,    28,
      25,   143,    40,    41,    42,    43,    44,   147,    25,   148,
       0,    45,    26,     0,    85,    86,    41,    42,    43,    44,
      62,    40,     0,     0,     0,     0,    41,    42,    43,    44,
      51,    41,    42,    43,    44,   159,   160,    40,     0,     0,
      51,   164,   144,    81,    82,    83,    84,     0,     0,     0,
      41,    42,    43,    44,    40,    10,     0,     0,    49,     0,
      81,    82,    83,    84,    85,    86,    41,    42,    43,    44,
      90,    10,    76,    77,   -15,     0,    32,     0,    33,    78,
      79,    85,    86,    41,    42,    43,    44,   121,    32,    91,
      33,    92,    93,    90,     0,     0,     0,     0,    94,     0,
     -32,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,    32,    91,    33,    92,    93,     0,     0,     0,     0,
       0,    94,     0,   -32
};

static const yytype_int16 yycheck[] =
{
      12,    96,    59,     0,    16,    62,     1,    88,    15,    26,
       6,    13,    93,   125,    19,    28,    21,    13,    14,    76,
      77,    78,    79,    25,    26,    20,    39,    44,     1,    16,
       5,   143,    39,    45,    39,   116,    39,    49,    40,    41,
      42,    43,    44,    17,    39,    47,    19,    20,    21,    22,
      23,    63,    64,    42,    43,    67,    29,    59,    31,   140,
      62,    36,    37,   120,   159,   160,     5,   148,    40,   164,
       1,    39,    32,    46,    76,    77,    78,    79,    90,    81,
      82,    83,    84,    85,    86,    16,    17,     3,     4,    20,
      92,    21,     1,     6,     7,    34,    35,    36,    37,    41,
      13,    14,    44,    19,    34,    40,   118,   119,     1,   121,
      19,    20,    21,    22,    23,   127,   128,    39,   120,    35,
      29,   123,    31,    45,    13,    14,    19,    20,    21,    22,
      23,    47,   144,   145,   146,    48,    29,    46,    31,     6,
       7,   153,   154,    40,    25,    41,    13,    14,     3,     4,
     162,   163,    39,    46,     5,   167,     3,     4,    45,    27,
      31,     8,     9,    10,    19,    47,    21,     5,    30,    24,
      33,    19,    19,    11,    12,    13,    14,     5,    42,    14,
      35,    48,     5,    34,    35,    36,    37,    26,    35,    42,
      -1,    42,    47,    -1,    32,    33,    34,    35,    36,    37,
      47,     5,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      48,    34,    35,    36,    37,   155,   156,     5,    -1,    -1,
      48,   161,    45,    11,    12,    13,    14,    -1,    -1,    -1,
      34,    35,    36,    37,     5,    39,    -1,    -1,     1,    -1,
      11,    12,    13,    14,    32,    33,    34,    35,    36,    37,
       1,    39,     6,     7,    17,    -1,    19,    -1,    21,    13,
      14,    32,    33,    34,    35,    36,    37,    18,    19,    20,
      21,    22,    23,     1,    -1,    -1,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    52,    15,    39,    53,     0,    54,    16,    57,
      39,    50,    58,    17,    63,    64,     1,    20,    39,    55,
      56,    50,     3,     4,    19,    35,    47,    80,    64,    50,
      40,    56,    19,    21,    59,    60,    61,    62,    80,    80,
       5,    34,    35,    36,    37,    42,    32,    40,    40,     1,
      60,    48,    80,    80,    80,    80,    80,    50,    25,     8,
       9,    10,    47,    79,    80,    21,    24,    78,    80,    50,
      65,    41,    79,    80,    79,    80,     6,     7,    13,    14,
      50,    11,    12,    13,    14,    32,    33,    50,    28,    50,
       1,    20,    22,    23,    29,    60,    66,    67,    68,    69,
      72,    73,    27,    48,    79,    79,    79,    79,    80,    80,
      80,    80,    80,    80,    78,    50,    42,    43,    80,    78,
      47,    18,    67,    31,    70,    30,    75,    33,    78,    26,
      44,    77,    50,    50,    79,    50,    80,    51,    50,    50,
      42,    41,    44,    48,    45,    45,    78,    26,    42,    51,
      50,    50,    50,    78,    45,    71,    76,    50,    50,    66,
      66,    74,    46,    46,    66,    50,    50,    46,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    54,    53,    55,
      55,    56,    56,    57,    58,    57,    59,    59,    59,    60,
      60,    61,    61,    62,    63,    63,    65,    64,    66,    66,
      67,    67,    68,    67,    67,    67,    69,    69,    69,    69,
      69,    71,    70,    72,    74,    73,    75,    76,    75,    77,
      77,    78,    78,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     4,     0,     4,     1,
       2,     8,     2,     0,     0,     4,     1,     2,     3,     1,
       1,     4,     4,     4,     1,     2,     0,     8,     1,     2,
       1,     1,     0,     2,     1,     2,     4,     6,     7,     3,
       3,     0,     8,     2,     0,    11,     0,     0,     8,     1,
       3,     1,     1,     1,     3,     1,     1,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     2,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* salto: '\n'  */
#line 141 "expresiones.y"
                     {n_lineas++;}
#line 1366 "expresiones.c"
    break;

  case 3: /* salto: salto '\n'  */
#line 142 "expresiones.y"
                     {n_lineas++;}
#line 1372 "expresiones.c"
    break;

  case 5: /* salto_opc: salto_opc '\n'  */
#line 146 "expresiones.y"
                        {n_lineas++;}
#line 1378 "expresiones.c"
    break;

  case 7: /* $@1: %empty  */
#line 155 "expresiones.y"
                             {debug << "+++ bloque personajes linea " << n_lineas << endl;}
#line 1384 "expresiones.c"
    break;

  case 11: /* asignacionPersonaje: ID_NOMBRE '=' '<' IDIOMA ',' VOZ '>' salto  */
#line 162 "expresiones.y"
                                                                { debug << "-------- asignacion nombre " << (yyvsp[-7].c_identificador) << "," << (yyvsp[-4].c_cadena) << "," << (yyvsp[-2].c_cadena) <<  " linea " << n_lineas << endl; chs.add(Character((yyvsp[-7].c_identificador), n_lineas, (yyvsp[-4].c_cadena), (yyvsp[-2].c_cadena)));}
#line 1390 "expresiones.c"
    break;

  case 12: /* asignacionPersonaje: error salto  */
#line 163 "expresiones.y"
                                                {yyerrok; errorSemantico = false; errorVariable = false;}
#line 1396 "expresiones.c"
    break;

  case 14: /* $@2: %empty  */
#line 169 "expresiones.y"
                     {debug << "+++ bloque definiciones linea " << n_lineas << endl;}
#line 1402 "expresiones.c"
    break;

  case 18: /* secBloqueDefiniciones: secBloqueDefiniciones error salto  */
#line 174 "expresiones.y"
                                                {yyerrok; errorSemantico = false; errorVariable = false;}
#line 1408 "expresiones.c"
    break;

  case 21: /* identificadorGeneral: ID_GENERAL '=' expr_arit salto  */
#line 182 "expresiones.y"
                                                       {
                                          if(!errorVariable && !errorSemantico){
                                                if(!ids.isExists((yyvsp[-3].c_identificador)))
                                                      if((yyvsp[-1].c_expresion_arit).esReal){
                                                            ids.add(Identifier((yyvsp[-3].c_identificador), n_lineas, (yyvsp[-1].c_expresion_arit).valor));
                                                            debug << "-------- asignacion id_general real " << (yyvsp[-3].c_identificador) <<  ", " << (yyvsp[-1].c_expresion_arit).valor << endl;     
                                                      } else{
                                                            ids.add(Identifier((yyvsp[-3].c_identificador), n_lineas, (int)(yyvsp[-1].c_expresion_arit).valor)); 
                                                            debug << "-------- asignacion id_general entero " << (yyvsp[-3].c_identificador) <<  ", " << (yyvsp[-1].c_expresion_arit).valor << endl;     
                                                      } 
                                                            
                                                else if((yyvsp[-1].c_expresion_arit).esReal && ids.getTipo((yyvsp[-3].c_identificador)) == TIPO_IDENT::T_REAL){
                                                      ids.setValor((yyvsp[-3].c_identificador), (yyvsp[-1].c_expresion_arit).valor);
                                                      debug << "-------- actualizacion valor asignacion id_general real" << (yyvsp[-3].c_identificador) <<  ", " << (yyvsp[-1].c_expresion_arit).valor << endl;     
                                                }
                                                
                                                else if(!(yyvsp[-1].c_expresion_arit).esReal && ids.getTipo((yyvsp[-3].c_identificador)) == TIPO_IDENT::T_ENT){
                                                      ids.setValor((yyvsp[-3].c_identificador), (int)(yyvsp[-1].c_expresion_arit).valor);                                          
                                                      debug << "-------- actualizacion valor asignacion id_general entero" << (yyvsp[-3].c_identificador) <<  ", " << (yyvsp[-1].c_expresion_arit).valor << endl;     
                                                }
                                                else{

                                                      cout << "***** Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[-3].c_identificador) << " es de tipo ";
                                                      
                                                      tipo_ident = ids.getTipo((yyvsp[-3].c_identificador)); // averiguamos el tipo de $1, es decir de la variable

                                                      switch (tipo_ident) {
                                                      case T_ENT: cout << "entero "; break;
                                                      case T_REAL: cout << "real "; break;
                                                      case T_BOOL: cout << "bool "; break;
                                                      case T_CADENA: cout << "cadena "; break;
                                                      default: cout << "undefined "; break;
                                                      }

                                                      cout << "y no se le puede asignar un valor ";

                                                      if((yyvsp[-1].c_expresion_arit).esReal) cout << "real" << endl;
                                                      else cout << "entero" << endl;
                                                }
                                          }

                                          errorSemantico = false;
                                          errorVariable = false;

                                  }
#line 1458 "expresiones.c"
    break;

  case 22: /* identificadorGeneral: ID_GENERAL '=' expr_log salto  */
#line 228 "expresiones.y"
                                        {
                                   
                                          if(!errorVariable && !errorSemantico){
                                                if(!ids.isExists((yyvsp[-3].c_identificador))){
                                                      ids.add(Identifier((yyvsp[-3].c_identificador), n_lineas, (yyvsp[-1].c_bool)));
                                                      debug << "-------- asignacion id_general logico" << (yyvsp[-3].c_identificador) <<  ", " << (yyvsp[-1].c_bool) << endl;     
                                                }
                                                else if(ids.getTipo((yyvsp[-3].c_identificador)) == TIPO_IDENT::T_BOOL){
                                                      ids.setValor((yyvsp[-3].c_identificador), (yyvsp[-1].c_bool));
                                                      debug << "-------- actualizacion valor asignacion id_general logico" << (yyvsp[-3].c_identificador) <<  ", " << (yyvsp[-1].c_bool) << endl;     
                                                }
                                                else{

                                                      cout << "***** Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[-3].c_identificador) << " es de tipo ";
                                                      
                                                      tipo_ident = ids.getTipo((yyvsp[-3].c_identificador)); // averiguamos el tipo de $1, es decir de la variable

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

                                 }
#line 1496 "expresiones.c"
    break;

  case 23: /* identificadorCadena: ID_CADENA '=' expr_cadena salto  */
#line 265 "expresiones.y"
                                                      {
            
                                          if(!errorVariable && !errorSemantico){
                                                if(!ids.isExists((yyvsp[-3].c_identificador))){
                                                      ids.add(Identifier((yyvsp[-3].c_identificador), n_lineas, (yyvsp[-1].c_cadena)));
                                                      debug << "-------- asignacion id_cadena " << (yyvsp[-3].c_identificador) <<  ", " << (yyvsp[-1].c_cadena) << endl;     
                                                }
                                                else if(ids.getTipo((yyvsp[-3].c_identificador)) == TIPO_IDENT::T_CADENA){
                                                      ids.setValor((yyvsp[-3].c_identificador), (yyvsp[-1].c_cadena));
                                                      debug << "-------- actualizacion valor asignacion id_cadena " << (yyvsp[-3].c_identificador) <<  ", " << (yyvsp[-1].c_cadena) << endl;     
                                                }
                                                else{

                                                      cout << "***** Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[-3].c_identificador) << " es de tipo ";
                                                      
                                                      tipo_ident = ids.getTipo((yyvsp[-3].c_identificador)); // averiguamos el tipo de $1, es decir de la variable

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
      
                                    }
#line 1534 "expresiones.c"
    break;

  case 26: /* $@3: %empty  */
#line 306 "expresiones.y"
                                  {
                                    if(!(yyvsp[-2].c_expresion_arit).esReal){
                                          if((yyvsp[-2].c_expresion_arit).valor > n_escena){
                                                debug << "+++ Inicio de la escena " << (yyvsp[-2].c_expresion_arit).valor << endl;
                                                salida << "echo Inicio de la escena " << (yyvsp[-2].c_expresion_arit).valor << endl;
                                                n_escena = (yyvsp[-2].c_expresion_arit).valor;
                                          }
                                          else{
                                                cout << "***** Error semantico en la linea " << n_lineas << ", el numero de la escena " << (yyvsp[-2].c_expresion_arit).valor << " debe ser superior al de la escena anterior" <<  endl;
                                                errorEscena = true;
                                          }
                                               
                                    }
                                    else{
                                          cout << "***** Error semantico en la linea " << n_lineas << ", el número de escena debe ser de tipo ENTERO" << endl;
                                          errorSemantico = true;
                                    }
      
      
                              }
#line 1559 "expresiones.c"
    break;

  case 27: /* escena: ESCENA expr_arit ':' salto $@3 secBloqueEscena FINESCENA salto  */
#line 325 "expresiones.y"
                                                               {
                                          if(!errorEscena){
                                                debug << "+++ Fin de la escena " << n_escena << endl; 
                                                salida << "echo Fin de la escena " << n_escena << endl; 
                                          }

                                          errorEscena = false;
                              }
#line 1572 "expresiones.c"
    break;

  case 32: /* $@4: %empty  */
#line 341 "expresiones.y"
        {esBucle = true;}
#line 1578 "expresiones.c"
    break;

  case 35: /* bloqueEscena: error salto  */
#line 343 "expresiones.y"
                                               {yyerrok; errorSemantico = false; errorVariable = false; }
#line 1584 "expresiones.c"
    break;

  case 36: /* lineaEscena: ID_NOMBRE ':' expr_cadena salto  */
#line 346 "expresiones.y"
                                                                 { debug << "-------- personaje " << " [" << (yyvsp[-3].c_identificador) << "] "  << " en linea " << n_lineas << " dice : " << (yyvsp[-1].c_cadena) << endl; 
                                                            
                                                                  if(chs.isExists((yyvsp[-3].c_identificador))){
                                                                        chs.get((yyvsp[-3].c_identificador), ch);
                                                                        str = ch.languaje + "+";
                                                                        str += ch.gender;
                                                                        str += to_string(ch.numCharacter) + " ";
                                                                        strcpy(tc, str.c_str());
                                                                        strcat(tc, (yyvsp[-1].c_cadena));

                                                                        if(!errorSemantico && !errorVariable && !errorEscena && !errorBucle && !errorCondicional && (!esCondicional[n_condicional] || esCondicional[n_condicional] && ejecutar[n_condicional])){

                                                                              if(esBucle){
                                                                                    (*table).add(new Row(tc, TIPO_ROW::T_FRASE));
                                                                                    debug << ">>> Añadido mensaje de personaje " << " [" << (yyvsp[-3].c_identificador) << "] "  << " en linea " << n_lineas << " dice : " << (yyvsp[-1].c_cadena) << " a la table " << table << endl;
                                                                              }
                                                                              else
                                                                                    salida << "espeak -v " << tc << endl;
                                                                        }

                                                                        errorSemantico = false;
                                                                        errorVariable = false;

                                                                  }else{
                                                                        cout << "***** Error semantico, el personaje " << (yyvsp[-3].c_identificador) << " no esta definido" << endl;
                                                                  }

                                                               }
#line 1617 "expresiones.c"
    break;

  case 37: /* lineaEscena: ID_NOMBRE '[' ']' ':' expr_cadena salto  */
#line 374 "expresiones.y"
                                                               { debug << "-------- personaje " << " [" << (yyvsp[-5].c_identificador) << "] "  << " en linea " << n_lineas << " dice : " << (yyvsp[-1].c_cadena) << endl; 
                                                                  

                                                                  if(chs.isExists((yyvsp[-5].c_identificador))){
                                                                        chs.get((yyvsp[-5].c_identificador), ch);
                                                                        str = ch.languaje + "+";
                                                                        str += ch.gender;
                                                                        str += to_string(ch.numCharacter) + " ";
                                                                        strcpy(tc, str.c_str());
                                                                        strcat(tc, (yyvsp[-1].c_cadena));

                                                                        if(!errorSemantico && !errorVariable && !errorEscena && !errorBucle && !errorCondicional && (!esCondicional[n_condicional] || esCondicional[n_condicional] && ejecutar[n_condicional])){

                                                                              if(esBucle){
                                                                                    (*table).add(new Row(tc, TIPO_ROW::T_FRASE));
                                                                                    debug << ">>> Añadido mensaje de personaje " << " [" << (yyvsp[-5].c_identificador) << "] "  << " en linea " << n_lineas << " dice : " << (yyvsp[-1].c_cadena) << " a la table " << table << endl;
                                                                              }
                                                                              else
                                                                                    salida << "espeak -v " << tc << endl;
                                                                        }

                                                                        errorSemantico = false;
                                                                        errorVariable = false;
                                                                  }else{
                                                                        cout << "***** Error semantico, el personaje " << (yyvsp[-5].c_identificador) << " no esta definido" << endl;
                                                                  }

                                                               }
#line 1650 "expresiones.c"
    break;

  case 38: /* lineaEscena: ID_NOMBRE '[' entonacion ']' ':' expr_cadena salto  */
#line 402 "expresiones.y"
                                                               { 
                                                                  debug << "-------- personaje " << " [" << (yyvsp[-6].c_identificador) << "] " << " en linea " << n_lineas << " dice : " << (yyvsp[-1].c_cadena) << " con entonación " << (yyvsp[-4].c_cadena) << endl; 
                                                                  

                                                                  if(chs.isExists((yyvsp[-6].c_identificador))){
                                                                        chs.get((yyvsp[-6].c_identificador), ch);
                                                                        str = ch.languaje + "+";
                                                                        str += ch.gender;
                                                                        str += to_string(ch.numCharacter) + " ";
                                                                        strcpy(tc, str.c_str());
                                                                        strcat(tc, (yyvsp[-4].c_cadena));
                                                                        strcat(tc, (yyvsp[-1].c_cadena));

                                                                        if(!errorSemantico && !errorVariable && !errorEscena && !errorBucle && !errorCondicional && (!esCondicional[n_condicional] || esCondicional[n_condicional] && ejecutar[n_condicional])){

                                                                           if(esBucle){
                                                                              (*table).add(new Row(tc, TIPO_ROW::T_FRASE));
                                                                               debug << ">>> Añadido mensaje de personaje " << " [" << (yyvsp[-6].c_identificador) << "] " << " en linea " << n_lineas << " dice : " << (yyvsp[-1].c_cadena) << " con entonación " << (yyvsp[-4].c_cadena) << " a la table " << table << endl;
                                                                           }
                                                                           else
                                                                              salida << "espeak -v " << tc << endl;  
                                                                        }

                                                                        errorSemantico = false;
                                                                        errorVariable = false;
                                                                  }else{
                                                                        cout << "***** Error semantico, el personaje " << (yyvsp[-6].c_identificador) << " no esta definido" << endl;
                                                                  }

                                                               }
#line 1685 "expresiones.c"
    break;

  case 39: /* lineaEscena: MENSAJE expr_cadena salto  */
#line 433 "expresiones.y"
                                                               { 

                                                                  strcpy(tc, (yyvsp[-1].c_cadena));
                                                                  debug << "-------- mensaje " << (yyvsp[-1].c_cadena) << endl; 
                                                            
                                                                  if(!errorSemantico && !errorVariable && !errorEscena && !errorBucle && !errorCondicional && (!esCondicional[n_condicional] || esCondicional[n_condicional] && ejecutar[n_condicional])){

                                                                     if(esBucle){
                                                                        (*table).add(new Row(tc, TIPO_ROW::T_MENSAJE)); 
                                                                        debug << ">>> Añadido mensaje " << (yyvsp[-1].c_cadena) << " a la table " << table << endl;
                                                                     } 
                                                                     else
                                                                        salida << "echo " << tc << endl;
                                                                  }
                                                                  

                                                                  errorSemantico = false;
                                                                  errorVariable = false;

                                                               }
#line 1710 "expresiones.c"
    break;

  case 40: /* lineaEscena: PAUSA expr_arit salto  */
#line 454 "expresiones.y"
                                                               { 
                                                                  debug << "-------- pausa " << (yyvsp[-1].c_expresion_arit).valor << endl; 
                                                                  
                                                                  if(!errorSemantico && !errorVariable && !errorEscena && !errorBucle && !errorCondicional && (!esCondicional[n_condicional] || esCondicional[n_condicional] && ejecutar[n_condicional])){
                                                                        
                                                                        if(esBucle){
                                                                              (*table).add(new Row((yyvsp[-1].c_expresion_arit).valor, TIPO_ROW::T_PAUSA)); 
                                                                              debug << ">>> Añadido pausa " << (yyvsp[-1].c_expresion_arit).valor << " a la table " << table << endl;
                                                                        }
                                                                        else
                                                                              salida << "sleep " << (yyvsp[-1].c_expresion_arit).valor << endl;
                                                                  }

                                                                  errorSemantico = false;
                                                                  errorVariable = false;
                                                                  
                                                               }
#line 1732 "expresiones.c"
    break;

  case 41: /* $@5: %empty  */
#line 478 "expresiones.y"
                                    {

                                          if(!errorBucle){
                                          
                                                if(!(yyvsp[-2].c_expresion_arit).esReal){
                                                      
                                                      debug << ">>> nuevo bucle" << endl; 

                                                      if(esBucle){ 
                                                            debug << "añadimos referencia a tabla" << endl;    
                                                            father = table;
                                                            debug << ">>> cambiamos padre" << endl;        
                                                            debug << ">>> table " << "( " <<  table << " )" << " && father " << "( " << father <<  " )" << endl;
                                                      }
                                                      esBucle = true; 
                                                      ls.add(table, (yyvsp[-2].c_expresion_arit).valor); 
                                                      if(father != NULL) (*father).add(new Row(table, TIPO_ROW::T_BUCLE));
                                                      table->setFather(father);
                                                      debug << ">>> table " << "( " <<  table << " )" << " && father " << "( " << father <<  " )" <<  endl;

                                                      debug << "+++ repetir " << (yyvsp[-2].c_expresion_arit).valor << endl; 
                                                
                                                }
                                                else{
                                                      cout << "***** Error semantico en la linea " << n_lineas << ", el número de repeticiones debe ser de tipo ENTERO" << endl;
                                                      errorSemantico = true;
                                                      errorBucle = true;
                                                }

                                          }


      }
#line 1770 "expresiones.c"
    break;

  case 42: /* bucle: REPETIR expr_arit '{' salto $@5 secBloqueEscena '}' salto  */
#line 510 "expresiones.y"
                                    {

                                    if(!errorBucle){

                                          if(!(yyvsp[-6].c_expresion_arit).esReal){
                                                debug << "+++ fin repetir " << (yyvsp[-6].c_expresion_arit).valor << endl;
                                                
                                                if(father == NULL){
                                                      table->run(salida); // ejecutamos el bucle padre del bloque de bucles
                                                      ls.clear(); // limpiamos la estructura de bucles
                                                      esBucle = false;  // cuando llegemos al padre de todos los bucles anidados acabamos el bloque de bucles 
                                                      
                                                }
                                                table->getFather(table);
                                                debug << ">>> obtenemos padre table " << "(" << table << ")" << endl;
                                                if(table != NULL){
                                                      table->getFather(father);
                                                      debug << ">>> obtenemos padre de padre de table " "(" << father <<  ")" << endl;
                                                }

                                          }

                                    }

                              }
#line 1800 "expresiones.c"
    break;

  case 44: /* $@6: %empty  */
#line 542 "expresiones.y"
                                                  { 

                                                if(!errorCondicional){
                                                      if(esCondicional[n_condicional]) n_condicional++; 
                                                      esCondicional[n_condicional] = true; 
                                                      ejecutar[n_condicional]=(yyvsp[-4].c_bool); 
                                                      debug << ">>> entramos en bloque si del condicional (n_condicional = " << n_condicional << ") && esCondicional[" << n_condicional << "] = " << esCondicional[n_condicional] << " && ejecutar[" << n_condicional <<  "] = " << ejecutar[n_condicional] << endl;
                                                      debug << "+++ inicio bloque si ( condicion=" << (yyvsp[-4].c_bool) <<  ")" << endl;
                                                }
                                               
                                          }
#line 1816 "expresiones.c"
    break;

  case 45: /* parteSi: SI '(' expr_log ')' salto_opc '{' salto $@6 secBloqueEscena '}' salto  */
#line 552 "expresiones.y"
                                                                       {

                                                if(!errorCondicional){

                                                      debug << "+++ fin bloque si ( condicion=" << (yyvsp[-8].c_bool) <<  ")" << endl;
                                                      debug << ">>> salimos en bloque si del condicional (n_condicional = " << n_condicional << ") && esCondicional[" << n_condicional << "] = " << esCondicional[n_condicional] << " && ejecutar[" << n_condicional <<  "] = " << ejecutar[n_condicional] << endl;
                                                }
                                          }
#line 1829 "expresiones.c"
    break;

  case 47: /* $@7: %empty  */
#line 564 "expresiones.y"
                                   {

                        if(!errorCondicional){

                              ejecutar[n_condicional] = !ejecutar[n_condicional]; 
                              debug << ">>> entramos en bloque si_no del condicional (n_condicional = " << n_condicional << ") && esCondicional[" << n_condicional << "] = " << esCondicional[n_condicional] << " && !ejecutar[" << n_condicional <<  "] = " << ejecutar[n_condicional] << endl;
                              debug << "+++ inicio bloque sino " << endl;
                        } 

                  }
#line 1844 "expresiones.c"
    break;

  case 48: /* parteSiNo: SI_NO salto_opc '{' salto $@7 secBloqueEscena '}' salto  */
#line 573 "expresiones.y"
                                              {

                        if(!errorCondicional){
                              debug << "+++ fin bloque sino " << endl;
                              esCondicional[n_condicional] = false; 
                              debug << ">>> salimos en bloque si_no del condicional (n_condicional = " << n_condicional << ") && esCondicional[" << n_condicional << "] = " << esCondicional[n_condicional] << " && !ejecutar[" << n_condicional <<  "] = " << ejecutar[n_condicional] << endl;
                              if(n_condicional > 0) n_condicional--; 
                        }

                        errorCondicional = false;
                  }
#line 1860 "expresiones.c"
    break;

  case 49: /* entonacion: TONO  */
#line 588 "expresiones.y"
                                    {strcpy((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1866 "expresiones.c"
    break;

  case 50: /* entonacion: entonacion ',' TONO  */
#line 589 "expresiones.y"
                                    {strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1872 "expresiones.c"
    break;

  case 51: /* expr_cadena: CADENA  */
#line 594 "expresiones.y"
                                               {strcpy((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1878 "expresiones.c"
    break;

  case 52: /* expr_cadena: ID_CADENA  */
#line 595 "expresiones.y"
                                               {
                                                if(ids.isExists((yyvsp[0].c_identificador))){
                                                      if(ids.getTipo((yyvsp[0].c_identificador)) == TIPO_IDENT::T_CADENA){
                                                            ids.get((yyvsp[0].c_identificador), ident);
                                                            strcpy((yyval.c_cadena), ident.valor.valor_cadena);
                                                      }
                                                      else{ 
                                                            cout << "***** Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[0].c_identificador) << " no es de tipo CADENA" << endl;            
                                                            errorSemantico = true;
                                                      }
                                                } 
                                                else{
                                                      cout << "***** Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[0].c_identificador) << " no esta definida" << endl;
                                                      errorVariable = true;
                                                      
                                                }
                                               }
#line 1900 "expresiones.c"
    break;

  case 53: /* expr_cadena: expr_arit  */
#line 613 "expresiones.y"
                                               {

                                                      string str = to_string((yyvsp[0].c_expresion_arit).valor);

                                                      if((yyvsp[0].c_expresion_arit).esReal)
                                                            str = str.substr(0, str.find(".")+2);
                                                      else
                                                            str = str.substr(0, str.find("."));

                                                      str = '"' + str  + '"';

                                                      strcpy((yyval.c_cadena), str.c_str());  

                                               }
#line 1919 "expresiones.c"
    break;

  case 54: /* expr_cadena: expr_cadena CONCATENACION expr_cadena  */
#line 628 "expresiones.y"
                                               {debug << "-------- concatenacion cadena (" << (yyvsp[-2].c_cadena) << ") cadena(" << (yyvsp[0].c_cadena) <<  ")" << endl; 
                                               
                                                if(!errorVariable){
                                                      string str1((yyvsp[-2].c_cadena));  
                                                      string str2((yyvsp[0].c_cadena));  

                                                      str1 = str1.replace(0, 1, "");
                                                      str1 = str1.replace(str1.length()-1, 1, "");

                                                      str2 = str2.replace(0, 1, "");
                                                      str2 = str2.replace(str2.length()-1, 1, "");

                                                      str1 = '"' + str1 + str2 + '"';
                                                      strcpy((yyval.c_cadena), str1.c_str());
                                                }else{
                                                      cout << "***** Error en la linea " << n_lineas << ", no se ha podido producir la operacion de la concatenacion, no se ha podido obtener el valor de la variable" << endl;
                                                      errorVariable = true;
                                                
                                                }
                                               
                                             }
#line 1945 "expresiones.c"
    break;

  case 55: /* expr_log: TRUE  */
#line 651 "expresiones.y"
                                              {(yyval.c_bool) = true; }
#line 1951 "expresiones.c"
    break;

  case 56: /* expr_log: FALSE  */
#line 652 "expresiones.y"
                                              {(yyval.c_bool) = false; }
#line 1957 "expresiones.c"
    break;

  case 57: /* expr_log: expr_log AND expr_log  */
#line 653 "expresiones.y"
                                              {(yyval.c_bool) = (yyvsp[-2].c_bool) and (yyvsp[0].c_bool); }
#line 1963 "expresiones.c"
    break;

  case 58: /* expr_log: expr_log OR expr_log  */
#line 654 "expresiones.y"
                                              {(yyval.c_bool) = (yyvsp[-2].c_bool) or (yyvsp[0].c_bool); }
#line 1969 "expresiones.c"
    break;

  case 59: /* expr_log: NOT expr_log  */
#line 655 "expresiones.y"
                                              {(yyval.c_bool) = (not (yyvsp[0].c_bool)); }
#line 1975 "expresiones.c"
    break;

  case 60: /* expr_log: '(' expr_log ')'  */
#line 656 "expresiones.y"
                                                  {(yyval.c_bool) =     (yyvsp[-1].c_bool); }
#line 1981 "expresiones.c"
    break;

  case 61: /* expr_log: expr_arit '>' expr_arit  */
#line 657 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor > (yyvsp[0].c_expresion_arit).valor)  ? true : false; }
#line 1987 "expresiones.c"
    break;

  case 62: /* expr_log: expr_arit MAYORIGUAL expr_arit  */
#line 658 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor >= (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1993 "expresiones.c"
    break;

  case 63: /* expr_log: expr_arit '<' expr_arit  */
#line 659 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor < (yyvsp[0].c_expresion_arit).valor)  ? true : false; }
#line 1999 "expresiones.c"
    break;

  case 64: /* expr_log: expr_arit MENORIGUAL expr_arit  */
#line 660 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor <= (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 2005 "expresiones.c"
    break;

  case 65: /* expr_log: expr_arit IGUAL2 expr_arit  */
#line 661 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor == (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 2011 "expresiones.c"
    break;

  case 66: /* expr_log: expr_arit DISTINTO expr_arit  */
#line 662 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor != (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 2017 "expresiones.c"
    break;

  case 67: /* expr_log: expr_log IGUAL2 expr_log  */
#line 663 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_bool) == (yyvsp[0].c_bool)) ? true : false; }
#line 2023 "expresiones.c"
    break;

  case 68: /* expr_log: expr_log DISTINTO expr_log  */
#line 664 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_bool) != (yyvsp[0].c_bool)) ? true : false; }
#line 2029 "expresiones.c"
    break;

  case 69: /* expr_arit: NUMERO  */
#line 667 "expresiones.y"
                                                        {(yyval.c_expresion_arit).esReal = false; (yyval.c_expresion_arit).valor = (yyvsp[0].c_entero); }
#line 2035 "expresiones.c"
    break;

  case 70: /* expr_arit: REAL  */
#line 668 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = true;  (yyval.c_expresion_arit).valor = (yyvsp[0].c_real); }
#line 2041 "expresiones.c"
    break;

  case 71: /* expr_arit: ID_GENERAL  */
#line 669 "expresiones.y"
                                              {
                                                if(ids.isExists((yyvsp[0].c_identificador))){
                                                      if(ids.getTipo((yyvsp[0].c_identificador)) == TIPO_IDENT::T_ENT){
                                                            (yyval.c_expresion_arit).esReal = false;
                                                            ids.get((yyvsp[0].c_identificador), ident);
                                                            (yyval.c_expresion_arit).valor = ident.valor.valor_entero;
                                                      }
                                                      else if(ids.getTipo((yyvsp[0].c_identificador)) == TIPO_IDENT::T_REAL){
                                                            (yyval.c_expresion_arit).esReal = true;
                                                            ids.get((yyvsp[0].c_identificador), ident);
                                                            (yyval.c_expresion_arit).valor = ident.valor.valor_real;
                                                      }
                                                      else{ 
                                                            cout << "***** Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[0].c_identificador) << " no es de tipo ENTERA o REAL" << endl;            
                                                            errorSemantico = true;
                                                      }
                                                } 
                                                else{
                                                      cout << "***** Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[0].c_identificador) << " no esta definida" << endl;
                                                      errorVariable = true;
                                                      
                                                }
                                              }
#line 2069 "expresiones.c"
    break;

  case 72: /* expr_arit: expr_arit '+' expr_arit  */
#line 692 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor + (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) + int((yyvsp[0].c_expresion_arit).valor); }
#line 2075 "expresiones.c"
    break;

  case 73: /* expr_arit: expr_arit '-' expr_arit  */
#line 693 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor - (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) - int((yyvsp[0].c_expresion_arit).valor); }
#line 2081 "expresiones.c"
    break;

  case 74: /* expr_arit: expr_arit '*' expr_arit  */
#line 694 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor * (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) * int((yyvsp[0].c_expresion_arit).valor); }
#line 2087 "expresiones.c"
    break;

  case 75: /* expr_arit: expr_arit '/' expr_arit  */
#line 696 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = true; 
                                                if((yyvsp[0].c_expresion_arit).valor == 0){ 
                                                      errorSemantico = true; 
                                                      cout << "***** Error semantico en la linea " << n_lineas << ", se ha detectado una división entre el número 0" << endl;
                                                } 
                                                else 
                                                      (yyval.c_expresion_arit).valor = (yyvsp[-2].c_expresion_arit).valor / (yyvsp[0].c_expresion_arit).valor;
                                              }
#line 2100 "expresiones.c"
    break;

  case 76: /* expr_arit: expr_arit DIV expr_arit  */
#line 705 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; 
                                                if((yyvsp[0].c_expresion_arit).valor == 0){ 
                                                      errorSemantico = true;
                                                      cout << "***** Error semantico en la linea " << n_lineas << ", se ha detectado una divisón entre el número 0" << endl;
                                                }else {
                                                      if((yyval.c_expresion_arit).esReal){ 
                                                            errorSemantico = true; 
                                                           cout << "***** Error semantico en la linea " << n_lineas << ", el operador div no se puede usar con datos de tipo real " << endl;
                                                      } 
                                                      else 
                                                            (yyval.c_expresion_arit).valor = int((yyvsp[-2].c_expresion_arit).valor) / int((yyvsp[0].c_expresion_arit).valor);
                                                }
                                               }
#line 2118 "expresiones.c"
    break;

  case 77: /* expr_arit: '-' expr_arit  */
#line 719 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[0].c_expresion_arit).esReal ; (yyval.c_expresion_arit).valor = ((yyvsp[0].c_expresion_arit).esReal) ? -(yyvsp[0].c_expresion_arit).valor : int(-(yyvsp[0].c_expresion_arit).valor); }
#line 2124 "expresiones.c"
    break;

  case 78: /* expr_arit: '(' expr_arit ')'  */
#line 720 "expresiones.y"
                                                  {(yyval.c_expresion_arit).esReal = (yyvsp[-1].c_expresion_arit).esReal ; (yyval.c_expresion_arit).valor = ((yyvsp[-1].c_expresion_arit).esReal) ?  (yyvsp[-1].c_expresion_arit).valor : int( (yyvsp[-1].c_expresion_arit).valor); }
#line 2130 "expresiones.c"
    break;


#line 2134 "expresiones.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 722 "expresiones.y"


int main(int argc, char *argv[]){
     
      if(argc >= 2){
            if(strlen(argv[1]) > 5){

                  string outfile, outfileExtension, outfileName, debugOp;
                  bool debugOpcion = false;

                  outfile = argv[1];
                  outfileExtension = outfile.substr(outfile.length()-3, outfile.length());
                  outfileName = outfile.substr(0, outfile.length()-4);

                  if(argc >= 3){
                        debugOp = argv[2];
                        debugOpcion = debugOp.compare("-d") == 0;
                  }

                  if(outfileExtension.compare("dia") != 0){
                        cout << argv[1] << ": La extensión del archivo de entrada no es el correcto " << endl;
                        return -1;
                  }else{
                        n_lineas = 1;  
                        n_escena = 0; 
                        n_condicional = 0;

                        esBucle = false;
                        errorVariable = false;
                        errorEscena = false;
                        errorBucle = false;
                        errorCondicional = false;
                        errorSemantico = false; 
                        ejecutar[n_condicional] = false;
                        esCondicional[n_condicional] = false;

                        table = NULL;
                        father = NULL;
                        
                        yyin = fopen(argv[1], "rt");
                        salida.open(outfileName + ".sh");
                        if(debugOpcion) debug.open(outfileName + ".debug");
                  
                        yyparse(); //llamada al analizador semantico
                  
                        salida.close();

                        ids.printIdentifiers(debug); // mostramos los identificadores declarados
                        chs.printCharacters(debug);  // mostramos los personajes declarados


                        if(debugOpcion) debug.close();

                       
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
