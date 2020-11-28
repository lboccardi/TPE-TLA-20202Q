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
#line 29 "grammar.y"

	char * stringValue;

#line 145 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
