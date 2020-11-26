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
	char * stringValue;
}

/* Non Terminals */ 
%type<stringValue> rule type op start arrow operator params out function program assignment operation var call args;

/* Terminals */ 
%token<stringValue>  DIGIT ALPHA;
%token<stringValue>  INT STRING; 
%token<stringValue>  PLUS MINUS TIMES DIV;
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
%token  RETURN;
%token  MAIN; 
%token  STDIN; 
%token  STDOUT; 
%token  FUNCTION; 
%token  COMMA;
%token  ARRAY;

%start start

/* Precedence */ 
%left PLUS MINUS
%left TIMES DIV

%%

start 
    : MAIN EXEC program END_EXEC {printf("int main(){ %s }\n",$3);free($3);}
    | function start {printf("%s\n",$1);free($1);}
    ;

function
    : type FUNCTION ALPHA OPEN_P params CLOSE_P EXEC program END_EXEC { $$ = malloc(strlen($1)+strlen($3)+strlen($5)+strlen($8)+ 8); sprintf($$, "%s %s(%s){\n%s}\n", $1, $3, $5, $8); if(strlen($5)){free($5);}; if(strlen($8)){free($8);};}
    ;

type
    : INT       {$$ = "int";}
    | STRING    {$$ = "char *";}
    ;

params 
    : type ALPHA                { $$ = malloc(strlen($1)+strlen($2) +2); sprintf($$, "%s %s", $1, $2); }
    | type ALPHA COMMA params   { $$ = malloc(strlen($1)+strlen($2)+4+strlen($4)); sprintf($$, "%s %s, %s", $1, $2, $4); if(strlen($4)){free($4);} } 
    | /* lambda */              { $$ = ""; }
    ;

args 
    : assignment                { $$ = malloc(strlen($1)+1); sprintf($$, "%s", $1);free($1);}
    | assignment COMMA args     { $$ = malloc(strlen($1)+2+strlen($3)); sprintf($$,"%s,%s",$1,$3); if(strlen($3)){free($3);}free($1);}
    | call                      { $$ = $1;}
    | /* lambda */              { $$ = "";}
    ;

call
    : ALPHA OPEN_P  args CLOSE_P { $$ = malloc(strlen($1)+3+strlen($3)); sprintf($$,"%s(%s)",$1,$3); if(strlen($3)){free($3);}} 
    ;

program 
    : var END program                           { $$ = malloc(strlen($1)+3+strlen($3)); sprintf($$,"%s; %s",$1,$3); if(strlen($3)){free($3);} if(strlen($1)){free($1);}}
    | call END program                          { $$ = malloc(strlen($1)+3+strlen($3)); sprintf($$,"%s; %s",$1,$3); if(strlen($3)){free($3);} if(strlen($1)){free($1);}}
    | OPEN_P rule operator rule CLOSE_P CONDITIONAL arrow EXEC program END_EXEC program {printf("%s(%s %s %s){%s}\n%s ",$7,$2,$3,$4,$9,$11);free($2);free($4);}
    | RETURN assignment END                     { $$ = malloc(strlen($2) +9); sprintf($$, "return %s;", $2); free($2);} 
    | STDIN OPEN_P ALPHA CLOSE_P END program    { $$ = malloc(strlen($3)+strlen($6)+ 11); sprintf($$,"sscanf(%s);\n%s",$3,$6); free($3); if(strlen($6)){free($6);}}
    | STDOUT OPEN_P out CLOSE_P END program     { $$ = malloc(strlen($3)+strlen($6)+ 11); sprintf($$, "printf(%s);\n%s", $3, $6); if(strlen($3)){free($3);}if(strlen($6)){free($6);} } 
    | /* lambda */  {$$="";}
    ;

out 
    : ALPHA out                 { $$ = malloc(1 + strlen($1) + strlen($2)); sprintf($$, "%s%s", $1, $2); if (strlen($2)){free($2);} }
    | ESCAPE ALPHA ESCAPE out   { $$ = malloc(3 + strlen($2) + strlen($4)); sprintf($$, "\'%s\'%s", $2, $4); if(strlen($4)){free($4);} }
    | /* lambda */              { $$ = ""; }
    ; 

var
    : type ALPHA ASSIGN assignment operation    { $$ = malloc(strlen($1)+strlen($2)+3+strlen($4)+strlen($5)); sprintf($$,"%s %s=%s%s",$1,$2,$4,$5);free($4);} 
    | ALPHA ASSIGN assignment operation         { $$ = malloc(strlen($1)+strlen($3)+strlen($4)+2);  sprintf($$, "%s=%s%s", $1, $3, $4); free($3);}
    | type ALPHA                                { $$ = malloc(strlen($1)+strlen($2)+2); sprintf($$,"%s %s",$1,$2);}
    | type ALPHA ASSIGN call                    { $$ = malloc(strlen($1)+strlen($2)+3+strlen($4)); sprintf($$,"%s %s=%s",$1,$2,$4); free($4);}
    | ALPHA ASSIGN call                         { $$ = malloc(strlen($1)+2+strlen($3)); sprintf($$,"%s=%s",$1,$3);free($3);}
    ; 
    
operation
    : op assignment operation   { $$ = malloc(strlen($1)+ 1 + strlen($2) + strlen($3)); sprintf($$,"%s%s%s",$1,$2,$3 ); if(strlen($3)){free($3);}free($2);}
    | /* lambda */              { $$ = "";}
    ;
    
assignment
    : ALPHA {$$ = $1;}
    | DIGIT {$$ = $1;}
    ;

rule
    : OPEN_P rule operator rule CLOSE_P { $$ = malloc(strlen($2) + strlen($3) + strlen($4) + 3); sprintf($$, "(%s%s%s)", $2, $3, $4); free($2); free($4);}
    | assignment                        { $$ = malloc(strlen($1)+1); sprintf($$, "%s", $1); free($1);}
    ;

arrow
    : WHILE { $$ = "while";}
    | IF    { $$ = "if";}
    ;

operator
    : op    { $$ = $1;}
    | L     { $$ = "<";}
    | G     { $$ = ">";}
    | LE    { $$ = "<=";}
    | GE    { $$ = ">=";} 
    | EQ    { $$ = "==";}
    | NOT   { $$ = "!";}
    | OR    { $$ = "||";}
    | AND   { $$ = "&&";}
    ;

op 
    : PLUS  { $$ = "+";}
    | MINUS { $$ = "-";}
    | DIV   { $$ = "/";}
    | TIMES { $$ = "*";}
    ;

%%

int main(){
    printf("Enter the expression:\n");
    yyparse(); 
}