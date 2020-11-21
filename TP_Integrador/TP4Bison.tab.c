
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
//#include "TP4.h"

#include <stdlib.h>



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
#line 114 "TP4Bison.tab.c"

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
#line 41 "TP4Bison.y"

char cadena[30];
int entero;
float real;



/* Line 214 of yacc.c  */
#line 194 "TP4Bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 206 "TP4Bison.tab.c"

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
#define YYLAST   539

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  183
/* YYNRULES -- Number of states.  */
#define YYNSTATES  296

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
     459,   466,   472,   473,   476,   482,   490,   500,   505,   509,
     513,   517,   520,   523
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
      -1,     1,    -1,   121,    -1,   126,    -1,   127,    -1,   129,
      -1,   130,    -1,   131,    -1,    40,   123,   125,    41,    -1,
      56,    -1,   122,    56,    -1,    -1,   122,    -1,   120,    -1,
     124,   120,    -1,    -1,   124,    -1,   101,    38,    -1,    19,
      44,   100,    45,   120,   128,    -1,    12,    44,   100,    45,
     120,    -1,    -1,    20,   120,    -1,    10,    44,   100,    45,
     120,    -1,    11,   120,    10,    44,   100,    45,    38,    -1,
       9,    44,   101,    38,   101,    38,   101,    45,   120,    -1,
      16,   100,    42,   120,    -1,    17,    42,   120,    -1,     5,
      42,   120,    -1,    18,   101,    38,    -1,    14,    38,    -1,
      15,    38,    -1,    13,     5,    38,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,    87,    90,    91,    92,    98,    99,   105,
     106,   109,   110,   111,   114,   115,   118,   119,   122,   123,
     126,   127,   128,   131,   132,   135,   138,   139,   140,   145,
     146,   149,   150,   153,   154,   157,   158,   161,   162,   165,
     168,   169,   172,   173,   176,   177,   180,   181,   184,   187,
     188,   191,   192,   195,   196,   199,   200,   203,   204,   207,
     208,   209,   210,   211,   212,   215,   216,   219,   220,   223,
     224,   227,   228,   231,   232,   233,   236,   237,   240,   241,
     244,   245,   246,   247,   250,   251,   254,   255,   258,   259,
     262,   263,   266,   267,   270,   273,   276,   277,   278,   281,
     282,   294,   295,   298,   299,   302,   303,   306,   309,   312,
     313,   316,   320,   321,   324,   325,   328,   329,   330,   333,
     334,   337,   338,   339,   342,   343,   344,   345,   348,   349,
     350,   351,   354,   355,   356,   357,   358,   361,   362,   363,
     366,   367,   371,   372,   375,   376,   377,   378,   381,   382,
     383,   384,   385,   386,   407,   408,   409,   410,   411,   412,
     415,   418,   419,   422,   423,   427,   428,   431,   432,   435,
     438,   439,   442,   443,   446,   447,   448,   451,   452,   453,
     456,   457,   458,   459
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
     127,   127,   128,   128,   129,   129,   129,   130,   130,   130,
     131,   131,   131,   131
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
       6,     5,     0,     2,     5,     7,     9,     4,     3,     3,
       3,     2,     2,     3
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
       0,     0,     0,   181,   182,   148,     0,     0,     0,     0,
       0,    89,     0,   129,   161,   164,     0,     0,     6,    57,
       0,    10,    16,    18,    54,     0,    15,    11,    12,    13,
      32,     0,     0,   169,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,   130,     0,     5,   179,
     145,   146,   144,   147,     0,   141,   142,     0,     0,     0,
       0,   183,     0,   178,   180,     0,    42,    42,    78,     0,
       0,   162,   165,     0,     0,   152,    55,    58,    51,     7,
       8,    53,     0,    64,    59,    53,    48,     0,   102,   113,
     124,   115,   117,   118,   120,   122,   123,   125,   126,   127,
     106,     0,   139,     0,     0,     0,     0,     0,   177,     0,
      43,    40,    41,    79,    99,   131,    94,     0,    90,    92,
     166,   160,    56,    52,    17,     0,    19,    20,    86,     0,
       0,     0,     0,    53,   138,   143,     0,   174,     0,   171,
     172,    78,   100,    95,     0,    88,     0,    23,     0,    84,
      76,    76,    76,     0,    65,    69,    78,    87,     0,   110,
       0,   108,    60,    31,    38,    37,     0,    44,    46,     0,
       0,     0,     0,   170,    99,    67,     0,    91,    93,     0,
      21,    77,    73,    74,    75,    62,     0,     0,     0,    63,
      61,    39,    53,     0,     0,   175,   173,     0,    68,     0,
       0,    22,    24,     0,    70,    83,    80,    78,    71,    72,
      85,    45,    47,     0,    96,    98,    97,     0,     0,     0,
     176,    66,     0,     0,    82,    81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    36,    37,    90,    38,    97,    91,    92,   196,
     218,    39,    40,    41,    42,    82,    43,   201,   202,   180,
     181,   236,   237,    93,   239,    94,    95,   147,   148,   156,
     223,   269,   224,   225,   226,   252,   184,   278,   227,   228,
      44,   187,   188,   189,   139,   212,   267,    45,    46,    47,
     115,   229,   230,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   124,   125,   126,    58,    59,    60,    85,
      86,   143,   144,    61,    62,   243,    63,    64,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -220
static const yytype_int16 yypact[] =
{
    -220,   192,  -220,  -220,  -220,  -220,    15,  -220,  -220,   -26,
     -14,   343,   -10,    45,    38,    92,   489,    96,   364,    89,
     112,  -220,  -220,  -220,  -220,   157,   489,  -220,  -220,  -220,
    -220,    13,  -220,   489,  -220,  -220,  -220,   128,    91,    13,
      13,    13,  -220,   173,  -220,   133,   146,  -220,  -220,   162,
     165,    67,   168,    -4,    51,   185,   489,   177,  -220,   182,
    -220,  -220,  -220,  -220,  -220,  -220,   343,   156,   364,   489,
     230,   489,   229,  -220,  -220,   231,    80,   343,   244,   489,
     122,   245,   248,  -220,  -220,    13,   243,   -13,  -220,    87,
     135,   250,  -220,   263,  -220,    12,  -220,  -220,  -220,  -220,
    -220,   251,   489,  -220,   489,   489,   489,   489,   489,   489,
     489,   489,   489,   489,  -220,   489,  -220,   489,  -220,  -220,
    -220,  -220,  -220,  -220,   254,   256,  -220,   275,    56,   257,
      70,  -220,   343,  -220,  -220,    75,   122,   122,   272,   271,
     312,  -220,  -220,   293,   277,  -220,  -220,    87,   276,  -220,
    -220,   276,   414,  -220,   176,   276,  -220,   122,  -220,   165,
    -220,    67,   168,   168,    -4,    51,    51,  -220,  -220,  -220,
    -220,   -27,  -220,   156,   364,   343,   489,   343,  -220,   343,
    -220,  -220,  -220,  -220,   278,  -220,  -220,   198,  -220,   294,
    -220,  -220,  -220,  -220,  -220,   414,  -220,  -220,    23,   435,
     279,   101,   282,   191,  -220,  -220,   285,  -220,   110,  -220,
     305,   272,  -220,   199,   312,  -220,   489,  -220,   210,  -220,
      16,    16,    16,   284,   291,  -220,   272,   296,   287,  -220,
     292,  -220,  -220,  -220,  -220,  -220,   227,  -220,   298,   299,
     470,   300,   343,  -220,   278,    16,   435,  -220,  -220,   136,
    -220,  -220,  -220,  -220,  -220,  -220,    19,    60,   340,  -220,
    -220,  -220,   191,   489,   304,  -220,  -220,   107,  -220,   306,
     316,  -220,  -220,   318,  -220,  -220,   324,   272,  -220,   199,
    -220,  -220,  -220,   343,  -220,  -220,  -220,   325,   435,    72,
    -220,  -220,   327,   330,  -220,  -220
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -220,  -220,  -220,   -22,  -220,   142,   228,  -220,   221,  -185,
    -220,  -220,   -65,   -47,  -220,   336,  -220,  -220,   179,   -66,
     247,  -220,   120,  -149,  -220,   240,  -220,  -220,  -220,  -220,
     144,  -220,  -220,   134,   -33,    49,  -203,   102,  -220,  -220,
    -220,  -220,   180,  -220,  -220,  -220,  -179,    -9,   -16,   -99,
    -220,  -205,  -219,  -195,  -220,   297,   290,   167,   288,   170,
     -25,  -220,  -220,  -220,  -220,   232,  -220,   -11,   310,  -220,
    -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -169
static const yytype_int16 yytable[] =
{
      70,    83,    78,   158,   231,   213,   200,    76,   244,    84,
     217,   248,   102,   153,   138,   136,   170,   154,    68,     7,
     204,   231,   220,   257,    87,   220,   102,   270,   219,   220,
      69,   116,   145,   137,    71,    21,    22,    23,    24,    25,
     221,   222,   146,   221,   222,   109,   110,   221,   222,    29,
      72,   231,   127,   197,   238,   119,   155,    66,   282,    67,
     128,   275,   130,   141,   272,   276,   133,   273,   231,   292,
     135,   136,   136,   275,   289,   142,    73,   276,   279,   160,
     160,   160,   160,   160,   160,   160,   167,   168,   169,   137,
     137,   203,   136,   231,   111,   102,   197,   106,   107,   -99,
     192,   175,   112,   113,   277,   -99,   -99,     7,   171,   102,
     137,    23,    24,   238,   102,   177,   277,   -99,   -99,   102,
     179,   178,   132,    21,    22,    23,    24,    25,     7,    -9,
      74,    -9,   190,    79,    89,   203,   136,     3,    77,     4,
       5,    75,   233,     8,    21,    22,    23,    24,    25,   102,
     197,   245,   284,   246,   137,   241,    80,    20,   206,   120,
     121,   122,    81,   123,   207,    88,   209,   208,   210,    26,
      27,    28,   102,   149,   160,    31,   195,   271,   100,    32,
      33,    96,    96,    96,   103,    34,    35,   251,   251,   251,
     104,   160,     2,     3,   105,     4,     5,     6,     7,     8,
     108,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   114,    20,    21,    22,    23,    24,    25,   118,
     198,   160,   199,   117,   264,    26,    27,    28,    29,    30,
    -103,   266,    31,   -49,    89,    32,    33,   214,   160,   215,
     129,    34,    35,   245,     3,   246,     4,     5,     6,   249,
       8,   250,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   160,    20,   261,   262,   131,    98,    99,
     253,   254,   290,   162,   163,    67,    26,    27,    28,   165,
     166,  -103,   134,    31,  -167,   -34,    32,    33,   140,   151,
     152,   157,    34,    35,     3,   173,     4,     5,     6,   172,
       8,   176,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   174,    20,   183,   185,   186,   191,    89,
     235,   216,   211,   240,   232,   242,    26,    27,    28,   255,
     256,  -103,   259,    31,  -168,   258,    32,    33,   265,   260,
     -50,   263,    34,    35,     3,   280,     4,     5,     6,   283,
       8,   285,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   286,    20,     3,   287,     4,     5,    75,
     288,     8,   194,   291,   294,   295,    26,    27,    28,   101,
     234,  -103,   281,    31,   182,    20,    32,    33,   193,   268,
     274,   293,    34,    35,   247,   161,   164,    26,    27,    28,
     150,   159,  -103,     0,     0,   205,     0,    32,    33,     0,
       0,     0,     0,    34,    35,     3,     0,     4,     5,    75,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,     3,     0,     4,     5,
      75,     0,     8,     0,     0,     0,     0,    26,    27,    28,
       0,     0,     0,     0,   195,     0,    20,    32,    33,     0,
       0,     0,     0,    34,    35,     0,     0,     0,    26,    27,
      28,     3,     0,     4,     5,    75,     0,     8,    32,    33,
       0,     0,  -109,     0,    34,    35,     0,     0,     0,     0,
       3,    20,     4,     5,    75,     0,     8,     0,     0,     0,
       0,     0,     0,    26,    27,    28,     0,     0,     0,     0,
      20,     0,     0,    32,    33,  -103,     0,     0,     0,    34,
      35,     0,    26,    27,    28,     0,     0,     0,     0,     0,
       0,     0,    32,    33,     0,     0,     0,     0,    34,    35
};

static const yytype_int16 yycheck[] =
{
      11,    26,    18,   102,   199,   184,   155,    16,   211,    31,
     195,   216,    39,     1,    80,    80,   115,     5,    44,     6,
      47,   216,     6,   226,    33,     6,    39,   246,     5,     6,
      44,    56,    45,    80,    44,    22,    23,    24,    25,    26,
      24,    25,    89,    24,    25,    49,    50,    24,    25,    36,
       5,   246,    68,   152,   203,    66,    44,    42,   263,    44,
      69,     1,    71,    85,   249,     5,    77,    48,   263,   288,
      79,   136,   137,     1,   277,    86,    38,     5,   257,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   136,
     137,   157,   157,   288,    43,    39,   195,    30,    31,    39,
     147,    45,    51,    52,    44,    45,    46,     6,   117,    39,
     157,    24,    25,   262,    39,    45,    44,    45,    46,    39,
      45,   132,    42,    22,    23,    24,    25,    26,     6,    38,
      38,    40,   143,    44,    43,   201,   201,     1,    42,     3,
       4,     5,    41,     7,    22,    23,    24,    25,    26,    39,
     249,    44,    45,    46,   201,    45,    44,    21,   174,     3,
       4,     5,     5,     7,   175,    37,   177,   176,   179,    33,
      34,    35,    39,    38,   199,    40,    40,    41,     5,    43,
      44,    39,    40,    41,    38,    49,    50,   220,   221,   222,
      28,   216,     0,     1,    29,     3,     4,     5,     6,     7,
      32,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    27,    21,    22,    23,    24,    25,    26,    37,
      44,   246,    46,    46,   240,    33,    34,    35,    36,    37,
      38,   242,    40,    42,    43,    43,    44,    39,   263,    41,
      10,    49,    50,    44,     1,    46,     3,     4,     5,    39,
       7,    41,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   288,    21,    38,    39,    38,    40,    41,
     221,   222,   283,   106,   107,    44,    33,    34,    35,   109,
     110,    38,    38,    40,    41,    40,    43,    44,    40,    39,
      27,    40,    49,    50,     1,    39,     3,     4,     5,    45,
       7,    44,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    38,    21,    43,    45,     5,    41,    43,
      38,    27,    44,    38,    45,    20,    33,    34,    35,    45,
      39,    38,    45,    40,    41,    39,    43,    44,    38,    47,
      42,    42,    49,    50,     1,     5,     3,     4,     5,    45,
       7,    45,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    47,    21,     1,    48,     3,     4,     5,
      46,     7,   151,    48,    47,    45,    33,    34,    35,    43,
     201,    38,   262,    40,   137,    21,    43,    44,   148,   245,
     256,   289,    49,    50,   214,   105,   108,    33,    34,    35,
      90,   104,    38,    -1,    -1,   173,    -1,    43,    44,    -1,
      -1,    -1,    -1,    49,    50,     1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,     1,    -1,     3,     4,
       5,    -1,     7,    -1,    -1,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    40,    -1,    21,    43,    44,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    33,    34,
      35,     1,    -1,     3,     4,     5,    -1,     7,    43,    44,
      -1,    -1,    47,    -1,    49,    50,    -1,    -1,    -1,    -1,
       1,    21,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,
      21,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,    49,
      50,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,    50
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
     121,   126,   127,   129,   130,   131,    42,    44,    44,    44,
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
      38,    45,    20,   128,    89,    44,    46,    95,   104,    39,
      41,    87,    88,    88,    88,    45,    39,    89,    39,    45,
      47,    38,    39,    42,   101,    38,   120,    99,    83,    84,
     105,    41,    62,    48,    86,     1,     5,    44,    90,    99,
       5,    75,   104,    45,    45,    45,    47,    48,    46,    89,
     120,    48,   105,    90,    47,    45
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
#line 90 "TP4Bison.y"
    {fprintf(archivoFinal,"\n--------------------------------------- \n \n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 91 "TP4Bison.y"
    {fprintf(archivoFinal,"\n-----------------SENTENCIA---------------- \n \n");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 92 "TP4Bison.y"
    {fprintf(archivoFinal,"\n-----------------DECLARACION---------------- \n \n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 98 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una declaracion \n");memset(tipo, 0, 30);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 99 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontró una desarrollo de función");memset(tipo, 0, 30);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 105 "TP4Bison.y"
    {memset(tipo, 0, 30);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 119 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro mas de una declaracion \n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 123 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una asignacion \n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 135 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, (yyvsp[(1) - (1)].cadena));};;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 138 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].cadena)) ;fprintf(archivoFinal, "se encontro el tipo de dato %s \n", tipo);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 145 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, (yyvsp[(1) - (1)].cadena));};;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 146 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, (yyvsp[(1) - (1)].cadena));};;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 150 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(2) - (2)].cadena));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 154 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(1) - (1)].cadena));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 191 "TP4Bison.y"
    {strcat(tipo, "*");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 207 "TP4Bison.y"
    {gestionar_identificador(&listaVariables, (yyvsp[(1) - (1)].cadena), tipo, archivoFinal);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 209 "TP4Bison.y"
    {gestionar_identificador(&listaVariables, (yyvsp[(1) - (4)].cadena), tipo, archivoFinal);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 210 "TP4Bison.y"
    {gestionar_funcion(&listaVariables, listaParametros,(yyvsp[(1) - (4)].cadena), tipo, archivoFinal);listaParametros = NULL;fprintf(archivoFinal, "se encontro una funcion \n");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 211 "TP4Bison.y"
    {gestionar_funcion(&listaVariables, listaParametros,(yyvsp[(1) - (4)].cadena), tipo, archivoFinal);listaParametros = NULL; fprintf(archivoFinal, "se encontro una funcion \n");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 212 "TP4Bison.y"
    {flag_error=1;fprintf(archivoFinal,"error xd \n");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 227 "TP4Bison.y"
    {agregar_info(&listaParametros, tipo_parametro); memset(tipo_parametro, 0, 30);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 228 "TP4Bison.y"
    {agregar_info(&listaParametros, tipo_parametro); memset(tipo_parametro, 0, 30);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 231 "TP4Bison.y"
    {strcpy(tipo_parametro, (yyvsp[(1) - (2)].cadena));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 232 "TP4Bison.y"
    {if(tipo_parametro[0] == '\0'){strcpy(tipo_parametro, (yyvsp[(1) - (2)].cadena));};;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 233 "TP4Bison.y"
    {if(tipo_parametro[0] == '\0'){strcpy(tipo_parametro, (yyvsp[(1) - (2)].cadena));};;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 241 "TP4Bison.y"
    {strcat(tipo_parametro, "*");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 247 "TP4Bison.y"
    {flag_error=1;fprintf(archivoFinal,"error xd \n");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 250 "TP4Bison.y"
    {agregar_info(&listaParametros, "int");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 251 "TP4Bison.y"
    {agregar_info(&listaParametros, "int");;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 259 "TP4Bison.y"
    {strcpy(tipo, (yyvsp[(2) - (2)].cadena));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 294 "TP4Bison.y"
    {memset(tipo, 0, 30);;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 321 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion OR \n");;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 325 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion AND \n");;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 329 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de IGUALDAD \n");;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 330 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de DIFERENCIA \n");;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 334 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion RELACIONAL \n");;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 338 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de SUMA \n");;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 339 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion de RESTA \n");;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 343 "TP4Bison.y"
    {if(!control_tipos(tipo, "int") && !control_tipos(tipo, "int*")){fprintf(archivoFinal,"No se puede realizar la operación MULTIPLICACION con el tipo de dato %s \n", tipo);};}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 344 "TP4Bison.y"
    {if(!control_tipos(tipo, "int") && !control_tipos(tipo, "int*")){fprintf(archivoFinal,"No se puede realizar la operación DIVISION con el tipo de dato %s \n", tipo);};}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 345 "TP4Bison.y"
    {if(!control_tipos(tipo, "int") && !control_tipos(tipo, "int*")){fprintf(archivoFinal,"No se puede realizar la operación RESTO con el tipo de dato %s \n", tipo);};}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 363 "TP4Bison.y"
    {sentencia_funcion(&listaVariables, listaParametros, (yyvsp[(1) - (4)].cadena), archivoFinal);;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 375 "TP4Bison.y"
    {agregar_info(&listaParametros, tipo_variable(listaVariables, (yyvsp[(1) - (1)].cadena), archivoFinal));;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 376 "TP4Bison.y"
    {agregar_info(&listaParametros, "int");;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 377 "TP4Bison.y"
    {agregar_info(&listaParametros, "float");;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 378 "TP4Bison.y"
    {agregar_info(&listaParametros, "char*");;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 381 "TP4Bison.y"
    {char* comparar_tipo = tipo_variable(listaVariables, (yyvsp[(1) - (1)].cadena), archivoFinal);if(strcmp(comparar_tipo, "error")){if(tipo[0] == '\0'){strcpy(tipo, comparar_tipo);}else if(!control_tipos(tipo, comparar_tipo)){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un %s y un %s\n", comparar_tipo, tipo);}};}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 382 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, "int");}else if(!control_tipos(tipo, "int")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un int y un %s\n", tipo);};}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 383 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, "float");}else if(!control_tipos(tipo, "float")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un float y un %s\n", tipo);};}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 384 "TP4Bison.y"
    {if(tipo[0] == '\0'){strcpy(tipo, "char*");}else if(!control_tipos(tipo, "char*")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un char* y un %s\n", tipo);};}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 386 "TP4Bison.y"
    {flag_error=1;fprintf(archivoFinal,"Expresion unaria no valida \n");;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 408 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una expresion \n");;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 409 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia de seleccion \n");;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 410 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia de iteracion \n");;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 411 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia etiquetada \n");;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 412 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro un sentencia de salto \n");;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 415 "TP4Bison.y"
    {fprintf(archivoFinal,"se encontro una sentencia compuesta \n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2154 "TP4Bison.tab.c"
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
#line 467 "TP4Bison.y"


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
