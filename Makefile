CCFLAGS=-Wall -pedantic -std=c99 -ggdb -fsanitize=address
YLFLAGS= -lfl -ll 

all:
	lex scanner.l
	yacc -v -d grammar.y
	gcc -o parser lex.yy.c y.tab.c tree.c $(YLFLAGS) $(CCFLAGS)
clean: 
	rm lex.yy.c y.tab.c y.tab.h parser