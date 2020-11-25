%{
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef E_PARSE_DEBUG
// Some yacc (bison) defines
#define YYDEBUG 1       // Generate debug code; needed for YYERROR_VERBOSE
#define YYERROR_VERBOSE // Give a more specific parse error message 
#endif

int yylex();

void yyerror(const char *str)
{
  fprintf(stderr,"error: %s\n",str);
} 
%}

%union {
    int intValue;
	char * stringValue;
}

%type<stringValue> ALPHA OP;
%type<intValue> DIGIT;

%token  DIGIT;
%token  ALPHA;
%token  END; 
%token  OPEN_P; 
%token  CLOSE_P;
%token  CONDITIONAL;
%token  EXEC; 
%token  END_EXEC;
%token  IF; 
%token  ELSE;
%token  ESCAPE;
%token  WHILE;
%token  L;
%token  G;
%token  LE;
%token  GE;
%token  EQ;
%token  NOT;
%token  OR;
%token  AND;
%token  ASSIGN; 
%token  INT; 
%token  STRING; 
%token  OP; 
%token  RETURN;
%token  MAIN; 
%token  STDIN; 
%token  STDOUT; 
%token  FUNCTION; 
%token  COMMA;

%start start

%%

start 
    : MAIN EXEC program END_EXEC {printf("int main(){ }\n");}
    | function start
    ;

function
    : type FUNCTION ALPHA OPEN_P params CLOSE_P EXEC program END_EXEC {printf("int %s(){ }\n",$3);}
    ;

type
    : INT 
    | STRING
    ;

params 
    : type ALPHA 
    | type ALPHA COMMA params 
    | /* lambda */
    ;

args 
    : assignment 
    | assignment COMMA args 
    | ALPHA OPEN_P args CLOSE_P
    | /* lambda */
    ;


program 
    : var END program  {printf(";\n");}
    | OPEN_P rule operator rule CLOSE_P CONDITIONAL arrow EXEC program END_EXEC program 
    | RETURN assignment END 
    | STDIN OPEN_P ALPHA CLOSE_P END program 
    | STDOUT OPEN_P out CLOSE_P END program  
    | /* lambda */  
    ;

out 
    : ALPHA out
    | ESCAPE ALPHA ESCAPE out
    | /* lambda */
    ; 

var
    : INT ALPHA creation {printf("int %s\n",$2);}
    | STRING ALPHA ASSIGN assignment
    | ALPHA botch 
    ; 
creation
    :ASSIGN action {printf("=\n");}
    |/*lambda*/ 
    ;
botch
    : ASSIGN action
    | OPEN_P  args CLOSE_P     
    ;

action
    : assignment call
    | ALPHA OPEN_P args CLOSE_P
    ;

call
    : OP assignment
    | /* lambda */
    ;

assignment
    : ALPHA 
    | DIGIT {printf("%d\n",$1);}
    ;

rule
    : OPEN_P rule operator rule CLOSE_P
    | assignment; 

arrow
    : WHILE 
    | IF; 

operator
    : OP 
    | L 
    | G
    | LE
    | GE
    | EQ
    | NOT
    | OR
    | AND; 

%%

int main(){
     printf("Enter the expression:\n");
    yyparse(); 
}