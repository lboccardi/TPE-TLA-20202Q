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
  program.error = true;
} 
%}

%union {
	char * stringValue;
}

/* Non Terminals */ 
%type<stringValue> rule type op start arrow operator params out get function program assignment operation var call args digit_array alpha_array;

/* Terminals */ 
%token<stringValue>  DIGIT ALPHA SPACE_ALPHA STRING_VALUE;
%token<stringValue>  INT STRING CHAR; 
%token<stringValue>  PLUS MINUS TIMES DIV MOD;
%token  END; 
%token  OPEN_P CLOSE_P;
%token  CONDITIONAL;
%token  EXEC END_EXEC;
%token  IF ELSE;
%token  ESCAPE;
%token  WHILE;
%token  L G LE GE EQ NE OR AND;
%token  ASSIGN;  
%token  RETURN;
%token  MAIN; 
%token  STDIN STDOUT CONVERT LENGTH; 
%token  FUNCTION; 
%token  COMMA;
%token  ARRAY;

%start start

/* Precedence */ 
%left PLUS MINUS
%left TIMES DIV

%%

start 
    : MAIN EXEC program END_EXEC    { if(!checkReturnType($3,KIND_INT)){yyerror("Wrong return type"); YYABORT;}$$ = malloc(16 +  strlen($3)); sprintf($$, "int main(){ %s }\n",$3); add($$, true);  } 
    | function start                { $$ = malloc(strlen($1)+strlen($2)+3); sprintf($$,"%s\n%s", $1, $2); add($$,true);}
    ;

function
    : INT FUNCTION ALPHA OPEN_P params CLOSE_P EXEC program END_EXEC    {if(checkIfFunctionExists($3)){yyerror("Function already declared."); YYABORT;} if(!checkReturnType($8,KIND_INT)){yyerror("Wrong return type"); YYABORT;}$$ = malloc(3+strlen($3)+strlen($5)+strlen($8)+ 8); sprintf($$, "%s %s(%s){\n%s}\n", "int", $3, $5, $8); add($$,true); addFunction($3,KIND_INT,$5); freeVars();}
    | STRING FUNCTION ALPHA OPEN_P params CLOSE_P EXEC program END_EXEC {if(checkIfFunctionExists($3)){yyerror("Function already declared."); YYABORT;} if(!checkReturnType($8,KIND_STRING)){yyerror("Wrong return type"); YYABORT;}$$ = malloc(7+strlen($3)+strlen($5)+strlen($8)+ 8); sprintf($$, "%s %s(%s){\n%s}\n", "char *", $3, $5, $8); add($$,true); addFunction($3,KIND_STRING,$5);freeVars();}
    | CHAR FUNCTION ALPHA OPEN_P params CLOSE_P EXEC program END_EXEC    {if(checkIfFunctionExists($3)){yyerror("Function already declared."); YYABORT;} if(!checkReturnType($8,KIND_CHAR)){yyerror("Wrong return type"); YYABORT;}$$ = malloc(4+strlen($3)+strlen($5)+strlen($8)+ 8); sprintf($$, "%s %s(%s){\n%s}\n", "char", $3, $5, $8); add($$,true); addFunction($3,KIND_CHAR,$5); freeVars();}
    ;

type
    : INT       {$$ = "int";}
    | STRING    {$$ = "char *";}
    | CHAR      {$$ = "char";}
    ;

params 
    : type ALPHA                { $$ = malloc(strlen($1)+strlen($2) +2); sprintf($$, "%s %s", $1, $2); add($$,true); if(strcmp($1,"int")==0){addVar($2, KIND_INT,1);}else{addVar($2, KIND_STRING,1);}}
    | type ALPHA COMMA params   { $$ = malloc(strlen($1)+strlen($2)+4+strlen($4)); sprintf($$, "%s %s, %s", $1, $2, $4); add($$,true);if(strcmp($1,"int")==0){addVar($2, KIND_INT,1);}else{addVar($2, KIND_STRING,1);}} 
    | /* lambda */              { $$ = ""; }
    ;

args 
    : assignment                { $$ = malloc(strlen($1)+1); sprintf($$, "%s", $1);add($$,true);}
    | assignment COMMA args     { $$ = malloc(strlen($1)+2+strlen($3)); sprintf($$,"%s,%s",$1,$3); add($$,true);}
    | call                      { $$ = $1;}
    | /* lambda */              { $$ = "";}
    ;

call
    : ALPHA OPEN_P  args CLOSE_P {if(!checkArgsOk($1,$3)){yyerror("Incompatible args for function"); YYABORT;} $$ = malloc(strlen($1)+3+strlen($3)); sprintf($$,"%s(%s)",$1,$3); add($$,true);} 
    ;

program 
    : var END program                                       { $$ = malloc(strlen($1)+3+strlen($3)); sprintf($$,"%s; %s",$1,$3); add($$,true);}
    | call END program                                      { $$ = malloc(strlen($1)+3+strlen($3)); sprintf($$,"%s; %s",$1,$3); add($$,true);}
    | RETURN assignment END                                 { $$ = malloc(strlen($2) +9); sprintf($$, "return %s;", $2); add($$,true);} 
    | get program                                           { $$ = malloc(strlen($1)+strlen($2)+5); sprintf($$,"%s %s",$1,$2); add($$, true);}
    | STDOUT out END program                                { char * print = printfParser($2); if(print==NULL){yyerror("Sintax error on P.\n Check if your variables exist."); YYABORT;} $$ = malloc(strlen($2)*2+5+strlen($4)+ 11); sprintf($$, "printf(%s);\n%s", print, $4); add($$,true); free(print);} 
    | OPEN_P rule operator rule CLOSE_P CONDITIONAL WHILE EXEC program END_EXEC program {   
                                                                                            if(!are_comparable($2, $4)) {
                                                                                                yyerror("Uncomparable data types");
                                                                                                YYABORT;
                                                                                            }
                                                                                            $$ = malloc(strlen($2)+10+strlen($3)+strlen($4)+strlen("while")+strlen($9)+strlen($11));
                                                                                            sprintf($$,"while(%s %s %s){%s}\n%s ",$2,$3,$4,$9,$11);
                                                                                            add($$,true);}
    | OPEN_P rule operator rule CLOSE_P CONDITIONAL IF EXEC program END_EXEC program {   
                                                                                            if(!are_comparable($2, $4)) {
                                                                                                yyerror("Uncomparable data types");
                                                                                                YYABORT;
                                                                                            }
                                                                                            $$ = malloc(strlen($2)+10+strlen($3)+strlen($4)+strlen("if")+strlen($9)+strlen($11));
                                                                                            sprintf($$,"if(%s %s %s){%s}\n%s ",$2,$3,$4,$9,$11);
                                                                                            add($$,true);}                                                                                        
    | OPEN_P rule operator rule CLOSE_P CONDITIONAL IF EXEC program END_EXEC ELSE EXEC program END_EXEC program {   
                                                                                                                        if(!are_comparable($2, $4)) {
                                                                                                                            yyerror("Uncomparable data types");
                                                                                                                            YYABORT;
                                                                                                                        }
                                                                                                                        $$ = malloc(25+strlen($2)+strlen($3)+strlen($4)+strlen($9)+strlen($13)+strlen($15));
                                                                                                                        sprintf($$,"if(%s %s %s){%s}\nelse{%s}\n%s ",$2,$3,$4,$9,$13,$15);
                                                                                                                        add($$,true);} 
    | /* lambda */                                          { $$ = "";}
    ;

get 
    : STDIN OPEN_P ALPHA COMMA DIGIT CLOSE_P END    { if(checkIfVarExists($3)){yyerror("That variable already exists, please choose another name"); YYABORT;}  $$ = malloc(2*strlen($3)+2*strlen($5)+ 30); sprintf($$,"char %s[%s];\nfgets(%s,%s,stdin);\n",$3,$5,$3,$5); add($$,true); addVar($3, KIND_STRING,1);}
    ;
    
out 
    : SPACE_ALPHA out                   { $$ = malloc(1 + strlen($1) + strlen($2)); sprintf($$, "%s%s", $1, $2); add($$,true);}
    | ESCAPE SPACE_ALPHA ESCAPE out     { $$ = malloc(3 + strlen($2) + strlen($4)); sprintf($$, "\'%s\'%s", $2, $4); add($$,true);}
    | /* lambda */                      { $$ = ""; }
    | ALPHA out                         { $$ = malloc(1 + strlen($1) + strlen($2)); sprintf($$, "%s%s", $1, $2); add($$,true);}
    | ESCAPE ALPHA ESCAPE out           { $$ = malloc(3 + strlen($2) + strlen($4)); sprintf($$, "\'%s\'%s", $2, $4); add($$,true);}
   
    ; 

var
    : INT ALPHA ASSIGN DIGIT operation              { if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;} $$ = malloc(3+strlen($2)+6+strlen($4)+strlen($5)); sprintf($$,"%s %s=%s%s","int",$2,$4,$5); add($$,true); addVar($2, KIND_INT,1);}
    | INT ALPHA ASSIGN ALPHA operation              { if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!isOfKind($4,KIND_INT)){yyerror("Variable should be int type."); YYABORT;}$$ = malloc(3+strlen($2)+6+strlen($4)+strlen($5)); sprintf($$,"%s %s=%s%s","int",$2,$4,$5); add($$,true); addVar($2, KIND_INT,1);} 
    | STRING ALPHA ASSIGN STRING_VALUE              { if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;}$$ = malloc(7+strlen($2)+6+strlen($4)); $4[strlen($4) - 1] = 0;sprintf($$,"%s %s=\"%s\"","char *",$2,$4+1); add($$,true); addVar($2, KIND_STRING,1);}
    | STRING ALPHA ASSIGN ALPHA                     { if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!isOfKind($4,KIND_STRING)){yyerror("Variable should be string type"); YYABORT;}$$ = malloc(7+strlen($2)+6+strlen($4)); sprintf($$,"%s %s=%s","char *",$2,$4); add($$,true); addVar($2, KIND_STRING,1);}
    | CHAR ALPHA ASSIGN ESCAPE ALPHA                { if(strlen($5)!=1){yyerror("Incompatible initialization for type char."); YYABORT;}if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;}$$ = malloc(7+strlen($2)+6+strlen($5));sprintf($$,"char %s=\'%s\'",$2,$5); add($$,true); addVar($2, KIND_CHAR,1);} 
    | INT ALPHA ARRAY DIGIT ASSIGN digit_array      { if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;}if(array_is_incorrect($6,atoi($4))){yyerror("Bad initialization of array"); YYABORT;} $$ = malloc(3+strlen($2)+10+strlen($4)+strlen($6)); sprintf($$,"%s %s[%s]={%s}","int",$2,$4,$6);add($$,true); addVar($2, KIND_ARRAY_INT,atoi($4)); }
    | STRING ALPHA ARRAY DIGIT ASSIGN alpha_array   { if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;}if(array_is_incorrect($6,atoi($4))){yyerror("Bad initialization of array"); YYABORT;} $$ = malloc(7+strlen($2)+10+strlen($4)+strlen($6)); sprintf($$,"%s %s[%s]={%s}","char *",$2,$4,$6);add($$,true); addVar($2, KIND_ARRAY_STRING,atoi($4));}
    | INT ALPHA ASSIGN CONVERT OPEN_P ALPHA CLOSE_P { if(!isOfKind($6,KIND_STRING)){yyerror("Variable to convert should be string type."); YYABORT;} $$ = malloc(7+strlen($6)+3+strlen($2)+6); sprintf($$,"int %s = atoi(%s)",$2,$6); add($$,true); addVar($2, KIND_INT,1);}
    | INT ALPHA ASSIGN LENGTH OPEN_P ALPHA CLOSE_P  { if(!isOfKind($6,KIND_STRING)){yyerror("Variable should be string type."); YYABORT;}$$ = malloc(strlen($6)+strlen($2) +15); sprintf($$,"int %s=strlen(%s)",$2, $6); add($$,true);addVar($2, KIND_INT,1);}      
    | INT ALPHA ASSIGN ALPHA ARRAY DIGIT            { if(!correctArray($4,KIND_ARRAY_INT,atoi($6))){yyerror("Variables aren't compatible.");YYABORT;}$$ = malloc(3+strlen($2)+6+strlen($4)+strlen($6)); sprintf($$, "int %s=%s[%s]", $2, $4, $6);add($$,true);addVar($2, KIND_INT,1);}
    | STRING ALPHA ASSIGN ALPHA ARRAY DIGIT         { if(!correctArray($4,KIND_ARRAY_STRING,atoi($6))){yyerror("Variables aren't compatible.");YYABORT;}$$ = malloc(7+strlen($2)+6+strlen($4)+strlen($6)); sprintf($$, "char * %s=%s[%s]", $2, $4, $6);add($$,true);addVar($2, KIND_STRING,1);}
    | INT ALPHA ASSIGN ALPHA ARRAY ALPHA            { if(!isOfKind($6,KIND_INT)){yyerror("Variable should be int type to de-reference.");YYABORT;}if(!correctArray($4,KIND_ARRAY_INT,atoi($6))){yyerror("Variables aren't compatible.");YYABORT;}$$ = malloc(3+strlen($2)+6+strlen($4)+strlen($6)); sprintf($$, "int %s=%s[%s]", $2, $4, $6);add($$,true);addVar($2, KIND_INT,1);}
    | STRING ALPHA ASSIGN ALPHA ARRAY ALPHA         { if(!isOfKind($6,KIND_INT)){yyerror("Variable should be int type to de-reference.");YYABORT;}if(!correctArray($4,KIND_ARRAY_STRING,atoi($6))){yyerror("Variables aren't compatible.");YYABORT;}$$ = malloc(7+strlen($2)+6+strlen($4)+strlen($6)); sprintf($$, "char * %s=%s[%s]", $2, $4, $6);add($$,true);addVar($2, KIND_STRING,1);}
    | CHAR ALPHA ASSIGN ALPHA                       { if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!isOfKind($4,KIND_CHAR)){yyerror("Variable should be char type."); YYABORT;}$$ = malloc(4+strlen($2)+6+strlen($4)); sprintf($$,"%s %s=%s","char",$2,$4); add($$,true); addVar($2, KIND_CHAR,1);}


    | INT ALPHA                                 { if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;}$$ = malloc(3+strlen($2)+2); sprintf($$,"%s %s","int",$2);add($$,true); addVar($2, KIND_INT,1);}
    | CHAR ALPHA                                { if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;}$$ = malloc(5+strlen($2)+2); sprintf($$,"char %s",$2);add($$,true); addVar($2, KIND_CHAR,1);}
    | STRING ALPHA                              { if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;}$$ = malloc(7+strlen($2)+2); sprintf($$,"%s %s","char *",$2);add($$,true); addVar($2, KIND_STRING,1);}
    | INT ALPHA ARRAY DIGIT                     { if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;} $$ = malloc(3+strlen($2)+5+strlen($4)); sprintf($$,"%s %s[%s]","int",$2,$4);add($$,true); addVar($2, KIND_ARRAY_INT,atoi($4)); }
    | STRING ALPHA ARRAY DIGIT                  { if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;} $$ = malloc(7+strlen($2)+5+strlen($4)); sprintf($$,"%s %s[%s]","char *",$2,$4);add($$,true); addVar($2, KIND_ARRAY_STRING,atoi($4));}
     
    | ALPHA ASSIGN ALPHA                        { if((!checkIfVarExists($1)||!checkIfVarExists($3))|| !are_comparable($1,$3)){yyerror("Variables aren't compatible."); YYABORT;}$$ = malloc(4+strlen($1)+6+strlen($3)); sprintf($$,"%s=%s",$1,$3); add($$,true);}
    | ALPHA ASSIGN ESCAPE ALPHA                 { if(!isOfKind($1,KIND_CHAR)){yyerror("Variable should be int type.");YYABORT;}if(strlen($4)!=1){yyerror("Incompatible initialization for type char."); YYABORT;}$$ = malloc(strlen($1)+strlen($4)+10); sprintf($$, "%s=\'%s\'", $1, $4);add($$,true);}
    | ALPHA ASSIGN DIGIT                        { if(!isOfKind($1,KIND_INT)){yyerror("Variable should be int type.");YYABORT;}$$ = malloc(strlen($1)+strlen($3)+5); sprintf($$, "%s=%s", $1, $3);add($$,true);}
    | ALPHA ASSIGN STRING_VALUE                 { if(!isOfKind($1,KIND_STRING)){yyerror("Variable should be string type.");YYABORT;}$$ = malloc(strlen($1)+strlen($3)+5); $3[strlen($3) - 1] = 0;sprintf($$, "%s=\"%s\"", $1, $3+1); add($$,true);}
    | ALPHA ASSIGN assignment operation         { if(!isOfKind($1,KIND_INT)){yyerror("Variable should be int type."); YYABORT;}$$ = malloc(strlen($1)+strlen($3)+strlen($4)+5);  sprintf($$, "%s=%s%s", $1, $3, $4); add($$,true);}
    | ALPHA ASSIGN ALPHA ARRAY DIGIT            { if(!compatibleArray($1,$3,atoi($5))){yyerror("Variables aren't compatible.");YYABORT;}$$ = malloc(strlen($1)+strlen($3)+strlen($5) +5); sprintf($$, "%s=%s[%s]", $1, $3, $5);add($$,true);}
    | ALPHA ASSIGN ALPHA ARRAY ALPHA            { if(!isOfKind($5,KIND_INT)){yyerror("Variable should be int type to de-reference.");YYABORT;}if(!compatibleArray($1,$3,0)){yyerror("Variables aren't compatible.");YYABORT;}$$ = malloc(strlen($1)+strlen($3)+strlen($5) +5); sprintf($$, "%s=%s[%s]", $1, $3, $5);add($$,true);}
    | ALPHA ASSIGN CONVERT OPEN_P ALPHA CLOSE_P { if(!isOfKind($1,KIND_INT)){yyerror("Variable to assign should be int type."); YYABORT;} if(!isOfKind($5,KIND_STRING)){yyerror("Argument should be string type."); YYABORT;} $$ = malloc(strlen($1)+strlen($5)+10); sprintf($$,"%s = atoi(%s)",$1,$5); add($$,true);}
    | ALPHA ASSIGN LENGTH OPEN_P ALPHA CLOSE_P  { if(!isOfKind($1,KIND_INT)){yyerror("Variable to assign should be int type."); YYABORT;} if(!isOfKind($5,KIND_STRING)){yyerror("Argument hould be string type."); YYABORT;}$$ = malloc(strlen($1)+strlen($5)+10); sprintf($$,"%s=strlen(%s)",$1, $5); add($$,true);}      
  

    | INT ALPHA ASSIGN call                     { if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!functionReturnsKind($4, KIND_INT)){yyerror("Function should return type int"); YYABORT;} $$ = malloc(3+strlen($2)+3+strlen($4)); sprintf($$,"int %s=%s",$2,$4); add($$,true); addVar($2, KIND_INT,1);}
    | STRING ALPHA ASSIGN call                  { if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!functionReturnsKind($4, KIND_STRING)){yyerror("Function should return type string"); YYABORT;} $$ = malloc(7+strlen($2)+3+strlen($4)); sprintf($$,"char* %s=%s",$2,$4); add($$,true); addVar($2, KIND_STRING,1);}
    | CHAR ALPHA ASSIGN call                    { if(checkIfVarExists($2)){yyerror("That variable already exists, please choose another name"); YYABORT;}if(!functionReturnsKind($4, KIND_CHAR)){yyerror("Function should return type char"); YYABORT;} $$ = malloc(strlen($2)+8+strlen($4)); sprintf($$,"char %s=%s",$2,$4); add($$,true); addVar($2, KIND_CHAR,1);}   
    | ALPHA ASSIGN call                         { $$ = malloc(strlen($1)+2+strlen($3)); sprintf($$,"%s=%s",$1,$3);add($$,true);}


    | ALPHA ARRAY DIGIT ASSIGN DIGIT            { if (!isOfKind($1, KIND_ARRAY_INT)){yyerror("Variable should be string array type"); YYABORT;} if(! enoughSpace($1, atoi($3)) ) { yyerror("Array has not enough space"); YYABORT; } $$ = malloc(strlen($1) + strlen($3) + strlen($5) + 4 ); sprintf($$, "%s[%s]=%s", $1, $3, $5); add($$, true); }
    | ALPHA ARRAY DIGIT ASSIGN STRING_VALUE     { if (!isOfKind($1, KIND_ARRAY_STRING)){yyerror("Variable should be string array type"); YYABORT;} if(! enoughSpace($1, atoi($3)) ) { yyerror("Array has not enough space"); YYABORT; } $$ = malloc(strlen($1) + strlen($3) + strlen($5) + 4 ); $5[strlen($5) - 1] = 0; sprintf($$, "%s[%s]=\"%s\"", $1, $3, $5+1); add($$, true); }
     
    ; 
    
operation
    : op DIGIT operation   { $$ = malloc(strlen($1)+ 1 + strlen($2) + strlen($3)); sprintf($$,"%s%s%s",$1,$2,$3 ); add($$,true);}
    | op ALPHA operation   { if (!isOfKind($2, KIND_INT)){yyerror("Variable should be int type"); YYABORT;}$$ = malloc(strlen($1)+ 1 + strlen($2) + strlen($3)); sprintf($$,"%s%s%s",$1,$2,$3 ); add($$,true);}
    | /* lambda */         { $$ = "";}
    ;
    
assignment
    : ALPHA         {$$ = $1;}
    | DIGIT         {$$ = $1;}
    | STRING_VALUE  {
        $1[strlen($1) - 1]  = '\"';
        $1[0]               = '\"';
        $$ = $1;
        }
    | ESCAPE ALPHA   { if(strlen($2)!=1){yyerror("Incompatible initialization for type char."); YYABORT;}$$ = malloc(strlen($2)+3); sprintf($$, "\'%s\'", $2);add($$,true);}
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
    : OPEN_P rule operator rule CLOSE_P {   
                                            if(!are_comparable($2, $4)) {
                                                yyerror("Uncomparable data types");
                                                YYABORT;
                                            }
                                            $$ = malloc(strlen($2) + strlen($3) + strlen($4) + 5);
                                            sprintf($$, "(%s %s %s)", $2, $3, $4);
                                            add($$,true);}

    | assignment                        { $$ = malloc(strlen($1)+1); sprintf($$, "%s", $1); add($$, true);}
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
    | OR    { $$ = "||";}
    | AND   { $$ = "&&";}
    ;

op 
    : PLUS  { $$ = "+";}
    | MINUS { $$ = "-";}
    | DIV   { $$ = "/";}
    | TIMES { $$ = "*";}
    | MOD   { $$ = "%";}
    ;

%%
