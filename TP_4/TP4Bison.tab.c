
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

int control_tipos(char palabra[], char tipo[]);
nodo* existe_variable(nodo* lista, char nombre[]);
char* tipo_variable(nodo* lista, char nombre[], FILE* arcFinal);
void agregar_parametro(nodoInfo** listaParametros, char tipo[]);
int agregar_variable(nodo** lista, char nombre[], char tipo[]);
void agregar_funcion(nodo** lista, char nombre[], char tipo[], nodoInfo* listaParametros);
void agregar_error(nodoInfo* lista, char error[]);
void gestionar_identificador(nodo** listaVariables, char nombre[], char tipo[], FILE* archivoFinal);
void gestionar_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], char tipo[], FILE* archivoFinal);
void sentencia_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], FILE* archivoFinal);
int parametros_contra_funcion(nodo* funcion, nodoInfo* listaParametros, FILE* archivoFinal);
//void eliminar_ultimo(nodoVariable* listavariables);
//void pasar_a_lista_parametros(nodoVariable* listaParametros, nodoVariable* listavariables, int cantidad);

void imprimir_parametros(nodoInfo* lista, FILE* archivoFinal);
void imprimir_lista_variables(nodo* lista, FILE* archivoFinal);
void imprimir_funciones(nodo* lista, FILE* archivoFinal);
void imprimir_errores(nodoInfo** lista, FILE* archivoFinal);

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

FILE* archivoFinal;

int yylex();

int yywrap(){
	return(1);
}

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
}



/* Line 189 of yacc.c  */
#line 148 "TP4Bison.tab.c"

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
#line 75 "TP4Bison.y"

char cadena[30];
int entero;
int tipo;
float real;



/* Line 214 of yacc.c  */
#line 229 "TP4Bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 241 "TP4Bison.tab.c"

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   517

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNRULES -- Number of states.  */
#define YYNSTATES  295

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
       0,     0,     3,     4,     7,     9,    12,    15,    19,    23,
      24,    26,    29,    32,    35,    36,    38,    40,    44,    46,
      50,    52,    56,    61,    63,    67,    69,    71,    73,    75,
      77,    79,    85,    88,    89,    91,    93,    95,    98,   101,
     105,   108,   111,   112,   114,   116,   120,   122,   126,   129,
     130,   132,   135,   139,   140,   142,   144,   147,   148,   150,
     152,   156,   161,   166,   171,   173,   175,   181,   182,   184,
     186,   190,   194,   198,   201,   204,   207,   208,   210,   211,
     213,   215,   220,   225,   227,   229,   233,   234,   236,   242,
     245,   247,   251,   253,   257,   259,   263,   268,   273,   278,
     279,   281,   283,   287,   288,   290,   292,   296,   298,   300,
     301,   303,   305,   307,   311,   313,   317,   319,   323,   327,
     329,   333,   335,   339,   343,   345,   349,   353,   357,   359,
     362,   365,   370,   372,   374,   376,   378,   380,   382,   387,
     392,   393,   395,   397,   401,   403,   405,   407,   409,   411,
     413,   415,   417,   421,   423,   425,   427,   429,   431,   433,
     435,   440,   442,   445,   446,   448,   450,   453,   454,   456,
     459,   465,   473,   479,   485,   493,   503,   508,   512,   516,
     520,   523,   526
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      54,     0,    -1,    -1,    54,    55,    -1,    37,    -1,   120,
      37,    -1,    56,    37,    -1,    58,    57,    38,    -1,    58,
      57,   121,    -1,    -1,    60,    -1,    64,    59,    -1,    65,
      59,    -1,    66,    59,    -1,    -1,    58,    -1,    61,    -1,
      60,    39,    61,    -1,    76,    -1,    76,    27,    62,    -1,
     102,    -1,    40,    63,    41,    -1,    40,    63,    39,    41,
      -1,    62,    -1,    63,    39,    62,    -1,    36,    -1,     6,
      -1,    67,    -1,    93,    -1,    24,    -1,    25,    -1,    69,
      68,    40,    70,    41,    -1,    69,     5,    -1,    -1,     5,
      -1,    22,    -1,    23,    -1,    71,    38,    -1,    70,    71,
      -1,    72,    74,    38,    -1,    65,    73,    -1,    66,    73,
      -1,    -1,    72,    -1,    75,    -1,    74,    39,    75,    -1,
      76,    -1,    77,    42,   104,    -1,    79,    82,    -1,    -1,
      76,    -1,    43,    81,    -1,    43,    81,    78,    -1,    -1,
      78,    -1,    66,    -1,    80,    66,    -1,    -1,    80,    -1,
       5,    -1,    44,    76,    45,    -1,     5,    46,   105,    47,
      -1,     5,    44,    83,    45,    -1,     5,    44,    92,    45,
      -1,     1,    -1,    85,    -1,    85,    39,    48,    48,    48,
      -1,    -1,    83,    -1,    86,    -1,    85,    39,    86,    -1,
      87,    89,    90,    -1,    87,    89,    99,    -1,     6,    88,
      -1,    24,    88,    -1,    25,    88,    -1,    -1,    87,    -1,
      -1,    43,    -1,     5,    -1,    44,    89,    90,    45,    -1,
       5,    46,   105,    47,    -1,     1,    -1,     5,    -1,    91,
      39,     5,    -1,    -1,    91,    -1,    26,    68,    40,    94,
      41,    -1,    26,     5,    -1,    95,    -1,    94,    39,    95,
      -1,    96,    -1,    96,    27,   104,    -1,     5,    -1,    72,
      89,    99,    -1,    44,    89,    99,    45,    -1,    99,    46,
     105,    47,    -1,    99,    44,    84,    45,    -1,    -1,    98,
      -1,   102,    -1,   100,    39,   102,    -1,    -1,   100,    -1,
     106,    -1,   113,   103,   102,    -1,    27,    -1,   106,    -1,
      -1,   104,    -1,   107,    -1,   108,    -1,   107,    28,   108,
      -1,   109,    -1,   108,    29,   109,    -1,   110,    -1,   109,
      30,   110,    -1,   109,    31,   110,    -1,   111,    -1,   110,
      32,   111,    -1,   112,    -1,   111,    49,   112,    -1,   111,
      50,   112,    -1,   113,    -1,   112,    43,   113,    -1,   112,
      51,   113,    -1,   112,    52,   113,    -1,   115,    -1,    33,
     113,    -1,   114,   113,    -1,    21,    44,    97,    45,    -1,
      35,    -1,    43,    -1,    50,    -1,    49,    -1,    34,    -1,
     119,    -1,   115,    46,   100,    47,    -1,     5,    44,   116,
      45,    -1,    -1,   117,    -1,   118,    -1,   117,    39,   118,
      -1,     5,    -1,     3,    -1,     4,    -1,     7,    -1,     5,
      -1,     3,    -1,     4,    -1,     7,    -1,    44,   100,    45,
      -1,     1,    -1,   121,    -1,   126,    -1,   127,    -1,   128,
      -1,   129,    -1,   130,    -1,    40,   123,   125,    41,    -1,
      56,    -1,   122,    56,    -1,    -1,   122,    -1,   120,    -1,
     124,   120,    -1,    -1,   124,    -1,   101,    38,    -1,    19,
      44,   100,    45,   120,    -1,    19,    44,   100,    45,   120,
      20,   120,    -1,    12,    44,   100,    45,   120,    -1,    10,
      44,   100,    45,   120,    -1,    11,   120,    10,    44,   100,
      45,    38,    -1,     9,    44,   101,    38,   101,    38,   101,
      45,   120,    -1,    16,   100,    42,   120,    -1,    17,    42,
     120,    -1,     5,    42,   120,    -1,    18,   101,    38,    -1,
      14,    38,    -1,    15,    38,    -1,    13,     5,    38,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   121,   121,   122,   125,   126,   127,   133,   134,   140,
     141,   144,   145,   146,   149,   150,   153,   154,   157,   158,
     161,   162,   163,   166,   167,   170,   173,   174,   175,   180,
     181,   184,   185,   188,   189,   192,   193,   196,   197,   200,
     203,   204,   207,   208,   211,   212,   215,   216,   219,   222,
     223,   226,   227,   230,   231,   234,   235,   238,   239,   242,
     243,   244,   245,   246,   247,   250,   251,   254,   255,   258,
     259,   262,   263,   266,   267,   268,   271,   272,   275,   276,
     279,   280,   281,   282,   285,   286,   289,   290,   293,   294,
     297,   298,   301,   302,   305,   308,   311,   312,   313,   316,
     317,   329,   330,   333,   334,   337,   338,   341,   344,   347,
     348,   351,   355,   356,   359,   360,   363,   364,   365,   368,
     369,   372,   373,   374,   377,   378,   379,   380,   383,   384,
     385,   386,   389,   390,   391,   392,   393,   396,   397,   398,
     401,   402,   406,   407,   410,   411,   412,   413,   416,   417,
     418,   419,   420,   421,   442,   443,   444,   445,   446,   447,
     450,   453,   454,   457,   458,   462,   463,   466,   467,   470,
     473,   474,   475,   478,   479,   480,   483,   484,   485,   488,
     489,   490,   491
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
  "'-'", "'/'", "'%'", "$accept", "input", "line", "declaracion",
  "listaDeclaradoresOP", "especificadoresDeclaracion",
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
  "sentExpresion", "sentSeleccion", "sentIteracion", "sentEtiquetada",
  "sentSalto", 0
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
       0,    53,    54,    54,    55,    55,    55,    56,    56,    57,
      57,    58,    58,    58,    59,    59,    60,    60,    61,    61,
      62,    62,    62,    63,    63,    64,    65,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    77,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      82,    82,    82,    82,    82,    83,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    87,    88,    88,    89,    89,
      90,    90,    90,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    97,    98,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   104,   105,
     105,   106,   107,   107,   108,   108,   109,   109,   109,   110,
     110,   111,   111,   111,   112,   112,   112,   112,   113,   113,
     113,   113,   114,   114,   114,   114,   114,   115,   115,   115,
     116,   116,   117,   117,   118,   118,   118,   118,   119,   119,
     119,   119,   119,   119,   120,   120,   120,   120,   120,   120,
     121,   122,   122,   123,   123,   124,   124,   125,   125,   126,
     127,   127,   127,   128,   128,   128,   129,   129,   129,   130,
     130,   130,   130
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     3,     3,     0,
       1,     2,     2,     2,     0,     1,     1,     3,     1,     3,
       1,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     5,     2,     0,     1,     1,     1,     2,     2,     3,
       2,     2,     0,     1,     1,     3,     1,     3,     2,     0,
       1,     2,     3,     0,     1,     1,     2,     0,     1,     1,
       3,     4,     4,     4,     1,     1,     5,     0,     1,     1,
       3,     3,     3,     2,     2,     2,     0,     1,     0,     1,
       1,     4,     4,     1,     1,     3,     0,     1,     5,     2,
       1,     3,     1,     3,     1,     3,     4,     4,     4,     0,
       1,     1,     3,     0,     1,     1,     3,     1,     1,     0,
       1,     1,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     4,     4,
       0,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     2,     0,     1,     1,     2,     0,     1,     2,
       5,     7,     5,     5,     7,     9,     4,     3,     3,     3,
       2,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,   153,   149,   150,   148,    26,   151,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    36,    29,    30,    33,     0,   136,   132,    25,
       4,   163,   133,     0,   135,   134,     3,     0,    53,    14,
      14,    14,    27,    33,    28,   104,     0,   101,   105,   111,
     112,   114,   116,   119,   121,   124,     0,   128,   137,     0,
     154,   155,   156,   157,   158,   159,     0,   140,     0,     0,
       0,     0,     0,   180,   181,   148,     0,     0,     0,     0,
       0,    89,     0,   129,   161,   164,     0,     0,     6,    57,
       0,    10,    16,    18,    54,     0,    15,    11,    12,    13,
      32,     0,     0,   169,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,   130,     0,     5,   178,
     145,   146,   144,   147,     0,   141,   142,     0,     0,     0,
       0,   182,     0,   177,   179,     0,    42,    42,    78,     0,
       0,   162,   165,     0,     0,   152,    55,    58,    51,     7,
       8,    53,     0,    64,    59,    53,    48,     0,   102,   113,
     124,   115,   117,   118,   120,   122,   123,   125,   126,   127,
     106,     0,   139,     0,     0,     0,     0,     0,   176,     0,
      43,    40,    41,    79,    99,   131,    94,     0,    90,    92,
     166,   160,    56,    52,    17,     0,    19,    20,    86,     0,
       0,     0,     0,    53,   138,   143,     0,   173,     0,   172,
     170,    78,   100,    95,     0,    88,     0,    23,     0,    84,
      76,    76,    76,     0,    65,    69,    78,    87,     0,   110,
       0,   108,    60,    31,    38,    37,     0,    44,    46,     0,
       0,     0,     0,    99,    67,     0,    91,    93,     0,    21,
      77,    73,    74,    75,    62,     0,     0,     0,    63,    61,
      39,    53,     0,     0,   174,   171,     0,    68,     0,     0,
      22,    24,     0,    70,    83,    80,    78,    71,    72,    85,
      45,    47,     0,    96,    98,    97,     0,     0,     0,   175,
      66,     0,     0,    82,    81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    36,    37,    90,    38,    97,    91,    92,   196,
     218,    39,    40,    41,    42,    82,    43,   201,   202,   180,
     181,   236,   237,    93,   239,    94,    95,   147,   148,   156,
     223,   268,   224,   225,   226,   251,   184,   277,   227,   228,
      44,   187,   188,   189,   139,   212,   266,    45,    46,    47,
     115,   229,   230,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   124,   125,   126,    58,    59,    60,    85,
      86,   143,   144,    61,    62,    63,    64,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -221
static const yytype_int16 yypact[] =
{
    -221,   192,  -221,  -221,  -221,  -221,   -10,  -221,  -221,    14,
      34,   342,    54,   102,    73,    80,   467,    92,   363,   107,
     116,  -221,  -221,  -221,  -221,   167,   467,  -221,  -221,  -221,
    -221,    21,  -221,   467,  -221,  -221,  -221,   147,   227,    21,
      21,    21,  -221,   185,  -221,   155,   162,  -221,  -221,   184,
     210,   100,   212,   173,   -23,   221,   467,   204,  -221,   229,
    -221,  -221,  -221,  -221,  -221,  -221,   342,   311,   363,   467,
     254,   467,   236,  -221,  -221,   237,    35,   342,   246,   467,
      15,   258,   260,  -221,  -221,    21,   242,   -27,  -221,   209,
     110,   255,  -221,   285,  -221,    25,  -221,  -221,  -221,  -221,
    -221,   277,   467,  -221,   467,   467,   467,   467,   467,   467,
     467,   467,   467,   467,  -221,   467,  -221,   467,  -221,  -221,
    -221,  -221,  -221,  -221,   283,   290,  -221,   293,   -26,   294,
      56,  -221,   342,  -221,  -221,    58,    15,    15,   291,   295,
     332,  -221,  -221,   292,   298,  -221,  -221,   209,   301,  -221,
    -221,   301,   136,  -221,   119,   301,  -221,    15,  -221,   210,
    -221,   100,   212,   212,   173,   -23,   -23,  -221,  -221,  -221,
    -221,    55,  -221,   311,   363,   342,   467,   342,  -221,   342,
    -221,  -221,  -221,  -221,   304,  -221,  -221,   134,  -221,   323,
    -221,  -221,  -221,  -221,  -221,   136,  -221,  -221,   263,   413,
     317,   103,   327,   230,  -221,  -221,   331,  -221,    75,  -221,
     351,   291,  -221,   175,   332,  -221,   467,  -221,   199,  -221,
     153,   153,   153,   328,   333,  -221,   291,   335,   334,  -221,
     336,  -221,  -221,  -221,  -221,  -221,   240,  -221,   339,   345,
     432,   340,   342,   304,   153,   413,  -221,  -221,   112,  -221,
    -221,  -221,  -221,  -221,  -221,    11,    60,   383,  -221,  -221,
    -221,   230,   467,   344,  -221,  -221,     4,  -221,   348,   343,
    -221,  -221,   346,  -221,  -221,   349,   291,  -221,   175,  -221,
    -221,  -221,   342,  -221,  -221,  -221,   352,   413,   137,  -221,
    -221,   355,   354,  -221,  -221
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -221,  -221,  -221,   -22,  -221,    83,   249,  -221,   252,  -184,
    -221,  -221,   -65,   -47,  -221,   361,  -221,  -221,   207,   -66,
     268,  -221,   148,  -149,  -221,   262,  -221,  -221,  -221,  -221,
     171,  -221,  -221,   156,   -33,    98,  -203,   131,  -221,  -221,
    -221,  -221,   208,  -221,  -221,  -221,  -180,    -9,   -16,   -99,
    -221,  -206,  -220,  -194,  -221,   319,   316,   215,   318,   214,
     -25,  -221,  -221,  -221,  -221,   251,  -221,   -11,   337,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -169
static const yytype_int16 yytable[] =
{
      70,    83,    78,   158,   213,   231,   200,    76,   243,    84,
     247,   217,   102,   102,   138,   136,   170,   220,   145,   175,
     111,     7,   231,   256,    87,   269,   153,     7,   112,   113,
     154,   116,    66,   137,    67,   221,   222,    21,    22,    23,
      24,    25,   146,    21,    22,    23,    24,    25,   244,   283,
     245,   231,   127,   197,   238,   119,   281,    29,    68,   272,
     128,   274,   130,   141,   271,   275,   133,   291,   231,   155,
     135,   136,   136,   288,   102,   142,   278,   132,    69,   160,
     160,   160,   160,   160,   160,   160,   167,   168,   169,   137,
     137,   203,   136,   231,   102,   102,   197,   102,    71,   -99,
     192,   177,   204,   179,   276,   -99,   -99,    72,   171,     7,
     137,    73,   238,     3,   102,     4,     5,    75,    74,     8,
     241,   178,    96,    96,    96,    21,    22,    23,    24,    25,
     106,   107,   190,    20,    77,   203,   136,     3,   274,     4,
       5,    75,   275,     8,   233,    26,    27,    28,   149,   197,
      31,    79,   195,   270,   137,    32,    33,    20,   206,   220,
      80,    34,    35,   198,   207,   199,   209,   208,   210,    26,
      27,    28,    81,   214,   160,   215,   195,   221,   222,    32,
      33,   276,   -99,   -99,    88,    34,    35,   250,   250,   250,
     100,   160,     2,     3,   102,     4,     5,     6,     7,     8,
     103,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   104,    20,    21,    22,    23,    24,    25,   244,
     160,   245,   109,   110,   263,    26,    27,    28,    29,    30,
    -103,   265,    31,    23,    24,    32,    33,   160,   248,   105,
     249,    34,    35,     3,   108,     4,     5,     6,   114,     8,
     117,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   160,    20,   129,    -9,   118,    -9,   219,   220,
      89,   289,   -49,    89,   131,    26,    27,    28,   260,   261,
    -103,    67,    31,  -167,   134,    32,    33,   221,   222,    98,
      99,    34,    35,     3,   151,     4,     5,     6,   -34,     8,
     140,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   152,    20,   120,   121,   122,   157,   123,   252,
     253,   162,   163,   165,   166,    26,    27,    28,   172,   173,
    -103,   174,    31,  -168,   183,    32,    33,   186,   176,   191,
     185,    34,    35,     3,    89,     4,     5,     6,   211,     8,
     216,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   232,    20,     3,   235,     4,     5,    75,   240,
       8,   242,   255,   254,   257,    26,    27,    28,   264,   258,
    -103,   -50,    31,   259,    20,    32,    33,   262,   279,   282,
     285,    34,    35,   284,   286,   287,    26,    27,    28,   294,
     290,  -103,   293,   194,   101,   182,    32,    33,   234,   280,
     193,   273,    34,    35,     3,   267,     4,     5,    75,   292,
       8,   161,   246,   159,   205,     0,   164,   150,     0,     0,
       0,     0,     0,     3,    20,     4,     5,    75,     0,     8,
       0,     0,     0,     0,     0,     0,    26,    27,    28,     0,
       0,     0,     0,    20,     0,     0,    32,    33,     0,     0,
    -109,     0,    34,    35,     0,    26,    27,    28,     3,     0,
       4,     5,    75,     0,     8,    32,    33,  -103,     0,     0,
       0,    34,    35,     0,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    27,    28,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,     0,     0,    34,    35
};

static const yytype_int16 yycheck[] =
{
      11,    26,    18,   102,   184,   199,   155,    16,   211,    31,
     216,   195,    39,    39,    80,    80,   115,     6,    45,    45,
      43,     6,   216,   226,    33,   245,     1,     6,    51,    52,
       5,    56,    42,    80,    44,    24,    25,    22,    23,    24,
      25,    26,    89,    22,    23,    24,    25,    26,    44,    45,
      46,   245,    68,   152,   203,    66,   262,    36,    44,    48,
      69,     1,    71,    85,   248,     5,    77,   287,   262,    44,
      79,   136,   137,   276,    39,    86,   256,    42,    44,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   136,
     137,   157,   157,   287,    39,    39,   195,    39,    44,    39,
     147,    45,    47,    45,    44,    45,    46,     5,   117,     6,
     157,    38,   261,     1,    39,     3,     4,     5,    38,     7,
      45,   132,    39,    40,    41,    22,    23,    24,    25,    26,
      30,    31,   143,    21,    42,   201,   201,     1,     1,     3,
       4,     5,     5,     7,    41,    33,    34,    35,    38,   248,
      40,    44,    40,    41,   201,    43,    44,    21,   174,     6,
      44,    49,    50,    44,   175,    46,   177,   176,   179,    33,
      34,    35,     5,    39,   199,    41,    40,    24,    25,    43,
      44,    44,    45,    46,    37,    49,    50,   220,   221,   222,
       5,   216,     0,     1,    39,     3,     4,     5,     6,     7,
      38,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    28,    21,    22,    23,    24,    25,    26,    44,
     245,    46,    49,    50,   240,    33,    34,    35,    36,    37,
      38,   242,    40,    24,    25,    43,    44,   262,    39,    29,
      41,    49,    50,     1,    32,     3,     4,     5,    27,     7,
      46,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   287,    21,    10,    38,    37,    40,     5,     6,
      43,   282,    42,    43,    38,    33,    34,    35,    38,    39,
      38,    44,    40,    41,    38,    43,    44,    24,    25,    40,
      41,    49,    50,     1,    39,     3,     4,     5,    40,     7,
      40,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    27,    21,     3,     4,     5,    40,     7,   221,
     222,   106,   107,   109,   110,    33,    34,    35,    45,    39,
      38,    38,    40,    41,    43,    43,    44,     5,    44,    41,
      45,    49,    50,     1,    43,     3,     4,     5,    44,     7,
      27,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    45,    21,     1,    38,     3,     4,     5,    38,
       7,    20,    39,    45,    39,    33,    34,    35,    38,    45,
      38,    42,    40,    47,    21,    43,    44,    42,     5,    45,
      47,    49,    50,    45,    48,    46,    33,    34,    35,    45,
      48,    38,    47,   151,    43,   137,    43,    44,   201,   261,
     148,   255,    49,    50,     1,   244,     3,     4,     5,   288,
       7,   105,   214,   104,   173,    -1,   108,    90,    -1,    -1,
      -1,    -1,    -1,     1,    21,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    43,    44,    -1,    -1,
      47,    -1,    49,    50,    -1,    33,    34,    35,     1,    -1,
       3,     4,     5,    -1,     7,    43,    44,    45,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    49,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,     0,     1,     3,     4,     5,     6,     7,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      21,    22,    23,    24,    25,    26,    33,    34,    35,    36,
      37,    40,    43,    44,    49,    50,    55,    56,    58,    64,
      65,    66,    67,    69,    93,   100,   101,   102,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   119,   120,
     121,   126,   127,   128,   129,   130,    42,    44,    44,    44,
     120,    44,     5,    38,    38,     5,   100,    42,   101,    44,
      44,     5,    68,   113,    56,   122,   123,   100,    37,    43,
      57,    60,    61,    76,    78,    79,    58,    59,    59,    59,
       5,    68,    39,    38,    28,    29,    30,    31,    32,    49,
      50,    43,    51,    52,    27,   103,   113,    46,    37,   120,
       3,     4,     5,     7,   116,   117,   118,   101,   100,    10,
     100,    38,    42,   120,    38,   100,    65,    66,    72,    97,
      40,    56,   120,   124,   125,    45,    66,    80,    81,    38,
     121,    39,    27,     1,     5,    44,    82,    40,   102,   108,
     113,   109,   110,   110,   111,   112,   112,   113,   113,   113,
     102,   100,    45,    39,    38,    45,    44,    45,   120,    45,
      72,    73,    73,    43,    89,    45,     5,    94,    95,    96,
     120,    41,    66,    78,    61,    40,    62,   102,    44,    46,
      76,    70,    71,    72,    47,   118,   101,   120,   100,   120,
     120,    44,    98,    99,    39,    41,    27,    62,    63,     5,
       6,    24,    25,    83,    85,    86,    87,    91,    92,   104,
     105,   106,    45,    41,    71,    38,    74,    75,    76,    77,
      38,    45,    20,    89,    44,    46,    95,   104,    39,    41,
      87,    88,    88,    88,    45,    39,    89,    39,    45,    47,
      38,    39,    42,   101,    38,   120,    99,    83,    84,   105,
      41,    62,    48,    86,     1,     5,    44,    90,    99,     5,
      75,   104,    45,    45,    45,    47,    48,    46,    89,   120,
      48,   105,    90,    47,    45
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
#line 125 "TP4Bison.y"
    {fprintf(archivoFinal,"\n--------------------------------------- \n \n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 126 "TP4Bison.y"
    {fprintf(archivoFinal,"\n-----------------SENTENCIA---------------- \n \n");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 127 "TP4Bison.y"
    {fprintf(archivoFinal,"\n-----------------DECLARACION---------------- \n \n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 133 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una declaracion \n");memset(tipo, 0, 30);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 134 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontró una desarrollo de función");memset(tipo, 0, 30);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 140 "TP4Bison.y"
    {memset(tipo, 0, 30);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 154 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro mas de una declaracion \n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 158 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una asignacion \n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 170 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, (yyvsp[(1) - (1)].cadena));};;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 173 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].cadena)) ;fprintf(archivoFinal, "se encontro el tipo de dato %s \n", tipo);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 180 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, (yyvsp[(1) - (1)].cadena));};;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 181 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, (yyvsp[(1) - (1)].cadena));};;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 185 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(2) - (2)].cadena));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 189 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].cadena));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 226 "TP4Bison.y"
    {strcat(tipo, "*");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 242 "TP4Bison.y"
    {gestionar_identificador(&listaVariables, (yyvsp[(1) - (1)].cadena), tipo, archivoFinal);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 244 "TP4Bison.y"
    {gestionar_identificador(&listaVariables, (yyvsp[(1) - (4)].cadena), tipo, archivoFinal);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 245 "TP4Bison.y"
    {gestionar_funcion(&listaVariables, listaParametros,(yyvsp[(1) - (4)].cadena), tipo, archivoFinal);listaParametros = NULL;fprintf(archivoFinal, "se encontro una funcion \n");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 246 "TP4Bison.y"
    {gestionar_funcion(&listaVariables, listaParametros,(yyvsp[(1) - (4)].cadena), tipo, archivoFinal);listaParametros = NULL; fprintf(archivoFinal, "se encontro una funcion \n");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 247 "TP4Bison.y"
    {flag_error=1;fprintf(archivoFinal,"error xd \n");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 262 "TP4Bison.y"
    {agregar_parametro(&listaParametros, tipo_parametro); memset(tipo_parametro, 0, 30);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 263 "TP4Bison.y"
    {agregar_parametro(&listaParametros, tipo_parametro); memset(tipo_parametro, 0, 30);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 266 "TP4Bison.y"
    {strcpy(tipo_parametro, (yyvsp[(1) - (2)].cadena));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 267 "TP4Bison.y"
    {if(tipo_parametro[0] == '\0'){strcpy(tipo_parametro, (yyvsp[(1) - (2)].cadena));};;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 268 "TP4Bison.y"
    {if(tipo_parametro[0] == '\0'){strcpy(tipo_parametro, (yyvsp[(1) - (2)].cadena));};;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 276 "TP4Bison.y"
    {strcat(tipo_parametro, "*");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 282 "TP4Bison.y"
    {flag_error=1;fprintf(archivoFinal,"error xd \n");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 285 "TP4Bison.y"
    {agregar_parametro(&listaParametros, "int");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 286 "TP4Bison.y"
    {agregar_parametro(&listaParametros, "int");;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 294 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(2) - (2)].cadena));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 329 "TP4Bison.y"
    {memset(tipo, 0, 30);;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 356 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion OR \n");;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 360 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion AND \n");;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 364 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de IGUALDAD \n");;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 365 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de DIFERENCIA \n");;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 369 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion RELACIONAL \n");;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 373 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de SUMA \n");;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 374 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de RESTA \n");;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 378 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de MULTIPLICACION \n");;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 379 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de DIVISION \n");;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 380 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de RESTO \n");;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 398 "TP4Bison.y"
    {sentencia_funcion(&listaVariables, listaParametros, (yyvsp[(1) - (4)].cadena), archivoFinal);;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 410 "TP4Bison.y"
    {agregar_parametro(&listaParametros, tipo_variable(listaVariables, (yyvsp[(1) - (1)].cadena), archivoFinal));;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 411 "TP4Bison.y"
    {agregar_parametro(&listaParametros, "int");;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 412 "TP4Bison.y"
    {agregar_parametro(&listaParametros, "float");;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 413 "TP4Bison.y"
    {agregar_parametro(&listaParametros, "char*");;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 416 "TP4Bison.y"
    {char* comparar_tipo = tipo_variable(listaVariables, (yyvsp[(1) - (1)].cadena), archivoFinal);if(strcmp(comparar_tipo, "error")){if(tipo[0] == '\0'){strcpy(tipo, comparar_tipo);}else if(!control_tipos(tipo, comparar_tipo)){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un %s y un %s\n", comparar_tipo, tipo);}};}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 417 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, "int");}else if(!control_tipos(tipo, "int")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un int y un %s\n", tipo);};}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 418 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, "float");}else if(!control_tipos(tipo, "float")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un float y un %s\n", tipo);};}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 419 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, "char*");}else if(!control_tipos(tipo, "char*")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un char* y un %s\n", tipo);};}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 421 "TP4Bison.y"
    {flag_error=1;fprintf(archivoFinal,"Expresion unaria no valida \n");;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 443 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion \n");;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 444 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia de seleccion \n");;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 445 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia de iteracion \n");;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 446 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia etiquetada \n");;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 447 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia de salto \n");;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 450 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una sentencia compuesta \n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2185 "TP4Bison.tab.c"
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
#line 499 "TP4Bison.y"


int main ()
{
  yyin = fopen("entrada.txt", "r");
  yyout = fopen("salida.txt", "w");
  archivoFinal = fopen("Informe.txt", "w");


  yyparse();
  yylex();

  imprimir_lista_variables(listaVariables, archivoFinal);
  imprimir_funciones(listaVariables, archivoFinal);
  imprimir_errores(&listaErroresLexicos, archivoFinal);

  fclose(archivoFinal);
  return 0;
  //yydebug = 1; --> Utilizar en caso de MODO DEBUG

}

int control_tipos(char palabra[], char tipo[]) {
  if((!strcmp(tipo, "int") || !strcmp(tipo, "float")) && (!strcmp(palabra, "int") || !strcmp(palabra, "float") || !strcmp(palabra, "char"))){
    return 1;
  }
  if(!strcmp(tipo, "char") && !strcmp(palabra, "char")){
    return 1;
  }
  if(!strcmp(tipo, "char*") && !strcmp(palabra, "char*")){
    return 1;
  }
  if(!strcmp(tipo, "void*") || !strcmp(tipo, "char*") || !strcmp(tipo, "int*") && !strcmp(palabra, "void*")){
    return 1;
  }
  if((!strcmp(tipo, "const") || !strcmp(tipo, "volatile") || !strcmp(tipo, "typedef")) && (!strcmp(palabra, "int"))){
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

void agregar_error(nodoInfo* lista, char error[]){
    nodoInfo* aux = lista;
    while(aux != NULL){
        aux = aux->sig;
    }
    aux = malloc(sizeof(*aux));
    strcpy(aux->info, error);
    aux->sig = NULL;
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

/*void eliminar_ultimo(nodoVariable* listavariables){
    nodoVariable* aux = listavariables;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    free(aux->info.identificador);
    free(aux->info.tipo);
    aux = NULL;
}*/
/*
void pasar_a_lista_parametros(nodoVariable* listaParametros, nodoVariable* listavariables, int cantidad){
  if(cantidad <= 0){
      return;
  }
  nodoVariable* aux = listavariables;
  while(aux->sig != NULL){
    aux = aux->sig;
  }
  strcpy(listaParametros->info.identificador, aux->info.identificador);
  strcpy(listaParametros->info.tipo, aux->info.tipo);
  free(aux->info.identificador);
  free(aux->info.tipo);
  free(aux);

  cantidad--;
  nodoVariable* auxParam = NULL;
  listaParametros->sig = auxParam; 
  while(cantidad > 0){
    auxParam = malloc(sizeof(*auxParam));
    aux = listavariables;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    strcpy(auxParam->info.identificador, aux->info.identificador);
    strcpy(auxParam->info.tipo, aux->info.tipo);
    auxParam->sig = NULL;
    auxParam = auxParam->sig;
    free(aux->info.identificador);
    free(aux->info.tipo);
    aux = NULL;
  }
}*/

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
  fprintf(archivoFinal, "---------------------------------- VARIABLES ----------------------------------\n");
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
  fprintf(archivoFinal, "---------------------------------- FUNCIONES ----------------------------------\n");
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
  fprintf(archivoFinal, "---------------------------------- ERRORES LEXICOS ----------------------------------\n");
  while(*lista){
    aux = (*lista);
    fprintf(archivoFinal, "%s\n", aux->info);
    (*lista) = aux->sig;
    free(aux->info);
    free(aux);
  }
}
