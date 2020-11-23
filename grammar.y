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

%start program

%%

program 
    : ALPHA 
    ;


%%

int main(){
    yyparse(); 
}