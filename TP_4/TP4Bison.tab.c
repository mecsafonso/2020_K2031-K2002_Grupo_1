
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
#include "TP4.h"

#define YYDEBUG 1
extern FILE *yyin;
extern FILE *yyout;

int flag_error=0;
int contador=0;
char* tipo;
char* identificador;
int modo_funcion = 0;
int contador_parametros = 0;

FILE* archivoFinal;

nodoVariables* listaVariables = NULL;
nodoFuncion* listaFunciones = NULL;
nodoError* listaErroresLexicos = NULL;
nodoVariable* listaParametros = NULL;


int yylex();

int yywrap(){
	return(1);
}

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
}



/* Line 189 of yacc.c  */
#line 111 "TP4Bison.tab.c"

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
#line 38 "TP4Bison.y"

char cadena[30];
int entero;
int tipo;
float real;



/* Line 214 of yacc.c  */
#line 192 "TP4Bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 204 "TP4Bison.tab.c"

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
#define YYLAST   624

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  77
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNRULES -- Number of states.  */
#define YYNSTATES  280

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
     152,   156,   161,   162,   168,   169,   175,   177,   179,   185,
     186,   188,   190,   194,   197,   200,   202,   206,   207,   209,
     215,   218,   220,   224,   226,   230,   232,   235,   237,   240,
     241,   243,   247,   252,   257,   258,   260,   262,   266,   267,
     269,   271,   275,   277,   279,   280,   282,   284,   286,   290,
     292,   296,   298,   302,   306,   308,   312,   314,   318,   322,
     324,   328,   332,   336,   338,   341,   344,   349,   351,   353,
     355,   357,   359,   361,   366,   371,   372,   374,   376,   380,
     382,   384,   386,   388,   392,   394,   396,   398,   400,   402,
     404,   406,   411,   413,   416,   417,   419,   421,   424,   425,
     427,   430,   436,   444,   450,   456,   464,   474,   479,   483,
     487,   491,   494,   497
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      54,     0,    -1,    -1,    54,    55,    -1,    37,    -1,   119,
      37,    -1,    56,    37,    -1,    58,    57,    38,    -1,    58,
      57,   120,    -1,    -1,    60,    -1,    64,    59,    -1,    65,
      59,    -1,    66,    59,    -1,    -1,    58,    -1,    61,    -1,
      60,    39,    61,    -1,    76,    -1,    76,    27,    62,    -1,
     102,    -1,    40,    63,    41,    -1,    40,    63,    39,    41,
      -1,    62,    -1,    63,    39,    62,    -1,    36,    -1,     6,
      -1,    67,    -1,    91,    -1,    24,    -1,    25,    -1,    69,
      68,    40,    70,    41,    -1,    69,     5,    -1,    -1,     5,
      -1,    22,    -1,    23,    -1,    71,    38,    -1,    70,    71,
      -1,    72,    74,    38,    -1,    65,    73,    -1,    66,    73,
      -1,    -1,    72,    -1,    75,    -1,    74,    39,    75,    -1,
      76,    -1,    77,    42,   104,    -1,    79,    82,    -1,    -1,
      76,    -1,    43,    81,    -1,    43,    81,    78,    -1,    -1,
      78,    -1,    66,    -1,    80,    66,    -1,    -1,    80,    -1,
       5,    -1,    44,    76,    45,    -1,    82,    46,   105,    47,
      -1,    -1,    82,    83,    44,    85,    45,    -1,    -1,    82,
      84,    44,    90,    45,    -1,     1,    -1,    87,    -1,    87,
      39,    48,    48,    48,    -1,    -1,    85,    -1,    88,    -1,
      87,    39,    88,    -1,    58,    76,    -1,    58,    97,    -1,
       5,    -1,    89,    39,     5,    -1,    -1,    89,    -1,    26,
      68,    40,    92,    41,    -1,    26,     5,    -1,    93,    -1,
      92,    39,    93,    -1,    94,    -1,    94,    27,   104,    -1,
       5,    -1,    72,    97,    -1,    78,    -1,    79,    98,    -1,
      -1,    96,    -1,    44,    96,    45,    -1,    99,    46,   105,
      47,    -1,    99,    44,    86,    45,    -1,    -1,    98,    -1,
     102,    -1,   100,    39,   102,    -1,    -1,   100,    -1,   106,
      -1,   113,   103,   102,    -1,    27,    -1,   106,    -1,    -1,
     104,    -1,   107,    -1,   108,    -1,   107,    28,   108,    -1,
     109,    -1,   108,    29,   109,    -1,   110,    -1,   109,    30,
     110,    -1,   109,    31,   110,    -1,   111,    -1,   110,    32,
     111,    -1,   112,    -1,   111,    49,   112,    -1,   111,    50,
     112,    -1,   113,    -1,   112,    43,   113,    -1,   112,    51,
     113,    -1,   112,    52,   113,    -1,   115,    -1,    33,   113,
      -1,   114,   113,    -1,    21,    44,    95,    45,    -1,    35,
      -1,    43,    -1,    50,    -1,    49,    -1,    34,    -1,   118,
      -1,   115,    46,   100,    47,    -1,   115,    44,   116,    45,
      -1,    -1,   117,    -1,   102,    -1,   117,    39,   102,    -1,
       5,    -1,     3,    -1,     4,    -1,     7,    -1,    44,   100,
      45,    -1,     1,    -1,   120,    -1,   125,    -1,   126,    -1,
     127,    -1,   128,    -1,   129,    -1,    40,   122,   124,    41,
      -1,    56,    -1,   121,    56,    -1,    -1,   121,    -1,   119,
      -1,   123,   119,    -1,    -1,   123,    -1,   101,    38,    -1,
      19,    44,   100,    45,   119,    -1,    19,    44,   100,    45,
     119,    20,   119,    -1,    12,    44,   100,    45,   119,    -1,
      10,    44,   100,    45,   119,    -1,    11,   119,    10,    44,
     100,    45,    38,    -1,     9,    44,   101,    38,   101,    38,
     101,    45,   119,    -1,    16,   100,    42,   119,    -1,    17,
      42,   119,    -1,     5,    42,   119,    -1,    18,   101,    38,
      -1,    14,    38,    -1,    15,    38,    -1,    13,     5,    38,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    85,    88,    89,    90,    96,    97,   103,
     104,   107,   108,   109,   112,   113,   116,   117,   120,   121,
     124,   125,   126,   129,   130,   133,   136,   137,   138,   143,
     144,   147,   148,   151,   152,   155,   156,   159,   160,   163,
     166,   167,   170,   171,   174,   175,   178,   179,   182,   185,
     186,   189,   190,   193,   194,   197,   198,   201,   202,   205,
     206,   207,   208,   208,   209,   209,   210,   213,   214,   217,
     218,   221,   222,   225,   226,   229,   230,   233,   234,   237,
     238,   241,   242,   245,   246,   249,   252,   255,   256,   259,
     260,   263,   264,   265,   268,   269,   281,   282,   285,   286,
     289,   290,   293,   296,   299,   300,   303,   307,   308,   311,
     312,   315,   316,   317,   320,   321,   324,   325,   326,   329,
     330,   331,   332,   335,   336,   337,   338,   341,   342,   343,
     344,   345,   348,   349,   350,   353,   354,   357,   358,   361,
     362,   363,   364,   365,   366,   387,   388,   389,   390,   391,
     392,   395,   398,   399,   402,   403,   407,   408,   411,   412,
     415,   418,   419,   420,   423,   424,   425,   428,   429,   430,
     433,   434,   435,   436
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
  "declaradorDirecto", "$@1", "$@2", "listaTiposParametros",
  "listaTiposParametrosOP", "listaParametros", "declaracionParametro",
  "listaIdentificadores", "listaIdentificadoresOP", "especificadorEnum",
  "listaEnumeradores", "enumerador", "constanteEnumeracion", "nombreTipo",
  "declaradorAbstracto", "declaradorAbstractoOP",
  "declaradorAbstractoDirecto", "declaradorAbstractoDirectoOP",
  "expresion", "expresionOP", "expAsignacion", "operAsignacion",
  "expConstante", "expConstanteOP", "expCondicional", "expOr", "expAnd",
  "expIgualdad", "expRelacional", "expAditiva", "expMultiplicativa",
  "expUnaria", "operUnario", "expPostfijo", "listaArgumentosOP",
  "listaArgumentos", "expPrimaria", "sentencia", "sentCompuesta",
  "listaDeclaraciones", "listaDeclaracionesOP", "listaSentencias",
  "listaSentenciasOP", "sentExpresion", "sentSeleccion", "sentIteracion",
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
       0,    53,    54,    54,    55,    55,    55,    56,    56,    57,
      57,    58,    58,    58,    59,    59,    60,    60,    61,    61,
      62,    62,    62,    63,    63,    64,    65,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    77,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      82,    82,    83,    82,    84,    82,    82,    85,    85,    86,
      86,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    95,    96,    96,    97,
      97,    98,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   103,   104,   105,   105,   106,   107,   107,   108,
     108,   109,   109,   109,   110,   110,   111,   111,   111,   112,
     112,   112,   112,   113,   113,   113,   113,   114,   114,   114,
     114,   114,   115,   115,   115,   116,   116,   117,   117,   118,
     118,   118,   118,   118,   118,   119,   119,   119,   119,   119,
     119,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   126,   126,   126,   127,   127,   127,   128,   128,   128,
     129,   129,   129,   129
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
       3,     4,     0,     5,     0,     5,     1,     1,     5,     0,
       1,     1,     3,     2,     2,     1,     3,     0,     1,     5,
       2,     1,     3,     1,     3,     1,     2,     1,     2,     0,
       1,     3,     4,     4,     0,     1,     1,     3,     0,     1,
       1,     3,     1,     1,     0,     1,     1,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     4,     4,     0,     1,     1,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     2,     0,     1,     1,     2,     0,     1,
       2,     5,     7,     5,     5,     7,     9,     4,     3,     3,
       3,     2,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,   144,   140,   141,   139,    26,   142,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    36,    29,    30,    33,     0,   131,   127,    25,
       4,   154,   128,     0,   130,   129,     3,     0,    53,    14,
      14,    14,    27,    33,    28,    99,     0,    96,   100,   106,
     107,   109,   111,   114,   116,   119,     0,   123,   132,     0,
     145,   146,   147,   148,   149,   150,     0,     0,     0,     0,
       0,     0,   171,   172,   139,     0,     0,     0,     0,     0,
      80,     0,   124,   152,   155,     0,     0,     6,    57,     0,
      10,    16,    18,    54,     0,    15,    11,    12,    13,    32,
       0,     0,   160,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,     0,   125,     0,     0,     5,   169,
       0,     0,     0,     0,   173,     0,   168,   170,     0,    42,
      42,    53,     0,     0,   153,   156,     0,     0,   143,    55,
      58,    51,     7,     8,    53,     0,    66,    59,    53,    48,
       0,    97,   108,   119,   110,   112,   113,   115,   117,   118,
     120,   121,   122,   101,   137,     0,   136,     0,     0,     0,
       0,     0,   167,     0,    43,    40,    41,    54,    94,    90,
      86,   126,    85,     0,    81,    83,   157,   151,    56,    52,
      17,     0,    19,    20,     0,     0,     0,     0,     0,     0,
      53,   134,     0,   133,     0,   164,     0,   163,   161,    53,
      88,     0,     0,    79,     0,    23,     0,    60,   105,     0,
     103,     0,    77,    31,    38,    37,     0,    44,    46,     0,
     138,     0,     0,     0,     0,    69,     0,    82,    84,     0,
      21,    61,    53,     0,    67,    71,    75,    78,     0,    39,
      53,     0,     0,   165,   162,    91,    70,     0,     0,    22,
      24,    73,     0,    74,    63,     0,     0,    65,    45,    47,
       0,    93,    92,    53,     0,    72,    76,   166,     0,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    36,    37,    89,    38,    96,    90,    91,   192,
     216,    39,    40,    41,    42,    81,    43,   198,   199,   174,
     175,   226,   227,    92,   229,    93,    94,   140,   141,   149,
     196,   197,   243,   257,   244,   245,   247,   248,    44,   183,
     184,   185,   132,   179,   180,   210,   211,    45,    46,    47,
     114,   218,   219,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   165,   166,    58,    59,    60,    84,    85,
     136,   137,    61,    62,    63,    64,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -203
static const yytype_int16 yypact[] =
{
    -203,   230,  -203,  -203,  -203,  -203,   -24,  -203,  -203,   -16,
      -5,   380,     9,    62,    25,    54,   574,    95,   401,   119,
     133,  -203,  -203,  -203,  -203,   135,   574,  -203,  -203,  -203,
    -203,   176,  -203,   574,  -203,  -203,  -203,   116,   103,   176,
     176,   176,  -203,   174,  -203,   152,   168,  -203,  -203,   179,
     180,    49,   178,    67,   -21,   181,   574,    -6,  -203,   182,
    -203,  -203,  -203,  -203,  -203,  -203,   380,   401,   574,   201,
     574,   175,  -203,  -203,  -203,   -26,   380,   177,   574,    98,
     183,   184,  -203,  -203,   176,   280,     2,  -203,   106,    75,
     186,  -203,   189,  -203,    32,  -203,  -203,  -203,  -203,  -203,
     188,   574,  -203,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,  -203,   574,  -203,   451,   574,  -203,  -203,
     194,    13,   173,    33,  -203,   380,  -203,  -203,    61,    98,
      98,    84,   193,   215,  -203,  -203,   330,   185,  -203,  -203,
     106,   207,  -203,  -203,   207,   470,  -203,  -203,   207,   101,
      98,  -203,   180,  -203,    49,   178,   178,    67,   -21,   -21,
    -203,  -203,  -203,  -203,  -203,   212,   219,   -12,   401,   380,
     574,   380,  -203,   380,  -203,  -203,  -203,    66,   216,  -203,
    -203,  -203,  -203,   109,  -203,   234,  -203,  -203,  -203,  -203,
    -203,   470,  -203,  -203,   217,   520,   225,   227,   162,   237,
     127,  -203,   574,  -203,   238,  -203,    73,  -203,   252,   207,
     105,   110,   215,  -203,   574,  -203,   137,  -203,  -203,   231,
    -203,   176,   272,  -203,  -203,  -203,   151,  -203,   240,   244,
    -203,   539,   250,   380,   255,   176,   520,  -203,  -203,   131,
    -203,  -203,    58,   257,   264,  -203,  -203,   265,   260,  -203,
     127,   574,   261,  -203,  -203,  -203,  -203,   262,   263,  -203,
    -203,  -203,    31,  -203,  -203,    20,   303,  -203,  -203,  -203,
     380,  -203,  -203,   207,   268,  -203,  -203,  -203,   269,  -203
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,  -203,  -203,   -20,  -203,   -38,   153,  -203,    77,  -177,
    -203,  -203,   -59,   -31,  -203,   266,  -203,  -203,   113,   -56,
     192,  -203,    69,  -140,  -203,  -116,  -114,  -203,  -203,  -203,
    -203,  -203,    91,  -203,  -203,    47,  -203,  -203,  -203,  -203,
     115,  -203,  -203,  -200,    83,  -203,  -203,    -9,   -13,   -95,
    -203,  -202,    92,  -185,  -203,   229,   232,    90,   243,    96,
     -22,  -203,  -203,  -203,  -203,  -203,   -11,   249,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -160
static const yytype_int16 yytable[] =
{
      69,    95,    95,    95,    82,    77,   151,    75,   194,   234,
     220,    83,   238,   101,   215,   177,   125,   178,    66,   163,
     129,   164,   110,   131,    86,   189,     7,   101,    67,   220,
     111,   112,   146,   146,   115,   203,   147,   147,   116,    68,
     117,   101,    21,    22,    23,    24,    25,   138,   130,   269,
     193,   220,   101,    70,   120,   119,    29,   139,   169,   121,
     228,   123,   260,    72,   134,   126,   220,    71,   274,   128,
     129,   129,   101,   234,   135,   273,   148,   -94,   171,   105,
     106,   153,   153,   153,   153,   153,   153,   153,   160,   161,
     162,   129,    73,   177,   200,   178,   193,   -89,   130,   130,
     101,    88,   261,   -89,     7,   -87,   173,   230,   167,   188,
     228,   -87,   101,   142,   172,    31,   108,   109,   232,   130,
      21,    22,    23,    24,    25,   186,   177,    88,   262,   -89,
      23,    24,     3,   194,     4,     5,    74,    76,     8,   129,
      80,    -9,   200,    -9,   193,   -62,    88,   195,   212,   -95,
     213,   -95,    20,    87,   235,   204,   236,   177,   205,   262,
     207,   206,   208,    78,    26,    27,    28,   130,     7,   -49,
      88,   191,   259,   153,    32,    33,   239,    79,   240,    99,
      34,    35,     7,   242,    21,    22,    23,    24,    25,   249,
     250,   101,   153,    97,    98,   155,   156,   242,    21,    22,
      23,    24,    25,   223,   158,   159,   102,   103,   113,   104,
     107,   122,    29,   124,   153,   127,   145,   170,   252,   118,
     182,   190,   254,   -34,   133,   144,   187,   242,   150,   153,
       2,     3,   168,     4,     5,     6,     7,     8,   181,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      88,    20,    21,    22,    23,    24,    25,   201,   202,   277,
     209,   214,   217,    26,    27,    28,    29,    30,   -98,   221,
      31,   222,   233,    32,    33,   225,   231,   246,   241,    34,
      35,     3,   -50,     4,     5,     6,   251,     8,   253,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     255,    20,   264,   265,   266,   267,   270,   271,   276,   100,
     272,   224,   275,    26,    27,    28,   278,   279,   -98,   268,
      31,  -158,   176,    32,    33,   263,   256,   237,   258,    34,
      35,     3,   152,     4,     5,     6,   154,     8,   143,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     157,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    27,    28,     0,     0,   -98,     0,
      31,  -159,     0,    32,    33,     0,     0,     0,     0,    34,
      35,     3,     0,     4,     5,     6,     0,     8,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,     3,     0,     4,     5,    74,     0,     8,     0,
       0,     0,     0,    26,    27,    28,     0,     0,   -98,     0,
      31,     0,    20,    32,    33,     0,     0,     0,     0,    34,
      35,     0,     0,     0,    26,    27,    28,     0,     0,   -98,
       0,     0,     0,     0,    32,    33,     0,     0,     0,     0,
      34,    35,     3,     0,     4,     5,    74,     0,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,    20,     4,     5,    74,     0,     8,     0,     0,
       0,     0,     0,     0,    26,    27,    28,     0,     0,     0,
       0,    20,     0,     0,    32,    33,  -135,     0,     0,     0,
      34,    35,     0,    26,    27,    28,     0,     0,     0,     0,
     191,     0,     0,    32,    33,     0,     0,     0,     0,    34,
      35,     3,     0,     4,     5,    74,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,    20,     4,     5,    74,     0,     8,     0,     0,     0,
       0,     0,     0,    26,    27,    28,     0,     0,     0,     0,
      20,     0,     0,    32,    33,     0,     0,  -104,     0,    34,
      35,     0,    26,    27,    28,     3,     0,     4,     5,    74,
       0,     8,    32,    33,   -98,     0,     0,     0,    34,    35,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,    27,    28,
       0,     0,     0,     0,     0,     0,     0,    32,    33,     0,
       0,     0,     0,    34,    35
};

static const yytype_int16 yycheck[] =
{
      11,    39,    40,    41,    26,    18,   101,    16,   148,   209,
     195,    31,   214,    39,   191,   131,    42,   131,    42,   114,
      79,   116,    43,    79,    33,   141,     6,    39,    44,   214,
      51,    52,     1,     1,    56,    47,     5,     5,    44,    44,
      46,    39,    22,    23,    24,    25,    26,    45,    79,   251,
     145,   236,    39,    44,    67,    66,    36,    88,    45,    68,
     200,    70,   239,    38,    84,    76,   251,     5,    48,    78,
     129,   130,    39,   273,    85,    44,    44,    46,    45,    30,
      31,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   150,    38,   209,   150,   209,   191,    39,   129,   130,
      39,    43,   242,    45,     6,    39,    45,   202,   117,   140,
     250,    45,    39,    38,   125,    40,    49,    50,    45,   150,
      22,    23,    24,    25,    26,   136,   242,    43,   242,    45,
      24,    25,     1,   273,     3,     4,     5,    42,     7,   198,
       5,    38,   198,    40,   239,    44,    43,    46,    39,    44,
      41,    46,    21,    37,    44,   168,    46,   273,   169,   273,
     171,   170,   173,    44,    33,    34,    35,   198,     6,    42,
      43,    40,    41,   195,    43,    44,    39,    44,    41,     5,
      49,    50,     6,   221,    22,    23,    24,    25,    26,    38,
      39,    39,   214,    40,    41,   105,   106,   235,    22,    23,
      24,    25,    26,    41,   108,   109,    38,    28,    27,    29,
      32,    10,    36,    38,   236,    38,    27,    44,   231,    37,
       5,   144,   233,    40,    40,    39,    41,   265,    40,   251,
       0,     1,    38,     3,     4,     5,     6,     7,    45,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      43,    21,    22,    23,    24,    25,    26,    45,    39,   270,
      44,    27,    45,    33,    34,    35,    36,    37,    38,    44,
      40,    44,    20,    43,    44,    38,    38,     5,    47,    49,
      50,     1,    42,     3,     4,     5,    42,     7,    38,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      45,    21,    45,    39,    39,    45,    45,    45,     5,    43,
      47,   198,   265,    33,    34,    35,    48,    48,    38,   250,
      40,    41,   130,    43,    44,   242,   235,   212,   236,    49,
      50,     1,   103,     3,     4,     5,   104,     7,    89,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     107,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    -1,    38,    -1,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,
      50,     1,    -1,     3,     4,     5,    -1,     7,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    21,     1,    -1,     3,     4,     5,    -1,     7,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    -1,    38,    -1,
      40,    -1,    21,    43,    44,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    33,    34,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,
      49,    50,     1,    -1,     3,     4,     5,    -1,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    21,     3,     4,     5,    -1,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,
      49,    50,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,
      50,     1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    21,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,
      21,    -1,    -1,    43,    44,    -1,    -1,    47,    -1,    49,
      50,    -1,    33,    34,    35,     1,    -1,     3,     4,     5,
      -1,     7,    43,    44,    45,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    -1,    49,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,     0,     1,     3,     4,     5,     6,     7,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      21,    22,    23,    24,    25,    26,    33,    34,    35,    36,
      37,    40,    43,    44,    49,    50,    55,    56,    58,    64,
      65,    66,    67,    69,    91,   100,   101,   102,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   118,   119,
     120,   125,   126,   127,   128,   129,    42,    44,    44,   119,
      44,     5,    38,    38,     5,   100,    42,   101,    44,    44,
       5,    68,   113,    56,   121,   122,   100,    37,    43,    57,
      60,    61,    76,    78,    79,    58,    59,    59,    59,     5,
      68,    39,    38,    28,    29,    30,    31,    32,    49,    50,
      43,    51,    52,    27,   103,   113,    44,    46,    37,   119,
     101,   100,    10,   100,    38,    42,   119,    38,   100,    65,
      66,    72,    95,    40,    56,   119,   123,   124,    45,    66,
      80,    81,    38,   120,    39,    27,     1,     5,    44,    82,
      40,   102,   108,   113,   109,   110,   110,   111,   112,   112,
     113,   113,   113,   102,   102,   116,   117,   100,    38,    45,
      44,    45,   119,    45,    72,    73,    73,    78,    79,    96,
      97,    45,     5,    92,    93,    94,   119,    41,    66,    78,
      61,    40,    62,   102,    76,    46,    83,    84,    70,    71,
      72,    45,    39,    47,   101,   119,   100,   119,   119,    44,
      98,    99,    39,    41,    27,    62,    63,    45,   104,   105,
     106,    44,    44,    41,    71,    38,    74,    75,    76,    77,
     102,    38,    45,    20,    96,    44,    46,    93,   104,    39,
      41,    47,    58,    85,    87,    88,     5,    89,    90,    38,
      39,    42,   101,    38,   119,    45,    85,    86,   105,    41,
      62,    76,    79,    97,    45,    39,    39,    45,    75,   104,
      45,    45,    47,    44,    48,    88,     5,   119,    48,    48
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
#line 88 "TP4Bison.y"
    {fprintf(archivoFinal,"\n--------------------------------------- \n \n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 89 "TP4Bison.y"
    {fprintf(archivoFinal,"\n-----------------SENTENCIA---------------- \n \n");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 90 "TP4Bison.y"
    {fprintf(archivoFinal,"\n-----------------DECLARACION---------------- \n \n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 96 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una declaracion \n");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 97 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontró una desarrollo de función");}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 103 "TP4Bison.y"
    {tipo = NULL;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 117 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro mas de una declaracion \n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 121 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una asignacion \n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 133 "TP4Bison.y"
    {if(tipo == NULL){strcpy(tipo, (yyvsp[(1) - (1)].cadena))};}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 136 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].cadena)) ; fprintf(archivoFinal, "se encontro el tipo de dato %s \n", (yyvsp[(1) - (1)].cadena));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 143 "TP4Bison.y"
    {if(tipo == NULL){strcpy(tipo, (yyvsp[(1) - (1)].cadena))};}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 144 "TP4Bison.y"
    {if(tipo == NULL){strcpy(tipo, (yyvsp[(1) - (1)].cadena))};}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 148 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(2) - (2)].cadena));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 152 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].cadena));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 189 "TP4Bison.y"
    {strcat(tipo, "*");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 205 "TP4Bison.y"
    {gestionar_identificador(listaFunciones, listaVariables, (yyvsp[(1) - (1)].cadena), tipo, modo_funcion, listaParametros, archivoFinal);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 208 "TP4Bison.y"
    {modo_funcion = 1; pasar_a_lista_parametros(listaParametros, listaVariables, contador_parametrosint cantidad);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 208 "TP4Bison.y"
    {contador_parametros = 0; modo_funcion = 0; vaciar_parametros(listaParametros); fprintf(archivoFinal,"se encontró una firma de función");}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 209 "TP4Bison.y"
    {modo_funcion = 1;;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 209 "TP4Bison.y"
    {modo_funcion = 0; vaciar_parametros(listaParametros);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 210 "TP4Bison.y"
    {flag_error=1;fprintf(archivoFinal,"error xd \n");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 225 "TP4Bison.y"
    {contador_parametros++;;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 229 "TP4Bison.y"
    {agregar_variable(listaParametros, (yyvsp[(1) - (1)].cadena), "int");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 230 "TP4Bison.y"
    {agregar_variable(listaParametros, (yyvsp[(2) - (3)].cadena), "int");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 238 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(2) - (2)].cadena));;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 281 "TP4Bison.y"
    {tipo = NULL;;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 308 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion OR \n");;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 312 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion AND \n");;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 316 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de IGUALDAD \n");;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 317 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de DIFERENCIA \n");;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 321 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion RELACIONAL \n");;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 325 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de SUMA \n");;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 326 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de RESTA \n");;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 330 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de MULTIPLICACION \n");;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 331 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de DIVISION \n");;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 332 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de RESTO \n");;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 361 "TP4Bison.y"
    {char* comparar_tipo = tipo_variable(listaVariables, &<cadena>1, archivoFinal);if(strcmp(comparar_tipo, "error")){if(tipo == NULL){strcpy(tipo, comparar_tipo);}else if(!control_tipos(tipo, comparar_tipo)){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un %s y un %s", comparar_tipo, (yyvsp[(1) - (1)].cadena));}};}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 362 "TP4Bison.y"
    {if(tipo == NULL){strcpy(tipo, "int");}else if(!control_tipos(tipo, "int")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un int y un %s", (yyvsp[(1) - (1)].cadena));};}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 363 "TP4Bison.y"
    {if(tipo == NULL){strcpy(tipo, "char");}else if(!control_tipos(tipo, "char")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un char y un %s", (yyvsp[(1) - (1)].cadena));};}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 364 "TP4Bison.y"
    {if(tipo == NULL){strcpy(tipo, "char*");}else if(!control_tipos(tipo, "char*")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un char* y un %s", (yyvsp[(1) - (1)].cadena));};}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 366 "TP4Bison.y"
    {flag_error=1;fprintf(archivoFinal,"Expresion unaria no valida \n");;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 388 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion \n");;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 389 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia de seleccion \n");;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 390 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia de iteracion \n");;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 391 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia etiquetada \n");;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 392 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia de salto \n");;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 395 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una sentencia compuesta \n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2086 "TP4Bison.tab.c"
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
#line 444 "TP4Bison.y"


int main ()
{
  yyin = fopen("entrada.txt", "r");
  yyout = fopen("salida.txt", "w");
  archivoFinal = fopen("Informe.txt", "w");


  yyparse();
  yylex();

  imprimir_lista_variables(listaVariables, archivoFinal);
  imprimir_funciones(listaFunciones, archivoFinal);
  imprimir_errores(listaErroresLexicos, archivoFinal);

  fclose(archivoFinal);
  return 0;
  //yydebug = 1; --> Utilizar en caso de MODO DEBUG

}


