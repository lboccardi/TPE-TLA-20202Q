alpha [A-Za-z]
digit [0-9]

%% 

{digit}+	yylval=atoi(yytext); return DIGIT;
{alpha}+	yylval=yytext; return ALPHA;
"."           return END;
[ \t]+      ;
"("        return CONDITION; 
")?"        return END_CONDITION;
"->"        return IF; 
":"         return ELSE;
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


%%

int yywrap(void){
    return 1;
}
int main(void){
    yylex();
    return 0;
}