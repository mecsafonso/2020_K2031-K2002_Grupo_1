
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
     ESPECIFICADOR_ALMACENAMIENTO = 291,
     ERROR_LEXICO = 292
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
#line 193 "TP4Bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 205 "TP4Bison.tab.c"

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
#define YYLAST   559

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNRULES -- Number of states.  */
#define YYNSTATES  277

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    53,     2,     2,
      45,    46,    44,    50,    40,    51,    49,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    39,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      35,    36,    37
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
     186,   190,   193,   196,   198,   202,   203,   205,   211,   214,
     216,   220,   222,   226,   228,   231,   233,   236,   237,   239,
     243,   248,   253,   254,   256,   258,   262,   263,   265,   267,
     271,   273,   275,   276,   278,   280,   282,   286,   288,   292,
     294,   298,   302,   304,   308,   310,   314,   318,   320,   324,
     328,   332,   334,   337,   340,   345,   347,   349,   351,   353,
     355,   357,   362,   367,   368,   370,   372,   376,   378,   380,
     382,   384,   388,   390,   392,   394,   396,   398,   400,   402,
     407,   409,   412,   413,   415,   417,   420,   421,   423,   426,
     432,   440,   446,   452,   460,   470,   475,   479,   483,   487,
     490,   493
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      55,     0,    -1,    -1,    55,    56,    -1,    38,    -1,   118,
      38,    -1,    57,    38,    -1,    59,    58,    39,    -1,    59,
      58,   119,    -1,    -1,    61,    -1,    65,    60,    -1,    66,
      60,    -1,    67,    60,    -1,    -1,    59,    -1,    62,    -1,
      61,    40,    62,    -1,    77,    -1,    77,    27,    63,    -1,
     101,    -1,    41,    64,    42,    -1,    41,    64,    40,    42,
      -1,    63,    -1,    64,    40,    63,    -1,    36,    -1,     6,
      -1,    68,    -1,    90,    -1,    24,    -1,    25,    -1,    70,
      69,    41,    71,    42,    -1,    70,     5,    -1,    -1,     5,
      -1,    22,    -1,    23,    -1,    72,    39,    -1,    71,    72,
      -1,    73,    75,    39,    -1,    66,    74,    -1,    67,    74,
      -1,    -1,    73,    -1,    76,    -1,    75,    40,    76,    -1,
      77,    -1,    78,    43,   103,    -1,    80,    83,    -1,    -1,
      77,    -1,    44,    82,    -1,    44,    82,    79,    -1,    -1,
      79,    -1,    67,    -1,    81,    67,    -1,    -1,    81,    -1,
       5,    -1,    45,    77,    46,    -1,     5,    47,   104,    48,
      -1,     5,    45,    84,    46,    -1,     5,    45,    89,    46,
      -1,     1,    -1,    86,    -1,    86,    40,    49,    49,    49,
      -1,    -1,    84,    -1,    87,    -1,    86,    40,    87,    -1,
      59,    77,    -1,    59,    96,    -1,     5,    -1,    88,    40,
       5,    -1,    -1,    88,    -1,    26,    69,    41,    91,    42,
      -1,    26,     5,    -1,    92,    -1,    91,    40,    92,    -1,
      93,    -1,    93,    27,   103,    -1,     5,    -1,    73,    96,
      -1,    79,    -1,    80,    97,    -1,    -1,    95,    -1,    45,
      95,    46,    -1,    98,    47,   104,    48,    -1,    98,    45,
      85,    46,    -1,    -1,    97,    -1,   101,    -1,    99,    40,
     101,    -1,    -1,    99,    -1,   105,    -1,   112,   102,   101,
      -1,    27,    -1,   105,    -1,    -1,   103,    -1,   106,    -1,
     107,    -1,   106,    28,   107,    -1,   108,    -1,   107,    29,
     108,    -1,   109,    -1,   108,    30,   109,    -1,   108,    31,
     109,    -1,   110,    -1,   109,    32,   110,    -1,   111,    -1,
     110,    50,   111,    -1,   110,    51,   111,    -1,   112,    -1,
     111,    44,   112,    -1,   111,    52,   112,    -1,   111,    53,
     112,    -1,   114,    -1,    33,   112,    -1,   113,   112,    -1,
      21,    45,    94,    46,    -1,    35,    -1,    44,    -1,    51,
      -1,    50,    -1,    34,    -1,   117,    -1,   114,    47,    99,
      48,    -1,   114,    45,   115,    46,    -1,    -1,   116,    -1,
     101,    -1,   116,    40,   101,    -1,     5,    -1,     3,    -1,
       4,    -1,     7,    -1,    45,    99,    46,    -1,     1,    -1,
     119,    -1,   124,    -1,   125,    -1,   126,    -1,   127,    -1,
     128,    -1,    41,   121,   123,    42,    -1,    57,    -1,   120,
      57,    -1,    -1,   120,    -1,   118,    -1,   122,   118,    -1,
      -1,   122,    -1,   100,    39,    -1,    19,    45,    99,    46,
     118,    -1,    19,    45,    99,    46,   118,    20,   118,    -1,
      12,    45,    99,    46,   118,    -1,    10,    45,    99,    46,
     118,    -1,    11,   118,    10,    45,    99,    46,    39,    -1,
       9,    45,   100,    39,   100,    39,   100,    46,   118,    -1,
      16,    99,    43,   118,    -1,    17,    43,   118,    -1,     5,
      43,   118,    -1,    18,   100,    39,    -1,    14,    39,    -1,
      15,    39,    -1,    13,     5,    39,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    86,    89,    90,    91,    97,    98,   104,
     105,   108,   109,   110,   113,   114,   117,   118,   121,   122,
     125,   126,   127,   130,   131,   134,   137,   138,   139,   144,
     145,   148,   149,   152,   153,   156,   157,   160,   161,   164,
     167,   168,   171,   172,   175,   176,   179,   180,   183,   186,
     187,   190,   191,   194,   195,   198,   199,   202,   203,   206,
     207,   208,   209,   210,   211,   214,   215,   218,   219,   222,
     223,   226,   227,   230,   231,   234,   235,   238,   239,   242,
     243,   246,   247,   250,   253,   256,   257,   260,   261,   264,
     265,   266,   269,   270,   282,   283,   286,   287,   290,   291,
     294,   297,   300,   301,   304,   308,   309,   312,   313,   316,
     317,   318,   321,   322,   325,   326,   327,   330,   331,   332,
     333,   336,   337,   338,   339,   342,   343,   344,   345,   346,
     349,   350,   351,   354,   355,   358,   359,   362,   363,   364,
     365,   366,   367,   388,   389,   390,   391,   392,   393,   396,
     399,   400,   403,   404,   408,   409,   412,   413,   416,   419,
     420,   421,   424,   425,   426,   429,   430,   431,   434,   435,
     436,   437
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
  "OPER_DIRECCION", "ESPECIFICADOR_ALMACENAMIENTO", "ERROR_LEXICO",
  "'\\n'", "';'", "','", "'{'", "'}'", "':'", "'*'", "'('", "')'", "'['",
  "']'", "'.'", "'+'", "'-'", "'/'", "'%'", "$accept", "input", "line",
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
  "listaParametros", "declaracionParametro", "listaIdentificadores",
  "listaIdentificadoresOP", "especificadorEnum", "listaEnumeradores",
  "enumerador", "constanteEnumeracion", "nombreTipo",
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
     285,   286,   287,   288,   289,   290,   291,   292,    10,    59,
      44,   123,   125,    58,    42,    40,    41,    91,    93,    46,
      43,    45,    47,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    57,    57,    58,
      58,    59,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    63,    64,    64,    65,    66,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    83,    83,    83,    83,    84,    84,    85,    85,    86,
      86,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    94,    95,    95,    96,    96,    97,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   103,   104,   104,   105,   106,   106,   107,   107,   108,
     108,   108,   109,   109,   110,   110,   110,   111,   111,   111,
     111,   112,   112,   112,   112,   113,   113,   113,   113,   113,
     114,   114,   114,   115,   115,   116,   116,   117,   117,   117,
     117,   117,   117,   118,   118,   118,   118,   118,   118,   119,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   125,
     125,   125,   126,   126,   126,   127,   127,   127,   128,   128,
     128,   128
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
       3,     2,     2,     1,     3,     0,     1,     5,     2,     1,
       3,     1,     3,     1,     2,     1,     2,     0,     1,     3,
       4,     4,     0,     1,     1,     3,     0,     1,     1,     3,
       1,     1,     0,     1,     1,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     4,     1,     1,     1,     1,     1,
       1,     4,     4,     0,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     2,     0,     1,     1,     2,     0,     1,     2,     5,
       7,     5,     5,     7,     9,     4,     3,     3,     3,     2,
       2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,   142,   138,   139,   137,    26,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    36,    29,    30,    33,     0,   129,   125,    25,
       4,   152,   126,     0,   128,   127,     3,     0,    53,    14,
      14,    14,    27,    33,    28,    97,     0,    94,    98,   104,
     105,   107,   109,   112,   114,   117,     0,   121,   130,     0,
     143,   144,   145,   146,   147,   148,     0,     0,     0,     0,
       0,     0,   169,   170,   137,     0,     0,     0,     0,     0,
      78,     0,   122,   150,   153,     0,     0,     6,    57,     0,
      10,    16,    18,    54,     0,    15,    11,    12,    13,    32,
       0,     0,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,     0,   123,     0,     0,     5,   167,
       0,     0,     0,     0,   171,     0,   166,   168,     0,    42,
      42,    53,     0,     0,   151,   154,     0,     0,   141,    55,
      58,    51,     7,     8,    53,     0,    64,    59,    53,    48,
       0,    95,   106,   117,   108,   110,   111,   113,   115,   116,
     118,   119,   120,    99,   135,     0,   134,     0,     0,     0,
       0,     0,   165,     0,    43,    40,    41,    54,    92,    88,
      84,   124,    83,     0,    79,    81,   155,   149,    56,    52,
      17,     0,    19,    20,    75,     0,     0,     0,     0,    53,
     132,     0,   131,     0,   162,     0,   161,   159,    53,    86,
       0,     0,    77,     0,    23,     0,    73,    53,     0,    65,
      69,    76,     0,   103,     0,   101,    60,    31,    38,    37,
       0,    44,    46,     0,   136,     0,     0,     0,     0,    67,
       0,    80,    82,     0,    21,    71,     0,    72,    62,     0,
       0,    63,    61,    39,    53,     0,     0,   163,   160,    89,
      68,     0,     0,    22,    24,    53,     0,    70,    74,    45,
      47,     0,    91,    90,     0,   164,    66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    36,    37,    89,    38,    96,    90,    91,   192,
     215,    39,    40,    41,    42,    81,    43,   197,   198,   174,
     175,   230,   231,    92,   233,    93,    94,   140,   141,   149,
     218,   261,   219,   220,   221,   222,    44,   183,   184,   185,
     132,   179,   180,   209,   210,    45,    46,    47,   114,   223,
     224,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   165,   166,    58,    59,    60,    84,    85,   136,   137,
      61,    62,    63,    64,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -200
static const yytype_int16 yypact[] =
{
    -200,   228,  -200,  -200,  -200,  -200,   -29,  -200,  -200,    47,
      70,   381,    78,   136,    73,    97,   508,   101,   172,   105,
     111,  -200,  -200,  -200,  -200,   164,   508,  -200,  -200,  -200,
    -200,    17,  -200,   508,  -200,  -200,  -200,   160,   158,    17,
      17,    17,  -200,   191,  -200,   163,   171,  -200,  -200,   190,
     198,    18,   204,   131,   -17,   221,   508,   -26,  -200,   217,
    -200,  -200,  -200,  -200,  -200,  -200,   381,   172,   508,   246,
     508,   218,  -200,  -200,  -200,    57,   381,   219,   508,   142,
     224,   227,  -200,  -200,    17,   279,     4,  -200,   162,    23,
     230,  -200,   232,  -200,    32,  -200,  -200,  -200,  -200,  -200,
     233,   508,  -200,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,  -200,   508,  -200,   400,   508,  -200,  -200,
     236,    12,   226,    65,  -200,   381,  -200,  -200,    67,   142,
     142,    29,   231,   271,  -200,  -200,   330,   239,  -200,  -200,
     162,   241,  -200,  -200,   241,   435,  -200,    77,   241,  -200,
     142,  -200,   198,  -200,    18,   204,   204,   131,   -17,   -17,
    -200,  -200,  -200,  -200,  -200,   253,   247,    -2,   172,   381,
     508,   381,  -200,   381,  -200,  -200,  -200,    93,   256,  -200,
    -200,  -200,  -200,    62,  -200,   275,  -200,  -200,  -200,  -200,
    -200,   435,  -200,  -200,   104,   454,   257,    95,   265,   146,
    -200,   508,  -200,   266,  -200,   103,  -200,   286,   241,    87,
     127,   271,  -200,   508,  -200,   138,  -200,   -12,   261,   268,
    -200,   269,   264,  -200,   263,  -200,  -200,  -200,  -200,  -200,
     169,  -200,   272,   273,  -200,   489,   278,   381,   276,    17,
     454,  -200,  -200,   150,  -200,  -200,    25,  -200,  -200,   495,
     314,  -200,  -200,  -200,   146,   508,   280,  -200,  -200,  -200,
    -200,   281,   277,  -200,  -200,   241,   283,  -200,  -200,  -200,
    -200,   381,  -200,  -200,   287,  -200,  -200
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -200,  -200,  -200,   -21,  -200,   -35,   180,  -200,   184,  -183,
    -200,  -200,   -62,   -34,  -200,   295,  -200,  -200,   153,   -59,
     222,  -200,    99,  -123,  -200,  -119,  -118,  -200,  -200,  -200,
     115,  -200,  -200,   106,  -200,  -200,  -200,  -200,   145,  -200,
    -200,  -199,   140,  -200,  -200,    -9,   -16,   -98,  -200,  -198,
     118,  -184,  -200,   258,   255,   107,   259,   116,   -25,  -200,
    -200,  -200,  -200,  -200,   -11,   284,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -158
static const yytype_int16 yytable[] =
{
      69,    82,    77,   151,    95,    95,    95,    75,   214,   238,
      83,   225,   177,   178,    66,   242,   163,   129,   164,   116,
     131,   117,   189,     7,    86,   196,   146,   110,   -87,   225,
     147,   115,    88,   146,   -87,   111,   112,   147,   101,    21,
      22,    23,    24,    25,   101,   130,   202,   193,   105,   106,
     138,   120,   101,    29,   139,   119,   225,   270,   169,   121,
     264,   123,   142,   134,    31,   126,   238,   129,   129,   128,
     265,   225,   -92,    88,   135,   -87,   232,   148,   153,   153,
     153,   153,   153,   153,   153,   160,   161,   162,   129,   177,
     178,   199,    67,   193,   245,   130,   130,   101,   177,   246,
     125,     7,   211,   234,   212,   101,   188,   101,   167,   216,
       7,   171,    72,   173,   172,    68,   130,    21,    22,    23,
      24,    25,   194,    70,   195,   186,    21,    22,    23,    24,
      25,   232,   -93,   -85,   -93,   129,    73,   227,   199,   -85,
      29,    71,   196,   101,    76,   193,   177,   246,     7,   236,
      78,     3,   203,     4,     5,    74,    79,     8,   204,   217,
     206,   205,   207,   130,    21,    22,    23,    24,    25,    80,
     153,    20,   239,     3,   240,     4,     5,    74,   243,     8,
     244,   108,   109,    26,    27,    28,    23,    24,   153,   -49,
      88,   191,   263,    20,    32,    33,    99,    -9,    87,    -9,
      34,    35,    88,   101,   217,    26,    27,    28,   253,   254,
     102,   -96,   155,   156,   217,   153,    32,    33,   103,   256,
      97,    98,    34,    35,   158,   159,   258,   104,     2,     3,
     153,     4,     5,     6,     7,     8,   107,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   113,    20,
      21,    22,    23,    24,    25,   118,   122,   124,   127,   145,
     275,    26,    27,    28,    29,   -34,    30,   -96,   133,    31,
     144,   170,    32,    33,   150,   168,   182,   181,    34,    35,
       3,   187,     4,     5,     6,    88,     8,   201,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   200,
      20,   208,   213,   226,   229,   235,   237,   248,   249,   250,
     251,   252,    26,    27,    28,   -50,   255,   257,   -96,   268,
      31,  -156,   259,    32,    33,   273,   271,   272,   190,    34,
      35,     3,   274,     4,     5,     6,   276,     8,   100,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     228,    20,   176,   269,   260,   267,   241,   247,   262,   154,
       0,   152,     0,    26,    27,    28,   157,     0,     0,   -96,
       0,    31,  -157,   143,    32,    33,     0,     0,     0,     0,
      34,    35,     3,     0,     4,     5,     6,     0,     8,     0,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     3,    20,     4,     5,    74,     0,     8,     0,     0,
       0,     0,     0,     0,    26,    27,    28,     0,     0,     0,
     -96,    20,    31,     0,     0,    32,    33,     0,     0,     0,
       0,    34,    35,    26,    27,    28,     3,     0,     4,     5,
      74,     0,     8,     0,    32,    33,  -133,     0,     0,     0,
      34,    35,     0,     0,     0,     3,    20,     4,     5,    74,
       0,     8,     0,     0,     0,     0,     0,     0,    26,    27,
      28,     0,     0,     0,     0,    20,   191,     0,     0,    32,
      33,     0,     0,     0,     0,    34,    35,    26,    27,    28,
       3,     0,     4,     5,    74,     0,     8,     0,    32,    33,
       0,     7,  -102,     0,    34,    35,     0,     0,     0,     3,
      20,     4,     5,    74,     0,     8,     0,    21,    22,    23,
      24,    25,    26,    27,    28,     0,     0,     0,     0,    20,
       0,    29,     0,    32,    33,   -96,     0,     0,     0,    34,
      35,    26,    27,    28,   266,     0,     0,     0,     0,     0,
       0,     0,    32,    33,     0,     0,     0,     0,    34,    35
};

static const yytype_int16 yycheck[] =
{
      11,    26,    18,   101,    39,    40,    41,    16,   191,   208,
      31,   195,   131,   131,    43,   213,   114,    79,   116,    45,
      79,    47,   141,     6,    33,   148,     1,    44,    40,   213,
       5,    56,    44,     1,    46,    52,    53,     5,    40,    22,
      23,    24,    25,    26,    40,    79,    48,   145,    30,    31,
      46,    67,    40,    36,    88,    66,   240,   255,    46,    68,
     243,    70,    39,    84,    41,    76,   265,   129,   130,    78,
      45,   255,    47,    44,    85,    46,   199,    45,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   150,   208,
     208,   150,    45,   191,   217,   129,   130,    40,   217,   217,
      43,     6,    40,   201,    42,    40,   140,    40,   117,     5,
       6,    46,    39,    46,   125,    45,   150,    22,    23,    24,
      25,    26,    45,    45,    47,   136,    22,    23,    24,    25,
      26,   254,    45,    40,    47,   197,    39,    42,   197,    46,
      36,     5,   265,    40,    43,   243,   265,   265,     6,    46,
      45,     1,   168,     3,     4,     5,    45,     7,   169,   194,
     171,   170,   173,   197,    22,    23,    24,    25,    26,     5,
     195,    21,    45,     1,    47,     3,     4,     5,    40,     7,
      42,    50,    51,    33,    34,    35,    24,    25,   213,    43,
      44,    41,    42,    21,    44,    45,     5,    39,    38,    41,
      50,    51,    44,    40,   239,    33,    34,    35,    39,    40,
      39,    39,   105,   106,   249,   240,    44,    45,    28,   235,
      40,    41,    50,    51,   108,   109,   237,    29,     0,     1,
     255,     3,     4,     5,     6,     7,    32,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    27,    21,
      22,    23,    24,    25,    26,    38,    10,    39,    39,    27,
     271,    33,    34,    35,    36,    41,    38,    39,    41,    41,
      40,    45,    44,    45,    41,    39,     5,    46,    50,    51,
       1,    42,     3,     4,     5,    44,     7,    40,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    46,
      21,    45,    27,    46,    39,    39,    20,    46,    40,    40,
      46,    48,    33,    34,    35,    43,    43,    39,    39,     5,
      41,    42,    46,    44,    45,    48,    46,    46,   144,    50,
      51,     1,    49,     3,     4,     5,    49,     7,    43,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     197,    21,   130,   254,   239,   249,   211,   217,   240,   104,
      -1,   103,    -1,    33,    34,    35,   107,    -1,    -1,    39,
      -1,    41,    42,    89,    44,    45,    -1,    -1,    -1,    -1,
      50,    51,     1,    -1,     3,     4,     5,    -1,     7,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     1,    21,     3,     4,     5,    -1,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,
      39,    21,    41,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    50,    51,    33,    34,    35,     1,    -1,     3,     4,
       5,    -1,     7,    -1,    44,    45,    46,    -1,    -1,    -1,
      50,    51,    -1,    -1,    -1,     1,    21,     3,     4,     5,
      -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    -1,    -1,    -1,    -1,    21,    41,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    50,    51,    33,    34,    35,
       1,    -1,     3,     4,     5,    -1,     7,    -1,    44,    45,
      -1,     6,    48,    -1,    50,    51,    -1,    -1,    -1,     1,
      21,     3,     4,     5,    -1,     7,    -1,    22,    23,    24,
      25,    26,    33,    34,    35,    -1,    -1,    -1,    -1,    21,
      -1,    36,    -1,    44,    45,    46,    -1,    -1,    -1,    50,
      51,    33,    34,    35,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,     0,     1,     3,     4,     5,     6,     7,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      21,    22,    23,    24,    25,    26,    33,    34,    35,    36,
      38,    41,    44,    45,    50,    51,    56,    57,    59,    65,
      66,    67,    68,    70,    90,    99,   100,   101,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   117,   118,
     119,   124,   125,   126,   127,   128,    43,    45,    45,   118,
      45,     5,    39,    39,     5,    99,    43,   100,    45,    45,
       5,    69,   112,    57,   120,   121,    99,    38,    44,    58,
      61,    62,    77,    79,    80,    59,    60,    60,    60,     5,
      69,    40,    39,    28,    29,    30,    31,    32,    50,    51,
      44,    52,    53,    27,   102,   112,    45,    47,    38,   118,
     100,    99,    10,    99,    39,    43,   118,    39,    99,    66,
      67,    73,    94,    41,    57,   118,   122,   123,    46,    67,
      81,    82,    39,   119,    40,    27,     1,     5,    45,    83,
      41,   101,   107,   112,   108,   109,   109,   110,   111,   111,
     112,   112,   112,   101,   101,   115,   116,    99,    39,    46,
      45,    46,   118,    46,    73,    74,    74,    79,    80,    95,
      96,    46,     5,    91,    92,    93,   118,    42,    67,    79,
      62,    41,    63,   101,    45,    47,    77,    71,    72,    73,
      46,    40,    48,   100,   118,    99,   118,   118,    45,    97,
      98,    40,    42,    27,    63,    64,     5,    59,    84,    86,
      87,    88,    89,   103,   104,   105,    46,    42,    72,    39,
      75,    76,    77,    78,   101,    39,    46,    20,    95,    45,
      47,    92,   103,    40,    42,    77,    80,    96,    46,    40,
      40,    46,    48,    39,    40,    43,   100,    39,   118,    46,
      84,    85,   104,    42,    63,    45,    49,    87,     5,    76,
     103,    46,    46,    48,    49,   118,    49
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
#line 89 "TP4Bison.y"
    {fprintf(archivoFinal,"\n--------------------------------------- \n \n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 90 "TP4Bison.y"
    {fprintf(archivoFinal,"\n-----------------SENTENCIA---------------- \n \n");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 91 "TP4Bison.y"
    {fprintf(archivoFinal,"\n-----------------DECLARACION---------------- \n \n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 97 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una declaracion \n");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 98 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontró una desarrollo de función");}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 104 "TP4Bison.y"
    {tipo = NULL;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 118 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro mas de una declaracion \n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 122 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una asignacion \n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 134 "TP4Bison.y"
    {if(tipo == NULL){strcpy(tipo, (yyvsp[(1) - (1)].cadena));};;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 137 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].cadena)) ; fprintf(archivoFinal, "se encontro el tipo de dato %s \n", (yyvsp[(1) - (1)].cadena));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 144 "TP4Bison.y"
    {if(tipo == NULL){strcpy(tipo, (yyvsp[(1) - (1)].cadena));};;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 145 "TP4Bison.y"
    {if(tipo == NULL){strcpy(tipo, (yyvsp[(1) - (1)].cadena));};;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 149 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(2) - (2)].cadena));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 153 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].cadena));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 190 "TP4Bison.y"
    {strcat(tipo, "*");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 206 "TP4Bison.y"
    {gestionar_identificador(listaFunciones, listaVariables, (yyvsp[(1) - (1)].cadena), tipo, modo_funcion, listaParametros, archivoFinal);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 211 "TP4Bison.y"
    {flag_error=1;fprintf(archivoFinal,"error xd \n");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 226 "TP4Bison.y"
    {contador_parametros++;;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 230 "TP4Bison.y"
    {agregar_variable(listaParametros, (yyvsp[(1) - (1)].cadena), "int");;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 231 "TP4Bison.y"
    {agregar_variable(listaParametros, (yyvsp[(2) - (3)].cadena), "int");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 239 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(2) - (2)].cadena));;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 282 "TP4Bison.y"
    {tipo = NULL;;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 309 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion OR \n");;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 313 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion AND \n");;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 317 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de IGUALDAD \n");;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 318 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de DIFERENCIA \n");;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 322 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion RELACIONAL \n");;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 326 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de SUMA \n");;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 327 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de RESTA \n");;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 331 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de MULTIPLICACION \n");;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 332 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de DIVISION \n");;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 333 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de RESTO \n");;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 362 "TP4Bison.y"
    {char* comparar_tipo = tipo_variable(listaVariables, &<cadena>1, archivoFinal);if(strcmp(comparar_tipo, "error")){if(tipo == NULL){strcpy(tipo, comparar_tipo);}else if(!control_tipos(tipo, comparar_tipo)){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un %s y un %s", comparar_tipo, (yyvsp[(1) - (1)].cadena));}};}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 363 "TP4Bison.y"
    {if(tipo == NULL){strcpy(tipo, "int");}else if(!control_tipos(tipo, "int")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un int y un %s", (yyvsp[(1) - (1)].cadena));};}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 364 "TP4Bison.y"
    {if(tipo == NULL){strcpy(tipo, "char");}else if(!control_tipos(tipo, "char")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un char y un %s", (yyvsp[(1) - (1)].cadena));};}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 365 "TP4Bison.y"
    {if(tipo == NULL){strcpy(tipo, "char*");}else if(!control_tipos(tipo, "char*")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un char* y un %s", (yyvsp[(1) - (1)].cadena));};}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 367 "TP4Bison.y"
    {flag_error=1;fprintf(archivoFinal,"Expresion unaria no valida \n");;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 389 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion \n");;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 390 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia de seleccion \n");;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 391 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia de iteracion \n");;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 392 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia etiquetada \n");;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 393 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia de salto \n");;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 396 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una sentencia compuesta \n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2044 "TP4Bison.tab.c"
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
#line 445 "TP4Bison.y"


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


