all:
	yacc -d grammar.y
	flex scanner.l
	gcc -o parser lex.yy.c -lfl