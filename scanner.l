%{
#include "y.tab.h"
#include "tree.h"
%}

alpha [A-Za-z]
digit [0-9]
varname {alpha}({alpha}|{digit})*
space_alpha [\[]({alpha}|{digit}|[  \  \\ \n \t]|" "|"'"|"_")*[\]]
string_value [\']({alpha}|{digit}|[  \  \\ \n \t]|" "|"'")*[\']

%% 

"S"           return MAIN; 
"G"           return STDIN; 
"P"           return STDOUT; 
"F"           return FUNCTION; 
"R"           return RETURN;

{digit}+	{char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				add(str,true);
				return DIGIT;
            }

{varname}   {char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				add(str,true);
				return ALPHA;
            }
{string_value}   {char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				add(str,true);
				return STRING_VALUE;
            }
{space_alpha}   {char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				add(str,true);
				return SPACE_ALPHA;
            }
"."         return END;
[ \t \n]+      ;
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
"!~"		return NE;
"!"         return NOT;
"|"         return OR;
"&"         return AND;
"="         return ASSIGN; 
"i$"        return INT; 
"s$"        return STRING; 
"+"         return PLUS; 
"-"         return MINUS;
"*"         return TIMES;
"/"         return DIV; 
","         return COMMA;
"_"         return ARRAY; 
<<EOF>>                         { yyterminate(); return 1; }
%%
 