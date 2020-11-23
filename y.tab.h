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
    END = 260,
    CONDITION = 261,
    END_CONDITION = 262,
    EXEC = 263,
    END_EXEC = 264,
    IF = 265,
    ELSE = 266,
    ESCAPE = 267,
    WHILE = 268,
    L = 269,
    G = 270,
    LE = 271,
    GE = 272,
    EQ = 273,
    NOT = 274,
    OR = 275,
    AND = 276,
    ASSIGN = 277,
    INT = 278,
    STRING = 279,
    OP = 280,
    RETURN = 281
  };
#endif
/* Tokens.  */
#define DIGIT 258
#define ALPHA 259
#define END 260
#define CONDITION 261
#define END_CONDITION 262
#define EXEC 263
#define END_EXEC 264
#define IF 265
#define ELSE 266
#define ESCAPE 267
#define WHILE 268
#define L 269
#define G 270
#define LE 271
#define GE 272
#define EQ 273
#define NOT 274
#define OR 275
#define AND 276
#define ASSIGN 277
#define INT 278
#define STRING 279
#define OP 280
#define RETURN 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
