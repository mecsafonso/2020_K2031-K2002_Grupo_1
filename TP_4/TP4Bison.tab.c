
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
#define YYLAST   622

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNRULES -- Number of states.  */
#define YYNSTATES  277

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
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    -1,    54,    55,    -1,    37,    -1,   117,
      37,    -1,    56,    37,    -1,    58,    57,    38,    -1,    58,
      57,   118,    -1,    -1,    60,    -1,    64,    59,    -1,    65,
      59,    -1,    66,    59,    -1,    -1,    58,    -1,    61,    -1,
      60,    39,    61,    -1,    76,    -1,    76,    27,    62,    -1,
     100,    -1,    40,    63,    41,    -1,    40,    63,    39,    41,
      -1,    62,    -1,    63,    39,    62,    -1,    36,    -1,     6,
      -1,    67,    -1,    89,    -1,    24,    -1,    25,    -1,    69,
      68,    40,    70,    41,    -1,    69,     5,    -1,    -1,     5,
      -1,    22,    -1,    23,    -1,    71,    38,    -1,    70,    71,
      -1,    72,    74,    38,    -1,    65,    73,    -1,    66,    73,
      -1,    -1,    72,    -1,    75,    -1,    74,    39,    75,    -1,
      76,    -1,    77,    42,   102,    -1,    79,    82,    -1,    -1,
      76,    -1,    43,    81,    -1,    43,    81,    78,    -1,    -1,
      78,    -1,    66,    -1,    80,    66,    -1,    -1,    80,    -1,
       5,    -1,    44,    76,    45,    -1,    82,    46,   103,    47,
      -1,    82,    44,    83,    45,    -1,    82,    44,    88,    45,
      -1,     1,    -1,    85,    -1,    85,    39,    48,    48,    48,
      -1,    -1,    83,    -1,    86,    -1,    85,    39,    86,    -1,
      58,    76,    -1,    58,    95,    -1,     5,    -1,    87,    39,
       5,    -1,    -1,    87,    -1,    26,    68,    40,    90,    41,
      -1,    26,     5,    -1,    91,    -1,    90,    39,    91,    -1,
      92,    -1,    92,    27,   102,    -1,     5,    -1,    72,    95,
      -1,    78,    -1,    79,    96,    -1,    -1,    94,    -1,    44,
      94,    45,    -1,    97,    46,   103,    47,    -1,    97,    44,
      84,    45,    -1,    -1,    96,    -1,   100,    -1,    98,    39,
     100,    -1,    -1,    98,    -1,   104,    -1,   111,   101,   100,
      -1,    27,    -1,   104,    -1,    -1,   102,    -1,   105,    -1,
     106,    -1,   105,    28,   106,    -1,   107,    -1,   106,    29,
     107,    -1,   108,    -1,   107,    30,   108,    -1,   107,    31,
     108,    -1,   109,    -1,   108,    32,   109,    -1,   110,    -1,
     109,    49,   110,    -1,   109,    50,   110,    -1,   111,    -1,
     110,    43,   111,    -1,   110,    51,   111,    -1,   110,    52,
     111,    -1,   113,    -1,    33,   111,    -1,   112,   111,    -1,
      21,    44,    93,    45,    -1,    35,    -1,    43,    -1,    50,
      -1,    49,    -1,    34,    -1,   116,    -1,   113,    46,    98,
      47,    -1,   113,    44,   114,    45,    -1,    -1,   115,    -1,
     100,    -1,   115,    39,   100,    -1,     5,    -1,     3,    -1,
       4,    -1,     7,    -1,    44,    98,    45,    -1,     1,    -1,
     118,    -1,   123,    -1,   124,    -1,   125,    -1,   126,    -1,
     127,    -1,    40,   120,   122,    41,    -1,    56,    -1,   119,
      56,    -1,    -1,   119,    -1,   117,    -1,   121,   117,    -1,
      -1,   121,    -1,    99,    38,    -1,    19,    44,    98,    45,
     117,    -1,    19,    44,    98,    45,   117,    20,   117,    -1,
      12,    44,    98,    45,   117,    -1,    10,    44,    98,    45,
     117,    -1,    11,   117,    10,    44,    98,    45,    38,    -1,
       9,    44,    99,    38,    99,    38,    99,    45,   117,    -1,
      16,    98,    42,   117,    -1,    17,    42,   117,    -1,     5,
      42,   117,    -1,    18,    99,    38,    -1,    14,    38,    -1,
      15,    38,    -1,    13,     5,    38,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    69,    70,    73,    74,    75,    83,    84,    87,
      88,    91,    92,    93,    96,    97,   100,   101,   104,   105,
     108,   109,   110,   113,   114,   117,   120,   121,   122,   127,
     128,   131,   132,   135,   136,   139,   140,   143,   144,   147,
     150,   151,   154,   155,   158,   159,   162,   163,   166,   169,
     170,   173,   174,   177,   178,   181,   182,   185,   186,   189,
     190,   191,   192,   193,   194,   197,   198,   201,   202,   205,
     206,   209,   210,   213,   214,   217,   218,   221,   222,   225,
     226,   229,   230,   233,   236,   239,   240,   243,   244,   247,
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
      85,    86,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    91,    91,    92,    93,    94,    94,    95,    95,    96,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   100,
     101,   102,   103,   103,   104,   105,   105,   106,   106,   107,
     107,   107,   108,   108,   109,   109,   109,   110,   110,   110,
     110,   111,   111,   111,   111,   112,   112,   112,   112,   112,
     113,   113,   113,   114,   114,   115,   115,   116,   116,   116,
     116,   116,   116,   117,   117,   117,   117,   117,   117,   118,
     119,   119,   120,   120,   121,   121,   122,   122,   123,   124,
     124,   124,   125,   125,   125,   126,   126,   126,   127,   127,
     127,   127
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
      17,     0,    19,    20,     0,    75,     0,     0,     0,    53,
     132,     0,   131,     0,   162,     0,   161,   159,    53,    86,
       0,     0,    77,     0,    23,     0,    60,    73,    53,     0,
      65,    69,    76,     0,   103,     0,   101,    31,    38,    37,
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
     219,   261,   220,   221,   222,   223,    44,   183,   184,   185,
     132,   179,   180,   209,   210,    45,    46,    47,   114,   224,
     225,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   165,   166,    58,    59,    60,    84,    85,   136,   137,
      61,    62,    63,    64,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -200
static const yytype_int16 yypact[] =
{
    -200,   228,  -200,  -200,  -200,  -200,   -27,  -200,  -200,   -10,
      16,   378,    20,    67,    82,    88,   572,    60,   174,    73,
      92,  -200,  -200,  -200,  -200,   134,   572,  -200,  -200,  -200,
    -200,    17,  -200,   572,  -200,  -200,  -200,   106,    52,    17,
      17,    17,  -200,   149,  -200,   126,   138,  -200,  -200,   142,
     143,    63,   150,   101,   -14,   162,   572,     0,  -200,   164,
    -200,  -200,  -200,  -200,  -200,  -200,   378,   174,   572,   188,
     572,   172,  -200,  -200,  -200,    -6,   378,   173,   572,   280,
     176,   180,  -200,  -200,    17,   278,     9,  -200,   132,    -8,
     175,  -200,   194,  -200,    13,  -200,  -200,  -200,  -200,  -200,
     182,   572,  -200,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,  -200,   572,  -200,   449,   572,  -200,  -200,
     187,    64,   183,    65,  -200,   378,  -200,  -200,    76,   280,
     280,     2,   191,   243,  -200,  -200,   328,   214,  -200,  -200,
     132,   213,  -200,  -200,   213,   468,  -200,  -200,   213,    29,
     280,  -200,   143,  -200,    63,   150,   150,   101,   -14,   -14,
    -200,  -200,  -200,  -200,  -200,   212,   219,   -12,   174,   378,
     572,   378,  -200,   378,  -200,  -200,  -200,    77,   215,  -200,
    -200,  -200,  -200,    93,  -200,   240,  -200,  -200,  -200,  -200,
    -200,   468,  -200,  -200,   224,   168,   518,   161,   232,   121,
    -200,   572,  -200,   235,  -200,    79,  -200,   254,   213,    91,
      96,   243,  -200,   572,  -200,   108,  -200,  -200,    62,   230,
     237,  -200,   241,   239,  -200,   251,  -200,  -200,  -200,  -200,
     130,  -200,   258,   259,  -200,   537,   269,   378,   263,    17,
     518,  -200,  -200,   399,  -200,  -200,    12,  -200,  -200,   105,
     304,  -200,  -200,  -200,   121,   572,   265,  -200,  -200,  -200,
    -200,   270,   267,  -200,  -200,   213,   272,  -200,  -200,  -200,
    -200,   378,  -200,  -200,   275,  -200,  -200
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -200,  -200,  -200,   -21,  -200,   -36,   156,  -200,   181,  -175,
    -200,  -200,   -53,   -17,  -200,   274,  -200,  -200,   127,   -59,
     196,  -200,    80,   -99,  -200,  -119,  -120,  -200,  -200,  -200,
     109,  -200,  -200,    81,  -200,  -200,  -200,  -200,   125,  -200,
    -200,  -199,   133,  -200,  -200,    -9,   -16,   -95,  -200,  -185,
     110,  -188,  -200,   249,   250,    94,   246,    97,   -25,  -200,
    -200,  -200,  -200,  -200,   -11,   266,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -158
static const yytype_int16 yytable[] =
{
      69,    82,    77,    95,    95,    95,   151,    75,   226,   238,
      83,   178,   177,   146,   146,    66,   214,   147,   147,   163,
     131,   164,   189,     7,    86,   226,   129,   101,   242,   110,
     142,   115,    31,   101,    67,   202,   125,   111,   112,    21,
      22,    23,    24,    25,   116,    88,   117,   -87,   101,   194,
     193,   120,   226,    29,   138,   119,   265,   148,   -92,   121,
      68,   123,   130,   134,    70,   126,   238,   226,   264,   128,
     270,   139,    71,   195,   135,   196,   129,   129,   153,   153,
     153,   153,   153,   153,   153,   160,   161,   162,   178,   177,
      -9,   199,    -9,   105,   106,    88,   193,   129,   246,   177,
     232,   -87,    76,   101,   101,    88,   234,   -87,   167,   169,
     171,     7,   130,   130,   172,   101,   -85,    78,   101,   245,
      72,   173,   -85,   188,   236,   186,    73,    21,    22,    23,
      24,    25,   211,   130,   212,   -93,    79,   -93,   199,    80,
     239,    29,   240,    87,   129,   246,   177,   243,   193,   244,
     108,   109,   203,   266,    99,   232,    23,    24,   204,   218,
     206,   205,   207,   -49,    88,   101,   194,     7,   253,   254,
     103,   153,   104,   217,     7,     3,   102,     4,     5,    74,
     130,     8,   107,    21,    22,    23,    24,    25,   153,   113,
      21,    22,    23,    24,    25,    20,    97,    98,   122,   155,
     156,   118,   227,   218,    29,   158,   159,    26,    27,    28,
     124,   127,   -96,   218,   144,   153,   -34,    32,    33,   256,
     133,   145,   150,    34,    35,   168,   258,   170,     2,     3,
     153,     4,     5,     6,     7,     8,   181,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   182,    20,
      21,    22,    23,    24,    25,   187,    88,   200,   201,   208,
     275,    26,    27,    28,    29,    30,   -96,   213,    31,   216,
     229,    32,    33,   235,   237,   248,   249,    34,    35,     3,
     250,     4,     5,     6,   251,     8,     7,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   252,    20,
     -50,   255,    21,    22,    23,    24,    25,   257,   259,   268,
     271,    26,    27,    28,   273,   272,   -96,   100,    31,  -156,
     274,    32,    33,   276,   228,   190,   176,    34,    35,     3,
     267,     4,     5,     6,   269,     8,   241,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   260,    20,
     262,   247,   152,   157,   154,   143,     0,     0,     0,     0,
       0,    26,    27,    28,     0,     0,   -96,     0,    31,  -157,
       0,    32,    33,     0,     0,     0,     0,    34,    35,     3,
       0,     4,     5,     6,     0,     8,     0,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
       3,     0,     4,     5,    74,     0,     8,     0,     0,     0,
       0,    26,    27,    28,     0,     0,   -96,     0,    31,     0,
      20,    32,    33,     0,     0,     0,     0,    34,    35,     0,
       0,     0,    26,    27,    28,     0,     0,     0,     0,   191,
     263,     0,    32,    33,     0,     0,     0,     0,    34,    35,
       3,     0,     4,     5,    74,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
      20,     4,     5,    74,     0,     8,     0,     0,     0,     0,
       0,     0,    26,    27,    28,     0,     0,     0,     0,    20,
       0,     0,    32,    33,  -133,     0,     0,     0,    34,    35,
       0,    26,    27,    28,     0,     0,     0,     0,   191,     0,
       0,    32,    33,     0,     0,     0,     0,    34,    35,     3,
       0,     4,     5,    74,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    20,
       4,     5,    74,     0,     8,     0,     0,     0,     0,     0,
       0,    26,    27,    28,     0,     0,     0,     0,    20,     0,
       0,    32,    33,     0,     0,  -102,     0,    34,    35,     0,
      26,    27,    28,     3,     0,     4,     5,    74,     0,     8,
      32,    33,   -96,     0,     0,     0,    34,    35,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    27,    28,     0,     0,
       0,     0,     0,     0,     0,    32,    33,     0,     0,     0,
       0,    34,    35
};

static const yytype_int16 yycheck[] =
{
      11,    26,    18,    39,    40,    41,   101,    16,   196,   208,
      31,   131,   131,     1,     1,    42,   191,     5,     5,   114,
      79,   116,   141,     6,    33,   213,    79,    39,   213,    43,
      38,    56,    40,    39,    44,    47,    42,    51,    52,    22,
      23,    24,    25,    26,    44,    43,    46,    45,    39,   148,
     145,    67,   240,    36,    45,    66,    44,    44,    46,    68,
      44,    70,    79,    84,    44,    76,   265,   255,   243,    78,
     255,    88,     5,    44,    85,    46,   129,   130,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   208,   208,
      38,   150,    40,    30,    31,    43,   191,   150,   218,   218,
     199,    39,    42,    39,    39,    43,   201,    45,   117,    45,
      45,     6,   129,   130,   125,    39,    39,    44,    39,   218,
      38,    45,    45,   140,    45,   136,    38,    22,    23,    24,
      25,    26,    39,   150,    41,    44,    44,    46,   197,     5,
      44,    36,    46,    37,   197,   265,   265,    39,   243,    41,
      49,    50,   168,    48,     5,   254,    24,    25,   169,   195,
     171,   170,   173,    42,    43,    39,   265,     6,    38,    39,
      28,   196,    29,     5,     6,     1,    38,     3,     4,     5,
     197,     7,    32,    22,    23,    24,    25,    26,   213,    27,
      22,    23,    24,    25,    26,    21,    40,    41,    10,   105,
     106,    37,    41,   239,    36,   108,   109,    33,    34,    35,
      38,    38,    38,   249,    39,   240,    40,    43,    44,   235,
      40,    27,    40,    49,    50,    38,   237,    44,     0,     1,
     255,     3,     4,     5,     6,     7,    45,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     5,    21,
      22,    23,    24,    25,    26,    41,    43,    45,    39,    44,
     271,    33,    34,    35,    36,    37,    38,    27,    40,    45,
      38,    43,    44,    38,    20,    45,    39,    49,    50,     1,
      39,     3,     4,     5,    45,     7,     6,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    47,    21,
      42,    42,    22,    23,    24,    25,    26,    38,    45,     5,
      45,    33,    34,    35,    47,    45,    38,    43,    40,    41,
      48,    43,    44,    48,   197,   144,   130,    49,    50,     1,
     249,     3,     4,     5,   254,     7,   211,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   239,    21,
     240,   218,   103,   107,   104,    89,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    -1,    38,    -1,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    -1,    49,    50,     1,
      -1,     3,     4,     5,    -1,     7,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    21,
       1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    -1,    38,    -1,    40,    -1,
      21,    43,    44,    -1,    -1,    -1,    -1,    49,    50,    -1,
      -1,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,    50,
       1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      21,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    43,    44,    45,    -1,    -1,    -1,    49,    50,
      -1,    33,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    43,    44,    -1,    -1,    -1,    -1,    49,    50,     1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    21,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    43,    44,    -1,    -1,    47,    -1,    49,    50,    -1,
      33,    34,    35,     1,    -1,     3,     4,     5,    -1,     7,
      43,    44,    45,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      -1,    49,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,     0,     1,     3,     4,     5,     6,     7,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      21,    22,    23,    24,    25,    26,    33,    34,    35,    36,
      37,    40,    43,    44,    49,    50,    55,    56,    58,    64,
      65,    66,    67,    69,    89,    98,    99,   100,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   116,   117,
     118,   123,   124,   125,   126,   127,    42,    44,    44,   117,
      44,     5,    38,    38,     5,    98,    42,    99,    44,    44,
       5,    68,   111,    56,   119,   120,    98,    37,    43,    57,
      60,    61,    76,    78,    79,    58,    59,    59,    59,     5,
      68,    39,    38,    28,    29,    30,    31,    32,    49,    50,
      43,    51,    52,    27,   101,   111,    44,    46,    37,   117,
      99,    98,    10,    98,    38,    42,   117,    38,    98,    65,
      66,    72,    93,    40,    56,   117,   121,   122,    45,    66,
      80,    81,    38,   118,    39,    27,     1,     5,    44,    82,
      40,   100,   106,   111,   107,   108,   108,   109,   110,   110,
     111,   111,   111,   100,   100,   114,   115,    98,    38,    45,
      44,    45,   117,    45,    72,    73,    73,    78,    79,    94,
      95,    45,     5,    90,    91,    92,   117,    41,    66,    78,
      61,    40,    62,   100,    76,    44,    46,    70,    71,    72,
      45,    39,    47,    99,   117,    98,   117,   117,    44,    96,
      97,    39,    41,    27,    62,    63,    45,     5,    58,    83,
      85,    86,    87,    88,   102,   103,   104,    41,    71,    38,
      74,    75,    76,    77,   100,    38,    45,    20,    94,    44,
      46,    91,   102,    39,    41,    76,    79,    95,    45,    39,
      39,    45,    47,    38,    39,    42,    99,    38,   117,    45,
      83,    84,   103,    41,    62,    44,    48,    86,     5,    75,
     102,    45,    45,    47,    48,   117,    48
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
        case 7:

/* Line 1455 of yacc.c  */
#line 83 "TP4Bison.y"
    {printf("se encontro una declaracion \n");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 84 "TP4Bison.y"
    {printf("se encontró una desarrollo de función");}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 87 "TP4Bison.y"
    {printf("se fue al vacio");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 101 "TP4Bison.y"
    {printf("se encontro mas de una declaracion \n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 105 "TP4Bison.y"
    {printf("se encontro una asignacion \n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 120 "TP4Bison.y"
    {printf("se encontro el tipo de dato %s \n", (yyvsp[(1) - (1)].cadena));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 189 "TP4Bison.y"
    {printf("se encontro declaradorDirecto %s \n", (yyvsp[(1) - (1)].cadena));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 192 "TP4Bison.y"
    {printf("se encontró una firma de función");}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 194 "TP4Bison.y"
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
#line 1853 "TP4Bison.tab.c"
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

