/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison interface for Yacc-like parsers in C

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

#line 139 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
