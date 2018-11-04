/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 9 "mipl.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>
#include <deque>
#include <list>
#include "SymbolTable.h"
#include "oal.h"
using namespace std;

void ignoreComment();
int ckInt();
void prRule(const char*, const char*);
void printTokenInfo(const char* tokenType, 
					const char* lexeme);
void prSymbolTableAddition(const string identName, 
						   const TYPE_INFO typeInfo);
void beginScope();
void endScope();
void cleanUp();
TYPE_INFO findEntryInAnyScope(const string theName);

// Hw6
Oal oal;
string temp;
bool is_var = false;
string assigned_variable;
bool negative = false;
string comparator;
bool negation = false; // For "not"
stack<string> comparator_stack;
stack<string> else_stack;
stack<string> all_done_stack;
stack<string> label_stack; // Used to match Dr. Leopold's output
deque<string> while_deque;
stack<string> array_var_stack;
bool handled_in_array;
int nesting_level = 0; // Proc nesting level
stack<string> proc_stack;

int yyerror(const char*);

extern "C" {
	int yyparse(void);
	int yylex(void);
	int yywrap() {return 1;}
}

#define MAX_INT	"2147483647"

#define PRINT_STUFF 		0
#define OUTPUT_TOKENS	 	PRINT_STUFF
#define OUTPUT_PRODUCTIONS 	PRINT_STUFF
#define OUTPUT_ST_MGT      	PRINT_STUFF

#define POSITIVE		1
#define NEGATIVE		-1

#define LOGICAL_OP 		100
#define ARITHMETIC_OP 	101

int lineNum = 1;                   // source line number

stack<SYMBOL_TABLE> scopeStack;    // stack of scope hashtables
list<string> variableNames;		  // list of declared variables


#line 138 "mipl.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_LPAREN = 258,
    T_RPAREN = 259,
    T_MULT = 260,
    T_PLUS = 261,
    T_COMMA = 262,
    T_MINUS = 263,
    T_DOT = 264,
    T_DOTDOT = 265,
    T_COLON = 266,
    T_ASSIGN = 267,
    T_SCOLON = 268,
    T_LT = 269,
    T_LE = 270,
    T_NE = 271,
    T_EQ = 272,
    T_GT = 273,
    T_GE = 274,
    T_LBRACK = 275,
    T_RBRACK = 276,
    T_DO = 277,
    T_AND = 278,
    T_ARRAY = 279,
    T_BEGIN = 280,
    T_BOOL = 281,
    T_CHAR = 282,
    T_CHARCONST = 283,
    T_DIV = 284,
    T_END = 285,
    T_FALSE = 286,
    T_IDENT = 287,
    T_IF = 288,
    T_INT = 289,
    T_INTCONST = 290,
    T_NOT = 291,
    T_OF = 292,
    T_OR = 293,
    T_PROC = 294,
    T_PROG = 295,
    T_READ = 296,
    T_TRUE = 297,
    T_VAR = 298,
    T_WHILE = 299,
    T_WRITE = 300,
    T_UNKNOWN = 301,
    ST_EOF = 302,
    T_THEN = 303,
    T_ELSE = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 81 "mipl.y" /* yacc.c:355  */

  char* text;
  char ch;
  int num;
  bool boolean;
  TYPE_INFO typeInfo;
  int intValue;

#line 234 "mipl.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 251 "mipl.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   136,   136,   163,   167,   175,   186,   195,   195,   242,
     241,   268,   282,   297,   304,   311,   303,   329,   339,   342,
     341,   356,   370,   385,   394,   403,   418,   459,   482,   492,
     503,   519,   526,   529,   537,   543,   557,   556,   587,   590,
     596,   625,   647,   650,   650,   668,   696,   699,   704,   711,
     732,   735,   741,   760,   770,   769,   783,   789,   795,   800,
     805,   810,   815,   820,   827,   832,   838,   845,   853,   861,
     870,   880,   884,   888,   892,   896,   900,   904,   910,   913,
     919,   924,   933,   941,   950,   985,   988,   995,   998,  1004,
    1013,  1023,  1044,  1053,  1043,  1071,  1078,  1083,  1089,  1095,
    1100,  1106,  1111,  1117,  1123,  1128
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_LPAREN", "T_RPAREN", "T_MULT",
  "T_PLUS", "T_COMMA", "T_MINUS", "T_DOT", "T_DOTDOT", "T_COLON",
  "T_ASSIGN", "T_SCOLON", "T_LT", "T_LE", "T_NE", "T_EQ", "T_GT", "T_GE",
  "T_LBRACK", "T_RBRACK", "T_DO", "T_AND", "T_ARRAY", "T_BEGIN", "T_BOOL",
  "T_CHAR", "T_CHARCONST", "T_DIV", "T_END", "T_FALSE", "T_IDENT", "T_IF",
  "T_INT", "T_INTCONST", "T_NOT", "T_OF", "T_OR", "T_PROC", "T_PROG",
  "T_READ", "T_TRUE", "T_VAR", "T_WHILE", "T_WRITE", "T_UNKNOWN", "ST_EOF",
  "T_THEN", "T_ELSE", "$accept", "N_START", "N_ADDOPLST", "N_ARRAY",
  "N_ARRAYVAR", "N_ASSIGN", "$@1", "N_BLOCK", "$@2", "N_BOOLCONST",
  "N_COMPOUND", "N_CONDITION", "$@3", "$@4", "N_THEN", "N_ELSE", "$@5",
  "N_CONST", "N_ENTIREVAR", "N_EXPR", "N_FACTOR", "N_IDENT", "N_IDENTLST",
  "N_IDX", "N_IDXRANGE", "N_IDXVAR", "$@6", "N_INPUTLST", "N_INPUTVAR",
  "N_INTCONST", "N_MULTOPLST", "$@7", "N_OUTPUT", "N_OUTPUTLST",
  "N_PROCDEC", "N_PROCHDR", "N_PROCDECPART", "N_PROCIDENT", "N_PROCSTMT",
  "N_PROG", "$@8", "N_PROGLBL", "N_READ", "N_RELOP", "N_SIGN", "N_SIMPLE",
  "N_SIMPLEEXPR", "N_STMT", "N_STMTLST", "N_STMTPART", "N_TERM", "N_TYPE",
  "N_VARDEC", "N_VARDECLST", "N_VARDECPART", "N_VARIABLE", "N_VARIDENT",
  "N_WHILE", "$@9", "$@10", "N_WRITE", "N_ADDOP", "N_ADD_OP_LOGICAL",
  "N_ADD_OP_ARITHMETIC", "N_MULTOP", "N_MULT_OP_LOGICAL",
  "N_MULT_OP_ARITHMETIC", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -75

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-75)))

#define YYTABLE_NINF -92

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -24,   -75,    21,   -75,     1,   -75,    19,   -75,    -3,    14,
      48,    20,   -75,    53,    49,   -75,    29,    51,    -3,   -75,
      14,    52,    14,    54,    20,   -75,    41,    53,   -12,    55,
     -75,   -75,   -75,     4,   -75,   -75,   -75,    56,   -75,   -75,
     -75,   -75,   -75,   -75,    14,    11,   -75,    66,   -75,    67,
     -75,   -75,   -75,   -75,    57,   -75,   -75,   -75,   -75,    59,
     -75,   -75,   -75,   -75,    50,   -75,    -1,    42,    -1,    -1,
      60,     4,    43,    63,   -75,   -75,    69,    61,   -75,    46,
      -1,   -75,   -75,    -1,   -75,   -75,   -75,   -75,     5,   -75,
     -15,    36,     0,   -75,    76,   -75,   -75,   -75,    77,    -1,
      59,   -75,    -1,    50,    58,   -75,    81,   -75,    38,   -75,
     -75,   -75,   -75,    -1,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,    -1,   -75,   -75,   -75,   -75,    -1,   -75,
     -75,    42,    83,    68,    -1,    84,    70,   -75,   -75,   -75,
      -8,   -75,     4,   -75,   -75,   -75,     0,    76,   -75,     4,
      77,   -75,   -75,   -75,    40,     5,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,     4,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    56,     0,     2,     0,     1,     0,    54,    87,     0,
       0,    50,    31,    32,     0,    55,     0,     0,    87,     9,
       0,     0,    85,     0,    50,    48,     0,    32,     0,     0,
      88,    49,    51,     0,    80,    10,    33,     0,    69,    68,
      67,    83,    82,    84,    85,    52,    14,     0,    92,     0,
      36,    71,    77,    75,    89,    90,    53,    72,    73,    78,
       7,    24,    76,    74,    64,    86,    64,     0,    64,    64,
       0,     0,     0,     0,    65,    66,     0,     0,    34,     0,
      64,    22,    12,    64,    11,    23,    28,    15,    42,    21,
       0,    25,     3,    91,    38,    40,    93,    45,    46,    64,
      78,    13,    64,    64,     0,    41,     0,    30,     0,   104,
     103,   105,    81,    64,   101,   102,    27,    58,    60,    63,
      62,    59,    61,    64,    99,   100,    98,    70,    64,    96,
      97,     0,     0,     0,    64,     0,     0,    79,     8,    35,
       0,    29,     0,    16,    43,    26,     3,    38,    57,     0,
      46,    95,    37,     5,    17,    42,     4,    39,    94,    47,
      19,    18,    44,     0,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -75,   -75,   -53,   -75,   -75,   -75,   -75,    78,   -75,   -75,
      71,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -55,
     -74,    74,    72,    -5,   -75,   -75,   -75,   -47,   -30,   -61,
     -52,   -75,   -32,   -46,   -75,   -75,    82,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -60,   -35,   -16,   -71,     8,   -75,
     -19,   -75,   101,    73,   -75,   -66,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   127,    41,    50,    51,    73,    10,    26,    85,
      52,    53,    66,   108,   143,   161,   163,    86,    54,    97,
      88,    13,    21,    76,    77,    55,    70,   132,    94,    89,
     112,   155,    98,   135,    17,    18,    19,    56,    57,     3,
       8,     4,    58,   123,    90,    42,    91,    59,    72,    35,
      92,    43,    29,    30,    11,    60,    61,    62,    68,   133,
      63,   128,   129,   130,   113,   114,   115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     100,    95,    80,    78,    79,    74,   124,    75,   125,   107,
     109,    87,    37,    96,    38,    39,     1,    93,    38,    39,
     105,     5,    40,   -91,   116,   106,    40,    81,   110,    33,
      82,   -91,     7,     6,   111,    83,    45,    46,   126,   144,
       9,    84,    78,    79,   136,    47,    12,   138,    48,    49,
     117,   118,   119,   120,   121,   122,    74,    15,    75,    16,
      20,    23,    22,    28,    24,    95,    33,    31,    44,    67,
      69,   154,    71,   101,    93,   102,    64,    -6,   158,   103,
      99,   105,   104,   131,   134,   141,   142,   148,   151,   160,
     149,   152,   164,   156,    27,   140,    25,    34,   139,    36,
     157,   147,   150,   162,   159,   153,    32,   145,   137,   146,
      14,     0,     0,     0,     0,     0,     0,    65
};

static const yytype_int16 yycheck[] =
{
      71,    67,     3,    64,    64,     6,     6,     8,     8,    83,
       5,    66,    24,    68,    26,    27,    40,    32,    26,    27,
      35,     0,    34,    12,    90,    80,    34,    28,    23,    25,
      31,    20,    13,    32,    29,    36,    32,    33,    38,   113,
      43,    42,   103,   103,    99,    41,    32,   102,    44,    45,
      14,    15,    16,    17,    18,    19,     6,     9,     8,    39,
       7,    32,    13,    11,    13,   131,    25,    13,    13,     3,
       3,   142,    13,    30,    32,    12,    20,    20,   149,    10,
      20,    35,    21,     7,     7,     4,    48,     4,     4,    49,
      22,    21,   163,   146,    20,    37,    18,    26,   103,    27,
     147,   131,   134,   155,   150,   140,    24,   123,   100,   128,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    51,    89,    91,     0,    32,    13,    90,    43,
      57,   104,    32,    71,   102,     9,    39,    84,    85,    86,
       7,    72,    13,    32,    13,    57,    58,    71,    11,   102,
     103,    13,    86,    25,    60,    99,    72,    24,    26,    27,
      34,    53,    95,   101,    13,    32,    33,    41,    44,    45,
      54,    55,    60,    61,    68,    75,    87,    88,    92,    97,
     105,   106,   107,   110,    20,   103,    62,     3,   108,     3,
      76,    13,    98,    56,     6,     8,    73,    74,    79,    94,
       3,    28,    31,    36,    42,    59,    67,    69,    70,    79,
      94,    96,   100,    32,    78,   105,    69,    69,    82,    20,
      97,    30,    12,    10,    21,    35,    69,    70,    63,     5,
      23,    29,    80,   114,   115,   116,   105,    14,    15,    16,
      17,    18,    19,    93,     6,     8,    38,    52,   111,   112,
     113,     7,    77,   109,     7,    83,    69,    98,    69,    73,
      37,     4,    48,    64,    70,    96,   100,    78,     4,    22,
      82,     4,    21,    95,    97,    81,    52,    77,    97,    83,
      49,    65,    80,    66,    97
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    54,    56,    55,    58,
      57,    59,    59,    60,    62,    63,    61,    64,    64,    66,
      65,    67,    67,    67,    68,    69,    69,    70,    70,    70,
      70,    71,    72,    72,    73,    74,    76,    75,    77,    77,
      78,    79,    80,    81,    80,    82,    83,    83,    84,    85,
      86,    86,    87,    88,    90,    89,    91,    92,    93,    93,
      93,    93,    93,    93,    94,    94,    94,    95,    95,    95,
      96,    97,    97,    97,    97,    97,    97,    97,    98,    98,
      99,   100,   101,   101,   102,   103,   103,   104,   104,   105,
     105,   106,   108,   109,   107,   110,   111,   111,   112,   113,
     113,   114,   114,   115,   116,   116
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     3,     6,     1,     0,     4,     0,
       4,     1,     1,     4,     0,     0,     5,     2,     3,     0,
       3,     1,     1,     1,     1,     1,     3,     2,     1,     3,
       2,     1,     0,     3,     1,     3,     0,     5,     0,     3,
       1,     2,     0,     0,     4,     1,     0,     3,     2,     3,
       0,     3,     1,     1,     0,     6,     1,     5,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       1,     2,     1,     1,     4,     0,     3,     0,     4,     1,
       1,     1,     0,     0,     6,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 137 "mipl.y" /* yacc.c:1646  */
    {
						prRule("N_START", "N_PROG");
						//printf("\n---- Completed parsing ----\n\n");

						// Add halt instruciton at end of main
						oal.push_back(Instruction("halt"));

						return 0;
					}
#line 1463 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 163 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_ADDOPLST", "epsilon");
					//comparator = ""; //might need as a divider
					}
#line 1472 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 168 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_ADDOPLST", 
						   "N_ADDOP N_TERM N_ADDOPLST");


					}
#line 1483 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 177 "mipl.y" /* yacc.c:1646  */
    {
						prRule("N_ARRAY",
						"T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE");
				(yyval.typeInfo).type = ARRAY; 
					  (yyval.typeInfo).startIndex = (yyvsp[-3].typeInfo).startIndex;
					  (yyval.typeInfo).endIndex = (yyvsp[-3].typeInfo).endIndex;
					(yyval.typeInfo).baseType = (yyvsp[0].typeInfo).type;
					}
#line 1496 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 187 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_ARRAYVAR", "N_ENTIREVAR");
				(yyval.typeInfo).type = (yyvsp[0].typeInfo).type; 
					(yyval.typeInfo).startIndex = (yyvsp[0].typeInfo).startIndex;
					(yyval.typeInfo).endIndex = (yyvsp[0].typeInfo).endIndex;
				 (yyval.typeInfo).baseType = (yyvsp[0].typeInfo).baseType;
					}
#line 1508 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 195 "mipl.y" /* yacc.c:1646  */
    {
					// Set assign oal
					if(handled_in_array == false) {
						oal.la(temp);
					}
					handled_in_array = false;
				}
#line 1520 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 202 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_ASSIGN", 
						   "N_VARIABLE T_ASSIGN N_EXPR");

						// If variable is array => error
						if((yyvsp[-3].typeInfo).type == ARRAY && (yyvsp[-3].typeInfo).entireVar == true) {
							yyerror("Cannot make assignment to an array");
						}

						if((yyvsp[0].typeInfo).type == PROCEDURE || (yyvsp[-3].typeInfo).type == PROCEDURE) {
							yyerror("Procedure/variable mismatch");
						}

						// If arrays of different types
						if((yyvsp[-3].typeInfo).type == (yyvsp[0].typeInfo).type && (yyvsp[-3].typeInfo).type == ARRAY) {
							// If array of different base types, throw error
							if((yyvsp[-3].typeInfo).baseType != (yyvsp[0].typeInfo).baseType) {
								yyerror("Expression must be of same type as variable");
							}
						}

						// LHS is array of different type than RHS
						if((yyvsp[-3].typeInfo).type == ARRAY && (yyvsp[0].typeInfo).type != ARRAY && (yyvsp[-3].typeInfo).baseType != (yyvsp[0].typeInfo).type) {
							yyerror("Expression must be of same type as variable");
						}

						// RHS is array of different type than LHS
						if((yyvsp[0].typeInfo).type == ARRAY && (yyvsp[-3].typeInfo).type != ARRAY && (yyvsp[0].typeInfo).baseType != (yyvsp[-3].typeInfo).type) {
							yyerror("Expression must be of same type as variable");
						}

						// --- N_var and N_expr must match --- //
						if((yyvsp[-3].typeInfo).type != (yyvsp[0].typeInfo).type && (yyvsp[-3].typeInfo).type != ARRAY && (yyvsp[0].typeInfo).type != ARRAY) { // If array and different base types
							yyerror("Expression must be of same type as variable");
						}

						oal.push_back(Instruction("st"));
					}
#line 1563 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 242 "mipl.y" /* yacc.c:1646  */
    {
						// Add label to block
						if(proc_stack.empty() == false) {
							oal.push_back(Instruction(oal.get_proc(proc_stack.top())));
							proc_stack.pop();
							oal.push_back(Instruction("save", nesting_level));
							oal.in_proc = true;
						} else {
							// Main
							oal.push_back(Instruction("L.3"));
							oal.in_proc = false;
						}

						// If in a procedure, perform asp
						oal.add_asp();
					}
#line 1584 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 258 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_BLOCK", 
						"N_VARDECPART N_PROCDECPART N_STMTPART");

						// If in a procedure, perform asp removal
						oal.remove_asp();

						endScope();
					}
#line 1598 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 269 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_BOOLCONST", "T_TRUE");
						(yyval.typeInfo).type = BOOL; 
						(yyval.typeInfo).startIndex = NOT_APPLICABLE;
						(yyval.typeInfo).endIndex = NOT_APPLICABLE;
						(yyval.typeInfo).baseType = NOT_APPLICABLE;

						// Set temp
						temp = "1";
						is_var = false;

						oal.push_back(Instruction("lc", 1));
					}
#line 1616 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 283 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_BOOLCONST", "T_FALSE");
						(yyval.typeInfo).type = BOOL; 
						(yyval.typeInfo).startIndex = NOT_APPLICABLE;
						(yyval.typeInfo).endIndex = NOT_APPLICABLE;
						(yyval.typeInfo).baseType = NOT_APPLICABLE;

						// Set temp
						temp = "0";
						is_var = false;

						oal.push_back(Instruction("lc", 0));
					}
#line 1634 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 298 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_COMPOUND", 
						   "T_BEGIN N_STMT N_STMTLST T_END");
					}
#line 1643 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 304 "mipl.y" /* yacc.c:1646  */
    {
						// Generate new labels for all done and else
						string next_label = oal.new_label();
						label_stack.push(oal.new_label());
						label_stack.push(next_label);
					}
#line 1654 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 311 "mipl.y" /* yacc.c:1646  */
    {
						if((yyvsp[0].typeInfo).type != BOOL) {
							yyerror("Expression must be of type boolean");
						}


						// Add generated label to else stack
						else_stack.push(label_stack.top());
						// Jump to new label if false
						oal.push_back(Instruction("jf", else_stack.top()));
						// Remove label from label stack
						label_stack.pop();
					}
#line 1672 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 324 "mipl.y" /* yacc.c:1646  */
    {
						oal.push_back(Instruction(all_done_stack.top()));
						all_done_stack.pop();
					}
#line 1681 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 330 "mipl.y" /* yacc.c:1646  */
    {
						all_done_stack.push(label_stack.top());
						oal.push_back(Instruction("jp", all_done_stack.top()));
						// Remove label from label stack
						label_stack.pop();

						oal.push_back(Instruction(else_stack.top()));
						else_stack.pop();
					}
#line 1695 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 342 "mipl.y" /* yacc.c:1646  */
    {
						all_done_stack.push(label_stack.top());
						oal.push_back(Instruction("jp", all_done_stack.top()));
						// Remove label from label stack
						label_stack.pop();

						oal.push_back(Instruction(else_stack.top()));
						else_stack.pop();
					}
#line 1709 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 352 "mipl.y" /* yacc.c:1646  */
    {

					}
#line 1717 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 357 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_CONST", "N_INTCONST");
						(yyval.typeInfo).type = INT; 
						(yyval.typeInfo).startIndex = NOT_APPLICABLE;
						(yyval.typeInfo).endIndex = NOT_APPLICABLE;
						(yyval.typeInfo).baseType = NOT_APPLICABLE;

						// Keep track of var and type
						temp = to_string((yyvsp[0].num));
						is_var = false;

						oal.push_back(Instruction("lc", temp));
					}
#line 1735 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 371 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_CONST", "T_CHARCONST");
						(yyval.typeInfo).type = CHAR; 
						(yyval.typeInfo).startIndex = NOT_APPLICABLE;
						(yyval.typeInfo).endIndex = NOT_APPLICABLE;
				 		(yyval.typeInfo).baseType = NOT_APPLICABLE;

				 		// Keep track of var and type
				 		temp = to_string(int((yyvsp[0].ch)));
				 		//temp = string(1, $1);
				 		is_var = false;

				 		oal.push_back(Instruction("lc", temp));
					}
#line 1754 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 386 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_CONST", "N_BOOLCONST");
						(yyval.typeInfo).type = BOOL; 
						(yyval.typeInfo).startIndex = NOT_APPLICABLE;
						(yyval.typeInfo).endIndex = NOT_APPLICABLE;
						(yyval.typeInfo).baseType = NOT_APPLICABLE;
					}
#line 1766 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 395 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_ENTIREVAR", "N_VARIDENT");
					(yyval.typeInfo).type = (yyvsp[0].typeInfo).type; 
					(yyval.typeInfo).startIndex = (yyvsp[0].typeInfo).startIndex;
					(yyval.typeInfo).endIndex = (yyvsp[0].typeInfo).endIndex;
				 (yyval.typeInfo).baseType = (yyvsp[0].typeInfo).baseType;
					}
#line 1778 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 404 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_EXPR", "N_SIMPLEEXPR");
						(yyval.typeInfo).type = (yyvsp[0].typeInfo).type; 
						(yyval.typeInfo).startIndex = (yyvsp[0].typeInfo).startIndex;
						(yyval.typeInfo).endIndex = (yyvsp[0].typeInfo).endIndex;
						(yyval.typeInfo).baseType = (yyvsp[0].typeInfo).baseType;

						// add, sub, mult, div, and, or, .eq., .ne., .lt., .le., .gt., .ge.
						while(comparator_stack.empty() == false) {
							comparator = comparator_stack.top();
							comparator_stack.pop();
							oal.push_back(comparator);
						}
					}
#line 1797 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 419 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_EXPR", 
						   "N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR");

						// If arrays of different types
						if((yyvsp[-2].typeInfo).type == (yyvsp[0].typeInfo).type && (yyvsp[-2].typeInfo).type == ARRAY) {
							// If array of different base types, throw error
							if((yyvsp[-2].typeInfo).baseType != (yyvsp[0].typeInfo).baseType) {
								yyerror("Expressions must both be int, or both char, or both boolean");
							}
						}

						// LHS is array of different type than RHS
						if((yyvsp[-2].typeInfo).type == ARRAY && (yyvsp[0].typeInfo).type != ARRAY && (yyvsp[-2].typeInfo).baseType != (yyvsp[0].typeInfo).type) {
							yyerror("Expressions must both be int, or both char, or both boolean");
						}

						// RHS is array of different type than LHS
						if((yyvsp[0].typeInfo).type == ARRAY && (yyvsp[-2].typeInfo).type != ARRAY && (yyvsp[0].typeInfo).baseType != (yyvsp[-2].typeInfo).type) {
							yyerror("Expressions must both be int, or both char, or both boolean");
						}

						// --- N_var and N_expr must match --- //
						if((yyvsp[-2].typeInfo).type != (yyvsp[0].typeInfo).type && (yyvsp[-2].typeInfo).type != ARRAY && (yyvsp[0].typeInfo).type != ARRAY) { // If array and different base types
							yyerror("Expressions must both be int, or both char, or both boolean");
						}

						(yyval.typeInfo).type = BOOL; 
						(yyval.typeInfo).startIndex = NOT_APPLICABLE;
						(yyval.typeInfo).endIndex = NOT_APPLICABLE;
						(yyval.typeInfo).baseType = NOT_APPLICABLE;

						// add, sub, mult, div, and, or, .eq., .ne., .lt., .le., .gt., .ge.
						while(comparator_stack.empty() == false) {
							comparator = comparator_stack.top();
							comparator_stack.pop();
							oal.push_back(comparator);
						}
					}
#line 1841 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 460 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_FACTOR", "N_SIGN N_VARIABLE");
						if((yyvsp[0].typeInfo).type == CHAR && (yyvsp[-1].num) == NEGATIVE) {
							yyerror("Expression must be of type integer");
						}

						(yyval.typeInfo).type = (yyvsp[0].typeInfo).type; 
						(yyval.typeInfo).startIndex = (yyvsp[0].typeInfo).startIndex;
						(yyval.typeInfo).endIndex = (yyvsp[0].typeInfo).endIndex;
						(yyval.typeInfo).baseType = (yyvsp[0].typeInfo).baseType;

						negation = false;

						if(handled_in_array == false) {
							oal.la(temp);
						}
						handled_in_array = false;
						oal.push_back(Instruction("deref"));
						if(negative == true) {
							oal.push_back(Instruction("neg"));
						}
					}
#line 1868 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 483 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_FACTOR", "N_CONST");
						(yyval.typeInfo).type = (yyvsp[0].typeInfo).type; 
						(yyval.typeInfo).startIndex = (yyvsp[0].typeInfo).startIndex;
						(yyval.typeInfo).endIndex = (yyvsp[0].typeInfo).endIndex;
						(yyval.typeInfo).baseType = (yyvsp[0].typeInfo).baseType;

						negation = false;
					}
#line 1882 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 493 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_FACTOR", 
						  "T_LPAREN N_EXPR T_RPAREN");
						(yyval.typeInfo).type = (yyvsp[-1].typeInfo).type; 
						(yyval.typeInfo).startIndex = (yyvsp[-1].typeInfo).startIndex;
						(yyval.typeInfo).endIndex = (yyvsp[-1].typeInfo).endIndex;
						(yyval.typeInfo).baseType = (yyvsp[-1].typeInfo).baseType;

						negation = false;
					}
#line 1897 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 504 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_FACTOR", "T_NOT N_FACTOR");

						if((yyvsp[0].typeInfo).type != BOOL) {
							yyerror("Expression must be of type boolean");
						}

						(yyval.typeInfo).type = BOOL; 
						(yyval.typeInfo).startIndex = NOT_APPLICABLE;
						(yyval.typeInfo).endIndex = NOT_APPLICABLE;
						(yyval.typeInfo).baseType = NOT_APPLICABLE;

						oal.push_back(Instruction("not"));
					}
#line 1916 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 520 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_IDENT", "T_IDENT");
					(yyval.text) = (yyvsp[0].text);
					}
#line 1925 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 526 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_IDENTLST", "epsilon");
					}
#line 1933 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 530 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_IDENTLST", 
						   "T_COMMA N_IDENT N_IDENTLST");
						string varName = string((yyvsp[-1].text));
						variableNames.push_front(varName);
					}
#line 1944 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 538 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_IDX", "N_INTCONST");
					(yyval.num) = (yyvsp[0].num);
					}
#line 1953 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 544 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_IDXRANGE", "N_IDX T_DOTDOT N_IDX");
						if((yyvsp[-2].num) > (yyvsp[0].num)) {
							yyerror("Start index must be less than or equal to end index of array");
						}

						(yyval.typeInfo).type = INDEX_RANGE; 
						(yyval.typeInfo).startIndex = (yyvsp[-2].num);
						(yyval.typeInfo).endIndex = (yyvsp[0].num);
						(yyval.typeInfo).baseType = NOT_APPLICABLE;
					}
#line 1969 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 557 "mipl.y" /* yacc.c:1646  */
    {
						array_var_stack.push(temp);
						oal.la(temp);
					}
#line 1978 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 562 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_IDXVAR", 
						  "N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK");

						// N_expr cannot be a proceduce
						if((yyvsp[-1].typeInfo).type == PROCEDURE || (yyvsp[-4].typeInfo).type == PROCEDURE) {
							yyerror("Procedure/variable mismatch");
						}

						if((yyvsp[-1].typeInfo).type != INT) {
							// Allow nested arrays
							if(!((yyvsp[-1].typeInfo).type == ARRAY && (yyvsp[-1].typeInfo).entireVar == false && (yyvsp[-1].typeInfo).baseType == INT)) {
								yyerror("Index expression must be of type integer");
							}
						}

						if((yyvsp[-4].typeInfo).type != ARRAY) {
							yyerror("Indexed variable must be of array type");
						}

						oal.push_back(Instruction("add"));
						handled_in_array = true;
					}
#line 2006 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 587 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_INPUTLST", "epsilon");
					}
#line 2014 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 591 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_INPUTLST", 
						   "T_COMMA N_INPUTVAR N_INPUTLST");
					}
#line 2023 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 597 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_INPUTVAR", "N_VARIABLE");

						if((yyvsp[0].typeInfo).type != INT && (yyvsp[0].typeInfo).type != CHAR) {
							// Handle not int or char arrays
							if(!((yyvsp[0].typeInfo).entireVar == false && (yyvsp[0].typeInfo).type == ARRAY && (((yyvsp[0].typeInfo).baseType == INT || (yyvsp[0].typeInfo).baseType == CHAR)))) {
								yyerror("Input variable must be of type integer or char");
							}
							if((yyvsp[0].typeInfo).type != ARRAY) {
								yyerror("Input variable must be of type integer or char");
							}
						}
						(yyval.typeInfo).type = (yyvsp[0].typeInfo).type; 
						(yyval.typeInfo).startIndex = (yyvsp[0].typeInfo).startIndex;
						(yyval.typeInfo).endIndex = (yyvsp[0].typeInfo).endIndex;
						(yyval.typeInfo).baseType = (yyvsp[0].typeInfo).baseType;
						(yyval.typeInfo).entireVar = (yyvsp[0].typeInfo).entireVar;

						// Read input
						oal.la(temp);
						if((yyvsp[0].typeInfo).type == INT) {
							oal.push_back(Instruction("iread"));
						} else {
							oal.push_back(Instruction("cread"));
						}
						oal.push_back(Instruction("st"));
					}
#line 2055 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 626 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_INTCONST", "N_SIGN T_INTCONST");
				(yyval.num) = (yyvsp[-1].num) * (yyvsp[0].num);
					}
#line 2064 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 647 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_MULTOPLST", "epsilon");
					}
#line 2072 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 650 "mipl.y" /* yacc.c:1646  */
    {
					/*
					if(comparator == "and")  {
						oal.push_back(Instruction("and"));
					}
					*/
				}
#line 2084 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 657 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_MULTOPLST", "N_MULTOP N_FACTOR N_MULTOPLST");

						if((yyvsp[-3].intValue) == ARITHMETIC_OP) {
							if((yyvsp[-2].typeInfo).type != INT) {
								yyerror("Expression must be of type integer");
							}
						}
						
					}
#line 2099 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 669 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_OUTPUT", "N_EXPR");
						
						if((yyvsp[0].typeInfo).type != INT && (yyvsp[0].typeInfo).type != CHAR) {
							// Handle not int or char arrays
							if(!((yyvsp[0].typeInfo).entireVar == false && (yyvsp[0].typeInfo).type == ARRAY && (((yyvsp[0].typeInfo).baseType == INT || (yyvsp[0].typeInfo).baseType == CHAR)))) {
								yyerror("Output expression must be of type integer or char");
							}
							if((yyvsp[0].typeInfo).type != ARRAY) {
								yyerror("Output expression must be of type integer or char");
							}
						}

						// Write
						if((yyvsp[0].typeInfo).type == INT || ((yyvsp[0].typeInfo).type == ARRAY && (yyvsp[0].typeInfo).baseType == INT))  {
							oal.push_back(Instruction("iwrite"));
						} else {
							oal.push_back(Instruction("cwrite"));
						}

						(yyval.typeInfo).type = (yyvsp[0].typeInfo).type; 
						(yyval.typeInfo).startIndex = (yyvsp[0].typeInfo).startIndex;
						(yyval.typeInfo).endIndex = (yyvsp[0].typeInfo).endIndex;
						(yyval.typeInfo).baseType = (yyvsp[0].typeInfo).baseType;
					}
#line 2129 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 696 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_OUTPUTLST", "epsilon");
					}
#line 2137 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 700 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_OUTPUTLST", "T_COMMA N_OUTPUT N_OUTPUTLST");
					}
#line 2145 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 705 "mipl.y" /* yacc.c:1646  */
    {
						prRule("N_PROCDEC", "N_PROCHDR N_BLOCK");
						oal.end_proc();
						nesting_level--;
					}
#line 2155 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 712 "mipl.y" /* yacc.c:1646  */
    {
						prRule("N_PROCHDR", "T_PROC T_IDENT T_SCOLON");
						string lexeme = string((yyvsp[-1].text));
						TYPE_INFO info = {PROCEDURE, NOT_APPLICABLE, NOT_APPLICABLE, NOT_APPLICABLE};
						prSymbolTableAddition(lexeme, info);
						bool success = scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(lexeme,info));
						if(! success) {
							yyerror("Multiply defined identifier");
						return(0);
						}

						beginScope();
						nesting_level++;

						// Put us in proc
						oal.begin_proc(string((yyvsp[-1].text)));
						proc_stack.push(string((yyvsp[-1].text)));
					}
#line 2178 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 732 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_PROCDECPART", "epsilon");
					}
#line 2186 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 736 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_PROCDECPART",
						   "N_PROCDEC T_SCOLON N_PROCDECPART");
					}
#line 2195 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 742 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_PROCIDENT", "T_IDENT");
						string ident = string((yyvsp[0].text));
						TYPE_INFO typeInfo = 
						findEntryInAnyScope(ident);
						if (typeInfo.type == UNDEFINED) {
						  yyerror("Undefined identifier");
						  return(0);
						}
						(yyval.typeInfo).type = typeInfo.type;
						(yyval.typeInfo).startIndex = typeInfo.startIndex;
						(yyval.typeInfo).endIndex = typeInfo.endIndex;
						(yyval.typeInfo).baseType = typeInfo.baseType;

						// Jump to proc
						oal.js(ident);
					}
#line 2217 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 761 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_PROCSTMT", "N_PROCIDENT");
				(yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
				(yyval.typeInfo).startIndex = (yyvsp[0].typeInfo).startIndex;
				(yyval.typeInfo).endIndex = (yyvsp[0].typeInfo).endIndex;
				(yyval.typeInfo).baseType = (yyvsp[0].typeInfo).baseType;
					}
#line 2229 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 770 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_PROG",
					 "N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT");
				string lexeme = string((yyvsp[-1].text));
				TYPE_INFO info = {PROGRAM, NOT_APPLICABLE,
						   NOT_APPLICABLE, NOT_APPLICABLE};
				prSymbolTableAddition(lexeme, info);
					bool success = scopeStack.top().addEntry
							   (SYMBOL_TABLE_ENTRY(lexeme,info));
				}
#line 2244 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 781 "mipl.y" /* yacc.c:1646  */
    { }
#line 2250 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 784 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_PROGLBL", "T_PROG");
				beginScope();
					}
#line 2259 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 790 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_READ",
						"T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN");
			   }
#line 2268 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 796 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_RELOP", "T_LT");
						comparator_stack.push(".lt.");
					}
#line 2277 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 801 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_RELOP", "T_GT");
						comparator_stack.push(".gt.");
					}
#line 2286 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 806 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_RELOP", "T_LE");
						comparator_stack.push(".le.");
					}
#line 2295 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 811 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_RELOP", "T_GE");
						comparator_stack.push(".ge.");
					}
#line 2304 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 816 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_RELOP", "T_EQ");
						comparator_stack.push(".eq.");
					}
#line 2313 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 821 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_RELOP", "T_NE");
						comparator_stack.push(".ne.");
					}
#line 2322 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 827 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_SIGN", "epsilon");
				(yyval.num) = POSITIVE;
						negative = false;
					}
#line 2332 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 833 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_SIGN", "T_PLUS");
						(yyval.num) = POSITIVE;
						negative = false;
					}
#line 2342 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 839 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_SIGN", "T_MINUS");
						(yyval.num) = NEGATIVE;
						negative = true;
					}
#line 2352 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 846 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_SIMPLE", "T_INT");
				(yyval.typeInfo).type = INT; 
					(yyval.typeInfo).startIndex = NOT_APPLICABLE;
					(yyval.typeInfo).endIndex = NOT_APPLICABLE;
				 (yyval.typeInfo).baseType = NOT_APPLICABLE;
					}
#line 2364 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 854 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_SIMPLE", "T_CHAR");
				(yyval.typeInfo).type = CHAR; 
					(yyval.typeInfo).startIndex = NOT_APPLICABLE;
					(yyval.typeInfo).endIndex = NOT_APPLICABLE;
				 (yyval.typeInfo).baseType = NOT_APPLICABLE;
					}
#line 2376 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 862 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_SIMPLE", "T_BOOL");
				(yyval.typeInfo).type = BOOL; 
					(yyval.typeInfo).startIndex = NOT_APPLICABLE;
					(yyval.typeInfo).endIndex = NOT_APPLICABLE;
				 (yyval.typeInfo).baseType = NOT_APPLICABLE;
					}
#line 2388 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 871 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_SIMPLEEXPR", 
						   "N_TERM N_ADDOPLST");
						(yyval.typeInfo).type = (yyvsp[-1].typeInfo).type; 
						(yyval.typeInfo).startIndex = (yyvsp[-1].typeInfo).startIndex;
						(yyval.typeInfo).endIndex = (yyvsp[-1].typeInfo).endIndex;
						(yyval.typeInfo).baseType = (yyvsp[-1].typeInfo).baseType;
					}
#line 2401 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 881 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_STMT", "N_ASSIGN");
					}
#line 2409 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 885 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_STMT", "N_PROCSTMT");
					}
#line 2417 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 889 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_STMT", "N_READ");
					}
#line 2425 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 893 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_STMT", "N_WRITE");
					}
#line 2433 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 897 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_STMT", "N_CONDITION");
					}
#line 2441 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 901 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_STMT", "N_WHILE");
					}
#line 2449 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 905 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_STMT", "N_COMPOUND");
					}
#line 2457 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 910 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_STMTLST", "epsilon");
					}
#line 2465 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 914 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_STMTLST", 
						   "T_SCOLON N_STMT N_STMTLST");
					}
#line 2474 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 920 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_STMTPART", "N_COMPOUND");
					}
#line 2482 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 925 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_TERM", "N_FACTOR N_MULTOPLST");
						(yyval.typeInfo).type = (yyvsp[-1].typeInfo).type; 
						(yyval.typeInfo).startIndex = (yyvsp[-1].typeInfo).startIndex;
						(yyval.typeInfo).endIndex = (yyvsp[-1].typeInfo).endIndex;
						(yyval.typeInfo).baseType = (yyvsp[-1].typeInfo).baseType;
					}
#line 2494 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 934 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_TYPE", "N_SIMPLE");
						(yyval.typeInfo).type = (yyvsp[0].typeInfo).type; 
						(yyval.typeInfo).startIndex = (yyvsp[0].typeInfo).startIndex;
						(yyval.typeInfo).endIndex = (yyvsp[0].typeInfo).endIndex;
						(yyval.typeInfo).baseType = (yyvsp[0].typeInfo).baseType;
					}
#line 2506 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 942 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_TYPE", "N_ARRAY");
						(yyval.typeInfo).type = (yyvsp[0].typeInfo).type; 
						(yyval.typeInfo).startIndex = (yyvsp[0].typeInfo).startIndex;
						(yyval.typeInfo).endIndex = (yyvsp[0].typeInfo).endIndex;
						(yyval.typeInfo).baseType = (yyvsp[0].typeInfo).baseType;
					}
#line 2518 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 951 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_VARDEC", 
						   "N_IDENT N_IDENTLST T_COLON N_TYPE");
						string varName = string((yyvsp[-3].text));
						variableNames.push_front(varName);
				
						for (std::list<string>::iterator
								  it=variableNames.begin();
							  it != variableNames.end(); it++) {
							string varName = string(*it);
							prSymbolTableAddition(varName, (yyvsp[0].typeInfo));
							bool success = scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(varName, (yyvsp[0].typeInfo)));
							if (! success) {
								yyerror("Multiply defined identifier");
								return(0);
							}
						}

						// Add each variable to oal
						for(auto varN : variableNames) {
							if(oal.var_exists(varN) == false) {
								TYPE_INFO info = findEntryInAnyScope(varN);
								if(info.type != ARRAY) {
									oal.add_addr(varN);
								} else {
									oal.add_addr(varN, info.startIndex, info.endIndex);
								}
							}
						}
						
						variableNames.clear();
					}
#line 2555 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 985 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_VARDECLST", "epsilon");
					}
#line 2563 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 989 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_VARDECLST", 
						   "N_VARDEC T_SCOLON N_VARDECLST");
					}
#line 2572 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 995 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_VARDECPART", "epsilon");
					}
#line 2580 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 999 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_VARDECPART",
						"T_VAR N_VARDEC T_SCOLON N_VARDECLST");
					}
#line 2589 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1005 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_VARIABLE", "N_ENTIREVAR");
						(yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
						(yyval.typeInfo).startIndex = (yyvsp[0].typeInfo).startIndex;
						(yyval.typeInfo).endIndex = (yyvsp[0].typeInfo).endIndex;
						(yyval.typeInfo).baseType = (yyvsp[0].typeInfo).baseType;
						(yyval.typeInfo).entireVar = true;
					}
#line 2602 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1014 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_VARIABLE", "N_IDXVAR");
						(yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
						(yyval.typeInfo).startIndex = (yyvsp[0].typeInfo).startIndex;
						(yyval.typeInfo).endIndex = (yyvsp[0].typeInfo).endIndex;
						(yyval.typeInfo).baseType = (yyvsp[0].typeInfo).baseType;
						(yyval.typeInfo).entireVar = false;
					}
#line 2615 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1024 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_VARIDENT", "T_IDENT");
				string ident = string((yyvsp[0].text));
						TYPE_INFO typeInfo = 
						findEntryInAnyScope(ident);
						if (typeInfo.type == UNDEFINED) {
						  yyerror("Undefined identifier");
						  return(0);
					}
					(yyval.typeInfo).type = typeInfo.type;
					(yyval.typeInfo).startIndex = typeInfo.startIndex;
					(yyval.typeInfo).endIndex = typeInfo.endIndex;
					(yyval.typeInfo).baseType = typeInfo.baseType;

					// Keep track of var and type
					temp = ident;
					is_var = true;
				}
#line 2638 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1044 "mipl.y" /* yacc.c:1646  */
    {
						// Label, jp
						while_deque.push_back(oal.new_label());
						// jf, label
						while_deque.push_back(oal.new_label());

						// First label
						oal.push_back(Instruction(while_deque[while_deque.size() - 2]));
					}
#line 2652 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1053 "mipl.y" /* yacc.c:1646  */
    {
						if((yyvsp[0].typeInfo).type != BOOL) {
							yyerror("Expression must be of type boolean");
						}
						
						oal.push_back(Instruction("jf", while_deque.back()));
					}
#line 2664 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1061 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_WHILE", 
						   "T_WHILE N_EXPR T_DO N_STMT");

						oal.push_back(Instruction("jp", while_deque[while_deque.size() - 2]));
						oal.push_back(Instruction(while_deque.back()));
						while_deque.pop_back();
						while_deque.pop_back();
					}
#line 2678 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1072 "mipl.y" /* yacc.c:1646  */
    {
					prRule("N_WRITE",
					  "T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN");

					}
#line 2688 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1079 "mipl.y" /* yacc.c:1646  */
    {
						prRule("N_ADD_OP", "N_ADD_OP_LOGICAL");
						(yyval.intValue) = LOGICAL_OP;
					}
#line 2697 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1084 "mipl.y" /* yacc.c:1646  */
    {
						prRule("N_ADD_OP", "N_ADD_OP_ARITHMETIC");
						(yyval.intValue) = ARITHMETIC_OP;
					}
#line 2706 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1090 "mipl.y" /* yacc.c:1646  */
    {
						prRule("N_ADD_OP_LOGICAL", "T_OR");
						comparator_stack.push("or");
					}
#line 2715 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1096 "mipl.y" /* yacc.c:1646  */
    {
						prRule("N_ADD_OP_ARITHMETIC", "T_PLUS");
						comparator_stack.push("add");
					}
#line 2724 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1101 "mipl.y" /* yacc.c:1646  */
    {
						prRule("N_ADD_OP_ARITHMETIC", "T_MINUS");
						comparator_stack.push("sub");
					}
#line 2733 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1107 "mipl.y" /* yacc.c:1646  */
    {
						prRule("N_MULT_OP", "N_MULT_OP_LOGICAL");
						(yyval.intValue) = LOGICAL_OP;
					}
#line 2742 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1112 "mipl.y" /* yacc.c:1646  */
    {
						prRule("N_MULT_OP", "N_MULT_OP_ARITHMETIC");
						(yyval.intValue) = ARITHMETIC_OP;
					}
#line 2751 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1118 "mipl.y" /* yacc.c:1646  */
    {
						prRule("N_MULT_OP_LOGICAL", "T_AND");
						comparator_stack.push("and");
					}
#line 2760 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1124 "mipl.y" /* yacc.c:1646  */
    {
						prRule("N_MULT_OP_ARITHMETIC", "T_MULT");
						comparator_stack.push("mult");
					}
#line 2769 "mipl.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1129 "mipl.y" /* yacc.c:1646  */
    {
						prRule("N_MULT_OP_ARITHMETIC", "T_DIV");
						comparator_stack.push("div");
					}
#line 2778 "mipl.tab.c" /* yacc.c:1646  */
    break;


#line 2782 "mipl.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  return yyresult;
}
#line 1135 "mipl.y" /* yacc.c:1906  */


#include    "lex.yy.c"
extern FILE *yyin;

void prRule(const char *lhs, const char *rhs) 
{
  if (OUTPUT_PRODUCTIONS)
	printf("%s -> %s\n", lhs, rhs);
  return;
}

int yyerror(const char *s) 
{
  printf("Line %d: %s\n", lineNum, s);
  cleanUp();
  exit(1);
}

int ckInt() 
{
  char *ptr;
  int	rc = 0;
  ptr = yytext;

  /* ignore sign and leading zeroes */
  if (*ptr == '-' || *ptr == '+')
	++ptr;
  while (*ptr == '0')
	++ptr;

  switch (*ptr) 
  {
  case '1':	/* ALL are valid */
			break;

  case '2':	/* it depends */
			if (strcmp(MAX_INT, ptr) < 0)
			  rc = 1;
			break;

  default:	     /* ALL are invalid */
			rc = 1;
			break;
  }
  return rc;
}

void ignoreComment() 
{
  char c, pc = 0;

  /* read and ignore input until you get an ending token */
  while (((c = yyinput()) != ')' || pc != '*') && c != 0) {
	pc = c;
	if (c == '\n') lineNum++;
  }

  return;
}

void printTokenInfo(const char* tokenType, 
					const char* lexeme) 
{
  if (OUTPUT_TOKENS)
	printf("TOKEN: %-15s  LEXEME: %s\n", tokenType, lexeme);
}

void beginScope() 
{
  scopeStack.push(SYMBOL_TABLE());
  if (OUTPUT_ST_MGT) 
	printf("\n___Entering new scope...\n\n");
}

void endScope() 
{
  scopeStack.pop();
  if (OUTPUT_ST_MGT) 
	printf("\n___Exiting scope...\n\n");
}

void prSymbolTableAddition(const string identName, 
						   const TYPE_INFO typeInfo) 
{
  if (OUTPUT_ST_MGT) 
  {
   char *cstr = new char[identName.length() + 1];
   strcpy(cstr, identName.c_str());
   printf("___Adding %s to symbol table with type ", cstr);
   delete [] cstr;
   switch (typeInfo.type) {
	case PROGRAM	: printf("PROGRAM\n"); break;
	case PROCEDURE	: printf("PROCEDURE\n"); break;
	case INT		: printf("INTEGER\n"); break;
	case CHAR		: printf("CHAR\n"); break;
	case BOOL		: printf("BOOLEAN\n"); break;
	case ARRAY		: printf("ARRAY ");
				  printf("%d .. %d OF ",
						 typeInfo.startIndex, 
						 typeInfo.endIndex);
				  switch (typeInfo.baseType) {
					case INT : printf("INTEGER\n"); 
									 break;
					case CHAR: printf("CHAR\n"); 
									 break;
					case BOOL: printf("BOOLEAN\n"); 
									 break;
					default  : printf("UNKNOWN\n"); 
									 break;
				  }
				  break;
	default 		: printf("UNKNOWN\n"); break;
   }
  }
}

TYPE_INFO findEntryInAnyScope(const string theName) 
{
  TYPE_INFO info = {UNDEFINED, NOT_APPLICABLE, NOT_APPLICABLE,
					NOT_APPLICABLE};
  if (scopeStack.empty( )) return(info);
  info = scopeStack.top().findEntry(theName);
  if (info.type != UNDEFINED)
	return(info);
  else { // check in "next higher" scope
	   SYMBOL_TABLE symbolTable = scopeStack.top( );
	   scopeStack.pop( );
	   info = findEntryInAnyScope(theName);
	   scopeStack.push(symbolTable); // restore the stack
	   return(info);
  }
}

void cleanUp() 
{
  if (scopeStack.empty()) 
	return;
  else {
		scopeStack.pop();
		cleanUp();
  }
}


int main(int argc, char** argv)
{
	if (argc < 2) {
		printf("You must specify a file in the command line!\n");
		exit(1);
	}
	yyin = fopen(argv[1], "r");
	do {
		yyparse();
	} while (!feof(yyin));

	oal.make_header();

	oal.print();

	return 0;
}


