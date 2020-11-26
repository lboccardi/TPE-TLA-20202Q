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
    INT = 260,
    STRING = 261,
    PLUS = 262,
    MINUS = 263,
    TIMES = 264,
    DIV = 265,
    END = 266,
    OPEN_P = 267,
    CLOSE_P = 268,
    CONDITIONAL = 269,
    EXEC = 270,
    END_EXEC = 271,
    IF = 272,
    ELSE = 273,
    ESCAPE = 274,
    WHILE = 275,
    L = 276,
    G = 277,
    LE = 278,
    GE = 279,
    EQ = 280,
    NOT = 281,
    OR = 282,
    AND = 283,
    ASSIGN = 284,
    RETURN = 285,
    MAIN = 286,
    STDIN = 287,
    STDOUT = 288,
    FUNCTION = 289,
    COMMA = 290,
    ARRAY = 291
  };
#endif
/* Tokens.  */
#define DIGIT 258
#define ALPHA 259
#define INT 260
#define STRING 261
#define PLUS 262
#define MINUS 263
#define TIMES 264
#define DIV 265
#define END 266
#define OPEN_P 267
#define CLOSE_P 268
#define CONDITIONAL 269
#define EXEC 270
#define END_EXEC 271
#define IF 272
#define ELSE 273
#define ESCAPE 274
#define WHILE 275
#define L 276
#define G 277
#define LE 278
#define GE 279
#define EQ 280
#define NOT 281
#define OR 282
#define AND 283
#define ASSIGN 284
#define RETURN 285
#define MAIN 286
#define STDIN 287
#define STDOUT 288
#define FUNCTION 289
#define COMMA 290
#define ARRAY 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "grammar.y"

	char * stringValue;

#line 133 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
