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


#line 112 "expresiones.c"

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
  YYSYMBOL_39_ = 39,                       /* '<'  */
  YYSYMBOL_40_ = 40,                       /* '>'  */
  YYSYMBOL_41_ = 41,                       /* '+'  */
  YYSYMBOL_42_ = 42,                       /* '-'  */
  YYSYMBOL_43_ = 43,                       /* '*'  */
  YYSYMBOL_44_ = 44,                       /* '/'  */
  YYSYMBOL_menos = 45,                     /* menos  */
  YYSYMBOL_46_n_ = 46,                     /* '\n'  */
  YYSYMBOL_47_ = 47,                       /* '='  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_49_ = 49,                       /* ':'  */
  YYSYMBOL_50_ = 50,                       /* '['  */
  YYSYMBOL_51_ = 51,                       /* ']'  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_salto = 55,                     /* salto  */
  YYSYMBOL_programa = 56,                  /* programa  */
  YYSYMBOL_bloquePersonajes = 57,          /* bloquePersonajes  */
  YYSYMBOL_58_1 = 58,                      /* $@1  */
  YYSYMBOL_59_2 = 59,                      /* $@2  */
  YYSYMBOL_bloqueDefiniciones = 60,        /* bloqueDefiniciones  */
  YYSYMBOL_61_3 = 61,                      /* $@3  */
  YYSYMBOL_62_4 = 62,                      /* $@4  */
  YYSYMBOL_63_5 = 63,                      /* $@5  */
  YYSYMBOL_64_6 = 64,                      /* $@6  */
  YYSYMBOL_secEscena = 65,                 /* secEscena  */
  YYSYMBOL_66_7 = 66,                      /* $@7  */
  YYSYMBOL_67_8 = 67,                      /* $@8  */
  YYSYMBOL_68_9 = 68,                      /* $@9  */
  YYSYMBOL_69_10 = 69,                     /* $@10  */
  YYSYMBOL_70_11 = 70,                     /* $@11  */
  YYSYMBOL_71_12 = 71,                     /* $@12  */
  YYSYMBOL_72_13 = 72,                     /* $@13  */
  YYSYMBOL_entonacion = 73,                /* entonacion  */
  YYSYMBOL_idioma = 74,                    /* idioma  */
  YYSYMBOL_voz = 75,                       /* voz  */
  YYSYMBOL_expr_cadena = 76,               /* expr_cadena  */
  YYSYMBOL_expr_log = 77,                  /* expr_log  */
  YYSYMBOL_expr_arit = 78                  /* expr_arit  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      46,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      52,    53,    43,    41,    48,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,     2,
      39,    47,    40,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   102,   102,   103,   106,   107,   108,   111,   112,   112,
     113,   113,   118,   119,   119,   120,   121,   121,   167,   167,
     201,   201,   236,   237,   237,   251,   251,   252,   252,   253,
     253,   254,   254,   255,   255,   256,   256,   257,   261,   262,
     263,   264,   265,   266,   267,   268,   272,   273,   274,   275,
     276,   277,   278,   281,   282,   286,   287,   288,   289,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   308,   309,   310,   333,   334,   335,   337,
     346,   360,   361
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
  "CONCATENACION", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "menos",
  "'\\n'", "'='", "','", "':'", "'['", "']'", "'('", "')'", "$accept",
  "salto", "programa", "bloquePersonajes", "$@1", "$@2",
  "bloqueDefiniciones", "$@3", "$@4", "$@5", "$@6", "secEscena", "$@7",
  "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "entonacion", "idioma",
  "voz", "expr_cadena", "expr_log", "expr_arit", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    60,
      62,    43,    45,    42,    47,   294,    10,    61,    44,    58,
      91,    93,    40,    41
};
#endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-13)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      39,   -47,   -46,   -47,    47,     8,   209,   -34,   -18,   -47,
     209,   -47,   -34,   -47,   -33,   -21,   238,    47,   237,   238,
       3,   -34,    14,     6,    28,   -47,   -30,    28,     6,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,     9,
     -47,   169,   -47,   -47,    14,   -47,   -47,   -47,    28,    14,
      58,   206,   -47,   -47,    28,    13,    45,    56,   -34,     6,
     100,    45,    13,    42,   -47,   -47,   206,   -47,    22,   163,
      14,    14,    14,    14,   -34,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,   -34,    -1,     6,   -34,
     -47,   178,    13,   -47,   -47,   -47,   -47,    19,    25,   -34,
     -34,   -47,   -47,    34,   -47,   -47,    24,    77,   -47,   -47,
     169,   -47,    45,    45,    45,    45,    45,    45,     1,     1,
     -47,   -47,   169,   -47,   169,   -34,   -47,   -34,     6,    78,
      33,   178,   178,   -34,   -47,   -47,   -47,   178,   178,    13,
     -47,   -47,   -47,   -47,     6,   -47,   -47,     3,   -47,   -47,
     -34,    13,    40,   178,   -34,   -47,   -47,   178,   -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     8,     0,     2,     7,     0,     0,     0,     0,     3,
       0,     1,     0,    13,     0,     0,     0,     7,     0,     0,
      15,     0,     0,     0,     0,    25,     0,     0,     0,    37,
       6,     9,    46,    47,    48,    49,    50,    51,    52,     0,
       5,     0,    73,    74,     0,    59,    60,    75,     0,     0,
      18,    16,    56,    55,     0,    20,    57,     0,     0,     0,
       0,    35,    33,     0,    14,    63,     0,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,     0,    27,    38,    39,    40,    41,     0,     0,     0,
       0,    53,    54,     0,    64,    82,    61,    62,    71,    72,
       0,    80,    66,    68,    69,    70,    67,    65,    76,    77,
      78,    79,     0,    58,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,    19,    17,    21,     0,     0,    29,
      42,    43,    44,    45,     0,    36,    34,    10,    24,    28,
       0,    31,     7,     0,     0,    11,    30,     0,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,    -5,   -47,    -4,   -47,   -47,     5,   -47,   -47,   -47,
     -47,   -14,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -25,   164,    82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,     7,   152,    29,    21,    86,    74,
      89,    30,   125,    58,   127,   150,   154,   100,    99,    98,
      39,   103,    55,    50,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,     8,    17,    62,    75,    40,    75,    20,    11,    42,
      43,    16,     3,    31,    22,    19,    41,    42,    43,    59,
      60,    18,    44,    45,    46,    47,    23,    52,    70,    71,
      53,    42,    43,    47,    92,    72,    73,    72,    73,    -4,
      82,    83,    84,    85,    84,    85,    64,    47,    48,     9,
      75,    88,   105,    91,     1,     1,    48,    63,    54,     2,
       2,    75,     1,   123,    70,    71,    49,     2,   128,   110,
      48,    72,    73,   129,   133,   104,   130,   126,   101,   102,
      54,   122,   144,    70,   124,     3,    82,    83,    84,    85,
      72,    73,     0,     9,   131,   132,     0,    82,    83,    84,
      85,     0,     0,   139,    51,    90,    57,     0,     0,    61,
     140,   141,   142,   143,     0,   134,     0,   145,   146,   151,
     137,     0,   138,   148,   149,     0,    66,   135,   147,   136,
      67,    69,    93,    94,    95,    96,    87,     0,     0,   156,
       0,     0,     0,   158,     0,   153,     0,     0,   155,   157,
       0,    97,    66,    66,    66,    66,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    75,   -12,
      12,     0,     0,     0,    76,    77,    78,    79,   -12,    12,
       0,     0,     0,     0,     0,    13,   -12,   -12,    14,   -12,
      15,   -12,   -12,     0,    13,    24,    25,    14,    26,    15,
      27,    28,    80,    81,    82,    83,    84,    85,    65,   -12,
      12,    75,     0,    68,     0,     9,   105,    76,    77,    78,
      79,     0,     0,     0,     9,    13,   -12,   -12,    14,   -12,
      15,   -12,   -12,     0,   106,   107,   108,   109,   -12,    12,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,     0,     0,     0,    13,    24,    25,    14,    26,    15,
      27,    28,    32,    33,    34,    35,    36,    37,    38
};

static const yytype_int16 yycheck[] =
{
       4,    47,     7,    28,     5,    19,     5,    12,     0,     3,
       4,     6,    46,    17,    47,    10,    21,     3,     4,    49,
      50,    39,     8,     9,    10,    19,    47,    21,     6,     7,
      24,     3,     4,    19,    59,    13,    14,    13,    14,     0,
      41,    42,    43,    44,    43,    44,    41,    19,    42,    46,
       5,    38,    53,    58,    15,    15,    42,    48,    52,    20,
      20,     5,    15,    88,     6,     7,    52,    20,    49,    74,
      42,    13,    14,    48,    40,    53,    51,    91,    36,    37,
      52,    86,    49,     6,    89,    46,    41,    42,    43,    44,
      13,    14,    -1,    46,    99,   100,    -1,    41,    42,    43,
      44,    -1,    -1,   128,    22,    49,    24,    -1,    -1,    27,
      32,    33,    34,    35,    -1,   110,    -1,   131,   132,   144,
     125,    -1,   127,   137,   138,    -1,    44,   122,   133,   124,
      48,    49,    32,    33,    34,    35,    54,    -1,    -1,   153,
      -1,    -1,    -1,   157,    -1,   150,    -1,    -1,   152,   154,
      -1,    51,    70,    71,    72,    73,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     5,     0,
       1,    -1,    -1,    -1,    11,    12,    13,    14,     0,     1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    39,    40,    41,    42,    43,    44,    44,     0,
       1,     5,    -1,    49,    -1,    46,    53,    11,    12,    13,
      14,    -1,    -1,    -1,    46,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    70,    71,    72,    73,     0,     1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    25,    26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    20,    46,    55,    56,    57,    58,    47,    46,
      57,     0,     1,    16,    19,    21,    60,    55,    39,    60,
      55,    61,    47,    47,    17,    18,    20,    22,    23,    60,
      65,    57,    25,    26,    27,    28,    29,    30,    31,    74,
      65,    55,     3,     4,     8,     9,    10,    19,    42,    52,
      77,    78,    21,    24,    52,    76,    78,    78,    67,    49,
      50,    78,    76,    48,    60,    77,    78,    78,    77,    78,
       6,     7,    13,    14,    63,     5,    11,    12,    13,    14,
      39,    40,    41,    42,    43,    44,    62,    78,    38,    64,
      49,    55,    76,    32,    33,    34,    35,    51,    73,    72,
      71,    36,    37,    75,    53,    53,    77,    77,    77,    77,
      55,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    55,    76,    55,    66,    65,    68,    49,    48,
      51,    55,    55,    40,    60,    60,    60,    55,    55,    76,
      32,    33,    34,    35,    49,    65,    65,    55,    65,    65,
      69,    76,    59,    55,    70,    57,    65,    55,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    57,    58,    57,
      59,    57,    60,    61,    60,    60,    62,    60,    63,    60,
      64,    60,    65,    66,    65,    67,    65,    68,    65,    69,
      65,    70,    65,    71,    65,    72,    65,    65,    73,    73,
      73,    73,    73,    73,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    76,    76,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     3,     0,     0,     4,
       0,    10,     0,     0,     4,     2,     0,     6,     0,     6,
       0,     6,     0,     0,     6,     0,     4,     0,     6,     0,
       8,     0,     9,     0,     5,     0,     5,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
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
#line 102 "expresiones.y"
                     {n_lineas++;}
#line 1314 "expresiones.c"
    break;

  case 3: /* salto: salto '\n'  */
#line 103 "expresiones.y"
                    {n_lineas++;}
#line 1320 "expresiones.c"
    break;

  case 8: /* $@1: %empty  */
#line 112 "expresiones.y"
                   {cout << "+++ bloque personajes linea " << n_lineas << endl;}
#line 1326 "expresiones.c"
    break;

  case 10: /* $@2: %empty  */
#line 113 "expresiones.y"
                                                   { cout << "-------- asignacion nombre " << (yyvsp[-7].c_identificador) << "," << (yyvsp[-4].c_cadena) << "," << (yyvsp[-2].c_cadena) <<  " linea " << n_lineas << endl;}
#line 1332 "expresiones.c"
    break;

  case 13: /* $@3: %empty  */
#line 119 "expresiones.y"
                     {cout << "+++ bloque definiciones linea " << n_lineas << endl;}
#line 1338 "expresiones.c"
    break;

  case 15: /* bloqueDefiniciones: error salto  */
#line 120 "expresiones.y"
                     {yyerrok; errorSemantico = false; errorVariable = false;}
#line 1344 "expresiones.c"
    break;

  case 16: /* $@4: %empty  */
#line 121 "expresiones.y"
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
#line 1394 "expresiones.c"
    break;

  case 18: /* $@5: %empty  */
#line 167 "expresiones.y"
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
#line 1432 "expresiones.c"
    break;

  case 20: /* $@6: %empty  */
#line 201 "expresiones.y"
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
#line 1470 "expresiones.c"
    break;

  case 23: /* $@7: %empty  */
#line 237 "expresiones.y"
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
#line 1489 "expresiones.c"
    break;

  case 25: /* $@8: %empty  */
#line 251 "expresiones.y"
                  {cout << "+++ Fin de la escena " << n_escena << endl; }
#line 1495 "expresiones.c"
    break;

  case 27: /* $@9: %empty  */
#line 252 "expresiones.y"
                                                               { cout << "-------- personaje " << " [" << (yyvsp[-2].c_identificador) << "] "  << " en linea " << n_lineas << " dice : " << (yyvsp[0].c_cadena) << endl; }
#line 1501 "expresiones.c"
    break;

  case 29: /* $@10: %empty  */
#line 253 "expresiones.y"
                                                               { cout << "-------- personaje " << " [" << (yyvsp[-4].c_identificador) << "] "  << " en linea " << n_lineas << " dice :      " << (yyvsp[0].c_cadena) << endl; }
#line 1507 "expresiones.c"
    break;

  case 31: /* $@11: %empty  */
#line 254 "expresiones.y"
                                                               { cout << "-------- personaje " << " [" << (yyvsp[-5].c_identificador) << "] " << " en linea " << n_lineas << " dice : " << (yyvsp[0].c_cadena) << " con entonación " << (yyvsp[-3].c_cadena) << endl; }
#line 1513 "expresiones.c"
    break;

  case 33: /* $@12: %empty  */
#line 255 "expresiones.y"
                             {cout << "-------- mensaje " << strncpy((yyvsp[0].c_cadena), (yyvsp[0].c_cadena)+1, strlen((yyvsp[0].c_cadena)-2)) << endl;}
#line 1519 "expresiones.c"
    break;

  case 35: /* $@13: %empty  */
#line 256 "expresiones.y"
                        {cout << "-------- pausa " << (yyvsp[0].c_expresion_arit).valor << endl;}
#line 1525 "expresiones.c"
    break;

  case 38: /* entonacion: DESPACIO  */
#line 261 "expresiones.y"
                                    {strcpy((yyval.c_cadena), "despacio");}
#line 1531 "expresiones.c"
    break;

  case 39: /* entonacion: DEPRISA  */
#line 262 "expresiones.y"
                                    {strcpy((yyval.c_cadena), "deprisa");}
#line 1537 "expresiones.c"
    break;

  case 40: /* entonacion: GRITANDO  */
#line 263 "expresiones.y"
                                    {strcpy((yyval.c_cadena), "gritando");}
#line 1543 "expresiones.c"
    break;

  case 41: /* entonacion: VOZ_BAJA  */
#line 264 "expresiones.y"
                                    {strcpy((yyval.c_cadena), "voz baja");}
#line 1549 "expresiones.c"
    break;

  case 42: /* entonacion: entonacion ',' DESPACIO  */
#line 265 "expresiones.y"
                                    {strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), ","); strcat((yyval.c_cadena), "despacio");}
#line 1555 "expresiones.c"
    break;

  case 43: /* entonacion: entonacion ',' DEPRISA  */
#line 266 "expresiones.y"
                                    {strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), ","); strcat((yyval.c_cadena), "deprisa");}
#line 1561 "expresiones.c"
    break;

  case 44: /* entonacion: entonacion ',' GRITANDO  */
#line 267 "expresiones.y"
                                    {strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), ","); strcat((yyval.c_cadena), "gritando");}
#line 1567 "expresiones.c"
    break;

  case 45: /* entonacion: entonacion ',' VOZ_BAJA  */
#line 268 "expresiones.y"
                                    {strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), ","); strcat((yyval.c_cadena), "voz baja");}
#line 1573 "expresiones.c"
    break;

  case 46: /* idioma: EN  */
#line 272 "expresiones.y"
                        {strcpy((yyval.c_cadena), "en");}
#line 1579 "expresiones.c"
    break;

  case 47: /* idioma: EN_US  */
#line 273 "expresiones.y"
                        {strcpy((yyval.c_cadena), "en-us");}
#line 1585 "expresiones.c"
    break;

  case 48: /* idioma: ES  */
#line 274 "expresiones.y"
                        {strcpy((yyval.c_cadena), "es");}
#line 1591 "expresiones.c"
    break;

  case 49: /* idioma: ES_LA  */
#line 275 "expresiones.y"
                        {strcpy((yyval.c_cadena), "es-la");}
#line 1597 "expresiones.c"
    break;

  case 50: /* idioma: PT  */
#line 276 "expresiones.y"
                        {strcpy((yyval.c_cadena), "pt");}
#line 1603 "expresiones.c"
    break;

  case 51: /* idioma: IT  */
#line 277 "expresiones.y"
                        {strcpy((yyval.c_cadena), "it");}
#line 1609 "expresiones.c"
    break;

  case 52: /* idioma: FR  */
#line 278 "expresiones.y"
                        {strcpy((yyval.c_cadena), "fr");}
#line 1615 "expresiones.c"
    break;

  case 53: /* voz: MASCULINO  */
#line 281 "expresiones.y"
                        {strcpy((yyval.c_cadena), "m");}
#line 1621 "expresiones.c"
    break;

  case 54: /* voz: FEMENINO  */
#line 282 "expresiones.y"
                        {strcpy((yyval.c_cadena), "f");}
#line 1627 "expresiones.c"
    break;

  case 55: /* expr_cadena: CADENA  */
#line 286 "expresiones.y"
                                               {strcpy((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1633 "expresiones.c"
    break;

  case 56: /* expr_cadena: ID_CADENA  */
#line 287 "expresiones.y"
                                               {strcpy((yyval.c_cadena), (yyvsp[0].c_identificador));}
#line 1639 "expresiones.c"
    break;

  case 57: /* expr_cadena: expr_arit  */
#line 288 "expresiones.y"
                                               {sprintf((yyval.c_cadena), "%f", (yyvsp[0].c_expresion_arit).valor);}
#line 1645 "expresiones.c"
    break;

  case 58: /* expr_cadena: expr_cadena CONCATENACION expr_cadena  */
#line 289 "expresiones.y"
                                               {cout << "-------- concatenacion cadena (" << (yyvsp[-2].c_cadena) << ") cadena(" << (yyvsp[0].c_cadena) <<  ")" << endl; strcpy((yyval.c_cadena), (yyvsp[-2].c_cadena)); strcat((yyval.c_cadena), (yyvsp[0].c_cadena));}
#line 1651 "expresiones.c"
    break;

  case 59: /* expr_log: TRUE  */
#line 292 "expresiones.y"
                                              {(yyval.c_bool) = true; }
#line 1657 "expresiones.c"
    break;

  case 60: /* expr_log: FALSE  */
#line 293 "expresiones.y"
                                              {(yyval.c_bool) = false; }
#line 1663 "expresiones.c"
    break;

  case 61: /* expr_log: expr_log AND expr_log  */
#line 294 "expresiones.y"
                                              {(yyval.c_bool) = (yyvsp[-2].c_bool) and (yyvsp[0].c_bool); }
#line 1669 "expresiones.c"
    break;

  case 62: /* expr_log: expr_log OR expr_log  */
#line 295 "expresiones.y"
                                              {(yyval.c_bool) = (yyvsp[-2].c_bool) or (yyvsp[0].c_bool); }
#line 1675 "expresiones.c"
    break;

  case 63: /* expr_log: NOT expr_log  */
#line 296 "expresiones.y"
                                              {(yyval.c_bool) = (not (yyvsp[0].c_bool)); }
#line 1681 "expresiones.c"
    break;

  case 64: /* expr_log: '(' expr_log ')'  */
#line 297 "expresiones.y"
                                                  {(yyval.c_bool) =     (yyvsp[-1].c_bool); }
#line 1687 "expresiones.c"
    break;

  case 65: /* expr_log: expr_arit '>' expr_arit  */
#line 298 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor > (yyvsp[0].c_expresion_arit).valor)  ? true : false; }
#line 1693 "expresiones.c"
    break;

  case 66: /* expr_log: expr_arit MAYORIGUAL expr_arit  */
#line 299 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor >= (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1699 "expresiones.c"
    break;

  case 67: /* expr_log: expr_arit '<' expr_arit  */
#line 300 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor < (yyvsp[0].c_expresion_arit).valor)  ? true : false; }
#line 1705 "expresiones.c"
    break;

  case 68: /* expr_log: expr_arit MENORIGUAL expr_arit  */
#line 301 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor <= (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1711 "expresiones.c"
    break;

  case 69: /* expr_log: expr_arit IGUAL2 expr_arit  */
#line 302 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor == (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1717 "expresiones.c"
    break;

  case 70: /* expr_log: expr_arit DISTINTO expr_arit  */
#line 303 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_expresion_arit).valor != (yyvsp[0].c_expresion_arit).valor) ? true : false; }
#line 1723 "expresiones.c"
    break;

  case 71: /* expr_log: expr_log IGUAL2 expr_log  */
#line 304 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_bool) == (yyvsp[0].c_bool)) ? true : false; }
#line 1729 "expresiones.c"
    break;

  case 72: /* expr_log: expr_log DISTINTO expr_log  */
#line 305 "expresiones.y"
                                              {(yyval.c_bool) = ((yyvsp[-2].c_bool) != (yyvsp[0].c_bool)) ? true : false; }
#line 1735 "expresiones.c"
    break;

  case 73: /* expr_arit: NUMERO  */
#line 308 "expresiones.y"
                                                        {(yyval.c_expresion_arit).esReal = false; (yyval.c_expresion_arit).valor = (yyvsp[0].c_entero); }
#line 1741 "expresiones.c"
    break;

  case 74: /* expr_arit: REAL  */
#line 309 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = true;  (yyval.c_expresion_arit).valor = (yyvsp[0].c_real); }
#line 1747 "expresiones.c"
    break;

  case 75: /* expr_arit: ID_GENERAL  */
#line 310 "expresiones.y"
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
#line 1775 "expresiones.c"
    break;

  case 76: /* expr_arit: expr_arit '+' expr_arit  */
#line 333 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor + (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) + int((yyvsp[0].c_expresion_arit).valor); }
#line 1781 "expresiones.c"
    break;

  case 77: /* expr_arit: expr_arit '-' expr_arit  */
#line 334 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor - (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) - int((yyvsp[0].c_expresion_arit).valor); }
#line 1787 "expresiones.c"
    break;

  case 78: /* expr_arit: expr_arit '*' expr_arit  */
#line 335 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[-2].c_expresion_arit).esReal || (yyvsp[0].c_expresion_arit).esReal; (yyval.c_expresion_arit).valor = ((yyval.c_expresion_arit).esReal) ? (yyvsp[-2].c_expresion_arit).valor * (yyvsp[0].c_expresion_arit).valor : int((yyvsp[-2].c_expresion_arit).valor) * int((yyvsp[0].c_expresion_arit).valor); }
#line 1793 "expresiones.c"
    break;

  case 79: /* expr_arit: expr_arit '/' expr_arit  */
#line 337 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = true; 
                                                if((yyvsp[0].c_expresion_arit).valor == 0){ 
                                                      errorSemantico = true; 
                                                      cout << "Error semantico en la linea " << n_lineas << ", se ha detectado una división entre el número 0" << endl;
                                                } 
                                                else 
                                                      (yyval.c_expresion_arit).valor = (yyvsp[-2].c_expresion_arit).valor / (yyvsp[0].c_expresion_arit).valor;
                                              }
#line 1806 "expresiones.c"
    break;

  case 80: /* expr_arit: expr_arit DIV expr_arit  */
#line 346 "expresiones.y"
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
#line 1824 "expresiones.c"
    break;

  case 81: /* expr_arit: '-' expr_arit  */
#line 360 "expresiones.y"
                                              {(yyval.c_expresion_arit).esReal = (yyvsp[0].c_expresion_arit).esReal ; (yyval.c_expresion_arit).valor = ((yyvsp[0].c_expresion_arit).esReal) ? -(yyvsp[0].c_expresion_arit).valor : int(-(yyvsp[0].c_expresion_arit).valor); }
#line 1830 "expresiones.c"
    break;

  case 82: /* expr_arit: '(' expr_arit ')'  */
#line 361 "expresiones.y"
                                                  {(yyval.c_expresion_arit).esReal = (yyvsp[-1].c_expresion_arit).esReal ; (yyval.c_expresion_arit).valor = ((yyvsp[-1].c_expresion_arit).esReal) ?  (yyvsp[-1].c_expresion_arit).valor : int( (yyvsp[-1].c_expresion_arit).valor); }
#line 1836 "expresiones.c"
    break;


#line 1840 "expresiones.c"

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

#line 363 "expresiones.y"


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
