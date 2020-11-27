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
} 

#line 95 "y.tab.c"

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
    PLUS = 264,
    MINUS = 265,
    TIMES = 266,
    DIV = 267,
    MOD = 268,
    END = 269,
    OPEN_P = 270,
    CLOSE_P = 271,
    CONDITIONAL = 272,
    EXEC = 273,
    END_EXEC = 274,
    IF = 275,
    ELSE = 276,
    ESCAPE = 277,
    WHILE = 278,
    L = 279,
    G = 280,
    LE = 281,
    GE = 282,
    EQ = 283,
    NE = 284,
    NOT = 285,
    OR = 286,
    AND = 287,
    ASSIGN = 288,
    RETURN = 289,
    MAIN = 290,
    STDIN = 291,
    STDOUT = 292,
    FUNCTION = 293,
    COMMA = 294,
    ARRAY = 295
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
#define MOD 268
#define END 269
#define OPEN_P 270
#define CLOSE_P 271
#define CONDITIONAL 272
#define EXEC 273
#define END_EXEC 274
#define IF 275
#define ELSE 276
#define ESCAPE 277
#define WHILE 278
#define L 279
#define G 280
#define LE 281
#define GE 282
#define EQ 283
#define NE 284
#define NOT 285
#define OR 286
#define AND 287
#define ASSIGN 288
#define RETURN 289
#define MAIN 290
#define STDIN 291
#define STDOUT 292
#define FUNCTION 293
#define COMMA 294
#define ARRAY 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "grammar.y"

	char * stringValue;

#line 231 "y.tab.c"

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    74,    74,    75,    79,    80,    84,    85,    89,    90,
      91,    95,    96,    97,    98,   102,   106,   107,   108,   109,
     110,   111,   112,   120,   130,   131,   135,   136,   137,   138,
     139,   144,   145,   146,   147,   149,   150,   151,   152,   154,
     155,   156,   158,   159,   160,   162,   163,   168,   169,   173,
     174,   175,   183,   184,   188,   189,   193,   202,   206,   207,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     224,   225,   226,   227,   228
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "ALPHA", "SPACE_ALPHA",
  "STRING_VALUE", "INT", "STRING", "PLUS", "MINUS", "TIMES", "DIV", "MOD",
  "END", "OPEN_P", "CLOSE_P", "CONDITIONAL", "EXEC", "END_EXEC", "IF",
  "ELSE", "ESCAPE", "WHILE", "L", "G", "LE", "GE", "EQ", "NE", "NOT", "OR",
  "AND", "ASSIGN", "RETURN", "MAIN", "STDIN", "STDOUT", "FUNCTION",
  "COMMA", "ARRAY", "$accept", "start", "function", "type", "params",
  "args", "call", "program", "get", "out", "var", "operation",
  "assignment", "alpha_array", "digit_array", "rule", "arrow", "operator",
  "op", YY_NULLPTR
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
     295
};
# endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,   -16,    -6,    41,    79,     6,    81,    94,    11,   -92,
     -92,    84,    85,   -10,    97,    98,    25,    65,    88,    12,
      69,    86,    11,    92,    35,    35,    78,    83,   101,   -13,
      27,   -92,   -92,   -92,    25,   -92,    26,    95,   103,    12,
      12,    90,    96,    11,   -92,   -92,    11,   -92,   -92,   104,
      99,   100,   102,   105,   -92,    72,   106,   108,   -92,    52,
      80,    93,   109,    68,   111,    26,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
      25,   -92,   -92,    89,   -92,   -92,   107,   110,    11,   -92,
     -92,    91,   115,   117,   -92,    78,   -92,   116,    67,    52,
     102,   -92,   112,   -92,   -92,   113,    25,   121,   120,    12,
      12,   -92,    35,    11,    11,   -92,    52,   -92,   -92,   -92,
     122,   118,   123,   124,   126,   -92,   -92,   -92,   119,   125,
     -92,   114,   -92,   127,   -92,   -92,    70,   129,   -92,   -92,
     122,   118,   130,   -92,   131,   -92,   -92,   -92,    11,    11,
     128,   132,   133,    11,   134,   -92,    11,   136,    11,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    21,     1,
       3,     0,     0,     0,     0,     0,     0,     0,     0,    28,
       0,     0,    21,     0,    10,    10,    14,     0,     0,    35,
      36,    50,    49,    51,     0,    57,     0,     0,     0,    28,
      28,     0,     0,    21,     2,    19,    21,     6,     7,     0,
       0,     0,    49,     0,    13,    11,    50,    51,    44,    48,
       0,     0,     0,     0,     0,     0,    70,    71,    73,    72,
      74,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    60,    18,     0,    29,    26,     0,     0,    21,    17,
      16,     8,     0,     0,    15,    14,    41,     0,     0,    48,
       0,    42,    37,    32,    43,    38,     0,     0,     0,    28,
      28,    20,    10,    21,    21,    12,    48,    45,    46,    31,
       0,     0,     0,     0,     0,    30,    27,     9,     0,     0,
      47,    55,    33,    53,    34,    56,     0,     0,     4,     5,
       0,     0,     0,    58,     0,    25,    54,    52,    21,    21,
       0,     0,     0,    21,     0,    22,    21,     0,    21,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   135,   -92,   -92,   -24,    23,   -17,   -22,   -92,   -33,
     -92,   -91,   -15,     9,    16,   -31,   -92,   137,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    49,    50,    53,    20,    21,    22,    42,
      23,    96,    35,   134,   132,    36,   144,    80,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    51,    37,    65,    81,    26,    84,    85,   119,    54,
      58,    55,    59,     1,     2,    13,    39,    40,    14,    15,
      61,    89,     6,    27,    90,   130,    16,    62,    31,    32,
      28,    33,     7,    81,    41,    66,    67,    68,    69,    70,
      34,     3,    47,    48,   101,    17,   104,    18,    19,   107,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     8,
      63,    66,    67,    68,    69,    70,   111,    64,    31,    32,
     117,    33,   100,   118,   103,   122,   125,   126,    54,     9,
      55,    31,    52,    43,    33,    11,    56,    52,   127,    57,
     142,   128,   129,   143,    86,    87,    99,   100,    12,    24,
      25,    29,    30,    38,    60,    44,    46,    83,    91,    82,
      88,    95,   102,    98,   105,    92,    93,    26,   115,   116,
     -39,    94,   -40,   124,   133,   131,   150,   151,   108,   109,
     112,   155,   110,   113,   157,   114,   159,   123,   138,   135,
      10,   136,   137,   145,   139,   120,   121,   152,   148,   149,
     147,   153,   156,   140,   154,   158,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   106
};

static const yytype_int16 yycheck[] =
{
      22,    25,    17,    34,    36,    15,    39,    40,    99,    26,
      27,    26,    27,     7,     8,     4,     4,     5,     7,     8,
      33,    43,    38,    33,    46,   116,    15,    40,     3,     4,
      40,     6,    38,    65,    22,     9,    10,    11,    12,    13,
      15,    35,     7,     8,    61,    34,    63,    36,    37,    80,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    18,
      33,     9,    10,    11,    12,    13,    88,    40,     3,     4,
       3,     6,     4,     6,     6,   106,   109,   110,    95,     0,
      95,     3,     4,    14,     6,     4,     3,     4,   112,     6,
      20,   113,   114,    23,     4,     5,     3,     4,     4,    15,
      15,     4,     4,    15,     3,    19,    14,     4,     4,    14,
      14,    39,     3,    33,     3,    16,    16,    15,    95,     3,
      14,    16,    14,     3,     6,     3,   148,   149,    39,    22,
      39,   153,    22,    18,   156,    18,   158,    16,    19,    16,
       5,    17,    16,    14,    19,    33,    33,    19,    18,    18,
     141,    19,    18,    39,    21,    19,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,    35,    42,    43,    38,    38,    18,     0,
      42,     4,     4,     4,     7,     8,    15,    34,    36,    37,
      47,    48,    49,    51,    15,    15,    15,    33,    40,     4,
       4,     3,     4,     6,    15,    53,    56,    53,    15,     4,
       5,    22,    50,    14,    19,    48,    14,     7,     8,    44,
      45,    45,     4,    46,    47,    53,     3,     6,    47,    53,
       3,    33,    40,    33,    40,    56,     9,    10,    11,    12,
      13,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      58,    59,    14,     4,    50,    50,     4,     5,    14,    48,
      48,     4,    16,    16,    16,    39,    52,    59,    33,     3,
       4,    47,     3,     6,    47,     3,    58,    56,    39,    22,
      22,    48,    39,    18,    18,    46,     3,     3,     6,    52,
      33,    33,    56,    16,     3,    50,    50,    45,    48,    48,
      52,     3,    55,     6,    54,    16,    17,    16,    19,    19,
      39,    39,    20,    23,    57,    14,    55,    54,    18,    18,
      48,    48,    19,    19,    21,    48,    18,    48,    19,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    44,    44,    45,    45,
      45,    46,    46,    46,    46,    47,    48,    48,    48,    48,
      48,    48,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    52,    52,    53,
      53,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     2,     9,     9,     1,     1,     2,     4,
       0,     1,     3,     1,     0,     4,     3,     3,     3,     2,
       4,     0,    11,    15,     0,     7,     2,     4,     0,     2,
       4,     5,     4,     6,     6,     2,     2,     4,     4,     3,
       3,     4,     4,     4,     3,     5,     5,     3,     0,     1,
       1,     1,     3,     1,     3,     1,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
#line 74 "grammar.y"
                                    { if(!checkReturnType((yyvsp[-1].stringValue),KIND_INT)){yyerror("Wrong return type"); YYABORT;}(yyval.stringValue) = malloc(16 +  strlen((yyvsp[-1].stringValue))); sprintf((yyval.stringValue), "int main(){ %s }\n",(yyvsp[-1].stringValue)); add((yyval.stringValue), true);  }
#line 1516 "y.tab.c"
    break;

  case 3:
#line 75 "grammar.y"
                                    { (yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))+3); sprintf((yyval.stringValue),"%s\n%s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1522 "y.tab.c"
    break;

  case 4:
#line 79 "grammar.y"
                                                                        {if(checkIfFunctionExists((yyvsp[-6].stringValue))){yyerror("Function already declared."); YYABORT;} if(!checkReturnType((yyvsp[-1].stringValue),KIND_INT)){yyerror("Wrong return type"); YYABORT;}(yyval.stringValue) = malloc(strlen("int")+strlen((yyvsp[-6].stringValue))+strlen((yyvsp[-4].stringValue))+strlen((yyvsp[-1].stringValue))+ 8); sprintf((yyval.stringValue), "%s %s(%s){\n%s}\n", "int", (yyvsp[-6].stringValue), (yyvsp[-4].stringValue), (yyvsp[-1].stringValue)); add((yyval.stringValue),true); addFunction((yyvsp[-6].stringValue),KIND_INT,(yyvsp[-4].stringValue)); freeVars();}
#line 1528 "y.tab.c"
    break;

  case 5:
#line 80 "grammar.y"
                                                                        {if(checkIfFunctionExists((yyvsp[-6].stringValue))){yyerror("Function already declared."); YYABORT;} if(!checkReturnType((yyvsp[-1].stringValue),KIND_STRING)){yyerror("Wrong return type"); YYABORT;}(yyval.stringValue) = malloc(strlen("char *")+strlen((yyvsp[-6].stringValue))+strlen((yyvsp[-4].stringValue))+strlen((yyvsp[-1].stringValue))+ 8); sprintf((yyval.stringValue), "%s %s(%s){\n%s}\n", "char *", (yyvsp[-6].stringValue), (yyvsp[-4].stringValue), (yyvsp[-1].stringValue)); add((yyval.stringValue),true); addFunction((yyvsp[-6].stringValue),KIND_STRING,(yyvsp[-4].stringValue));freeVars();}
#line 1534 "y.tab.c"
    break;

  case 6:
#line 84 "grammar.y"
                {(yyval.stringValue) = "int";}
#line 1540 "y.tab.c"
    break;

  case 7:
#line 85 "grammar.y"
                {(yyval.stringValue) = "char *";}
#line 1546 "y.tab.c"
    break;

  case 8:
#line 89 "grammar.y"
                                { (yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue)) +2); sprintf((yyval.stringValue), "%s %s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true); if(strcmp((yyvsp[-1].stringValue),"int")==0){addVar((yyvsp[0].stringValue), KIND_INT,1);}else{addVar((yyvsp[0].stringValue), KIND_STRING,1);}}
#line 1552 "y.tab.c"
    break;

  case 9:
#line 90 "grammar.y"
                                { (yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+strlen((yyvsp[-2].stringValue))+4+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s %s, %s", (yyvsp[-3].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);if(strcmp((yyvsp[-3].stringValue),"int")==0){addVar((yyvsp[-2].stringValue), KIND_INT,1);}else{addVar((yyvsp[-2].stringValue), KIND_STRING,1);}}
#line 1558 "y.tab.c"
    break;

  case 10:
#line 91 "grammar.y"
                                { (yyval.stringValue) = ""; }
#line 1564 "y.tab.c"
    break;

  case 11:
#line 95 "grammar.y"
                                { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+1); sprintf((yyval.stringValue), "%s", (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1570 "y.tab.c"
    break;

  case 12:
#line 96 "grammar.y"
                                { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+2+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s,%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1576 "y.tab.c"
    break;

  case 13:
#line 97 "grammar.y"
                                { (yyval.stringValue) = (yyvsp[0].stringValue);}
#line 1582 "y.tab.c"
    break;

  case 14:
#line 98 "grammar.y"
                                { (yyval.stringValue) = "";}
#line 1588 "y.tab.c"
    break;

  case 15:
#line 102 "grammar.y"
                                 {if(!checkArgsOk((yyvsp[-3].stringValue),(yyvsp[-1].stringValue))){yyerror("Incompatible args for function"); YYABORT;} (yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+3+strlen((yyvsp[-1].stringValue))); sprintf((yyval.stringValue),"%s(%s)",(yyvsp[-3].stringValue),(yyvsp[-1].stringValue)); add((yyval.stringValue),true);}
#line 1594 "y.tab.c"
    break;

  case 16:
#line 106 "grammar.y"
                                                            { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+3+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s; %s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1600 "y.tab.c"
    break;

  case 17:
#line 107 "grammar.y"
                                                            { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+3+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s; %s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1606 "y.tab.c"
    break;

  case 18:
#line 108 "grammar.y"
                                                            { (yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue)) +9); sprintf((yyval.stringValue), "return %s;", (yyvsp[-1].stringValue)); add((yyval.stringValue),true);}
#line 1612 "y.tab.c"
    break;

  case 19:
#line 109 "grammar.y"
                                                            { (yyval.stringValue) = malloc(strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))+5); sprintf((yyval.stringValue),"%s %s",(yyvsp[-1].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue), true);}
#line 1618 "y.tab.c"
    break;

  case 20:
#line 110 "grammar.y"
                                                            { char * print = printfParser((yyvsp[-2].stringValue)); if(print==NULL){yyerror("Sintax error on P.\n Check if your variables exist."); YYABORT;} (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))*2+5+strlen((yyvsp[0].stringValue))+ 11); sprintf((yyval.stringValue), "printf(%s);\n%s", print, (yyvsp[0].stringValue)); add((yyval.stringValue),true); free(print);}
#line 1624 "y.tab.c"
    break;

  case 21:
#line 111 "grammar.y"
                                                            { (yyval.stringValue) = "";}
#line 1630 "y.tab.c"
    break;

  case 22:
#line 112 "grammar.y"
                                                                                        {   
                                                                                            if(!are_comparable((yyvsp[-9].stringValue), (yyvsp[-7].stringValue))) {
                                                                                                yyerror("Uncomparable data types");
                                                                                                YYABORT;
                                                                                            }
                                                                                            (yyval.stringValue) = malloc(strlen((yyvsp[-9].stringValue))+10+strlen((yyvsp[-8].stringValue))+strlen((yyvsp[-7].stringValue))+strlen((yyvsp[-4].stringValue))+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue)));
                                                                                            sprintf((yyval.stringValue),"%s(%s %s %s){%s}\n%s ",(yyvsp[-4].stringValue),(yyvsp[-9].stringValue),(yyvsp[-8].stringValue),(yyvsp[-7].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue));
                                                                                            add((yyval.stringValue),true);}
#line 1643 "y.tab.c"
    break;

  case 23:
#line 120 "grammar.y"
                                                                                                                {   
                                                                                                                        if(!are_comparable((yyvsp[-13].stringValue), (yyvsp[-11].stringValue))) {
                                                                                                                            yyerror("Uncomparable data types");
                                                                                                                            YYABORT;
                                                                                                                        }
                                                                                                                        (yyval.stringValue) = malloc(25+strlen((yyvsp[-13].stringValue))+strlen((yyvsp[-12].stringValue))+strlen((yyvsp[-11].stringValue))+strlen((yyvsp[-6].stringValue))+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue)));
                                                                                                                        sprintf((yyval.stringValue),"if(%s %s %s){%s}\nelse{%s}\n%s ",(yyvsp[-13].stringValue),(yyvsp[-12].stringValue),(yyvsp[-11].stringValue),(yyvsp[-6].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue));
                                                                                                                        add((yyval.stringValue),true);}
#line 1656 "y.tab.c"
    break;

  case 25:
#line 131 "grammar.y"
                                                    { if(checkIfVarExists((yyvsp[-4].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}  (yyval.stringValue) = malloc(2*strlen((yyvsp[-4].stringValue))+2*strlen((yyvsp[-2].stringValue))+ 30); sprintf((yyval.stringValue),"char %s[%s];\nfgets(%s,%s,stdin);\n",(yyvsp[-4].stringValue),(yyvsp[-2].stringValue),(yyvsp[-4].stringValue),(yyvsp[-2].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-4].stringValue), KIND_STRING,1);}
#line 1662 "y.tab.c"
    break;

  case 26:
#line 135 "grammar.y"
                                        { (yyval.stringValue) = malloc(1 + strlen((yyvsp[-1].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s%s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1668 "y.tab.c"
    break;

  case 27:
#line 136 "grammar.y"
                                        { (yyval.stringValue) = malloc(3 + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "\'%s\'%s", (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1674 "y.tab.c"
    break;

  case 28:
#line 137 "grammar.y"
                                        { (yyval.stringValue) = ""; }
#line 1680 "y.tab.c"
    break;

  case 29:
#line 138 "grammar.y"
                                        { (yyval.stringValue) = malloc(1 + strlen((yyvsp[-1].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s%s", (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1686 "y.tab.c"
    break;

  case 30:
#line 139 "grammar.y"
                                        { (yyval.stringValue) = malloc(3 + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "\'%s\'%s", (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1692 "y.tab.c"
    break;

  case 31:
#line 144 "grammar.y"
                                                    { if(checkIfVarExists((yyvsp[-3].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}(yyval.stringValue) = malloc(strlen("int")+strlen((yyvsp[-3].stringValue))+6+strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s=%s%s","int",(yyvsp[-3].stringValue),(yyvsp[-1].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-3].stringValue), KIND_INT,1);}
#line 1698 "y.tab.c"
    break;

  case 32:
#line 145 "grammar.y"
                                                    { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}(yyval.stringValue) = malloc(strlen("char *")+strlen((yyvsp[-2].stringValue))+6+strlen((yyvsp[0].stringValue))); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0;sprintf((yyval.stringValue),"%s %s=\"%s\"","char *",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)+1); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_STRING,1);}
#line 1704 "y.tab.c"
    break;

  case 33:
#line 146 "grammar.y"
                                                    { if(checkIfVarExists((yyvsp[-4].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(array_is_incorrect((yyvsp[0].stringValue),atoi((yyvsp[-2].stringValue)))){yyerror("Bad initialization of array"); YYABORT;} (yyval.stringValue) = malloc(strlen("int")+strlen((yyvsp[-4].stringValue))+10+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]={%s}","int",(yyvsp[-4].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-4].stringValue), KIND_ARRAY_INT,atoi((yyvsp[-2].stringValue))); }
#line 1710 "y.tab.c"
    break;

  case 34:
#line 147 "grammar.y"
                                                    { if(checkIfVarExists((yyvsp[-4].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(array_is_incorrect((yyvsp[0].stringValue),atoi((yyvsp[-2].stringValue)))){yyerror("Bad initialization of array"); YYABORT;} (yyval.stringValue) = malloc(strlen("char *")+strlen((yyvsp[-4].stringValue))+10+strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]={%s}","char *",(yyvsp[-4].stringValue),(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-4].stringValue), KIND_ARRAY_STRING,atoi((yyvsp[-2].stringValue)));}
#line 1716 "y.tab.c"
    break;

  case 35:
#line 149 "grammar.y"
                                                { if(checkIfVarExists((yyvsp[0].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}(yyval.stringValue) = malloc(strlen("int")+strlen((yyvsp[0].stringValue))+2); sprintf((yyval.stringValue),"%s %s","int",(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[0].stringValue), KIND_INT,1);}
#line 1722 "y.tab.c"
    break;

  case 36:
#line 150 "grammar.y"
                                                { if(checkIfVarExists((yyvsp[0].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}(yyval.stringValue) = malloc(strlen("char *")+strlen((yyvsp[0].stringValue))+2); sprintf((yyval.stringValue),"%s %s","char *",(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[0].stringValue), KIND_STRING,1);}
#line 1728 "y.tab.c"
    break;

  case 37:
#line 151 "grammar.y"
                                                {if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;} (yyval.stringValue) = malloc(strlen("int")+strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]","int",(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_ARRAY_INT,atoi((yyvsp[0].stringValue))); }
#line 1734 "y.tab.c"
    break;

  case 38:
#line 152 "grammar.y"
                                                {if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;} (yyval.stringValue) = malloc(strlen("char *")+strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s[%s]","char *",(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_ARRAY_STRING,atoi((yyvsp[0].stringValue)));}
#line 1740 "y.tab.c"
    break;

  case 39:
#line 154 "grammar.y"
                                                { if(!isOfKind((yyvsp[-2].stringValue),KIND_INT)){yyerror("Variable should be int type.");YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))+5); sprintf((yyval.stringValue), "%s=%s", (yyvsp[-2].stringValue), (yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1746 "y.tab.c"
    break;

  case 40:
#line 155 "grammar.y"
                                                { if(!isOfKind((yyvsp[-2].stringValue),KIND_STRING)){yyerror("Variable should be string type.");YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+strlen((yyvsp[0].stringValue))+5); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0;sprintf((yyval.stringValue), "%s=\"%s\"", (yyvsp[-2].stringValue), (yyvsp[0].stringValue)+1); add((yyval.stringValue),true);}
#line 1752 "y.tab.c"
    break;

  case 41:
#line 156 "grammar.y"
                                                { if(!isOfKind((yyvsp[-3].stringValue),KIND_INT)){yyerror("Variable should be int type."); YYABORT;}(yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue))+strlen((yyvsp[-1].stringValue))+strlen((yyvsp[0].stringValue))+5);  sprintf((yyval.stringValue), "%s=%s%s", (yyvsp[-3].stringValue), (yyvsp[-1].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1758 "y.tab.c"
    break;

  case 42:
#line 158 "grammar.y"
                                                { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!functionReturnsKind((yyvsp[0].stringValue), KIND_INT)){yyerror("Function should return type int"); YYABORT;} (yyval.stringValue) = malloc(strlen("int")+strlen((yyvsp[-2].stringValue))+3+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s=%s","int",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_INT,1);}
#line 1764 "y.tab.c"
    break;

  case 43:
#line 159 "grammar.y"
                                                { if(checkIfVarExists((yyvsp[-2].stringValue))){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!functionReturnsKind((yyvsp[0].stringValue), KIND_STRING)){yyerror("Function should return type string"); YYABORT;} (yyval.stringValue) = malloc(strlen("char *")+strlen((yyvsp[-2].stringValue))+3+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s %s=%s","char *",(yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true); addVar((yyvsp[-2].stringValue), KIND_STRING,1);}
#line 1770 "y.tab.c"
    break;

  case 44:
#line 160 "grammar.y"
                                                { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+2+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s=%s",(yyvsp[-2].stringValue),(yyvsp[0].stringValue));add((yyval.stringValue),true);}
#line 1776 "y.tab.c"
    break;

  case 45:
#line 162 "grammar.y"
                                                { if (!isOfKind((yyvsp[-4].stringValue), KIND_ARRAY_INT)){yyerror("Variable should de string array type"); YYABORT;} if(! enoughSpace((yyvsp[-4].stringValue), atoi((yyvsp[-2].stringValue))) ) { yyerror("Array has not enough space"); YYABORT; } (yyval.stringValue) = malloc(strlen((yyvsp[-4].stringValue)) + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue)) + 4 ); sprintf((yyval.stringValue), "%s[%s]=%s", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue)); add((yyval.stringValue), true); }
#line 1782 "y.tab.c"
    break;

  case 46:
#line 163 "grammar.y"
                                                { if (!isOfKind((yyvsp[-4].stringValue), KIND_ARRAY_STRING)){yyerror("Variable should de string array type"); YYABORT;} if(! enoughSpace((yyvsp[-4].stringValue), atoi((yyvsp[-2].stringValue))) ) { yyerror("Array has not enough space"); YYABORT; } (yyval.stringValue) = malloc(strlen((yyvsp[-4].stringValue)) + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[0].stringValue)) + 4 ); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0; sprintf((yyval.stringValue), "%s[%s]=\"%s\"", (yyvsp[-4].stringValue), (yyvsp[-2].stringValue), (yyvsp[0].stringValue)+1); add((yyval.stringValue), true); }
#line 1788 "y.tab.c"
    break;

  case 47:
#line 168 "grammar.y"
                           { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+ 1 + strlen((yyvsp[-1].stringValue)) + strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue),"%s%s%s",(yyvsp[-2].stringValue),(yyvsp[-1].stringValue),(yyvsp[0].stringValue) ); add((yyval.stringValue),true);}
#line 1794 "y.tab.c"
    break;

  case 48:
#line 169 "grammar.y"
                           { (yyval.stringValue) = "";}
#line 1800 "y.tab.c"
    break;

  case 49:
#line 173 "grammar.y"
                    {(yyval.stringValue) = (yyvsp[0].stringValue);}
#line 1806 "y.tab.c"
    break;

  case 50:
#line 174 "grammar.y"
                    {(yyval.stringValue) = (yyvsp[0].stringValue);}
#line 1812 "y.tab.c"
    break;

  case 51:
#line 175 "grammar.y"
                    {
        (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1]  = '\"';
        (yyvsp[0].stringValue)[0]               = '\"';
        (yyval.stringValue) = (yyvsp[0].stringValue);
        }
#line 1822 "y.tab.c"
    break;

  case 52:
#line 183 "grammar.y"
                                        { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+5+strlen((yyvsp[0].stringValue))); (yyvsp[-2].stringValue)[strlen((yyvsp[-2].stringValue)) - 1] = 0; sprintf((yyval.stringValue), "\"%s\",%s", (yyvsp[-2].stringValue)+1,(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1828 "y.tab.c"
    break;

  case 53:
#line 184 "grammar.y"
                                        { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+5); (yyvsp[0].stringValue)[strlen((yyvsp[0].stringValue)) - 1] = 0; sprintf((yyval.stringValue), "\"%s\"", (yyvsp[0].stringValue)+1); add((yyval.stringValue),true);}
#line 1834 "y.tab.c"
    break;

  case 54:
#line 188 "grammar.y"
                                { (yyval.stringValue) = malloc(strlen((yyvsp[-2].stringValue))+2+strlen((yyvsp[0].stringValue))); sprintf((yyval.stringValue), "%s,%s", (yyvsp[-2].stringValue),(yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1840 "y.tab.c"
    break;

  case 55:
#line 189 "grammar.y"
                                { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+1); sprintf((yyval.stringValue), "%s", (yyvsp[0].stringValue)); add((yyval.stringValue),true);}
#line 1846 "y.tab.c"
    break;

  case 56:
#line 193 "grammar.y"
                                        {   
                                            if(!are_comparable((yyvsp[-3].stringValue), (yyvsp[-1].stringValue))) {
                                                yyerror("Uncomparable data types");
                                                YYABORT;
                                            }
                                            (yyval.stringValue) = malloc(strlen((yyvsp[-3].stringValue)) + strlen((yyvsp[-2].stringValue)) + strlen((yyvsp[-1].stringValue)) + 5);
                                            sprintf((yyval.stringValue), "(%s %s %s)", (yyvsp[-3].stringValue), (yyvsp[-2].stringValue), (yyvsp[-1].stringValue));
                                            add((yyval.stringValue),true);}
#line 1859 "y.tab.c"
    break;

  case 57:
#line 202 "grammar.y"
                                        { (yyval.stringValue) = malloc(strlen((yyvsp[0].stringValue))+1); sprintf((yyval.stringValue), "%s", (yyvsp[0].stringValue)); add((yyval.stringValue), true);}
#line 1865 "y.tab.c"
    break;

  case 58:
#line 206 "grammar.y"
            { (yyval.stringValue) = "while";}
#line 1871 "y.tab.c"
    break;

  case 59:
#line 207 "grammar.y"
            { (yyval.stringValue) = "if";}
#line 1877 "y.tab.c"
    break;

  case 60:
#line 211 "grammar.y"
            { (yyval.stringValue) = (yyvsp[0].stringValue);}
#line 1883 "y.tab.c"
    break;

  case 61:
#line 212 "grammar.y"
            { (yyval.stringValue) = "<";}
#line 1889 "y.tab.c"
    break;

  case 62:
#line 213 "grammar.y"
            { (yyval.stringValue) = ">";}
#line 1895 "y.tab.c"
    break;

  case 63:
#line 214 "grammar.y"
            { (yyval.stringValue) = "<=";}
#line 1901 "y.tab.c"
    break;

  case 64:
#line 215 "grammar.y"
            { (yyval.stringValue) = ">=";}
#line 1907 "y.tab.c"
    break;

  case 65:
#line 216 "grammar.y"
            { (yyval.stringValue) = "==";}
#line 1913 "y.tab.c"
    break;

  case 66:
#line 217 "grammar.y"
            { (yyval.stringValue) = "!=";}
#line 1919 "y.tab.c"
    break;

  case 67:
#line 218 "grammar.y"
            { (yyval.stringValue) = "!";}
#line 1925 "y.tab.c"
    break;

  case 68:
#line 219 "grammar.y"
            { (yyval.stringValue) = "||";}
#line 1931 "y.tab.c"
    break;

  case 69:
#line 220 "grammar.y"
            { (yyval.stringValue) = "&&";}
#line 1937 "y.tab.c"
    break;

  case 70:
#line 224 "grammar.y"
            { (yyval.stringValue) = "+";}
#line 1943 "y.tab.c"
    break;

  case 71:
#line 225 "grammar.y"
            { (yyval.stringValue) = "-";}
#line 1949 "y.tab.c"
    break;

  case 72:
#line 226 "grammar.y"
            { (yyval.stringValue) = "/";}
#line 1955 "y.tab.c"
    break;

  case 73:
#line 227 "grammar.y"
            { (yyval.stringValue) = "*";}
#line 1961 "y.tab.c"
    break;

  case 74:
#line 228 "grammar.y"
          { (yyval.stringValue) = "%";}
#line 1967 "y.tab.c"
    break;


#line 1971 "y.tab.c"

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
#line 231 "grammar.y"

