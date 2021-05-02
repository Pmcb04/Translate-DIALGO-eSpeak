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
  YYSYMBOL_EN = 25,                        /* EN  */
  YYSYMBOL_EN_US = 26,                     /* EN_US  */
  YYSYMBOL_ES = 27,                        /* ES  */
  YYSYMBOL_ES_LA = 28,                     /* ES_LA  */
  YYSYMBOL_PT = 29,                        /* PT  */
  YYSYMBOL_IT = 30,                        /* IT  */
  YYSYMBOL_FR = 31,                        /* FR  */
  YYSYMBOL_DESPACIO = 32,                  /* DESPACIO  */
  YYSYMBOL_DEPRISA = 33,                   /* DEPRISA  */
  YYSYMBOL_GRITANDO = 34,                  /* GRITANDO  */
  YYSYMBOL_VOZ_BAJA = 35,                  /* VOZ_BAJA  */
  YYSYMBOL_MASCULINO = 36,                 /* MASCULINO  */
  YYSYMBOL_FEMENINO = 37,                  /* FEMENINO  */
  YYSYMBOL_CONCATENACION = 38,             /* CONCATENACION  */
  YYSYMBOL_SI = 39,                        /* SI  */
  YYSYMBOL_SI_NO = 40,                     /* SI_NO  */
  YYSYMBOL_REPETIR = 41,                   /* REPETIR  */
  YYSYMBOL_42_ = 42,                       /* '<'  */
  YYSYMBOL_43_ = 43,                       /* '>'  */
  YYSYMBOL_44_ = 44,                       /* '+'  */
  YYSYMBOL_45_ = 45,                       /* '-'  */
  YYSYMBOL_46_ = 46,                       /* '*'  */
  YYSYMBOL_47_ = 47,                       /* '/'  */
  YYSYMBOL_menos = 48,                     /* menos  */
  YYSYMBOL_49_n_ = 49,                     /* '\n'  */
  YYSYMBOL_50_ = 50,                       /* '='  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* ':'  */
  YYSYMBOL_53_ = 53,                       /* '['  */
  YYSYMBOL_54_ = 54,                       /* ']'  */
  YYSYMBOL_55_ = 55,                       /* '{'  */
  YYSYMBOL_56_ = 56,                       /* '}'  */
  YYSYMBOL_57_ = 57,                       /* '('  */
  YYSYMBOL_58_ = 58,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_salto = 60,                     /* salto  */
  YYSYMBOL_salto_opc = 61,                 /* salto_opc  */
  YYSYMBOL_programa = 62,                  /* programa  */
  YYSYMBOL_bloquePersonajes = 63,          /* bloquePersonajes  */
  YYSYMBOL_64_1 = 64,                      /* $@1  */
  YYSYMBOL_secBloquePersonajes = 65,       /* secBloquePersonajes  */
  YYSYMBOL_asignacionPersonaje = 66,       /* asignacionPersonaje  */
  YYSYMBOL_67_2 = 67,                      /* $@2  */
  YYSYMBOL_bloqueDefiniciones = 68,        /* bloqueDefiniciones  */
  YYSYMBOL_69_3 = 69,                      /* $@3  */
  YYSYMBOL_secBloqueDefiniciones = 70,     /* secBloqueDefiniciones  */
  YYSYMBOL_identificador = 71,             /* identificador  */
  YYSYMBOL_identificadorGeneral = 72,      /* identificadorGeneral  */
  YYSYMBOL_73_4 = 73,                      /* $@4  */
  YYSYMBOL_74_5 = 74,                      /* $@5  */
  YYSYMBOL_identificadorCadena = 75,       /* identificadorCadena  */
  YYSYMBOL_76_6 = 76,                      /* $@6  */
  YYSYMBOL_secEscena = 77,                 /* secEscena  */
  YYSYMBOL_escena = 78,                    /* escena  */
  YYSYMBOL_79_7 = 79,                      /* $@7  */
  YYSYMBOL_80_8 = 80,                      /* $@8  */
  YYSYMBOL_secBloqueEscena = 81,           /* secBloqueEscena  */
  YYSYMBOL_bloqueEscena = 82,              /* bloqueEscena  */
  YYSYMBOL_83_9 = 83,                      /* $@9  */
  YYSYMBOL_84_10 = 84,                     /* $@10  */
  YYSYMBOL_85_11 = 85,                     /* $@11  */
  YYSYMBOL_86_12 = 86,                     /* $@12  */
  YYSYMBOL_87_13 = 87,                     /* $@13  */
  YYSYMBOL_bucle = 88,                     /* bucle  */
  YYSYMBOL_89_14 = 89,                     /* $@14  */
  YYSYMBOL_condicional = 90,               /* condicional  */
  YYSYMBOL_parteSi = 91,                   /* parteSi  */
  YYSYMBOL_92_15 = 92,                     /* $@15  */
  YYSYMBOL_parteSiNo = 93,                 /* parteSiNo  */
  YYSYMBOL_94_16 = 94,                     /* $@16  */
  YYSYMBOL_entonacion = 95,                /* entonacion  */
  YYSYMBOL_tono = 96,                      /* tono  */
  YYSYMBOL_idioma = 97,                    /* idioma  */
  YYSYMBOL_voz = 98,                       /* voz  */
  YYSYMBOL_expr_cadena = 99,               /* expr_cadena  */
  YYSYMBOL_expr_log = 100,                 /* expr_log  */
  YYSYMBOL_expr_arit = 101                 /* expr_arit  */
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
#define YYLAST   294

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      49,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      57,    58,    46,    44,    51,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,     2,
      42,    50,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   125,   125,   126,   129,   130,   134,   139,   139,   142,
     143,   146,   146,   151,   152,   152,   155,   156,   159,   160,
     163,   163,   209,   209,   245,   245,   282,   283,   286,   299,
     286,   302,   303,   306,   306,   324,   324,   341,   341,   363,
     363,   374,   374,   384,   386,   388,   391,   391,   393,   396,
     396,   399,   400,   400,   405,   406,   409,   410,   411,   412,
     416,   417,   418,   419,   420,   421,   422,   427,   428,   433,
     434,   435,   437,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   456,   457,   458,
     481,   482,   483,   485,   494,   508,   509
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
  "CADENA", "EN", "EN_US", "ES", "ES_LA", "PT", "IT", "FR", "DESPACIO",
  "DEPRISA", "GRITANDO", "VOZ_BAJA", "MASCULINO", "FEMENINO",
  "CONCATENACION", "SI", "SI_NO", "REPETIR", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "menos", "'\\n'", "'='", "','", "':'", "'['", "']'", "'{'",
  "'}'", "'('", "')'", "$accept", "salto", "salto_opc", "programa",
  "bloquePersonajes", "$@1", "secBloquePersonajes", "asignacionPersonaje",
  "$@2", "bloqueDefiniciones", "$@3", "secBloqueDefiniciones",
  "identificador", "identificadorGeneral", "$@4", "$@5",
  "identificadorCadena", "$@6", "secEscena", "escena", "$@7", "$@8",
  "secBloqueEscena", "bloqueEscena", "$@9", "$@10", "$@11", "$@12", "$@13",
  "bucle", "$@14", "condicional", "parteSi", "$@15", "parteSiNo", "$@16",
  "entonacion", "tono", "idioma", "voz", "expr_cadena", "expr_log",
  "expr_arit", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    60,    62,    43,    45,    42,    47,   297,    10,
      61,    44,    58,    91,    93,   123,   125,    40,    41
};
#endif

#define YYPACT_NINF (-155)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -155,    -8,     6,  -155,  -155,     9,  -155,   -33,  -155,    21,
    -155,   -17,   -33,    57,    21,  -155,    -7,  -155,    28,  -155,
      38,  -155,  -155,  -155,    57,    57,   133,  -155,    12,  -155,
      15,    44,    65,  -155,  -155,  -155,  -155,     0,    57,    57,
      57,    57,    57,  -155,   254,    18,    10,  -155,  -155,  -155,
      35,    35,  -155,  -155,   -33,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,    17,    18,  -155,  -155,    18,   114,   160,  -155,
    -155,    47,   142,   222,    70,  -155,   160,   109,    99,    18,
      18,    18,    18,   -33,    57,    57,    57,    57,    57,    57,
     -33,    10,   -33,    87,    57,    10,    31,    57,  -155,   228,
    -155,  -155,  -155,    63,  -155,  -155,    74,  -155,   139,    56,
    -155,  -155,    75,   142,   142,   142,   142,   142,   142,    75,
    -155,    75,    10,   240,   142,    47,    18,   104,  -155,  -155,
      76,  -155,  -155,    47,  -155,  -155,  -155,  -155,   103,   -21,
    -155,   -33,   -33,   112,   -33,   -33,   -33,   -33,   -33,    10,
     149,   106,    75,    75,  -155,    75,    75,    75,    75,    75,
      47,  -155,    10,   -40,   237,   237,   -33,    47,   -33,   171,
     176,    75,   -33,    75,   -33,   -33,    75,   237,    75,    75,
     199,   -33,    75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     7,     5,    13,     1,     0,    14,     0,
       2,     0,     0,     0,     6,    26,     0,     3,     8,     9,
       0,    87,    88,    89,     0,     0,     0,    27,     0,    10,
       0,     0,    15,    16,    19,    18,    95,     0,     0,     0,
       0,     0,     0,    28,     0,     0,     0,    17,    96,    94,
      90,    91,    92,    93,     0,    60,    61,    62,    63,    64,
      65,    66,     0,     0,    73,    74,     0,    22,    20,    70,
      69,    24,    71,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,     0,
      31,    45,    44,    51,    67,    68,     0,    78,    75,    76,
      85,    86,    23,    80,    82,    83,    84,    81,    79,    21,
      72,    25,     0,     0,    41,    39,     0,     0,    29,    32,
       0,    48,    11,    33,    56,    57,    58,    59,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    40,     4,    46,    30,    52,    12,    34,
      35,    55,     0,     0,     0,     0,     0,    37,     0,     0,
       0,    36,     0,    49,     0,     0,    38,     0,    47,    53,
       0,     0,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,   -12,     7,  -155,  -155,  -155,  -155,   146,  -155,  -155,
    -155,  -155,    69,  -155,  -155,  -155,  -155,  -155,  -155,   152,
    -155,  -155,  -154,   -97,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,    25,  -155,  -155,
     -83,   -62,    11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    11,     1,     2,     5,     7,    18,    19,   147,     9,
      12,    32,    98,    34,    90,    83,    35,    92,    14,    15,
      54,   145,    99,   100,   148,   166,   172,   142,   141,   101,
     164,   102,   103,   177,   131,   165,   139,   140,    62,   106,
      71,    67,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    75,   129,    16,    77,    38,     6,     3,   120,     4,
     169,   170,   125,    21,    22,   168,    10,   108,   109,   110,
     111,    21,    22,   180,    26,     8,    63,    64,    65,    23,
     150,    69,    17,   151,    70,    36,    37,    23,    13,   133,
      38,     4,    73,    28,    39,    40,    41,    42,    16,    49,
      50,    51,    52,    53,    44,    24,    68,    30,    48,    31,
      21,    22,    79,    24,   143,    45,   160,    25,    74,    81,
      82,   112,   129,   129,    76,    66,    23,    78,   119,   167,
     121,    41,    42,   129,    30,    91,    31,    17,   126,    33,
      76,    76,    76,    76,    46,   113,   114,   115,   116,   117,
     118,    47,    24,   130,    38,   124,   104,   105,   127,    38,
      84,    85,    86,    87,    25,    79,    80,   132,    79,    80,
      79,    80,    81,    82,    17,    81,    82,    81,    82,   152,
     153,   146,   155,   156,   157,   158,   159,    76,    38,   122,
     123,    88,    89,    39,    40,    41,    42,    38,    39,    40,
      41,    42,    81,    82,   171,   149,   173,    48,   162,   144,
     176,   163,   178,   179,    29,    38,    27,   107,     0,   182,
     154,    84,    85,    86,    87,   161,     0,    39,    40,    41,
      42,   134,   135,   136,   137,    43,    39,    40,    41,    42,
      30,    93,    31,    94,    95,    30,    93,    31,    94,    95,
       0,     0,    88,    89,    39,    40,    41,    42,     0,     0,
      96,     0,    97,     0,     0,    96,     0,    97,    30,    93,
      31,    94,    95,     0,     0,     0,     0,   174,     0,     0,
       0,     0,   175,     0,     0,     0,     0,     0,    96,     0,
      97,    30,    93,    31,    94,    95,   128,    30,    93,    31,
      94,    95,     0,     0,     0,   181,    30,    93,    31,    94,
      95,    96,     0,    97,     0,     0,     0,    96,     0,    97,
       0,    17,   134,   135,   136,   137,    96,     0,    97,    55,
      56,    57,    58,    59,    60,    61,     0,     0,     0,     0,
       0,     0,     0,     0,   138
};

static const yytype_int16 yycheck[] =
{
      12,    63,    99,    20,    66,     5,     0,    15,    91,    49,
     164,   165,    95,     3,     4,    55,    49,    79,    80,    81,
      82,     3,     4,   177,    13,    16,     8,     9,    10,    19,
      51,    21,    49,    54,    24,    24,    25,    19,    17,   122,
       5,    49,    54,    50,    44,    45,    46,    47,    20,    38,
      39,    40,    41,    42,    42,    45,    45,    19,    58,    21,
       3,     4,     6,    45,   126,    50,   149,    57,    51,    13,
      14,    83,   169,   170,    63,    57,    19,    66,    90,   162,
      92,    46,    47,   180,    19,    38,    21,    49,    57,    20,
      79,    80,    81,    82,    50,    84,    85,    86,    87,    88,
      89,    32,    45,    40,     5,    94,    36,    37,    97,     5,
      11,    12,    13,    14,    57,     6,     7,    43,     6,     7,
       6,     7,    13,    14,    49,    13,    14,    13,    14,   141,
     142,    55,   144,   145,   146,   147,   148,   126,     5,    52,
      53,    42,    43,    44,    45,    46,    47,     5,    44,    45,
      46,    47,    13,    14,   166,    52,   168,    58,    52,    55,
     172,   154,   174,   175,    18,     5,    14,    58,    -1,   181,
      58,    11,    12,    13,    14,   150,    -1,    44,    45,    46,
      47,    32,    33,    34,    35,    52,    44,    45,    46,    47,
      19,    20,    21,    22,    23,    19,    20,    21,    22,    23,
      -1,    -1,    42,    43,    44,    45,    46,    47,    -1,    -1,
      39,    -1,    41,    -1,    -1,    39,    -1,    41,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      41,    19,    20,    21,    22,    23,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    56,    19,    20,    21,    22,
      23,    39,    -1,    41,    -1,    -1,    -1,    39,    -1,    41,
      -1,    49,    32,    33,    34,    35,    39,    -1,    41,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    61,    62,    15,    49,    63,     0,    64,    16,    68,
      49,    60,    69,    17,    77,    78,    20,    49,    65,    66,
      60,     3,     4,    19,    45,    57,   101,    78,    50,    66,
      19,    21,    70,    71,    72,    75,   101,   101,     5,    44,
      45,    46,    47,    52,    42,    50,    50,    71,    58,   101,
     101,   101,   101,   101,    79,    25,    26,    27,    28,    29,
      30,    31,    97,     8,     9,    10,    57,   100,   101,    21,
      24,    99,   101,    60,    51,   100,   101,   100,   101,     6,
       7,    13,    14,    74,    11,    12,    13,    14,    42,    43,
      73,    38,    76,    20,    22,    23,    39,    41,    71,    81,
      82,    88,    90,    91,    36,    37,    98,    58,   100,   100,
     100,   100,    60,   101,   101,   101,   101,   101,   101,    60,
      99,    60,    52,    53,   101,    99,    57,   101,    18,    82,
      40,    93,    43,    99,    32,    33,    34,    35,    54,    95,
      96,    87,    86,   100,    55,    80,    55,    67,    83,    52,
      51,    54,    60,    60,    58,    60,    60,    60,    60,    60,
      99,    96,    52,    61,    89,    94,    84,    99,    55,    81,
      81,    60,    85,    60,    56,    56,    60,    92,    60,    60,
      81,    56,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    62,    64,    63,    65,
      65,    67,    66,    68,    69,    68,    70,    70,    71,    71,
      73,    72,    74,    72,    76,    75,    77,    77,    79,    80,
      78,    81,    81,    83,    82,    84,    82,    85,    82,    86,
      82,    87,    82,    82,    82,    82,    89,    88,    90,    92,
      91,    93,    94,    93,    95,    95,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    98,    98,    99,
      99,    99,    99,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     4,     0,     4,     1,
       2,     0,     9,     0,     0,     4,     1,     2,     1,     1,
       0,     5,     0,     5,     0,     5,     1,     2,     0,     0,
       9,     1,     2,     0,     5,     0,     7,     0,     8,     0,
       4,     0,     4,     1,     1,     1,     0,     8,     2,     0,
      11,     0,     0,     7,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       3,     3,     3,     3,     3,     2,     3
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
#line 125 "expresiones.y"
                     {n_lineas++;}
#line 1383 "expresiones.c"
    break;

  case 3: /* salto: salto '\n'  */
#line 126 "expresiones.y"
                    {n_lineas++;}
#line 1389 "expresiones.c"
    break;

  case 5: /* salto_opc: salto_opc '\n'  */
#line 130 "expresiones.y"
                        {n_lineas++;}
#line 1395 "expresiones.c"
    break;

  case 7: /* $@1: %empty  */
#line 139 "expresiones.y"
                             {cout << "+++ bloque personajes linea " << n_lineas << endl;}
#line 1401 "expresiones.c"
    break;

  case 11: /* $@2: %empty  */
#line 146 "expresiones.y"
                                                           { cout << "-------- asignacion nombre " << (yyvsp[-6].c_identificador) << "," << (yyvsp[-3].c_cadena) << "," << (yyvsp[-1].c_cadena) <<  " linea " << n_lineas << endl; chs.add(Character((yyvsp[-6].c_identificador), n_lineas, (yyvsp[-3].c_cadena), (yyvsp[-1].c_cadena)));}
#line 1407 "expresiones.c"
    break;

  case 14: /* $@3: %empty  */
#line 152 "expresiones.y"
                     {cout << "+++ bloque definiciones linea " << n_lineas << endl;}
#line 1413 "expresiones.c"
    break;

  case 20: /* $@4: %empty  */
#line 163 "expresiones.y"
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
#line 1463 "expresiones.c"
    break;

  case 22: /* $@5: %empty  */
#line 209 "expresiones.y"
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
#line 1501 "expresiones.c"
    break;

  case 24: /* $@6: %empty  */
#line 245 "expresiones.y"
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
#line 1539 "expresiones.c"
    break;

  case 28: /* $@7: %empty  */
#line 286 "expresiones.y"
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
#line 1558 "expresiones.c"
    break;

  case 29: /* $@8: %empty  */
#line 299 "expresiones.y"
                                                                {cout << "+++ Fin de la escena " << n_escena << endl; }
#line 1564 "expresiones.c"
    break;

  case 33: /* $@9: %empty  */
#line 306 "expresiones.y"
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
#line 1587 "expresiones.c"
    break;

  case 35: /* $@10: %empty  */
#line 324 "expresiones.y"
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
#line 1609 "expresiones.c"
    break;

  case 37: /* $@11: %empty  */
#line 341 "expresiones.y"
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
#line 1635 "expresiones.c"
    break;

  case 39: /* $@12: %empty  */
#line 363 "expresiones.y"
                                                               { 

                                                                  strcpy(tc, (yyvsp[0].c_cadena));
                                                                  cout << "-------- mensaje " << (yyvsp[0].c_cadena) << endl; 
                                                                  
                                                                  if(esBucle)
                                                                        (*table).add(Row(tc, TIPO_ROW::T_MENSAJE)); 
                                                                  else
                                                                        salida << "echo " << tc << endl;
                                                               }
#line 1650 "expresiones.c"
    break;

  case 41: /* $@13: %empty  */
#line 374 "expresiones.y"
                                                               { 
                                                                  cout << "-------- pausa " << (yyvsp[0].c_expresion_arit).valor << endl; 
                                                                  
                                                                  if(esBucle)
                                                                        (*table).add(Row((yyvsp[0].c_expresion_arit).valor, TIPO_ROW::T_PAUSA)); 
                                                                  else
                                                                        salida << "sleep " << (yyvsp[0].c_expresion_arit).valor << endl;
                                                                  
                                                               }
#line 1664 "expresiones.c"
    break;

  case 46: /* $@14: %empty  */
#line 391 "expresiones.y"
                                   {table = new Table((yyvsp[-2].c_expresion_arit).valor); esBucle = true; cout << "+++ repetir " << (yyvsp[-2].c_expresion_arit).valor <<  "(n_loop=" << n_loop <<  ") " << endl;}
#line 1670 "expresiones.c"
    break;

  case 47: /* bucle: REPETIR expr_arit '{' salto $@14 secBloqueEscena '}' salto  */
#line 391 "expresiones.y"
                                                                                                                                                                                            {esBucle = false; ls.add((*table)); table->run(salida); cout << "+++ fin repetir " << (yyvsp[-6].c_expresion_arit).valor << endl; n_loop++;}
#line 1676 "expresiones.c"
    break;

  case 49: /* $@15: %empty  */
#line 396 "expresiones.y"
                                                  {ejecutar=(yyvsp[-4].c_bool);}
#line 1682 "expresiones.c"
    break;

  case 50: /* parteSi: SI '(' expr_log ')' salto_opc '{' salto $@15 secBloqueEscena '}' salto  */
#line 396 "expresiones.y"
                                                                                                  {cout << "+++ bloque si ( condicion=" << (yyvsp[-8].c_bool) <<  ")" << endl;}
#line 1688 "expresiones.c"
    break;

  case 52: /* $@16: %empty  */
#line 400 "expresiones.y"
                         {ejecutar = !ejecutar;}
#line 1694 "expresiones.c"
    break;

  case 53: /* parteSiNo: SI_NO '{' salto $@16 secBloqueEscena '}' salto  */
#line 400 "expresiones.y"
                                                                                        {cout << "+++ bloque sino " << endl;}
#line 1700 "expresiones.c"
    break;

  case 54: /* entonacion: tono  */
#line 405 "expresiones.y"
                                    {strcpy((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1706 "expresiones.c"
    break;

  case 55: /* entonacion: entonacion ',' tono  */
#line 406 "expresiones.y"
                                    {strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1712 "expresiones.c"
    break;

  case 56: /* tono: DESPACIO  */
#line 409 "expresiones.y"
                                    {strcpy((yyval.c_cadena), "-s 80 ");}
#line 1718 "expresiones.c"
    break;

  case 57: /* tono: DEPRISA  */
#line 410 "expresiones.y"
                                    {strcpy((yyval.c_cadena), "-s 300 ");}
#line 1724 "expresiones.c"
    break;

  case 58: /* tono: GRITANDO  */
#line 411 "expresiones.y"
                                    {strcpy((yyval.c_cadena), "-a 200 ");}
#line 1730 "expresiones.c"
    break;

  case 59: /* tono: VOZ_BAJA  */
#line 412 "expresiones.y"
                                    {strcpy((yyval.c_cadena), "-a 30 ");}
#line 1736 "expresiones.c"
    break;

  case 60: /* idioma: EN  */
#line 416 "expresiones.y"
                        {strcpy((yyval.c_cadena), "en");}
#line 1742 "expresiones.c"
    break;

  case 61: /* idioma: EN_US  */
#line 417 "expresiones.y"
                        {strcpy((yyval.c_cadena), "en-us");}
#line 1748 "expresiones.c"
    break;

  case 62: /* idioma: ES  */
#line 418 "expresiones.y"
                        {strcpy((yyval.c_cadena), "es");}
#line 1754 "expresiones.c"
    break;

  case 63: /* idioma: ES_LA  */
#line 419 "expresiones.y"
                        {strcpy((yyval.c_cadena), "es-la");}
#line 1760 "expresiones.c"
    break;

  case 64: /* idioma: PT  */
#line 420 "expresiones.y"
                        {strcpy((yyval.c_cadena), "pt");}
#line 1766 "expresiones.c"
    break;

  case 65: /* idioma: IT  */
#line 421 "expresiones.y"
                        {strcpy((yyval.c_cadena), "it");}
#line 1772 "expresiones.c"
    break;

  case 66: /* idioma: FR  */
#line 422 "expresiones.y"
                        {strcpy((yyval.c_cadena), "fr");}
#line 1778 "expresiones.c"
    break;

  case 67: /* voz: MASCULINO  */
#line 427 "expresiones.y"
                       {strcpy((yyval.c_cadena), "m");}
#line 1784 "expresiones.c"
    break;

  case 68: /* voz: FEMENINO  */
#line 428 "expresiones.y"
                       {strcpy((yyval.c_cadena), "f");}
#line 1790 "expresiones.c"
    break;

  case 69: /* expr_cadena: CADENA  */
#line 433 "expresiones.y"
                                               {strcpy((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1796 "expresiones.c"
    break;

  case 70: /* expr_cadena: ID_CADENA  */
#line 434 "expresiones.y"
                                               {strcpy((yyval.c_cadena), (yyvsp[0].c_identificador));}
#line 1802 "expresiones.c"
    break;

  case 71: /* expr_cadena: expr_arit  */
#line 435 "expresiones.y"
                                               {sprintf((yyval.c_cadena), "%f", (yyvsp[0].c_expresion_arit).valor);}
#line 1808 "expresiones.c"
    break;

  case 72: /* expr_cadena: expr_cadena CONCATENACION expr_cadena  */
#line 437 "expresiones.y"
                                               {cout << "-------- concatenacion cadena (" << (yyvsp[-2].c_cadena) << ") cadena(" << (yyvsp[0].c_cadena) <<  ")" << endl; strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1814 "expresiones.c"
    break;

  case 73: /* expr_log: TRUE  */
#line 440 "expresiones.y"
                                              {(yyval.c_bool) = true; }
#line 1820 "expresiones.c"
    break;

  case 74: /* expr_log: FALSE  */
#line 441 "expresiones.y"
                                              {(yyval.c_bool) = false; }
#line 1826 "expresiones.c"
    break;

  case 75: /* expr_log: expr_log AND expr_log  */
#line 442 "expresiones.y"
                                              {(yyval.c_bool) = (yyvsp[-2].c_bool) and (yyvsp[0].c_bool); }
#line 1832 "expresiones.c"
    break;

  case 76: /* expr_log: expr_log OR expr_log  */
#line 443 "expresiones.y"
                                              {(yyval.c_bool) = (yyvsp[-2].c_bool) or (yyvsp[0].c_bool); }
#line 1838 "expresiones.c"
    break;

  case 77: /* expr_log: NOT expr_log  */
#line 444 "expresiones.y"
                                              {(yyval.c_bool) = (not (yyvsp[0].c_bool)); }
#line 1844 "expresiones.c"
    break;

  case 78: /* expr_log: '(' expr_log ')'  */
#line 445 "expresiones.y"
                                                  {(yyval.c_bool) =     (yyvsp[-1].c_bool); }
#line 1850 "expresiones.c"
    break;

  case 79: /* expr_log: expr_arit '>' expr_arit  */
#line 446 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor > (yyvsp[0].c_expresion_arit).valor)  ? true : false; }
#line 1856 "expresiones.c"
    break;

  case 80: /* expr_log: expr_arit MAYORIGUAL expr_arit  */
#line 447 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor >= (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1862 "expresiones.c"
    break;

  case 81: /* expr_log: expr_arit '<' expr_arit  */
#line 448 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor < (yyvsp[0].c_expresion_arit).valor)  ? true : false; }
#line 1868 "expresiones.c"
    break;

  case 82: /* expr_log: expr_arit MENORIGUAL expr_arit  */
#line 449 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor <= (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1874 "expresiones.c"
    break;

  case 83: /* expr_log: expr_arit IGUAL2 expr_arit  */
#line 450 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor == (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1880 "expresiones.c"
    break;

  case 84: /* expr_log: expr_arit DISTINTO expr_arit  */
#line 451 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor != (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1886 "expresiones.c"
    break;

  case 85: /* expr_log: expr_log IGUAL2 expr_log  */
#line 452 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_bool) == (yyvsp[0].c_bool)) ? true : false; }
#line 1892 "expresiones.c"
    break;

  case 86: /* expr_log: expr_log DISTINTO expr_log  */
#line 453 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_bool) != (yyvsp[0].c_bool)) ? true : false; }
#line 1898 "expresiones.c"
    break;

  case 87: /* expr_arit: NUMERO  */
#line 456 "expresiones.y"
                                                        {(yyval.c_expresion_arit).esReal = false; (yyval.c_expresion_arit).valor = (yyvsp[0].c_entero); }
#line 1904 "expresiones.c"
    break;

  case 88: /* expr_arit: REAL  */
#line 457 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = true;  (yyval.c_expresion_arit).valor = (yyvsp[0].c_real); }
#line 1910 "expresiones.c"
    break;

  case 89: /* expr_arit: ID_GENERAL  */
#line 458 "expresiones.y"
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
#line 1938 "expresiones.c"
    break;

  case 90: /* expr_arit: expr_arit '+' expr_arit  */
#line 481 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor + (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) + int((yyvsp[0].c_expresion_arit).valor); }
#line 1944 "expresiones.c"
    break;

  case 91: /* expr_arit: expr_arit '-' expr_arit  */
#line 482 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor - (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) - int((yyvsp[0].c_expresion_arit).valor); }
#line 1950 "expresiones.c"
    break;

  case 92: /* expr_arit: expr_arit '*' expr_arit  */
#line 483 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor * (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) * int((yyvsp[0].c_expresion_arit).valor); }
#line 1956 "expresiones.c"
    break;

  case 93: /* expr_arit: expr_arit '/' expr_arit  */
#line 485 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = true; 
                                                if((yyvsp[0].c_expresion_arit).valor == 0){ 
                                                      errorSemantico = true; 
                                                      cout << "Error semantico en la linea " << n_lineas << ", se ha detectado una división entre el número 0" << endl;
                                                } 
                                                else 
                                                      (yyval.c_expresion_arit).valor = (yyvsp[-2].c_expresion_arit).valor / (yyvsp[0].c_expresion_arit).valor;
                                              }
#line 1969 "expresiones.c"
    break;

  case 94: /* expr_arit: expr_arit DIV expr_arit  */
#line 494 "expresiones.y"
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
#line 1987 "expresiones.c"
    break;

  case 95: /* expr_arit: '-' expr_arit  */
#line 508 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[0].c_expresion_arit).esReal ; (yyval.c_expresion_arit).valor = ((yyvsp[0].c_expresion_arit).esReal) ? -(yyvsp[0].c_expresion_arit).valor : int(-(yyvsp[0].c_expresion_arit).valor); }
#line 1993 "expresiones.c"
    break;

  case 96: /* expr_arit: '(' expr_arit ')'  */
#line 509 "expresiones.y"
                                                  {(yyval.c_expresion_arit).esReal = (yyvsp[-1].c_expresion_arit).esReal ; (yyval.c_expresion_arit).valor = ((yyvsp[-1].c_expresion_arit).esReal) ?  (yyvsp[-1].c_expresion_arit).valor : int( (yyvsp[-1].c_expresion_arit).valor); }
#line 1999 "expresiones.c"
    break;


#line 2003 "expresiones.c"

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

#line 511 "expresiones.y"


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
