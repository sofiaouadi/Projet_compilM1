
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
#line 1 "minialgo.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"
#include "quad.h"

extern int yylex();
void yyerror(const char *s);

extern int ligne;
extern int colonne;

char *current_type  = NULL;   /* type courant (INTEGER / FLOAT) */
int   current_const = 0;      /* 0 = variable, 1 = constante  */


/* Line 189 of yacc.c  */
#line 91 "minialgo.tab.c"

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
     PROGRAM = 258,
     DECL = 259,
     ENDDECL = 260,
     BEGIN_T = 261,
     END_T = 262,
     INTEGER = 263,
     FLOAT_T = 264,
     CONST = 265,
     IF = 266,
     ELSE = 267,
     WHILE = 268,
     FOR = 269,
     WRITE = 270,
     EQL = 271,
     EQ = 272,
     NEQ = 273,
     GE = 274,
     LE = 275,
     AND = 276,
     OR = 277,
     IDF = 278,
     INT_CONST = 279,
     FLOAT_CONST = 280
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 21 "minialgo.y"

    int   ival;
    float fval;
    char *str;
    struct {
        char *type;    /* "INTEGER" ou "FLOAT" */
        char *place;   /* T0, T1 … ou nom de variable */
    } expr;



/* Line 214 of yacc.c  */
#line 164 "minialgo.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 176 "minialgo.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   188

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNRULES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,     2,     2,     2,     2,     2,
      38,    39,    31,    29,    35,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    34,
      27,     2,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    10,    14,    17,    19,    24,    26,    28,
      30,    34,    40,    42,    46,    51,    57,    63,    64,    67,
      69,    71,    73,    75,    77,    79,    84,    92,    94,    96,
      98,   103,   107,   111,   115,   119,   123,   127,   131,   135,
     139,   143,   147,   150,   154,   158,   159,   168,   169,   170,
     184,   185,   186,   196,   197,   212
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,     3,    23,    44,     6,    50,     7,    -1,
       4,    45,     5,    -1,    45,    46,    -1,    46,    -1,    47,
      33,    48,    34,    -1,    49,    -1,     8,    -1,     9,    -1,
      48,    35,    23,    -1,    48,    35,    23,    16,    53,    -1,
      23,    -1,    23,    16,    53,    -1,    23,    36,    24,    37,
      -1,    10,    23,    16,    24,    34,    -1,    10,    23,    16,
      25,    34,    -1,    -1,    50,    51,    -1,    52,    -1,    49,
      -1,    62,    -1,    59,    -1,    55,    -1,    64,    -1,    23,
      16,    53,    34,    -1,    23,    36,    53,    37,    16,    53,
      34,    -1,    24,    -1,    25,    -1,    23,    -1,    23,    36,
      53,    37,    -1,    53,    29,    53,    -1,    53,    30,    53,
      -1,    53,    31,    53,    -1,    53,    32,    53,    -1,    38,
      53,    39,    -1,    53,    28,    53,    -1,    53,    27,    53,
      -1,    53,    17,    53,    -1,    53,    18,    53,    -1,    53,
      19,    53,    -1,    53,    20,    53,    -1,    26,    53,    -1,
      54,    21,    54,    -1,    54,    22,    54,    -1,    -1,    11,
      38,    54,    39,    56,    40,    50,    41,    -1,    -1,    -1,
      11,    38,    54,    39,    57,    40,    50,    41,    58,    12,
      40,    50,    41,    -1,    -1,    -1,    13,    60,    38,    54,
      39,    61,    40,    50,    41,    -1,    -1,    14,    38,    23,
      33,    24,    33,    24,    33,    24,    39,    63,    40,    50,
      41,    -1,    15,    38,    53,    39,    34,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    82,    86,    87,    91,    92,    96,    97,
     102,   105,   114,   117,   126,   136,   146,   161,   163,   167,
     168,   169,   170,   171,   172,   179,   193,   211,   218,   225,
     234,   245,   253,   261,   269,   280,   289,   294,   299,   304,
     309,   314,   319,   324,   329,   352,   351,   363,   369,   362,
     395,   401,   394,   431,   430,   502
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "DECL", "ENDDECL", "BEGIN_T",
  "END_T", "INTEGER", "FLOAT_T", "CONST", "IF", "ELSE", "WHILE", "FOR",
  "WRITE", "EQL", "EQ", "NEQ", "GE", "LE", "AND", "OR", "IDF", "INT_CONST",
  "FLOAT_CONST", "'!'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "':'",
  "';'", "','", "'['", "']'", "'('", "')'", "'{'", "'}'", "$accept",
  "programme", "declarations", "liste_declarations", "declaration", "type",
  "liste_id", "declaration_constante", "instructions", "instruction",
  "affectation", "expression", "condition", "InstructionIf", "@1", "@2",
  "@3", "InstructionWhile", "@4", "@5", "InstructionFor", "@6", "write", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    33,    60,    62,    43,
      45,    42,    47,    58,    59,    44,    91,    93,    40,    41,
     123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    46,    46,    47,    47,
      48,    48,    48,    48,    48,    49,    49,    50,    50,    51,
      51,    51,    51,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    56,    55,    57,    58,    55,
      60,    61,    59,    63,    62,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     3,     2,     1,     4,     1,     1,     1,
       3,     5,     1,     3,     4,     5,     5,     0,     2,     1,
       1,     1,     1,     1,     1,     4,     7,     1,     1,     1,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     0,     8,     0,     0,    13,
       0,     0,     9,     0,    14,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     8,     9,     0,
       0,     5,     0,     7,    17,     0,     3,     4,     0,     0,
       0,    12,     0,     2,     0,    50,     0,     0,     0,    20,
      18,    19,    23,    22,    21,    24,     0,     0,     0,     0,
       6,     0,     0,     0,     0,     0,     0,     0,    15,    16,
      29,    27,    28,     0,    13,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,    42,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     0,     0,    25,     0,     0,    35,
      31,    32,    33,    34,    11,    38,    39,    40,    41,    37,
      36,    43,    44,     0,     0,    51,     0,    55,     0,    30,
      17,    17,     0,     0,     0,     0,     0,    17,     0,    26,
      46,    48,     0,     0,     0,    52,     0,     0,    53,    17,
       0,     0,    17,    49,     0,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    10,    11,    12,    22,    29,    19,    30,
      31,    58,    59,    32,   103,   104,   124,    33,    43,   112,
      34,   130,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -47
static const yytype_int16 yypact[] =
{
       7,   -22,    35,     8,   -47,    95,    66,   -47,   -47,    62,
     146,   -47,    74,   -47,   -47,    75,   -47,   -47,    72,    83,
      52,   -14,    47,   -47,    70,   -47,   115,   123,    12,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,    99,   101,    96,   107,
     -47,   139,    92,   125,   141,    96,    96,    96,   -47,   -47,
     129,   -47,   -47,    96,   128,   130,   150,    96,    82,    45,
      92,   135,    93,   112,   -26,    96,    97,    96,    96,    96,
      96,   -47,    96,   128,    96,    96,    96,    96,    96,    96,
      92,    92,   -47,    53,   145,   136,   -47,   155,   108,   -47,
      57,    57,   -47,   -47,   128,   128,   128,   128,   128,   128,
     128,   -47,   151,   133,   134,   -47,   142,   -47,    96,   -47,
     -47,   -47,   137,   152,   118,     3,    10,   -47,   147,   -47,
     -47,   -47,    32,   154,   167,   -47,   143,   144,   -47,   -47,
     148,    39,   -47,   -47,    46,   -47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   -47,   -47,   -47,   171,   -47,   -47,    58,   -46,   -47,
     -47,   -38,    -2,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -47
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      54,     3,    38,    67,    68,    69,    70,    62,    63,    64,
       1,    87,     5,     9,    24,    66,    25,    26,    27,    73,
       9,    24,    39,    25,    26,    27,    28,    88,    46,    90,
      91,    92,    93,    28,    94,     4,    95,    96,    97,    98,
      99,   100,     9,    24,   120,    25,    26,    27,    47,     9,
      24,   121,    25,    26,    27,    28,     9,    24,    83,    25,
      26,    27,    28,    13,   115,   116,    80,    81,    13,    28,
     114,   122,    14,   125,    80,    81,    36,    37,   101,   102,
     133,    40,    41,   131,    82,    15,   134,   135,    69,    70,
      23,    20,   105,     9,    24,    21,    25,    26,    27,    74,
      75,    76,    77,     7,     8,     9,    28,    18,    42,    78,
      79,    67,    68,    69,    70,    50,    51,    52,    57,    50,
      51,    52,    67,    68,    69,    70,    67,    68,    69,    70,
      53,    55,    85,    48,    53,    49,    89,    67,    68,    69,
      70,    67,    68,    69,    70,   109,    86,    67,    68,    69,
      70,    16,   119,    44,     7,     8,     9,    67,    68,    69,
      70,    45,    56,    60,    61,    65,    72,    71,    84,   106,
     107,   108,    80,   110,   111,   113,   118,   117,   126,   127,
     123,    17,   128,     0,   129,     0,     0,     0,   132
};

static const yytype_int16 yycheck[] =
{
      38,    23,    16,    29,    30,    31,    32,    45,    46,    47,
       3,    37,     4,    10,    11,    53,    13,    14,    15,    57,
      10,    11,    36,    13,    14,    15,    23,    65,    16,    67,
      68,    69,    70,    23,    72,     0,    74,    75,    76,    77,
      78,    79,    10,    11,    41,    13,    14,    15,    36,    10,
      11,    41,    13,    14,    15,    23,    10,    11,    60,    13,
      14,    15,    23,     5,   110,   111,    21,    22,    10,    23,
     108,   117,     6,    41,    21,    22,    24,    25,    80,    81,
      41,    34,    35,   129,    39,    23,   132,    41,    31,    32,
       7,    16,    39,    10,    11,    23,    13,    14,    15,    17,
      18,    19,    20,     8,     9,    10,    23,    33,    38,    27,
      28,    29,    30,    31,    32,    23,    24,    25,    26,    23,
      24,    25,    29,    30,    31,    32,    29,    30,    31,    32,
      38,    24,    39,    34,    38,    34,    39,    29,    30,    31,
      32,    29,    30,    31,    32,    37,    34,    29,    30,    31,
      32,     5,    34,    38,     8,     9,    10,    29,    30,    31,
      32,    38,    23,    38,    23,    36,    16,    37,    33,    24,
      34,    16,    21,    40,    40,    33,    24,    40,    24,    12,
      33,    10,    39,    -1,    40,    -1,    -1,    -1,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,    23,     0,     4,    44,     8,     9,    10,
      45,    46,    47,    49,     6,    23,     5,    46,    33,    50,
      16,    23,    48,     7,    11,    13,    14,    15,    23,    49,
      51,    52,    55,    59,    62,    64,    24,    25,    16,    36,
      34,    35,    38,    60,    38,    38,    16,    36,    34,    34,
      23,    24,    25,    38,    53,    24,    23,    26,    53,    54,
      38,    23,    53,    53,    53,    36,    53,    29,    30,    31,
      32,    37,    16,    53,    17,    18,    19,    20,    27,    28,
      21,    22,    39,    54,    33,    39,    34,    37,    53,    39,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    56,    57,    39,    24,    34,    16,    37,
      40,    40,    61,    33,    53,    50,    50,    40,    24,    34,
      41,    41,    50,    33,    58,    41,    24,    12,    39,    40,
      63,    50,    40,    41,    50,    41
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
        case 2:

/* Line 1455 of yacc.c  */
#line 67 "minialgo.y"
    {
        afficherTable();
        afficher_quads();
        optimiser_quads();
        printf("\n=== APRES OPTIMISATION ===\n");
        afficher_quads();
        generer_asm_8086("output.asm");
        printf("\nAnalyse et compilation terminees avec succes !\n");
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 96 "minialgo.y"
    { current_type = "INTEGER"; current_const = 0; ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 97 "minialgo.y"
    { current_type = "FLOAT";   current_const = 0; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 102 "minialgo.y"
    {
        inserer((yyvsp[(3) - (3)].str), current_type, current_const);
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 105 "minialgo.y"
    {
        inserer((yyvsp[(3) - (5)].str), current_type, current_const);
        setInitialisee((yyvsp[(3) - (5)].str));
        if (!compatible(current_type, (yyvsp[(5) - (5)].expr).type))
            printf("Erreur semantique ligne %d : incompatibilite de type pour '%s' (%s attendu, %s recu)\n",
                   ligne, (yyvsp[(3) - (5)].str), current_type, (yyvsp[(5) - (5)].expr).type);
        else
            generer_quad("=", (yyvsp[(5) - (5)].expr).place, "", (yyvsp[(3) - (5)].str));
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 114 "minialgo.y"
    {
        inserer((yyvsp[(1) - (1)].str), current_type, current_const);
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 117 "minialgo.y"
    {
        inserer((yyvsp[(1) - (3)].str), current_type, current_const);
        setInitialisee((yyvsp[(1) - (3)].str));
        if (!compatible(current_type, (yyvsp[(3) - (3)].expr).type))
            printf("Erreur semantique ligne %d : incompatibilite de type pour '%s' (%s attendu, %s recu)\n",
                   ligne, (yyvsp[(1) - (3)].str), current_type, (yyvsp[(3) - (3)].expr).type);
        else
            generer_quad("=", (yyvsp[(3) - (3)].expr).place, "", (yyvsp[(1) - (3)].str));
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 126 "minialgo.y"
    {
        if ((yyvsp[(3) - (4)].ival) <= 0)
            printf("Erreur semantique ligne %d : taille de tableau invalide pour '%s'\n", ligne, (yyvsp[(1) - (4)].str));
        else
            inserer_tableau((yyvsp[(1) - (4)].str), current_type, (yyvsp[(3) - (4)].ival));
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 136 "minialgo.y"
    {
        if (existe((yyvsp[(2) - (5)].str)))
            printf("Erreur semantique ligne %d : double declaration de '%s'\n", ligne, (yyvsp[(2) - (5)].str));
        else {
            inserer((yyvsp[(2) - (5)].str), "INTEGER", 1);
            setInitialisee((yyvsp[(2) - (5)].str));
            char buf[30]; sprintf(buf, "%d", (yyvsp[(4) - (5)].ival));
            generer_quad("=", buf, "", (yyvsp[(2) - (5)].str));
        }
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 146 "minialgo.y"
    {
        if (existe((yyvsp[(2) - (5)].str)))
            printf("Erreur semantique ligne %d : double declaration de '%s'\n", ligne, (yyvsp[(2) - (5)].str));
        else {
            inserer((yyvsp[(2) - (5)].str), "FLOAT", 1);
            setInitialisee((yyvsp[(2) - (5)].str));
            char buf[30]; sprintf(buf, "%f", (yyvsp[(4) - (5)].fval));
            generer_quad("=", buf, "", (yyvsp[(2) - (5)].str));
        }
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 179 "minialgo.y"
    {
        if (!existe((yyvsp[(1) - (4)].str)))
            printf("Erreur semantique ligne %d : '%s' non declare\n", ligne, (yyvsp[(1) - (4)].str));
        else if (isConstante((yyvsp[(1) - (4)].str)))
            printf("Erreur semantique ligne %d : '%s' est une constante, affectation interdite\n", ligne, (yyvsp[(1) - (4)].str));
        else {
            if (!compatible(getType((yyvsp[(1) - (4)].str)), (yyvsp[(3) - (4)].expr).type))
                printf("Erreur semantique ligne %d : incompatibilite de type (%s = %s)\n",
                       ligne, getType((yyvsp[(1) - (4)].str)), (yyvsp[(3) - (4)].expr).type);
            generer_quad("=", (yyvsp[(3) - (4)].expr).place, "", (yyvsp[(1) - (4)].str));
            setInitialisee((yyvsp[(1) - (4)].str));
        }
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 193 "minialgo.y"
    {
        if (!existe((yyvsp[(1) - (7)].str)))
            printf("Erreur semantique ligne %d : '%s' non declare\n", ligne, (yyvsp[(1) - (7)].str));
        else if (!isTableau((yyvsp[(1) - (7)].str)))
            printf("Erreur semantique ligne %d : '%s' n'est pas un tableau\n", ligne, (yyvsp[(1) - (7)].str));
        else {
            /* vérification d'indice si constante */
            char res[40];
            sprintf(res, "%s[%s]", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].expr).place);
            generer_quad("=", (yyvsp[(6) - (7)].expr).place, "", res);
        }
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 211 "minialgo.y"
    {
        char buf[30]; sprintf(buf, "%d", (yyvsp[(1) - (1)].ival));
        char *t = newTemp();
        generer_quad("=", buf, "", t);
        (yyval.expr).type  = "INTEGER";
        (yyval.expr).place = t;
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 218 "minialgo.y"
    {
        char buf[30]; sprintf(buf, "%f", (yyvsp[(1) - (1)].fval));
        char *t = newTemp();
        generer_quad("=", buf, "", t);
        (yyval.expr).type  = "FLOAT";
        (yyval.expr).place = t;
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 225 "minialgo.y"
    {
        if (!existe((yyvsp[(1) - (1)].str)))
            printf("Erreur semantique ligne %d : '%s' non declare\n", ligne, (yyvsp[(1) - (1)].str));
        else if (!estInitialisee((yyvsp[(1) - (1)].str)))
            printf("Avertissement ligne %d : '%s' utilisee sans initialisation\n", ligne, (yyvsp[(1) - (1)].str));
        (yyval.expr).type  = existe((yyvsp[(1) - (1)].str)) ? getType((yyvsp[(1) - (1)].str)) : "INTEGER";
        (yyval.expr).place = (yyvsp[(1) - (1)].str);
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 234 "minialgo.y"
    {
        if (!existe((yyvsp[(1) - (4)].str)))
            printf("Erreur semantique ligne %d : '%s' non declare\n", ligne, (yyvsp[(1) - (4)].str));
        else if (!isTableau((yyvsp[(1) - (4)].str)))
            printf("Erreur semantique ligne %d : '%s' n'est pas un tableau\n", ligne, (yyvsp[(1) - (4)].str));
        char *t = newTemp();
        char  src[40]; sprintf(src, "%s[%s]", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].expr).place);
        generer_quad("=", src, "", t);
        (yyval.expr).type  = existe((yyvsp[(1) - (4)].str)) ? getType((yyvsp[(1) - (4)].str)) : "INTEGER";
        (yyval.expr).place = t;
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 245 "minialgo.y"
    {
        if (!compatible((yyvsp[(1) - (3)].expr).type, (yyvsp[(3) - (3)].expr).type))
            printf("Erreur semantique ligne %d : types incompatibles dans '+'\n", ligne);
        char *t = newTemp();
        generer_quad("+", (yyvsp[(1) - (3)].expr).place, (yyvsp[(3) - (3)].expr).place, t);
        (yyval.expr).type  = (strcmp((yyvsp[(1) - (3)].expr).type,"FLOAT")==0 || strcmp((yyvsp[(3) - (3)].expr).type,"FLOAT")==0) ? "FLOAT" : "INTEGER";
        (yyval.expr).place = t;
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 253 "minialgo.y"
    {
        if (!compatible((yyvsp[(1) - (3)].expr).type, (yyvsp[(3) - (3)].expr).type))
            printf("Erreur semantique ligne %d : types incompatibles dans '-'\n", ligne);
        char *t = newTemp();
        generer_quad("-", (yyvsp[(1) - (3)].expr).place, (yyvsp[(3) - (3)].expr).place, t);
        (yyval.expr).type  = (strcmp((yyvsp[(1) - (3)].expr).type,"FLOAT")==0 || strcmp((yyvsp[(3) - (3)].expr).type,"FLOAT")==0) ? "FLOAT" : "INTEGER";
        (yyval.expr).place = t;
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 261 "minialgo.y"
    {
        if (!compatible((yyvsp[(1) - (3)].expr).type, (yyvsp[(3) - (3)].expr).type))
            printf("Erreur semantique ligne %d : types incompatibles dans '*'\n", ligne);
        char *t = newTemp();
        generer_quad("*", (yyvsp[(1) - (3)].expr).place, (yyvsp[(3) - (3)].expr).place, t);
        (yyval.expr).type  = (strcmp((yyvsp[(1) - (3)].expr).type,"FLOAT")==0 || strcmp((yyvsp[(3) - (3)].expr).type,"FLOAT")==0) ? "FLOAT" : "INTEGER";
        (yyval.expr).place = t;
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 269 "minialgo.y"
    {
        if (!compatible((yyvsp[(1) - (3)].expr).type, (yyvsp[(3) - (3)].expr).type))
            printf("Erreur semantique ligne %d : types incompatibles dans '/'\n", ligne);
        /* détection division par zéro sur constante littérale */
        if (strcmp((yyvsp[(3) - (3)].expr).place, "0") == 0)
            printf("Erreur semantique ligne %d : division par zero\n", ligne);
        char *t = newTemp();
        generer_quad("/", (yyvsp[(1) - (3)].expr).place, (yyvsp[(3) - (3)].expr).place, t);
        (yyval.expr).type  = "FLOAT";
        (yyval.expr).place = t;
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 280 "minialgo.y"
    {
        (yyval.expr) = (yyvsp[(2) - (3)].expr);
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 289 "minialgo.y"
    {
        char *t = newTemp();
        generer_quad(">", (yyvsp[(1) - (3)].expr).place, (yyvsp[(3) - (3)].expr).place, t);
        (yyval.expr).type = "INTEGER"; (yyval.expr).place = t;
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 294 "minialgo.y"
    {
        char *t = newTemp();
        generer_quad("<", (yyvsp[(1) - (3)].expr).place, (yyvsp[(3) - (3)].expr).place, t);
        (yyval.expr).type = "INTEGER"; (yyval.expr).place = t;
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 299 "minialgo.y"
    {
        char *t = newTemp();
        generer_quad("==", (yyvsp[(1) - (3)].expr).place, (yyvsp[(3) - (3)].expr).place, t);
        (yyval.expr).type = "INTEGER"; (yyval.expr).place = t;
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 304 "minialgo.y"
    {
        char *t = newTemp();
        generer_quad("!=", (yyvsp[(1) - (3)].expr).place, (yyvsp[(3) - (3)].expr).place, t);
        (yyval.expr).type = "INTEGER"; (yyval.expr).place = t;
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 309 "minialgo.y"
    {
        char *t = newTemp();
        generer_quad(">=", (yyvsp[(1) - (3)].expr).place, (yyvsp[(3) - (3)].expr).place, t);
        (yyval.expr).type = "INTEGER"; (yyval.expr).place = t;
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 314 "minialgo.y"
    {
        char *t = newTemp();
        generer_quad("<=", (yyvsp[(1) - (3)].expr).place, (yyvsp[(3) - (3)].expr).place, t);
        (yyval.expr).type = "INTEGER"; (yyval.expr).place = t;
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 319 "minialgo.y"
    {
        char *t = newTemp();
        generer_quad("!", (yyvsp[(2) - (2)].expr).place, "", t);
        (yyval.expr).type = "INTEGER"; (yyval.expr).place = t;
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 324 "minialgo.y"
    {
        char *t = newTemp();
        generer_quad("&&", (yyvsp[(1) - (3)].expr).place, (yyvsp[(3) - (3)].expr).place, t);
        (yyval.expr).type = "INTEGER"; (yyval.expr).place = t;
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 329 "minialgo.y"
    {
        char *t = newTemp();
        generer_quad("||", (yyvsp[(1) - (3)].expr).place, (yyvsp[(3) - (3)].expr).place, t);
        (yyval.expr).type = "INTEGER"; (yyval.expr).place = t;
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 352 "minialgo.y"
    {
        char *lelse = newLabel();
        generer_quad("ifFalse", (yyvsp[(3) - (4)].expr).place, "", lelse);
        (yyval.str) = lelse;
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 358 "minialgo.y"
    {
        generer_quad("label", "", "", (yyvsp[(3) - (8)].str));
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 363 "minialgo.y"
    {
        char *lelse = newLabel();
        generer_quad("ifFalse", (yyvsp[(3) - (4)].expr).place, "", lelse);
        (yyval.str) = lelse;
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 369 "minialgo.y"
    {
        char *lend = newLabel();
        generer_quad("goto", "", "", lend);
        generer_quad("label", "", "", (yyvsp[(3) - (8)].str));
        (yyval.str) = lend;
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 376 "minialgo.y"
    {
        generer_quad("label", "", "", (yyvsp[(7) - (13)].str));
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 395 "minialgo.y"
    {
            char *ldebut = newLabel();
            generer_quad("label", "", "", ldebut);
            (yyval.str) = ldebut;
        ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 401 "minialgo.y"
    {
            char *lfin = newLabel();
            generer_quad("ifFalse", (yyvsp[(4) - (5)].expr).place, "", lfin);
            (yyval.str) = lfin;
        ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 407 "minialgo.y"
    {
            generer_quad("goto",  "", "", (yyvsp[(2) - (9)].str));   /* retour en début de boucle */
            generer_quad("label", "", "", (yyvsp[(6) - (9)].str));   /* label de sortie           */
        ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 431 "minialgo.y"
    {
            /* ── vérifications sémantiques ── */
            if (!existe((yyvsp[(3) - (10)].str)))
                printf("Erreur semantique ligne %d : '%s' non declare\n", ligne, (yyvsp[(3) - (10)].str));
            else if (isConstante((yyvsp[(3) - (10)].str)))
                printf("Erreur semantique ligne %d : '%s' est une constante\n", ligne, (yyvsp[(3) - (10)].str));
            else if (strcmp(getType((yyvsp[(3) - (10)].str)), "INTEGER") != 0)
                printf("Erreur semantique ligne %d : l'indice de FOR doit etre INTEGER\n", ligne);

            if ((yyvsp[(7) - (10)].ival) == 0)
                printf("Erreur semantique ligne %d : le pas du FOR ne peut pas etre 0\n", ligne);
            if ((yyvsp[(7) - (10)].ival) > 0 && (yyvsp[(9) - (10)].ival) < (yyvsp[(5) - (10)].ival))
                printf("Avertissement ligne %d : borne de fin < borne de debut (boucle vide)\n", ligne);

            /* ── initialisation de l'indice ── */
            char buf_debut[20], buf_pas[20], buf_fin[20];
            sprintf(buf_debut, "%d", (yyvsp[(5) - (10)].ival));
            sprintf(buf_pas,   "%d", (yyvsp[(7) - (10)].ival));
            sprintf(buf_fin,   "%d", (yyvsp[(9) - (10)].ival));

            generer_quad("=", buf_debut, "", (yyvsp[(3) - (10)].str));
            setInitialisee((yyvsp[(3) - (10)].str));

            /* ── label de début de boucle ── */
            char *ldebut = newLabel();
            generer_quad("label", "", "", ldebut);

            /* ── condition i <= fin ── */
            char *tcond = newTemp();
            generer_quad("<=", (yyvsp[(3) - (10)].str), buf_fin, tcond);

            /* ── saut de sortie ── */
            char *lfin = newLabel();
            generer_quad("ifFalse", tcond, "", lfin);

            /* stocker pour après les instructions */
            (yyval.str) = ldebut;      /* on réutilise $$ pour stocker ldebut */

            /* NOTE : buf_pas et lfin sont stockés via une astuce —
               on les passe en global temporairement */
            /* Pour simplifier : on les stocke dans des variables globales ad-hoc */
            extern char _for_pas[20];
            extern char _for_idf[20];
            extern char _for_lfin[30];
            strcpy(_for_pas,  buf_pas);
            strcpy(_for_idf,  (yyvsp[(3) - (10)].str));
            strcpy(_for_lfin, lfin);
        ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 480 "minialgo.y"
    {
            extern char _for_pas[20];
            extern char _for_idf[20];
            extern char _for_lfin[30];

            /* incrémenter l'indice */
            char *tinc = newTemp();
            generer_quad("+", _for_idf, _for_pas, tinc);
            generer_quad("=", tinc, "", _for_idf);

            /* retour au début */
            generer_quad("goto",  "", "", (yyvsp[(11) - (14)].str));

            /* label de fin */
            generer_quad("label", "", "", _for_lfin);
        ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 502 "minialgo.y"
    {
        if (strcmp((yyvsp[(3) - (5)].expr).type, "INTEGER") != 0 && strcmp((yyvsp[(3) - (5)].expr).type, "FLOAT") != 0)
            printf("Erreur semantique ligne %d : WRITE ne peut afficher que INTEGER ou FLOAT\n", ligne);
        generer_quad("write", (yyvsp[(3) - (5)].expr).place, "", "");
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2040 "minialgo.tab.c"
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
#line 509 "minialgo.y"


/* ─────────────────────────────────────────
   Variables globales pour la boucle FOR
   ───────────────────────────────────────── */
char _for_pas[20]  = "";
char _for_idf[20]  = "";
char _for_lfin[30] = "";

/* ─────────────────────────────────────────
   Gestion des erreurs syntaxiques
   ───────────────────────────────────────── */
void yyerror(const char *s) {
    printf("Erreur syntaxique : ligne %d, colonne %d : %s\n", ligne, colonne, s);
}

