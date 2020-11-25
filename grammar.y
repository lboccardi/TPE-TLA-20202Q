%{
#include <ctype.h>
#include <stdio.h>

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


%token  DIGIT;
%token  ALPHA;
%token  END; 
%token  CONDITION; 
%token  END_CONDITION;
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
    : MAIN EXEC program END_EXEC
    | function start 
    ;

function
    : type FUNCTION ALPHA CONDITION params END_CONDITION EXEC program END_EXEC
    ;

call 
    : ALPHA ASSIGN ALPHA CONDITION args END_CONDITION END
    | ALPHA CONDITION args END_CONDITION END { printf("call");   };
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
    : ALPHA 
    | ALPHA COMMA args 
    | /* lambda */
    ;

program 
    : var END program
    | CONDITION rule operator rule END_CONDITION arrow EXEC program END_EXEC program 
    | RETURN END 
    | call program 
    | STDIN CONDITION ALPHA END_CONDITION END program 
    | STDOUT CONDITION out END_CONDITION END program  
    | /* lambda */  
    ;

out 
    : ALPHA out
    | ESCAPE ALPHA ESCAPE out
    | /* lambda */
    ; 

var
    : INT ALPHA ASSIGN assignment 
    | STRING ALPHA ASSIGN assignment
    | ALPHA ASSIGN assignment
    | ALPHA ASSIGN assignment OP assignment { $$ = $3+$5; printf("Found %d\n", $3+$5);   };
    ; 

assignment
    : ALPHA 
    | DIGIT { $$ = $1; printf("Found %d\n", $1);   };

rule
    : CONDITION rule operator rule END_CONDITION 
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