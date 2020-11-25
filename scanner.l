%{
#include "y.tab.h"
%}

alpha [A-Za-z]
digit [0-9]
varname {alpha}({alpha}|{digit})*

%% 

"S"           return MAIN; 
"G"           return STDIN; 
"P"           return STDOUT; 
"F"           return FUNCTION; 
"R"           return RETURN;
{digit}+	{ yylval.intValue = atoi(yytext);}; return DIGIT;
{varname}   {char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				return ALPHA;
            }
"."         return END;
[ \t]+      ;
"("         return OPEN_P; 
")"         return CLOSE_P;
"?"         return CONDITIONAL;
"{"         return EXEC; 
"}"         return END_EXEC;
"->"        return IF; 
"'"         return ESCAPE;
"-->"       return WHILE;
"<"         return L;
">"         return G;
"<="        return LE;
">="        return GE;
"~"         return EQ;
"!"         return NOT;
"|"         return OR;
"&"         return AND;
"="         return ASSIGN; 
"i$"        return INT; 
"s$"        return STRING; 
[+\-*/]		{	char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				return OP;
            }
","         return COMMA;

 
%%
 