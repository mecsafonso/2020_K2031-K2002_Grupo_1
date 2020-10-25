
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
#define YYDEBUG 1

int flag_error=0;
int contador=0;
char* tipo;

int yylex();

int yywrap(){
	return(1);
}

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
}



/* Line 189 of yacc.c  */
#line 96 "TP4Bison.tab.c"

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
#line 23 "TP4Bison.y"

char cadena[30];
int entero;
int tipo;
float real;



/* Line 214 of yacc.c  */
#line 177 "TP4Bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 189 "TP4Bison.tab.c"

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
#define YYLAST   600

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNRULES -- Number of states.  */
#define YYNSTATES  275

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
      44,    45,    43,    49,    38,    50,    48,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
       0,     0,     3,     4,     7,     9,    12,    15,    17,    18,
      21,    24,    27,    28,    30,    32,    36,    38,    42,    44,
      48,    53,    55,    59,    61,    63,    65,    67,    69,    71,
      73,    79,    82,    83,    85,    87,    89,    92,    95,    99,
     102,   105,   106,   108,   110,   114,   116,   120,   123,   124,
     126,   129,   133,   134,   136,   138,   141,   142,   144,   146,
     150,   155,   160,   165,   167,   169,   175,   176,   178,   180,
     184,   187,   190,   192,   196,   197,   199,   205,   208,   210,
     214,   216,   220,   222,   224,   227,   229,   232,   233,   235,
     239,   244,   249,   250,   252,   254,   258,   259,   261,   263,
     267,   269,   271,   272,   274,   276,   278,   282,   284,   288,
     290,   294,   298,   300,   304,   306,   310,   314,   316,   320,
     324,   328,   330,   333,   336,   341,   343,   345,   347,   349,
     351,   353,   358,   363,   364,   366,   368,   372,   374,   376,
     378,   380,   384,   386,   388,   390,   392,   394,   396,   398,
     403,   405,   408,   409,   411,   413,   416,   417,   419,   422,
     428,   436,   442,   448,   456,   466,   471,   475,   479,   483,
     486,   489
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      54,     0,    -1,    -1,    54,    55,    -1,    37,    -1,   118,
      37,    -1,    58,    57,    -1,    60,    -1,    -1,    64,    59,
      -1,    65,    59,    -1,    66,    59,    -1,    -1,    58,    -1,
      61,    -1,    60,    38,    61,    -1,    76,    -1,    76,    27,
      62,    -1,   101,    -1,    39,    63,    40,    -1,    39,    63,
      38,    40,    -1,    62,    -1,    63,    38,    62,    -1,    36,
      -1,     6,    -1,    67,    -1,    89,    -1,    93,    -1,    24,
      -1,    25,    -1,    69,    68,    39,    70,    40,    -1,    69,
       5,    -1,    -1,     5,    -1,    22,    -1,    23,    -1,    71,
      41,    -1,    70,    71,    -1,    72,    74,    41,    -1,    65,
      73,    -1,    66,    73,    -1,    -1,    72,    -1,    75,    -1,
      74,    38,    75,    -1,    76,    -1,    77,    42,   103,    -1,
      79,    82,    -1,    -1,    76,    -1,    43,    81,    -1,    43,
      81,    78,    -1,    -1,    78,    -1,    66,    -1,    80,    66,
      -1,    -1,    80,    -1,     5,    -1,    44,    76,    45,    -1,
      82,    46,   104,    47,    -1,    82,    44,    83,    45,    -1,
      82,    44,    88,    45,    -1,     1,    -1,    85,    -1,    85,
      38,    48,    48,    48,    -1,    -1,    83,    -1,    86,    -1,
      85,    38,    86,    -1,    58,    76,    -1,    58,    96,    -1,
       5,    -1,    87,    38,     5,    -1,    -1,    87,    -1,    26,
      68,    39,    90,    40,    -1,    26,     5,    -1,    91,    -1,
      90,    38,    91,    -1,    92,    -1,    92,    27,   103,    -1,
       5,    -1,     5,    -1,    72,    96,    -1,    78,    -1,    79,
      97,    -1,    -1,    95,    -1,    44,    95,    45,    -1,    98,
      46,   104,    47,    -1,    98,    44,    84,    45,    -1,    -1,
      97,    -1,   101,    -1,    99,    38,   101,    -1,    -1,    99,
      -1,   105,    -1,   112,   102,   101,    -1,    27,    -1,   105,
      -1,    -1,   103,    -1,   106,    -1,   107,    -1,   106,    28,
     107,    -1,   108,    -1,   107,    29,   108,    -1,   109,    -1,
     108,    30,   109,    -1,   108,    31,   109,    -1,   110,    -1,
     109,    32,   110,    -1,   111,    -1,   110,    49,   111,    -1,
     110,    50,   111,    -1,   112,    -1,   111,    43,   112,    -1,
     111,    51,   112,    -1,   111,    52,   112,    -1,   114,    -1,
      33,   112,    -1,   113,   112,    -1,    21,    44,    94,    45,
      -1,    35,    -1,    43,    -1,    50,    -1,    49,    -1,    34,
      -1,   117,    -1,   114,    46,    99,    47,    -1,   114,    44,
     115,    45,    -1,    -1,   116,    -1,   101,    -1,   116,    38,
     101,    -1,     5,    -1,     3,    -1,     4,    -1,     7,    -1,
      44,    99,    45,    -1,     1,    -1,   119,    -1,   124,    -1,
     125,    -1,   126,    -1,   127,    -1,   128,    -1,    39,   121,
     123,    40,    -1,    56,    -1,   120,    56,    -1,    -1,   120,
      -1,   118,    -1,   122,   118,    -1,    -1,   122,    -1,   100,
      41,    -1,    19,    44,    99,    45,   118,    -1,    19,    44,
      99,    45,   118,    20,   118,    -1,    12,    44,    99,    45,
     118,    -1,    10,    44,    99,    45,   118,    -1,    11,   118,
      10,    44,    99,    45,    41,    -1,     9,    44,   100,    41,
     100,    41,   100,    45,   118,    -1,    16,    99,    42,   118,
      -1,    17,    42,   118,    -1,     5,    42,   118,    -1,    18,
     100,    41,    -1,    14,    41,    -1,    15,    41,    -1,    13,
       5,    41,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    69,    70,    73,    74,    82,    85,    86,    89,
      90,    91,    94,    95,    98,    99,   102,   103,   106,   107,
     108,   111,   112,   115,   118,   119,   120,   121,   124,   125,
     128,   129,   132,   133,   136,   137,   140,   141,   144,   147,
     148,   151,   152,   155,   156,   159,   160,   163,   166,   167,
     170,   171,   174,   175,   178,   179,   182,   183,   186,   187,
     188,   189,   190,   191,   194,   195,   198,   199,   202,   203,
     206,   207,   210,   211,   214,   215,   218,   219,   222,   223,
     226,   227,   230,   233,   236,   239,   240,   243,   244,   247,
     248,   249,   252,   253,   265,   266,   269,   270,   273,   274,
     277,   280,   283,   284,   287,   291,   292,   295,   296,   299,
     300,   301,   304,   305,   308,   309,   310,   313,   314,   315,
     316,   319,   320,   321,   322,   325,   326,   327,   328,   329,
     332,   333,   334,   337,   338,   341,   342,   345,   346,   347,
     348,   349,   350,   371,   372,   373,   374,   375,   376,   379,
     382,   383,   386,   387,   391,   392,   395,   396,   399,   402,
     403,   404,   407,   408,   409,   412,   413,   414,   417,   418,
     419,   420
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
  "OPER_DIRECCION", "ESPECIFICADOR_ALMACENAMIENTO", "'\\n'", "','", "'{'",
  "'}'", "';'", "':'", "'*'", "'('", "')'", "'['", "']'", "'.'", "'+'",
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
  "listaParametros", "declaracionParametro", "listaIdentificadores",
  "listaIdentificadoresOP", "especificadorEnum", "listaEnumeradores",
  "enumerador", "constanteEnumeracion", "nombreTypedef", "nombreTipo",
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
     285,   286,   287,   288,   289,   290,   291,    10,    44,   123,
     125,    59,    58,    42,    40,    41,    91,    93,    46,    43,
      45,    47,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    56,    57,    57,    58,
      58,    58,    59,    59,    60,    60,    61,    61,    62,    62,
      62,    63,    63,    64,    65,    65,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    72,
      72,    73,    73,    74,    74,    75,    75,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      82,    82,    82,    82,    83,    83,    84,    84,    85,    85,
      86,    86,    87,    87,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    93,    94,    95,    95,    96,    96,    97,
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
       0,     2,     0,     2,     1,     2,     2,     1,     0,     2,
       2,     2,     0,     1,     1,     3,     1,     3,     1,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       5,     2,     0,     1,     1,     1,     2,     2,     3,     2,
       2,     0,     1,     1,     3,     1,     3,     2,     0,     1,
       2,     3,     0,     1,     1,     2,     0,     1,     1,     3,
       4,     4,     4,     1,     1,     5,     0,     1,     1,     3,
       2,     2,     1,     3,     0,     1,     5,     2,     1,     3,
       1,     3,     1,     1,     2,     1,     2,     0,     1,     3,
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
       2,     0,     1,   142,   138,   139,   137,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   125,     4,   152,   126,     0,   128,   127,     3,
      97,     0,    94,    98,   104,   105,   107,   109,   112,   114,
     117,     0,   121,   130,     0,   143,   144,   145,   146,   147,
     148,     0,     0,     0,     0,     0,     0,   169,   170,   137,
       0,     0,     0,     0,     0,   122,    83,    24,    34,    35,
      28,    29,    32,    23,   150,     8,    12,    12,    12,    25,
      32,    26,    27,   153,     0,     0,     0,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,     0,
     123,     0,     0,     5,   167,     0,     0,     0,     0,   171,
       0,   166,   168,     0,    41,    41,    52,     0,    77,     0,
      56,     6,     7,    14,    16,    53,     0,    13,     9,    10,
      11,    31,     0,   151,   154,     0,     0,   141,    95,   106,
     117,   108,   110,   111,   113,   115,   116,   118,   119,   120,
      99,   135,     0,   134,     0,     0,     0,     0,     0,   165,
       0,    42,    39,    40,    53,    92,    88,    84,   124,     0,
      54,    57,    50,    52,     0,    63,    58,    52,    47,     0,
     155,   149,   132,     0,   131,     0,   162,     0,   161,   159,
      52,    86,     0,    82,     0,    78,    80,    55,    51,    15,
       0,    17,    18,     0,    74,     0,     0,     0,    52,   136,
       0,     0,     0,     0,    66,     0,     0,    76,     0,    21,
       0,    59,    83,    52,     0,    64,    68,    75,     0,   103,
       0,   101,    30,    37,    36,     0,    43,    45,     0,     0,
     163,   160,    89,    67,     0,     0,    79,    81,     0,    19,
      70,     0,    71,    61,     0,     0,    62,    60,    52,    38,
       0,     0,    91,    90,    20,    22,    52,     0,    69,    73,
      44,    46,   164,     0,    65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    29,    74,   121,   127,   128,   122,   123,   201,
     220,    76,    77,    78,    79,   119,    80,   206,   207,   161,
     162,   235,   236,   124,   238,   125,   126,   171,   172,   178,
     224,   244,   225,   226,   227,   228,    81,   194,   195,   196,
      82,   117,   166,   167,   191,   192,    30,    31,    32,    99,
     229,   230,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   152,   153,    43,    44,    45,    83,    84,   135,
     136,    46,    47,    48,    49,    50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -216
static const yytype_int16 yypact[] =
{
    -216,   223,  -216,  -216,  -216,  -216,   -37,  -216,   -22,   -16,
     373,    15,    44,    32,    52,   550,    79,   392,    92,   100,
     550,  -216,  -216,  -216,   174,  -216,   550,  -216,  -216,  -216,
     109,   111,  -216,  -216,   105,   127,    86,   139,   -11,   -18,
     155,   550,    26,  -216,   149,  -216,  -216,  -216,  -216,  -216,
    -216,   373,   392,   550,   180,   550,   151,  -216,  -216,  -216,
      57,   373,   153,   550,   482,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,   196,  -216,  -216,   164,   174,   174,   174,  -216,
     203,  -216,  -216,   174,   273,   -14,   550,  -216,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,  -216,   550,
    -216,   427,   550,  -216,  -216,   168,     5,   167,     8,  -216,
     373,  -216,  -216,    10,   482,   482,    51,   169,   173,   176,
     136,  -216,   175,  -216,   189,  -216,    31,  -216,  -216,  -216,
    -216,  -216,   178,  -216,  -216,   323,   179,  -216,  -216,   127,
    -216,    86,   139,   139,   -11,   -18,   -18,  -216,  -216,  -216,
    -216,  -216,   177,   182,   -32,   392,   373,   550,   373,  -216,
     373,  -216,  -216,  -216,    53,   181,  -216,  -216,  -216,   213,
    -216,   136,   164,   164,   446,  -216,  -216,   164,    69,   482,
    -216,  -216,  -216,   550,  -216,   188,  -216,    59,  -216,   201,
     164,    99,   113,  -216,   132,  -216,   216,  -216,  -216,  -216,
     446,  -216,  -216,   200,   432,   496,    83,   205,   122,  -216,
     515,   206,   373,   204,   174,   496,   213,  -216,   550,  -216,
     147,  -216,    89,    -3,   207,   212,  -216,   215,   209,  -216,
     208,  -216,  -216,  -216,  -216,     6,  -216,   217,   219,   218,
    -216,  -216,  -216,  -216,   220,   221,  -216,  -216,   134,  -216,
    -216,    25,  -216,  -216,   106,   264,  -216,  -216,   122,  -216,
     550,   373,  -216,  -216,  -216,  -216,   164,   222,  -216,  -216,
    -216,  -216,  -216,   227,  -216
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -216,  -216,  -216,   198,  -216,   -23,    98,  -216,   120,  -182,
    -216,  -216,   -53,   -57,  -216,   191,  -216,  -216,    73,   -55,
     183,  -216,    37,  -156,  -216,  -104,  -103,  -216,  -216,  -216,
      82,  -216,  -216,    43,  -216,  -216,  -216,  -216,    84,  -216,
    -216,  -216,  -176,    76,  -216,  -216,     1,   -15,   -82,  -216,
    -215,    87,  -195,  -216,   230,   214,   114,   228,    95,   -12,
    -216,  -216,  -216,  -216,  -216,   -10,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -158
static const yytype_int16 yytable[] =
{
      54,    75,    62,   247,   138,    51,    86,   115,    65,   116,
     231,   114,   164,   165,   213,   184,    60,   150,   219,   151,
     231,   203,    52,   231,    86,    95,   175,    85,    53,   100,
     176,   137,   175,    96,    97,   -87,   176,   105,    93,    94,
     120,   104,   -87,    86,   258,   271,    86,   259,    86,    56,
     156,   111,   237,   158,   106,   160,   108,   115,   115,    55,
      75,   114,   114,   170,   113,   231,   265,   250,   198,   266,
     101,   -92,   102,    57,   134,   177,   140,   140,   140,   140,
     140,   140,   140,   147,   148,   149,   164,   165,    66,    67,
     213,   -85,   202,    58,   120,    86,   -87,    86,   -85,   110,
     159,   209,   237,   154,   211,    68,    69,    70,    71,    72,
     203,    66,    67,   204,   197,   205,    90,    91,   202,   164,
     251,    61,   115,   232,   208,   180,   114,   -72,    68,    69,
      70,    71,    72,    88,   -72,     3,    63,     4,     5,    59,
     185,     7,    73,   -93,    64,   -93,   186,    86,   188,   115,
     189,   208,    87,   114,   267,    19,    89,   214,   187,   215,
      70,    71,   164,   251,   -48,   120,   202,    20,    21,    22,
     216,    92,   217,   200,   264,   129,   130,    25,    26,    66,
      67,   223,    98,    27,    28,   248,   103,   249,   145,   146,
     107,   223,   109,   140,   112,   239,    68,    69,    70,    71,
      72,   118,   241,   140,   142,   143,   140,   120,   131,   155,
      73,   157,   -33,   173,   168,   169,   174,   179,   193,   181,
     183,   212,   182,     2,     3,   190,     4,     5,     6,   210,
       7,   223,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,   218,    19,   221,   234,   240,   140,   242,
     254,   272,   253,   255,   256,   257,    20,    21,    22,   -49,
      23,   260,    24,   261,   -96,   262,    25,    26,   263,   269,
     273,   132,    27,    28,     3,   274,     4,     5,     6,   233,
       7,   133,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,   199,    19,   270,   243,   268,   163,   252,
     246,     0,   245,   141,     0,     0,    20,    21,    22,     0,
       0,     0,    24,  -156,   -96,     0,    25,    26,   139,     0,
     144,     0,    27,    28,     3,     0,     4,     5,     6,     0,
       7,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    21,    22,     0,
       0,     0,    24,  -157,   -96,     0,    25,    26,     0,     0,
       0,     0,    27,    28,     3,     0,     4,     5,     6,     0,
       7,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     3,    19,     4,     5,    59,     0,     7,
       0,     0,     0,     0,     0,     0,    20,    21,    22,     0,
       0,     0,    24,    19,   -96,     0,    25,    26,     0,     0,
       0,     0,    27,    28,     0,    20,    21,    22,     3,     0,
       4,     5,    59,   -96,     7,    25,    26,   222,    67,     0,
       0,    27,    28,     0,     0,     0,     0,     3,    19,     4,
       5,    59,     0,     7,    68,    69,    70,    71,    72,     0,
      20,    21,    22,     0,     0,     0,     0,    19,    73,     0,
      25,    26,  -133,     0,     0,     0,    27,    28,     0,    20,
      21,    22,     0,     0,     0,   200,     0,    66,    67,    25,
      26,     0,     0,     0,     0,    27,    28,     3,     0,     4,
       5,    59,     0,     7,    68,    69,    70,    71,    72,     0,
       0,     0,     0,     0,     0,     0,     3,    19,     4,     5,
      59,     0,     7,     0,     0,     0,     0,     0,     0,    20,
      21,    22,     0,     0,     0,     0,    19,     0,     0,    25,
      26,     0,     0,  -102,     0,    27,    28,     0,    20,    21,
      22,     3,     0,     4,     5,    59,     0,     7,    25,    26,
     -96,     0,     0,     0,    27,    28,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,    21,    22,     0,     0,     0,     0,
       0,     0,     0,    25,    26,     0,     0,     0,     0,    27,
      28
};

static const yytype_int16 yycheck[] =
{
      10,    24,    17,   218,    86,    42,    38,    64,    20,    64,
     205,    64,   116,   116,   190,    47,    15,    99,   200,   101,
     215,   177,    44,   218,    38,    43,     1,    26,    44,    41,
       5,    45,     1,    51,    52,    38,     5,    52,    49,    50,
      43,    51,    45,    38,    38,   260,    38,    41,    38,     5,
      45,    61,   208,    45,    53,    45,    55,   114,   115,    44,
      83,   114,   115,   120,    63,   260,   248,   223,   172,    44,
      44,    46,    46,    41,    84,    44,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   190,   190,     5,     6,
     266,    38,   174,    41,    43,    38,    45,    38,    45,    42,
     110,   183,   258,   102,    45,    22,    23,    24,    25,    26,
     266,     5,     6,    44,   171,    46,    30,    31,   200,   223,
     223,    42,   179,    40,   179,   135,   179,    38,    22,    23,
      24,    25,    26,    28,    45,     1,    44,     3,     4,     5,
     155,     7,    36,    44,    44,    46,   156,    38,   158,   206,
     160,   206,    41,   206,    48,    21,    29,    44,   157,    46,
      24,    25,   266,   266,    42,    43,   248,    33,    34,    35,
      38,    32,    40,    39,    40,    77,    78,    43,    44,     5,
       6,   204,    27,    49,    50,    38,    37,    40,    93,    94,
      10,   214,    41,   205,    41,   210,    22,    23,    24,    25,
      26,     5,   212,   215,    90,    91,   218,    43,     5,    41,
      36,    44,    39,    38,    45,    39,    27,    39,     5,    40,
      38,    20,    45,     0,     1,    44,     3,     4,     5,    41,
       7,   254,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    27,    21,    45,    41,    41,   260,    45,
      38,   261,    45,    38,    45,    47,    33,    34,    35,    42,
      37,    42,    39,    45,    41,    45,    43,    44,    47,     5,
      48,    80,    49,    50,     1,    48,     3,     4,     5,   206,
       7,    83,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   173,    21,   258,   214,   254,   115,   223,
     216,    -1,   215,    89,    -1,    -1,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    41,    -1,    43,    44,    88,    -1,
      92,    -1,    49,    50,     1,    -1,     3,     4,     5,    -1,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    -1,    49,    50,     1,    -1,     3,     4,     5,    -1,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     1,    21,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,
      -1,    -1,    39,    21,    41,    -1,    43,    44,    -1,    -1,
      -1,    -1,    49,    50,    -1,    33,    34,    35,     1,    -1,
       3,     4,     5,    41,     7,    43,    44,     5,     6,    -1,
      -1,    49,    50,    -1,    -1,    -1,    -1,     1,    21,     3,
       4,     5,    -1,     7,    22,    23,    24,    25,    26,    -1,
      33,    34,    35,    -1,    -1,    -1,    -1,    21,    36,    -1,
      43,    44,    45,    -1,    -1,    -1,    49,    50,    -1,    33,
      34,    35,    -1,    -1,    -1,    39,    -1,     5,     6,    43,
      44,    -1,    -1,    -1,    -1,    49,    50,     1,    -1,     3,
       4,     5,    -1,     7,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    21,     3,     4,
       5,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    -1,    -1,    -1,    -1,    21,    -1,    -1,    43,
      44,    -1,    -1,    47,    -1,    49,    50,    -1,    33,    34,
      35,     1,    -1,     3,     4,     5,    -1,     7,    43,    44,
      45,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,
      50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,     0,     1,     3,     4,     5,     7,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    21,
      33,    34,    35,    37,    39,    43,    44,    49,    50,    55,
      99,   100,   101,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   117,   118,   119,   124,   125,   126,   127,
     128,    42,    44,    44,   118,    44,     5,    41,    41,     5,
      99,    42,   100,    44,    44,   112,     5,     6,    22,    23,
      24,    25,    26,    36,    56,    58,    64,    65,    66,    67,
      69,    89,    93,   120,   121,    99,    38,    41,    28,    29,
      30,    31,    32,    49,    50,    43,    51,    52,    27,   102,
     112,    44,    46,    37,   118,   100,    99,    10,    99,    41,
      42,   118,    41,    99,    65,    66,    72,    94,     5,    68,
      43,    57,    60,    61,    76,    78,    79,    58,    59,    59,
      59,     5,    68,    56,   118,   122,   123,    45,   101,   107,
     112,   108,   109,   109,   110,   111,   111,   112,   112,   112,
     101,   101,   115,   116,    99,    41,    45,    44,    45,   118,
      45,    72,    73,    73,    78,    79,    95,    96,    45,    39,
      66,    80,    81,    38,    27,     1,     5,    44,    82,    39,
     118,    40,    45,    38,    47,   100,   118,    99,   118,   118,
      44,    97,    98,     5,    90,    91,    92,    66,    78,    61,
      39,    62,   101,    76,    44,    46,    70,    71,    72,   101,
      41,    45,    20,    95,    44,    46,    38,    40,    27,    62,
      63,    45,     5,    58,    83,    85,    86,    87,    88,   103,
     104,   105,    40,    71,    41,    74,    75,    76,    77,   100,
      41,   118,    45,    83,    84,   104,    91,   103,    38,    40,
      76,    79,    96,    45,    38,    38,    45,    47,    38,    41,
      42,    45,    45,    47,    40,    62,    44,    48,    86,     5,
      75,   103,   118,    48,    48
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
        case 6:

/* Line 1455 of yacc.c  */
#line 82 "TP4Bison.y"
    {printf("se encontro declaracion \n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 85 "TP4Bison.y"
    {printf("se encontro lsitaDeclaradoresOP \n");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 86 "TP4Bison.y"
    {printf("se encontro un opcional \n");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 89 "TP4Bison.y"
    {printf("se encontr1 \n");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 90 "TP4Bison.y"
    {printf("se encontro lsitaDeclaradoresOP 2222 \n");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 91 "TP4Bison.y"
    {printf("se encontro lsitaDeclaradoresOP 3333 \n");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 102 "TP4Bison.y"
    {printf("se encontro declador1 \n");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 103 "TP4Bison.y"
    {printf("se encontro el declarador2 \n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 118 "TP4Bison.y"
    {printf("se encontro el tipo de dato %s \n", (yyvsp[(1) - (1)].cadena));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 186 "TP4Bison.y"
    {printf("se encontro declaradorDirecto %s \n", (yyvsp[(1) - (1)].cadena));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 191 "TP4Bison.y"
    {flag_error=1;printf("error xd \n");;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 345 "TP4Bison.y"
    {printf("se encontro el identificador %s \n", (yyvsp[(1) - (1)].cadena));;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 346 "TP4Bison.y"
    {printf("se encontro el valor %i \n", (yyvsp[(1) - (1)].entero));;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 350 "TP4Bison.y"
    {flag_error=1;printf("Expresion unaria no valida \n");;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 379 "TP4Bison.y"
    {printf("se encontro una sentencia compuesta \n");;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 402 "TP4Bison.y"
    {printf("se encontro un if \n");;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 403 "TP4Bison.y"
    {printf("se encontro un if con un else \n");;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 404 "TP4Bison.y"
    {printf("se encontro un switch \n");;}
    break;



/* Line 1455 of yacc.c  */
#line 1863 "TP4Bison.tab.c"
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
#line 443 "TP4Bison.y"


int main ()
{

  //yydebug = 1; --> Utilizar en caso de MODO DEBUG
  yyparse ();
}

