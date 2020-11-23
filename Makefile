CCFLAGS=-Wall -pedantic -std=c99 -ggdb -fsanitize=address

all:
	lex scanner.l
	yacc -d grammar.y
	gcc -o parser lex.yy.c y.tab.c -lfl -ll 
	
clean: 
	rm lex.yy.c y.tab.c y.tab.h *.out