alpha [A-Za-z]
digit [0-9]

%% 

{digit}+	        yylval=atoi(yytext); return DIGIT;
{alpha}+{digit}*	yylval=yytext; return ALPHA;
"."         return END;
[ \t]+      ;
"("         return CONDITION; 
")?"        return END_CONDITION;
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
[+-*/]      yylval=yytext; return OP;
R[{alpha}+ | {digit}*]+.   return RETURN;  

 
%%

int yywrap(void){
    return 1;
}
int main(void){
    yylex();
    return 0;
}