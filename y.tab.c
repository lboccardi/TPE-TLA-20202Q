/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar.y"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#ifdef E_PARSE_DEBUG
// Some yacc (bison) defines
#define YYDEBUG 1       // Generate debug code; needed for YYERROR_VERBOSE
#define YYERROR_VERBOSE // Give a more specific parse error message 
#define YYACCEPT 0
#endif

int yylex();

int yydebug=1;

void yyerror(const char *str)
{
  fprintf(stderr,"error: %s\n",str);
  freeResources(true); 
} 

#line 95 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    DIGIT = 258,
    ALPHA = 259,
    SPACE_ALPHA = 260,
    STRING_VALUE = 261,
    INT = 262,
    STRING = 263,
    PLUS = 264,
    MINUS = 265,
    TIMES = 266,
    DIV = 267,
    END = 268,
    OPEN_P = 269,
    CLOSE_P = 270,
    CONDITIONAL = 271,
    EXEC = 272,
    END_EXEC = 273,
    IF = 274,
    ELSE = 275,
    ESCAPE = 276,
    WHILE = 277,
    L = 278,
    G = 279,
    LE = 280,
    GE = 281,
    EQ = 282,
    NE = 283,
    NOT = 284,
    OR = 285,
    AND = 286,
    ASSIGN = 287,
    RETURN = 288,
    MAIN = 289,
    STDIN = 290,
    STDOUT = 291,
    FUNCTION = 292,
    COMMA = 293,
    ARRAY = 294
  };
#endif
/* Tokens.  */
#define DIGIT 258
#define ALPHA 259
#define SPACE_ALPHA 260
#define STRING_VALUE 261
#define INT 262
#define STRING 263
#define PLUS 264
#define MINUS 265
#define TIMES 266
#define DIV 267
#define END 268
#define OPEN_P 269
#define CLOSE_P 270
#define CONDITIONAL 271
#define EXEC 272
#define END_EXEC 273
#define IF 274
#define ELSE 275
#define ESCAPE 276
#define WHILE 277
#define L 278
#define G 279
#define LE 280
#define GE 281
#define EQ 282
#define NE 283
#define NOT 284
#define OR 285
#define AND 286
#define ASSIGN 287
#define RETURN 288
#define MAIN 289
#define STDIN 290
#define STDOUT 291
#define FUNCTION 292
#define COMMA 293
#define ARRAY 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "grammar.y"

	char * stringValue;

#line 220 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

#define YYUNDEFTOK  2
#define YYMAXUTOK   294

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    74,    74,    75,    79,    83,    84,    88,    89,    90,
      94,    95,    96,    97,   101,   105,   106,   107,   108,   109,
     110,   111,   115,   116,   117,   118,   119,   124,   125,   126,
     127,   129,   130,   131,   132,   134,   135,   136,   138,   139,
     141,   142,   147,   148,   152,   153,   154,   158,   159,   162,
     163,   167,   168,   172,   173,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   190,   191,   192,   193
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "ALPHA", "SPACE_ALPHA",
  "STRING_VALUE", "INT", "STRING", "PLUS", "MINUS", "TIMES", "DIV", "END",
  "OPEN_P", "CLOSE_P", "CONDITIONAL", "EXEC", "END_EXEC", "IF", "ELSE",
  "ESCAPE", "WHILE", "L", "G", "LE", "GE", "EQ", "NE", "NOT", "OR", "AND",
  "ASSIGN", "RETURN", "MAIN", "STDIN", "STDOUT", "FUNCTION", "COMMA",
  "ARRAY", "$accept", "start", "function", "type", "params", "args",
  "call", "program", "out", "var", "operation", "assignment",
  "alpha_array", "digit_array", "rule", "arrow", "operator", "op", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -70

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-70)))

#define YYTABLE_NINF -37

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,   -70,   -70,     4,    28,     7,    -5,    12,   -70,   -70,
      42,    -3,    51,    55,    21,    50,    47,    13,    65,    60,
      57,    66,    69,    54,    59,    81,    -9,    -1,   -70,   -70,
     -70,    21,   -70,    77,    72,    86,    13,    13,    63,    78,
      61,    12,   -70,    12,    74,    80,    83,   -70,    71,    79,
      82,   -70,    40,    64,   107,   108,   106,   110,    77,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,    21,   -70,   -70,    99,   -70,   -70,    94,    95,
      12,   114,   -70,   -70,   115,   105,   -70,    54,   -70,   118,
      36,    40,    90,   -70,    91,    21,   109,   112,    13,    13,
     -70,    80,   -70,    88,   111,   -70,    40,   -70,   -70,   -70,
     124,   123,   116,   117,    12,   -70,   -70,    74,    12,   -70,
      92,   -70,    96,   -70,   -70,    58,   -70,   -70,   119,   124,
     123,   -70,   -70,   121,   -70,   -70,   -70,    12,   122,    12,
     -70
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     6,     0,     0,     0,     0,    21,     1,     3,
       0,     0,     0,     0,     0,     0,     0,    24,     0,     0,
       0,     0,     0,    13,     0,     0,    31,    32,    45,    44,
      46,     0,    52,     0,     0,     0,    24,    24,     0,     0,
       0,    21,     2,    21,     9,    44,     0,    12,    10,    45,
      46,    39,    43,     0,     0,     0,     0,     0,     0,    65,
      66,    68,    67,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,    55,    18,     0,    25,    22,     0,     0,
      21,     0,    16,    15,     0,     0,    14,    13,    37,     0,
       0,    43,    33,    28,    34,     0,     0,     0,    24,    24,
      20,     0,    38,     7,     0,    11,    43,    40,    41,    27,
       0,     0,     0,     0,    21,    26,    23,     9,    21,    42,
      50,    29,    48,    30,    51,     0,    19,     8,     0,     0,
       0,    54,    53,     0,     4,    49,    47,    21,     0,    21,
      17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   127,   -70,     0,    18,    49,   -17,   -40,   -27,   -70,
     -69,   -11,     9,    14,   -29,   -70,    84,   -25
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    18,    85,    46,    19,    20,    39,    21,
      88,    32,   123,   121,    33,   133,    72,    89
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,    82,    58,    83,    34,     6,    47,    51,    73,    76,
      77,    23,    48,    52,     1,     2,    11,    36,    37,    12,
      13,     7,   109,    54,    28,    29,    14,    30,     8,    24,
      55,    56,    10,    73,    38,    31,    25,   119,    57,   107,
     100,     3,   108,    96,    84,    15,    22,    16,    17,    59,
      60,    61,    62,    28,    29,    26,    30,    28,    45,    27,
      30,    35,    49,    45,   102,    50,   112,    78,    79,    40,
      47,   115,   116,    41,   126,    42,    48,   131,   128,    43,
     132,     1,     2,    44,    53,    74,    59,    60,    61,    62,
      75,    80,   -35,    81,    23,   -36,    90,   138,    86,   140,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    87,
      91,    92,    93,    94,    97,    98,    99,    84,   101,   103,
     104,   106,   110,   111,   113,   114,   117,   120,   118,   122,
     129,   124,     9,   125,   130,   127,   105,   134,   137,   136,
     139,     0,    95,   135
};

static const yytype_int16 yycheck[] =
{
       0,    41,    31,    43,    15,     5,    23,    24,    33,    36,
      37,    14,    23,    24,     7,     8,     4,     4,     5,     7,
       8,    17,    91,    32,     3,     4,    14,     6,     0,    32,
      39,    32,    37,    58,    21,    14,    39,   106,    39,     3,
      80,    34,     6,    72,    44,    33,     4,    35,    36,     9,
      10,    11,    12,     3,     4,     4,     6,     3,     4,     4,
       6,    14,     3,     4,    81,     6,    95,     4,     5,     4,
      87,    98,    99,    13,   114,    18,    87,    19,   118,    13,
      22,     7,     8,    14,     3,    13,     9,    10,    11,    12,
       4,    13,    13,    32,    14,    13,    32,   137,    15,   139,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    38,
       3,     3,     6,     3,    15,    21,    21,   117,     4,     4,
      15,     3,    32,    32,    15,    13,    38,     3,    17,     6,
      38,    15,     5,    16,    38,   117,    87,    18,    17,   130,
      18,    -1,    58,   129
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    34,    41,    42,    43,    17,     0,    41,
      37,     4,     7,     8,    14,    33,    35,    36,    43,    46,
      47,    49,     4,    14,    32,    39,     4,     4,     3,     4,
       6,    14,    51,    54,    51,    14,     4,     5,    21,    48,
       4,    13,    18,    13,    14,     4,    45,    46,    51,     3,
       6,    46,    51,     3,    32,    39,    32,    39,    54,     9,
      10,    11,    12,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    56,    57,    13,     4,    48,    48,     4,     5,
      13,    32,    47,    47,    43,    44,    15,    38,    50,    57,
      32,     3,     3,     6,     3,    56,    54,    15,    21,    21,
      47,     4,    46,     4,    15,    45,     3,     3,     6,    50,
      32,    32,    54,    15,    13,    48,    48,    38,    17,    50,
       3,    53,     6,    52,    15,    16,    47,    44,    47,    38,
      38,    19,    22,    55,    18,    53,    52,    17,    47,    18,
      47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    42,    43,    43,    44,    44,    44,
      45,    45,    45,    45,    46,    47,    47,    47,    47,    47,
      47,    47,    48,    48,    48,    48,    48,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    50,    50,    51,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    57,    57,    57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     9,     1,     1,     2,     4,     0,
       1,     3,     1,     0,     4,     3,     3,    11,     3,     6,
       4,     0,     2,     4,     0,     2,     4,     5,     4,     6,
       6,     2,     2,     4,     4,     3,     3,     4,     4,     3,
       5,     5,     3,     0,     1,     1,     1,     3,     1,     3,
       1,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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
  case 2:
#line 74 "grammar.y"
    { (yyval.stringValue) = malloc(16 +  strlen((yyvsp[-1].stringValue))); sprintf((yyval.stringValue), "int main(){ %s }\n",(yyvsp[-1].stringValue)); add((yyval.stringValue), true);  }
#line 1404 "y.tab.c"
    break;

  case 3:
#line 75 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))+3); sprintf((yyval.stringValue),"%s\n%s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1410 "y.tab.c"
    break;

  case 4:
#line 79 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-8].stringValue))+strlen((yyvsp[-6].stringValue))+strlen((yyvsp[-4].stringValue))+strlen((yyvsp[-1].stringValue))+ 8); sprintf((yyval.stringValue), "%s %s(%s){\n%s}\n", (yyvsp[-8].stringValue), (yyvsp[-6].stringValue), (yyvsp[-4].stringValue), (yyvsp[-1].stringValue)); add((yyval.stringValue),true);}
#line 1416 "y.tab.c"
    break;

  case 5:
#line 83 "grammar.y"
    {(yyval.stringValue) = "int";}
#line 1422 "y.tab.c"
    break;

  case 6:
#line 84 "grammar.y"
    {(yyval.stringValue) = "char *";}
#line 1428 "y.tab.c"
    break;

  case 7:
#line 88 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue)) +2); sprintf((yyval.stringValue), "%s %s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1434 "y.tab.c"
    break;

  case 8:
#line 89 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+strlen((yyvsp[-2].stringValue))+4+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s %s, %s", (yyvsp[-3].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1440 "y.tab.c"
    break;

  case 9:
#line 90 "grammar.y"
    { (yyval.stringValue) = ""; }
#line 1446 "y.tab.c"
    break;

  case 10:
#line 94 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+1); sprintf((yyval.stringValue), "%s", (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1452 "y.tab.c"
    break;

  case 11:
#line 95 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+2+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s,%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1458 "y.tab.c"
    break;

  case 12:
#line 96 "grammar.y"
    { (yyval.stringValue) = (yyvsp[0].stringValue);}
#line 1464 "y.tab.c"
    break;

  case 13:
#line 97 "grammar.y"
    { (yyval.stringValue) = "";}
#line 1470 "y.tab.c"
    break;

  case 14:
#line 101 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+3+strlen((yyvsp[-1].stringValue))); sprintf((yyval.stringValue),"%s(%s)",(yyvsp[-3].stringValue),(yyvsp[-1].stringValue)); add((yyval.stringValue),true);}
#line 1476 "y.tab.c"
    break;

  case 15:
#line 105 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+3+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s; %s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1482 "y.tab.c"
    break;

  case 16:
#line 106 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+3+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s; %s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1488 "y.tab.c"
    break;

  case 17:
#line 107 "grammar.y"
    {(yyval.stringValue) = malloc(strlen((yyvsp[-9].stringValue))+10+strlen((yyvsp[-8].stringValue))+strlen((yyvsp[-7].stringValue))+strlen((yyvsp[-4].stringValue))+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s(%s %s %s){%s}\n%s ",(yyvsp[-4].stringValue),(yyvsp[-9].stringValue),(yyvsp[-8].stringValue),(yyvsp[-7].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1494 "y.tab.c"
    break;

  case 18:
#line 108 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue)) +9); sprintf((yyval.stringValue), "return %s;", (yyvsp[-1].stringValue)); add((yyval.stringValue),true);}
#line 1500 "y.tab.c"
    break;

  case 19:
#line 109 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+strlen((yyvsp[0].stringValue))+ 11); sprintf((yyval.stringValue),"gets(%s);\n%s",(yyvsp[0].stringValue),(yyvsp[-3].stringValue)); add((yyval.stringValue),true);}
#line 1506 "y.tab.c"
    break;

  case 20:
#line 110 "grammar.y"
    { char * print = printfParser((yyvsp[-2].stringValue)); if(print==NULL){yyerror("Sintax error on P.\n Check if your variables exist."); YYABORT;} (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))*2+5+strlen((yyvsp[0].stringValue))+ 11); sprintf((yyval.stringValue), "printf(%s);\n%s", print, (yyvsp[0].stringValue)); add((yyval.stringValue),true); free(print);}
#line 1512 "y.tab.c"
    break;

  case 21:
#line 111 "grammar.y"
    { (yyval.stringValue)="";}
#line 1518 "y.tab.c"
    break;

  case 22:
#line 115 "grammar.y"
    { (yyval.stringValue) = malloc(1 + strlen((yyvsp[-1].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s%s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1524 "y.tab.c"
    break;

  case 23:
#line 116 "grammar.y"
    { (yyval.stringValue) = malloc(3 + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "\'%s\'%s", (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1530 "y.tab.c"
    break;

  case 24:
#line 117 "grammar.y"
    { (yyval.stringValue) = ""; }
#line 1536 "y.tab.c"
    break;

  case 25:
#line 118 "grammar.y"
    { (yyval.stringValue) = malloc(1 + strlen((yyvsp[-1].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s%s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1542 "y.tab.c"
    break;

  case 26:
#line 119 "grammar.y"
    { (yyval.stringValue) = malloc(3 + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "\'%s\'%s", (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1548 "y.tab.c"
    break;

  case 27:
#line 124 "grammar.y"
    { (yyval.stringValue) = malloc(strlen("int")+strlen((yyvsp[-3].stringValue))+6+strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s=%s%s","int",(yyvsp[-3].stringValue),(yyvsp[-1].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-3].stringValue), KIND_INT,1);}
#line 1554 "y.tab.c"
    break;

  case 28:
#line 125 "grammar.y"
    { (yyval.stringValue) = malloc(strlen("char *")+strlen((yyvsp[-2].stringValue))+6+strlen((yyvsp[0].stringValue))); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0;sprintf((yyval.stringValue),"%s %s=\"%s\"","char *",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)+1); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_STRING,1);}
#line 1560 "y.tab.c"
    break;

  case 29:
#line 126 "grammar.y"
    { if(array_is_incorrect((yyvsp[0].stringValue),atoi((yyvsp[-2].stringValue)))){yyerror("Bad initialization of array"); YYABORT;} (yyval.stringValue) = malloc(strlen("int")+strlen((yyvsp[-4].stringValue))+10+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]={%s}","int",(yyvsp[-4].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-4].stringValue), KIND_ARRAY_INT,atoi((yyvsp[-2].stringValue))); }
#line 1566 "y.tab.c"
    break;

  case 30:
#line 127 "grammar.y"
    { if(array_is_incorrect((yyvsp[0].stringValue),atoi((yyvsp[-2].stringValue)))){yyerror("Bad initialization of array"); YYABORT;} (yyval.stringValue) = malloc(strlen("char *")+strlen((yyvsp[-4].stringValue))+10+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]={%s}","char *",(yyvsp[-4].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-4].stringValue), KIND_ARRAY_STRING,atoi((yyvsp[-2].stringValue)));}
#line 1572 "y.tab.c"
    break;

  case 31:
#line 129 "grammar.y"
    { (yyval.stringValue) = malloc(strlen("int")+strlen((yyvsp[0].stringValue))+2); sprintf((yyval.stringValue),"%s %s","int",(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[0].stringValue), KIND_INT,1);}
#line 1578 "y.tab.c"
    break;

  case 32:
#line 130 "grammar.y"
    { (yyval.stringValue) = malloc(strlen("char *")+strlen((yyvsp[0].stringValue))+2); sprintf((yyval.stringValue),"%s %s","char *",(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[0].stringValue), KIND_STRING,1);}
#line 1584 "y.tab.c"
    break;

  case 33:
#line 131 "grammar.y"
    { (yyval.stringValue) = malloc(strlen("int")+strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]","int",(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_ARRAY_INT,atoi((yyvsp[0].stringValue))); }
#line 1590 "y.tab.c"
    break;

  case 34:
#line 132 "grammar.y"
    {  (yyval.stringValue) = malloc(strlen("char *")+strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]","char *",(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_ARRAY_STRING,atoi((yyvsp[0].stringValue)));}
#line 1596 "y.tab.c"
    break;

  case 35:
#line 134 "grammar.y"
    { if(!isOfKind((yyvsp[-2].stringValue),KIND_INT)){yyerror("Variable should be int type.");YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))+5); sprintf((yyval.stringValue), "%s=%s", (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1602 "y.tab.c"
    break;

  case 36:
#line 135 "grammar.y"
    { if(!isOfKind((yyvsp[-2].stringValue),KIND_STRING)){yyerror("Variable should be string type.");YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))+5); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0;sprintf((yyval.stringValue), "%s=\"%s\"", (yyvsp[-2].stringValue), (yyvsp[0].stringValue)+1); add((yyval.stringValue),true);}
#line 1608 "y.tab.c"
    break;

  case 37:
#line 136 "grammar.y"
    { if(!isOfKind((yyvsp[-3].stringValue),KIND_INT)){yyerror("Variable should be int type."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))+5);  sprintf((yyval.stringValue), "%s=%s%s", (yyvsp[-3].stringValue), (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1614 "y.tab.c"
    break;

  case 38:
#line 138 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+strlen((yyvsp[-2].stringValue))+3+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s=%s",(yyvsp[-3].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_INT,1);}
#line 1620 "y.tab.c"
    break;

  case 39:
#line 139 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+2+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s=%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1626 "y.tab.c"
    break;

  case 40:
#line 141 "grammar.y"
    { if (!isOfKind((yyvsp[-4].stringValue), KIND_ARRAY_INT)){yyerror("Variable should de string array type"); YYABORT;} if(! enoughSpace((yyvsp[-4].stringValue), atoi((yyvsp[-2].stringValue))) ) { yyerror("Array has not enough space"); YYABORT; } (yyval.stringValue) = malloc(strlen((yyvsp[-4].stringValue)) + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue)) + 4 ); sprintf((yyval.stringValue), "%s[%s]=%s", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue), true); }
#line 1632 "y.tab.c"
    break;

  case 41:
#line 142 "grammar.y"
    { if (!isOfKind((yyvsp[-4].stringValue), KIND_ARRAY_STRING)){yyerror("Variable should de string array type"); YYABORT;} if(! enoughSpace((yyvsp[-4].stringValue), atoi((yyvsp[-2].stringValue))) ) { yyerror("Array has not enough space"); YYABORT; } (yyval.stringValue) = malloc(strlen((yyvsp[-4].stringValue)) + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue)) + 4 ); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0; sprintf((yyval.stringValue), "%s[%s]=\"%s\"", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue)+1); add((yyval.stringValue), true); }
#line 1638 "y.tab.c"
    break;

  case 42:
#line 147 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+ 1 + strlen((yyvsp[-1].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s%s%s",(yyvsp[-2].stringValue),(yyvsp[-1].stringValue),(yyvsp[0].stringValue) ); add((yyval.stringValue),true);}
#line 1644 "y.tab.c"
    break;

  case 43:
#line 148 "grammar.y"
    { (yyval.stringValue) = "";}
#line 1650 "y.tab.c"
    break;

  case 44:
#line 152 "grammar.y"
    {(yyval.stringValue) = (yyvsp[0].stringValue);}
#line 1656 "y.tab.c"
    break;

  case 45:
#line 153 "grammar.y"
    {(yyval.stringValue) = (yyvsp[0].stringValue);}
#line 1662 "y.tab.c"
    break;

  case 46:
#line 154 "grammar.y"
    {(yyval.stringValue) = (yyvsp[0].stringValue);}
#line 1668 "y.tab.c"
    break;

  case 47:
#line 158 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); (yyvsp[-2].stringValue)[strlen((yyvsp[-2].stringValue)) - 1] = 0; sprintf((yyval.stringValue), "\"%s\",%s", (yyvsp[-2].stringValue)+1,(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1674 "y.tab.c"
    break;

  case 48:
#line 159 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+5); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0; sprintf((yyval.stringValue), "\"%s\"", (yyvsp[0].stringValue)+1); add((yyval.stringValue),true);}
#line 1680 "y.tab.c"
    break;

  case 49:
#line 162 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+2+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s,%s", (yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1686 "y.tab.c"
    break;

  case 50:
#line 163 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+1); sprintf((yyval.stringValue), "%s", (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1692 "y.tab.c"
    break;

  case 51:
#line 167 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue)) + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[-1].stringValue)) + 3); sprintf((yyval.stringValue), "(%s%s%s)", (yyvsp[-3].stringValue), (yyvsp[-2].stringValue), (yyvsp[-1].stringValue)); add((yyval.stringValue),true);}
#line 1698 "y.tab.c"
    break;

  case 52:
#line 168 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+1); sprintf((yyval.stringValue), "%s", (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1704 "y.tab.c"
    break;

  case 53:
#line 172 "grammar.y"
    { (yyval.stringValue) = "while";}
#line 1710 "y.tab.c"
    break;

  case 54:
#line 173 "grammar.y"
    { (yyval.stringValue) = "if";}
#line 1716 "y.tab.c"
    break;

  case 55:
#line 177 "grammar.y"
    { (yyval.stringValue) = (yyvsp[0].stringValue);}
#line 1722 "y.tab.c"
    break;

  case 56:
#line 178 "grammar.y"
    { (yyval.stringValue) = "<";}
#line 1728 "y.tab.c"
    break;

  case 57:
#line 179 "grammar.y"
    { (yyval.stringValue) = ">";}
#line 1734 "y.tab.c"
    break;

  case 58:
#line 180 "grammar.y"
    { (yyval.stringValue) = "<=";}
#line 1740 "y.tab.c"
    break;

  case 59:
#line 181 "grammar.y"
    { (yyval.stringValue) = ">=";}
#line 1746 "y.tab.c"
    break;

  case 60:
#line 182 "grammar.y"
    { (yyval.stringValue) = "==";}
#line 1752 "y.tab.c"
    break;

  case 61:
#line 183 "grammar.y"
    { (yyval.stringValue) = "!=";}
#line 1758 "y.tab.c"
    break;

  case 62:
#line 184 "grammar.y"
    { (yyval.stringValue) = "!";}
#line 1764 "y.tab.c"
    break;

  case 63:
#line 185 "grammar.y"
    { (yyval.stringValue) = "||";}
#line 1770 "y.tab.c"
    break;

  case 64:
#line 186 "grammar.y"
    { (yyval.stringValue) = "&&";}
#line 1776 "y.tab.c"
    break;

  case 65:
#line 190 "grammar.y"
    { (yyval.stringValue) = "+";}
#line 1782 "y.tab.c"
    break;

  case 66:
#line 191 "grammar.y"
    { (yyval.stringValue) = "-";}
#line 1788 "y.tab.c"
    break;

  case 67:
#line 192 "grammar.y"
    { (yyval.stringValue) = "/";}
#line 1794 "y.tab.c"
    break;

  case 68:
#line 193 "grammar.y"
    { (yyval.stringValue) = "*";}
#line 1800 "y.tab.c"
    break;


#line 1804 "y.tab.c"

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 196 "grammar.y"

