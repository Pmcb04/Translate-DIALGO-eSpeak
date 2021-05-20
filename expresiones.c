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


#line 131 "expresiones.c"

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
  YYSYMBOL_62_3 = 62,                      /* $@3  */
  YYSYMBOL_63_4 = 63,                      /* $@4  */
  YYSYMBOL_identificadorCadena = 64,       /* identificadorCadena  */
  YYSYMBOL_65_5 = 65,                      /* $@5  */
  YYSYMBOL_secEscena = 66,                 /* secEscena  */
  YYSYMBOL_escena = 67,                    /* escena  */
  YYSYMBOL_68_6 = 68,                      /* $@6  */
  YYSYMBOL_69_7 = 69,                      /* $@7  */
  YYSYMBOL_secBloqueEscena = 70,           /* secBloqueEscena  */
  YYSYMBOL_bloqueEscena = 71,              /* bloqueEscena  */
  YYSYMBOL_72_8 = 72,                      /* $@8  */
  YYSYMBOL_73_9 = 73,                      /* $@9  */
  YYSYMBOL_74_10 = 74,                     /* $@10  */
  YYSYMBOL_75_11 = 75,                     /* $@11  */
  YYSYMBOL_76_12 = 76,                     /* $@12  */
  YYSYMBOL_bucle = 77,                     /* bucle  */
  YYSYMBOL_78_13 = 78,                     /* $@13  */
  YYSYMBOL_condicional = 79,               /* condicional  */
  YYSYMBOL_parteSi = 80,                   /* parteSi  */
  YYSYMBOL_81_14 = 81,                     /* $@14  */
  YYSYMBOL_parteSiNo = 82,                 /* parteSiNo  */
  YYSYMBOL_83_15 = 83,                     /* $@15  */
  YYSYMBOL_entonacion = 84,                /* entonacion  */
  YYSYMBOL_expr_cadena = 85,               /* expr_cadena  */
  YYSYMBOL_expr_log = 86,                  /* expr_log  */
  YYSYMBOL_expr_arit = 87                  /* expr_arit  */
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
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
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
       0,   120,   120,   121,   124,   125,   129,   134,   134,   137,
     138,   141,   146,   147,   147,   150,   151,   154,   155,   158,
     158,   204,   204,   240,   240,   277,   278,   281,   294,   281,
     297,   298,   301,   301,   319,   319,   336,   336,   358,   358,
     369,   369,   379,   381,   383,   386,   386,   388,   391,   391,
     394,   395,   395,   400,   401,   406,   407,   408,   409,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   439,   440,   441,   464,   465,   466,   468,
     477,   491,   492
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
  "$@3", "$@4", "identificadorCadena", "$@5", "secEscena", "escena", "$@6",
  "$@7", "secBloqueEscena", "bloqueEscena", "$@8", "$@9", "$@10", "$@11",
  "$@12", "bucle", "$@13", "condicional", "parteSi", "$@14", "parteSiNo",
  "$@15", "entonacion", "expr_cadena", "expr_log", "expr_arit", YY_NULLPTR
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

#define YYPACT_NINF (-89)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -89,     0,    14,   -89,   -89,    -6,   -89,    -2,   -89,    40,
     -89,    -4,    -2,     3,    40,   -89,    11,   -89,    20,   -89,
       2,   -89,   -89,   -89,     3,     3,   133,   -89,    30,   -89,
      82,   101,    81,   -89,   -89,   -89,   -89,    24,     3,     3,
       3,     3,     3,   -89,    45,     9,    71,   -89,   -89,   -89,
      -3,    -3,   -89,   -89,    -2,    84,     9,   -89,   -89,     9,
     165,   151,   -89,   -89,   115,    78,   210,   120,   -89,   151,
     144,    96,     9,     9,     9,     9,    -2,     3,     3,     3,
       3,     3,     3,    -2,    71,    -2,    34,     3,    71,   107,
       3,   -89,   224,   -89,   -89,   -89,   131,   140,   -89,    90,
      85,   -89,   -89,   127,    78,    78,    78,    78,    78,    78,
     127,   -89,   127,    71,    10,    78,   115,     9,   100,   -89,
     -89,   129,   -89,    -2,   115,   -89,   134,    52,    -2,    -2,
     146,    -2,    -2,    -2,   127,    -2,    71,   154,   135,   127,
     127,   -89,   127,   127,   127,   127,   115,   -89,    71,   -36,
     237,   237,    -2,   115,    -2,   176,   181,   127,    -2,   127,
      -2,    -2,   127,   237,   127,   127,   194,    -2,   127
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     7,     5,    12,     1,     0,    13,     0,
       2,     0,     0,     0,     6,    25,     0,     3,     8,     9,
       0,    73,    74,    75,     0,     0,     0,    26,     0,    10,
       0,     0,    14,    15,    18,    17,    81,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,    16,    82,    80,
      76,    77,    78,    79,     0,     0,     0,    59,    60,     0,
      21,    19,    56,    55,    23,    57,     0,     0,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,    30,    44,    43,    50,     0,    64,    61,
      62,    71,    72,    22,    66,    68,    69,    70,    67,    65,
      20,    58,    24,     0,     0,    40,    38,     0,     0,    28,
      31,     0,    47,     0,    32,    53,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,    41,
      39,     4,    45,    29,    51,    33,    34,    54,     0,     0,
       0,     0,     0,    36,     0,     0,     0,    35,     0,    48,
       0,     0,    37,     0,    46,    52,     0,     0,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,   -12,    41,   -89,   -89,   -89,   -89,   163,   -89,   -89,
     -89,    23,   -89,   -89,   -89,   -89,   -89,   -89,   175,   -89,
     -89,   -24,   -88,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -83,   -48,     7
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    11,     1,     2,     5,     7,    18,    19,     9,    12,
      32,    91,    34,    83,    76,    35,    85,    14,    15,    54,
     132,    92,    93,   135,   152,   158,   129,   128,    94,   150,
      95,    96,   163,   122,   151,   127,    64,    60,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,   111,    38,     4,   120,   116,    21,    22,    68,   154,
       8,    70,    21,    22,     6,     3,    16,    56,    57,    58,
      26,    30,    23,    31,    99,   100,   101,   102,    23,    38,
     124,    36,    37,    41,    42,    17,   125,    10,    24,     4,
      16,    17,    66,    33,    24,    49,    50,    51,    52,    53,
      25,    28,    61,   146,   126,    47,    59,    13,    39,    40,
      41,    42,    44,    69,   103,   153,    71,   120,   120,   130,
      55,   110,    48,   112,    21,    22,   113,   114,   120,    69,
      69,    69,    69,    38,   104,   105,   106,   107,   108,   109,
      23,    72,    62,   137,   115,    63,   138,   118,    74,    75,
      30,    38,    31,    74,    75,    38,    24,    77,    78,    79,
      80,   134,    39,    40,    41,    42,   139,   140,    25,   142,
     143,   144,    45,   145,    69,    67,   155,   156,    81,    82,
      39,    40,    41,    42,    39,    40,    41,    42,    38,   166,
     157,    46,   159,    84,    48,   131,   162,    97,   164,   165,
      72,    73,    72,    73,   117,   168,    38,    74,    75,    74,
      75,   121,    77,    78,    79,    80,    17,    39,    40,    41,
      42,    72,    73,   123,   133,    43,   136,   148,    74,    75,
     147,    29,   149,    81,    82,    39,    40,    41,    42,    27,
       0,     0,    98,     0,   141,    30,    86,    31,    87,    88,
      30,    86,    31,    87,    88,    89,     0,    90,     0,     0,
      89,     0,    90,    30,    86,    31,    87,    88,     0,     0,
       0,     0,   160,    89,     0,    90,     0,   161,     0,    30,
      86,    31,    87,    88,     0,     0,     0,     0,     0,    89,
     167,    90,   119,    30,    86,    31,    87,    88,     0,    17,
       0,     0,     0,    89,     0,    90,    30,    86,    31,    87,
      88,     0,     0,     0,     0,     0,    89,     0,    90
};

static const yytype_int16 yycheck[] =
{
      12,    84,     5,    39,    92,    88,     3,     4,    56,    45,
      16,    59,     3,     4,     0,    15,    20,     8,     9,    10,
      13,    19,    19,    21,    72,    73,    74,    75,    19,     5,
     113,    24,    25,    36,    37,    39,    26,    39,    35,    39,
      20,    39,    54,    20,    35,    38,    39,    40,    41,    42,
      47,    40,    45,   136,    44,    32,    47,    17,    34,    35,
      36,    37,    32,    56,    76,   148,    59,   155,   156,   117,
      25,    83,    48,    85,     3,     4,    42,    43,   166,    72,
      73,    74,    75,     5,    77,    78,    79,    80,    81,    82,
      19,     6,    21,    41,    87,    24,    44,    90,    13,    14,
      19,     5,    21,    13,    14,     5,    35,    11,    12,    13,
      14,   123,    34,    35,    36,    37,   128,   129,    47,   131,
     132,   133,    40,   135,   117,    41,   150,   151,    32,    33,
      34,    35,    36,    37,    34,    35,    36,    37,     5,   163,
     152,    40,   154,    28,    48,    45,   158,    27,   160,   161,
       6,     7,     6,     7,    47,   167,     5,    13,    14,    13,
      14,    30,    11,    12,    13,    14,    39,    34,    35,    36,
      37,     6,     7,    33,    45,    42,    42,    42,    13,    14,
      26,    18,   141,    32,    33,    34,    35,    36,    37,    14,
      -1,    -1,    48,    -1,    48,    19,    20,    21,    22,    23,
      19,    20,    21,    22,    23,    29,    -1,    31,    -1,    -1,
      29,    -1,    31,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    46,    29,    -1,    31,    -1,    46,    -1,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    29,
      46,    31,    18,    19,    20,    21,    22,    23,    -1,    39,
      -1,    -1,    -1,    29,    -1,    31,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    52,    15,    39,    53,     0,    54,    16,    57,
      39,    50,    58,    17,    66,    67,    20,    39,    55,    56,
      50,     3,     4,    19,    35,    47,    87,    67,    40,    56,
      19,    21,    59,    60,    61,    64,    87,    87,     5,    34,
      35,    36,    37,    42,    32,    40,    40,    60,    48,    87,
      87,    87,    87,    87,    68,    25,     8,     9,    10,    47,
      86,    87,    21,    24,    85,    87,    50,    41,    86,    87,
      86,    87,     6,     7,    13,    14,    63,    11,    12,    13,
      14,    32,    33,    62,    28,    65,    20,    22,    23,    29,
      31,    60,    70,    71,    77,    79,    80,    27,    48,    86,
      86,    86,    86,    50,    87,    87,    87,    87,    87,    87,
      50,    85,    50,    42,    43,    87,    85,    47,    87,    18,
      71,    30,    82,    33,    85,    26,    44,    84,    76,    75,
      86,    45,    69,    45,    50,    72,    42,    41,    44,    50,
      50,    48,    50,    50,    50,    50,    85,    26,    42,    51,
      78,    83,    73,    85,    45,    70,    70,    50,    74,    50,
      46,    46,    50,    81,    50,    50,    70,    46,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    54,    53,    55,
      55,    56,    57,    58,    57,    59,    59,    60,    60,    62,
      61,    63,    61,    65,    64,    66,    66,    68,    69,    67,
      70,    70,    72,    71,    73,    71,    74,    71,    75,    71,
      76,    71,    71,    71,    71,    78,    77,    79,    81,    80,
      82,    83,    82,    84,    84,    85,    85,    85,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     4,     0,     4,     1,
       2,     8,     0,     0,     4,     1,     2,     1,     1,     0,
       5,     0,     5,     0,     5,     1,     2,     0,     0,     9,
       1,     2,     0,     5,     0,     7,     0,     8,     0,     4,
       0,     4,     1,     1,     1,     0,     8,     2,     0,    11,
       0,     0,     7,     1,     3,     1,     1,     1,     3,     1,
       1,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     3,     3,     3,     3,
       3,     2,     3
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
#line 120 "expresiones.y"
                     {n_lineas++;}
#line 1347 "expresiones.c"
    break;

  case 3: /* salto: salto '\n'  */
#line 121 "expresiones.y"
                     {n_lineas++;}
#line 1353 "expresiones.c"
    break;

  case 5: /* salto_opc: salto_opc '\n'  */
#line 125 "expresiones.y"
                        {n_lineas++;}
#line 1359 "expresiones.c"
    break;

  case 7: /* $@1: %empty  */
#line 134 "expresiones.y"
                             {cout << "+++ bloque personajes linea " << n_lineas << endl;}
#line 1365 "expresiones.c"
    break;

  case 11: /* asignacionPersonaje: ID_NOMBRE '=' '<' IDIOMA ',' VOZ '>' salto  */
#line 141 "expresiones.y"
                                                                { cout << "-------- asignacion nombre " << (yyvsp[-7].c_identificador) << "," << (yyvsp[-4].c_cadena) << "," << (yyvsp[-2].c_cadena) <<  " linea " << n_lineas << endl; chs.add(Character((yyvsp[-7].c_identificador), n_lineas, (yyvsp[-4].c_cadena), (yyvsp[-2].c_cadena)));}
#line 1371 "expresiones.c"
    break;

  case 13: /* $@2: %empty  */
#line 147 "expresiones.y"
                     {cout << "+++ bloque definiciones linea " << n_lineas << endl;}
#line 1377 "expresiones.c"
    break;

  case 19: /* $@3: %empty  */
#line 158 "expresiones.y"
                                                  {
                                          if(!errorVariable && !errorSemantico){
                                                if(!ids.isExists((yyvsp[-2].c_identificador)))
                                                      if((yyvsp[0].c_expresion_arit).esReal){
                                                            ids.add(Identifier((yyvsp[-2].c_identificador), n_lineas, (yyvsp[0].c_expresion_arit).valor));
                                                            cout << "-------- asignacion id_general real " << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_expresion_arit).valor << endl;     
                                                      } else{
                                                            ids.add(Identifier((yyvsp[-2].c_identificador), n_lineas, (int)(yyvsp[0].c_expresion_arit).valor)); 
                                                            cout << "-------- asignacion id_general entero " << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_expresion_arit).valor << endl;     
                                                      } 
                                                            
                                                else if((yyvsp[0].c_expresion_arit).esReal && ids.getTipo((yyvsp[-2].c_identificador)) == TIPO_IDENT::T_REAL){
                                                      ids.setValor((yyvsp[-2].c_identificador), (yyvsp[0].c_expresion_arit).valor);
                                                      cout << "-------- actualizacion valor asignacion id_general real" << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_expresion_arit).valor << endl;     
                                                }
                                                
                                                else if(!(yyvsp[0].c_expresion_arit).esReal && ids.getTipo((yyvsp[-2].c_identificador)) == TIPO_IDENT::T_ENT){
                                                      ids.setValor((yyvsp[-2].c_identificador), (int)(yyvsp[0].c_expresion_arit).valor);                                          
                                                      cout << "-------- actualizacion valor asignacion id_general entero" << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_expresion_arit).valor << endl;     
                                                }
                                                else{

                                                      cout << "********** Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[-2].c_identificador) << " es de tipo ";
                                                      
                                                      tipo_ident = ids.getTipo((yyvsp[-2].c_identificador)); // averiguamos el tipo de $1, es decir de la variable

                                                      switch (tipo_ident) {
                                                      case T_ENT: cout << "entero "; break;
                                                      case T_REAL: cout << "real "; break;
                                                      case T_BOOL: cout << "bool "; break;
                                                      case T_CADENA: cout << "cadena "; break;
                                                      default: cout << "undefined "; break;
                                                      }

                                                      cout << "y no se le puede asignar un valor ";

                                                      if((yyvsp[0].c_expresion_arit).esReal) cout << "real" << endl;
                                                      else cout << "entero" << endl;
                                                }
                                          }

                                          errorSemantico = false;
                                          errorVariable = false;

                                  }
#line 1427 "expresiones.c"
    break;

  case 21: /* $@4: %empty  */
#line 204 "expresiones.y"
                                     {
                                   
                                          if(!errorVariable && !errorSemantico){
                                                if(!ids.isExists((yyvsp[-2].c_identificador))){
                                                      ids.add(Identifier((yyvsp[-2].c_identificador), n_lineas, (yyvsp[0].c_bool)));
                                                      cout << "-------- asignacion id_general logico" << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_bool) << endl;     
                                                }
                                                else if(ids.getTipo((yyvsp[-2].c_identificador)) == TIPO_IDENT::T_BOOL){
                                                      ids.setValor((yyvsp[-2].c_identificador), (yyvsp[0].c_bool));
                                                      cout << "-------- actualizacion valor asignacion id_general logico" << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_bool) << endl;     
                                                }
                                                else{

                                                      cout << "********** Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[-2].c_identificador) << " es de tipo ";
                                                      
                                                      tipo_ident = ids.getTipo((yyvsp[-2].c_identificador)); // averiguamos el tipo de $1, es decir de la variable

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
#line 1465 "expresiones.c"
    break;

  case 23: /* $@5: %empty  */
#line 240 "expresiones.y"
                                                {
            
                                          if(!errorVariable && !errorSemantico){
                                                if(!ids.isExists((yyvsp[-2].c_identificador))){
                                                      ids.add(Identifier((yyvsp[-2].c_identificador), n_lineas, (yyvsp[0].c_cadena)));
                                                      cout << "-------- asignacion id_cadena " << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_cadena) << endl;     
                                                }
                                                else if(ids.getTipo((yyvsp[-2].c_identificador)) == TIPO_IDENT::T_CADENA){
                                                      ids.setValor((yyvsp[-2].c_identificador), (yyvsp[0].c_cadena));
                                                      cout << "-------- actualizacion valor asignacion id_cadena " << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_cadena) << endl;     
                                                }
                                                else{

                                                      cout << "********** Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[-2].c_identificador) << " es de tipo ";
                                                      
                                                      tipo_ident = ids.getTipo((yyvsp[-2].c_identificador)); // averiguamos el tipo de $1, es decir de la variable

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
#line 1503 "expresiones.c"
    break;

  case 27: /* $@6: %empty  */
#line 281 "expresiones.y"
                            {
                                    if(!(yyvsp[-1].c_expresion_arit).esReal){
                                          if((yyvsp[-1].c_expresion_arit).valor > n_escena){
                                                cout << "+++ Inicio de la escena " << (yyvsp[-1].c_expresion_arit).valor << endl;
                                                n_escena = (yyvsp[-1].c_expresion_arit).valor;
                                          }
                                          else
                                                cout << "Error semantico en la linea " << n_lineas << ", la escena " << (yyvsp[-1].c_expresion_arit).valor << " no puede ser procesada" <<  endl;
                                    }
                                    else
                                          cout << "Error semantico en la linea " << n_lineas << ", el número de escena debe ser de tipo ENTERO" << endl;
      
      
                              }
#line 1522 "expresiones.c"
    break;

  case 28: /* $@7: %empty  */
#line 294 "expresiones.y"
                                                                {cout << "+++ Fin de la escena " << n_escena << endl; }
#line 1528 "expresiones.c"
    break;

  case 32: /* $@8: %empty  */
#line 301 "expresiones.y"
                                                               { cout << "-------- personaje " << " [" << (yyvsp[-2].c_identificador) << "] "  << " en linea " << n_lineas << " dice : " << (yyvsp[0].c_cadena) << endl; 
                                                                  
                                                                  if(chs.isExists((yyvsp[-2].c_identificador))){
                                                                        chs.get((yyvsp[-2].c_identificador), ch);
                                                                        str = ch.languaje + "+";
                                                                        str += ch.gender;
                                                                        str += to_string(ch.numCharacter) + " ";
                                                                        strcpy(tc, str.c_str());
                                                                        strcat(tc, (yyvsp[0].c_cadena));
                                                                        
                                                                        if(esBucle)
                                                                              (*table).add(Row(tc, TIPO_ROW::T_FRASE)); 
                                                                        else
                                                                              salida << "espeak -v " << tc << endl;

                                                                  }

                                                               }
#line 1551 "expresiones.c"
    break;

  case 34: /* $@9: %empty  */
#line 319 "expresiones.y"
                                                               { cout << "-------- personaje " << " [" << (yyvsp[-4].c_identificador) << "] "  << " en linea " << n_lineas << " dice : " << (yyvsp[0].c_cadena) << endl; 
                                                                  
                                                                  if(chs.isExists((yyvsp[-4].c_identificador))){
                                                                        chs.get((yyvsp[-4].c_identificador), ch);
                                                                        str = ch.languaje + "+";
                                                                        str += ch.gender;
                                                                        str += to_string(ch.numCharacter) + " ";
                                                                        strcpy(tc, str.c_str());
                                                                        strcat(tc, (yyvsp[0].c_cadena));

                                                                        if(esBucle)
                                                                              (*table).add(Row(tc, TIPO_ROW::T_FRASE));
                                                                        else
                                                                              salida << "espeak -v " << tc << endl;
                                                                  }

                                                               }
#line 1573 "expresiones.c"
    break;

  case 36: /* $@10: %empty  */
#line 336 "expresiones.y"
                                                               { 
                                                                  cout << "-------- personaje " << " [" << (yyvsp[-5].c_identificador) << "] " << " en linea " << n_lineas << " dice : " << (yyvsp[0].c_cadena) << " con entonación " << (yyvsp[-3].c_cadena) << endl; 
                                                                  
                                                                  if(chs.isExists((yyvsp[-5].c_identificador))){
                                                                        chs.get((yyvsp[-5].c_identificador), ch);
                                                                        str = ch.languaje + "+";
                                                                        str += ch.gender;
                                                                        str += to_string(ch.numCharacter) + " ";
                                                                        strcpy(tc, str.c_str());
                                                                        strcat(tc, (yyvsp[-3].c_cadena));
                                                                        strcat(tc, (yyvsp[0].c_cadena));

                                                                        if(esBucle)
                                                                              (*table).add(Row(tc, TIPO_ROW::T_FRASE)); 
                                                                        else
                                                                              salida << "espeak -v " << tc << endl;  
                                                                  } 


                                                               
                                                               }
#line 1599 "expresiones.c"
    break;

  case 38: /* $@11: %empty  */
#line 358 "expresiones.y"
                                                               { 

                                                                  strcpy(tc, (yyvsp[0].c_cadena));
                                                                  cout << "-------- mensaje " << (yyvsp[0].c_cadena) << endl; 
                                                                  
                                                                  if(esBucle)
                                                                        (*table).add(Row(tc, TIPO_ROW::T_MENSAJE)); 
                                                                  else
                                                                        salida << "echo " << tc << endl;
                                                               }
#line 1614 "expresiones.c"
    break;

  case 40: /* $@12: %empty  */
#line 369 "expresiones.y"
                                                               { 
                                                                  cout << "-------- pausa " << (yyvsp[0].c_expresion_arit).valor << endl; 
                                                                  
                                                                  if(esBucle)
                                                                        (*table).add(Row((yyvsp[0].c_expresion_arit).valor, TIPO_ROW::T_PAUSA)); 
                                                                  else
                                                                        salida << "sleep " << (yyvsp[0].c_expresion_arit).valor << endl;
                                                                  
                                                               }
#line 1628 "expresiones.c"
    break;

  case 45: /* $@13: %empty  */
#line 386 "expresiones.y"
                                   {table = new Table((yyvsp[-2].c_expresion_arit).valor); esBucle = true; cout << "+++ repetir " << (yyvsp[-2].c_expresion_arit).valor <<  "(n_loop=" << n_loop <<  ") " << endl;}
#line 1634 "expresiones.c"
    break;

  case 46: /* bucle: REPETIR expr_arit '{' salto $@13 secBloqueEscena '}' salto  */
#line 386 "expresiones.y"
                                                                                                                                                                                            {esBucle = false; ls.add((*table)); table->run(salida); cout << "+++ fin repetir " << (yyvsp[-6].c_expresion_arit).valor << endl; n_loop++;}
#line 1640 "expresiones.c"
    break;

  case 48: /* $@14: %empty  */
#line 391 "expresiones.y"
                                                  {ejecutar=(yyvsp[-4].c_bool);}
#line 1646 "expresiones.c"
    break;

  case 49: /* parteSi: SI '(' expr_log ')' salto_opc '{' salto $@14 secBloqueEscena '}' salto  */
#line 391 "expresiones.y"
                                                                                                  {cout << "+++ bloque si ( condicion=" << (yyvsp[-8].c_bool) <<  ")" << endl;}
#line 1652 "expresiones.c"
    break;

  case 51: /* $@15: %empty  */
#line 395 "expresiones.y"
                         {ejecutar = !ejecutar;}
#line 1658 "expresiones.c"
    break;

  case 52: /* parteSiNo: SI_NO '{' salto $@15 secBloqueEscena '}' salto  */
#line 395 "expresiones.y"
                                                                                        {cout << "+++ bloque sino " << endl;}
#line 1664 "expresiones.c"
    break;

  case 53: /* entonacion: TONO  */
#line 400 "expresiones.y"
                                    {strcpy((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1670 "expresiones.c"
    break;

  case 54: /* entonacion: entonacion ',' TONO  */
#line 401 "expresiones.y"
                                    {strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1676 "expresiones.c"
    break;

  case 55: /* expr_cadena: CADENA  */
#line 406 "expresiones.y"
                                               {strcpy((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1682 "expresiones.c"
    break;

  case 56: /* expr_cadena: ID_CADENA  */
#line 407 "expresiones.y"
                                               {strcpy((yyval.c_cadena), (yyvsp[0].c_identificador));}
#line 1688 "expresiones.c"
    break;

  case 57: /* expr_cadena: expr_arit  */
#line 408 "expresiones.y"
                                               {string str = '"' + to_string((yyvsp[0].c_expresion_arit).valor)  + '"'; strcpy((yyval.c_cadena), str.c_str());}
#line 1694 "expresiones.c"
    break;

  case 58: /* expr_cadena: expr_cadena CONCATENACION expr_cadena  */
#line 409 "expresiones.y"
                                               {cout << "-------- concatenacion cadena (" << (yyvsp[-2].c_cadena) << ") cadena(" << (yyvsp[0].c_cadena) <<  ")" << endl; 
                                                string str1((yyvsp[-2].c_cadena));  
                                                string str2((yyvsp[0].c_cadena));  

                                                str1 = str1.replace(0, 1, "");
                                                str1 = str1.replace(str1.length()-1, 1, "");

                                                str2 = str2.replace(0, 1, "");
                                                str2 = str2.replace(str2.length()-1, 1, "");

                                                str1 = '"' + str1 + str2 + '"';
                                                strcpy((yyval.c_cadena), str1.c_str());}
#line 1711 "expresiones.c"
    break;

  case 59: /* expr_log: TRUE  */
#line 423 "expresiones.y"
                                              {(yyval.c_bool) = true; }
#line 1717 "expresiones.c"
    break;

  case 60: /* expr_log: FALSE  */
#line 424 "expresiones.y"
                                              {(yyval.c_bool) = false; }
#line 1723 "expresiones.c"
    break;

  case 61: /* expr_log: expr_log AND expr_log  */
#line 425 "expresiones.y"
                                              {(yyval.c_bool) = (yyvsp[-2].c_bool) and (yyvsp[0].c_bool); }
#line 1729 "expresiones.c"
    break;

  case 62: /* expr_log: expr_log OR expr_log  */
#line 426 "expresiones.y"
                                              {(yyval.c_bool) = (yyvsp[-2].c_bool) or (yyvsp[0].c_bool); }
#line 1735 "expresiones.c"
    break;

  case 63: /* expr_log: NOT expr_log  */
#line 427 "expresiones.y"
                                              {(yyval.c_bool) = (not (yyvsp[0].c_bool)); }
#line 1741 "expresiones.c"
    break;

  case 64: /* expr_log: '(' expr_log ')'  */
#line 428 "expresiones.y"
                                                  {(yyval.c_bool) =     (yyvsp[-1].c_bool); }
#line 1747 "expresiones.c"
    break;

  case 65: /* expr_log: expr_arit '>' expr_arit  */
#line 429 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor > (yyvsp[0].c_expresion_arit).valor)  ? true : false; }
#line 1753 "expresiones.c"
    break;

  case 66: /* expr_log: expr_arit MAYORIGUAL expr_arit  */
#line 430 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor >= (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1759 "expresiones.c"
    break;

  case 67: /* expr_log: expr_arit '<' expr_arit  */
#line 431 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor < (yyvsp[0].c_expresion_arit).valor)  ? true : false; }
#line 1765 "expresiones.c"
    break;

  case 68: /* expr_log: expr_arit MENORIGUAL expr_arit  */
#line 432 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor <= (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1771 "expresiones.c"
    break;

  case 69: /* expr_log: expr_arit IGUAL2 expr_arit  */
#line 433 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor == (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1777 "expresiones.c"
    break;

  case 70: /* expr_log: expr_arit DISTINTO expr_arit  */
#line 434 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor != (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1783 "expresiones.c"
    break;

  case 71: /* expr_log: expr_log IGUAL2 expr_log  */
#line 435 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_bool) == (yyvsp[0].c_bool)) ? true : false; }
#line 1789 "expresiones.c"
    break;

  case 72: /* expr_log: expr_log DISTINTO expr_log  */
#line 436 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_bool) != (yyvsp[0].c_bool)) ? true : false; }
#line 1795 "expresiones.c"
    break;

  case 73: /* expr_arit: NUMERO  */
#line 439 "expresiones.y"
                                                        {(yyval.c_expresion_arit).esReal = false; (yyval.c_expresion_arit).valor = (yyvsp[0].c_entero); }
#line 1801 "expresiones.c"
    break;

  case 74: /* expr_arit: REAL  */
#line 440 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = true;  (yyval.c_expresion_arit).valor = (yyvsp[0].c_real); }
#line 1807 "expresiones.c"
    break;

  case 75: /* expr_arit: ID_GENERAL  */
#line 441 "expresiones.y"
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
                                                      cout << "Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[0].c_identificador) << " no es de tipo ENTERA o REAL" << endl;            
                                                      errorSemantico = true;
                                                }
                                          } 
                                          else{
                                                cout << "Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[0].c_identificador) << " no esta definida" << endl;
                                                errorVariable = true;
                                                
                                          }
                                    }
#line 1835 "expresiones.c"
    break;

  case 76: /* expr_arit: expr_arit '+' expr_arit  */
#line 464 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor + (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) + int((yyvsp[0].c_expresion_arit).valor); }
#line 1841 "expresiones.c"
    break;

  case 77: /* expr_arit: expr_arit '-' expr_arit  */
#line 465 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor - (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) - int((yyvsp[0].c_expresion_arit).valor); }
#line 1847 "expresiones.c"
    break;

  case 78: /* expr_arit: expr_arit '*' expr_arit  */
#line 466 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor * (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) * int((yyvsp[0].c_expresion_arit).valor); }
#line 1853 "expresiones.c"
    break;

  case 79: /* expr_arit: expr_arit '/' expr_arit  */
#line 468 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = true; 
                                                if((yyvsp[0].c_expresion_arit).valor == 0){ 
                                                      errorSemantico = true; 
                                                      cout << "Error semantico en la linea " << n_lineas << ", se ha detectado una división entre el número 0" << endl;
                                                } 
                                                else 
                                                      (yyval.c_expresion_arit).valor = (yyvsp[-2].c_expresion_arit).valor / (yyvsp[0].c_expresion_arit).valor;
                                              }
#line 1866 "expresiones.c"
    break;

  case 80: /* expr_arit: expr_arit DIV expr_arit  */
#line 477 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; 
                                                if((yyvsp[0].c_expresion_arit).valor == 0){ 
                                                      errorSemantico = true;
                                                      cout << "Error semantico en la linea " << n_lineas << ", se ha detectado una divisón entre el número 0" << endl;
                                                }else {
                                                      if((yyval.c_expresion_arit).esReal){ 
                                                            errorSemantico = true; 
                                                           cout << "Error semantico en la linea " << n_lineas << ", el operador div no se puede usar con datos de tipo real " << endl;
                                                      } 
                                                      else 
                                                            (yyval.c_expresion_arit).valor = int((yyvsp[-2].c_expresion_arit).valor) / int((yyvsp[0].c_expresion_arit).valor);
                                                }
                                               }
#line 1884 "expresiones.c"
    break;

  case 81: /* expr_arit: '-' expr_arit  */
#line 491 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[0].c_expresion_arit).esReal ; (yyval.c_expresion_arit).valor = ((yyvsp[0].c_expresion_arit).esReal) ? -(yyvsp[0].c_expresion_arit).valor : int(-(yyvsp[0].c_expresion_arit).valor); }
#line 1890 "expresiones.c"
    break;

  case 82: /* expr_arit: '(' expr_arit ')'  */
#line 492 "expresiones.y"
                                                  {(yyval.c_expresion_arit).esReal = (yyvsp[-1].c_expresion_arit).esReal ; (yyval.c_expresion_arit).valor = ((yyvsp[-1].c_expresion_arit).esReal) ?  (yyvsp[-1].c_expresion_arit).valor : int( (yyvsp[-1].c_expresion_arit).valor); }
#line 1896 "expresiones.c"
    break;


#line 1900 "expresiones.c"

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

#line 494 "expresiones.y"


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
