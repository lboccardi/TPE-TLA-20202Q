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
    END = 260,
    OPEN_P = 261,
    CLOSE_P = 262,
    CONDITIONAL = 263,
    EXEC = 264,
    END_EXEC = 265,
    IF = 266,
    ELSE = 267,
    ESCAPE = 268,
    WHILE = 269,
    L = 270,
    G = 271,
    LE = 272,
    GE = 273,
    EQ = 274,
    NOT = 275,
    OR = 276,
    AND = 277,
    ASSIGN = 278,
    INT = 279,
    STRING = 280,
    OP = 281,
    RETURN = 282,
    MAIN = 283,
    STDIN = 284,
    STDOUT = 285,
    FUNCTION = 286,
    COMMA = 287
  };
#endif
/* Tokens.  */
#define DIGIT 258
#define ALPHA 259
#define END 260
#define OPEN_P 261
#define CLOSE_P 262
#define CONDITIONAL 263
#define EXEC 264
#define END_EXEC 265
#define IF 266
#define ELSE 267
#define ESCAPE 268
#define WHILE 269
#define L 270
#define G 271
#define LE 272
#define GE 273
#define EQ 274
#define NOT 275
#define OR 276
#define AND 277
#define ASSIGN 278
#define INT 279
#define STRING 280
#define OP 281
#define RETURN 282
#define MAIN 283
#define STDIN 284
#define STDOUT 285
#define FUNCTION 286
#define COMMA 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "grammar.y"

    int intValue;
	char * stringValue;

#line 126 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
