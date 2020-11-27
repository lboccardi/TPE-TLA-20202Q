/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 141 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
