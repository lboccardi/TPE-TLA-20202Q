%token DIGIT;
%token  ALPHA;
%token  END; 
%token  CONDITION; 
%token  END_CONDITION;
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
%token  INT; 
%token  STRING; 
%token  OP; 

%%

main(){
    yyparser(); 
}