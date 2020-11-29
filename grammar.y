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

extern int yylineno;

void yyerror(const char *str)
{
  fprintf(stderr,"Error at line %d: %s\n",yylineno,str);
  freeResources(true); 
  program.error = true;
} 
%}

%union {
	char * stringValue;
}

/* Non Terminals */ 
%type<stringValue> rule constant var_init type op start operator params out get function program assignment operation var call args digit_array alpha_array char_array;

/* Terminals */ 
%token<stringValue>  DIGIT ALPHA SPACE_ALPHA STRING_VALUE;
%token<stringValue>  INT STRING CHAR; 

%token  IF;
%token  ESCAPE;
%token  WHILE;
%token  LE GE NE;
  
%token  RETURN;  
%token  MAIN STDIN STDOUT CONVERT LENGTH FUNCTION; 
%token  INT_DEFINE STRING_DEFINE CHAR_DEFINE;

%start start

/* Precedence */ 
%left '+' '-'
%left '*' '/' '%'

%%

/** General structure for a label
** - Checkings:         Necessary for avoiding warnings in syntax valid clauses ¿
** - $$ = malloc(...):  Alloc the necessary space for the String that will be generated for the compiler
** - sprintf($$, ...):  Store the C code string for compiling
** - add($$, true):     Save the allocked pointer in order to free it later
** - addVar():          Stores variables in a similar way to a symbol table
** - declareFunction(): Stores function name, params and return type
*/

start 
    :
    /* Main function (entry point) */
    MAIN '{' program '}'      {
                                        if(!checkReturnType($3,KIND_INT)) {
                                            yyerror("Wrong return type");
                                            YYABORT;
                                        }
                                        $$ = malloc(16 +  strlen($3));
                                        sprintf($$, "int main(){ %s }\n",$3);
                                        add($$, true); 
                                    } 
    
    /* Function before program */
    | function start                {
                                        $$ = malloc(strlen($1)+strlen($2)+3);
                                        sprintf($$,"%s\n%s", $1, $2);
                                        add($$,true);
                                    }
    
    /* Constant before program */
    | constant start                {
                                        $$ = malloc(strlen($1)+strlen($2)+3);
                                        sprintf($$,"%s\n%s", $1, $2);
                                        add($$,true);
                                    }
    ;
    
constant
    :
    /* Integer Constant */
    INT_DEFINE ALPHA DIGIT              {
                                            if(checkIfVarExists($2)){
                                                yyerror("That constant is already declared");
                                                YYABORT;
                                            }
                                            $$ = malloc(strlen($3)+strlen($2)+11);
                                            sprintf($$, "#define %s %s\n", $2, $3);
                                            add($$,true);
                                            addVar($2, KIND_INT, 1,true);
                                        }

    /* Character Constant */
    | CHAR_DEFINE ALPHA ESCAPE ALPHA    {
                                            if(checkIfVarExists($2)){
                                                yyerror("That constant is already declared");
                                                YYABORT;
                                            }
                                            $$ = malloc(strlen($4)+strlen($2)+14);
                                            sprintf($$, "#define %s \'%s\'\n", $2, $4);
                                            add($$,true);
                                            addVar($2, KIND_CHAR, 1,true);
                                        }

    /* String Constant */                   
    | STRING_DEFINE ALPHA STRING_VALUE  {
                                            if(checkIfVarExists($2)) {
                                                yyerror("That constant is already declared");
                                                YYABORT;
                                            }
                                            $3[strlen($3) - 1] = '\"';
                                            $3[0] = '\"';
                                            $$ = malloc(strlen($3)+strlen($2)+11);
                                            sprintf($$, "#define %s %s\n", $2, $3);
                                            add($$,true);
                                            addVar($2, KIND_STRING, 1,true);
                                        }     
    ; 


function
    :
    /* Integer Function Definition: i$ F f_name (...) { ... } */
    INT FUNCTION ALPHA '(' params ')' '{' program '}'       {
                                                                if(strcmp($3, "main")==0){
                                                                    yyerror("That name is not permitted. Please choose another one.");
                                                                    YYABORT;
                                                                }
                                                                if(checkIfFunctionExists($3)) {
                                                                    yyerror("Function already declared."); 
                                                                    YYABORT;
                                                                }
                                                                if(!checkReturnType($8,KIND_INT)){
                                                                    yyerror("Wrong return type");
                                                                    YYABORT;
                                                                }
                                                                $$ = malloc(3+strlen($3)+strlen($5)+strlen($8)+ 8);
                                                                sprintf($$, "%s %s(%s){\n%s}\n", "int", $3, $5, $8);
                                                                add($$,true);
                                                                addFunction($3,KIND_INT,$5);
                                                                freeVars(false);
                                                            }

    /* String Function Definition: s$ F f_name (...) { ... } */
    | STRING FUNCTION ALPHA '(' params ')' '{' program '}'  {
                                                                if(strcmp($3, "main")==0){
                                                                    yyerror("That name is not permitted. Please choose another one.");
                                                                    YYABORT;
                                                                }
                                                                if(checkIfFunctionExists($3)){
                                                                    yyerror("Function already declared.");
                                                                    YYABORT;
                                                                }
                                                                if(!checkReturnType($8,KIND_STRING)){
                                                                    yyerror("Wrong return type");
                                                                    YYABORT;
                                                                }
                                                                $$ = malloc(7+strlen($3)+strlen($5)+strlen($8)+ 8);
                                                                sprintf($$, "%s %s(%s){\n%s}\n", "char *", $3, $5, $8);
                                                                add($$,true);
                                                                addFunction($3,KIND_STRING,$5);
                                                                freeVars(false);
                                                            }

    /* Character Function Definition: c$ F f_name (...) { ... } */                                                        
    | CHAR FUNCTION ALPHA '(' params ')' '{' program '}'    {
                                                                if(strcmp($3, "main")==0){
                                                                    yyerror("That name is not permitted. Please choose another one.");
                                                                    YYABORT;
                                                                }
                                                                if(checkIfFunctionExists($3)){
                                                                    yyerror("Function already declared.");
                                                                    YYABORT;
                                                                }
                                                                if(!checkReturnType($8,KIND_CHAR)){
                                                                    yyerror("Wrong return type");
                                                                    YYABORT;
                                                                }
                                                                $$ = malloc(4+strlen($3)+strlen($5)+strlen($8)+ 8);
                                                                sprintf($$, "%s %s(%s){\n%s}\n", "char", $3, $5, $8);
                                                                add($$,true);
                                                                addFunction($3,KIND_CHAR,$5);
                                                                freeVars(false);
                                                            }

    /* Integer Function Declaration: i$ F f_name (...) . */                                                        
    | INT FUNCTION ALPHA '(' params ')' '.'                 {
                                                                if(strcmp($3, "main")==0){
                                                                    yyerror("That name is not permitted. Please choose another one.");
                                                                    YYABORT;
                                                                }
                                                                if(checkIfFunctionExists($3)){
                                                                    yyerror("Function already declared.");
                                                                    YYABORT;
                                                                }
                                                                $$ = malloc(4+strlen($3)+strlen($5)+ 7);
                                                                sprintf($$, "%s %s(%s);\n", "int", $3, $5);
                                                                add($$,true);
                                                                declareFunction($3,KIND_INT,$5);
                                                                freeVars(false);
                                                            }    

    /* String Function Declaration: s$ F f_name (...) . */
    | STRING FUNCTION ALPHA '(' params ')' '.'              {
                                                                if(strcmp($3, "main")==0){
                                                                    yyerror("That name is not permitted. Please choose another one.");
                                                                    YYABORT;
                                                                }
                                                                if(checkIfFunctionExists($3)){
                                                                    yyerror("Function already declared.");
                                                                    YYABORT;
                                                                }
                                                                $$ = malloc(4+strlen($3)+strlen($5)+ 9);
                                                                sprintf($$, "%s %s(%s);\n", "char *", $3, $5);
                                                                add($$,true);
                                                                declareFunction($3,KIND_STRING,$5);
                                                                freeVars(false);
                                                            }  

    /* Character Function Declaration: c$ F f_name (...) . */
    | CHAR FUNCTION ALPHA '(' params ')' '.'                {
                                                                if(strcmp($3, "main")==0){
                                                                    yyerror("That name is not permitted. Please choose another one.");
                                                                    YYABORT;
                                                                }
                                                                if(checkIfFunctionExists($3)){
                                                                    yyerror("Function already declared.");
                                                                    YYABORT;
                                                                }
                                                                $$ = malloc(4+strlen($3)+strlen($5)+ 8);
                                                                sprintf($$, "%s %s(%s);\n", "char", $3, $5);
                                                                add($$,true);
                                                                declareFunction($3,KIND_CHAR,$5);
                                                                freeVars(false);
                                                            } 
    ;

type
    :
    /* Integer Data Type */
    INT       {   $$ = "int";     }

    /* String Data Type */
    | STRING    {   $$ = "char *";  }

    /* Character Data Type */
    | CHAR      {   $$ = "char";    }
    ;

params 
    :
    /* Last parameter */
    type ALPHA                  {
                                    $$ = malloc(strlen($1)+strlen($2) +2);
                                    sprintf($$, "%s %s", $1, $2);
                                    add($$,true);
                                    if(strcmp($1,"int")==0){
                                        addVar($2, KIND_INT,1,false);
                                    } else if (strcmp($1, "char *") == 0) {
                                        addVar($2, KIND_STRING,1,false);
                                    } else {
                                        addVar($2, KIND_CHAR, 1,false);
                                    }
                                }

    /* Append another parameter */
    | type ALPHA ',' params     {
                                    $$ = malloc(strlen($1)+strlen($2)+4+strlen($4));
                                    sprintf($$, "%s %s, %s", $1, $2, $4);
                                    add($$,true);
                                    if(strcmp($1,"int")==0){
                                        addVar($2, KIND_INT,1,false);
                                    } else if (strcmp($1, "char *") == 0) {
                                        addVar($2, KIND_STRING,1,false);
                                    } else {
                                        addVar($2, KIND_CHAR, 1,false);
                                    };
                                }

    | /* lambda */              {   $$ = "";    }
    ;

args
    :
    /* Last assignment */
    assignment                  {
                                    $$ = malloc(strlen($1)+1);
                                    sprintf($$, "%s", $1);
                                    add($$,true);
                                }
    /* Append another assignment */                            
    | assignment ',' args       {
                                    $$ = malloc(strlen($1)+2+strlen($3));
                                    sprintf($$,"%s,%s",$1,$3);
                                    add($$,true);
                                }
    /* Make function call */                            
    | call                      {   $$ = $1;    }

    | /* lambda */              {   $$ = "";    }
    ;

call
    :
    /* Function call f_name (...) */
    ALPHA '(' args ')'          {
                                    if(!checkArgsOk($1,$3)){
                                        yyerror("Incompatible args for function");
                                        YYABORT;
                                    }
                                    $$ = malloc(strlen($1)+3+strlen($3));
                                    sprintf($$,"%s(%s)",$1,$3);
                                    add($$,true);
                                } 
    ;

program 
    :
    /* Variable declaration */
    var '.' program         {
                                $$ = malloc(strlen($1)+3+strlen($3));
                                sprintf($$,"%s; %s",$1,$3);
                                add($$,true);
                            }
    
    /* Function call without assignment */                        
    | call '.' program      {
                                $$ = malloc(strlen($1)+3+strlen($3));
                                sprintf($$,"%s; %s",$1,$3);
                                add($$,true);
                            }
    
    /* Return statement: R ? */                        
    | RETURN assignment '.' {
                                $$ = malloc(strlen($2) +9);
                                sprintf($$, "return %s;", $2);
                                add($$,true);
                            } 
    
    /* STDIN function call */
    | get program           {
                                $$ = malloc(strlen($1)+strlen($2)+5);
                                sprintf($$,"%s %s",$1,$2);
                                add($$, true);
                            }
    
    /* STDOUT function call */
    | STDOUT out '.' program    {
                                    char * print = printfParser($2);
                                    if(print==NULL){
                                        yyerror("Sintax error on P.\n Check if your variables exist.");
                                        YYABORT;
                                    }
                                    $$ = malloc(strlen($2)*2+5+strlen($4)+ 11);
                                    sprintf($$, "printf(%s);\n%s", print, $4);
                                    add($$,true); free(print);
                                } 
    
    /* While Loop: ( CONDITION ) ? --> { ... } */
    | '(' rule operator rule ')' '?' WHILE '{' program '}' program  {   
                                                                        if(!are_comparable($2, $4)) {
                                                                            yyerror("Uncomparable data types");
                                                                            YYABORT;
                                                                        }
                                                                        $$ = malloc(strlen($2)+10+strlen($3)+strlen($4)+strlen("while")+strlen($9)+strlen($11));
                                                                        sprintf($$,"while(%s %s %s){%s}\n%s ",$2,$3,$4,$9,$11);
                                                                        add($$,true);
                                                                    }
    
    /* If Statement: ( CONDITION ) ? -> { ... } */
    | '(' rule operator rule ')' '?' IF '{' program '}' program     {   
                                                                        if(!are_comparable($2, $4)) {
                                                                            yyerror("Uncomparable data types");
                                                                            YYABORT;
                                                                        }
                                                                        $$ = malloc(strlen($2)+10+strlen($3)+strlen($4)+strlen("if")+strlen($9)+strlen($11));
                                                                        sprintf($$,"if(%s %s %s){%s}\n%s ",$2,$3,$4,$9,$11);
                                                                        add($$,true);
                                                                    }                                                                                        
    
    /* If-Else Statement: ( CONDITION ) ? -> { ... } : { ... } */
    | '(' rule operator rule ')' '?' IF '{' program '}' ':' '{' program '}' program    {   
                                                                                            if(!are_comparable($2, $4)) {
                                                                                                yyerror("Uncomparable data types");
                                                                                                YYABORT;
                                                                                            }
                                                                                            $$ = malloc(25+strlen($2)+strlen($3)+strlen($4)+strlen($9)+strlen($13)+strlen($15));
                                                                                            sprintf($$,"if(%s %s %s){%s}\nelse{%s}\n%s ",$2,$3,$4,$9,$13,$15);
                                                                                            add($$,true);
                                                                                        } 
    
    | /* lambda */      {   $$ = "";    }
    ;

get 
    :
    /* Input function: G(buffer_name, size) */
    STDIN '(' ALPHA ',' DIGIT ')' '.'    { 
                                            if(checkIfVarExists($3)){
                                                yyerror("That variable already exists, please choose another name"); 
                                                YYABORT;
                                            }
                                            $$ = malloc(2*strlen($3)+2*strlen($5)+ 30); 
                                            sprintf($$,"char %s[%s];\nfgets(%s,%s,stdin);\n",$3,$5,$3,$5); 
                                            add($$,true); 
                                            addVar($3, KIND_ARRAY_CHAR,1,false);
                                        }
    ;
    
out
    :
    
    /* Spaced alphnum characters */
    SPACE_ALPHA out                     { 
                                            $$ = malloc(1 + strlen($1) + strlen($2)); 
                                            sprintf($$, "%s%s", $1, $2); 
                                            add($$,true);
                                        }
    
    /* Escaped spaced alphnum characters */
    | ESCAPE SPACE_ALPHA ESCAPE out     { 
                                            $$ = malloc(3 + strlen($2) + strlen($4)); 
                                            sprintf($$, "\'%s\'%s", $2, $4); 
                                            add($$,true);
                                        }
    
    
    | /* lambda */                      {   $$ = "";    }
    
    /* Alphnum characters */
    | ALPHA out                         {
                                            $$ = malloc(1 + strlen($1) + strlen($2));
                                            sprintf($$, "%s%s", $1, $2); 
                                            add($$,true);
                                        }
    
    
    /* Escaped alphnum characters: Vars */
    | ESCAPE ALPHA ESCAPE out           { 
                                            $$ = malloc(3 + strlen($2) + strlen($4)); 
                                            sprintf($$, "\'%s\'%s", $2, $4); 
                                            add($$,true);
                                        }
   
    ; 

var
    :
    /* Integer: i$ var_name = INT_VALUE  */
    INT ALPHA '=' DIGIT operation               {
                                                    if(strcmp($2, "int")==0){
                                                        yyerror("That name is not permitted. Please choose another one");
                                                        YYABORT;
                                                    } if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name");
                                                        YYABORT;
                                                    } 
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name");
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(3+strlen($2)+6+strlen($4)+strlen($5));
                                                    sprintf($$,"%s %s=%s%s","int",$2,$4,$5);
                                                    add($$,true);
                                                    addVar($2, KIND_INT,1,false);
                                                }
    
    /* Integer: i$ var_name = var_name2 */
    | INT ALPHA '=' ALPHA operation              {
                                                    if(strcmp($2, "int")==0){
                                                        yyerror("That name is not permitted. Please choose another one");
                                                        YYABORT;
                                                    }
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name");
                                                        YYABORT;
                                                    }
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name");
                                                        YYABORT;
                                                    }
                                                    if(!isOfKind($4,KIND_INT)){
                                                        yyerror("Variable should be int type.");
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(3+strlen($2)+6+strlen($4)+strlen($5));
                                                    sprintf($$,"%s %s=%s%s","int",$2,$4,$5);
                                                    add($$,true);
                                                    addVar($2, KIND_INT,1,false);
                                                } 
    
    /* String: s$ var_name = STRING_VALUE  */
    | STRING ALPHA '=' STRING_VALUE              {
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name");
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(7+strlen($2)+6+strlen($4));
                                                    $4[strlen($4) - 1] = 0;
                                                    sprintf($$,"%s %s=\"%s\"","char *",$2,$4+1);
                                                    add($$,true);
                                                    addVar($2, KIND_STRING,1,false);
                                                }
    
    /* String: s$ var_name = var_name2  */
    | STRING ALPHA '=' ALPHA                     {
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name");
                                                        YYABORT;
                                                    }
                                                    if(!isOfKind($4,KIND_STRING)){
                                                        yyerror("Variable should be string type");
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(7+strlen($2)+6+strlen($4));
                                                    sprintf($$,"%s %s=%s","char *",$2,$4);
                                                    add($$,true); 
                                                    addVar($2, KIND_STRING,1,false);
                                                }
    
    /* Char: c$ var_name = SINGLE_ALPHA_VALUE  */
    | CHAR ALPHA '=' ESCAPE ALPHA                {
                                                    if(strcmp($2, "char")==0){
                                                        yyerror("That name is not permitted. Please choose another one"); 
                                                        YYABORT;
                                                    }   
                                                    if(strlen($5)!=1){
                                                        yyerror("Incompatible initialization for type char."); 
                                                        YYABORT;
                                                    }
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name");
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(7+strlen($2)+6+strlen($5));
                                                    sprintf($$,"char %s=\'%s\'",$2,$5); 
                                                    add($$,true); 
                                                    addVar($2, KIND_CHAR,1,false);
                                                } 
    
    /* Char: c$ var_name = SINGLE_DIGIT_VALUE */
    | CHAR ALPHA '=' ESCAPE DIGIT                { 
                                                    if(strcmp($2, "char")==0){
                                                        yyerror("That name is not permitted. Please choose another one"); 
                                                        YYABORT;
                                                    } 
                                                    if(strlen($5)!=1){
                                                        yyerror("Incompatible initialization for type char."); 
                                                        YYABORT;
                                                    }if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name"); 
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(7+strlen($2)+6+strlen($5));
                                                    sprintf($$,"char %s=\'%s\'",$2,$5);
                                                    add($$,true); 
                                                    addVar($2, KIND_CHAR,1,false);
                                                } 
    
    /* Char: c$ var_name = var_name2 */
    | CHAR ALPHA '=' ALPHA                      { 
                                                    if(strcmp($2, "char")==0){
                                                        yyerror("That name is not permitted. Please choose another one"); 
                                                        YYABORT;
                                                    } 
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name"); 
                                                        YYABORT;
                                                    }
                                                    if(!isOfKind($4,KIND_CHAR)){
                                                        yyerror("Variable should be char type."); 
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(4+strlen($2)+6+strlen($4)); 
                                                    sprintf($$,"%s %s=%s","char",$2,$4); 
                                                    add($$,true); 
                                                    addVar($2, KIND_CHAR,1,false);
                                                }
    
    /* Integer Array: i$ name_LENGTH = ... */
    | INT ALPHA '_' DIGIT '=' digit_array       { 
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name"); 
                                                        YYABORT;
                                                    }
                                                    if(array_is_incorrect($6,atoi($4))){
                                                        yyerror("Bad initialization of '_'"); 
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(3+strlen($2)+10+strlen($4)+strlen($6)); 
                                                    sprintf($$,"%s %s[%s]={%s}","int",$2,$4,$6);
                                                    add($$,true); 
                                                    addVar($2, KIND_ARRAY_INT,atoi($4),false); 
                                                }
    
    /* String Array: s$ name_LENGTH = ... */
    | STRING ALPHA '_' DIGIT '=' alpha_array    {
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name"); 
                                                        YYABORT;
                                                    }
                                                    if(array_is_incorrect($6,atoi($4))){
                                                        yyerror("Bad initialization of '_'"); 
                                                        YYABORT;
                                                    } 
                                                    $$ = malloc(7+strlen($2)+10+strlen($4)+strlen($6)); 
                                                    sprintf($$,"%s %s[%s]={%s}","char *",$2,$4,$6);
                                                    add($$,true); 
                                                    addVar($2, KIND_ARRAY_STRING,atoi($4),false);
                                                }
    
    /* Char Array: c$ name_LENGTH = ... */
    | CHAR ALPHA '_' DIGIT '=' char_array   { 
                                                if(checkIfVarExists($2)){
                                                    yyerror("That variable already exists, please choose another name"); 
                                                    YYABORT;
                                                }
                                                if(array_is_incorrect($6,atoi($4))){
                                                    yyerror("Bad initialization of '_'"); 
                                                    YYABORT;
                                                } 
                                                $$ = malloc(7+strlen($2)+10+strlen($4)+strlen($6)); 
                                                sprintf($$,"%s %s[%s]={%s}","char",$2,$4,$6);
                                                add($$,true); 
                                                addVar($2, KIND_ARRAY_CHAR,atoi($4),false);
                                            }
    
    /* Integer Array: i$ name_LENGTH = ... */
    | INT ALPHA '=' CONVERT '(' ALPHA ')'   { 
                                                if(strcmp($2, "int")==0){
                                                    yyerror("That name is not permitted. Please choose another one"); 
                                                    YYABORT;
                                                } 
                                                if(checkIfVarExists($2)){
                                                    yyerror("That variable already exists, please choose another name"); 
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($6,KIND_STRING) && !isOfKind($6,KIND_ARRAY_CHAR)){
                                                    yyerror("Variable to convert should be string type."); 
                                                    YYABORT;
                                                } 
                                                $$ = malloc(7+strlen($6)+3+strlen($2)+6); 
                                                sprintf($$,"int %s = atoi(%s)",$2,$6); 
                                                add($$,true); 
                                                addVar($2, KIND_INT,1,false);
                                            }
    
    
    | INT ALPHA '=' LENGTH '(' ALPHA ')'  { 
                                            if(strcmp($2, "int")==0){
                                                yyerror("That name is not permitted. Please choose another one"); 
                                                YYABORT;
                                            } 
                                            if(checkIfVarExists($2)){
                                                yyerror("That variable already exists, please choose another name"); 
                                                YYABORT;
                                            } 
                                            if(!isOfKind($6,KIND_STRING) && !isOfKind($6,KIND_ARRAY_CHAR)){
                                                yyerror("Variable should be string type."); 
                                            YYABORT;
                                            }
                                            $$ = malloc(strlen($6)+strlen($2) +15); 
                                            sprintf($$,"int %s=strlen(%s)",$2, $6); 
                                            add($$,true);
                                            addVar($2, KIND_INT,1,false);
                                        }      
    
    /* Integer Assign to Array: i$ name = arr_INDEX */
    | INT ALPHA '=' ALPHA '_' DIGIT             { 
                                                    if(strcmp($2, "int")==0){
                                                        yyerror("That name is not permitted. Please choose another one"); 
                                                        YYABORT;
                                                    } 
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name");
                                                        YYABORT;
                                                    }
                                                    if(!correctArray($4,KIND_ARRAY_INT,atoi($6))){
                                                        yyerror("Variables aren't compatible.");
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(3+strlen($2)+6+strlen($4)+strlen($6)); 
                                                    sprintf($$, "int %s=%s[%s]", $2, $4, $6);
                                                    add($$,true);
                                                    addVar($2, KIND_INT,1,false);
                                                }
    
    /* String Assign to Array: s$ name = arr_INDEX */
    | STRING ALPHA '=' ALPHA '_' DIGIT         {
                                                    if(!correctArray($4,KIND_ARRAY_STRING,atoi($6))){
                                                        yyerror("Variables aren't compatible.");
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(7+strlen($2)+6+strlen($4)+strlen($6)); 
                                                    sprintf($$, "char * %s=%s[%s]", $2, $4, $6);
                                                    add($$,true);
                                                    addVar($2, KIND_STRING,1,false);
                                                }
    
    /* Integer Assign to Array: i$ name = arr_VAR */
    | INT ALPHA '=' ALPHA '_' ALPHA             { 
                                                    if(strcmp($2, "int")==0){
                                                        yyerror("That name is not permitted. Please choose another one"); 
                                                        YYABORT;
                                                    } 
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name"); 
                                                        YYABORT;
                                                    } 
                                                    if(!isOfKind($6,KIND_INT)){
                                                        yyerror("Variable should be int type to de-reference.");
                                                        YYABORT;
                                                    }
                                                    if(!isOfKind($4,KIND_ARRAY_INT)){
                                                        yyerror("Variables aren't compatible.");
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(3+strlen($2)+6+strlen($4)+strlen($6)); 
                                                    sprintf($$, "int %s=%s[%s]", $2, $4, $6);
                                                    add($$,true);
                                                    addVar($2, KIND_INT,1,false);
                                                }
    
    /* String Assign to Array: s$ name = arr_INDEX */
    | STRING ALPHA '=' ALPHA '_' ALPHA         { 
                                                    if(!isOfKind($6,KIND_INT)){
                                                        yyerror("Variable should be int type to de-reference.");
                                                        YYABORT;
                                                    }
                                                    if(!isOfKind($4,KIND_ARRAY_STRING)){
                                                        yyerror("Variables aren't compatible.");
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(7+strlen($2)+6+strlen($4)+strlen($6)); 
                                                    sprintf($$, "char * %s=%s[%s]", $2, $4, $6);
                                                    add($$,true);
                                                    addVar($2, KIND_STRING,1,false);
                                                }
    
    /* Char Assign to Array: c$ name = arr_INDEX */
    | CHAR ALPHA '=' ALPHA '_' DIGIT            { 
                                                    if(strcmp($2, "char")==0){
                                                        yyerror("That name is not permitted. Please choose another one");
                                                        YYABORT;
                                                    }
                                                    if(!correctArray($4,KIND_ARRAY_CHAR,atoi($6))){
                                                        yyerror("Variables aren't compatible.");
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(4+strlen($2)+6+strlen($4)+strlen($6)); 
                                                    sprintf($$, "char %s=%s[%s]", $2, $4, $6);
                                                    add($$,true);
                                                    addVar($2, KIND_CHAR,1,false);
                                                }
    
    /* Char Assign to Array: c$ name = arr_VAR */
    | CHAR ALPHA '=' ALPHA '_' ALPHA            { 
                                                    if(strcmp($2, "char")==0){
                                                        yyerror("That name is not permitted. Please choose another one"); 
                                                        YYABORT;
                                                    } 
                                                    if(!isOfKind($6,KIND_INT)){
                                                        yyerror("Variable should be int type to de-reference.");
                                                        YYABORT;
                                                    }
                                                    if(!isOfKind($4,KIND_ARRAY_CHAR)){
                                                        yyerror("Variables aren't compatible.");
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(4+strlen($2)+6+strlen($4)+strlen($6)); 
                                                    sprintf($$, "char %s=%s[%s]", $2, $4, $6);
                                                    add($$,true);
                                                    addVar($2, KIND_CHAR,1,false);
                                                }

    /* Integer Declaration: i$ name */
    | INT ALPHA                                 { 
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name"); 
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(3+strlen($2)+2); 
                                                    sprintf($$,"%s %s","int",$2);
                                                    add($$,true); 
                                                    addVar($2, KIND_INT,1,false);
                                                }
    
    /* Char Declaration: c$ name */
    | CHAR ALPHA                                { 
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name");
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(5+strlen($2)+2); 
                                                    sprintf($$,"char %s",$2);
                                                    add($$,true); 
                                                    addVar($2, KIND_CHAR,1,false);
                                                }
                                                
    /* String Declaration: s$ name */
    | STRING ALPHA                              { 
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name"); 
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(7+strlen($2)+2); 
                                                    sprintf($$,"%s %s","char *",$2);
                                                    add($$,true); 
                                                    addVar($2, KIND_STRING,1,false);
                                                }
    
    /* Integer Array Declaration: i$ name_LENGTH */
    | INT ALPHA '_' DIGIT                       { 
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name"); 
                                                        YYABORT;
                                                    } 
                                                    $$ = malloc(3+strlen($2)+5+strlen($4)); 
                                                    sprintf($$,"%s %s[%s]","int",$2,$4);
                                                    add($$,true); 
                                                    addVar($2, KIND_ARRAY_INT,atoi($4),false); 
                                                }
    
    /* Integer Array Declaration: i$ name_VAR */
    | INT ALPHA '_' ALPHA                       {
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name"); 
                                                        YYABORT;
                                                    }
                                                    if(!isOfKind($4,KIND_INT)){
                                                        yyerror("Variable should be int type to de-reference.");
                                                        YYABORT;
                                                    } 
                                                    $$ = malloc(3+strlen($2)+5+strlen($4)); 
                                                    sprintf($$,"%s %s[%s]","int",$2,$4);
                                                    add($$,true); 
                                                    addVar($2, KIND_ARRAY_INT,-1,false); 
                                                }
    
    /* String Array Declaration: s$ name_LENGTH */
    | STRING ALPHA '_' DIGIT                    { 
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name"); 
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(7+strlen($2)+5+strlen($4));
                                                    sprintf($$,"%s %s[%s]","char *",$2,$4);
                                                    add($$,true); 
                                                    addVar($2, KIND_ARRAY_STRING,atoi($4),false);
                                                }
    
    /* Char Array Declaration: c$ name_LENGTH */
    | CHAR ALPHA '_' DIGIT                      { 
                                                    if(checkIfVarExists($2)){
                                                        yyerror("That variable already exists, please choose another name"); 
                                                        YYABORT;
                                                    } 
                                                    $$ = malloc(4+strlen($2)+5+strlen($4)); 
                                                    sprintf($$,"%s %s[%s]","char",$2,$4);
                                                    add($$,true); 
                                                    addVar($2, KIND_ARRAY_CHAR,atoi($4),false); 
                                                }
    
    /* Char Array Declaration: i$ name_VAR */
    | CHAR ALPHA '_' ALPHA                      { 
                                                    if(checkIfVarExists($2))
                                                        {yyerror("That variable already exists, please choose another name"); 
                                                        YYABORT;
                                                    } 
                                                    if(!isOfKind($4,KIND_INT)){
                                                        yyerror("Variable should be int type to de-reference.");
                                                        YYABORT;
                                                    }
                                                    $$ = malloc(4+strlen($2)+5+strlen($4)); 
                                                    sprintf($$,"%s %s[%s]","char",$2,$4);
                                                    add($$,true); 
                                                    addVar($2, KIND_ARRAY_CHAR,-1,false); 
                                                }
 
    /* Assignment between variables */
    | ALPHA '=' ALPHA                       { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                }
                                                if((!checkIfVarExists($1)||!checkIfVarExists($3))|| !are_comparable($1,$3)){
                                                    yyerror("Variables aren't compatible.");
                                                    YYABORT;
                                                }
                                                $$ = malloc(4+strlen($1)+6+strlen($3)); 
                                                sprintf($$,"%s=%s",$1,$3); 
                                                add($$,true);
                                            }

    /* Assignment: var = 'ALPHA */
    | ALPHA '=' ESCAPE ALPHA                { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($1,KIND_CHAR)){
                                                    yyerror("Variable should be int type.");
                                                    YYABORT;
                                                }
                                                if(strlen($4)!=1){
                                                    yyerror("Incompatible initialization for type char."); 
                                                    YYABORT;
                                                }
                                                $$ = malloc(strlen($1)+strlen($4)+10); 
                                                sprintf($$, "%s=\'%s\'", $1, $4);
                                                add($$,true);
                                            }
    
    /* Assignment: var = 'DIGIT */
    | ALPHA '=' ESCAPE DIGIT                 { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($1,KIND_CHAR)){
                                                    yyerror("Variable should be int type.");
                                                    YYABORT;
                                                }
                                                if(strlen($4)!=1){
                                                    yyerror("Incompatible initialization for type char."); 
                                                    YYABORT;
                                                }
                                                $$ = malloc(strlen($1)+strlen($4)+10); 
                                                sprintf($$, "%s=\'%s\'", $1, $4);
                                                add($$,true);
                                            }
    
    /* Assignment: var = STRING_VALUE */
    | ALPHA '=' STRING_VALUE                 { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($1,KIND_STRING)){
                                                    yyerror("Variable should be string type.");
                                                    YYABORT;
                                                }
                                                $$ = malloc(strlen($1)+strlen($3)+5); 
                                                $3[strlen($3) - 1] = 0;
                                                sprintf($$, "%s=\"%s\"", $1, $3+1); 
                                                add($$,true);
                                            }
    
    /* Assignment: */
    | ALPHA '=' var_init operation           { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($1,KIND_INT)){
                                                    yyerror("Variable should be int type."); 
                                                    YYABORT;
                                                }
                                                $$ = malloc(strlen($1)+strlen($3)+strlen($4)+5);  
                                                sprintf($$, "%s=%s%s", $1, $3, $4); 
                                                add($$,true);
                                            }
    
    /* Assignment: var = arr_INDEX */
    | ALPHA '=' ALPHA '_' DIGIT             { 
        if(isConstant($1)){
            yyerror("Constants can't be modified.");
            YYABORT;
        } 
        if(!compatibleArray($1,$3,atoi($5))){
            yyerror("Variables aren't compatible.");
            YYABORT;
        }
        $$ = malloc(strlen($1)+strlen($3)+strlen($5) +5); 
        sprintf($$, "%s=%s[%s]", $1, $3, $5);
        add($$,true);
    }

    /* Assignment: var = arr_VAR */
    | ALPHA '=' ALPHA '_' ALPHA             { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($5,KIND_INT)){
                                                    yyerror("Variable should be int type to de-reference.");
                                                    YYABORT;
                                                }
                                                if(!compatibleArray($1,$3,0)){
                                                    yyerror("Variables aren't compatible.");
                                                    YYABORT;
                                                }
                                                $$ = malloc(strlen($1)+strlen($3)+strlen($5) +5); 
                                                sprintf($$, "%s=%s[%s]", $1, $3, $5);
                                                add($$,true);
                                            }


    | ALPHA '=' CONVERT '(' ALPHA ')'       { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($1,KIND_INT)){
                                                    yyerror("Variable to '=' should be int type.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($5,KIND_STRING) && !isOfKind($5,KIND_ARRAY_CHAR)){
                                                    yyerror("Argument should be string type.");
                                                    YYABORT;
                                                } 
                                                $$ = malloc(strlen($1)+strlen($5)+10); 
                                                sprintf($$,"%s = atoi(%s)",$1,$5); 
                                                add($$,true);
                                            }


    | ALPHA '=' LENGTH '(' ALPHA ')'        { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($1,KIND_INT)){
                                                    yyerror("Variable to '=' should be int type."); 
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($5,KIND_STRING) && !isOfKind($5,KIND_ARRAY_CHAR)){
                                                    yyerror("Argument hould be string type."); 
                                                    YYABORT;
                                                }
                                                $$ = malloc(strlen($1)+strlen($5)+10); 
                                                sprintf($$,"%s=strlen(%s)",$1, $5); 
                                                add($$,true);
                                            }      
  
    /* Integer declaration and assign to function */
    | INT ALPHA '=' call                     { 
                                                if(checkIfVarExists($2)){
                                                    yyerror("That variable already exists, please choose another name"); 
                                                    YYABORT;
                                                }
                                                if(!functionReturnsKind($4, KIND_INT)){
                                                    yyerror("Function should return type int"); 
                                                    YYABORT;
                                                } 
                                                $$ = malloc(3+strlen($2)+3+strlen($4)); 
                                                sprintf($$,"int %s=%s",$2,$4); 
                                                add($$,true); 
                                                addVar($2, KIND_INT,1,false);
                                            }

    /* String declaration and assign to function */
    | STRING ALPHA '=' call                  { 
                                                if(checkIfVarExists($2)){
                                                    yyerror("That variable already exists, please choose another name"); 
                                                    YYABORT;
                                                }
                                                if(!functionReturnsKind($4, KIND_STRING)){
                                                    yyerror("Function should return type string"); 
                                                    YYABORT;
                                                } 
                                                $$ = malloc(7+strlen($2)+3+strlen($4)); 
                                                sprintf($$,"char* %s=%s",$2,$4); 
                                                add($$,true); 
                                                addVar($2, KIND_STRING,1,false);
                                            }

    /* Char declaration and assign to function */
    | CHAR ALPHA '=' call                    { 
                                                if(checkIfVarExists($2)){
                                                    yyerror("That variable already exists, please choose another name"); 
                                                    YYABORT;
                                                }
                                                if(!functionReturnsKind($4, KIND_CHAR)){
                                                    yyerror("Function should return type char"); 
                                                    YYABORT;
                                                } 
                                                $$ = malloc(strlen($2)+8+strlen($4)); 
                                                sprintf($$,"char %s=%s",$2,$4); 
                                                add($$,true); 
                                                addVar($2, KIND_CHAR,1,false);
                                            } 

    /* Assignment: var = call_function*/  
    | ALPHA '=' call                        {
                                                $$ = malloc(strlen($1)+2+strlen($3)); 
                                                sprintf($$,"%s=%s",$1,$3);
                                                add($$,true);
                                            }


    /* Derefence value of array and assign to Integer */
    | ALPHA '_' DIGIT '=' DIGIT             { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                } 
                                                if (!isOfKind($1, KIND_ARRAY_INT)){
                                                    yyerror("Variable should be string '_' type"); 
                                                    YYABORT;
                                                } 
                                                if(! enoughSpace($1, atoi($3)) ) { 
                                                    yyerror("'_' has not enough space"); 
                                                    YYABORT; 
                                                } 
                                                $$ = malloc(strlen($1) + strlen($3) + strlen($5) + 4 ); 
                                                sprintf($$, "%s[%s]=%s", $1, $3, $5); 
                                                add($$, true); 
                                            }

    /* Derefence value of array and assign to Character */
    | ALPHA '_' DIGIT '=' ESCAPE ALPHA      { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                } 
                                                if (!isOfKind($1, KIND_ARRAY_CHAR)){
                                                    yyerror("Variable should be char '_' type"); 
                                                    YYABORT;
                                                } 
                                                if(! enoughSpace($1, atoi($3)) ) { 
                                                    yyerror("'_' has not enough space"); 
                                                    YYABORT; 
                                                } 
                                                if(strlen($6)!=1){
                                                    yyerror("Incompatible initialization for type char.");
                                                    YYABORT;
                                                }
                                                $$ = malloc(strlen($1) + strlen($3) + strlen($6) + 10 ); 
                                                sprintf($$, "%s[%s]=\'%s\'", $1, $3, $6);
                                                add($$, true); 
                                            }

    /* Derefence value of array and assign to Character */
    | ALPHA '_' DIGIT '=' ESCAPE DIGIT      { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                }
                                                if (!isOfKind($1, KIND_ARRAY_CHAR)){
                                                    yyerror("Variable should be char '_' type"); 
                                                    YYABORT;
                                                } 
                                                if(! enoughSpace($1, atoi($3)) ) {
                                                    yyerror("'_' has not enough space"); 
                                                    YYABORT; 
                                                } 
                                                if(strlen($6)!=1){
                                                    yyerror("Incompatible initialization for type char."); 
                                                    YYABORT;
                                                }
                                                $$ = malloc(strlen($1) + strlen($3) + strlen($6) + 10 ); 
                                                sprintf($$, "%s[%s]=\'%s\'", $1, $3, $6); 
                                                add($$, true); 
                                            }
    
    /* Derefence value of array and assign to String */
    | ALPHA '_' DIGIT '=' STRING_VALUE      { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                } 
                                                if (!isOfKind($1, KIND_ARRAY_STRING)){
                                                    yyerror("Variable should be string '_' type"); 
                                                    YYABORT;
                                                } 
                                                if(! enoughSpace($1, atoi($3)) ) { 
                                                    yyerror("'_' has not enough space"); 
                                                    YYABORT; 
                                                } 
                                                $$ = malloc(strlen($1) + strlen($3) + strlen($5) + 4 ); 
                                                $5[strlen($5) - 1] = 0; 
                                                sprintf($$, "%s[%s]=\"%s\"", $1, $3, $5+1); 
                                                add($$, true); 
                                            }
    
    /* Derefence value of array and assign to Variable */
    | ALPHA '_' ALPHA '=' ALPHA             { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                } 
                                                if(!compatibleArray($5,$1,0)){
                                                    yyerror("Variables aren't compatible.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($3,KIND_INT)){
                                                    yyerror("Variable should be int type."); 
                                                    YYABORT;
                                                }
                                                $$ = malloc(strlen($1) + strlen($3) + strlen($5) + 4 ); 
                                                sprintf($$, "%s[%s]=%s", $1, $3, $5); 
                                                add($$, true); 
                                            }
    
    /* Derefence value of array by Variable and assign to Digit */
    | ALPHA '_' ALPHA '=' DIGIT             { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($1, KIND_ARRAY_INT)){
                                                    yyerror("Variables aren't compatible.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($3,KIND_INT)){
                                                    yyerror("Variable should be int type."); 
                                                    YYABORT;
                                                }
                                                $$ = malloc(strlen($1) + strlen($3) + strlen($5) + 4 ); 
                                                sprintf($$, "%s[%s]=%s", $1, $3, $5); 
                                                add($$, true); 
                                            }
    
    /* Derefence value of array by Variable and assign to String */
    | ALPHA '_' ALPHA '=' STRING_VALUE      { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($1, KIND_ARRAY_STRING)){
                                                    yyerror("Variables aren't compatible.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($3,KIND_INT)){
                                                    yyerror("Variable should be int type."); 
                                                    YYABORT;
                                                }
                                                $$ = malloc(strlen($1) + strlen($3) + strlen($5) + 10 );
                                                $5[strlen($5) - 1] = 0; 
                                                sprintf($$, "%s[%s]=\"%s\"", $1, $3, $5+1); 
                                                add($$, true); 
                                            }
    
    /* Derefence value of array by Variable and assign to another Array by Variable */
    | ALPHA '_' ALPHA '=' ALPHA '_' ALPHA   { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                } 
                                                if(!checkIfVarExists($5) || !checkIfVarExists($1)){
                                                    yyerror("That '_' variable does not exist"); 
                                                    YYABORT;
                                                }  
                                                if(!compatibleArrayAssignment($1,$5,atoi($3),atoi($7))){
                                                    yyerror("Arrays types aren't compatible.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($3,KIND_INT)){
                                                    yyerror("First index should be int type."); 
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($7,KIND_INT)){
                                                    yyerror("Second index should be int type."); 
                                                    YYABORT;
                                                } 
                                                $$ = malloc(strlen($1) + strlen($3) + strlen($5) +strlen($7) + 7 ); 
                                                sprintf($$, "%s[%s]=%s[%s]", $1, $3, $5,$7); 
                                                add($$, true);
                                            }  
    
    /* Derefence value of array by Variable and assign to Character */
    | ALPHA '_' ALPHA '=' ESCAPE ALPHA      { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($1,KIND_ARRAY_CHAR)){
                                                    yyerror("Variables aren't compatible.");
                                                    YYABORT;
                                                } 
                                                if(!isOfKind($3,KIND_INT)){
                                                    yyerror("Variable should be int type."); 
                                                    YYABORT;
                                                }
                                                if(strlen($6)!=1){
                                                    yyerror("Incompatible initialization for type char.");
                                                    YYABORT;
                                                }
                                                $$ = malloc(strlen($1) + strlen($3) + strlen($6) + 10 ); 
                                                sprintf($$, "%s[%s]=\'%s\'", $1, $3, $6); 
                                                add($$, true); 
                                            }
    
    /* Derefence value of array by Variable and assign to Character */
    | ALPHA '_' ALPHA '=' ESCAPE DIGIT      { 
                                                if(isConstant($1)){
                                                    yyerror("Constants can't be modified.");
                                                    YYABORT;
                                                }
                                                if(!isOfKind($1,KIND_ARRAY_CHAR)){
                                                    yyerror("Variables aren't compatible.");
                                                    YYABORT;
                                                }
                                                if(!isOfKind($3,KIND_INT)){
                                                    yyerror("Variable should be int type."); 
                                                    YYABORT;
                                                }
                                                if(strlen($6)!=1){
                                                    yyerror("Incompatible initialization for type char.");
                                                    YYABORT;
                                                }
                                                $$ = malloc(strlen($1) + strlen($3) + strlen($6) + 10 );
                                                sprintf($$, "%s[%s]=\'%s\'", $1, $3, $6);
                                                add($$, true); 
                                            }
    ; 
    
operation
    : 
    /* Operation with Integer Literal */
    op DIGIT operation      {
                                $$ = malloc(strlen($1)+ 1 + strlen($2) + strlen($3));
                                sprintf($$,"%s%s%s",$1,$2,$3 );
                                add($$,true);
                            }

    /* Operation with Integer Variable */
    | op ALPHA operation    {
                                if (!isOfKind($2, KIND_INT)){
                                    yyerror("Variable should be int type");
                                    YYABORT;
                                }
                                $$ = malloc(strlen($1)+ 1 + strlen($2) + strlen($3));
                                sprintf($$,"%s%s%s",$1,$2,$3 );
                                add($$,true);
                            }

    | /* lambda */          {   $$ = "";    }
    ;
    
assignment
    :
    /* Assign variable to another variable */
    ALPHA               {   $$ = $1;    }
    
    /* Assign digits for Integer */
    | DIGIT             {   $$ = $1;    }
    
    /* Assign string value for String */
    | STRING_VALUE      {
                            $1[strlen($1) - 1] = '\"';
                            $1[0] = '\"';
                            $$ = $1;
                        }

    /* Assign escaped alpha for Character */
    | ESCAPE ALPHA      {
                            if(strlen($2)!=1){
                                yyerror("Incompatible initialization for type char.");
                                YYABORT;
                            }
                            $$ = malloc(strlen($2)+3);
                            sprintf($$, "\'%s\'", $2);
                            add($$,true);
                        }
    
    /* Assign escaped digit for Character */
    | ESCAPE DIGIT      {
                            if(strlen($2)!=1){
                                yyerror("Incompatible initialization for type char.");
                                YYABORT;
                            }
                            $$ = malloc(strlen($2)+3);
                            sprintf($$, "\'%s\'", $2);
                            add($$,true);
                        }
    
    /* Assign array accessed by digit index */
    | ALPHA '_' DIGIT   {
                            if(!isAnArray($1)) {
                                yyerror("Not an '_'.");
                                YYABORT;
                            }
                            $$ = malloc(strlen($1) + strlen($3) + 10);
                            sprintf($$, "%s[%s]", $1, $3);
                            add($$,true);
                        }

    /* Assign array accessed by variable index */                    
    | ALPHA '_' ALPHA   {
                            if(!isAnArray($1)) {
                                yyerror("Not an '_'.");
                                YYABORT;
                            }
                            if(!isOfKind($3,KIND_INT)){
                                yyerror("Variable should be int type to de-reference.");
                                YYABORT;
                            }
                            $$ = malloc(strlen($1) + strlen($3) + 10);
                            sprintf($$, "%s[%s]", $1, $3);
                            add($$,true);
                        }
    ;

var_init
    : ALPHA             {   $$ = $1;   }
    | DIGIT             {   $$ = $1;   }
    ;


alpha_array
    :
    /* String array not finished */
    STRING_VALUE ',' alpha_array    {
                                        $$ = malloc(strlen($1)+5+strlen($3));
                                        $1[strlen($1) - 1] = 0;
                                        sprintf($$, "\"%s\",%s", $1+1,$3);
                                        add($$,true);
                                    }
    
    /* String array last member */
    | STRING_VALUE                  {
                                        $$ = malloc(strlen($1)+5);
                                        $1[strlen($1) - 1] = 0;
                                        sprintf($$, "\"%s\"", $1+1);
                                        add($$,true);
                                    }
    ;

digit_array
    :
    /* Integer array not finished */
    DIGIT ',' digit_array           {
                                        $$ = malloc(strlen($1)+2+strlen($3));
                                        sprintf($$, "%s,%s", $1,$3);
                                        add($$,true);
                                    }

    /* Integer array finished */                                
    | DIGIT                         {
                                        $$ = malloc(strlen($1)+1);
                                        sprintf($$, "%s", $1);
                                        add($$,true);
                                    }     
    ; 

char_array
    :
    /* Character array not finished (alphnum)  */
    ESCAPE ALPHA ',' char_array   {
                                        if(strlen($2)!=1) {
                                            yyerror("Incompatible initialization for type char.");
                                            YYABORT;
                                        }
                                        $$ = malloc(strlen($2)+5+strlen($4));
                                        sprintf($$, "\'%s\',%s", $2,$4);
                                        add($$,true);
                                    }

    /* Caracter array last member (alphnum) */                                
    | ESCAPE ALPHA                  {
                                        if(strlen($2)!=1) { 
                                            yyerror("Incompatible initialization for type char.");
                                            YYABORT;
                                        }
                                        $$ = malloc(strlen($2)+5);
                                        sprintf($$, "\'%s\'", $2);
                                        add($$,true);
                                    }

    /* Character array not finished (digit)  */                                
    | ESCAPE DIGIT ',' char_array   {
                                        if(strlen($2)!=1){
                                            yyerror("Incompatible initialization for type char.");
                                            YYABORT;
                                        }
                                        $$ = malloc(strlen($2)+5+strlen($4));
                                        sprintf($$, "\'%s\',%s", $2,$4);
                                        add($$,true);
                                    }
    
    /* Character array last member (digit)  */
    | ESCAPE DIGIT                  {
                                        if(strlen($2)!=1) {
                                            yyerror("Incompatible initialization for type char.");
                                            YYABORT;
                                        }
                                        $$ = malloc(strlen($2)+5);
                                        sprintf($$, "\'%s\'", $2);
                                        add($$,true);
                                    }
    ;

/* Binary rules */
rule
    :
    /* General rule: ( R ? R ). R can be ( R ? R ) or E */
    '(' rule operator rule ')'    {   
                                        if(!are_comparable($2, $4)) {
                                            yyerror("Uncomparable data types");
                                            YYABORT;
                                        }
                                        $$ = malloc(strlen($2) + strlen($3) + strlen($4) + 5);
                                        sprintf($$, "(%s %s %s)", $2, $3, $4);
                                        add($$,true);
                                    }
    /* Expression: E */
    | assignment                    {
                                        $$ = malloc(strlen($1)+1);
                                        sprintf($$, "%s", $1); 
                                        add($$, true);
                                    }
    ;

/* General unary/binary operators */
operator
    : op    {   $$ = $1;    }
    | '<'   {   $$ = "<";   }
    | '>'   {   $$ = ">";   }
    | LE    {   $$ = "<=";  }
    | GE    {   $$ = ">=";  } 
    | '~'   {   $$ = "==";  }
    | NE    {   $$ = "!=";  } 
    | '|'   {   $$ = "||";  }
    | '&'   {   $$ = "&&";  }
    ;

/* Arithmetic operators */
op 
    : '+'   {   $$ = "+";   }
    | '-'   {   $$ = "-";   }
    | '/'   {   $$ = "/";   }
    | '*'   {   $$ = "*";   }
    | '%'   {   $$ = "%";   }
    ;

%%
