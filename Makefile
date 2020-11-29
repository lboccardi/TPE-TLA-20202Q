PHONY = all clean
CCFLAGS=-Wall -pedantic -std=c99 -ggdb -fsanitize=address -D_XOPEN_SOURCE=700
YLFLAGS= -lfl

all:
	lex scanner.l
	yacc -v -d grammar.y
	gcc -o parser lex.yy.c y.tab.c tree.c compiler.c $(YLFLAGS) $(CCFLAGS)
clean: 
	rm -rf lex.yy.c y.tab.c y.tab.h parser intermediate.c executable