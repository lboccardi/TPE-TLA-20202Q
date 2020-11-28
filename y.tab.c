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
  program.error = true;
} 

#line 96 "y.tab.c"

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
    CHAR = 264,
    PLUS = 265,
    MINUS = 266,
    TIMES = 267,
    DIV = 268,
    MOD = 269,
    END = 270,
    OPEN_P = 271,
    CLOSE_P = 272,
    CONDITIONAL = 273,
    EXEC = 274,
    END_EXEC = 275,
    IF = 276,
    ELSE = 277,
    ESCAPE = 278,
    WHILE = 279,
    L = 280,
    G = 281,
    LE = 282,
    GE = 283,
    EQ = 284,
    NE = 285,
    OR = 286,
    AND = 287,
    ASSIGN = 288,
    RETURN = 289,
    MAIN = 290,
    STDIN = 291,
    STDOUT = 292,
    CONVERT = 293,
    LENGTH = 294,
    FUNCTION = 295,
    COMMA = 296,
    ARRAY = 297
  };
#endif
/* Tokens.  */
#define DIGIT 258
#define ALPHA 259
#define SPACE_ALPHA 260
#define STRING_VALUE 261
#define INT 262
#define STRING 263
#define CHAR 264
#define PLUS 265
#define MINUS 266
#define TIMES 267
#define DIV 268
#define MOD 269
#define END 270
#define OPEN_P 271
#define CLOSE_P 272
#define CONDITIONAL 273
#define EXEC 274
#define END_EXEC 275
#define IF 276
#define ELSE 277
#define ESCAPE 278
#define WHILE 279
#define L 280
#define G 281
#define LE 282
#define GE 283
#define EQ 284
#define NE 285
#define OR 286
#define AND 287
#define ASSIGN 288
#define RETURN 289
#define MAIN 290
#define STDIN 291
#define STDOUT 292
#define CONVERT 293
#define LENGTH 294
#define FUNCTION 295
#define COMMA 296
#define ARRAY 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "grammar.y"

	char * stringValue;

#line 227 "y.tab.c"

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  223

#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    63,    67,    68,    69,    73,    74,    75,
      79,    80,    81,    85,    86,    87,    88,    92,    96,    97,
      98,    99,   100,   101,   109,   117,   125,   129,   133,   134,
     135,   136,   137,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     160,   161,   162,   163,   164,   165,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   178,   179,   180,   181,   184,
     185,   186,   191,   192,   193,   197,   198,   199,   204,   208,
     209,   213,   214,   218,   219,   223,   232,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   253,   254,   255,   256,
     257
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "ALPHA", "SPACE_ALPHA",
  "STRING_VALUE", "INT", "STRING", "CHAR", "PLUS", "MINUS", "TIMES", "DIV",
  "MOD", "END", "OPEN_P", "CLOSE_P", "CONDITIONAL", "EXEC", "END_EXEC",
  "IF", "ELSE", "ESCAPE", "WHILE", "L", "G", "LE", "GE", "EQ", "NE", "OR",
  "AND", "ASSIGN", "RETURN", "MAIN", "STDIN", "STDOUT", "CONVERT",
  "LENGTH", "FUNCTION", "COMMA", "ARRAY", "$accept", "start", "function",
  "type", "params", "args", "call", "program", "get", "out", "var",
  "operation", "assignment", "alpha_array", "digit_array", "char_array",
  "rule", "operator", "op", YY_NULLPTR
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
     295,   296,   297
};
# endif

#define YYPACT_NINF -109

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-109)))

#define YYTABLE_NINF -60

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      67,   -25,   -17,    -9,     7,    34,    67,    38,    55,    63,
      64,  -109,  -109,    54,    70,    94,    12,   108,   113,   124,
     123,    86,   118,    56,   136,   125,    64,   148,   140,   140,
     140,   127,    10,   135,    -4,    -3,    66,  -109,  -109,  -109,
     123,   160,  -109,    93,   151,   161,    56,    56,   132,   153,
      64,  -109,  -109,    64,  -109,  -109,  -109,   163,   155,   157,
     159,   162,   164,  -109,   128,   165,     4,   167,   166,   169,
     170,  -109,   130,   138,    18,   172,    87,   174,     2,   176,
      93,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,   123,  -109,  -109,   146,  -109,
    -109,   168,   171,    64,  -109,  -109,   149,   173,   177,   178,
    -109,   127,   150,   183,   195,   196,  -109,   152,   129,   130,
      71,   185,   186,  -109,   175,    27,  -109,  -109,   179,    36,
     199,  -109,   180,   123,   187,   202,    56,    56,  -109,   140,
      64,    64,    64,  -109,  -109,  -109,   189,   190,   130,   130,
    -109,  -109,   205,  -109,   154,  -109,   206,   207,   211,   156,
     209,   158,  -109,   193,   200,   201,   203,  -109,  -109,  -109,
     198,   204,   208,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
     210,   212,   181,  -109,  -109,  -109,   182,  -109,  -109,  -109,
     217,  -109,  -109,    42,   215,  -109,  -109,  -109,  -109,  -109,
     211,   209,   184,   213,   214,  -109,  -109,  -109,   193,    64,
      64,  -109,   216,   218,    28,    64,   220,  -109,  -109,    64,
     221,    64,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     1,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,     0,    26,     0,    12,    12,
      12,    16,     0,     0,    50,    52,    51,    76,    75,    77,
       0,     0,    86,     0,     0,     0,    30,    30,     0,     0,
      26,     2,    21,    26,     7,     8,     9,     0,     0,     0,
       0,    75,     0,    15,    13,    76,    75,    77,     0,     0,
       0,    68,    74,     0,     0,     0,     0,     0,     0,     0,
       0,    78,    96,    97,    99,    98,   100,    88,    89,    90,
      91,    92,    93,    94,    95,     0,    87,    20,     0,    31,
      28,     0,     0,    26,    19,    18,    10,     0,     0,     0,
      17,    16,     0,    78,     0,     0,    60,     0,     0,    74,
      74,     0,     0,    65,    53,    36,    35,    66,    54,    47,
       0,    67,    55,     0,     0,     0,    30,    30,    22,    12,
      26,    26,    26,    14,    61,    62,     0,     0,    74,    74,
      69,    71,     0,    33,     0,    34,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,    32,    29,    11,
       0,     0,     0,    63,    64,    72,    73,    70,    43,    45,
       0,     0,    82,    38,    44,    46,    80,    39,    48,    49,
       0,    40,    85,     0,     0,     4,     5,     6,    41,    42,
       0,     0,    84,     0,     0,    27,    81,    79,     0,    26,
      26,    83,     0,     0,    26,    26,     0,    24,    23,    26,
       0,    26,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,   225,  -109,  -109,   -28,    62,   -23,   -26,  -109,   -42,
    -109,  -108,   -14,    25,    35,    26,   -37,   188,   -33
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    57,    58,    62,    24,    25,    26,    49,
      27,   116,    42,   187,   183,   191,    43,    95,   117
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    59,    60,    80,    99,   100,   129,    44,    63,    71,
      96,   153,   155,    65,    66,     7,    67,    64,    72,   -56,
      31,   119,   120,     8,   104,   130,    10,   105,    31,    74,
      76,     9,    16,    68,    11,    17,    18,    19,    75,    77,
     175,   176,    13,    31,    20,    32,   112,    96,    69,    70,
     216,   123,    31,   127,    33,   131,   121,   122,   134,    14,
      46,    47,    21,   203,    22,    23,   204,    15,    16,   159,
      28,    17,    18,    19,     1,     2,     3,   138,   161,    48,
      20,    82,    83,    84,    85,    86,    29,    31,    63,    37,
      38,   125,    39,   126,   167,   168,   164,    64,    21,    78,
      22,    23,     4,    82,    83,    84,    85,    86,    79,    41,
      30,   169,    34,   154,   170,   171,   172,    35,    87,    88,
      89,    90,    91,    92,    93,    94,    37,    38,    36,    39,
      37,    61,   150,    39,    45,   151,   101,   102,    73,    40,
      82,    83,    84,    85,    86,    51,    41,    54,    55,    56,
      41,    50,   152,   144,   145,   148,   149,   178,   179,   184,
     185,   188,   189,    53,    81,    98,    97,   106,   103,   111,
     113,   118,   107,   143,   108,   124,   109,   128,    31,   132,
     -58,   110,   -59,   212,   213,   114,   115,   135,   217,   218,
     139,   136,   140,   220,   137,   222,   141,   142,   -57,   146,
     147,   156,   157,   162,   165,   166,   173,   174,   158,   177,
     180,   181,   160,   163,   182,   186,   190,   192,   195,   193,
     194,   202,   200,   201,   196,   208,   207,   198,   197,   199,
     205,    12,   209,   210,   211,   206,   214,     0,   215,   219,
       0,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133
};

static const yytype_int16 yycheck[] =
{
      26,    29,    30,    40,    46,    47,     4,    21,    31,    32,
      43,   119,   120,     3,     4,    40,     6,    31,    32,    15,
      16,     3,     4,    40,    50,    23,    19,    53,    16,    33,
      33,    40,     4,    23,     0,     7,     8,     9,    42,    42,
     148,   149,     4,    16,    16,    33,    42,    80,    38,    39,
      22,    74,    16,    76,    42,    78,    38,    39,    95,     4,
       4,     5,    34,    21,    36,    37,    24,     4,     4,    42,
      16,     7,     8,     9,     7,     8,     9,   103,    42,    23,
      16,    10,    11,    12,    13,    14,    16,    16,   111,     3,
       4,     4,     6,     6,   136,   137,   133,   111,    34,    33,
      36,    37,    35,    10,    11,    12,    13,    14,    42,    23,
      16,   139,     4,    42,   140,   141,   142,     4,    25,    26,
      27,    28,    29,    30,    31,    32,     3,     4,     4,     6,
       3,     4,     3,     6,    16,     6,     4,     5,     3,    16,
      10,    11,    12,    13,    14,    20,    23,     7,     8,     9,
      23,    15,    23,     3,     4,     3,     4,     3,     4,     3,
       4,     3,     4,    15,     4,     4,    15,     4,    15,    41,
       4,    33,    17,   111,    17,     3,    17,     3,    16,     3,
      15,    17,    15,   209,   210,    16,    16,    41,   214,   215,
      41,    23,    19,   219,    23,   221,    19,    19,    15,     4,
       4,    16,    16,     4,    17,     3,    17,    17,    33,     4,
       4,     4,    33,    33,     3,     6,    23,    17,    20,    18,
      17,     4,    41,    41,    20,    41,   201,    17,    20,    17,
      15,     6,    19,    19,   208,   200,    20,    -1,    20,    19,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    35,    44,    45,    40,    40,    40,
      19,     0,    44,     4,     4,     4,     4,     7,     8,     9,
      16,    34,    36,    37,    49,    50,    51,    53,    16,    16,
      16,    16,    33,    42,     4,     4,     4,     3,     4,     6,
      16,    23,    55,    59,    55,    16,     4,     5,    23,    52,
      15,    20,    50,    15,     7,     8,     9,    46,    47,    47,
      47,     4,    48,    49,    55,     3,     4,     6,    23,    38,
      39,    49,    55,     3,    33,    42,    33,    42,    33,    42,
      59,     4,    10,    11,    12,    13,    14,    25,    26,    27,
      28,    29,    30,    31,    32,    60,    61,    15,     4,    52,
      52,     4,     5,    15,    50,    50,     4,    17,    17,    17,
      17,    41,    42,     4,    16,    16,    54,    61,    33,     3,
       4,    38,    39,    49,     3,     4,     6,    49,     3,     4,
      23,    49,     3,    60,    59,    41,    23,    23,    50,    41,
      19,    19,    19,    48,     3,     4,     4,     4,     3,     4,
       3,     6,    23,    54,    42,    54,    16,    16,    33,    42,
      33,    42,     4,    33,    59,    17,     3,    52,    52,    47,
      50,    50,    50,    17,    17,    54,    54,     4,     3,     4,
       4,     4,     3,    57,     3,     4,     6,    56,     3,     4,
      23,    58,    17,    18,    17,    20,    20,    20,    17,    17,
      41,    41,     4,    21,    24,    15,    57,    56,    41,    19,
      19,    58,    50,    50,    20,    20,    22,    50,    50,    19,
      50,    20,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    45,    46,    46,    46,
      47,    47,    47,    48,    48,    48,    48,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    52,    52,
      52,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    54,    54,    54,    55,    55,    55,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    61,    61,    61,
      61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     9,     9,     9,     1,     1,     1,
       2,     4,     0,     1,     3,     1,     0,     4,     3,     3,
       3,     2,     4,    11,    11,    15,     0,     7,     2,     4,
       0,     2,     4,     5,     5,     4,     4,     5,     6,     6,
       6,     7,     7,     6,     6,     6,     6,     4,     6,     6,
       2,     2,     2,     4,     4,     4,     3,     4,     3,     3,
       4,     5,     5,     6,     6,     4,     4,     4,     3,     5,
       6,     5,     3,     3,     0,     1,     1,     1,     2,     3,
       1,     3,     1,     4,     2,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
#line 62 "grammar.y"
    { if(!checkReturnType((yyvsp[-1].stringValue),KIND_INT)){yyerror("Wrong return type"); YYABORT;}(yyval.stringValue) = malloc(16 +  strlen((yyvsp[-1].stringValue))); sprintf((yyval.stringValue), "int main(){ %s }\n",(yyvsp[-1].stringValue)); add((yyval.stringValue), true);  }
#line 1473 "y.tab.c"
    break;

  case 3:
#line 63 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))+3); sprintf((yyval.stringValue),"%s\n%s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1479 "y.tab.c"
    break;

  case 4:
#line 67 "grammar.y"
    {if(checkIfFunctionExists((yyvsp[-6].stringValue))){yyerror("Function already declared."); YYABORT;} if(!checkReturnType((yyvsp[-1].stringValue),KIND_INT)){yyerror("Wrong return type"); YYABORT;}(yyval.stringValue) = malloc(3+strlen((yyvsp[-6].stringValue))+strlen((yyvsp[-4].stringValue))+strlen((yyvsp[-1].stringValue))+ 8); sprintf((yyval.stringValue), "%s %s(%s){\n%s}\n", "int", (yyvsp[-6].stringValue), (yyvsp[-4].stringValue), (yyvsp[-1].stringValue)); add((yyval.stringValue),true); addFunction((yyvsp[-6].stringValue),KIND_INT,(yyvsp[-4].stringValue)); freeVars();}
#line 1485 "y.tab.c"
    break;

  case 5:
#line 68 "grammar.y"
    {if(checkIfFunctionExists((yyvsp[-6].stringValue))){yyerror("Function already declared."); YYABORT;} if(!checkReturnType((yyvsp[-1].stringValue),KIND_STRING)){yyerror("Wrong return type"); YYABORT;}(yyval.stringValue) = malloc(7+strlen((yyvsp[-6].stringValue))+strlen((yyvsp[-4].stringValue))+strlen((yyvsp[-1].stringValue))+ 8); sprintf((yyval.stringValue), "%s %s(%s){\n%s}\n", "char *", (yyvsp[-6].stringValue), (yyvsp[-4].stringValue), (yyvsp[-1].stringValue)); add((yyval.stringValue),true); addFunction((yyvsp[-6].stringValue),KIND_STRING,(yyvsp[-4].stringValue));freeVars();}
#line 1491 "y.tab.c"
    break;

  case 6:
#line 69 "grammar.y"
    {if(checkIfFunctionExists((yyvsp[-6].stringValue))){yyerror("Function already declared."); YYABORT;} if(!checkReturnType((yyvsp[-1].stringValue),KIND_CHAR)){yyerror("Wrong return type"); YYABORT;}(yyval.stringValue) = malloc(4+strlen((yyvsp[-6].stringValue))+strlen((yyvsp[-4].stringValue))+strlen((yyvsp[-1].stringValue))+ 8); sprintf((yyval.stringValue), "%s %s(%s){\n%s}\n", "char", (yyvsp[-6].stringValue), (yyvsp[-4].stringValue), (yyvsp[-1].stringValue)); add((yyval.stringValue),true); addFunction((yyvsp[-6].stringValue),KIND_CHAR,(yyvsp[-4].stringValue)); freeVars();}
#line 1497 "y.tab.c"
    break;

  case 7:
#line 73 "grammar.y"
    {(yyval.stringValue) = "int";}
#line 1503 "y.tab.c"
    break;

  case 8:
#line 74 "grammar.y"
    {(yyval.stringValue) = "char *";}
#line 1509 "y.tab.c"
    break;

  case 9:
#line 75 "grammar.y"
    {(yyval.stringValue) = "char";}
#line 1515 "y.tab.c"
    break;

  case 10:
#line 79 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue)) +2); sprintf((yyval.stringValue), "%s %s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true); if(strcmp((yyvsp[-1].stringValue),"int")==0){addVar((yyvsp[0].stringValue), KIND_INT,1);}else{addVar((yyvsp[0].stringValue), KIND_STRING,1);}}
#line 1521 "y.tab.c"
    break;

  case 11:
#line 80 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+strlen((yyvsp[-2].stringValue))+4+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s %s, %s", (yyvsp[-3].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);if(strcmp((yyvsp[-3].stringValue),"int")==0){addVar((yyvsp[-2].stringValue), KIND_INT,1);}else{addVar((yyvsp[-2].stringValue), KIND_STRING,1);}}
#line 1527 "y.tab.c"
    break;

  case 12:
#line 81 "grammar.y"
    { (yyval.stringValue) = ""; }
#line 1533 "y.tab.c"
    break;

  case 13:
#line 85 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+1); sprintf((yyval.stringValue), "%s", (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1539 "y.tab.c"
    break;

  case 14:
#line 86 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+2+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s,%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1545 "y.tab.c"
    break;

  case 15:
#line 87 "grammar.y"
    { (yyval.stringValue) = (yyvsp[0].stringValue);}
#line 1551 "y.tab.c"
    break;

  case 16:
#line 88 "grammar.y"
    { (yyval.stringValue) = "";}
#line 1557 "y.tab.c"
    break;

  case 17:
#line 92 "grammar.y"
    {if(!checkArgsOk((yyvsp[-3].stringValue),(yyvsp[-1].stringValue))){yyerror("Incompatible args for function"); YYABORT;} (yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+3+strlen((yyvsp[-1].stringValue))); sprintf((yyval.stringValue),"%s(%s)",(yyvsp[-3].stringValue),(yyvsp[-1].stringValue)); add((yyval.stringValue),true);}
#line 1563 "y.tab.c"
    break;

  case 18:
#line 96 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+3+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s; %s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1569 "y.tab.c"
    break;

  case 19:
#line 97 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+3+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s; %s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1575 "y.tab.c"
    break;

  case 20:
#line 98 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue)) +9); sprintf((yyval.stringValue), "return %s;", (yyvsp[-1].stringValue)); add((yyval.stringValue),true);}
#line 1581 "y.tab.c"
    break;

  case 21:
#line 99 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))+5); sprintf((yyval.stringValue),"%s %s",(yyvsp[-1].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue), true);}
#line 1587 "y.tab.c"
    break;

  case 22:
#line 100 "grammar.y"
    { char * print = printfParser((yyvsp[-2].stringValue)); if(print==NULL){yyerror("Sintax error on P.\n Check if your variables exist."); YYABORT;} (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))*2+5+strlen((yyvsp[0].stringValue))+ 11); sprintf((yyval.stringValue), "printf(%s);\n%s", print, (yyvsp[0].stringValue)); add((yyval.stringValue),true); free(print);}
#line 1593 "y.tab.c"
    break;

  case 23:
#line 101 "grammar.y"
    {   
                                                                                            if(!are_comparable((yyvsp[-9].stringValue), (yyvsp[-7].stringValue))) {
                                                                                                yyerror("Uncomparable data types");
                                                                                                YYABORT;
                                                                                            }
                                                                                            (yyval.stringValue) = malloc(strlen((yyvsp[-9].stringValue))+10+strlen((yyvsp[-8].stringValue))+strlen((yyvsp[-7].stringValue))+strlen("while")+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue)));
                                                                                            sprintf((yyval.stringValue),"while(%s %s %s){%s}\n%s ",(yyvsp[-9].stringValue),(yyvsp[-8].stringValue),(yyvsp[-7].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue));
                                                                                            add((yyval.stringValue),true);}
#line 1606 "y.tab.c"
    break;

  case 24:
#line 109 "grammar.y"
    {   
                                                                                            if(!are_comparable((yyvsp[-9].stringValue), (yyvsp[-7].stringValue))) {
                                                                                                yyerror("Uncomparable data types");
                                                                                                YYABORT;
                                                                                            }
                                                                                            (yyval.stringValue) = malloc(strlen((yyvsp[-9].stringValue))+10+strlen((yyvsp[-8].stringValue))+strlen((yyvsp[-7].stringValue))+strlen("if")+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue)));
                                                                                            sprintf((yyval.stringValue),"if(%s %s %s){%s}\n%s ",(yyvsp[-9].stringValue),(yyvsp[-8].stringValue),(yyvsp[-7].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue));
                                                                                            add((yyval.stringValue),true);}
#line 1619 "y.tab.c"
    break;

  case 25:
#line 117 "grammar.y"
    {   
                                                                                                                        if(!are_comparable((yyvsp[-13].stringValue), (yyvsp[-11].stringValue))) {
                                                                                                                            yyerror("Uncomparable data types");
                                                                                                                            YYABORT;
                                                                                                                        }
                                                                                                                        (yyval.stringValue) = malloc(25+strlen((yyvsp[-13].stringValue))+strlen((yyvsp[-12].stringValue))+strlen((yyvsp[-11].stringValue))+strlen((yyvsp[-6].stringValue))+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue)));
                                                                                                                        sprintf((yyval.stringValue),"if(%s %s %s){%s}\nelse{%s}\n%s ",(yyvsp[-13].stringValue),(yyvsp[-12].stringValue),(yyvsp[-11].stringValue),(yyvsp[-6].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue));
                                                                                                                        add((yyval.stringValue),true);}
#line 1632 "y.tab.c"
    break;

  case 26:
#line 125 "grammar.y"
    { (yyval.stringValue) = "";}
#line 1638 "y.tab.c"
    break;

  case 27:
#line 129 "grammar.y"
    { if(checkIfVarExists((yyvsp[-4].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}  (yyval.stringValue) = malloc(2*strlen((yyvsp[-4].stringValue))+2*strlen((yyvsp[-2].stringValue))+ 30); sprintf((yyval.stringValue),"char %s[%s];\nfgets(%s,%s,stdin);\n",(yyvsp[-4].stringValue),(yyvsp[-2].stringValue),(yyvsp[-4].stringValue),(yyvsp[-2].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-4].stringValue), KIND_STRING,1);}
#line 1644 "y.tab.c"
    break;

  case 28:
#line 133 "grammar.y"
    { (yyval.stringValue) = malloc(1 + strlen((yyvsp[-1].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s%s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1650 "y.tab.c"
    break;

  case 29:
#line 134 "grammar.y"
    { (yyval.stringValue) = malloc(3 + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "\'%s\'%s", (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1656 "y.tab.c"
    break;

  case 30:
#line 135 "grammar.y"
    { (yyval.stringValue) = ""; }
#line 1662 "y.tab.c"
    break;

  case 31:
#line 136 "grammar.y"
    { (yyval.stringValue) = malloc(1 + strlen((yyvsp[-1].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s%s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1668 "y.tab.c"
    break;

  case 32:
#line 137 "grammar.y"
    { (yyval.stringValue) = malloc(3 + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "\'%s\'%s", (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1674 "y.tab.c"
    break;

  case 33:
#line 142 "grammar.y"
    { if(checkIfVarExists((yyvsp[-3].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;} (yyval.stringValue) = malloc(3+strlen((yyvsp[-3].stringValue))+6+strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s=%s%s","int",(yyvsp[-3].stringValue),(yyvsp[-1].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-3].stringValue), KIND_INT,1);}
#line 1680 "y.tab.c"
    break;

  case 34:
#line 143 "grammar.y"
    { if(checkIfVarExists((yyvsp[-3].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!isOfKind((yyvsp[-1].stringValue),KIND_INT)){yyerror("Variable should be int type."); YYABORT;}(yyval.stringValue) = malloc(3+strlen((yyvsp[-3].stringValue))+6+strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s=%s%s","int",(yyvsp[-3].stringValue),(yyvsp[-1].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-3].stringValue), KIND_INT,1);}
#line 1686 "y.tab.c"
    break;

  case 35:
#line 144 "grammar.y"
    { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}(yyval.stringValue) = malloc(7+strlen((yyvsp[-2].stringValue))+6+strlen((yyvsp[0].stringValue))); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0;sprintf((yyval.stringValue),"%s %s=\"%s\"","char *",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)+1); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_STRING,1);}
#line 1692 "y.tab.c"
    break;

  case 36:
#line 145 "grammar.y"
    { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!isOfKind((yyvsp[0].stringValue),KIND_STRING)){yyerror("Variable should be string type"); YYABORT;}(yyval.stringValue) = malloc(7+strlen((yyvsp[-2].stringValue))+6+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s=%s","char *",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_STRING,1);}
#line 1698 "y.tab.c"
    break;

  case 37:
#line 146 "grammar.y"
    { if(strlen((yyvsp[0].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}if(checkIfVarExists((yyvsp[-3].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}(yyval.stringValue) = malloc(7+strlen((yyvsp[-3].stringValue))+6+strlen((yyvsp[0].stringValue)));sprintf((yyval.stringValue),"char %s=\'%s\'",(yyvsp[-3].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-3].stringValue), KIND_CHAR,1);}
#line 1704 "y.tab.c"
    break;

  case 38:
#line 147 "grammar.y"
    { if(checkIfVarExists((yyvsp[-4].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(array_is_incorrect((yyvsp[0].stringValue),atoi((yyvsp[-2].stringValue)))){yyerror("Bad initialization of array"); YYABORT;} (yyval.stringValue) = malloc(3+strlen((yyvsp[-4].stringValue))+10+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]={%s}","int",(yyvsp[-4].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-4].stringValue), KIND_ARRAY_INT,atoi((yyvsp[-2].stringValue))); }
#line 1710 "y.tab.c"
    break;

  case 39:
#line 148 "grammar.y"
    { if(checkIfVarExists((yyvsp[-4].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(array_is_incorrect((yyvsp[0].stringValue),atoi((yyvsp[-2].stringValue)))){yyerror("Bad initialization of array"); YYABORT;} (yyval.stringValue) = malloc(7+strlen((yyvsp[-4].stringValue))+10+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]={%s}","char *",(yyvsp[-4].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-4].stringValue), KIND_ARRAY_STRING,atoi((yyvsp[-2].stringValue)));}
#line 1716 "y.tab.c"
    break;

  case 40:
#line 149 "grammar.y"
    { if(checkIfVarExists((yyvsp[-4].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(array_is_incorrect((yyvsp[0].stringValue),atoi((yyvsp[-2].stringValue)))){yyerror("Bad initialization of array"); YYABORT;} (yyval.stringValue) = malloc(7+strlen((yyvsp[-4].stringValue))+10+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]={%s}","char",(yyvsp[-4].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-4].stringValue), KIND_ARRAY_CHAR,atoi((yyvsp[-2].stringValue)));}
#line 1722 "y.tab.c"
    break;

  case 41:
#line 150 "grammar.y"
    { if(!isOfKind((yyvsp[-1].stringValue),KIND_STRING)){yyerror("Variable to convert should be string type."); YYABORT;} (yyval.stringValue) = malloc(7+strlen((yyvsp[-1].stringValue))+3+strlen((yyvsp[-5].stringValue))+6); sprintf((yyval.stringValue),"int %s = atoi(%s)",(yyvsp[-5].stringValue),(yyvsp[-1].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-5].stringValue), KIND_INT,1);}
#line 1728 "y.tab.c"
    break;

  case 42:
#line 151 "grammar.y"
    { if(!isOfKind((yyvsp[-1].stringValue),KIND_STRING)){yyerror("Variable should be string type."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue))+strlen((yyvsp[-5].stringValue)) +15); sprintf((yyval.stringValue),"int %s=strlen(%s)",(yyvsp[-5].stringValue), (yyvsp[-1].stringValue)); add((yyval.stringValue),true);addVar((yyvsp[-5].stringValue), KIND_INT,1);}
#line 1734 "y.tab.c"
    break;

  case 43:
#line 152 "grammar.y"
    { if(!correctArray((yyvsp[-2].stringValue),KIND_ARRAY_INT,atoi((yyvsp[0].stringValue)))){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(3+strlen((yyvsp[-4].stringValue))+6+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "int %s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);addVar((yyvsp[-4].stringValue), KIND_INT,1);}
#line 1740 "y.tab.c"
    break;

  case 44:
#line 153 "grammar.y"
    { if(!correctArray((yyvsp[-2].stringValue),KIND_ARRAY_STRING,atoi((yyvsp[0].stringValue)))){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(7+strlen((yyvsp[-4].stringValue))+6+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "char * %s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);addVar((yyvsp[-4].stringValue), KIND_STRING,1);}
#line 1746 "y.tab.c"
    break;

  case 45:
#line 154 "grammar.y"
    { if(!isOfKind((yyvsp[0].stringValue),KIND_INT)){yyerror("Variable should be int type to de-reference.");YYABORT;}if(!correctArray((yyvsp[-2].stringValue),KIND_ARRAY_INT,atoi((yyvsp[0].stringValue)))){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(3+strlen((yyvsp[-4].stringValue))+6+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "int %s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);addVar((yyvsp[-4].stringValue), KIND_INT,1);}
#line 1752 "y.tab.c"
    break;

  case 46:
#line 155 "grammar.y"
    { if(!isOfKind((yyvsp[0].stringValue),KIND_INT)){yyerror("Variable should be int type to de-reference.");YYABORT;}if(!correctArray((yyvsp[-2].stringValue),KIND_ARRAY_STRING,atoi((yyvsp[0].stringValue)))){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(7+strlen((yyvsp[-4].stringValue))+6+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "char * %s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);addVar((yyvsp[-4].stringValue), KIND_STRING,1);}
#line 1758 "y.tab.c"
    break;

  case 47:
#line 156 "grammar.y"
    { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!isOfKind((yyvsp[0].stringValue),KIND_CHAR)){yyerror("Variable should be char type."); YYABORT;}(yyval.stringValue) = malloc(4+strlen((yyvsp[-2].stringValue))+6+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s=%s","char",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_CHAR,1);}
#line 1764 "y.tab.c"
    break;

  case 48:
#line 157 "grammar.y"
    { if(!correctArray((yyvsp[-2].stringValue),KIND_ARRAY_CHAR,atoi((yyvsp[0].stringValue)))){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(4+strlen((yyvsp[-4].stringValue))+6+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "char %s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);addVar((yyvsp[-4].stringValue), KIND_CHAR,1);}
#line 1770 "y.tab.c"
    break;

  case 49:
#line 158 "grammar.y"
    { if(!isOfKind((yyvsp[0].stringValue),KIND_INT)){yyerror("Variable should be int type to de-reference.");YYABORT;}if(!correctArray((yyvsp[-2].stringValue),KIND_ARRAY_CHAR,atoi((yyvsp[0].stringValue)))){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(4+strlen((yyvsp[-4].stringValue))+6+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "char %s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);addVar((yyvsp[-4].stringValue), KIND_CHAR,1);}
#line 1776 "y.tab.c"
    break;

  case 50:
#line 160 "grammar.y"
    { if(checkIfVarExists((yyvsp[0].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}(yyval.stringValue) = malloc(3+strlen((yyvsp[0].stringValue))+2); sprintf((yyval.stringValue),"%s %s","int",(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[0].stringValue), KIND_INT,1);}
#line 1782 "y.tab.c"
    break;

  case 51:
#line 161 "grammar.y"
    { if(checkIfVarExists((yyvsp[0].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}(yyval.stringValue) = malloc(5+strlen((yyvsp[0].stringValue))+2); sprintf((yyval.stringValue),"char %s",(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[0].stringValue), KIND_CHAR,1);}
#line 1788 "y.tab.c"
    break;

  case 52:
#line 162 "grammar.y"
    { if(checkIfVarExists((yyvsp[0].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}(yyval.stringValue) = malloc(7+strlen((yyvsp[0].stringValue))+2); sprintf((yyval.stringValue),"%s %s","char *",(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[0].stringValue), KIND_STRING,1);}
#line 1794 "y.tab.c"
    break;

  case 53:
#line 163 "grammar.y"
    { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;} (yyval.stringValue) = malloc(3+strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]","int",(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_ARRAY_INT,atoi((yyvsp[0].stringValue))); }
#line 1800 "y.tab.c"
    break;

  case 54:
#line 164 "grammar.y"
    { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;} (yyval.stringValue) = malloc(7+strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]","char *",(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_ARRAY_STRING,atoi((yyvsp[0].stringValue)));}
#line 1806 "y.tab.c"
    break;

  case 55:
#line 165 "grammar.y"
    { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;} (yyval.stringValue) = malloc(4+strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]","char",(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_ARRAY_CHAR,atoi((yyvsp[0].stringValue))); }
#line 1812 "y.tab.c"
    break;

  case 56:
#line 167 "grammar.y"
    { if((!checkIfVarExists((yyvsp[-2].stringValue))||!checkIfVarExists((yyvsp[0].stringValue)))|| !are_comparable((yyvsp[-2].stringValue),(yyvsp[0].stringValue))){yyerror("Variables aren't compatible."); YYABORT;}(yyval.stringValue) = malloc(4+strlen((yyvsp[-2].stringValue))+6+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s=%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1818 "y.tab.c"
    break;

  case 57:
#line 168 "grammar.y"
    { if(!isOfKind((yyvsp[-3].stringValue),KIND_CHAR)){yyerror("Variable should be int type.");YYABORT;}if(strlen((yyvsp[0].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+strlen((yyvsp[0].stringValue))+10); sprintf((yyval.stringValue), "%s=\'%s\'", (yyvsp[-3].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1824 "y.tab.c"
    break;

  case 58:
#line 169 "grammar.y"
    { if(!isOfKind((yyvsp[-2].stringValue),KIND_INT)){yyerror("Variable should be int type.");YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))+5); sprintf((yyval.stringValue), "%s=%s", (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1830 "y.tab.c"
    break;

  case 59:
#line 170 "grammar.y"
    { if(!isOfKind((yyvsp[-2].stringValue),KIND_STRING)){yyerror("Variable should be string type.");YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))+5); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0;sprintf((yyval.stringValue), "%s=\"%s\"", (yyvsp[-2].stringValue), (yyvsp[0].stringValue)+1); add((yyval.stringValue),true);}
#line 1836 "y.tab.c"
    break;

  case 60:
#line 171 "grammar.y"
    { if(!isOfKind((yyvsp[-3].stringValue),KIND_INT)){yyerror("Variable should be int type."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))+5);  sprintf((yyval.stringValue), "%s=%s%s", (yyvsp[-3].stringValue), (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1842 "y.tab.c"
    break;

  case 61:
#line 172 "grammar.y"
    { if(!compatibleArray((yyvsp[-4].stringValue),(yyvsp[-2].stringValue),atoi((yyvsp[0].stringValue)))){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-4].stringValue))+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue)) +5); sprintf((yyval.stringValue), "%s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1848 "y.tab.c"
    break;

  case 62:
#line 173 "grammar.y"
    { if(!isOfKind((yyvsp[0].stringValue),KIND_INT)){yyerror("Variable should be int type to de-reference.");YYABORT;}if(!compatibleArray((yyvsp[-4].stringValue),(yyvsp[-2].stringValue),0)){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-4].stringValue))+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue)) +5); sprintf((yyval.stringValue), "%s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1854 "y.tab.c"
    break;

  case 63:
#line 174 "grammar.y"
    { if(!isOfKind((yyvsp[-5].stringValue),KIND_INT)){yyerror("Variable to assign should be int type."); YYABORT;} if(!isOfKind((yyvsp[-1].stringValue),KIND_STRING)){yyerror("Argument should be string type."); YYABORT;} (yyval.stringValue) = malloc(strlen((yyvsp[-5].stringValue))+strlen((yyvsp[-1].stringValue))+10); sprintf((yyval.stringValue),"%s = atoi(%s)",(yyvsp[-5].stringValue),(yyvsp[-1].stringValue)); add((yyval.stringValue),true);}
#line 1860 "y.tab.c"
    break;

  case 64:
#line 175 "grammar.y"
    { if(!isOfKind((yyvsp[-5].stringValue),KIND_INT)){yyerror("Variable to assign should be int type."); YYABORT;} if(!isOfKind((yyvsp[-1].stringValue),KIND_STRING)){yyerror("Argument hould be string type."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-5].stringValue))+strlen((yyvsp[-1].stringValue))+10); sprintf((yyval.stringValue),"%s=strlen(%s)",(yyvsp[-5].stringValue), (yyvsp[-1].stringValue)); add((yyval.stringValue),true);}
#line 1866 "y.tab.c"
    break;

  case 65:
#line 178 "grammar.y"
    { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!functionReturnsKind((yyvsp[0].stringValue), KIND_INT)){yyerror("Function should return type int"); YYABORT;} (yyval.stringValue) = malloc(3+strlen((yyvsp[-2].stringValue))+3+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"int %s=%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_INT,1);}
#line 1872 "y.tab.c"
    break;

  case 66:
#line 179 "grammar.y"
    { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!functionReturnsKind((yyvsp[0].stringValue), KIND_STRING)){yyerror("Function should return type string"); YYABORT;} (yyval.stringValue) = malloc(7+strlen((yyvsp[-2].stringValue))+3+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"char* %s=%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_STRING,1);}
#line 1878 "y.tab.c"
    break;

  case 67:
#line 180 "grammar.y"
    { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!functionReturnsKind((yyvsp[0].stringValue), KIND_CHAR)){yyerror("Function should return type char"); YYABORT;} (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+8+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"char %s=%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_CHAR,1);}
#line 1884 "y.tab.c"
    break;

  case 68:
#line 181 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+2+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s=%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1890 "y.tab.c"
    break;

  case 69:
#line 184 "grammar.y"
    { if (!isOfKind((yyvsp[-4].stringValue), KIND_ARRAY_INT)){yyerror("Variable should be string array type"); YYABORT;} if(! enoughSpace((yyvsp[-4].stringValue), atoi((yyvsp[-2].stringValue))) ) { yyerror("Array has not enough space"); YYABORT; } (yyval.stringValue) = malloc(strlen((yyvsp[-4].stringValue)) + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue)) + 4 ); sprintf((yyval.stringValue), "%s[%s]=%s", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue), true); }
#line 1896 "y.tab.c"
    break;

  case 70:
#line 185 "grammar.y"
    { if (!isOfKind((yyvsp[-5].stringValue), KIND_ARRAY_CHAR)){yyerror("Variable should be char array type"); YYABORT;} if(! enoughSpace((yyvsp[-5].stringValue), atoi((yyvsp[-3].stringValue))) ) { yyerror("Array has not enough space"); YYABORT; } if(strlen((yyvsp[0].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-5].stringValue)) + strlen((yyvsp[-3].stringValue)) + strlen((yyvsp[0].stringValue)) + 10 ); sprintf((yyval.stringValue), "%s[%s]=\'%s\'", (yyvsp[-5].stringValue), (yyvsp[-3].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue), true); }
#line 1902 "y.tab.c"
    break;

  case 71:
#line 186 "grammar.y"
    { if (!isOfKind((yyvsp[-4].stringValue), KIND_ARRAY_STRING)){yyerror("Variable should be string array type"); YYABORT;} if(! enoughSpace((yyvsp[-4].stringValue), atoi((yyvsp[-2].stringValue))) ) { yyerror("Array has not enough space"); YYABORT; } (yyval.stringValue) = malloc(strlen((yyvsp[-4].stringValue)) + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue)) + 4 ); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0; sprintf((yyval.stringValue), "%s[%s]=\"%s\"", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue)+1); add((yyval.stringValue), true); }
#line 1908 "y.tab.c"
    break;

  case 72:
#line 191 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+ 1 + strlen((yyvsp[-1].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s%s%s",(yyvsp[-2].stringValue),(yyvsp[-1].stringValue),(yyvsp[0].stringValue) ); add((yyval.stringValue),true);}
#line 1914 "y.tab.c"
    break;

  case 73:
#line 192 "grammar.y"
    { if (!isOfKind((yyvsp[-1].stringValue), KIND_INT)){yyerror("Variable should be int type"); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+ 1 + strlen((yyvsp[-1].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s%s%s",(yyvsp[-2].stringValue),(yyvsp[-1].stringValue),(yyvsp[0].stringValue) ); add((yyval.stringValue),true);}
#line 1920 "y.tab.c"
    break;

  case 74:
#line 193 "grammar.y"
    { (yyval.stringValue) = "";}
#line 1926 "y.tab.c"
    break;

  case 75:
#line 197 "grammar.y"
    {(yyval.stringValue) = (yyvsp[0].stringValue);}
#line 1932 "y.tab.c"
    break;

  case 76:
#line 198 "grammar.y"
    {(yyval.stringValue) = (yyvsp[0].stringValue);}
#line 1938 "y.tab.c"
    break;

  case 77:
#line 199 "grammar.y"
    {
        (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1]  = '\"';
        (yyvsp[0].stringValue)[0]               = '\"';
        (yyval.stringValue) = (yyvsp[0].stringValue);
        }
#line 1948 "y.tab.c"
    break;

  case 78:
#line 204 "grammar.y"
    { if(strlen((yyvsp[0].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+3); sprintf((yyval.stringValue), "\'%s\'", (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1954 "y.tab.c"
    break;

  case 79:
#line 208 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); (yyvsp[-2].stringValue)[strlen((yyvsp[-2].stringValue)) - 1] = 0; sprintf((yyval.stringValue), "\"%s\",%s", (yyvsp[-2].stringValue)+1,(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1960 "y.tab.c"
    break;

  case 80:
#line 209 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+5); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0; sprintf((yyval.stringValue), "\"%s\"", (yyvsp[0].stringValue)+1); add((yyval.stringValue),true);}
#line 1966 "y.tab.c"
    break;

  case 81:
#line 213 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+2+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s,%s", (yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1972 "y.tab.c"
    break;

  case 82:
#line 214 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+1); sprintf((yyval.stringValue), "%s", (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1978 "y.tab.c"
    break;

  case 83:
#line 218 "grammar.y"
    { if(strlen((yyvsp[-2].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "\'%s\',%s", (yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1984 "y.tab.c"
    break;

  case 84:
#line 219 "grammar.y"
    { if(strlen((yyvsp[0].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+5); sprintf((yyval.stringValue), "\'%s\'", (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1990 "y.tab.c"
    break;

  case 85:
#line 223 "grammar.y"
    {   
                                            if(!are_comparable((yyvsp[-3].stringValue), (yyvsp[-1].stringValue))) {
                                                yyerror("Uncomparable data types");
                                                YYABORT;
                                            }
                                            (yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue)) + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[-1].stringValue)) + 5);
                                            sprintf((yyval.stringValue), "(%s %s %s)", (yyvsp[-3].stringValue), (yyvsp[-2].stringValue), (yyvsp[-1].stringValue));
                                            add((yyval.stringValue),true);}
#line 2003 "y.tab.c"
    break;

  case 86:
#line 232 "grammar.y"
    { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+1); sprintf((yyval.stringValue), "%s", (yyvsp[0].stringValue)); add((yyval.stringValue), true);}
#line 2009 "y.tab.c"
    break;

  case 87:
#line 241 "grammar.y"
    { (yyval.stringValue) = (yyvsp[0].stringValue);}
#line 2015 "y.tab.c"
    break;

  case 88:
#line 242 "grammar.y"
    { (yyval.stringValue) = "<";}
#line 2021 "y.tab.c"
    break;

  case 89:
#line 243 "grammar.y"
    { (yyval.stringValue) = ">";}
#line 2027 "y.tab.c"
    break;

  case 90:
#line 244 "grammar.y"
    { (yyval.stringValue) = "<=";}
#line 2033 "y.tab.c"
    break;

  case 91:
#line 245 "grammar.y"
    { (yyval.stringValue) = ">=";}
#line 2039 "y.tab.c"
    break;

  case 92:
#line 246 "grammar.y"
    { (yyval.stringValue) = "==";}
#line 2045 "y.tab.c"
    break;

  case 93:
#line 247 "grammar.y"
    { (yyval.stringValue) = "!=";}
#line 2051 "y.tab.c"
    break;

  case 94:
#line 248 "grammar.y"
    { (yyval.stringValue) = "||";}
#line 2057 "y.tab.c"
    break;

  case 95:
#line 249 "grammar.y"
    { (yyval.stringValue) = "&&";}
#line 2063 "y.tab.c"
    break;

  case 96:
#line 253 "grammar.y"
    { (yyval.stringValue) = "+";}
#line 2069 "y.tab.c"
    break;

  case 97:
#line 254 "grammar.y"
    { (yyval.stringValue) = "-";}
#line 2075 "y.tab.c"
    break;

  case 98:
#line 255 "grammar.y"
    { (yyval.stringValue) = "/";}
#line 2081 "y.tab.c"
    break;

  case 99:
#line 256 "grammar.y"
    { (yyval.stringValue) = "*";}
#line 2087 "y.tab.c"
    break;

  case 100:
#line 257 "grammar.y"
    { (yyval.stringValue) = "%";}
#line 2093 "y.tab.c"
    break;


#line 2097 "y.tab.c"

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
#line 260 "grammar.y"

