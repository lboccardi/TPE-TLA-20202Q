/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

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

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#line 236 "y.tab.c"

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

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

#define YYUNDEFTOK  2
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    63,    67,    68,    69,    73,    74,    75,
      79,    80,    81,    85,    86,    87,    88,    92,    96,    97,
      98,    99,   100,   101,   109,   117,   125,   129,   133,   134,
     135,   136,   137,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   161,   162,   163,   164,   165,   166,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   180,   181,   182,
     183,   186,   187,   188,   189,   190,   194,   195,   196,   200,
     201,   202,   207,   211,   212,   216,   217,   221,   222,   223,
     224,   228,   237,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   258,   259,   260,   261,   262
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
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-62)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      68,   -22,    11,    20,     4,    53,    68,    54,    84,    89,
      58,   -51,   -51,   115,   119,   123,    63,   116,   139,   148,
     126,   130,   140,    81,   145,   153,    58,   159,   104,   104,
     104,   134,     9,    65,   -17,   -16,    47,   -51,   -51,   -51,
     126,   171,   -51,    96,   161,   173,    81,    81,    78,   163,
      58,   -51,   -51,    58,   -51,   -51,   -51,   175,   165,   167,
     168,   170,   172,   -51,   146,   178,    -5,   179,    87,   174,
     180,   -51,   152,   150,   162,    18,   177,    24,   185,    10,
     196,    96,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   126,   -51,   -51,   160,
     -51,   -51,   158,   182,    58,   -51,   -51,   169,   181,   184,
     187,   -51,   134,   112,   -51,   192,   204,   205,   -51,   142,
     138,   207,   152,    28,   197,   198,   -51,   183,    13,   -51,
     -51,   186,    29,   144,   -51,   188,   126,   195,   212,    81,
      81,   -51,   104,    58,    58,    58,   -51,   -51,   -51,   200,
     201,   152,   152,   -51,   -51,   147,   -51,   -51,   151,   -51,
     216,   218,   220,   155,   219,   164,   -51,   -51,   203,   210,
     206,   211,   -51,   -51,   -51,   209,   213,   214,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   215,   221,   189,   -51,
     -51,   -51,   190,   -51,   -51,   -51,   166,   -51,   -51,    60,
     222,   -51,   -51,   -51,   -51,   -51,   220,   219,   194,   199,
     217,   223,   -51,   -51,   -51,   203,   203,    58,    58,   -51,
     -51,   224,   225,    27,    58,   227,   -51,   -51,    58,   228,
      58,   -51
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     1,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,     0,    26,     0,    12,    12,
      12,    16,     0,     0,    51,    53,    52,    80,    79,    81,
       0,     0,    92,     0,     0,     0,    30,    30,     0,     0,
      26,     2,    21,    26,     7,     8,     9,     0,     0,     0,
       0,    79,     0,    15,    13,    80,    79,    81,     0,     0,
       0,    70,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,   102,   103,   105,   104,   106,    94,    95,
      96,    97,    98,    99,   100,   101,     0,    93,    20,     0,
      31,    28,     0,     0,    26,    19,    18,    10,     0,     0,
       0,    17,    16,     0,    59,    82,     0,     0,    62,     0,
       0,     0,    78,    78,     0,     0,    67,    54,    36,    35,
      68,    55,    48,     0,    69,    56,     0,     0,     0,    30,
      30,    22,    12,    26,    26,    26,    14,    63,    64,     0,
       0,    78,    78,    71,    74,     0,    75,    33,     0,    34,
       0,     0,     0,     0,     0,     0,    38,    37,     0,     0,
       0,     0,    32,    29,    11,     0,     0,     0,    65,    66,
      76,    77,    73,    72,    44,    46,     0,     0,    86,    39,
      45,    47,    84,    40,    49,    50,     0,    41,    91,     0,
       0,     4,     5,     6,    42,    43,     0,     0,    90,    88,
       0,     0,    27,    85,    83,     0,     0,    26,    26,    89,
      87,     0,     0,    26,    26,     0,    24,    23,    26,     0,
      26,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -51,   233,   -51,   -51,   -28,   129,   -25,   -26,   -51,   -42,
     -51,   -50,   -12,    36,    41,   -44,   -37,   176,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    57,    58,    62,    24,    25,    26,    49,
      27,   118,    42,   193,   189,   197,    43,    96,   119
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    59,    60,    81,   100,   101,    63,    71,    97,    44,
     -57,    31,    65,    66,   132,    67,    75,    77,     7,    64,
      72,   122,   123,    10,   105,    76,    78,   106,   128,    31,
     129,    16,    68,   133,    17,    18,    19,   113,    83,    84,
      85,    86,    87,    20,    31,    31,    97,    69,    70,   225,
     126,     8,   130,    11,   134,   163,   124,   125,    13,   137,
       9,    21,    16,    22,    23,    17,    18,    19,    73,    74,
     158,   165,   157,   159,    20,     1,     2,     3,   141,    31,
      79,   210,   102,   103,   211,    46,    47,    63,    14,    80,
     114,   115,    21,    15,    22,    23,    32,   172,   173,   169,
      64,   180,   181,     4,    48,    33,    83,    84,    85,    86,
      87,    54,    55,    56,   174,   147,   148,   175,   176,   177,
      34,    88,    89,    90,    91,    92,    93,    94,    95,    37,
      38,    28,    39,    37,    38,    29,    39,    37,    61,    30,
      39,   153,    40,    35,   154,   151,   152,   166,   167,    41,
     182,   183,    36,    41,   184,   185,    45,    41,   190,   191,
      50,   155,    83,    84,    85,    86,    87,   194,   195,   208,
     209,   219,   220,    51,    53,    82,    98,    99,   104,   107,
     127,   139,   108,   120,   109,   110,    31,   112,   131,   111,
     116,   221,   222,   -60,   -61,   121,   117,   226,   227,   135,
     143,   138,   229,   144,   231,   140,   145,   -58,   149,   150,
     142,   156,   170,   160,   161,   171,   162,   178,   179,   164,
     186,   168,   187,   188,   199,   192,   196,   198,   200,   201,
     206,   207,   204,   202,   203,   215,   217,   212,   205,    12,
     216,   146,   218,   214,   223,   224,   228,   213,   230,     0,
       0,     0,     0,     0,     0,     0,     0,   136
};

static const yytype_int16 yycheck[] =
{
      26,    29,    30,    40,    46,    47,    31,    32,    43,    21,
      15,    16,     3,     4,     4,     6,    33,    33,    40,    31,
      32,     3,     4,    19,    50,    42,    42,    53,     4,    16,
       6,     4,    23,    23,     7,     8,     9,    42,    10,    11,
      12,    13,    14,    16,    16,    16,    81,    38,    39,    22,
      75,    40,    77,     0,    79,    42,    38,    39,     4,    96,
      40,    34,     4,    36,    37,     7,     8,     9,     3,     4,
      42,    42,   122,   123,    16,     7,     8,     9,   104,    16,
      33,    21,     4,     5,    24,     4,     5,   112,     4,    42,
       3,     4,    34,     4,    36,    37,    33,   139,   140,   136,
     112,   151,   152,    35,    23,    42,    10,    11,    12,    13,
      14,     7,     8,     9,   142,     3,     4,   143,   144,   145,
       4,    25,    26,    27,    28,    29,    30,    31,    32,     3,
       4,    16,     6,     3,     4,    16,     6,     3,     4,    16,
       6,     3,    16,     4,     6,     3,     4,     3,     4,    23,
       3,     4,     4,    23,     3,     4,    16,    23,     3,     4,
      15,    23,    10,    11,    12,    13,    14,     3,     4,     3,
       4,   215,   216,    20,    15,     4,    15,     4,    15,     4,
       3,    23,    17,    33,    17,    17,    16,    41,     3,    17,
      16,   217,   218,    15,    15,    33,    16,   223,   224,     3,
      19,    41,   228,    19,   230,    23,    19,    15,     4,     4,
      41,     4,    17,    16,    16,     3,    33,    17,    17,    33,
       4,    33,     4,     3,    18,     6,    23,    17,    17,    20,
      41,    41,    17,    20,    20,    41,    19,    15,    17,     6,
      41,   112,    19,   207,    20,    20,    19,   206,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    35,    44,    45,    40,    40,    40,
      19,     0,    44,     4,     4,     4,     4,     7,     8,     9,
      16,    34,    36,    37,    49,    50,    51,    53,    16,    16,
      16,    16,    33,    42,     4,     4,     4,     3,     4,     6,
      16,    23,    55,    59,    55,    16,     4,     5,    23,    52,
      15,    20,    50,    15,     7,     8,     9,    46,    47,    47,
      47,     4,    48,    49,    55,     3,     4,     6,    23,    38,
      39,    49,    55,     3,     4,    33,    42,    33,    42,    33,
      42,    59,     4,    10,    11,    12,    13,    14,    25,    26,
      27,    28,    29,    30,    31,    32,    60,    61,    15,     4,
      52,    52,     4,     5,    15,    50,    50,     4,    17,    17,
      17,    17,    41,    42,     3,     4,    16,    16,    54,    61,
      33,    33,     3,     4,    38,    39,    49,     3,     4,     6,
      49,     3,     4,    23,    49,     3,    60,    59,    41,    23,
      23,    50,    41,    19,    19,    19,    48,     3,     4,     4,
       4,     3,     4,     3,     6,    23,     4,    54,    42,    54,
      16,    16,    33,    42,    33,    42,     3,     4,    33,    59,
      17,     3,    52,    52,    47,    50,    50,    50,    17,    17,
      54,    54,     3,     4,     3,     4,     4,     4,     3,    57,
       3,     4,     6,    56,     3,     4,    23,    58,    17,    18,
      17,    20,    20,    20,    17,    17,    41,    41,     3,     4,
      21,    24,    15,    57,    56,    41,    41,    19,    19,    58,
      58,    50,    50,    20,    20,    22,    50,    50,    19,    50,
      20,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    45,    46,    46,    46,
      47,    47,    47,    48,    48,    48,    48,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    52,    52,
      52,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    54,    54,    54,    55,
      55,    55,    55,    56,    56,    57,    57,    58,    58,    58,
      58,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    61,    61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     2,     9,     9,     9,     1,     1,     1,
       2,     4,     0,     1,     3,     1,     0,     4,     3,     3,
       3,     2,     4,    11,    11,    15,     0,     7,     2,     4,
       0,     2,     4,     5,     5,     4,     4,     5,     5,     6,
       6,     6,     7,     7,     6,     6,     6,     6,     4,     6,
       6,     2,     2,     2,     4,     4,     4,     3,     4,     4,
       3,     3,     4,     5,     5,     6,     6,     4,     4,     4,
       3,     5,     6,     6,     5,     5,     3,     3,     0,     1,
       1,     1,     2,     3,     1,     3,     1,     4,     2,     4,
       2,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
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
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
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

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
#line 1564 "y.tab.c"
    break;

  case 3:
#line 63 "grammar.y"
                                    { (yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))+3); sprintf((yyval.stringValue),"%s\n%s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1570 "y.tab.c"
    break;

  case 4:
#line 67 "grammar.y"
                                                                        {if(checkIfFunctionExists((yyvsp[-6].stringValue))){yyerror("Function already declared."); YYABORT;} if(!checkReturnType((yyvsp[-1].stringValue),KIND_INT)){yyerror("Wrong return type"); YYABORT;}(yyval.stringValue) = malloc(3+strlen((yyvsp[-6].stringValue))+strlen((yyvsp[-4].stringValue))+strlen((yyvsp[-1].stringValue))+ 8); sprintf((yyval.stringValue), "%s %s(%s){\n%s}\n", "int", (yyvsp[-6].stringValue), (yyvsp[-4].stringValue), (yyvsp[-1].stringValue)); add((yyval.stringValue),true); addFunction((yyvsp[-6].stringValue),KIND_INT,(yyvsp[-4].stringValue)); freeVars();}
#line 1576 "y.tab.c"
    break;

  case 5:
#line 68 "grammar.y"
                                                                        {if(checkIfFunctionExists((yyvsp[-6].stringValue))){yyerror("Function already declared."); YYABORT;} if(!checkReturnType((yyvsp[-1].stringValue),KIND_STRING)){yyerror("Wrong return type"); YYABORT;}(yyval.stringValue) = malloc(7+strlen((yyvsp[-6].stringValue))+strlen((yyvsp[-4].stringValue))+strlen((yyvsp[-1].stringValue))+ 8); sprintf((yyval.stringValue), "%s %s(%s){\n%s}\n", "char *", (yyvsp[-6].stringValue), (yyvsp[-4].stringValue), (yyvsp[-1].stringValue)); add((yyval.stringValue),true); addFunction((yyvsp[-6].stringValue),KIND_STRING,(yyvsp[-4].stringValue));freeVars();}
#line 1582 "y.tab.c"
    break;

  case 6:
#line 69 "grammar.y"
                                                                         {if(checkIfFunctionExists((yyvsp[-6].stringValue))){yyerror("Function already declared."); YYABORT;} if(!checkReturnType((yyvsp[-1].stringValue),KIND_CHAR)){yyerror("Wrong return type"); YYABORT;}(yyval.stringValue) = malloc(4+strlen((yyvsp[-6].stringValue))+strlen((yyvsp[-4].stringValue))+strlen((yyvsp[-1].stringValue))+ 8); sprintf((yyval.stringValue), "%s %s(%s){\n%s}\n", "char", (yyvsp[-6].stringValue), (yyvsp[-4].stringValue), (yyvsp[-1].stringValue)); add((yyval.stringValue),true); addFunction((yyvsp[-6].stringValue),KIND_CHAR,(yyvsp[-4].stringValue)); freeVars();}
#line 1588 "y.tab.c"
    break;

  case 7:
#line 73 "grammar.y"
                {(yyval.stringValue) = "int";}
#line 1594 "y.tab.c"
    break;

  case 8:
#line 74 "grammar.y"
                {(yyval.stringValue) = "char *";}
#line 1600 "y.tab.c"
    break;

  case 9:
#line 75 "grammar.y"
                {(yyval.stringValue) = "char";}
#line 1606 "y.tab.c"
    break;

  case 10:
#line 79 "grammar.y"
                                { (yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue)) +2); sprintf((yyval.stringValue), "%s %s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true); if(strcmp((yyvsp[-1].stringValue),"int")==0){addVar((yyvsp[0].stringValue), KIND_INT,1);}else{addVar((yyvsp[0].stringValue), KIND_STRING,1);}}
#line 1612 "y.tab.c"
    break;

  case 11:
#line 80 "grammar.y"
                                { (yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+strlen((yyvsp[-2].stringValue))+4+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s %s, %s", (yyvsp[-3].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);if(strcmp((yyvsp[-3].stringValue),"int")==0){addVar((yyvsp[-2].stringValue), KIND_INT,1);}else{addVar((yyvsp[-2].stringValue), KIND_STRING,1);}}
#line 1618 "y.tab.c"
    break;

  case 12:
#line 81 "grammar.y"
                                { (yyval.stringValue) = ""; }
#line 1624 "y.tab.c"
    break;

  case 13:
#line 85 "grammar.y"
                                { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+1); sprintf((yyval.stringValue), "%s", (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1630 "y.tab.c"
    break;

  case 14:
#line 86 "grammar.y"
                                { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+2+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s,%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1636 "y.tab.c"
    break;

  case 15:
#line 87 "grammar.y"
                                { (yyval.stringValue) = (yyvsp[0].stringValue);}
#line 1642 "y.tab.c"
    break;

  case 16:
#line 88 "grammar.y"
                                { (yyval.stringValue) = "";}
#line 1648 "y.tab.c"
    break;

  case 17:
#line 92 "grammar.y"
                                 {if(!checkArgsOk((yyvsp[-3].stringValue),(yyvsp[-1].stringValue))){yyerror("Incompatible args for function"); YYABORT;} (yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+3+strlen((yyvsp[-1].stringValue))); sprintf((yyval.stringValue),"%s(%s)",(yyvsp[-3].stringValue),(yyvsp[-1].stringValue)); add((yyval.stringValue),true);}
#line 1654 "y.tab.c"
    break;

  case 18:
#line 96 "grammar.y"
                                                            { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+3+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s; %s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1660 "y.tab.c"
    break;

  case 19:
#line 97 "grammar.y"
                                                            { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+3+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s; %s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1666 "y.tab.c"
    break;

  case 20:
#line 98 "grammar.y"
                                                            { (yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue)) +9); sprintf((yyval.stringValue), "return %s;", (yyvsp[-1].stringValue)); add((yyval.stringValue),true);}
#line 1672 "y.tab.c"
    break;

  case 21:
#line 99 "grammar.y"
                                                            { (yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))+5); sprintf((yyval.stringValue),"%s %s",(yyvsp[-1].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue), true);}
#line 1678 "y.tab.c"
    break;

  case 22:
#line 100 "grammar.y"
                                                            { char * print = printfParser((yyvsp[-2].stringValue)); if(print==NULL){yyerror("Sintax error on P.\n Check if your variables exist."); YYABORT;} (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))*2+5+strlen((yyvsp[0].stringValue))+ 11); sprintf((yyval.stringValue), "printf(%s);\n%s", print, (yyvsp[0].stringValue)); add((yyval.stringValue),true); free(print);}
#line 1684 "y.tab.c"
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
#line 1697 "y.tab.c"
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
#line 1710 "y.tab.c"
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
#line 1723 "y.tab.c"
    break;

  case 26:
#line 125 "grammar.y"
                                                            { (yyval.stringValue) = "";}
#line 1729 "y.tab.c"
    break;

  case 27:
#line 129 "grammar.y"
                                                    { if(checkIfVarExists((yyvsp[-4].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}  (yyval.stringValue) = malloc(2*strlen((yyvsp[-4].stringValue))+2*strlen((yyvsp[-2].stringValue))+ 30); sprintf((yyval.stringValue),"char %s[%s];\nfgets(%s,%s,stdin);\n",(yyvsp[-4].stringValue),(yyvsp[-2].stringValue),(yyvsp[-4].stringValue),(yyvsp[-2].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-4].stringValue), KIND_ARRAY_CHAR,1);}
#line 1735 "y.tab.c"
    break;

  case 28:
#line 133 "grammar.y"
                                        { (yyval.stringValue) = malloc(1 + strlen((yyvsp[-1].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s%s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1741 "y.tab.c"
    break;

  case 29:
#line 134 "grammar.y"
                                        { (yyval.stringValue) = malloc(3 + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "\'%s\'%s", (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1747 "y.tab.c"
    break;

  case 30:
#line 135 "grammar.y"
                                        { (yyval.stringValue) = ""; }
#line 1753 "y.tab.c"
    break;

  case 31:
#line 136 "grammar.y"
                                        { (yyval.stringValue) = malloc(1 + strlen((yyvsp[-1].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s%s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1759 "y.tab.c"
    break;

  case 32:
#line 137 "grammar.y"
                                        { (yyval.stringValue) = malloc(3 + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "\'%s\'%s", (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1765 "y.tab.c"
    break;

  case 33:
#line 142 "grammar.y"
                                                    { if(checkIfVarExists((yyvsp[-3].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;} (yyval.stringValue) = malloc(3+strlen((yyvsp[-3].stringValue))+6+strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s=%s%s","int",(yyvsp[-3].stringValue),(yyvsp[-1].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-3].stringValue), KIND_INT,1);}
#line 1771 "y.tab.c"
    break;

  case 34:
#line 143 "grammar.y"
                                                    { if(checkIfVarExists((yyvsp[-3].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!isOfKind((yyvsp[-1].stringValue),KIND_INT)){yyerror("Variable should be int type."); YYABORT;}(yyval.stringValue) = malloc(3+strlen((yyvsp[-3].stringValue))+6+strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s=%s%s","int",(yyvsp[-3].stringValue),(yyvsp[-1].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-3].stringValue), KIND_INT,1);}
#line 1777 "y.tab.c"
    break;

  case 35:
#line 144 "grammar.y"
                                                    { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}(yyval.stringValue) = malloc(7+strlen((yyvsp[-2].stringValue))+6+strlen((yyvsp[0].stringValue))); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0;sprintf((yyval.stringValue),"%s %s=\"%s\"","char *",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)+1); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_STRING,1);}
#line 1783 "y.tab.c"
    break;

  case 36:
#line 145 "grammar.y"
                                                    { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!isOfKind((yyvsp[0].stringValue),KIND_STRING)){yyerror("Variable should be string type"); YYABORT;}(yyval.stringValue) = malloc(7+strlen((yyvsp[-2].stringValue))+6+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s=%s","char *",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_STRING,1);}
#line 1789 "y.tab.c"
    break;

  case 37:
#line 146 "grammar.y"
                                                    { if(strlen((yyvsp[0].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}if(checkIfVarExists((yyvsp[-3].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}(yyval.stringValue) = malloc(7+strlen((yyvsp[-3].stringValue))+6+strlen((yyvsp[0].stringValue)));sprintf((yyval.stringValue),"char %s=\'%s\'",(yyvsp[-3].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-3].stringValue), KIND_CHAR,1);}
#line 1795 "y.tab.c"
    break;

  case 38:
#line 147 "grammar.y"
                                                    { if(strlen((yyvsp[0].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}if(checkIfVarExists((yyvsp[-3].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}(yyval.stringValue) = malloc(7+strlen((yyvsp[-3].stringValue))+6+strlen((yyvsp[0].stringValue)));sprintf((yyval.stringValue),"char %s=\'%s\'",(yyvsp[-3].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-3].stringValue), KIND_CHAR,1);}
#line 1801 "y.tab.c"
    break;

  case 39:
#line 148 "grammar.y"
                                                    { if(checkIfVarExists((yyvsp[-4].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(array_is_incorrect((yyvsp[0].stringValue),atoi((yyvsp[-2].stringValue)))){yyerror("Bad initialization of array"); YYABORT;} (yyval.stringValue) = malloc(3+strlen((yyvsp[-4].stringValue))+10+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]={%s}","int",(yyvsp[-4].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-4].stringValue), KIND_ARRAY_INT,atoi((yyvsp[-2].stringValue))); }
#line 1807 "y.tab.c"
    break;

  case 40:
#line 149 "grammar.y"
                                                    { if(checkIfVarExists((yyvsp[-4].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(array_is_incorrect((yyvsp[0].stringValue),atoi((yyvsp[-2].stringValue)))){yyerror("Bad initialization of array"); YYABORT;} (yyval.stringValue) = malloc(7+strlen((yyvsp[-4].stringValue))+10+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]={%s}","char *",(yyvsp[-4].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-4].stringValue), KIND_ARRAY_STRING,atoi((yyvsp[-2].stringValue)));}
#line 1813 "y.tab.c"
    break;

  case 41:
#line 150 "grammar.y"
                                                    { if(checkIfVarExists((yyvsp[-4].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(array_is_incorrect((yyvsp[0].stringValue),atoi((yyvsp[-2].stringValue)))){yyerror("Bad initialization of array"); YYABORT;} (yyval.stringValue) = malloc(7+strlen((yyvsp[-4].stringValue))+10+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]={%s}","char",(yyvsp[-4].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-4].stringValue), KIND_ARRAY_CHAR,atoi((yyvsp[-2].stringValue)));}
#line 1819 "y.tab.c"
    break;

  case 42:
#line 151 "grammar.y"
                                                    { if(!isOfKind((yyvsp[-1].stringValue),KIND_STRING) && !isOfKind((yyvsp[-1].stringValue),KIND_ARRAY_CHAR)){yyerror("Variable to convert should be string type."); YYABORT;} (yyval.stringValue) = malloc(7+strlen((yyvsp[-1].stringValue))+3+strlen((yyvsp[-5].stringValue))+6); sprintf((yyval.stringValue),"int %s = atoi(%s)",(yyvsp[-5].stringValue),(yyvsp[-1].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-5].stringValue), KIND_INT,1);}
#line 1825 "y.tab.c"
    break;

  case 43:
#line 152 "grammar.y"
                                                    { if(!isOfKind((yyvsp[-1].stringValue),KIND_STRING) && !isOfKind((yyvsp[-1].stringValue),KIND_ARRAY_CHAR)){yyerror("Variable should be string type."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue))+strlen((yyvsp[-5].stringValue)) +15); sprintf((yyval.stringValue),"int %s=strlen(%s)",(yyvsp[-5].stringValue), (yyvsp[-1].stringValue)); add((yyval.stringValue),true);addVar((yyvsp[-5].stringValue), KIND_INT,1);}
#line 1831 "y.tab.c"
    break;

  case 44:
#line 153 "grammar.y"
                                                    { if(!correctArray((yyvsp[-2].stringValue),KIND_ARRAY_INT,atoi((yyvsp[0].stringValue)))){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(3+strlen((yyvsp[-4].stringValue))+6+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "int %s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);addVar((yyvsp[-4].stringValue), KIND_INT,1);}
#line 1837 "y.tab.c"
    break;

  case 45:
#line 154 "grammar.y"
                                                    { if(!correctArray((yyvsp[-2].stringValue),KIND_ARRAY_STRING,atoi((yyvsp[0].stringValue)))){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(7+strlen((yyvsp[-4].stringValue))+6+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "char * %s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);addVar((yyvsp[-4].stringValue), KIND_STRING,1);}
#line 1843 "y.tab.c"
    break;

  case 46:
#line 155 "grammar.y"
                                                    { if(!isOfKind((yyvsp[0].stringValue),KIND_INT)){yyerror("Variable should be int type to de-reference.");YYABORT;}if(!isOfKind((yyvsp[-2].stringValue),KIND_ARRAY_INT)){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(3+strlen((yyvsp[-4].stringValue))+6+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "int %s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);addVar((yyvsp[-4].stringValue), KIND_INT,1);}
#line 1849 "y.tab.c"
    break;

  case 47:
#line 156 "grammar.y"
                                                    { if(!isOfKind((yyvsp[0].stringValue),KIND_INT)){yyerror("Variable should be int type to de-reference.");YYABORT;}if(!isOfKind((yyvsp[-2].stringValue),KIND_ARRAY_STRING)){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(7+strlen((yyvsp[-4].stringValue))+6+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "char * %s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);addVar((yyvsp[-4].stringValue), KIND_STRING,1);}
#line 1855 "y.tab.c"
    break;

  case 48:
#line 157 "grammar.y"
                                                    { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!isOfKind((yyvsp[0].stringValue),KIND_CHAR)){yyerror("Variable should be char type."); YYABORT;}(yyval.stringValue) = malloc(4+strlen((yyvsp[-2].stringValue))+6+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s=%s","char",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_CHAR,1);}
#line 1861 "y.tab.c"
    break;

  case 49:
#line 158 "grammar.y"
                                                    { if(!correctArray((yyvsp[-2].stringValue),KIND_ARRAY_CHAR,atoi((yyvsp[0].stringValue)))){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(4+strlen((yyvsp[-4].stringValue))+6+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "char %s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);addVar((yyvsp[-4].stringValue), KIND_CHAR,1);}
#line 1867 "y.tab.c"
    break;

  case 50:
#line 159 "grammar.y"
                                                    { if(!isOfKind((yyvsp[0].stringValue),KIND_INT)){yyerror("Variable should be int type to de-reference.");YYABORT;}if(!isOfKind((yyvsp[-2].stringValue),KIND_ARRAY_CHAR)){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(4+strlen((yyvsp[-4].stringValue))+6+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "char %s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);addVar((yyvsp[-4].stringValue), KIND_CHAR,1);}
#line 1873 "y.tab.c"
    break;

  case 51:
#line 161 "grammar.y"
                                                { if(checkIfVarExists((yyvsp[0].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}(yyval.stringValue) = malloc(3+strlen((yyvsp[0].stringValue))+2); sprintf((yyval.stringValue),"%s %s","int",(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[0].stringValue), KIND_INT,1);}
#line 1879 "y.tab.c"
    break;

  case 52:
#line 162 "grammar.y"
                                                { if(checkIfVarExists((yyvsp[0].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}(yyval.stringValue) = malloc(5+strlen((yyvsp[0].stringValue))+2); sprintf((yyval.stringValue),"char %s",(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[0].stringValue), KIND_CHAR,1);}
#line 1885 "y.tab.c"
    break;

  case 53:
#line 163 "grammar.y"
                                                { if(checkIfVarExists((yyvsp[0].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}(yyval.stringValue) = malloc(7+strlen((yyvsp[0].stringValue))+2); sprintf((yyval.stringValue),"%s %s","char *",(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[0].stringValue), KIND_STRING,1);}
#line 1891 "y.tab.c"
    break;

  case 54:
#line 164 "grammar.y"
                                                { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;} (yyval.stringValue) = malloc(3+strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]","int",(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_ARRAY_INT,atoi((yyvsp[0].stringValue))); }
#line 1897 "y.tab.c"
    break;

  case 55:
#line 165 "grammar.y"
                                                { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;} (yyval.stringValue) = malloc(7+strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]","char *",(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_ARRAY_STRING,atoi((yyvsp[0].stringValue)));}
#line 1903 "y.tab.c"
    break;

  case 56:
#line 166 "grammar.y"
                                                { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;} (yyval.stringValue) = malloc(4+strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]","char",(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_ARRAY_CHAR,atoi((yyvsp[0].stringValue))); }
#line 1909 "y.tab.c"
    break;

  case 57:
#line 168 "grammar.y"
                                                { if((!checkIfVarExists((yyvsp[-2].stringValue))||!checkIfVarExists((yyvsp[0].stringValue)))|| !are_comparable((yyvsp[-2].stringValue),(yyvsp[0].stringValue))){yyerror("Variables aren't compatible."); YYABORT;}(yyval.stringValue) = malloc(4+strlen((yyvsp[-2].stringValue))+6+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s=%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1915 "y.tab.c"
    break;

  case 58:
#line 169 "grammar.y"
                                                { if(!isOfKind((yyvsp[-3].stringValue),KIND_CHAR)){yyerror("Variable should be int type.");YYABORT;}if(strlen((yyvsp[0].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+strlen((yyvsp[0].stringValue))+10); sprintf((yyval.stringValue), "%s=\'%s\'", (yyvsp[-3].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1921 "y.tab.c"
    break;

  case 59:
#line 170 "grammar.y"
                                                { if(!isOfKind((yyvsp[-3].stringValue),KIND_CHAR)){yyerror("Variable should be int type.");YYABORT;}if(strlen((yyvsp[0].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+strlen((yyvsp[0].stringValue))+10); sprintf((yyval.stringValue), "%s=\'%s\'", (yyvsp[-3].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1927 "y.tab.c"
    break;

  case 60:
#line 171 "grammar.y"
                                                { if(!isOfKind((yyvsp[-2].stringValue),KIND_INT)){yyerror("Variable should be int type.");YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))+5); sprintf((yyval.stringValue), "%s=%s", (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1933 "y.tab.c"
    break;

  case 61:
#line 172 "grammar.y"
                                                { if(!isOfKind((yyvsp[-2].stringValue),KIND_STRING)){yyerror("Variable should be string type.");YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))+5); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0;sprintf((yyval.stringValue), "%s=\"%s\"", (yyvsp[-2].stringValue), (yyvsp[0].stringValue)+1); add((yyval.stringValue),true);}
#line 1939 "y.tab.c"
    break;

  case 62:
#line 173 "grammar.y"
                                                { if(!isOfKind((yyvsp[-3].stringValue),KIND_INT)){yyerror("Variable should be int type."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))+5);  sprintf((yyval.stringValue), "%s=%s%s", (yyvsp[-3].stringValue), (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1945 "y.tab.c"
    break;

  case 63:
#line 174 "grammar.y"
                                                { if(!compatibleArray((yyvsp[-4].stringValue),(yyvsp[-2].stringValue),atoi((yyvsp[0].stringValue)))){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-4].stringValue))+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue)) +5); sprintf((yyval.stringValue), "%s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1951 "y.tab.c"
    break;

  case 64:
#line 175 "grammar.y"
                                                { if(!isOfKind((yyvsp[0].stringValue),KIND_INT)){yyerror("Variable should be int type to de-reference.");YYABORT;}if(!compatibleArray((yyvsp[-4].stringValue),(yyvsp[-2].stringValue),0)){yyerror("Variables aren't compatible.");YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-4].stringValue))+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue)) +5); sprintf((yyval.stringValue), "%s=%s[%s]", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1957 "y.tab.c"
    break;

  case 65:
#line 176 "grammar.y"
                                                { if(!isOfKind((yyvsp[-5].stringValue),KIND_INT)){yyerror("Variable to assign should be int type."); YYABORT;} if(!isOfKind((yyvsp[-1].stringValue),KIND_STRING) && !isOfKind((yyvsp[-1].stringValue),KIND_ARRAY_CHAR)){yyerror("Argument should be string type."); YYABORT;} (yyval.stringValue) = malloc(strlen((yyvsp[-5].stringValue))+strlen((yyvsp[-1].stringValue))+10); sprintf((yyval.stringValue),"%s = atoi(%s)",(yyvsp[-5].stringValue),(yyvsp[-1].stringValue)); add((yyval.stringValue),true);}
#line 1963 "y.tab.c"
    break;

  case 66:
#line 177 "grammar.y"
                                                { if(!isOfKind((yyvsp[-5].stringValue),KIND_INT)){yyerror("Variable to assign should be int type."); YYABORT;} if(!isOfKind((yyvsp[-1].stringValue),KIND_STRING) && !isOfKind((yyvsp[-1].stringValue),KIND_ARRAY_CHAR)){yyerror("Argument hould be string type."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-5].stringValue))+strlen((yyvsp[-1].stringValue))+10); sprintf((yyval.stringValue),"%s=strlen(%s)",(yyvsp[-5].stringValue), (yyvsp[-1].stringValue)); add((yyval.stringValue),true);}
#line 1969 "y.tab.c"
    break;

  case 67:
#line 180 "grammar.y"
                                                { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!functionReturnsKind((yyvsp[0].stringValue), KIND_INT)){yyerror("Function should return type int"); YYABORT;} (yyval.stringValue) = malloc(3+strlen((yyvsp[-2].stringValue))+3+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"int %s=%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_INT,1);}
#line 1975 "y.tab.c"
    break;

  case 68:
#line 181 "grammar.y"
                                                { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!functionReturnsKind((yyvsp[0].stringValue), KIND_STRING)){yyerror("Function should return type string"); YYABORT;} (yyval.stringValue) = malloc(7+strlen((yyvsp[-2].stringValue))+3+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"char* %s=%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_STRING,1);}
#line 1981 "y.tab.c"
    break;

  case 69:
#line 182 "grammar.y"
                                                { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!functionReturnsKind((yyvsp[0].stringValue), KIND_CHAR)){yyerror("Function should return type char"); YYABORT;} (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+8+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"char %s=%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_CHAR,1);}
#line 1987 "y.tab.c"
    break;

  case 70:
#line 183 "grammar.y"
                                                { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+2+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s=%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1993 "y.tab.c"
    break;

  case 71:
#line 186 "grammar.y"
                                                { if (!isOfKind((yyvsp[-4].stringValue), KIND_ARRAY_INT)){yyerror("Variable should be string array type"); YYABORT;} if(! enoughSpace((yyvsp[-4].stringValue), atoi((yyvsp[-2].stringValue))) ) { yyerror("Array has not enough space"); YYABORT; } (yyval.stringValue) = malloc(strlen((yyvsp[-4].stringValue)) + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue)) + 4 ); sprintf((yyval.stringValue), "%s[%s]=%s", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue), true); }
#line 1999 "y.tab.c"
    break;

  case 72:
#line 187 "grammar.y"
                                                 { if (!isOfKind((yyvsp[-5].stringValue), KIND_ARRAY_CHAR)){yyerror("Variable should be char array type"); YYABORT;} if(! enoughSpace((yyvsp[-5].stringValue), atoi((yyvsp[-3].stringValue))) ) { yyerror("Array has not enough space"); YYABORT; } if(strlen((yyvsp[0].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-5].stringValue)) + strlen((yyvsp[-3].stringValue)) + strlen((yyvsp[0].stringValue)) + 10 ); sprintf((yyval.stringValue), "%s[%s]=\'%s\'", (yyvsp[-5].stringValue), (yyvsp[-3].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue), true); }
#line 2005 "y.tab.c"
    break;

  case 73:
#line 188 "grammar.y"
                                                 { if (!isOfKind((yyvsp[-5].stringValue), KIND_ARRAY_CHAR)){yyerror("Variable should be char array type"); YYABORT;} if(! enoughSpace((yyvsp[-5].stringValue), atoi((yyvsp[-3].stringValue))) ) { yyerror("Array has not enough space"); YYABORT; } if(strlen((yyvsp[0].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-5].stringValue)) + strlen((yyvsp[-3].stringValue)) + strlen((yyvsp[0].stringValue)) + 10 ); sprintf((yyval.stringValue), "%s[%s]=\'%s\'", (yyvsp[-5].stringValue), (yyvsp[-3].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue), true); }
#line 2011 "y.tab.c"
    break;

  case 74:
#line 189 "grammar.y"
                                                { if (!isOfKind((yyvsp[-4].stringValue), KIND_ARRAY_STRING)){yyerror("Variable should be string array type"); YYABORT;} if(! enoughSpace((yyvsp[-4].stringValue), atoi((yyvsp[-2].stringValue))) ) { yyerror("Array has not enough space"); YYABORT; } (yyval.stringValue) = malloc(strlen((yyvsp[-4].stringValue)) + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue)) + 4 ); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0; sprintf((yyval.stringValue), "%s[%s]=\"%s\"", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue)+1); add((yyval.stringValue), true); }
#line 2017 "y.tab.c"
    break;

  case 75:
#line 190 "grammar.y"
                                                { if(!compatibleArray((yyvsp[0].stringValue),(yyvsp[-4].stringValue),0)){yyerror("Variables aren't compatible.");YYABORT;} if(!isOfKind((yyvsp[-2].stringValue),KIND_INT)){yyerror("Variable should be int type."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-4].stringValue)) + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue)) + 4 ); sprintf((yyval.stringValue), "%s[%s]=%s", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue), true); }
#line 2023 "y.tab.c"
    break;

  case 76:
#line 194 "grammar.y"
                           { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+ 1 + strlen((yyvsp[-1].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s%s%s",(yyvsp[-2].stringValue),(yyvsp[-1].stringValue),(yyvsp[0].stringValue) ); add((yyval.stringValue),true);}
#line 2029 "y.tab.c"
    break;

  case 77:
#line 195 "grammar.y"
                           { if (!isOfKind((yyvsp[-1].stringValue), KIND_INT)){yyerror("Variable should be int type"); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+ 1 + strlen((yyvsp[-1].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s%s%s",(yyvsp[-2].stringValue),(yyvsp[-1].stringValue),(yyvsp[0].stringValue) ); add((yyval.stringValue),true);}
#line 2035 "y.tab.c"
    break;

  case 78:
#line 196 "grammar.y"
                           { (yyval.stringValue) = "";}
#line 2041 "y.tab.c"
    break;

  case 79:
#line 200 "grammar.y"
                    {(yyval.stringValue) = (yyvsp[0].stringValue);}
#line 2047 "y.tab.c"
    break;

  case 80:
#line 201 "grammar.y"
                    {(yyval.stringValue) = (yyvsp[0].stringValue);}
#line 2053 "y.tab.c"
    break;

  case 81:
#line 202 "grammar.y"
                    {
        (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1]  = '\"';
        (yyvsp[0].stringValue)[0]               = '\"';
        (yyval.stringValue) = (yyvsp[0].stringValue);
        }
#line 2063 "y.tab.c"
    break;

  case 82:
#line 207 "grammar.y"
                     { if(strlen((yyvsp[0].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+3); sprintf((yyval.stringValue), "\'%s\'", (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 2069 "y.tab.c"
    break;

  case 83:
#line 211 "grammar.y"
                                        { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); (yyvsp[-2].stringValue)[strlen((yyvsp[-2].stringValue)) - 1] = 0; sprintf((yyval.stringValue), "\"%s\",%s", (yyvsp[-2].stringValue)+1,(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 2075 "y.tab.c"
    break;

  case 84:
#line 212 "grammar.y"
                                        { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+5); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0; sprintf((yyval.stringValue), "\"%s\"", (yyvsp[0].stringValue)+1); add((yyval.stringValue),true);}
#line 2081 "y.tab.c"
    break;

  case 85:
#line 216 "grammar.y"
                                { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+2+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s,%s", (yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 2087 "y.tab.c"
    break;

  case 86:
#line 217 "grammar.y"
                                { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+1); sprintf((yyval.stringValue), "%s", (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 2093 "y.tab.c"
    break;

  case 87:
#line 221 "grammar.y"
                                    { if(strlen((yyvsp[-2].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "\'%s\',%s", (yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 2099 "y.tab.c"
    break;

  case 88:
#line 222 "grammar.y"
                   { if(strlen((yyvsp[0].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+5); sprintf((yyval.stringValue), "\'%s\'", (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 2105 "y.tab.c"
    break;

  case 89:
#line 223 "grammar.y"
                                    { if(strlen((yyvsp[-2].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "\'%s\',%s", (yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 2111 "y.tab.c"
    break;

  case 90:
#line 224 "grammar.y"
                   { if(strlen((yyvsp[0].stringValue))!=1){yyerror("Incompatible initialization for type char."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+5); sprintf((yyval.stringValue), "\'%s\'", (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 2117 "y.tab.c"
    break;

  case 91:
#line 228 "grammar.y"
                                        {   
                                            if(!are_comparable((yyvsp[-3].stringValue), (yyvsp[-1].stringValue))) {
                                                yyerror("Uncomparable data types");
                                                YYABORT;
                                            }
                                            (yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue)) + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[-1].stringValue)) + 5);
                                            sprintf((yyval.stringValue), "(%s %s %s)", (yyvsp[-3].stringValue), (yyvsp[-2].stringValue), (yyvsp[-1].stringValue));
                                            add((yyval.stringValue),true);}
#line 2130 "y.tab.c"
    break;

  case 92:
#line 237 "grammar.y"
                                        { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+1); sprintf((yyval.stringValue), "%s", (yyvsp[0].stringValue)); add((yyval.stringValue), true);}
#line 2136 "y.tab.c"
    break;

  case 93:
#line 246 "grammar.y"
            { (yyval.stringValue) = (yyvsp[0].stringValue);}
#line 2142 "y.tab.c"
    break;

  case 94:
#line 247 "grammar.y"
            { (yyval.stringValue) = "<";}
#line 2148 "y.tab.c"
    break;

  case 95:
#line 248 "grammar.y"
            { (yyval.stringValue) = ">";}
#line 2154 "y.tab.c"
    break;

  case 96:
#line 249 "grammar.y"
            { (yyval.stringValue) = "<=";}
#line 2160 "y.tab.c"
    break;

  case 97:
#line 250 "grammar.y"
            { (yyval.stringValue) = ">=";}
#line 2166 "y.tab.c"
    break;

  case 98:
#line 251 "grammar.y"
            { (yyval.stringValue) = "==";}
#line 2172 "y.tab.c"
    break;

  case 99:
#line 252 "grammar.y"
            { (yyval.stringValue) = "!=";}
#line 2178 "y.tab.c"
    break;

  case 100:
#line 253 "grammar.y"
            { (yyval.stringValue) = "||";}
#line 2184 "y.tab.c"
    break;

  case 101:
#line 254 "grammar.y"
            { (yyval.stringValue) = "&&";}
#line 2190 "y.tab.c"
    break;

  case 102:
#line 258 "grammar.y"
            { (yyval.stringValue) = "+";}
#line 2196 "y.tab.c"
    break;

  case 103:
#line 259 "grammar.y"
            { (yyval.stringValue) = "-";}
#line 2202 "y.tab.c"
    break;

  case 104:
#line 260 "grammar.y"
            { (yyval.stringValue) = "/";}
#line 2208 "y.tab.c"
    break;

  case 105:
#line 261 "grammar.y"
            { (yyval.stringValue) = "*";}
#line 2214 "y.tab.c"
    break;

  case 106:
#line 262 "grammar.y"
            { (yyval.stringValue) = "%";}
#line 2220 "y.tab.c"
    break;


#line 2224 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                  yystos[+*yyssp], yyvsp);
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
#line 265 "grammar.y"

