%{
#include "y.tab.h"
%}

alpha [A-Za-z]
digit [0-9]

%% 

"S"           return MAIN; 
"G"           return STDIN; 
"P"           return STDOUT; 
"F"           return FUNCTION; 
R[{alpha}+ | {digit}*]+   return RETURN;
{digit}+	        yylval=atoi(yytext); return DIGIT;
{alpha}+	yylval=atoi(yytext); return ALPHA;
"."         return END;
[ \t]+      ;
"("         return OPEN_P; 
")"         return CLOSE_P;
"?"         return CONDITIONAL;
"?"         return CONDITIONAL;
"?"         return CONDITIONAL;
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
[+\-*/]      yylval=atoi(yytext); return OP;
","         return COMMA;

 
%%
 