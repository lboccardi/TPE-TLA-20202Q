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
    | ALPHA OPEN_P args CLOSE_P {printf("%s()\n",$1);}
    | /* lambda */
    ;


program 
    : var END program 
    | OPEN_P rule operator rule CLOSE_P CONDITIONAL arrow EXEC program END_EXEC program 
    | RETURN assignment END {printf("return ;\n");}
    | STDIN OPEN_P ALPHA CLOSE_P END program {printf("scanchar (%s);\n",$3);}
    | STDOUT OPEN_P out CLOSE_P END program  {printf("printf();\n");} 
    | /* lambda */  
    ;

out 
    : ALPHA out {printf("%s\n",$1);}
    | ESCAPE ALPHA ESCAPE out {printf("'%s'\n",$2);}
    | /* lambda */
    ; 

var
    : INT ALPHA creation {printf("int %s\n;\n",$2); }
    | STRING ALPHA ASSIGN assignment {printf("char * %s = \n;\n",$2); }
    | ALPHA botch {printf("BOTCH %s\n;\n",$1); }
    ; 
creation
    :ASSIGN action {printf("=\n");}
    |/*lambda*/ 
    ;
botch
    : ASSIGN action {printf("=\n");}
    | OPEN_P  args CLOSE_P {printf("()\n");}     
    ;

action
    : assignment call
    | ALPHA OPEN_P args CLOSE_P {printf("%s()\n",$1);}
    ;

call
    : OP assignment call {printf("%s\n",$1);}
    | /* lambda */
    ;
    
assignment
    : ALPHA {printf("%s\n",$1);}
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