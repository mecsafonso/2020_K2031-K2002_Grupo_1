
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "TP4Bison.y"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

//#include "TP4.h"

#include <stdlib.h>

typedef struct nodoInfo{
    char info[30];
    struct nodoInfo* sig;
}nodoInfo;

typedef struct {
    char identificador[30];
    char tipo[30];
    int es_funcion;
    nodoInfo* listaParametros;
} funcion;

typedef struct nodo{
    funcion info;
    struct nodo* sig;
} nodo;

typedef struct nodoErroresSintacticos{
    int linea;
    struct nodoErroresSintacticos* sig;
}nodoErroresSintacticos;

typedef struct nodoValidacionesSintacticas{
    char info[100];
    int linea;
    struct nodoValidacionesSintacticas* sig;
}nodoValidacionesSintacticas;


int control_tipos(char palabra[], char tipo[]);
nodo* existe_variable(nodo* lista, char nombre[]);
char* tipo_variable(nodo* lista, char nombre[], FILE* arcFinal);
void agregar_info(nodoInfo** listaParametros, char tipo[]);
void agregar_validaciones_sintacticas(nodoValidacionesSintacticas** listaParametros, int nroLinea , char mensaje[]);
void agregar_error_sintactico(nodoErroresSintacticos** listaParametros, int nroLinea);
int agregar_variable(nodo** lista, char nombre[], char tipo[]);
void agregar_funcion(nodo** lista, char nombre[], char tipo[], nodoInfo* listaParametros);
void gestionar_identificador(nodo** listaVariables, char nombre[], char tipo[], FILE* archivoFinal);
void gestionar_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], char tipo[], FILE* archivoFinal);
void sentencia_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], FILE* archivoFinal);
int parametros_contra_funcion(nodo* funcion, nodoInfo* listaParametros, FILE* archivoFinal);

void imprimir_parametros(nodoInfo* lista, FILE* archivoFinal);
void imprimir_lista_variables(nodo* lista, FILE* archivoFinal);
void imprimir_funciones(nodo* lista, FILE* archivoFinal);
void imprimir_validaciones_sintacticas(nodoValidacionesSintacticas** lista, FILE* archivoFinal);
void imprimir_errores(nodoInfo** lista, FILE* archivoFinal);
void imprimir_errores_sintacticos(nodoErroresSintacticos** lista, FILE* archivoFinal);


#define YYDEBUG 1
extern FILE *yyin;
extern FILE *yyout;

int flag_error=0;
int contador=0;
char tipo[30];
char identificador[30];
char tipo_parametro[30];
int modo_funcion = 0;
int contador_parametros = 0;
nodo* listaVariables = NULL;
nodoInfo* listaErroresLexicos = NULL;
nodoInfo* listaParametros = NULL;
nodoErroresSintacticos* listaErroresSintacticos = NULL;
nodoValidacionesSintacticas* listaDeValidacionesSintacticas = NULL;


FILE* archivoFinal;

int yylex();

int yywrap(){
	return(1);
}

int numeroDeLinea = 1;

void yyerror (char const *s) {
  agregar_error_sintactico(&listaErroresSintacticos, numeroDeLinea);
}



/* Line 189 of yacc.c  */
#line 167 "TP4Bison.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     CONS_REAL = 259,
     IDENTIFICADOR = 260,
     ESPECIFICADOR_TIPO = 261,
     LIT_CADENA = 262,
     CARACTER = 263,
     FOR = 264,
     WHILE = 265,
     DO = 266,
     SWITCH = 267,
     GOTO = 268,
     CONTINUE = 269,
     BREAK = 270,
     CASE = 271,
     DEFAULT = 272,
     RETURN = 273,
     IF = 274,
     ELSE = 275,
     SIZEOF = 276,
     STRUCT = 277,
     UNION = 278,
     CONST = 279,
     VOLATILE = 280,
     ENUM = 281,
     OPER_ASIGNACION = 282,
     OPER_OR = 283,
     OPER_AND = 284,
     OPER_IGUALDAD = 285,
     OPER_DIFERENCIA = 286,
     OPER_RELACIONAL = 287,
     OPER_INC_DEC = 288,
     OPER_NEGACION = 289,
     OPER_DIRECCION = 290,
     ESPECIFICADOR_ALMACENAMIENTO = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 94 "TP4Bison.y"

char cadena[30];
int entero;
float real;



/* Line 214 of yacc.c  */
#line 247 "TP4Bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 259 "TP4Bison.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   510

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  183
/* YYNRULES -- Number of states.  */
#define YYNSTATES  297

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    52,     2,     2,
      44,    45,    43,    49,    39,    50,    48,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    38,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    12,    15,    18,    20,
      22,    26,    30,    31,    33,    36,    39,    42,    43,    45,
      47,    51,    53,    57,    59,    63,    68,    70,    74,    76,
      78,    80,    82,    84,    86,    92,    95,    96,    98,   100,
     102,   105,   108,   112,   115,   118,   119,   121,   123,   127,
     129,   133,   136,   137,   139,   142,   146,   147,   149,   151,
     154,   155,   157,   159,   163,   168,   173,   178,   180,   186,
     187,   189,   191,   195,   199,   203,   206,   209,   212,   213,
     215,   216,   218,   220,   225,   230,   232,   236,   237,   239,
     245,   248,   250,   254,   256,   260,   262,   266,   271,   276,
     281,   282,   284,   286,   290,   291,   293,   295,   299,   301,
     303,   304,   306,   308,   310,   314,   316,   320,   322,   326,
     330,   332,   336,   338,   342,   346,   348,   352,   356,   360,
     362,   365,   368,   373,   375,   377,   379,   381,   383,   385,
     390,   395,   396,   398,   400,   404,   406,   408,   410,   412,
     414,   416,   418,   420,   424,   426,   428,   430,   432,   434,
     436,   441,   443,   446,   447,   449,   451,   454,   455,   457,
     460,   467,   473,   474,   477,   483,   491,   501,   506,   510,
     514,   518,   521,   524
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      54,     0,    -1,    -1,    54,    55,    -1,     1,    56,    -1,
      37,    -1,   121,    37,    -1,    57,    37,    -1,    38,    -1,
      37,    -1,    59,    58,    38,    -1,    59,    58,   122,    -1,
      -1,    61,    -1,    65,    60,    -1,    66,    60,    -1,    67,
      60,    -1,    -1,    59,    -1,    62,    -1,    61,    39,    62,
      -1,    77,    -1,    77,    27,    63,    -1,   103,    -1,    40,
      64,    41,    -1,    40,    64,    39,    41,    -1,    63,    -1,
      64,    39,    63,    -1,    36,    -1,     6,    -1,    68,    -1,
      94,    -1,    24,    -1,    25,    -1,    70,    69,    40,    71,
      41,    -1,    70,     5,    -1,    -1,     5,    -1,    22,    -1,
      23,    -1,    72,    38,    -1,    71,    72,    -1,    73,    75,
      38,    -1,    66,    74,    -1,    67,    74,    -1,    -1,    73,
      -1,    76,    -1,    75,    39,    76,    -1,    77,    -1,    78,
      42,   105,    -1,    80,    83,    -1,    -1,    77,    -1,    43,
      82,    -1,    43,    82,    79,    -1,    -1,    79,    -1,    67,
      -1,    81,    67,    -1,    -1,    81,    -1,     5,    -1,    44,
      77,    45,    -1,     5,    46,   106,    47,    -1,     5,    44,
      84,    45,    -1,     5,    44,    93,    45,    -1,    86,    -1,
      86,    39,    48,    48,    48,    -1,    -1,    84,    -1,    87,
      -1,    86,    39,    87,    -1,    88,    90,    91,    -1,    88,
      90,   100,    -1,     6,    89,    -1,    24,    89,    -1,    25,
      89,    -1,    -1,    88,    -1,    -1,    43,    -1,     5,    -1,
      44,    90,    91,    45,    -1,     5,    46,   106,    47,    -1,
       5,    -1,    92,    39,     5,    -1,    -1,    92,    -1,    26,
      69,    40,    95,    41,    -1,    26,     5,    -1,    96,    -1,
      95,    39,    96,    -1,    97,    -1,    97,    27,   105,    -1,
       5,    -1,    73,    90,   100,    -1,    44,    90,   100,    45,
      -1,   100,    46,   106,    47,    -1,   100,    44,    85,    45,
      -1,    -1,    99,    -1,   103,    -1,   101,    39,   103,    -1,
      -1,   101,    -1,   107,    -1,   114,   104,   103,    -1,    27,
      -1,   107,    -1,    -1,   105,    -1,   108,    -1,   109,    -1,
     108,    28,   109,    -1,   110,    -1,   109,    29,   110,    -1,
     111,    -1,   110,    30,   111,    -1,   110,    31,   111,    -1,
     112,    -1,   111,    32,   112,    -1,   113,    -1,   112,    49,
     113,    -1,   112,    50,   113,    -1,   114,    -1,   113,    43,
     114,    -1,   113,    51,   114,    -1,   113,    52,   114,    -1,
     116,    -1,    33,   114,    -1,   115,   114,    -1,    21,    44,
      98,    45,    -1,    35,    -1,    43,    -1,    50,    -1,    49,
      -1,    34,    -1,   120,    -1,   116,    46,   101,    47,    -1,
       5,    44,   117,    45,    -1,    -1,   118,    -1,   119,    -1,
     118,    39,   119,    -1,     5,    -1,     3,    -1,     4,    -1,
       7,    -1,     5,    -1,     3,    -1,     4,    -1,     7,    -1,
      44,   101,    45,    -1,   127,    -1,   122,    -1,   128,    -1,
     130,    -1,   131,    -1,   132,    -1,    40,   124,   126,    41,
      -1,    57,    -1,   123,    57,    -1,    -1,   123,    -1,   121,
      -1,   125,   121,    -1,    -1,   125,    -1,   102,    38,    -1,
      19,    44,   101,    45,   121,   129,    -1,    12,    44,   101,
      45,   121,    -1,    -1,    20,   121,    -1,    10,    44,   101,
      45,   121,    -1,    11,   121,    10,    44,   101,    45,    38,
      -1,     9,    44,   102,    38,   102,    38,   102,    45,   121,
      -1,    16,   101,    42,   121,    -1,    17,    42,   121,    -1,
       5,    42,   121,    -1,    18,   102,    38,    -1,    14,    38,
      -1,    15,    38,    -1,    13,     5,    38,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   140,   140,   141,   142,   145,   146,   147,   150,   151,
     154,   155,   162,   163,   166,   167,   168,   171,   172,   175,
     176,   179,   180,   183,   184,   185,   188,   189,   192,   195,
     196,   197,   204,   205,   208,   209,   212,   213,   216,   217,
     220,   221,   224,   227,   228,   231,   232,   235,   236,   239,
     240,   243,   246,   247,   250,   251,   254,   255,   258,   259,
     262,   263,   266,   267,   268,   269,   270,   276,   277,   280,
     281,   284,   285,   288,   289,   292,   293,   294,   297,   298,
     301,   302,   305,   306,   307,   311,   312,   315,   316,   319,
     320,   325,   326,   329,   330,   333,   336,   339,   340,   341,
     344,   345,   357,   358,   361,   362,   365,   366,   369,   372,
     375,   376,   379,   383,   384,   387,   388,   391,   392,   393,
     396,   397,   400,   401,   402,   405,   406,   407,   408,   411,
     412,   413,   414,   417,   418,   419,   420,   421,   424,   425,
     426,   429,   430,   434,   435,   438,   439,   440,   441,   444,
     445,   446,   447,   448,   469,   470,   471,   472,   473,   474,
     483,   486,   487,   490,   491,   495,   496,   499,   500,   503,
     506,   507,   511,   512,   515,   516,   517,   520,   521,   522,
     525,   526,   527,   528
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "CONS_REAL", "IDENTIFICADOR",
  "ESPECIFICADOR_TIPO", "LIT_CADENA", "CARACTER", "FOR", "WHILE", "DO",
  "SWITCH", "GOTO", "CONTINUE", "BREAK", "CASE", "DEFAULT", "RETURN", "IF",
  "ELSE", "SIZEOF", "STRUCT", "UNION", "CONST", "VOLATILE", "ENUM",
  "OPER_ASIGNACION", "OPER_OR", "OPER_AND", "OPER_IGUALDAD",
  "OPER_DIFERENCIA", "OPER_RELACIONAL", "OPER_INC_DEC", "OPER_NEGACION",
  "OPER_DIRECCION", "ESPECIFICADOR_ALMACENAMIENTO", "'\\n'", "';'", "','",
  "'{'", "'}'", "':'", "'*'", "'('", "')'", "'['", "']'", "'.'", "'+'",
  "'-'", "'/'", "'%'", "$accept", "input", "line", "caracterDeCorte",
  "declaracion", "listaDeclaradoresOP", "especificadoresDeclaracion",
  "especificadoresDeclaracionOP", "listaDeclaradores", "declarador",
  "inicializador", "listaInicializadores",
  "especificadorClaseAlmacenamiento", "especificadorTipo",
  "calificadorTipo", "especificadorStructOUnion", "identificadorOP",
  "structOUnion", "listaDeclaracionesStruct", "declaracionStruct",
  "listaCalificadores", "listaCalificadoresOP", "declaradoresStruct",
  "declaStruct", "decla", "declaOP", "puntero", "punteroOP",
  "listaCalificadoresTipos", "listaCalificadoresTiposOP",
  "declaradorDirecto", "listaTiposParametros", "listaTiposParametrosOP",
  "listaParametros", "declaracionParametro",
  "especificadoresDeclaracionParametro",
  "especificadoresDeclaracionParametroOp", "punteroParametroOp",
  "declaParametro", "listaIdentificadores", "listaIdentificadoresOP",
  "especificadorEnum", "listaEnumeradores", "enumerador",
  "constanteEnumeracion", "nombreTipo", "declaradorAbstractoDirecto",
  "declaradorAbstractoDirectoOP", "expresion", "expresionOP",
  "expAsignacion", "operAsignacion", "expConstante", "expConstanteOP",
  "expCondicional", "expOr", "expAnd", "expIgualdad", "expRelacional",
  "expAditiva", "expMultiplicativa", "expUnaria", "operUnario",
  "expPostfijo", "listaArgumentosOP", "listaArgumentos", "argumento",
  "expPrimaria", "sentencia", "sentCompuesta", "listaDeclaraciones",
  "listaDeclaracionesOP", "listaSentencias", "listaSentenciasOP",
  "sentExpresion", "sentSeleccion", "elseOP", "sentIteracion",
  "sentEtiquetada", "sentSalto", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    10,    59,    44,
     123,   125,    58,    42,    40,    41,    91,    93,    46,    43,
      45,    47,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    54,    55,    55,    55,    56,    56,
      57,    57,    58,    58,    59,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    63,    64,    64,    65,    66,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    73,    73,    74,    74,    75,    75,    76,
      76,    77,    78,    78,    79,    79,    80,    80,    81,    81,
      82,    82,    83,    83,    83,    83,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    88,    88,    88,    89,    89,
      90,    90,    91,    91,    91,    92,    92,    93,    93,    94,
      94,    95,    95,    96,    96,    97,    98,    99,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   105,
     106,   106,   107,   108,   108,   109,   109,   110,   110,   110,
     111,   111,   112,   112,   112,   113,   113,   113,   113,   114,
     114,   114,   114,   115,   115,   115,   115,   115,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   119,   119,   120,
     120,   120,   120,   120,   121,   121,   121,   121,   121,   121,
     122,   123,   123,   124,   124,   125,   125,   126,   126,   127,
     128,   128,   129,   129,   130,   130,   130,   131,   131,   131,
     132,   132,   132,   132
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     2,     1,     1,
       3,     3,     0,     1,     2,     2,     2,     0,     1,     1,
       3,     1,     3,     1,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     5,     2,     0,     1,     1,     1,
       2,     2,     3,     2,     2,     0,     1,     1,     3,     1,
       3,     2,     0,     1,     2,     3,     0,     1,     1,     2,
       0,     1,     1,     3,     4,     4,     4,     1,     5,     0,
       1,     1,     3,     3,     3,     2,     2,     2,     0,     1,
       0,     1,     1,     4,     4,     1,     3,     0,     1,     5,
       2,     1,     3,     1,     3,     1,     3,     4,     4,     4,
       0,     1,     1,     3,     0,     1,     1,     3,     1,     1,
       0,     1,     1,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     4,
       4,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       4,     1,     2,     0,     1,     1,     2,     0,     1,     2,
       6,     5,     0,     2,     5,     7,     9,     4,     3,     3,
       3,     2,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   104,     9,     8,     4,     1,   150,   151,   149,
      29,   152,     0,     0,   104,     0,     0,     0,     0,     0,
       0,   104,     0,     0,    38,    39,    32,    33,    36,     0,
     137,   133,    28,     5,   163,   134,     0,   136,   135,     3,
       0,    12,    17,    17,    17,    30,    36,    31,   105,     0,
     102,   106,   112,   113,   115,   117,   120,   122,   125,     0,
     129,   138,     0,   155,   154,   156,   157,   158,   159,   104,
     141,   104,     0,     0,     0,     0,   181,   182,   149,     0,
     104,     0,     0,     0,    90,     0,   130,   161,   164,   104,
       0,     7,    60,     0,    13,    19,    21,    57,     0,    18,
      14,    15,    16,    35,     0,     0,   169,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,   131,
       0,     6,   179,   146,   147,   145,   148,     0,   142,   143,
       0,     0,     0,     0,   183,   104,   178,   180,     0,    45,
      45,    80,     0,     0,   162,   165,   104,     0,   153,    58,
      61,    54,    10,    11,    56,     0,    62,    56,    51,     0,
     103,   114,   125,   116,   118,   119,   121,   123,   124,   126,
     127,   128,   107,     0,   140,     0,   104,   104,     0,   104,
     177,   104,    46,    43,    44,    81,   100,   132,    95,     0,
      91,    93,   166,   160,    59,    55,    20,     0,    22,    23,
      87,   110,     0,     0,     0,    56,   139,   144,     0,   174,
       0,   171,   172,    80,   101,    96,     0,    89,     0,    26,
       0,    85,    78,    78,    78,     0,    67,    71,    80,    88,
       0,   111,     0,   109,    63,    34,    41,    40,     0,    47,
      49,     0,   104,     0,   104,   170,   100,    69,   110,    92,
      94,     0,    24,    79,    75,    76,    77,    65,     0,   100,
       0,    66,    64,    42,    56,     0,     0,   175,   173,     0,
      70,     0,     0,    25,    27,     0,    72,    82,    80,    73,
      74,    86,    48,    50,   104,    97,    99,    98,     0,   110,
     100,   176,    68,     0,     0,    84,    83
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    39,     5,    40,    93,    41,   100,    94,    95,
     198,   220,    42,    43,    44,    45,    85,    46,   203,   204,
     182,   183,   238,   239,    96,   241,    97,    98,   150,   151,
     158,   225,   271,   226,   227,   228,   254,   186,   279,   229,
     230,    47,   189,   190,   191,   142,   214,   269,    48,    49,
      50,   118,   231,   232,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,   127,   128,   129,    61,    62,    63,
      88,    89,   146,   147,    64,    65,   245,    66,    67,    68
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -231
static const yytype_int16 yypact[] =
{
     191,   -24,   262,  -231,  -231,  -231,  -231,  -231,  -231,    32,
    -231,  -231,    -8,    -5,   406,    33,    20,    56,    67,   460,
      85,   460,    68,    87,  -231,  -231,  -231,  -231,   131,   460,
    -231,  -231,  -231,  -231,    21,  -231,   460,  -231,  -231,  -231,
     124,    60,    21,    21,    21,  -231,   138,  -231,   132,   139,
    -231,  -231,   155,   164,    18,   167,    70,   -17,   184,   460,
     190,  -231,   205,  -231,  -231,  -231,  -231,  -231,  -231,   406,
     141,   460,   460,   235,   460,   208,  -231,  -231,   203,   -10,
     406,   212,   460,   100,   211,   213,  -231,  -231,    21,   310,
      11,  -231,   130,    59,   215,  -231,   225,  -231,    23,  -231,
    -231,  -231,  -231,  -231,   216,   460,  -231,   460,   460,   460,
     460,   460,   460,   460,   460,   460,   460,  -231,   460,  -231,
     460,  -231,  -231,  -231,  -231,  -231,  -231,   210,   218,  -231,
     220,    57,   219,    62,  -231,   406,  -231,  -231,    89,   100,
     100,   217,   214,   259,  -231,  -231,   358,   241,  -231,  -231,
     130,   246,  -231,  -231,   246,   426,   118,   246,  -231,   100,
    -231,   164,  -231,    18,   167,   167,    70,   -17,   -17,  -231,
    -231,  -231,  -231,   -27,  -231,   141,   460,   406,   460,   406,
    -231,   406,  -231,  -231,  -231,  -231,   247,  -231,  -231,   133,
    -231,   263,  -231,  -231,  -231,  -231,  -231,   426,  -231,  -231,
     105,   460,   248,    92,   254,   176,  -231,  -231,   256,  -231,
     102,  -231,   280,   217,  -231,   142,   259,  -231,   460,  -231,
     148,  -231,    16,    16,    16,   258,   265,  -231,   217,   268,
     264,  -231,   261,  -231,  -231,  -231,  -231,  -231,   183,  -231,
     274,   276,   460,   272,   406,  -231,   247,    16,   460,  -231,
    -231,   135,  -231,  -231,  -231,  -231,  -231,  -231,    13,    25,
     296,  -231,  -231,  -231,   176,   460,   285,  -231,  -231,   106,
    -231,   287,   286,  -231,  -231,   288,  -231,   289,   217,  -231,
     142,  -231,  -231,  -231,   406,  -231,  -231,  -231,   290,   460,
      25,  -231,  -231,   292,   295,  -231,  -231
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,  -231,  -231,  -231,   -25,  -231,   116,   189,  -231,   180,
    -187,  -231,  -231,   -68,   -50,  -231,   291,  -231,  -231,   143,
     -66,   201,  -231,    78,  -151,  -231,   196,  -231,  -231,  -231,
    -231,   101,  -231,  -231,    91,   -42,    15,  -205,    65,  -231,
    -231,  -231,  -231,   140,  -231,  -231,  -231,  -181,   -12,   -19,
    -102,  -231,  -207,  -230,  -197,  -231,   245,   249,   134,   253,
     136,   -28,  -231,  -231,  -231,  -231,   206,  -231,   -14,   273,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -169
static const yytype_int16 yytable[] =
{
      73,    86,    81,   160,   233,   215,   202,    79,   246,    87,
     219,   250,   105,     3,     4,   139,   172,   141,   272,   222,
     206,   233,   222,   259,    90,    75,   114,    10,   156,   105,
     277,   119,   135,   140,   115,   116,    71,   223,   224,    72,
     223,   224,   149,    24,    25,    26,    27,    28,   109,   110,
     105,   233,   130,   199,   240,   122,   148,    32,   283,   293,
     131,   275,   133,   144,   274,   -56,   136,   157,   233,   278,
     138,   139,   139,   290,    69,   145,    70,    74,   280,   162,
     162,   162,   162,   162,   162,   162,   169,   170,   171,   140,
     140,   139,   233,   205,    76,   199,   105,   152,    10,    34,
     194,   105,   177,    92,   -56,    77,    10,   179,   173,   140,
     221,   222,    82,   240,    24,    25,    26,    27,    28,   112,
     113,   180,    24,    25,    26,    27,    28,    80,   105,   223,
     224,    83,   192,   235,   181,   139,    84,   205,     7,     8,
      78,   105,    11,   103,   123,   124,   125,   243,   126,   199,
     247,   285,   248,   140,    26,    27,    23,   208,    99,    99,
      99,    91,   200,   209,   201,   211,   210,   212,    29,    30,
      31,   105,   216,   162,   217,   197,   273,   106,    35,    36,
     253,   253,   253,   107,    37,    38,   247,   251,   248,   252,
     162,    -2,     1,   108,    -2,    -2,    -2,    -2,    -2,   111,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,   117,    -2,    -2,    -2,    -2,    -2,    -2,   -52,    92,
     162,   263,   264,   266,    -2,    -2,    -2,    -2,    -2,    -2,
     268,    -2,   101,   102,    -2,    -2,   120,   162,   255,   256,
      -2,    -2,   121,   164,   165,   132,   134,    70,   167,   168,
     137,   -37,   155,   143,   154,   174,   159,   175,   176,   187,
     185,   162,     6,   178,   188,     7,     8,     9,    10,    11,
     291,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   193,    23,    24,    25,    26,    27,    28,    92,
     218,   213,   237,   234,   242,    29,    30,    31,    32,    33,
     244,   281,    34,   257,   258,    35,    36,   260,   262,   261,
     267,    37,    38,     7,     8,     9,   -53,    11,   265,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     284,    23,   286,   287,   196,   289,   288,   104,   292,   295,
     296,   184,   282,    29,    30,    31,   236,   195,   270,   276,
      34,  -167,   161,    35,    36,   294,   249,   163,     0,    37,
      38,     7,     8,     9,   166,    11,   153,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,     0,    23,
       0,   207,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    30,    31,     0,     0,     0,     0,    34,  -168,
       0,    35,    36,     0,     0,     0,     0,    37,    38,     7,
       8,     9,     0,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     0,    23,     0,     7,
       8,    78,     0,    11,     0,     0,     0,     0,     0,    29,
      30,    31,     0,     0,     0,     0,    34,    23,     0,    35,
      36,     0,     0,     0,     0,    37,    38,     0,     0,    29,
      30,    31,     0,     7,     8,    78,   197,    11,     0,    35,
      36,     0,     0,     0,     0,    37,    38,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,     0,     0,     0,     0,
       0,     0,     0,    35,    36,     0,     0,     0,     0,    37,
      38
};

static const yytype_int16 yycheck[] =
{
      14,    29,    21,   105,   201,   186,   157,    19,   213,    34,
     197,   218,    39,    37,    38,    83,   118,    83,   248,     6,
      47,   218,     6,   228,    36,     5,    43,     6,     5,    39,
       5,    59,    42,    83,    51,    52,    44,    24,    25,    44,
      24,    25,    92,    22,    23,    24,    25,    26,    30,    31,
      39,   248,    71,   155,   205,    69,    45,    36,   265,   289,
      72,    48,    74,    88,   251,     5,    80,    44,   265,    44,
      82,   139,   140,   278,    42,    89,    44,    44,   259,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   139,
     140,   159,   289,   159,    38,   197,    39,    38,     6,    40,
     150,    39,    45,    43,    44,    38,     6,    45,   120,   159,
       5,     6,    44,   264,    22,    23,    24,    25,    26,    49,
      50,   135,    22,    23,    24,    25,    26,    42,    39,    24,
      25,    44,   146,    41,    45,   203,     5,   203,     3,     4,
       5,    39,     7,     5,     3,     4,     5,    45,     7,   251,
      44,    45,    46,   203,    24,    25,    21,   176,    42,    43,
      44,    37,    44,   177,    46,   179,   178,   181,    33,    34,
      35,    39,    39,   201,    41,    40,    41,    38,    43,    44,
     222,   223,   224,    28,    49,    50,    44,    39,    46,    41,
     218,     0,     1,    29,     3,     4,     5,     6,     7,    32,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    27,    21,    22,    23,    24,    25,    26,    42,    43,
     248,    38,    39,   242,    33,    34,    35,    36,    37,    38,
     244,    40,    43,    44,    43,    44,    46,   265,   223,   224,
      49,    50,    37,   109,   110,    10,    38,    44,   112,   113,
      38,    40,    27,    40,    39,    45,    40,    39,    38,    45,
      43,   289,     0,    44,     5,     3,     4,     5,     6,     7,
     284,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    41,    21,    22,    23,    24,    25,    26,    43,
      27,    44,    38,    45,    38,    33,    34,    35,    36,    37,
      20,     5,    40,    45,    39,    43,    44,    39,    47,    45,
      38,    49,    50,     3,     4,     5,    42,     7,    42,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      45,    21,    45,    47,   154,    46,    48,    46,    48,    47,
      45,   140,   264,    33,    34,    35,   203,   151,   247,   258,
      40,    41,   107,    43,    44,   290,   216,   108,    -1,    49,
      50,     3,     4,     5,   111,     7,    93,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    21,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    -1,    -1,    -1,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    -1,    49,    50,     3,
       4,     5,    -1,     7,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    21,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    -1,    -1,    -1,    -1,    40,    21,    -1,    43,
      44,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    33,
      34,    35,    -1,     3,     4,     5,    40,     7,    -1,    43,
      44,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,
      50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    54,    37,    38,    56,     0,     3,     4,     5,
       6,     7,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    21,    22,    23,    24,    25,    26,    33,
      34,    35,    36,    37,    40,    43,    44,    49,    50,    55,
      57,    59,    65,    66,    67,    68,    70,    94,   101,   102,
     103,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   120,   121,   122,   127,   128,   130,   131,   132,    42,
      44,    44,    44,   121,    44,     5,    38,    38,     5,   101,
      42,   102,    44,    44,     5,    69,   114,    57,   123,   124,
     101,    37,    43,    58,    61,    62,    77,    79,    80,    59,
      60,    60,    60,     5,    69,    39,    38,    28,    29,    30,
      31,    32,    49,    50,    43,    51,    52,    27,   104,   114,
      46,    37,   121,     3,     4,     5,     7,   117,   118,   119,
     102,   101,    10,   101,    38,    42,   121,    38,   101,    66,
      67,    73,    98,    40,    57,   121,   125,   126,    45,    67,
      81,    82,    38,   122,    39,    27,     5,    44,    83,    40,
     103,   109,   114,   110,   111,   111,   112,   113,   113,   114,
     114,   114,   103,   101,    45,    39,    38,    45,    44,    45,
     121,    45,    73,    74,    74,    43,    90,    45,     5,    95,
      96,    97,   121,    41,    67,    79,    62,    40,    63,   103,
      44,    46,    77,    71,    72,    73,    47,   119,   102,   121,
     101,   121,   121,    44,    99,   100,    39,    41,    27,    63,
      64,     5,     6,    24,    25,    84,    86,    87,    88,    92,
      93,   105,   106,   107,    45,    41,    72,    38,    75,    76,
      77,    78,    38,    45,    20,   129,    90,    44,    46,    96,
     105,    39,    41,    88,    89,    89,    89,    45,    39,    90,
      39,    45,    47,    38,    39,    42,   102,    38,   121,   100,
      84,    85,   106,    41,    63,    48,    87,     5,    44,    91,
     100,     5,    76,   105,    45,    45,    45,    47,    48,    46,
      90,   121,    48,   106,    91,    47,    45
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1455 of yacc.c  */
#line 142 "TP4Bison.y"
    {flag_error==0;;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 145 "TP4Bison.y"
    {fprintf(archivoFinal,"");flag_error=0; numeroDeLinea++;;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 146 "TP4Bison.y"
    {fprintf(archivoFinal,"");flag_error==0; numeroDeLinea++;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 147 "TP4Bison.y"
    {fprintf(archivoFinal,"");flag_error==0; numeroDeLinea++;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 151 "TP4Bison.y"
    {numeroDeLinea++;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 154 "TP4Bison.y"
    {memset(tipo, 0, 30);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 155 "TP4Bison.y"
    {memset(tipo, 0, 30);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 162 "TP4Bison.y"
    {memset(tipo, 0, 30);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 180 "TP4Bison.y"
    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "ASIGNACION");;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 192 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, (yyvsp[(1) - (1)].cadena));};;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 195 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].cadena));}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 204 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, (yyvsp[(1) - (1)].cadena));};;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 205 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, (yyvsp[(1) - (1)].cadena));};;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 209 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(2) - (2)].cadena));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 213 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].cadena));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 250 "TP4Bison.y"
    {strcat(tipo, "*");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 266 "TP4Bison.y"
    {gestionar_identificador(&listaVariables, (yyvsp[(1) - (1)].cadena), tipo, archivoFinal);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 268 "TP4Bison.y"
    {gestionar_identificador(&listaVariables, (yyvsp[(1) - (4)].cadena), tipo, archivoFinal);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 269 "TP4Bison.y"
    {gestionar_funcion(&listaVariables, listaParametros,(yyvsp[(1) - (4)].cadena), tipo, archivoFinal);listaParametros = NULL;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 270 "TP4Bison.y"
    {gestionar_funcion(&listaVariables, listaParametros,(yyvsp[(1) - (4)].cadena), tipo, archivoFinal);listaParametros = NULL;;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 288 "TP4Bison.y"
    {agregar_info(&listaParametros, tipo_parametro); memset(tipo_parametro, 0, 30);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 289 "TP4Bison.y"
    {agregar_info(&listaParametros, tipo_parametro); memset(tipo_parametro, 0, 30);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 292 "TP4Bison.y"
    {strcpy(tipo_parametro, (yyvsp[(1) - (2)].cadena));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 293 "TP4Bison.y"
    {if(tipo_parametro[0] == '\0'){strcpy(tipo_parametro, (yyvsp[(1) - (2)].cadena));};;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 294 "TP4Bison.y"
    {if(tipo_parametro[0] == '\0'){strcpy(tipo_parametro, (yyvsp[(1) - (2)].cadena));};;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 302 "TP4Bison.y"
    {strcat(tipo_parametro, "*");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 311 "TP4Bison.y"
    {agregar_info(&listaParametros, "int");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 312 "TP4Bison.y"
    {agregar_info(&listaParametros, "int");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 320 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(2) - (2)].cadena));;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 357 "TP4Bison.y"
    {memset(tipo, 0, 30);;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 384 "TP4Bison.y"
    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "expresion OR");;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 388 "TP4Bison.y"
    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "expresion AND");;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 392 "TP4Bison.y"
    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "expresion IGUALDAD");;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 393 "TP4Bison.y"
    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "expresion DIFERENCIA");;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 397 "TP4Bison.y"
    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "expresion RELACIONAL");;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 401 "TP4Bison.y"
    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "expresion SUMA");;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 402 "TP4Bison.y"
    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "expresion RESTA");;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 406 "TP4Bison.y"
    {if(!control_tipos(tipo, "int") && !control_tipos(tipo, "int*")){fprintf(archivoFinal,"No se puede realizar la operación MULTIPLICACION con el tipo de dato %s \n", tipo);};}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 407 "TP4Bison.y"
    {if(!control_tipos(tipo, "int") && !control_tipos(tipo, "int*")){fprintf(archivoFinal,"No se puede realizar la operación DIVISION con el tipo de dato %s \n", tipo);};}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 408 "TP4Bison.y"
    {if(!control_tipos(tipo, "int") && !control_tipos(tipo, "int*")){fprintf(archivoFinal,"No se puede realizar la operación RESTO con el tipo de dato %s \n", tipo);};}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 426 "TP4Bison.y"
    {sentencia_funcion(&listaVariables, listaParametros, (yyvsp[(1) - (4)].cadena), archivoFinal);;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 438 "TP4Bison.y"
    {agregar_info(&listaParametros, tipo_variable(listaVariables, (yyvsp[(1) - (1)].cadena), archivoFinal));;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 439 "TP4Bison.y"
    {agregar_info(&listaParametros, "int");;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 440 "TP4Bison.y"
    {agregar_info(&listaParametros, "float");;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 441 "TP4Bison.y"
    {agregar_info(&listaParametros, "char*");;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 444 "TP4Bison.y"
    {char* comparar_tipo = tipo_variable(listaVariables, (yyvsp[(1) - (1)].cadena), archivoFinal);if(strcmp(comparar_tipo, "error")){if(tipo[0] == '\0'){strcpy(tipo, comparar_tipo);}else if(!control_tipos(tipo, comparar_tipo)){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un %s y un %s\n", comparar_tipo, tipo);}};}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 445 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, "int");}else if(!control_tipos(tipo, "int")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un int y un %s\n", tipo);};;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 446 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, "float");}else if(!control_tipos(tipo, "float")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un float y un %s\n", tipo);};}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 447 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, "char*");}else if(!control_tipos(tipo, "char*")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un char* y un %s\n", tipo);};}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 507 "TP4Bison.y"
    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "SWITCH");;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 511 "TP4Bison.y"
    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "IF");;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 512 "TP4Bison.y"
    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "ELSE IF");;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 515 "TP4Bison.y"
    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "WHILE");;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 516 "TP4Bison.y"
    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "DO");;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 517 "TP4Bison.y"
    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "FOR");;}
    break;



/* Line 1455 of yacc.c  */
#line 2189 "TP4Bison.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 536 "TP4Bison.y"


int main ()
{
  yyin = fopen("entrada.txt", "r");
  yyout = fopen("salida.txt", "w");
  archivoFinal = fopen("Informe.txt", "w");

                         
  fprintf(archivoFinal, "------------------------- ERRORES SEMÁNTICOS --------------------------\n\n * Se encontraron los siguientes errores semánticos:\n\n");



  yyparse();
  yylex();

  
  imprimir_lista_variables(listaVariables, archivoFinal);
  imprimir_validaciones_sintacticas(&listaDeValidacionesSintacticas, archivoFinal);
  imprimir_funciones(listaVariables, archivoFinal);
  imprimir_errores(&listaErroresLexicos, archivoFinal);
  imprimir_errores_sintacticos(&listaErroresSintacticos, archivoFinal);



  fclose(archivoFinal);
  return 0;
  //yydebug = 1; --> Utilizar en caso de MODO DEBUG

}


int control_tipos(char palabra[], char tipo[]) {
  if(!strcmp(palabra, tipo)){
    return 1;
  }
  if((!strcmp(tipo, "int") || !strcmp(tipo, "float") || !strcmp(palabra, "char")) && (!strcmp(palabra, "int") || !strcmp(palabra, "float") || !strcmp(palabra, "char"))){
    return 1;
  }
  if((!strcmp(tipo, "int*") || !strcmp(tipo, "float*")) && (!strcmp(palabra, "int*") || !strcmp(palabra, "float*"))){
    return 1;
  }
  if((!strcmp(tipo, "char*") || !strcmp(tipo, "int*") || !strcmp(tipo, "float*")) && (!strcmp(palabra, "void*"))){
    return 1;
  }
  if((!strcmp(palabra, "char*") || !strcmp(palabra, "int*") || !strcmp(palabra, "float*")) && (!strcmp(tipo, "void*"))){
    return 1;
  }
  if((!strcmp(tipo, "const") || !strcmp(tipo, "volatile") || !strcmp(tipo, "typedef") || !strcmp(tipo, "int")) && (!strcmp(palabra, "const") || !strcmp(palabra, "volatile") || !strcmp(palabra, "typedef") || !strcmp(palabra, "int"))){
    return 1;
  }
  return 0;
}

nodo* existe_variable(nodo* lista, char nombre[]){
    nodo* aux = lista;
    while(aux){
        if(!strcmp(aux->info.identificador, nombre)){
            return aux;
        }
        aux = aux->sig;
    }
    return NULL;
}

char* tipo_variable(nodo* lista, char nombre[], FILE* arcFinal){
  nodo* variable = existe_variable(lista, nombre);
  if(variable == NULL){
    fprintf(arcFinal, "La variable %s no fue declarada\n", nombre);
    return "error";
  } 
  return variable->info.tipo;
}

void agregar_info(nodoInfo** listaParametros, char tipo[]){
  nodoInfo* aux = (*listaParametros);
  while(aux != NULL && aux->sig != NULL){
      aux = aux->sig;
  }
  if(aux == NULL){
    (*listaParametros) = malloc(sizeof(nodoInfo));
    strcpy((*listaParametros)->info, tipo);
    (*listaParametros)->sig = NULL;
    return;
  }
  aux->sig = malloc(sizeof(nodoInfo));
  strcpy(aux->sig->info, tipo);
  aux->sig->sig = NULL;
  return;
}

void agregar_parametro(nodoInfo** listaParametros, char tipo[]){
  nodoInfo* aux = (*listaParametros);
  while(aux != NULL && aux->sig != NULL){
      aux = aux->sig;
  }
  if(aux == NULL){
    (*listaParametros) = malloc(sizeof(nodoInfo));
    strcpy((*listaParametros)->info, tipo);
    (*listaParametros)->sig = NULL;
    return;
  }
  aux->sig = malloc(sizeof(nodoInfo));
  strcpy(aux->sig->info, tipo);
  aux->sig->sig = NULL;
  return;
}

int agregar_variable(nodo** lista, char nombre[], char tipo[]){
    if(existe_variable(*lista, nombre) != NULL){
        return 0;
    }
    nodo* aux = (*lista);
    while(aux != NULL && aux->sig != NULL){
        aux = aux->sig;
    }
    if(aux == NULL){
      (*lista) = malloc(sizeof(nodo));
      (*lista)->info.es_funcion = 0;
      (*lista)->info.listaParametros = NULL;
      strcpy((*lista)->info.identificador, nombre);
      strcpy((*lista)->info.tipo, tipo);
      (*lista)->sig = NULL;
      return 1;
    }
    aux->sig = malloc(sizeof(nodo));
    strcpy(aux->sig->info.identificador, nombre);
    strcpy(aux->sig->info.tipo, tipo);
    aux->sig->info.es_funcion = 0;
    aux->sig->info.listaParametros = NULL;
    aux->sig->sig = NULL;
    return 1;
}

void agregar_funcion(nodo** lista, char nombre[], char tipo[], nodoInfo* listaParametros){
    nodo* aux = (*lista);
    while(aux != NULL && aux->sig != NULL){
        aux = aux->sig;
    }
    if(aux == NULL){
      (*lista) = malloc(sizeof(nodo));
      (*lista)->info.es_funcion = 1;
      (*lista)->info.listaParametros = listaParametros;
      strcpy((*lista)->info.identificador, nombre);
      strcpy((*lista)->info.tipo, tipo);
      (*lista)->sig = NULL;
      return;
    }
    aux->sig = malloc(sizeof(nodo));
    strcpy(aux->sig->info.identificador, nombre);
    strcpy(aux->sig->info.tipo, tipo);
    aux->sig->info.es_funcion = 1;
    aux->sig->info.listaParametros = listaParametros;
    aux->sig->sig = NULL;
}

void gestionar_identificador(nodo** listaVariables, char nombre[], char tipo[], FILE* archivoFinal){
    if(!agregar_variable(listaVariables, nombre, tipo)){
      fprintf(archivoFinal, "Doble declaración de la variable: %s \n", nombre);
    }    
}

void gestionar_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], char tipo[], FILE* archivoFinal){
    nodo* aux = existe_variable(*lista, identificador);
    if(aux == NULL){
        agregar_funcion(lista, identificador, tipo, listaParametros);
    } else {
        parametros_contra_funcion(aux, listaParametros, archivoFinal);           
    }
}

void sentencia_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], FILE* archivoFinal){
  nodo* aux = existe_variable(*lista, identificador);
    if(aux == NULL){
        fprintf(archivoFinal, "La funcion %s no fue declarada\n", identificador);
    } else {
        parametros_contra_funcion(aux, listaParametros, archivoFinal);           
    }
}

int parametros_contra_funcion(nodo* funcion, nodoInfo* listaParametros, FILE* archivoFinal){
  nodoInfo* auxLista = funcion->info.listaParametros;
  nodoInfo* auxParam = listaParametros;
  int contador_parametros = 0;
  while(auxParam != NULL && auxLista != NULL){
    if(!control_tipos(auxParam->info, auxLista->info)){
      fprintf(archivoFinal, "La funcion %s esperaba una variable de tipo %s como parametro %d, pero recibio %s\n", funcion->info.identificador, auxLista->info, contador_parametros, auxParam->info);
      return 0;
    }
    auxLista = auxLista->sig;
    auxParam = auxParam->sig;
  }
  if(auxLista != NULL){
    fprintf(archivoFinal, "La funcion %s esperaba mas parametros de los recibidos\n", funcion->info.identificador); 
    return 0;
  } 
  if (auxParam != NULL){
    fprintf(archivoFinal, "La funcion %s recibio menos parametros de los esperados\n", funcion->info.identificador);     
  }
  return 1;
}

void imprimir_parametros(nodoInfo* lista, FILE* archivoFinal){
  nodoInfo* aux = lista;
  int i = 0;
  while(aux != NULL){
    fprintf(archivoFinal, "\t\t\tIdentificador N°: %d\t Tipo: %s\n", i, aux->info);
    aux = aux->sig;
    i++;
  }
}

void imprimir_lista_variables(nodo* lista, FILE* archivoFinal){
                             
  fprintf(archivoFinal, "\n\n----------------------------- VARIABLES -------------------------------\n\n * Se encontraron las siguientes variables declaradas:\n\n");
  nodo* aux = lista;
  while(aux != NULL){
    if(aux->info.es_funcion == 0){
      fprintf(archivoFinal, "Identificador: %s\t Tipo: %s\n", aux->info.identificador, aux->info.tipo);
    }
    aux = aux->sig;
  }
}

void imprimir_funciones(nodo* lista, FILE* archivoFinal){
  nodo* aux = lista;       
  fprintf(archivoFinal, "\n----------------------------- FUNCIONES -------------------------------\n\n * Se encontraron las siguientes funciones declaradas:\n\n");
  while(aux != NULL){
    if(aux->info.es_funcion == 1){
      fprintf(archivoFinal, "IDENTIFICADOR: %s\n\t Tipo Retorno: %s\n\t Parametros:\n", aux->info.identificador, aux->info.tipo);
      imprimir_parametros(aux->info.listaParametros, archivoFinal);
    }    
    aux = aux->sig;
  }
}
                           
void imprimir_errores(nodoInfo** lista, FILE* archivoFinal){
  nodoInfo* aux;
  fprintf(archivoFinal, "\n--------------------------- ERRORES LÉXICOS ---------------------------\n\n * Se encontraron los siguientes errores léxicos:\n\n");
  while(*lista){
    aux = (*lista);
    fprintf(archivoFinal, "%s\n", aux->info);
    (*lista) = aux->sig;
    free(aux->info);
    free(aux);
  }
}

void imprimir_errores_sintacticos(nodoErroresSintacticos** lista, FILE* archivoFinal){
  nodoErroresSintacticos* aux;
  fprintf(archivoFinal, "\n------------------------- ERRORES SINTÁCTICOS -------------------------\n\n * Se encontraron errores sintácticos en las siguientes lineas:");
  fprintf(archivoFinal, "\n\n_____________________________\n");
  fprintf(archivoFinal, "│    ERRORES SINTÁCTICOS    │\n");
  fprintf(archivoFinal, "│___________________________│\n");
  fprintf(archivoFinal, "│      Número de Línea      │\n");
  fprintf(archivoFinal, "│___________________________│\n");
  fprintf(archivoFinal, "│                           │\n");
  while(*lista){
    aux = (*lista);
    fprintf(archivoFinal, "│            %-14d │\n", aux->linea);
    (*lista) = aux->sig;
    free(aux);
  }
  fprintf(archivoFinal, "│___________________________│\n\n");
}

void agregar_error_sintactico(nodoErroresSintacticos** listaParametros, int nroLinea){
  nodoErroresSintacticos* aux = (*listaParametros);
  while(aux != NULL && aux->sig != NULL){
      aux = aux->sig;
  }
  if(aux == NULL){
    (*listaParametros) = malloc(sizeof(nodoErroresSintacticos));
    (*listaParametros)->linea = nroLinea;
    (*listaParametros)->sig = NULL;
    return;
  }
  aux->sig = malloc(sizeof(nodoErroresSintacticos));
  aux->sig->linea = nroLinea;
  aux->sig->sig = NULL;
  return;
}


void agregar_validaciones_sintacticas(nodoValidacionesSintacticas** listaParametros, int nroLinea , char mensaje[]){
  nodoValidacionesSintacticas* aux = (*listaParametros);
  while(aux != NULL && aux->sig != NULL){
      aux = aux->sig;
  }
  if(aux == NULL){
    (*listaParametros) = malloc(sizeof(nodoValidacionesSintacticas));
    strcpy((*listaParametros)->info, mensaje);
    (*listaParametros)->linea = nroLinea;
    (*listaParametros)->sig = NULL;
    return;
  }
  aux->sig = malloc(sizeof(nodoValidacionesSintacticas));
  strcpy(aux->sig->info, mensaje);
  aux->sig->linea = nroLinea;
  aux->sig->sig = NULL;
  return;
}


/*
    fprintf(archivoFinal, "\n\n_______________________________________________________________________\n");
    fprintf(archivoFinal, "|                    Lista de Palabras Reservadas                     |\n");
    fprintf(archivoFinal, "|_____________________________________________________________________|\n");
    fprintf(archivoFinal, "|             Lexema     |                 Categoria                  |\n");
    fprintf(archivoFinal, "|________________________|____________________________________________|\n");

    imprimirCola(PalabrasReservadas, archivoFinal, P_RESERVADA);
    fprintf(archivoFinal, "|________________________|____________________________________________|\n\n");*/

void imprimir_validaciones_sintacticas(nodoValidacionesSintacticas** lista, FILE* archivoFinal){
  nodoValidacionesSintacticas* aux;
   fprintf(archivoFinal, "\n----------------------------- SENTENCIAS ------------------------------\n\n");
  fprintf(archivoFinal, " * Se encontraron las siguientes sentencias:");
  fprintf(archivoFinal, "\n\n_______________________________________________________________________\n");
  fprintf(archivoFinal, "│                             SENTENCIAS                              │\n");
  fprintf(archivoFinal, "│_____________________________________________________________________│\n");
  fprintf(archivoFinal, "│               Tipo                  │       Número de Línea         │\n");
  fprintf(archivoFinal, "│_____________________________________│_______________________________│\n");
  fprintf(archivoFinal, "│                                     │                               │\n");
  while(*lista){
    aux = (*lista);
    fprintf(archivoFinal, "│ %-34s  │              %-16d │\n", aux->info, aux->linea);
    (*lista) = aux->sig;
    free(aux);
  }
  fprintf(archivoFinal, "│_____________________________________│_______________________________│\n\n");
}




