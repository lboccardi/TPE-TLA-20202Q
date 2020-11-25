CCFLAGS=-Wall -pedantic -std=c99 -ggdb -fsanitize=address
YLFLAGS= -lfl -ll 

all:
	lex scanner.l
	yacc -d grammar.y
	gcc -o parser lex.yy.c y.tab.c $(YLFLAGS)
clean: 
	rm lex.yy.c y.tab.c y.tab.h *.out