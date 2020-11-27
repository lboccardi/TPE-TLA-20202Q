%{
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#ifdef E_PARSE_DEBUG
// Some yacc (bison) defines
#define YYDEBUG 1       // Generate debug code; needed for YYERROR_VERBOSE
#define YYERROR_VERBOSE // Give a more specific parse error message 
#define YYACCEPT 0
#endif

int yylex();

int yydebug=1;

void yyerror(const char *str)
{
  fprintf(stderr,"error: %s\n",str);
  freeResources(true); 
} 
%}

%union {
	char * stringValue;
}

/* Non Terminals */ 
%type<stringValue> rule type op start arrow operator params out function program assignment operation var call args digit_array alpha_array;

/* Terminals */ 
%token<stringValue>  DIGIT ALPHA SPACE_ALPHA STRING_VALUE;
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
%token  NE;
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
    : MAIN EXEC program END_EXEC    { $$ = malloc(16 +  strlen($3)); sprintf($$, "int main(){ %s }\n",$3); add($$, true);  } 
    | function start                { $$ = malloc(strlen($1)+strlen($2)+3); sprintf($$,"%s\n%s", $1, $2); add($$,true);}
    ;

function
    : INT FUNCTION ALPHA OPEN_P params CLOSE_P EXEC program END_EXEC    { $$ = malloc(strlen("int")+strlen($3)+strlen($5)+strlen($8)+ 8); sprintf($$, "%s %s(%s){\n%s}\n", "int", $3, $5, $8); add($$,true); addFunction($3,KIND_INT,1);}
    | STRING FUNCTION ALPHA OPEN_P params CLOSE_P EXEC program END_EXEC { $$ = malloc(strlen("char *")+strlen($3)+strlen($5)+strlen($8)+ 8); sprintf($$, "%s %s(%s){\n%s}\n", "char *", $3, $5, $8); add($$,true); addFunction($3,KIND_STRING,1);}
    ;

type
    : INT       {$$ = "int";}
    | STRING    {$$ = "char *";}
    ;

params 
    : type ALPHA                { $$ = malloc(strlen($1)+strlen($2) +2); sprintf($$, "%s %s", $1, $2); add($$,true);}
    | type ALPHA COMMA params   { $$ = malloc(strlen($1)+strlen($2)+4+strlen($4)); sprintf($$, "%s %s, %s", $1, $2, $4); add($$,true);} 
    | /* lambda */              { $$ = ""; }
    ;

args 
    : assignment                { $$ = malloc(strlen($1)+1); sprintf($$, "%s", $1);add($$,true);}
    | assignment COMMA args     { $$ = malloc(strlen($1)+2+strlen($3)); sprintf($$,"%s,%s",$1,$3); add($$,true);}
    | call                      { $$ = $1;}
    | /* lambda */              { $$ = "";}
    ;

call
    : ALPHA OPEN_P  args CLOSE_P { $$ = malloc(strlen($1)+3+strlen($3)); sprintf($$,"%s(%s)",$1,$3); add($$,true);} 
    ;

program 
    : var END program                           { $$ = malloc(strlen($1)+3+strlen($3)); sprintf($$,"%s; %s",$1,$3); add($$,true);}
    | call END program                          { $$ = malloc(strlen($1)+3+strlen($3)); sprintf($$,"%s; %s",$1,$3); add($$,true);}
    | OPEN_P rule operator rule CLOSE_P CONDITIONAL arrow EXEC program END_EXEC program {$$ = malloc(strlen($2)+10+strlen($3)+strlen($4)+strlen($7)+strlen($9)+strlen($11)); sprintf($$,"%s(%s %s %s){%s}\n%s ",$7,$2,$3,$4,$9,$11); add($$,true);}
    | RETURN assignment END                     { $$ = malloc(strlen($2) +9); sprintf($$, "return %s;", $2); add($$,true);} 
    | STDIN OPEN_P ALPHA CLOSE_P END program    { $$ = malloc(strlen($3)+strlen($6)+ 11); sprintf($$,"gets(%s);\n%s",$6,$3); add($$,true);}
    | STDOUT out END program                    { char * print = printfParser($2); if(print==NULL){yyerror("Sintax error on P.\n Check if your variables exist."); YYABORT;} $$ = malloc(strlen($2)*2+5+strlen($4)+ 11); sprintf($$, "printf(%s);\n%s", print, $4); add($$,true); free(print);} 
    | /* lambda */                              { $$ = "";}
    ;

out 
    : SPACE_ALPHA out                   { $$ = malloc(1 + strlen($1) + strlen($2)); sprintf($$, "%s%s", $1, $2); add($$,true);}
    | ESCAPE SPACE_ALPHA ESCAPE out     { $$ = malloc(3 + strlen($2) + strlen($4)); sprintf($$, "\'%s\'%s", $2, $4); add($$,true);}
    | /* lambda */                      { $$ = ""; }
    | ALPHA out                         { $$ = malloc(1 + strlen($1) + strlen($2)); sprintf($$, "%s%s", $1, $2); add($$,true);}
    | ESCAPE ALPHA ESCAPE out           { $$ = malloc(3 + strlen($2) + strlen($4)); sprintf($$, "\'%s\'%s", $2, $4); add($$,true);}
   
    ; 

var
    : INT ALPHA ASSIGN DIGIT operation              { $$ = malloc(strlen("int")+strlen($2)+6+strlen($4)+strlen($5)); sprintf($$,"%s %s=%s%s","int",$2,$4,$5); add($$,true); addVar($2, KIND_INT,1);} 
    | STRING ALPHA ASSIGN STRING_VALUE              { $$ = malloc(strlen("char *")+strlen($2)+6+strlen($4)); $4[strlen($4) - 1] = 0;sprintf($$,"%s %s=\"%s\"","char *",$2,$4+1); add($$,true); addVar($2, KIND_STRING,1);} 
    | INT ALPHA ARRAY DIGIT ASSIGN digit_array      { if(array_is_incorrect($6,atoi($4))){yyerror("Bad initialization of array"); YYABORT;} $$ = malloc(strlen("int")+strlen($2)+10+strlen($4)+strlen($6)); sprintf($$,"%s %s[%s]={%s}","int",$2,$4,$6);add($$,true); addVar($2, KIND_ARRAY_INT,atoi($4)); }
    | STRING ALPHA ARRAY DIGIT ASSIGN alpha_array   { if(array_is_incorrect($6,atoi($4))){yyerror("Bad initialization of array"); YYABORT;} $$ = malloc(strlen("char *")+strlen($2)+10+strlen($4)+strlen($6)); sprintf($$,"%s %s[%s]={%s}","char *",$2,$4,$6);add($$,true); addVar($2, KIND_ARRAY_STRING,atoi($4));}
    
    | INT ALPHA                                 { $$ = malloc(strlen("int")+strlen($2)+2); sprintf($$,"%s %s","int",$2);add($$,true); addVar($2, KIND_INT,1);}
    | STRING ALPHA                              { $$ = malloc(strlen("char *")+strlen($2)+2); sprintf($$,"%s %s","char *",$2);add($$,true); addVar($2, KIND_STRING,1);}
    | INT ALPHA ARRAY DIGIT                     { $$ = malloc(strlen("int")+strlen($2)+5+strlen($4)); sprintf($$,"%s %s[%s]","int",$2,$4);add($$,true); addVar($2, KIND_ARRAY_INT,atoi($4)); }
    | STRING ALPHA ARRAY DIGIT                  { $$ = malloc(strlen("char *")+strlen($2)+5+strlen($4)); sprintf($$,"%s %s[%s]","char *",$2,$4);add($$,true); addVar($2, KIND_ARRAY_STRING,atoi($4));}
   
    | ALPHA ASSIGN DIGIT                        { if(!isOfKind($1,KIND_INT)){yyerror("Variable should be int type.");YYABORT;}$$ = malloc(strlen($1)+strlen($3)+5); sprintf($$, "%s=%s", $1, $3);add($$,true);}
    | ALPHA ASSIGN STRING_VALUE                 { if(!isOfKind($1,KIND_STRING)){yyerror("Variable should be string type.");YYABORT;}$$ = malloc(strlen($1)+strlen($3)+5); $3[strlen($3) - 1] = 0;sprintf($$, "%s=\"%s\"", $1, $3+1); add($$,true);}
    | ALPHA ASSIGN assignment operation         { if(!isOfKind($1,KIND_INT)){yyerror("Variable should be int type."); YYABORT;}$$ = malloc(strlen($1)+strlen($3)+strlen($4)+5);  sprintf($$, "%s=%s%s", $1, $3, $4); add($$,true);}

    | INT ALPHA ASSIGN call                     { if(!functionReturnsKind($4, KIND_INT)){yyerror("Function should return type int"); YYABORT;} $$ = malloc(strlen("int")+strlen($2)+3+strlen($4)); sprintf($$,"%s %s=%s","int",$2,$4); add($$,true); addVar($2, KIND_INT,1);}
    | STRING ALPHA ASSIGN call                  { if(!functionReturnsKind($4, KIND_STRING)){yyerror("Function should return type string"); YYABORT;} $$ = malloc(strlen("char *")+strlen($2)+3+strlen($4)); sprintf($$,"%s %s=%s","char *",$2,$4); add($$,true); addVar($2, KIND_STRING,1);}
    | ALPHA ASSIGN call                         { $$ = malloc(strlen($1)+2+strlen($3)); sprintf($$,"%s=%s",$1,$3);add($$,true);}

    | ALPHA ARRAY DIGIT ASSIGN DIGIT            { if (!isOfKind($1, KIND_ARRAY_INT)){yyerror("Variable should de string array type"); YYABORT;} if(! enoughSpace($1, atoi($3)) ) { yyerror("Array has not enough space"); YYABORT; } $$ = malloc(strlen($1) + strlen($3) + strlen($5) + 4 ); sprintf($$, "%s[%s]=%s", $1, $3, $5); add($$, true); }
    | ALPHA ARRAY DIGIT ASSIGN STRING_VALUE     { if (!isOfKind($1, KIND_ARRAY_STRING)){yyerror("Variable should de string array type"); YYABORT;} if(! enoughSpace($1, atoi($3)) ) { yyerror("Array has not enough space"); YYABORT; } $$ = malloc(strlen($1) + strlen($3) + strlen($5) + 4 ); $5[strlen($5) - 1] = 0; sprintf($$, "%s[%s]=\"%s\"", $1, $3, $5+1); add($$, true); }
     
    ; 
    
operation
    : op DIGIT operation   { $$ = malloc(strlen($1)+ 1 + strlen($2) + strlen($3)); sprintf($$,"%s%s%s",$1,$2,$3 ); add($$,true);}
    | /* lambda */         { $$ = "";}
    ;
    
assignment
    : ALPHA         {$$ = $1;}
    | DIGIT         {$$ = $1;}
    | STRING_VALUE  {$$ = $1;}
    ;

alpha_array
    : STRING_VALUE COMMA alpha_array    { $$ = malloc(strlen($1)+5+strlen($3)); $1[strlen($1) - 1] = 0; sprintf($$, "\"%s\",%s", $1+1,$3); add($$,true);}
    | STRING_VALUE                      { $$ = malloc(strlen($1)+5); $1[strlen($1) - 1] = 0; sprintf($$, "\"%s\"", $1+1); add($$,true);}
    ;
digit_array
    : DIGIT COMMA digit_array   { $$ = malloc(strlen($1)+2+strlen($3)); sprintf($$, "%s,%s", $1,$3); add($$,true);}
    | DIGIT                     { $$ = malloc(strlen($1)+1); sprintf($$, "%s", $1); add($$,true);}     
    ; 
    
rule
    : OPEN_P rule operator rule CLOSE_P { $$ = malloc(strlen($2) + strlen($3) + strlen($4) + 3); sprintf($$, "(%s%s%s)", $2, $3, $4); add($$,true);}
    | assignment                        { $$ = malloc(strlen($1)+1); sprintf($$, "%s", $1); add($$,true);}
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
    | NE    { $$ = "!=";}
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
