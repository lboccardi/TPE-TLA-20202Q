%{
#include "y.tab.h"
#include "tree.h"
bool last_escape = false;
%}

%option nounput
%option noinput
%option yylineno

alpha [A-Za-z]
digit [0-9]
varname {alpha}({alpha}|{digit})*
space_alpha [\[]({alpha}|{digit}|[  \  \\ \n \t]|" "|"'"|"_"|":"|"=")*[\]]
string_value [\']({alpha}|{digit}|[  \  \\ \n \t]|" "|"'")*[\']

%% 

"S"           {if(!last_escape){
				return MAIN;} 
				last_escape = false;
			  char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				add(str,true);
				return ALPHA;
			  } 
"G"           {if(!last_escape){
				return STDIN;} 
				last_escape = false;
			  char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				add(str,true);
				return ALPHA;
			  }  
"P"           {if(!last_escape){
				return STDOUT;} 
				last_escape = false;
			   char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				add(str,true);
				return ALPHA;
			  } 
"F"          {if(!last_escape){
				return FUNCTION;} 
				last_escape = false;
			  char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				add(str,true);
				return ALPHA;
			  } 
"R"           {if(!last_escape){
				return RETURN;} 
				last_escape = false;
			  char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				add(str,true);
				return ALPHA;
			  }
"L"			  {if(!last_escape){
				return LENGTH;} 
				last_escape = false;
			  char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				add(str,true);
				return ALPHA;
			  } 
"C"		      {if(!last_escape){
				return CONVERT;} 
				last_escape = false;
			  char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				add(str,true);
				return ALPHA;
			  } 			  

{digit}+	{char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				add(str,true);
				last_escape = false;
				return DIGIT;
            }

{varname}   {char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				add(str,true);
				last_escape = false;
				return ALPHA;
            }
{string_value}   {char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				add(str,true);
				last_escape = false;
				return STRING_VALUE;
            }
{space_alpha}   {char* str = malloc(strlen(yytext) + 1);
				strcpy(str, yytext);
				yylval.stringValue = str;
				add(str,true);
				last_escape = false;
				return SPACE_ALPHA;
            }
[ \t \n]+      ;
"'"         {last_escape = true;return ESCAPE;}
[<>~|&=%/,_.:]|\-|\(|\)|\{|\}|\?|\+|\*		{ return *yytext; }
"->"        {last_escape = false; return IF; }
"-->"       {last_escape = false; return WHILE;}
"<="        {last_escape = false; return LE;}
">="        {last_escape = false; return GE;}
"!~"		{last_escape = false; return NE; }
"i$"        {last_escape = false;return INT;} 
"s$"        {last_escape = false;return STRING;}
"c$" 		{last_escape = false;return CHAR;}
"i#"		{last_escape = false;return INT_DEFINE;}
"c#"        {last_escape = false;return CHAR_DEFINE;}
"s#"		{last_escape = false;return STRING_DEFINE;}
<<EOF>>                         { yyterminate(); return 1; }
%%
 