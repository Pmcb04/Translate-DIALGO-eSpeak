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


#line 109 "expresiones.c"

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
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* ':'  */
  YYSYMBOL_53_ = 53,                       /* '['  */
  YYSYMBOL_54_ = 54,                       /* ']'  */
  YYSYMBOL_55_ = 55,                       /* '('  */
  YYSYMBOL_56_ = 56,                       /* ')'  */
  YYSYMBOL_57_ = 57,                       /* '{'  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_salto = 59,                     /* salto  */
  YYSYMBOL_programa = 60,                  /* programa  */
  YYSYMBOL_bloquePersonajes = 61,          /* bloquePersonajes  */
  YYSYMBOL_62_1 = 62,                      /* $@1  */
  YYSYMBOL_secPersonajes = 63,             /* secPersonajes  */
  YYSYMBOL_64_2 = 64,                      /* $@2  */
  YYSYMBOL_bloqueDefiniciones = 65,        /* bloqueDefiniciones  */
  YYSYMBOL_66_3 = 66,                      /* $@3  */
  YYSYMBOL_secDefiniciones = 67,           /* secDefiniciones  */
  YYSYMBOL_68_4 = 68,                      /* $@4  */
  YYSYMBOL_69_5 = 69,                      /* $@5  */
  YYSYMBOL_70_6 = 70,                      /* $@6  */
  YYSYMBOL_secEscena = 71,                 /* secEscena  */
  YYSYMBOL_72_7 = 72,                      /* $@7  */
  YYSYMBOL_73_8 = 73,                      /* $@8  */
  YYSYMBOL_74_9 = 74,                      /* $@9  */
  YYSYMBOL_75_10 = 75,                     /* $@10  */
  YYSYMBOL_76_11 = 76,                     /* $@11  */
  YYSYMBOL_77_12 = 77,                     /* $@12  */
  YYSYMBOL_78_13 = 78,                     /* $@13  */
  YYSYMBOL_entonacion = 79,                /* entonacion  */
  YYSYMBOL_idioma = 80,                    /* idioma  */
  YYSYMBOL_voz = 81,                       /* voz  */
  YYSYMBOL_expr_cadena = 82,               /* expr_cadena  */
  YYSYMBOL_expr_log = 83,                  /* expr_log  */
  YYSYMBOL_expr_arit = 84                  /* expr_arit  */
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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   334

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

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
      55,    56,    46,    44,    51,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,     2,
      42,    50,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,     2,     2,     2,     2,     2,
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
       0,    99,    99,   100,   102,   103,   104,   107,   108,   108,
     109,   112,   113,   113,   114,   117,   118,   118,   119,   122,
     123,   124,   124,   170,   170,   204,   204,   239,   240,   241,
     241,   255,   255,   256,   256,   257,   257,   258,   258,   259,
     259,   260,   260,   261,   265,   266,   267,   268,   269,   270,
     271,   272,   276,   277,   278,   279,   280,   281,   282,   285,
     286,   298,   299,   300,   301,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   320,
     321,   322,   345,   346,   347,   349,   358,   372,   373
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
  "menos", "'\\n'", "'='", "','", "':'", "'['", "']'", "'('", "')'", "'{'",
  "$accept", "salto", "programa", "bloquePersonajes", "$@1",
  "secPersonajes", "$@2", "bloqueDefiniciones", "$@3", "secDefiniciones",
  "$@4", "$@5", "$@6", "secEscena", "$@7", "$@8", "$@9", "$@10", "$@11",
  "$@12", "$@13", "entonacion", "idioma", "voz", "expr_cadena", "expr_log",
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
      61,    44,    58,    91,    93,    40,    41,   123
};
#endif

#define YYPACT_NINF (-97)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-20)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     127,   -46,   -97,   -20,   -97,   199,    16,   279,   -97,   -17,
     -46,    -7,   -97,   279,   -97,   -46,   -97,   -10,     6,   311,
     -97,   199,   285,   311,   -17,   -46,     2,    15,   -46,    19,
     -97,   -27,    19,    15,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -18,   -97,   207,   -97,   -97,     2,
     -97,   -97,   -97,    19,     2,    52,   231,   -97,   -97,    19,
      20,    73,   -17,   126,   -46,    15,   229,    73,    20,   -11,
     -97,   -97,   231,   -97,    96,    39,     2,     2,     2,     2,
     -46,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,   -46,    43,    15,   -46,   -97,   232,    20,   -97,
     -97,   -97,   -97,    -3,   -34,   -46,   -46,   -97,   -97,     0,
     -97,   -97,    32,    63,   -97,   -97,   240,   -97,    73,    73,
      73,    73,    73,    73,     8,     8,   -97,   -97,   240,   -97,
     240,   -46,   -97,   -46,    15,   144,    21,   232,   232,   -46,
     -97,   -97,   -97,   232,   232,    20,   -97,   -97,   -97,   -97,
      15,   -97,   -97,   -17,   -97,   -97,   -46,    20,   287,   232,
     -46,   -97,   -97,   232,   -97
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     8,     0,     2,     0,     0,     0,    10,    14,
       0,     0,     3,     0,     1,     0,    16,     0,     0,     0,
      18,     0,     0,     0,    20,     0,     0,     0,     0,     0,
      31,     0,     0,     0,    43,     6,     9,    52,    53,    54,
      55,    56,    57,    58,     0,     5,     0,    79,    80,     0,
      65,    66,    81,     0,     0,    23,    21,    62,    61,     0,
      25,    63,    20,     0,     0,     0,     0,    41,    39,     0,
      17,    69,     0,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,    33,    44,
      45,    46,    47,     0,     0,     0,     0,    59,    60,     0,
      70,    88,    67,    68,    77,    78,     0,    86,    72,    74,
      75,    76,    73,    71,    82,    83,    84,    85,     0,    64,
       0,     0,    32,     0,     0,     0,     0,     0,     0,     0,
      24,    22,    26,     0,     0,    35,    48,    49,    50,    51,
       0,    42,    40,    12,    30,    34,     0,    37,     0,     0,
       0,    13,    36,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -97,    -1,   -97,    10,   -97,   -96,   -97,    -9,   -97,    -5,
     -97,   -97,   -97,   -22,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -26,    86,   107
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,    10,     8,   158,    19,    25,    34,
      92,    80,    95,    35,   131,    64,   133,   156,   160,   106,
     105,   104,    44,   109,    60,    55,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    45,    20,     4,    23,    47,    48,    68,    20,    21,
      49,    50,    51,    81,    24,    13,    14,   135,    47,    48,
     136,    52,    47,    48,    46,    65,    66,    62,   107,   108,
      11,    36,    12,    69,    52,    22,    57,    70,    52,    98,
      26,    20,    58,   139,    81,    78,    79,    53,    81,   134,
      82,    83,    84,    85,    90,    91,    27,    54,    76,    77,
      53,    94,   161,    97,    53,    78,    79,     0,   129,    76,
      59,     0,     0,   150,    59,   132,    78,    79,    81,   116,
       0,    86,    87,    88,    89,    90,    91,    88,    89,    90,
      91,   128,     0,     0,   130,   111,     0,     0,     0,   111,
       0,     0,    76,    77,   137,   138,     0,     0,   145,    78,
      79,   140,     0,     0,     0,   151,   152,    88,    89,    90,
      91,   154,   155,   141,   157,   142,     0,    -4,     1,     0,
     143,    81,   144,    56,     0,    71,    63,   162,   153,    67,
      74,   164,     2,    -7,    -7,    -7,    -7,     3,    -7,    -7,
      -7,     0,   110,     0,     0,   159,    72,     0,     0,   163,
      73,    75,   112,   113,   114,   115,    93,     0,     0,     0,
      88,    89,    90,    91,     0,     0,     4,     0,    96,   146,
     147,   148,   149,    72,    72,    72,    72,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -7,
       1,     0,     0,     0,     0,     0,     0,   -15,    15,     0,
       0,     0,     0,     0,     2,    -7,    -7,    -7,    -7,     3,
      -7,    -7,    -7,    16,   -15,   -15,    17,   -15,    18,   -15,
     -15,     0,   -19,    28,     0,     0,    81,     0,     0,     0,
     -19,    15,    82,    83,    84,    85,     0,     0,    12,    29,
      30,    17,    31,    18,    32,    33,    12,   -19,   -19,    17,
     -19,    18,   -19,   -19,    99,   100,   101,   102,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,    91,   -15,
      15,    12,     0,   103,     0,     0,     0,   -11,     1,    12,
       0,     0,     0,     0,     0,    16,   -15,   -15,    17,   -15,
      18,   -15,   -15,   -11,   -11,   -11,   -11,     3,   -11,   -11,
     -11,   -19,    28,    37,    38,    39,    40,    41,    42,    43,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    30,
      17,    31,    18,    32,    33
};

static const yytype_int16 yycheck[] =
{
       1,    23,     7,    49,    13,     3,     4,    33,    13,    10,
       8,     9,    10,     5,    15,     5,     0,    51,     3,     4,
      54,    19,     3,     4,    25,    52,    53,    28,    39,    40,
      50,    21,    49,    51,    19,    42,    21,    46,    19,    65,
      50,    46,    27,    43,     5,    13,    14,    45,     5,    52,
      11,    12,    13,    14,    46,    47,    50,    55,     6,     7,
      45,    41,   158,    64,    45,    13,    14,    -1,    94,     6,
      55,    -1,    -1,    52,    55,    97,    13,    14,     5,    80,
      -1,    42,    43,    44,    45,    46,    47,    44,    45,    46,
      47,    92,    -1,    -1,    95,    56,    -1,    -1,    -1,    56,
      -1,    -1,     6,     7,   105,   106,    -1,    -1,   134,    13,
      14,   116,    -1,    -1,    -1,   137,   138,    44,    45,    46,
      47,   143,   144,   128,   150,   130,    -1,     0,     1,    -1,
     131,     5,   133,    26,    -1,    49,    29,   159,   139,    32,
      54,   163,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    56,    -1,    -1,   156,    49,    -1,    -1,   160,
      53,    54,    76,    77,    78,    79,    59,    -1,    -1,    -1,
      44,    45,    46,    47,    -1,    -1,    49,    -1,    52,    35,
      36,    37,    38,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,     0,     1,    -1,    -1,     5,    -1,    -1,    -1,
       0,     1,    11,    12,    13,    14,    -1,    -1,    49,    17,
      18,    19,    20,    21,    22,    23,    49,    17,    18,    19,
      20,    21,    22,    23,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,     0,
       1,    49,    -1,    54,    -1,    -1,    -1,     0,     1,    49,
      -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    16,    17,    18,    19,    20,    21,    22,
      23,     0,     1,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    15,    20,    49,    59,    60,    61,    63,    59,
      62,    50,    49,    61,     0,     1,    16,    19,    21,    65,
      67,    59,    42,    65,    59,    66,    50,    50,     1,    17,
      18,    20,    22,    23,    67,    71,    61,    28,    29,    30,
      31,    32,    33,    34,    80,    71,    59,     3,     4,     8,
       9,    10,    19,    45,    55,    83,    84,    21,    27,    55,
      82,    84,    59,    84,    73,    52,    53,    84,    82,    51,
      65,    83,    84,    84,    83,    84,     6,     7,    13,    14,
      69,     5,    11,    12,    13,    14,    42,    43,    44,    45,
      46,    47,    68,    84,    41,    70,    52,    59,    82,    35,
      36,    37,    38,    54,    79,    78,    77,    39,    40,    81,
      56,    56,    83,    83,    83,    83,    59,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    59,    82,
      59,    72,    71,    74,    52,    51,    54,    59,    59,    43,
      67,    67,    67,    59,    59,    82,    35,    36,    37,    38,
      52,    71,    71,    59,    71,    71,    75,    82,    64,    59,
      76,    63,    71,    59,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    60,    61,    62,    61,
      61,    63,    64,    63,    63,    65,    66,    65,    65,    67,
      67,    68,    67,    69,    67,    70,    67,    71,    71,    72,
      71,    73,    71,    74,    71,    75,    71,    76,    71,    77,
      71,    78,    71,    71,    79,    79,    79,    79,    79,    79,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    82,    82,    82,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     3,     0,     0,     4,
       1,     0,     0,    10,     2,     0,     0,     4,     1,     0,
       2,     0,     6,     0,     6,     0,     6,     0,     2,     0,
       6,     0,     4,     0,     6,     0,     8,     0,     9,     0,
       5,     0,     5,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     3,     2,
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
#line 99 "expresiones.y"
                     {n_lineas++;}
#line 1335 "expresiones.c"
    break;

  case 3: /* salto: salto '\n'  */
#line 100 "expresiones.y"
                    {n_lineas++;}
#line 1341 "expresiones.c"
    break;

  case 8: /* $@1: %empty  */
#line 108 "expresiones.y"
                   {cout << "+++ bloque personajes linea " << n_lineas << endl;}
#line 1347 "expresiones.c"
    break;

  case 12: /* $@2: %empty  */
#line 113 "expresiones.y"
                                                   { cout << "-------- asignacion nombre " << (yyvsp[-7].c_identificador) << "," << (yyvsp[-4].c_cadena) << "," << (yyvsp[-2].c_cadena) <<  " linea " << n_lineas << endl;}
#line 1353 "expresiones.c"
    break;

  case 14: /* secPersonajes: error salto  */
#line 114 "expresiones.y"
                     {yyerrok; errorSemantico = false; errorVariable = false;}
#line 1359 "expresiones.c"
    break;

  case 16: /* $@3: %empty  */
#line 118 "expresiones.y"
                     {cout << "+++ bloque definiciones linea " << n_lineas << endl;}
#line 1365 "expresiones.c"
    break;

  case 20: /* secDefiniciones: error salto  */
#line 123 "expresiones.y"
                     {yyerrok; errorSemantico = false; errorVariable = false;}
#line 1371 "expresiones.c"
    break;

  case 21: /* $@4: %empty  */
#line 124 "expresiones.y"
                                    {
                                    if(!errorVariable && !errorSemantico){
                                          if(!ids.isExists((yyvsp[-2].c_identificador)))
                                                if((yyvsp[0].c_expresion_arit).esReal){
                                                      ids.add(Info((yyvsp[-2].c_identificador), n_lineas, (yyvsp[0].c_expresion_arit).valor));
                                                      cout << "-------- asignacion id_general real " << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_expresion_arit).valor << endl;     
                                                } else{
                                                      ids.add(Info((yyvsp[-2].c_identificador), n_lineas, (int)(yyvsp[0].c_expresion_arit).valor)); 
                                                      cout << "-------- asignacion id_general entero " << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_expresion_arit).valor << endl;     
                                                } 
                                                      
                                          else if((yyvsp[0].c_expresion_arit).esReal && ids.getTipo((yyvsp[-2].c_identificador)) == TIPO::T_REAL){
                                                ids.setValor((yyvsp[-2].c_identificador), (yyvsp[0].c_expresion_arit).valor);
                                                cout << "-------- actualizacion valor asignacion id_general real" << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_expresion_arit).valor << endl;     
                                          }
                                          
                                          else if(!(yyvsp[0].c_expresion_arit).esReal && ids.getTipo((yyvsp[-2].c_identificador)) == TIPO::T_ENT){
                                                ids.setValor((yyvsp[-2].c_identificador), (int)(yyvsp[0].c_expresion_arit).valor);                                          
                                                cout << "-------- actualizacion valor asignacion id_general entero" << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_expresion_arit).valor << endl;     
                                          }
                                          else{

                                                cout << "********** Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[-2].c_identificador) << " es de tipo ";
                                                
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
#line 1421 "expresiones.c"
    break;

  case 23: /* $@5: %empty  */
#line 170 "expresiones.y"
                                     {
                                   
                                    if(!errorVariable && !errorSemantico){
                                          if(!ids.isExists((yyvsp[-2].c_identificador))){
                                                ids.add(Info((yyvsp[-2].c_identificador), n_lineas, (yyvsp[0].c_bool)));
                                                cout << "-------- asignacion id_general logico" << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_bool) << endl;     
                                          }
                                          else if(ids.getTipo((yyvsp[-2].c_identificador)) == TIPO::T_BOOL){
                                                ids.setValor((yyvsp[-2].c_identificador), (yyvsp[0].c_bool));
                                                cout << "-------- actualizacion valor asignacion id_general logico" << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_bool) << endl;     
                                          }
                                          else{

                                                cout << "********** Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[-2].c_identificador) << " es de tipo ";
                                                
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
#line 1459 "expresiones.c"
    break;

  case 25: /* $@6: %empty  */
#line 204 "expresiones.y"
                                  {
      
                                     if(!errorVariable && !errorSemantico){
                                          if(!ids.isExists((yyvsp[-2].c_identificador))){
                                                ids.add(Info((yyvsp[-2].c_identificador), n_lineas, (yyvsp[0].c_cadena)));
                                                cout << "-------- asignacion id_cadena " << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_cadena) << endl;     
                                          }
                                          else if(ids.getTipo((yyvsp[-2].c_identificador)) == TIPO::T_CADENA){
                                                ids.setValor((yyvsp[-2].c_identificador), (yyvsp[0].c_cadena));
                                                cout << "-------- actualizacion valor asignacion id_cadena " << (yyvsp[-2].c_identificador) <<  ", " << (yyvsp[0].c_cadena) << endl;     
                                          }
                                          else{

                                                cout << "********** Error semantico en la linea " << n_lineas << ", la variable " << (yyvsp[-2].c_identificador) << " es de tipo ";
                                                
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
#line 1497 "expresiones.c"
    break;

  case 28: /* secEscena: error salto  */
#line 240 "expresiones.y"
                     {yyerrok; errorSemantico = false; errorVariable = false;}
#line 1503 "expresiones.c"
    break;

  case 29: /* $@7: %empty  */
#line 241 "expresiones.y"
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

  case 31: /* $@8: %empty  */
#line 255 "expresiones.y"
                  {cout << "+++ Fin de la escena " << n_escena << endl; }
#line 1528 "expresiones.c"
    break;

  case 33: /* $@9: %empty  */
#line 256 "expresiones.y"
                                                               { cout << "-------- personaje " << " [" << (yyvsp[-2].c_identificador) << "] "  << " en linea " << n_lineas << " dice : " << (yyvsp[0].c_cadena) << endl; }
#line 1534 "expresiones.c"
    break;

  case 35: /* $@10: %empty  */
#line 257 "expresiones.y"
                                                               { cout << "-------- personaje " << " [" << (yyvsp[-4].c_identificador) << "] "  << " en linea " << n_lineas << " dice :      " << (yyvsp[0].c_cadena) << endl; }
#line 1540 "expresiones.c"
    break;

  case 37: /* $@11: %empty  */
#line 258 "expresiones.y"
                                                               { cout << "-------- personaje " << " [" << (yyvsp[-5].c_identificador) << "] " << " en linea " << n_lineas << " dice : " << (yyvsp[0].c_cadena) << " con entonación   " << (yyvsp[-3].c_cadena) << endl; }
#line 1546 "expresiones.c"
    break;

  case 39: /* $@12: %empty  */
#line 259 "expresiones.y"
                             {cout << "-------- mensaje " << strncpy((yyvsp[0].c_cadena), (yyvsp[0].c_cadena)+1, strlen((yyvsp[0].c_cadena)-2)) << endl;}
#line 1552 "expresiones.c"
    break;

  case 41: /* $@13: %empty  */
#line 260 "expresiones.y"
                        {cout << "-------- pausa " << (yyvsp[0].c_expresion_arit).valor << endl;}
#line 1558 "expresiones.c"
    break;

  case 44: /* entonacion: DESPACIO  */
#line 265 "expresiones.y"
                                    {strcpy((yyval.c_cadena), "despacio");}
#line 1564 "expresiones.c"
    break;

  case 45: /* entonacion: DEPRISA  */
#line 266 "expresiones.y"
                                    {strcpy((yyval.c_cadena), "deprisa");}
#line 1570 "expresiones.c"
    break;

  case 46: /* entonacion: GRITANDO  */
#line 267 "expresiones.y"
                                    {strcpy((yyval.c_cadena), "gritando");}
#line 1576 "expresiones.c"
    break;

  case 47: /* entonacion: VOZ_BAJA  */
#line 268 "expresiones.y"
                                    {strcpy((yyval.c_cadena), "voz baja");}
#line 1582 "expresiones.c"
    break;

  case 48: /* entonacion: entonacion ',' DESPACIO  */
#line 269 "expresiones.y"
                                    {strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), ","); strcat((yyval.c_cadena), "despacio");}
#line 1588 "expresiones.c"
    break;

  case 49: /* entonacion: entonacion ',' DEPRISA  */
#line 270 "expresiones.y"
                                    {strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), ","); strcat((yyval.c_cadena), "deprisa");}
#line 1594 "expresiones.c"
    break;

  case 50: /* entonacion: entonacion ',' GRITANDO  */
#line 271 "expresiones.y"
                                    {strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), ","); strcat((yyval.c_cadena), "gritando");}
#line 1600 "expresiones.c"
    break;

  case 51: /* entonacion: entonacion ',' VOZ_BAJA  */
#line 272 "expresiones.y"
                                    {strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), ","); strcat((yyval.c_cadena), "voz baja");}
#line 1606 "expresiones.c"
    break;

  case 52: /* idioma: EN  */
#line 276 "expresiones.y"
                        {strcpy((yyval.c_cadena), "en");}
#line 1612 "expresiones.c"
    break;

  case 53: /* idioma: EN_US  */
#line 277 "expresiones.y"
                        {strcpy((yyval.c_cadena), "en-us");}
#line 1618 "expresiones.c"
    break;

  case 54: /* idioma: ES  */
#line 278 "expresiones.y"
                        {strcpy((yyval.c_cadena), "es");}
#line 1624 "expresiones.c"
    break;

  case 55: /* idioma: ES_LA  */
#line 279 "expresiones.y"
                        {strcpy((yyval.c_cadena), "es-la");}
#line 1630 "expresiones.c"
    break;

  case 56: /* idioma: PT  */
#line 280 "expresiones.y"
                        {strcpy((yyval.c_cadena), "pt");}
#line 1636 "expresiones.c"
    break;

  case 57: /* idioma: IT  */
#line 281 "expresiones.y"
                        {strcpy((yyval.c_cadena), "it");}
#line 1642 "expresiones.c"
    break;

  case 58: /* idioma: FR  */
#line 282 "expresiones.y"
                        {strcpy((yyval.c_cadena), "fr");}
#line 1648 "expresiones.c"
    break;

  case 59: /* voz: MASCULINO  */
#line 285 "expresiones.y"
                        {strcpy((yyval.c_cadena), "m");}
#line 1654 "expresiones.c"
    break;

  case 60: /* voz: FEMENINO  */
#line 286 "expresiones.y"
                        {strcpy((yyval.c_cadena), "f");}
#line 1660 "expresiones.c"
    break;

  case 61: /* expr_cadena: CADENA  */
#line 298 "expresiones.y"
                                               {strcpy((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1666 "expresiones.c"
    break;

  case 62: /* expr_cadena: ID_CADENA  */
#line 299 "expresiones.y"
                                               {strcpy((yyval.c_cadena), (yyvsp[0].c_identificador));}
#line 1672 "expresiones.c"
    break;

  case 63: /* expr_cadena: expr_arit  */
#line 300 "expresiones.y"
                                               {sprintf((yyval.c_cadena), "%f", (yyvsp[0].c_expresion_arit).valor);}
#line 1678 "expresiones.c"
    break;

  case 64: /* expr_cadena: expr_cadena CONCATENACION expr_cadena  */
#line 301 "expresiones.y"
                                               {cout << "-------- concatenacion cadena (" << (yyvsp[-2].c_cadena) << ") cadena(" << (yyvsp[0].c_cadena) <<  ")" << endl; strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1684 "expresiones.c"
    break;

  case 65: /* expr_log: TRUE  */
#line 304 "expresiones.y"
                                              {(yyval.c_bool) = true; }
#line 1690 "expresiones.c"
    break;

  case 66: /* expr_log: FALSE  */
#line 305 "expresiones.y"
                                              {(yyval.c_bool) = false; }
#line 1696 "expresiones.c"
    break;

  case 67: /* expr_log: expr_log AND expr_log  */
#line 306 "expresiones.y"
                                              {(yyval.c_bool) = (yyvsp[-2].c_bool) and (yyvsp[0].c_bool); }
#line 1702 "expresiones.c"
    break;

  case 68: /* expr_log: expr_log OR expr_log  */
#line 307 "expresiones.y"
                                              {(yyval.c_bool) = (yyvsp[-2].c_bool) or (yyvsp[0].c_bool); }
#line 1708 "expresiones.c"
    break;

  case 69: /* expr_log: NOT expr_log  */
#line 308 "expresiones.y"
                                              {(yyval.c_bool) = (not (yyvsp[0].c_bool)); }
#line 1714 "expresiones.c"
    break;

  case 70: /* expr_log: '(' expr_log ')'  */
#line 309 "expresiones.y"
                                                  {(yyval.c_bool) =     (yyvsp[-1].c_bool); }
#line 1720 "expresiones.c"
    break;

  case 71: /* expr_log: expr_arit '>' expr_arit  */
#line 310 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor > (yyvsp[0].c_expresion_arit).valor)  ? true : false; }
#line 1726 "expresiones.c"
    break;

  case 72: /* expr_log: expr_arit MAYORIGUAL expr_arit  */
#line 311 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor >= (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1732 "expresiones.c"
    break;

  case 73: /* expr_log: expr_arit '<' expr_arit  */
#line 312 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor < (yyvsp[0].c_expresion_arit).valor)  ? true : false; }
#line 1738 "expresiones.c"
    break;

  case 74: /* expr_log: expr_arit MENORIGUAL expr_arit  */
#line 313 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor <= (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1744 "expresiones.c"
    break;

  case 75: /* expr_log: expr_arit IGUAL2 expr_arit  */
#line 314 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor == (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1750 "expresiones.c"
    break;

  case 76: /* expr_log: expr_arit DISTINTO expr_arit  */
#line 315 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor != (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1756 "expresiones.c"
    break;

  case 77: /* expr_log: expr_log IGUAL2 expr_log  */
#line 316 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_bool) == (yyvsp[0].c_bool)) ? true : false; }
#line 1762 "expresiones.c"
    break;

  case 78: /* expr_log: expr_log DISTINTO expr_log  */
#line 317 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_bool) != (yyvsp[0].c_bool)) ? true : false; }
#line 1768 "expresiones.c"
    break;

  case 79: /* expr_arit: NUMERO  */
#line 320 "expresiones.y"
                                                        {(yyval.c_expresion_arit).esReal = false; (yyval.c_expresion_arit).valor = (yyvsp[0].c_entero); }
#line 1774 "expresiones.c"
    break;

  case 80: /* expr_arit: REAL  */
#line 321 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = true;  (yyval.c_expresion_arit).valor = (yyvsp[0].c_real); }
#line 1780 "expresiones.c"
    break;

  case 81: /* expr_arit: ID_GENERAL  */
#line 322 "expresiones.y"
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
#line 1808 "expresiones.c"
    break;

  case 82: /* expr_arit: expr_arit '+' expr_arit  */
#line 345 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor + (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) + int((yyvsp[0].c_expresion_arit).valor); }
#line 1814 "expresiones.c"
    break;

  case 83: /* expr_arit: expr_arit '-' expr_arit  */
#line 346 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor - (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) - int((yyvsp[0].c_expresion_arit).valor); }
#line 1820 "expresiones.c"
    break;

  case 84: /* expr_arit: expr_arit '*' expr_arit  */
#line 347 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor * (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) * int((yyvsp[0].c_expresion_arit).valor); }
#line 1826 "expresiones.c"
    break;

  case 85: /* expr_arit: expr_arit '/' expr_arit  */
#line 349 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = true; 
                                                if((yyvsp[0].c_expresion_arit).valor == 0){ 
                                                      errorSemantico = true; 
                                                      cout << "Error semantico en la linea " << n_lineas << ", se ha detectado una división entre el número 0" << endl;
                                                } 
                                                else 
                                                      (yyval.c_expresion_arit).valor = (yyvsp[-2].c_expresion_arit).valor / (yyvsp[0].c_expresion_arit).valor;
                                              }
#line 1839 "expresiones.c"
    break;

  case 86: /* expr_arit: expr_arit DIV expr_arit  */
#line 358 "expresiones.y"
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
#line 1857 "expresiones.c"
    break;

  case 87: /* expr_arit: '-' expr_arit  */
#line 372 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[0].c_expresion_arit).esReal ; (yyval.c_expresion_arit).valor = ((yyvsp[0].c_expresion_arit).esReal) ? -(yyvsp[0].c_expresion_arit).valor : int(-(yyvsp[0].c_expresion_arit).valor); }
#line 1863 "expresiones.c"
    break;

  case 88: /* expr_arit: '(' expr_arit ')'  */
#line 373 "expresiones.y"
                                                  {(yyval.c_expresion_arit).esReal = (yyvsp[-1].c_expresion_arit).esReal ; (yyval.c_expresion_arit).valor = ((yyvsp[-1].c_expresion_arit).esReal) ?  (yyvsp[-1].c_expresion_arit).valor : int( (yyvsp[-1].c_expresion_arit).valor); }
#line 1869 "expresiones.c"
    break;


#line 1873 "expresiones.c"

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

#line 375 "expresiones.y"


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
                        salida.open(outfileName + ".sh");
                  
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
