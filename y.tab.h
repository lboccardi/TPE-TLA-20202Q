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
    INT = 261,
    STRING = 262,
    PLUS = 263,
    MINUS = 264,
    TIMES = 265,
    DIV = 266,
    END = 267,
    OPEN_P = 268,
    CLOSE_P = 269,
    CONDITIONAL = 270,
    EXEC = 271,
    END_EXEC = 272,
    IF = 273,
    ELSE = 274,
    ESCAPE = 275,
    WHILE = 276,
    L = 277,
    G = 278,
    LE = 279,
    GE = 280,
    EQ = 281,
    NOT = 282,
    OR = 283,
    AND = 284,
    ASSIGN = 285,
    RETURN = 286,
    MAIN = 287,
    STDIN = 288,
    STDOUT = 289,
    FUNCTION = 290,
    COMMA = 291,
    ARRAY = 292
  };
#endif
/* Tokens.  */
#define DIGIT 258
#define ALPHA 259
#define SPACE_ALPHA 260
#define INT 261
#define STRING 262
#define PLUS 263
#define MINUS 264
#define TIMES 265
#define DIV 266
#define END 267
#define OPEN_P 268
#define CLOSE_P 269
#define CONDITIONAL 270
#define EXEC 271
#define END_EXEC 272
#define IF 273
#define ELSE 274
#define ESCAPE 275
#define WHILE 276
#define L 277
#define G 278
#define LE 279
#define GE 280
#define EQ 281
#define NOT 282
#define OR 283
#define AND 284
#define ASSIGN 285
#define RETURN 286
#define MAIN 287
#define STDIN 288
#define STDOUT 289
#define FUNCTION 290
#define COMMA 291
#define ARRAY 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "grammar.y"

	char * stringValue;

#line 135 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
