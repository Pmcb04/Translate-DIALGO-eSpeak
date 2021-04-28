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


#line 108 "expresiones.c"

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
  YYSYMBOL_REPETIR = 24,                   /* REPETIR  */
  YYSYMBOL_SI = 25,                        /* SI  */
  YYSYMBOL_SI_NO = 26,                     /* SI_NO  */
  YYSYMBOL_CADENA = 27,                    /* CADENA  */
  YYSYMBOL_EN = 28,                        /* EN  */
  YYSYMBOL_EN_US = 29,                     /* EN_US  */
  YYSYMBOL_ES = 30,                        /* ES  */
  YYSYMBOL_ES_LA = 31,                     /* ES_LA  */
  YYSYMBOL_PT = 32,                        /* PT  */
  YYSYMBOL_IT = 33,                        /* IT  */
  YYSYMBOL_FR = 34,                        /* FR  */
  YYSYMBOL_DESPACIO = 35,                  /* DESPACIO  */
  YYSYMBOL_DEPRISA = 36,                   /* DEPRISA  */
  YYSYMBOL_GRITANDO = 37,                  /* GRITANDO  */
  YYSYMBOL_VOZ_BAJA = 38,                  /* VOZ_BAJA  */
  YYSYMBOL_MASCULINO = 39,                 /* MASCULINO  */
  YYSYMBOL_FEMENINO = 40,                  /* FEMENINO  */
  YYSYMBOL_CONCATENACION = 41,             /* CONCATENACION  */
  YYSYMBOL_42_ = 42,                       /* '<'  */
  YYSYMBOL_43_ = 43,                       /* '>'  */
  YYSYMBOL_44_ = 44,                       /* '+'  */
  YYSYMBOL_45_ = 45,                       /* '-'  */
  YYSYMBOL_46_ = 46,                       /* '*'  */
  YYSYMBOL_47_ = 47,                       /* '/'  */
  YYSYMBOL_menos = 48,                     /* menos  */
  YYSYMBOL_49_n_ = 49,                     /* '\n'  */
  YYSYMBOL_50_ = 50,                       /* '='  */
  YYSYMBOL_51_ = 51,                       /* ':'  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* '{'  */
  YYSYMBOL_55_ = 55,                       /* ','  */
  YYSYMBOL_56_ = 56,                       /* '['  */
  YYSYMBOL_57_ = 57,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_salto = 59,                     /* salto  */
  YYSYMBOL_entrada = 60,                   /* entrada  */
  YYSYMBOL_linea = 61,                     /* linea  */
  YYSYMBOL_62_1 = 62,                      /* $@1  */
  YYSYMBOL_63_2 = 63,                      /* $@2  */
  YYSYMBOL_64_3 = 64,                      /* $@3  */
  YYSYMBOL_65_4 = 65,                      /* $@4  */
  YYSYMBOL_66_5 = 66,                      /* $@5  */
  YYSYMBOL_67_6 = 67,                      /* $@6  */
  YYSYMBOL_68_7 = 68,                      /* $@7  */
  YYSYMBOL_69_8 = 69,                      /* $@8  */
  YYSYMBOL_70_9 = 70,                      /* $@9  */
  YYSYMBOL_71_10 = 71,                     /* $@10  */
  YYSYMBOL_72_11 = 72,                     /* $@11  */
  YYSYMBOL_73_12 = 73,                     /* $@12  */
  YYSYMBOL_74_13 = 74,                     /* $@13  */
  YYSYMBOL_75_14 = 75,                     /* $@14  */
  YYSYMBOL_expr_cadena = 76,               /* expr_cadena  */
  YYSYMBOL_expr_log = 77,                  /* expr_log  */
  YYSYMBOL_expr_arit = 78,                 /* expr_arit  */
  YYSYMBOL_entonacion = 79,                /* entonacion  */
  YYSYMBOL_idioma = 80,                    /* idioma  */
  YYSYMBOL_voz = 81                        /* voz  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

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
      52,    53,    46,    44,    55,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,     2,
      42,    50,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,     2,     2,     2,     2,     2,
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
       0,    88,    88,    89,    91,    92,    96,    96,   131,   131,
     161,   161,   162,   162,   163,   163,   177,   177,   178,   178,
     179,   180,   180,   181,   181,   182,   182,   184,   184,   214,
     216,   216,   217,   217,   218,   218,   221,   225,   226,   227,
     228,   229,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   248,   249,   250,   273,
     274,   275,   277,   286,   300,   301,   305,   306,   307,   308,
     309,   310,   311,   312,   316,   317,   318,   319,   320,   321,
     322,   325,   326
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
  "REPETIR", "SI", "SI_NO", "CADENA", "EN", "EN_US", "ES", "ES_LA", "PT",
  "IT", "FR", "DESPACIO", "DEPRISA", "GRITANDO", "VOZ_BAJA", "MASCULINO",
  "FEMENINO", "CONCATENACION", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "menos", "'\\n'", "'='", "':'", "'('", "')'", "'{'", "','", "'['", "']'",
  "$accept", "salto", "entrada", "linea", "$@1", "$@2", "$@3", "$@4",
  "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13",
  "$@14", "expr_cadena", "expr_log", "expr_arit", "entonacion", "idioma",
  "voz", YY_NULLPTR
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
      61,    58,    40,    41,   123,    44,    91,    93
};
#endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -47,   170,   -47,   -46,   -47,   -47,    23,   -47,   -41,   -31,
     -37,    23,    62,    23,   -29,   -24,   -47,   -47,   -15,   -46,
     -46,   -47,   -47,   -47,    23,    23,    90,   -46,     2,    -2,
      62,   162,    62,   128,   -47,   -47,     5,   121,   128,     2,
     -47,   -47,   -15,   -15,   -47,    47,    23,    23,    23,    23,
      23,   -47,   -15,     2,   -47,   -47,     2,   195,   137,   182,
       5,   -47,   -47,   -47,   -47,    -3,   -39,     5,   -46,    62,
     -46,    62,    31,   137,   -46,   -47,   -47,    26,    26,   -47,
     -47,   -46,   -47,   125,   110,     2,     2,     2,     2,   -46,
      23,    23,    23,    23,    23,    23,   -46,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,     8,   -46,    62,   108,    18,   -46,
     -15,   -47,   128,   -15,   -47,    -1,   -15,   -15,   -47,    15,
       1,   -47,   -47,   -15,   128,   128,   128,   128,   128,   128,
     -15,    -7,   -15,     5,   -47,   -47,   -47,   -47,    62,   -15,
     -47,   -47,   -47,    13,   -46,     5,   -46,   -46,   -15,   -46,
     -15,   -15,   -15
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     1,     0,    10,    12,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     2,    36,     0,
       0,    56,    57,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    38,    37,    21,     0,    20,     0,
      25,     3,    11,    13,    64,     0,     0,     0,     0,     0,
       0,    14,    17,     0,    42,    43,     0,     8,     6,     0,
      30,    66,    67,    68,    69,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,    65,    63,    59,    60,    61,
      62,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,     0,     0,     0,     0,     0,     0,
      19,    39,    41,    22,    40,     0,    26,    15,    47,    44,
      45,    54,    55,     9,    49,    51,    52,    53,    50,    48,
       7,     0,    31,    32,    70,    71,    72,    73,     0,    28,
      23,    81,    82,     0,     0,    34,     0,     0,    33,     0,
      24,    29,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -19,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -28,    32,
      11,   -47,   -47,   -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    18,     1,    16,    96,    89,    19,    20,    81,    27,
      68,    70,   146,    74,   109,   105,   144,   149,    36,    57,
      37,    66,   104,   143
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      42,    43,    60,    17,    67,    21,    22,    85,    52,    28,
      53,    54,    55,    32,    87,    88,   107,    26,   108,    29,
      30,    23,    33,    39,    38,    31,    21,    22,    87,    88,
      40,    46,   141,   142,    41,    44,    45,    85,    86,    58,
      59,   111,    23,   114,    87,    88,    69,    24,   106,   110,
      73,   113,    46,   140,    56,   116,   147,    76,    77,    78,
      79,    80,   117,   131,    73,    21,    22,    84,    24,   138,
     123,    72,    49,    50,     0,    25,     0,   130,   133,     0,
     112,    23,     0,    34,   115,    82,   132,     0,    83,    35,
     139,    47,    48,    49,    50,    46,    73,    73,    73,    73,
      75,   124,   125,   126,   127,   128,   129,    24,     0,     0,
     145,     0,     0,     0,    25,    46,     0,   119,   120,   121,
     122,    90,    91,    92,    93,   148,    46,   150,   151,     0,
     152,    85,    86,    46,    47,    48,    49,    50,    87,    88,
       0,    51,    46,   134,   135,   136,   137,     0,    90,    91,
      92,    93,    94,    95,    47,    48,    49,    50,     0,     0,
       0,     0,    71,    75,     0,    47,    48,    49,    50,     0,
       2,     3,    47,    48,    49,    50,     0,     0,   118,    94,
      95,    47,    48,    49,    50,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    61,    62,    63,
      64,    85,    86,     0,     0,     0,     0,     0,    87,    88,
      97,    98,    99,   100,   101,   102,   103,     0,     0,    65
};

static const yytype_int16 yycheck[] =
{
      19,    20,    30,    49,    32,     3,     4,     6,    27,    50,
       8,     9,    10,    50,    13,    14,    55,     6,    57,    50,
      51,    19,    11,    52,    13,    56,     3,     4,    13,    14,
      54,     5,    39,    40,    49,    24,    25,     6,     7,    28,
      42,    69,    19,    71,    13,    14,    41,    45,    51,    68,
      39,    70,     5,    54,    52,    74,    43,    46,    47,    48,
      49,    50,    81,    55,    53,     3,     4,    56,    45,    51,
      89,    39,    46,    47,    -1,    52,    -1,    96,   106,    -1,
      69,    19,    -1,    21,    53,    53,   105,    -1,    56,    27,
     109,    44,    45,    46,    47,     5,    85,    86,    87,    88,
      53,    90,    91,    92,    93,    94,    95,    45,    -1,    -1,
     138,    -1,    -1,    -1,    52,     5,    -1,    85,    86,    87,
      88,    11,    12,    13,    14,   144,     5,   146,   147,    -1,
     149,     6,     7,     5,    44,    45,    46,    47,    13,    14,
      -1,    51,     5,    35,    36,    37,    38,    -1,    11,    12,
      13,    14,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    41,    53,    -1,    44,    45,    46,    47,    -1,
       0,     1,    44,    45,    46,    47,    -1,    -1,    53,    42,
      43,    44,    45,    46,    47,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    35,    36,    37,
      38,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    60,     0,     1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    61,    49,    59,    64,
      65,     3,     4,    19,    45,    52,    78,    67,    50,    50,
      51,    56,    50,    78,    21,    27,    76,    78,    78,    52,
      54,    49,    59,    59,    78,    78,     5,    44,    45,    46,
      47,    51,    59,     8,     9,    10,    52,    77,    78,    42,
      76,    35,    36,    37,    38,    57,    79,    76,    68,    41,
      69,    41,    77,    78,    71,    53,    78,    78,    78,    78,
      78,    66,    77,    77,    78,     6,     7,    13,    14,    63,
      11,    12,    13,    14,    42,    43,    62,    28,    29,    30,
      31,    32,    33,    34,    80,    73,    51,    55,    57,    72,
      59,    76,    78,    59,    76,    53,    59,    59,    53,    77,
      77,    77,    77,    59,    78,    78,    78,    78,    78,    78,
      59,    55,    59,    76,    35,    36,    37,    38,    51,    59,
      54,    39,    40,    81,    74,    76,    70,    43,    59,    75,
      59,    59,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    62,    61,    63,    61,
      64,    61,    65,    61,    66,    61,    67,    61,    68,    61,
      61,    69,    61,    70,    61,    71,    61,    72,    61,    61,
      73,    61,    74,    61,    75,    61,    61,    76,    76,    76,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    79,    79,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     0,     5,     0,     5,
       0,     3,     0,     3,     0,     5,     0,     3,     0,     4,
       2,     0,     4,     0,     7,     0,     4,     0,     5,     8,
       0,     5,     0,     7,     0,     8,     2,     1,     1,     3,
       3,     3,     1,     1,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     2,     3,     1,     1,     1,     1,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
#line 88 "expresiones.y"
                     {n_lineas++;}
#line 1303 "expresiones.c"
    break;

  case 3: /* salto: salto '\n'  */
#line 89 "expresiones.y"
                    {n_lineas++;}
#line 1309 "expresiones.c"
    break;

  case 6: /* $@1: %empty  */
#line 96 "expresiones.y"
                                   {
                                    if(!errorVariable && !errorSemantico){
                                          if(!ids.isExists((yyvsp[-2].c_identificador)))
                                                ((yyvsp[0].c_expresion_arit).esReal)? ids.add(Info((yyvsp[-2].c_identificador), n_lineas, (yyvsp[0].c_expresion_arit).valor)) : ids.add(Info((yyvsp[-2].c_identificador), n_lineas, (int)(yyvsp[0].c_expresion_arit).valor));
                                          else if((yyvsp[0].c_expresion_arit).esReal && ids.getTipo((yyvsp[-2].c_identificador)) == TIPO::T_REAL)
                                                ids.setValor((yyvsp[-2].c_identificador), (yyvsp[0].c_expresion_arit).valor);
                                          
                                          else if(!(yyvsp[0].c_expresion_arit).esReal && ids.getTipo((yyvsp[-2].c_identificador)) == TIPO::T_ENT)
                                                ids.setValor((yyvsp[-2].c_identificador), (int)(yyvsp[0].c_expresion_arit).valor);                                          
                                          else{

                                                cout << "Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[-2].c_identificador) << " es de tipo ";
                                                
                                                tipo = ids.getTipo((yyvsp[-2].c_identificador)); // averiguamos el tipo de $1, es decir de la variable

                                                switch (tipo) {
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
#line 1348 "expresiones.c"
    break;

  case 8: /* $@2: %empty  */
#line 131 "expresiones.y"
                                     {
                                   
                                    if(!errorVariable && !errorSemantico){
                                          if(!ids.isExists((yyvsp[-2].c_identificador)))
                                                ids.add(Info((yyvsp[-2].c_identificador), n_lineas, (yyvsp[0].c_bool)));
                                          else if(ids.getTipo((yyvsp[-2].c_identificador)) == TIPO::T_BOOL)
                                                ids.setValor((yyvsp[-2].c_identificador), (yyvsp[0].c_bool));
                                          else{

                                                cout << "Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[-2].c_identificador) << " es de tipo ";
                                                
                                                tipo = ids.getTipo((yyvsp[-2].c_identificador)); // averiguamos el tipo de $1, es decir de la variable

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

                                 }
#line 1382 "expresiones.c"
    break;

  case 10: /* $@3: %empty  */
#line 161 "expresiones.y"
                   {cout << "bloque personajes linea " << n_lineas << endl;}
#line 1388 "expresiones.c"
    break;

  case 12: /* $@4: %empty  */
#line 162 "expresiones.y"
                     {cout << "bloque definiciones linea " << n_lineas << endl;}
#line 1394 "expresiones.c"
    break;

  case 14: /* $@5: %empty  */
#line 163 "expresiones.y"
                             {
                                    if(!(yyvsp[-1].c_expresion_arit).esReal){
                                          if((yyvsp[-1].c_expresion_arit).valor > n_escena){
                                                salida << "echo Inicio de la escena " << (yyvsp[-1].c_expresion_arit).valor << endl;
                                                n_escena = (yyvsp[-1].c_expresion_arit).valor;
                                          }
                                          else
                                                cout << "Error semantico en la linea " << n_lineas << ", la escena " << (yyvsp[-1].c_expresion_arit).valor << " no puede ser procesada" <<  endl;
                                    }
                                    else
                                          cout << "Error semantico en la linea " << n_lineas << ", el número de escena debe ser de tipo ENTERO" << endl;
      
      
                              }
#line 1413 "expresiones.c"
    break;

  case 16: /* $@6: %empty  */
#line 177 "expresiones.y"
                  {salida << "echo Fin de la escena " << n_escena << endl; }
#line 1419 "expresiones.c"
    break;

  case 18: /* $@7: %empty  */
#line 178 "expresiones.y"
                        {salida << "sleep " << (yyvsp[0].c_expresion_arit).valor << endl;}
#line 1425 "expresiones.c"
    break;

  case 20: /* linea: REPETIR expr_arit  */
#line 179 "expresiones.y"
                          {cout << "detectado repetir " << (yyvsp[0].c_expresion_arit).valor << " (real=" << (yyvsp[0].c_expresion_arit).esReal << ") linea " << n_lineas << endl;}
#line 1431 "expresiones.c"
    break;

  case 21: /* $@8: %empty  */
#line 180 "expresiones.y"
                             {salida << "echo " << strncpy((yyvsp[0].c_cadena), (yyvsp[0].c_cadena)+1, strlen((yyvsp[0].c_cadena)-2)) << endl;}
#line 1437 "expresiones.c"
    break;

  case 23: /* $@9: %empty  */
#line 181 "expresiones.y"
                                {cout << "detectado si (condicion=" << (yyvsp[-2].c_bool) << ") linea "  << n_lineas << endl;}
#line 1443 "expresiones.c"
    break;

  case 25: /* $@10: %empty  */
#line 182 "expresiones.y"
                  {cout << "detectado si_no linea " << n_lineas << endl;}
#line 1449 "expresiones.c"
    break;

  case 27: /* $@11: %empty  */
#line 184 "expresiones.y"
                                  {cout << "asignacion id_cadena " << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_cadena) << endl;
      
                                     if(!errorVariable && !errorSemantico){
                                          if(!ids.isExists((yyvsp[-2].c_identificador)))
                                                ids.add(Info((yyvsp[-2].c_identificador), n_lineas, (yyvsp[0].c_cadena)));
                                          else if(ids.getTipo((yyvsp[-2].c_identificador)) == TIPO::T_CADENA)
                                                ids.setValor((yyvsp[-2].c_identificador), (yyvsp[0].c_cadena));
                                          else{

                                                cout << "Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[-2].c_identificador) << " es de tipo ";
                                                
                                                tipo = ids.getTipo((yyvsp[-2].c_identificador)); // averiguamos el tipo de $1, es decir de la variable

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
      
      }
#line 1483 "expresiones.c"
    break;

  case 29: /* linea: ID_NOMBRE '=' '<' idioma ',' voz '>' salto  */
#line 214 "expresiones.y"
                                                   { cout << "asignacion nombre " << (yyvsp[-7].c_identificador) << "," << (yyvsp[-4].c_cadena) << "," << (yyvsp[-2].c_cadena) <<  " linea " << n_lineas << endl;}
#line 1489 "expresiones.c"
    break;

  case 30: /* $@12: %empty  */
#line 216 "expresiones.y"
                                                               { cout << "personaje " << " [" << (yyvsp[-2].c_identificador) << "] " << " dice : " << (yyvsp[0].c_cadena) << endl; }
#line 1495 "expresiones.c"
    break;

  case 32: /* $@13: %empty  */
#line 217 "expresiones.y"
                                                               { cout << "personaje " << " [" << (yyvsp[-4].c_identificador) << "] " << " dice : " << (yyvsp[0].c_cadena) << endl; }
#line 1501 "expresiones.c"
    break;

  case 34: /* $@14: %empty  */
#line 218 "expresiones.y"
                                                               { cout << "personaje " << " [" << (yyvsp[-5].c_identificador) << "] " << " dice : " << (yyvsp[0].c_cadena) << " con entonación   " << endl; }
#line 1507 "expresiones.c"
    break;

  case 36: /* linea: error salto  */
#line 221 "expresiones.y"
                     {yyerrok; errorSemantico = false; errorVariable = false;}
#line 1513 "expresiones.c"
    break;

  case 37: /* expr_cadena: CADENA  */
#line 225 "expresiones.y"
                                               {strcpy((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1519 "expresiones.c"
    break;

  case 38: /* expr_cadena: ID_CADENA  */
#line 226 "expresiones.y"
                                               {cout << "id_cadena" << endl; strcpy((yyval.c_cadena), (yyvsp[0].c_identificador));}
#line 1525 "expresiones.c"
    break;

  case 39: /* expr_cadena: expr_cadena CONCATENACION expr_cadena  */
#line 227 "expresiones.y"
                                               {cout << "concatenacion cadena (" << (yyvsp[-2].c_cadena) << ") cadena(" << (yyvsp[0].c_cadena) <<  ")" << endl; strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1531 "expresiones.c"
    break;

  case 40: /* expr_cadena: expr_arit CONCATENACION expr_cadena  */
#line 228 "expresiones.y"
                                               {cout << "concatenacion arit (" << to_string((yyvsp[-2].c_expresion_arit).valor) << ") cadena(" << (yyvsp[0].c_cadena) <<  ")" << endl; strcpy((yyval.c_cadena), ""); strcat((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1537 "expresiones.c"
    break;

  case 41: /* expr_cadena: expr_cadena CONCATENACION expr_arit  */
#line 229 "expresiones.y"
                                               {cout << "concatenacion cadena (" << (yyvsp[-2].c_cadena) << ") arit(" << to_string((yyvsp[0].c_expresion_arit).valor) <<  ")" << endl; strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), "");}
#line 1543 "expresiones.c"
    break;

  case 42: /* expr_log: TRUE  */
#line 232 "expresiones.y"
                                              {(yyval.c_bool) = true; }
#line 1549 "expresiones.c"
    break;

  case 43: /* expr_log: FALSE  */
#line 233 "expresiones.y"
                                              {(yyval.c_bool) = false; }
#line 1555 "expresiones.c"
    break;

  case 44: /* expr_log: expr_log AND expr_log  */
#line 234 "expresiones.y"
                                              {(yyval.c_bool) = (yyvsp[-2].c_bool) and (yyvsp[0].c_bool); }
#line 1561 "expresiones.c"
    break;

  case 45: /* expr_log: expr_log OR expr_log  */
#line 235 "expresiones.y"
                                              {(yyval.c_bool) = (yyvsp[-2].c_bool) or (yyvsp[0].c_bool); }
#line 1567 "expresiones.c"
    break;

  case 46: /* expr_log: NOT expr_log  */
#line 236 "expresiones.y"
                                              {(yyval.c_bool) = (not (yyvsp[0].c_bool)); }
#line 1573 "expresiones.c"
    break;

  case 47: /* expr_log: '(' expr_log ')'  */
#line 237 "expresiones.y"
                                                  {(yyval.c_bool) =     (yyvsp[-1].c_bool); }
#line 1579 "expresiones.c"
    break;

  case 48: /* expr_log: expr_arit '>' expr_arit  */
#line 238 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor > (yyvsp[0].c_expresion_arit).valor)  ? true : false; }
#line 1585 "expresiones.c"
    break;

  case 49: /* expr_log: expr_arit MAYORIGUAL expr_arit  */
#line 239 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor >= (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1591 "expresiones.c"
    break;

  case 50: /* expr_log: expr_arit '<' expr_arit  */
#line 240 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor < (yyvsp[0].c_expresion_arit).valor)  ? true : false; }
#line 1597 "expresiones.c"
    break;

  case 51: /* expr_log: expr_arit MENORIGUAL expr_arit  */
#line 241 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor <= (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1603 "expresiones.c"
    break;

  case 52: /* expr_log: expr_arit IGUAL2 expr_arit  */
#line 242 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor == (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1609 "expresiones.c"
    break;

  case 53: /* expr_log: expr_arit DISTINTO expr_arit  */
#line 243 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor != (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1615 "expresiones.c"
    break;

  case 54: /* expr_log: expr_log IGUAL2 expr_log  */
#line 244 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_bool) == (yyvsp[0].c_bool)) ? true : false; }
#line 1621 "expresiones.c"
    break;

  case 55: /* expr_log: expr_log DISTINTO expr_log  */
#line 245 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_bool) != (yyvsp[0].c_bool)) ? true : false; }
#line 1627 "expresiones.c"
    break;

  case 56: /* expr_arit: NUMERO  */
#line 248 "expresiones.y"
                                                        {(yyval.c_expresion_arit).esReal = false; (yyval.c_expresion_arit).valor = (yyvsp[0].c_entero); }
#line 1633 "expresiones.c"
    break;

  case 57: /* expr_arit: REAL  */
#line 249 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = true;  (yyval.c_expresion_arit).valor = (yyvsp[0].c_real); }
#line 1639 "expresiones.c"
    break;

  case 58: /* expr_arit: ID_GENERAL  */
#line 250 "expresiones.y"
                                         {
                                          if(ids.isExists((yyvsp[0].c_identificador))){
                                                if(ids.getTipo((yyvsp[0].c_identificador)) == TIPO::T_ENT){
                                                      (yyval.c_expresion_arit).esReal = false;
                                                      ids.get((yyvsp[0].c_identificador), info);
                                                      (yyval.c_expresion_arit).valor = info.valor.valor_entero;
                                                }
                                                else if(ids.getTipo((yyvsp[0].c_identificador)) == TIPO::T_REAL){
                                                      (yyval.c_expresion_arit).esReal = true;
                                                      ids.get((yyvsp[0].c_identificador), info);
                                                      (yyval.c_expresion_arit).valor = info.valor.valor_real;
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
#line 1667 "expresiones.c"
    break;

  case 59: /* expr_arit: expr_arit '+' expr_arit  */
#line 273 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor + (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) + int((yyvsp[0].c_expresion_arit).valor); }
#line 1673 "expresiones.c"
    break;

  case 60: /* expr_arit: expr_arit '-' expr_arit  */
#line 274 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor - (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) - int((yyvsp[0].c_expresion_arit).valor); }
#line 1679 "expresiones.c"
    break;

  case 61: /* expr_arit: expr_arit '*' expr_arit  */
#line 275 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor * (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) * int((yyvsp[0].c_expresion_arit).valor); }
#line 1685 "expresiones.c"
    break;

  case 62: /* expr_arit: expr_arit '/' expr_arit  */
#line 277 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = true; 
                                                if((yyvsp[0].c_expresion_arit).valor == 0){ 
                                                      errorSemantico = true; 
                                                      cout << "Error semantico en la linea " << n_lineas << ", se ha detectado una división entre el número 0" << endl;
                                                } 
                                                else 
                                                      (yyval.c_expresion_arit).valor = (yyvsp[-2].c_expresion_arit).valor / (yyvsp[0].c_expresion_arit).valor;
                                              }
#line 1698 "expresiones.c"
    break;

  case 63: /* expr_arit: expr_arit DIV expr_arit  */
#line 286 "expresiones.y"
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
#line 1716 "expresiones.c"
    break;

  case 64: /* expr_arit: '-' expr_arit  */
#line 300 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[0].c_expresion_arit).esReal ; (yyval.c_expresion_arit).valor = ((yyvsp[0].c_expresion_arit).esReal) ? -(yyvsp[0].c_expresion_arit).valor : int(-(yyvsp[0].c_expresion_arit).valor); }
#line 1722 "expresiones.c"
    break;

  case 65: /* expr_arit: '(' expr_arit ')'  */
#line 301 "expresiones.y"
                                                  {(yyval.c_expresion_arit).esReal = (yyvsp[-1].c_expresion_arit).esReal ; (yyval.c_expresion_arit).valor = ((yyvsp[-1].c_expresion_arit).esReal) ?  (yyvsp[-1].c_expresion_arit).valor : int( (yyvsp[-1].c_expresion_arit).valor); }
#line 1728 "expresiones.c"
    break;

  case 66: /* entonacion: DESPACIO  */
#line 305 "expresiones.y"
                                    {cout << "despacio" << endl;}
#line 1734 "expresiones.c"
    break;

  case 67: /* entonacion: DEPRISA  */
#line 306 "expresiones.y"
                                    {cout << "deprisa" << endl;}
#line 1740 "expresiones.c"
    break;

  case 68: /* entonacion: GRITANDO  */
#line 307 "expresiones.y"
                                    {cout << "gritando" << endl;}
#line 1746 "expresiones.c"
    break;

  case 69: /* entonacion: VOZ_BAJA  */
#line 308 "expresiones.y"
                                    {cout << "voz_baja" << endl;}
#line 1752 "expresiones.c"
    break;

  case 70: /* entonacion: entonacion ',' DESPACIO  */
#line 309 "expresiones.y"
                                    {cout << "despacio coma" << endl;}
#line 1758 "expresiones.c"
    break;

  case 71: /* entonacion: entonacion ',' DEPRISA  */
#line 310 "expresiones.y"
                                    {cout << "deprisa coma" << endl;}
#line 1764 "expresiones.c"
    break;

  case 72: /* entonacion: entonacion ',' GRITANDO  */
#line 311 "expresiones.y"
                                    {cout << "gritando coma" << endl;}
#line 1770 "expresiones.c"
    break;

  case 73: /* entonacion: entonacion ',' VOZ_BAJA  */
#line 312 "expresiones.y"
                                    {cout << "voz_baja coma" << endl;}
#line 1776 "expresiones.c"
    break;

  case 74: /* idioma: EN  */
#line 316 "expresiones.y"
                        {strcpy((yyval.c_cadena), "en");}
#line 1782 "expresiones.c"
    break;

  case 75: /* idioma: EN_US  */
#line 317 "expresiones.y"
                        {strcpy((yyval.c_cadena), "en-us");}
#line 1788 "expresiones.c"
    break;

  case 76: /* idioma: ES  */
#line 318 "expresiones.y"
                        {strcpy((yyval.c_cadena), "es");}
#line 1794 "expresiones.c"
    break;

  case 77: /* idioma: ES_LA  */
#line 319 "expresiones.y"
                        {strcpy((yyval.c_cadena), "es-la");}
#line 1800 "expresiones.c"
    break;

  case 78: /* idioma: PT  */
#line 320 "expresiones.y"
                        {strcpy((yyval.c_cadena), "pt");}
#line 1806 "expresiones.c"
    break;

  case 79: /* idioma: IT  */
#line 321 "expresiones.y"
                        {strcpy((yyval.c_cadena), "it");}
#line 1812 "expresiones.c"
    break;

  case 80: /* idioma: FR  */
#line 322 "expresiones.y"
                        {strcpy((yyval.c_cadena), "fr");}
#line 1818 "expresiones.c"
    break;

  case 81: /* voz: MASCULINO  */
#line 325 "expresiones.y"
                        {strcpy((yyval.c_cadena), "m");}
#line 1824 "expresiones.c"
    break;

  case 82: /* voz: FEMENINO  */
#line 326 "expresiones.y"
                        {strcpy((yyval.c_cadena), "f");}
#line 1830 "expresiones.c"
    break;


#line 1834 "expresiones.c"

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

#line 328 "expresiones.y"


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