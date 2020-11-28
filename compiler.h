#ifndef COMPILER_H
#define COMPILER_H

#include <stdio.h>

extern FILE *yyin; //Set yyin for yacc to parse file

/* Generates Assembly code */
void generateIntermediateCodeFile(FILE *file);

void compile(char *name);
#endif